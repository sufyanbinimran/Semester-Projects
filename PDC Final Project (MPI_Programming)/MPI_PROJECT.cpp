#include <mpi.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <random>  // For generating random system statuses in the simulation
#include <numeric> // For std::accumulate
#include <zlib.h>
#include <string>
#include <map>

struct PatientRecord {
    std::string id;
    int age;
    char gender;
    std::string bloodType;
    std::string dateOfRecord;
    std::string condition;

    std::string serialize() const {
        std::ostringstream oss;
        oss << id << ',' << age << ',' << gender << ',' << bloodType << ',' << dateOfRecord << ',' << condition;
        return oss.str();
    }

    static PatientRecord deserialize(const std::string& data) {
        std::istringstream iss(data);
        PatientRecord record;
        char delim;
        iss >> record.id >> delim >> record.age >> delim >> record.gender >> delim
            >> record.bloodType >> delim >> record.dateOfRecord >> delim >> record.condition;
        return record;
    }
};
// Initialize MPI environment
void initializeMPI()
{
    int provided;
    MPI_Init_thread(nullptr, nullptr, MPI_THREAD_MULTIPLE, &provided);
    if (provided < MPI_THREAD_MULTIPLE)
    {
        std::cerr << "ERROR: The MPI implementation does not support full thread safety." << std::endl;
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
}

// Load configuration from a specified file
std::vector<std::string> loadConfiguration(const std::string& filename)
{
    std::vector<std::string> records;
    std::string line;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "ERROR: Unable to open file " << filename << std::endl;
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    while (getline(file, line))
    {
        records.push_back(line);
    }
    file.close();

    return records;
}

// Establish communicators for different node groups
void establishCommunicators(MPI_Comm& custom_comm)
{
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int color = world_size % 2; // Example: split by even and odd ranks
    MPI_Comm_split(MPI_COMM_WORLD, color, 0, &custom_comm);
}
// Add a new patient record
void addPatientRecord(std::vector<PatientRecord>& records, const PatientRecord& record) {
    // Check if the record already exists
    auto it = std::find_if(records.begin(), records.end(),
        [&record](const PatientRecord& existingRecord) {
            return existingRecord.id == record.id;
        });
    if (it != records.end()) {
        std::cerr << "ERROR: Record with ID " << record.id << " already exists." << std::endl;
        return;
    }

    records.push_back(record);
}

// Update an existing patient record by ID
void updatePatientRecord(std::vector<PatientRecord>& records, const std::string& patient_id, const PatientRecord& new_record) {
    auto it = std::find_if(records.begin(), records.end(),
        [&patient_id](const PatientRecord& record) {
            return record.id == patient_id;
        });
    if (it != records.end()) {
        *it = new_record;
    }
    else {
        std::cerr << "ERROR: No record found with ID " << patient_id << std::endl;
    }
}

// Delete a patient record by ID
void deletePatientRecord(std::vector<PatientRecord>& records, const std::string& patient_id) {
    auto it = std::remove_if(records.begin(), records.end(),
        [&patient_id](const PatientRecord& record) {
            return record.id == patient_id;
        });
    if (it == records.end()) {
        std::cerr << "ERROR: No record found with ID " << patient_id << std::endl;
    }
    else {
        records.erase(it, records.end());
    }
}

// View a patient record by ID
void viewPatientRecord(const std::vector<PatientRecord>& records, const std::string& patient_id) {
    auto it = std::find_if(records.begin(), records.end(),
        [&patient_id](const PatientRecord& record) {
            return record.id == patient_id;
        });
    if (it != records.end()) {
        std::cout << "Record: " << it->serialize() << std::endl;
    }
    else {
        std::cerr << "ERROR: No record found with ID " << patient_id << std::endl;
    }
}

// Distribute patient records across nodes
void distributeRecords(const std::vector<PatientRecord>& records, MPI_Comm& comm) {
    int rank, size;
    MPI_Comm_rank(comm, &rank);
    MPI_Comm_size(comm, &size);

    // Serialize records to a single string
    std::string all_data;
    for (const auto& record : records) {
        all_data += record.serialize() + "\n";  // Use newline as a separator
    }

    // Calculate total size and prepare buffer for scattering
    int total_size = all_data.size();
    std::vector<int> sizes(size);
    std::vector<int> displs(size);

    // Calculate sizes and displacements for each process
    int base_size = total_size / size;
    int remainder = total_size % size;

    int start = 0;
    for (int i = 0; i < size; ++i) {
        sizes[i] = base_size + (i < remainder ? 1 : 0);
        displs[i] = start;
        start += sizes[i];
    }

    // Prepare buffer to receive data
    std::vector<char> local_data(sizes[rank]);

    // Scatter serialized data to all processes
    MPI_Scatterv(all_data.data(), sizes.data(), displs.data(), MPI_CHAR,
        local_data.data(), sizes[rank], MPI_CHAR, 0, comm);

    // Deserialize data in local buffer
    std::string local_str(local_data.begin(), local_data.end());
    std::istringstream iss(local_str);
    std::string line;
    std::vector<PatientRecord> local_records;
    while (getline(iss, line)) {
        local_records.push_back(PatientRecord::deserialize(line));
    }

    // Each process now has its portion of the records to work with
    if (rank == 0) {
        for (const auto& record : local_records) {
            std::cout << "Process 0 record: " << record.serialize() << std::endl;
        }
    }
}

// Helper function to gather all data sizes from all processes to the root for monitoring
std::vector<int> gatherDataSizes(int local_size)
{
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    std::vector<int> all_sizes(world_size);
    MPI_Gather(&local_size, 1, MPI_INT, all_sizes.data(), 1, MPI_INT, 0, MPI_COMM_WORLD);
    return all_sizes;
}

// Monitor the distribution of records: gathers data from all nodes and prints it
void monitorDistribution(int local_records_count)
{
    std::vector<int> all_sizes = gatherDataSizes(local_records_count);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    if (world_rank == 0)
    { // Only the root node prints the distribution information
        std::cout << "Record distribution across nodes:" << std::endl;
        for (int i = 0; i < all_sizes.size(); ++i)
        {
            std::cout << "Node " << i << " has " << all_sizes[i] << " records." << std::endl;
        }
    }
}

// Adjust the parameters for record distribution (Example: changing the distribution logic)
void adjustDistributionSettings(int& new_setting)
{
    // This function can be expanded to include more complex settings adjustments
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    if (world_rank == 0)
    { // Root node adjusts settings
        std::cout << "Enter new setting value: ";
        std::cin >> new_setting;
        // Broadcast the new setting value to all nodes
        MPI_Bcast(&new_setting, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }
    else
    {
        // Receive the new setting from the root node
        MPI_Bcast(&new_setting, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }
}

// Perform bulk updates on records
void bulkUpdateRecords(std::vector<std::string>& local_records, const std::string& update_criteria, const std::string& new_data)
{
    // Example: Update all records of patients older than a certain age
    for (auto& record : local_records)
    {
        // Extract age from the record and check against update_criteria
        if (meetsCriteria(record, update_criteria))
        {
            record = new_data; // Simplified for illustration
        }
    }
}

// Access patient records distributed across nodes
std::vector<std::string> accessDistributedRecords(const std::vector<std::string>& local_records, const std::string& search_criteria)
{
    std::vector<std::string> results;
    for (const auto& record : local_records)
    {
        if (meetsSearchCriteria(record, search_criteria))
        {
            results.push_back(record);
        }
    }
    return results;
}

// Utility function to parse a record and check if it meets update criteria
bool meetsCriteria(const std::string& record, const std::string& update_criteria)
{
    std::istringstream iss(record);
    std::string id, age, gender, blood_type, date, diagnosis;
    getline(iss, id, ',');
    getline(iss, age, ',');
    getline(iss, gender, ',');
    getline(iss, blood_type, ',');
    getline(iss, date, ',');
    getline(iss, diagnosis, ',');

    // Example criterion: update if patient's age is greater than given value
    return std::stoi(age) > std::stoi(update_criteria);
}

// Utility function to parse a record and check if it meets search criteria
bool meetsSearchCriteria(const std::string& record, const std::string& search_criteria)
{
    return record.find(search_criteria) != std::string::npos;
}

// Check data consistency across the system
void checkDataConsistency(const std::vector<std::string>& local_records)
{
    int local_size = local_records.size();
    std::vector<int> all_sizes = gatherDataSizes(local_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    if (world_rank == 0)
    {
        int total_records = 0;
        for (int size : all_sizes)
        {
            total_records += size;
        }
        std::cout << "Total records across all nodes: " << total_records << std::endl;
        // Further consistency checks can be performed here
    }
}

// Schedule a backup of patient records
void scheduleBackup(const std::vector<std::string>& records, const std::string& backup_filename)
{
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if (world_rank == 0)
    {
        std::ofstream backup_file(backup_filename);
        if (!backup_file.is_open())
        {
            std::cerr << "Failed to open backup file." << std::endl;
            return;
        }

        for (const auto& record : records)
        {
            backup_file << record << std::endl;
        }

        backup_file.close();
        std::cout << "Backup completed successfully." << std::endl;
    }
    MPI_Barrier(MPI_COMM_WORLD); // Ensure all nodes wait until the backup is complete
}

// Restore data from a backup file
void restoreFromBackup(std::vector<std::string>& records, const std::string& backup_filename)
{
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if (world_rank == 0)
    {
        std::ifstream backup_file(backup_filename);
        if (!backup_file.is_open())
        {
            std::cerr << "Failed to open backup file for restoration." << std::endl;
            return;
        }

        std::string line;
        records.clear(); // Clear current records before restoration
        while (getline(backup_file, line))
        {
            records.push_back(line);
        }

        backup_file.close();
        std::cout << "Restoration completed successfully." << std::endl;
    }
    MPI_Barrier(MPI_COMM_WORLD); // Ensure all nodes are synchronized after restoration
}

// Log a backup event
void logBackupEvent(const std::string& backup_filename)
{
    std::ofstream log_file("backup_history.log", std::ios::app);
    if (!log_file.is_open())
    {
        std::cerr << "Failed to open log file for backup history." << std::endl;
        return;
    }

    // Get current time for logging
    std::time_t now = std::time(nullptr);
    std::string time_str = std::asctime(std::localtime(&now));
    time_str.pop_back(); // Remove the newline character at the end of the asctime string

    log_file << time_str << ": Backup created - " << backup_filename << std::endl;
    log_file.close();
}

// View backup history
void viewBackupHistory()
{
    std::ifstream log_file("backup_history.log");
    if (!log_file.is_open())
    {
        std::cerr << "Failed to open log file to view backup history." << std::endl;
        return;
    }

    std::string line;
    std::cout << "Backup History:\n";
    while (getline(log_file, line))
    {
        std::cout << line << std::endl;
    }
    log_file.close();
}

// Perform a simple search across local records
std::vector<std::string> simpleSearch(const std::vector<std::string>& local_records, const std::string& search_term)
{
    std::vector<std::string> found_records;
    for (const auto& record : local_records)
    {
        if (record.find(search_term) != std::string::npos)
        {
            found_records.push_back(record);
        }
    }
    return found_records;
}

// Helper function to parse a record
std::vector<std::string> parseRecord(const std::string& record)
{
    std::stringstream ss(record);
    std::vector<std::string> fields;
    std::string field;
    while (getline(ss, field, ','))
    {
        fields.push_back(field);
    }
    return fields;
}

// Check if a record meets complex search criteria
bool meetsAdvancedCriteria(const std::string& record, const std::map<std::string, std::string>& criteria)
{
    auto fields = parseRecord(record);
    // Assuming fields are: ID, Age, Gender, Blood Type, Date of Diagnosis, Diagnosis
    if (criteria.count("age")) {
        std::string age = fields[1];
        age.erase(age.begin(), std::find_if(age.begin(), age.end(), [](unsigned char ch) {
            return !std::isspace(ch);
            }));
        age.erase(std::find_if(age.rbegin(), age.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
            }).base(), age.end());
        if (std::stoi(age) != std::stoi(criteria.at("age")))
            return false;
    }
    // Repeat the same process for the other fields...
    return true;
}

// Perform an advanced search using detailed parameters
std::vector<std::string> advancedSearch(const std::vector<std::string>& local_records, const std::map<std::string, std::string>& search_criteria)
{
    std::vector<std::string> results;
    for (const auto& record : local_records)
    {
        if (meetsAdvancedCriteria(record, search_criteria))
        {
            results.push_back(record);
        }
    }
    return results;
}

// View results from the last search performed
void viewSearchResults(const std::vector<std::string>& search_results)
{
    for (const auto& result : search_results)
    {
        std::cout << result << std::endl;
    }
}

// View system logs based on the specified log type
void viewLogs(const std::string& log_filename)
{
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if (world_rank == 0)
    { // Ensure only the master node handles the log viewing
        std::ifstream log_file(log_filename);
        if (!log_file.is_open())
        {
            std::cerr << "Failed to open log file." << std::endl;
            return;
        }

        std::string line;
        while (getline(log_file, line))
        {
            std::cout << line << std::endl;
        }
        log_file.close();
    }
}

// Export logs to an external location with the specified format
void exportLogs(const std::vector<std::string>& logs, const std::string& export_filename)
{
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if (world_rank == 0)
    { // Only the master node should handle log exporting
        std::ofstream export_file(export_filename);
        if (!export_file.is_open())
        {
            std::cerr << "Failed to export logs to " << export_filename << std::endl;
            return;
        }

        for (const auto& log : logs)
        {
            export_file << log << std::endl;
        }
        export_file.close();
        std::cout << "Logs exported successfully to " << export_filename << std::endl;
    }
}

// Simulate monitoring system status with random data to mimic system loads (CPU and memory usage)
void monitorSystemStatus()
{
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100); // Random load between 0 and 100

    int cpu_usage = dis(gen);
    int memory_usage = dis(gen);

    // Each process reports its system status
    std::cout << "Node " << world_rank << " CPU usage: " << cpu_usage << "%, Memory usage: " << memory_usage << "MB" << std::endl;
}

// View the current load on each node
void viewCurrentLoad(const std::vector<int>& loads)
{
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Example of viewing load: simply print it out
    std::cout << "Node " << world_rank << " has a load of " << loads[world_rank] << std::endl;
}

// Rebalance the workload across nodes
void rebalanceLoad(std::vector<int>& loads)
{
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Simple rebalancing strategy: average the loads and distribute the excess
    int total_load = 0;
    for (auto& load : loads)
    {
        total_load += load;
    }
    int average_load = total_load / world_size;

    for (int i = 0; i < world_size; i++)
    {
        if (loads[i] > average_load)
        {
            int excess = loads[i] - average_load;
            loads[i] -= excess;
            loads[(i + 1) % world_size] += excess; // Simplified distribution logic
        }
    }

    if (world_rank == 0)
    {
        std::cout << "Load rebalanced among nodes." << std::endl;
    }
}

// Adjust load balancing based on CPU usage
void setLoadBalancingRules(std::vector<int>& loads)
{
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Simulate a simple rebalance based on the CPU usage passed in 'loads'
    int total_load = std::accumulate(loads.begin(), loads.end(), 0);
    int average_load = total_load / world_size;

    std::vector<int> load_changes(world_size, 0);

    for (int i = 0; i < world_size; ++i)
    {
        if (loads[i] > average_load)
        {
            int excess = loads[i] - average_load;
            load_changes[(i + 1) % world_size] += excess;
            loads[i] -= excess;
            loads[(i + 1) % world_size] += excess;
        }
    }

    // Display load adjustments if the node is master
    if (world_rank == 0)
    {
        for (int i = 0; i < world_size; ++i)
        {
            std::cout << "Node " << i << " load adjusted to " << loads[i] << std::endl;
        }
    }
}

// Function to compress a string using zlib with an adjustable compression level
std::string compressString(const std::string& str, int compression_level)
{
    uLong ucompSize = str.size();              // Uncompressed size
    uLong compSize = compressBound(ucompSize); // Compressed size maximum estimate
    std::vector<char> dest(compSize);

    // The compression level can be Z_DEFAULT_COMPRESSION, or between 0 (no compression) and 9 (maximum compression)
    int res = compress2((Bytef*)dest.data(), &compSize, (const Bytef*)str.data(), ucompSize, compression_level);

    if (res != Z_OK)
    {
        std::cerr << "Compression failed with error: " << res << std::endl;
        return "";
    }

    return std::string(dest.begin(), dest.begin() + compSize);
}

// Compress data from a vector of strings, allowing for specified compression level
void compressData(const std::vector<std::string>& data, const std::string& output_filename, int compression_level)
{
    std::ofstream output_file(output_filename, std::ios::binary);
    if (!output_file.is_open())
    {
        std::cerr << "Failed to open file for compression." << std::endl;
        return;
    }

    for (const auto& record : data)
    {
        std::string compressed_data = compressString(record, compression_level);
        output_file.write(compressed_data.data(), compressed_data.size());
    }
    output_file.close();
    std::cout << "Data compression completed and stored in " << output_filename << std::endl;
}

// Decompression function remains the same
std::string decompressString(const std::string& str)
{
    uLong compSize = str.size();
    uLong ucompSize = str.size() * 4; // Initial estimate for uncompressed size
    std::vector<char> dest(ucompSize);

    int res = uncompress((Bytef*)dest.data(), &ucompSize, (const Bytef*)str.data(), compSize);

    while (res == Z_BUF_ERROR)
    {
        ucompSize *= 2;
        dest.resize(ucompSize);
        res = uncompress((Bytef*)dest.data(), &ucompSize, (const Bytef*)str.data(), compSize);
    }

    if (res != Z_OK)
    {
        std::cerr << "Decompression failed with error: " << res << std::endl;
        return "";
    }

    return std::string(dest.begin(), dest.begin() + ucompSize);
}

// Adjust compression settings by choosing the compression level
void adjustCompressionSettings(int& compression_level)
{
    std::cout << "Current Compression Level: " << compression_level << std::endl;
    std::cout << "Enter new compression level (0-9): ";
    std::cin >> compression_level;
    if (compression_level < 0 || compression_level > 9)
    {
        std::cerr << "Invalid compression level. Please enter a value between 0 and 9." << std::endl;
        return;
    }
    std::cout << "Compression level adjusted to: " << compression_level << std::endl;
}

// Access user manual
void accessUserManual()
{
    std::cout << "User Manual: For detailed guidance, refer to the manual provided with the software package." << std::endl;
}

// View Frequently Asked Questions
void viewFAQ()
{
    std::cout << "FAQs:\n"
        << "Q: How do I add a new patient record?\n"
        << "A: Go to the 'Patient Record Management' menu and select 'Add Patient Record'.\n"
        << "Q: What should I do if the system crashes?\n"
        << "A: Restart the system and restore data from the latest backup if necessary.\n"
        << "Q: How to search for a patient record?\n"
        << "A: Use the 'Distributed Search' menu and choose 'Simple Search' or 'Advanced Search' to find records." << std::endl;
}
void menu1(MPI_Comm& comm) {
    int option;
    std::string patient_id, record;
    do {
        std::cout << "\n--- Patient Record Operations ---\n";
        std::cout << "1. Add Patient Record\n";
        std::cout << "2. View Patient Record\n";
        std::cout << "3. Update Patient Record\n";
        std::cout << "4. Delete Patient Record\n";
        std::cout << "5. Return to Main Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;

        switch (option) {
        case 1:
        {
            PatientRecord new_record;
            std::cout << "Enter patient ID: ";
            std::cin >> new_record.id;
            std::cout << "Enter patient age: ";
            std::cin >> new_record.age;
            std::cout << "Enter patient gender: ";
            std::cin >> new_record.gender;
            std::cout << "Enter patient blood type: ";
            std::cin >> new_record.bloodType;
            std::cout << "Enter date of record: ";
            std::cin >> new_record.dateOfRecord;
            std::cout << "Enter patient condition: ";
            std::cin >> new_record.condition;
            addPatientRecord(records, new_record);
        }
        break;
        case 2:
            std::cout << "Enter patient ID to view: ";
            std::cin >> patient_id;
            viewPatientRecord(records, patient_id);
            break;
        case 3:
        {
            PatientRecord updated_record;
            std::cout << "Enter patient ID to update: ";
            std::cin >> patient_id;
            std::cout << "Enter new patient ID (or press enter to keep the same): ";
            std::string new_id;
            std::cin.ignore();
            std::getline(std::cin, new_id);
            if (!new_id.empty()) {
                updated_record.id = new_id;
            }
            else {
                updated_record.id = records[patient_id].id;
            }
            std::cout << "Enter new patient age (or press enter to keep the same): ";
            std::string new_age;
            std::getline(std::cin, new_age);
            if (!new_age.empty()) {
                try {
                    updated_record.age = std::stoi(new_age);
                }
                catch (const std::exception& e) {
                    std::cout << "Invalid age input. Age must be an integer.\n";
                    break;
                }
            }
            else {
                updated_record.age = records[patient_id].age;
            }
            std::cout << "Enter new patient gender (or press enter to keep the same): ";
            std::string new_gender;
            std::getline(std::cin, new_gender);
            if (!new_gender.empty()) {
                if (new_gender.length() == 1) {
                    updated_record.gender = new_gender[0];
                }
                else {
                    std::cout << "Invalid gender input. Gender must be a single character.\n";
                    break;
                }
            }
            else {
                updated_record.gender = records[patient_id].gender;
            }
            std::cout << "Enter new patient blood type (or press enter to keep the same): ";
            std::string new_blood_type;
            std::getline(std::cin, new_blood_type);
            if (!new_blood_type.empty()) {
                updated_record.bloodType = new_blood_type;
            }
            else {
                updated_record.bloodType = records[patient_id].bloodType;
            }
            std::cout << "Enter new date of record (or press enter to keep the same): ";
            std::string new_date_of_record;
            std::getline(std::cin, new_date_of_record);
            if (!new_date_of_record.empty()) {
                updated_record.dateOfRecord = new_date_of_record;
            }
            else {
                updated_record.dateOfRecord = records[patient_id].dateOfRecord;
            }
            std::cout << "Enter new patient condition (or press enter to keep the same): ";
            std::string new_condition;
            std::getline(std::cin, new_condition);
            if (!new_condition.empty()) {
                updated_record.condition = new_condition;
            }
            else {
                updated_record.condition = records[patient_id].condition;
            }
            updatePatientRecord(records, patient_id, updated_record);
        }
        break;
        case 4:
            std::cout << "Enter patient ID to delete: ";
            std::cin >> patient_id;
            deletePatientRecord(records, patient_id);
            break;
        case 5:
            std::cout << "Returning to main menu...\n";
            break;
        default:
            std::cout << "Invalid option, please try again.\n";
        }
    } while (option != 5);
}

void menu2(MPI_Comm& comm) {
    // Similar structure for Data Management menu
}

void menu3(MPI_Comm& comm) {
    // Similar structure for System Utilities menu
}
void mainMenu() {
    int choice = 0;
    MPI_Comm custom_comm;
    establishCommunicators(custom_comm); // Establish custom communicators for different node groups

    do {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. Patient Record Operations\n";
        std::cout << "2. Data Management\n";
        std::cout << "3. System Utilities\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            menu1(custom_comm);
            break;
        case 2:
            menu2(custom_comm);
            break;
        case 3:
            menu3(custom_comm);
            break;
        case 4:
            std::cout << "Exiting system...\n";
            MPI_Abort(MPI_COMM_WORLD, 0);  // Exit all processes safely
            break;
        default:
            std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);
}

int main(int argc, char** argv)
{
    MPI_Init(&argc, &argv);
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Initialize MPI-related settings
    initializeMPI();

    if (world_rank == 0)
    {
        mainMenu();
    }
    // Synchronize and finalize MPI
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
}