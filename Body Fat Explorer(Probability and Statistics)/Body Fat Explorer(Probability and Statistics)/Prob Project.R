read.csv("C:\\Users\\Wel\\Downloads\\BodyFat - Extended.csv")
# Load necessary libraries
# ggplot2: Used for creating and customizing complex plots and visualizations
library(ggplot2)
# dplyr: Provides a set of tools for efficiently manipulating datasets, including functions like filter(), select(), and summarise()
library(dplyr)
# MASS: Stands for Modern Applied Statistics with S. It provides various statistical functions and datasets.
library(MASS)
# Assuming your dataset is stored in a data frame called 'body_data'
weight <- read.csv("C:\\Users\\Wel\\Downloads\\BodyFat - Extended.csv")
# Display the structure of the dataset
str(body_data)


# 1. Graphical and Tabular Data Representation
# Quntitative Data
# Print the input
cat("Instructions 1.You cannot enter Orignal and Sex as a parameter beacuse they are Quantitative:", "\n")
# Prompt the user for input
user_input <- readline("Enter the variable for X-axis: ")
# Histogram of Body Fat Percentage
# aes_string(x = user_input) specifies that the user-provided variable will be plotted on the x-axis
ggplot(weight, aes_string(x = user_input)) +
  geom_histogram(binwidth = 2, fill = "orange", color = "black") +
  labs(title = user_input ,
       x = "X-axis",
       y = "Frequency")
# Scatter plot of Weight vs. Body Fat Percentage for comparison
# Prompt the user for input
user_input1 <- readline("Enter the first variable : ")
user_input2 <- readline("Enter the second variable: ")
# Scatter plot using user inputs
ggplot(body_data, aes_string(x = user_input1, y = user_input2)) +
  geom_point(color = "darkgreen") +
  labs(title = paste("Scatter plot of", user_input2, "vs.", user_input1),
       x = user_input1,
       y = user_input2)
# Qualitative Data
# Assuming 'Orignal' is a column in your data frame
# Create a bar chart
ggplot(weight, aes(x = Original, fill = Original)) +
  geom_bar() +
  labs(title = "Bar Chart for Original", x = "Categories", y = "Count") +
  scale_fill_manual(values = c("Y" = "skyblue", "N" = "coral"), labels = c("Y", "N")) +
  theme_minimal()
# Assuming 'Sex' is a column in your data frame
# Create a bar chart
ggplot(weight, aes(x = Sex, fill = Sex)) +
  geom_bar() +
  labs(title = "Bar Chart for Sex", x = "Categories", y = "Count") +
  theme_minimal()


# 2. Descriptive Statistical Measures
# Prompt the user for input
user_input3 <- readline("Enter the variable on which you want to apply summary statistics: ")
# Check if the entered variable exists in the dataset
if (!user_input3 %in% names(body_data)) {
  cat("Error: The entered variable does not exist in the dataset.\n")
} else {
  # Summary statistics
  summary_stats <- summary(body_data[[user_input3]])
  print(summary_stats)
  # Mean and standard deviation
  var1 <- mean(body_data[[user_input3]])
  var2 <- sd(body_data[[user_input3]])
  # Print the results
  cat("Mean is:", var1, "\n")
  cat("Standard Deviation is:", var2, "\n")
}


# 3.Distributions 
# ***** Uniform Distribution ***
#Chances of events are Equal
# Prompt the user for input
user_variable <- readline("Enter the variable on which you want to apply the uniform distribution: ")
# Specify the range for the uniform distribution
min_value <- min(weight[[user_variable]])
max_value <- max(weight[[user_variable]])
# Calculate mean, variance, and standard deviation using the formula
mean_value_formula <- (min_value + max_value) / 2
variance_value_formula <- (max_value - min_value)^2 / 12
std_deviation_value_formula <- sqrt(variance_value_formula)
# Probability Density Function (PDF) formula
pdf_formula <- 1 / (max_value - min_value)
# Print the calculated values using the formula
cat("Mean (Formula):", mean_value_formula, "\n")
cat("Variance (Formula):", variance_value_formula, "\n")
cat("Standard Deviation (Formula):", std_deviation_value_formula, "\n")
cat("PDF (Formula):", pdf_formula, "\n")
# Generate random samples from a uniform distribution
n <- 437
uniform_samples <- runif(n, min = min_value, max = max_value)
# Plot a histogram of the uniform distribution
hist(uniform_samples, main = paste("Uniform Distribution for", user_variable), col = "skyblue", breaks = 20)


