#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

char structure[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
bool Tie = false;
int r, c;
char currentPlayer = 'X'; // Renamed from Choice1

void X()
{
    cout << "T I C  T A C  T O E  G A M E ";
}

void structureoutput()
{
    system("cls"); // Consider a more portable solution or remove for simplicity
    cout << "\n\n\W E L C O M E  T O  T H E" << endl << endl;
    X();
    cout << endl << endl;
    cout << "\tPlayer1 [X]" << endl;
    cout << "\tPlayer2 [O]" << endl << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << structure[0][0] << "  |  " << structure[0][1] << "  |  " << structure[0][2] << "  " << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << structure[1][0] << "  |  " << structure[1][1] << "  |  " << structure[1][2] << "  " << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << structure[2][0] << "  |  " << structure[2][1] << "  |  " << structure[2][2] << "  " << endl;
    cout << "\t\t     |     |     " << endl;
}

void player_turn()
{
    int option;
    cout << "\n\tPlayer " << currentPlayer << " Turn: ";
    cin >> option;

    switch (option)
    {
    case 1: r = 0; c = 0; break;
    case 2: r = 0; c = 1; break;
    case 3: r = 0; c = 2; break;
    case 4: r = 1; c = 0; break;
    case 5: r = 1; c = 1; break;
    case 6: r = 1; c = 2; break;
    case 7: r = 2; c = 0; break;
    case 8: r = 2; c = 1; break;
    case 9: r = 2; c = 2; break;
    default:
        cout << "Invalid Choice";
        player_turn(); // Re-ask for input in case of invalid choice
        return;
    }

    if (structure[r][c] != 'X' && structure[r][c] != 'O')
    {
        structure[r][c] = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    else
    {
        cout << "Box Already Filled..!!";
        cout << " Re-Enter Turn...";
        player_turn(); // Re-ask for input if box is already filled
    }

    structureoutput();
}

void CPU_turn()
{
    int choice;
    if (currentPlayer == 'X') // Assuming CPU plays as 'X'
    {
        choice = rand() % 9 + 1; // Generate a random number between 1 and 9
        switch (choice)
        {
        case 1: r = 0; c = 0; break;
        case 2: r = 0; c = 1; break;
        case 3: r = 0; c = 2; break;
        case 4: r = 1; c = 0; break;
        case 5: r = 1; c = 1; break;
        case 6: r = 1; c = 2; break;
        case 7: r = 2; c = 0; break;
        case 8: r = 2; c = 1; break;
        case 9: r = 2; c = 2; break;
        default:
            cout << "Wrong choice try again!!";
            CPU_turn(); // Re-ask for input if choice is invalid
            return;
        }
        if (structure[r][c] != 'X' && structure[r][c] != 'O')
        {
            structure[r][c] = currentPlayer;
            currentPlayer = 'X'; // Assuming CPU's opponent is 'O'
        }
        else
        {
            cout << "Box Already Filled..!!";
            cout << " Re-Enter Turn...";
            CPU_turn(); // Re-ask for input if box is already filled
        }
    }

    structureoutput();
}

bool gameover()
{
    // Check win conditions
    for (int i = 0; i < 3; i++)
    {
        if (structure[i][0] == structure[i][1] && structure[i][0] == structure[i][2])
            return false; // Row win
        if (structure[0][i] == structure[1][i] && structure[0][i] == structure[2][i])
            return false; // Column win
    }
    if (structure[0][0] == structure[1][1] && structure[0][0] == structure[2][2])
        return false; // Diagonal win
    if (structure[0][2] == structure[1][1] && structure[0][2] == structure[2][0])
        return false; // Diagonal win

    // Check if the board is full (Tie)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (structure[i][j] != 'X' && structure[i][j] != 'O')
                return true; // Board not full yet
        }
    }
    Tie = true; // Board is full, game is a tie
    return false;
}

int main()
{
    int choice;
    cout << "1) Player vs Computer\n2) Player vs Player" << endl;
    cin >> choice;

    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    if (choice == 2)
    {
        while (gameover())
        {
            structureoutput();
            player_turn();
        }
        if (currentPlayer == 'X' && !Tie)
        {
            cout << "\t\t\t\nPlayer2 [O] You Won HURRAH ..." << endl;
        }
        else if (currentPlayer == 'O' && !Tie)
        {
            cout << "Player1 [X] You Won HURRAH";
        }
        else
        {
            cout << "Game Tie..!!";
        }
    }
    else if (choice == 1)
    {
        while (gameover())
        {
            structureoutput();
            CPU_turn();
        }
        if (currentPlayer == 'X' && !Tie)
        {
            cout << "\t\t\t\nCPU You Won HURRAH ...";
        }
        else if (currentPlayer == 'O' && !Tie)
        {
            cout << "Player1 [X] You Won..Hurrah";
        }
        else
        {
            cout << "Game Tie";
        }
    }
    else
    {
        cout << "You entered the wrong choice. Please try again.";
    }

    return 0;
}