# ********* Normal Distribution *********
# Prompt the user for input
user_variable <- readline("Enter the variable on which you want to apply the normal distribution: ")
# Extract the specified variable
selected_variable <- weight[[user_variable]]
# Calculate mean and standard deviation
mean_value <- mean(selected_variable)
std_deviation_value <- sd(selected_variable)
# Calculate exact variance
variance_value <- var(selected_variable)
# Probability Density Function (PDF) formula for normal distribution
pdf_normal <- function(x) {
  exp(-((x - mean_value)^2) / (2 * std_deviation_value^2)) / (std_deviation_value * sqrt(2 * pi))
 }
# Generate random samples from a normal distribution
n <- 437
normal_samples <- rnorm(n, mean = mean_value, sd = std_deviation_value)
# Plot a histogram of the normal distribution
hist(normal_samples, main = paste("Normal Distribution for", user_variable), col = "skyblue", breaks = 20, prob = TRUE)
# Plot the PDF curve
x_values <- seq(min(normal_samples), max(normal_samples), length.out = 100)
lines(x_values, pdf_normal(x_values), col = "red", lwd = 2)
# Print mean, variance, standard deviation, and PDF
cat("Mean:", mean_value, "\n")
cat("Variance:", variance_value, "\n")
cat("Standard Deviation:", std_deviation_value, "\n")
cat("PDF (Normal):", pdf_normal(mean_value), "\n")


# 4. Regression Modeling and Predictions

user_variable1 <- readline("Enter the Dependent Var: ")

# Prompt user to enter the independent variable
independent_var <- readline("Enter Independent Variable: ")

# Check if the entered variable names exist in the dataset
if (!(dependent_var %in% colnames(weight))) {
  stop("Entered dependent variable does not exist in the dataset.")
}

if (!(independent_var %in% colnames(weight))) {
  stop("Entered independent variable does not exist in the dataset.")
}

# Modify the formula with user input
formula <- formula(paste(dependent_var, "~ Sex +", independent_var))

# Perform linear regression
reg_model <- lm(formula, data = weight)

# Display regression summary
summary(reg_model)

# Scatter plot
library(ggplot2)
ggplot(weight, aes_string(x = independent_var, y = dependent_var, color = "Sex")) +
  geom_point() +
  geom_smooth(method = "lm", se = FALSE) +
  labs(title = "Scatter Plot and Regression Line",
       x = independent_var,
       y = dependent_var,
       color = "Sex")

# Display regression coefficients
coefficients(reg_model)

# Create a new data frame for prediction with user input
new_data <- data.frame(Sex = c("Male", "Female"), Height = c(weight, weight))

# Display the predicted values
predicted_values <- predict(reg_model, newdata = new_data)
cat("Predicted values of", dependent_var, ":\n")
print(data.frame(Sex = new_data$Sex, Predicted = predicted_values))

# 5. Confidence Interval of Descriptive Measures and Regression Estimates

# Prompt user to enter the variable for which to calculate the confidence interval
variable_name <- readline("Enter the variable name for which to calculate the confidence interval: ")

# Confidence interval for the mean of the specified variable
conf_interval_mean <- t.test(body_data[[variable_name]])$conf.int
cat(paste("95% Confidence Interval for Mean", variable_name, ":", conf_interval_mean, "\n"))

# Confidence interval for the regression coefficients
# Assuming you have a linear regression model stored in 'model'
# You need to replace 'model' with the actual linear regression model object
# For example: model <- lm(Outcome ~ Predictor, data = your_data)
conf_interval_regression <- confint(model)
cat("95% Confidence Intervals for Regression Coefficients:\n")
print(conf_interval_regression)

