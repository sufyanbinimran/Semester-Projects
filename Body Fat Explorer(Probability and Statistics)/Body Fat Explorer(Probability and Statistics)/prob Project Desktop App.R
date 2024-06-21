# app.R
library(shiny)
library(ggplot2)
library(dplyr)
library(shinydashboard)

# Read the data
weight <- read.csv("C:\\Users\\Wel\\Downloads\\BodyFat - Extended.csv")

ui <- dashboardPage(
  dashboardHeader(title = "BodyFat Analysis Dashboard"),
  dashboardSidebar(
    sidebarMenu(
      menuItem("Graphs", tabName = "graphs"),
      menuItem("Descriptive Statistics", tabName = "desc_stats"),
      menuItem("Distributions", tabName = "distributions"),
      menuItem("Regression Modeling", tabName = "regression"),
      menuItem("Confidence Intervals", tabName = "conf_intervals")
    )
  ),
  dashboardBody(
    tabItems(
      # Graphs tab
      tabItem(
        tabName = "graphs",
        fluidRow(
          box(
            title = "Quantitative Data",
            status = "primary",
            solidHeader = TRUE,
            width = 6,
            textInput("quant_variable", "Enter variable for X-axis:", ""),
            actionButton("quant_plotBtn", "Plot Quantitative Data"),
            plotOutput("quant_histogram")
          ),
          box(
            title = "Scatter Plot",
            status = "success",
            solidHeader = TRUE,
            width = 6,
            textInput("scatter_x", "Enter X variable:", ""),
            textInput("scatter_y", "Enter Y variable:", ""),
            actionButton("scatter_plotBtn", "Plot Scatter Plot"),
            plotOutput("scatter_plot")
          )
        ),
        fluidRow(
          box(
            title = "Bar Charts",
            status = "info",
            solidHeader = TRUE,
            width = 6,
            actionButton("qual_plotBtn", "Plot Qualitative Data"),
            plotOutput("bar_chart_original")
          ),
          box(
            title = "Bar Chart for Sex",
            status = "warning",
            solidHeader = TRUE,
            width = 6,
            plotOutput("bar_chart_sex")
          )
        )
      ),
      
      # Descriptive Statistics tab
      tabItem(
        tabName = "desc_stats",
        fluidRow(
          box(
            title = "Descriptive Statistics",
            status = "primary",
            solidHeader = TRUE,
            width = 6,
            textInput("desc_variable", "Enter variable for summary statistics:", ""),
            actionButton("desc_statsBtn", "Calculate Descriptive Statistics"),
            tableOutput("desc_stats")
          )
        )
      ),
      
      # Distributions tab
      tabItem(
        tabName = "distributions",
        fluidRow(
          box(
            title = "Uniform Distribution",
            status = "success",
            solidHeader = TRUE,
            width = 6,
            textInput("uniform_variable", "Enter variable for uniform distribution:", ""),
            actionButton("uniform_distributionBtn", "Plot Uniform Distribution"),
            plotOutput("uniform_distribution"),
            verbatimTextOutput("uniform_distribution_values")
          ),
          box(
            title = "Normal Distribution",
            status = "info",
            solidHeader = TRUE,
            width = 6,
            textInput("normal_variable", "Enter variable for normal distribution:", ""),
            actionButton("normal_distributionBtn", "Plot Normal Distribution"),
            plotOutput("normal_distribution"),
            verbatimTextOutput("normal_distribution_values")
          )
        )
      ),
      
      # Regression Modeling tab
      tabItem(
        tabName = "regression",
        fluidRow(
          box(
            title = "Linear Regression",
            status = "primary",
            solidHeader = TRUE,
            width = 6,
            textInput("dependent_variable", "Enter dependent variable:", ""),
            textInput("independent_variable", "Enter independent variable (X):", ""),
            actionButton("regressionBtn", "Plot Linear Regression"),
            plotOutput("regression_plot"),
            tableOutput("regression_summary"),
            tableOutput("regression_output")
          )
        )
      ),
      
      # Confidence Intervals tab
      tabItem(
        tabName = "conf_intervals",
        fluidRow(
          box(
            title = "Confidence Intervals",
            status = "success",
            solidHeader = TRUE,
            width = 6,
            textInput("variable_name", "Enter variable name:", ""),
            actionButton("conf_intervalBtn", "Calculate Confidence Intervals"),
            verbatimTextOutput("conf_interval_output")
          )
        )
      )
    )
  )
)


# Define the server
server <- function(input, output) {
  # 1. Graphs
  output$quant_histogram <- renderPlot({
    ggplot(weight, aes_string(x = input$quant_variable)) +
      geom_histogram(binwidth = 2, fill = "orange", color = "black") +
      labs(title = input$quant_variable, x = "X-axis", y = "Frequency")
  })
  
  output$scatter_plot <- renderPlot({
    ggplot(weight, aes_string(x = input$scatter_x, y = input$scatter_y)) +
      geom_point(color = "darkgreen") +
      labs(title = paste("Scatter plot of", input$scatter_y, "vs.", input$scatter_x),
           x = input$scatter_x,
           y = input$scatter_y)
  })
  
  observeEvent(input$qual_plotBtn, {
    output$bar_chart_original <- renderPlot({
      ggplot(weight, aes(x = Original, fill = Original)) +
        geom_bar() +
        labs(title = "Bar Chart for Original", x = "Categories", y = "Count") +
        scale_fill_manual(values = c("Y" = "skyblue", "N" = "coral"), labels = c("Y", "N")) +
        theme_minimal()
    })
    
    output$bar_chart_sex <- renderPlot({
      ggplot(weight, aes(x = Sex, fill = Sex)) +
        geom_bar() +
        labs(title = "Bar Chart for Sex", x = "Categories", y = "Count") +
        theme_minimal()
    })
  })
  
  # 2. Descriptive Statistics
  observeEvent(input$desc_statsBtn, {
    user_input3 <- input$desc_variable
    
    if (!user_input3 %in% names(weight)) {
      output$desc_stats <- renderPrint({
        "Error: The entered variable does not exist in the dataset."
      })
    } else {
      summary_stats <- summary(weight[[user_input3]])
      mean_value <- mean(weight[[user_input3]])
      sd_value <- sd(weight[[user_input3]])
      
      output$desc_stats <- renderPrint({
        cat("Summary Statistics:\n", format_summary(summary_stats), "\n")
        cat("Mean is:\n", mean_value, "\n")
        cat("Standard Deviation is:\n", sd_value, "\n")
      })
    }
  })
  
  # Custom function to format summary statistics
  format_summary <- function(stats) {
    formatted_stats <- paste(names(stats), stats, sep = ": ", collapse = "\n")
    return(formatted_stats)
  }
  
  # 3. Distributions
  # 3. Distributions
  observeEvent(input$uniform_distributionBtn, {
    user_variable_uniform <- isolate(input$uniform_variable)
    req(user_variable_uniform)
    
    # Specify the range for the uniform distribution
    min_value_uniform <- min(weight[[user_variable_uniform]])
    max_value_uniform <- max(weight[[user_variable_uniform]])
    
    # Calculate mean, variance, and standard deviation using the formula
    mean_value_formula_uniform <- (min_value_uniform + max_value_uniform) / 2
    variance_value_formula_uniform <- (max_value_uniform - min_value_uniform)^2 / 12
    std_deviation_value_formula_uniform <- sqrt(variance_value_formula_uniform)
    
    # Probability Density Function (PDF) formula for uniform distribution
    pdf_uniform <- function(x) {
      ifelse(x >= min_value_uniform & x <= max_value_uniform, 1 / (max_value_uniform - min_value_uniform), 0)
    }
    
    # Generate random samples from a uniform distribution
    n_uniform <- 437
    uniform_samples <- runif(n_uniform, min = min_value_uniform, max = max_value_uniform)
    
    # Plot a histogram of the uniform distribution with PDF
    output$uniform_distribution <- renderPlot({
      hist(uniform_samples, main = paste("Uniform Distribution for", user_variable_uniform), col = "skyblue", breaks = 20, probability = TRUE)
      
      # Plot the PDF curve
      x_values_uniform <- seq(min_value_uniform, max_value_uniform, length.out = 100)
      lines(x_values_uniform, pdf_uniform(x_values_uniform), col = "red", lwd = 2)
    })
    
    # Display the calculated values using verbatimTextOutput
    output$uniform_distribution_values <- renderPrint({
      list(
        Mean = mean_value_formula_uniform,
        Variance = variance_value_formula_uniform,
        Standard_Deviation = std_deviation_value_formula_uniform,
        PDF_at_Mean = pdf_uniform(mean_value_formula_uniform)  # Add the mean as x value to calculate PDF
      )
    })
  })
  
  # 3. Distributions (Normal)
  observeEvent(input$normal_distributionBtn, {
    user_variable_normal <- isolate(input$normal_variable)
    req(user_variable_normal)
    
    # Extract the specified variable
    selected_variable_normal <- weight[[user_variable_normal]]
    
    # Calculate mean and standard deviation
    mean_value_normal <- mean(selected_variable_normal)
    std_deviation_value_normal <- sd(selected_variable_normal)
    
    # Calculate exact variance
    variance_value_normal <- var(selected_variable_normal)
    
    # Probability Density Function (PDF) formula for normal distribution
    pdf_normal <- function(x) {
      dnorm(x, mean = mean_value_normal, sd = std_deviation_value_normal)
    }
    
    # Generate random samples from a normal distribution
    n_normal <- 437
    normal_samples <- rnorm(n_normal, mean = mean_value_normal, sd = std_deviation_value_normal)
    
    # Plot a histogram of the normal distribution with PDF
    output$normal_distribution <- renderPlot({
      hist(normal_samples, main = paste("Normal Distribution for", user_variable_normal), col = "skyblue", breaks = 20, probability = TRUE)
      
      # Plot the PDF curve
      x_values_normal <- seq(min(normal_samples), max(normal_samples), length.out = 100)
      lines(x_values_normal, pdf_normal(x_values_normal), col = "red", lwd = 2)
    })
    
    # Display the calculated values using verbatimTextOutput
    output$normal_distribution_values <- renderPrint({
      list(
        Mean = mean_value_normal,
        Variance = variance_value_normal,
        Standard_Deviation = std_deviation_value_normal,
        PDF_at_Mean = pdf_normal(mean_value_normal)  # Add the mean as x value to calculate PDF
      )
    })
  })
  
  
  # 4.Regression Modeling and Predictions
  observeEvent(input$regressionBtn, {
    dependent_var <- input$dependent_variable
    independent_var <- input$independent_variable
    
    # Check if the entered variables exist in the dataset
    if (!(dependent_var %in% colnames(weight) && independent_var %in% colnames(weight))) {
      return()  # Return if variables are not found
    }
    
    # Calculate means
    mean_X <- mean(weight[[independent_var]])
    mean_Y <- mean(weight[[dependent_var]])
    
    # Calculate slope (b) and intercept (a) using least squares method
    b <- sum((weight[[independent_var]] - mean_X) * (weight[[dependent_var]] - mean_Y)) / sum((weight[[independent_var]] - mean_X)^2)
    a <- mean_Y - b * mean_X
    
    # Predict Y values based on simple linear regression equation
    predicted_Y <- a + b * weight[[independent_var]]
    
    output$regression_plot <- renderPlot({
      ggplot(weight, aes_string(x = independent_var, y = dependent_var, color = "Sex")) +
        geom_point() +
        geom_smooth(method = "lm", se = FALSE) +
        labs(
          title = paste("Scatter Plot and Regression Line of", independent_var, "vs.", dependent_var),
          x = independent_var,
          y = dependent_var
        )
    })
    
    output$regression_output <- renderText({
      paste("Linear Regression Values:\n",
            "Intercept (a): ", a, "\n",
            "Slope (b): ", b, "\n")
    })
    
    
    output$regression_summary <- renderTable({
      # Display other regression statistics if needed
      summary(lm(weight[[dependent_var]] ~ weight[[independent_var]]))$coefficients
    })
    
    output$predicted_values <- renderTable({
      data.frame(Actual_Y = weight[[dependent_var]], Predicted_Y = predicted_Y)
    })
  })
  # 5.Confidence Intervals   
  output$conf_interval_output <- renderPrint({
    # Check if the button is clicked
    req(input$conf_intervalBtn)
    
    # Prompt user to enter the variable name for which to calculate the confidence interval
    variable_name <- isolate(input$variable_name)
    
    # Check if the entered variable name exists in the dataset
    if (!(variable_name %in% colnames(weight))) {
      return("Entered variable name does not exist in the dataset.")
    }
    
    # Confidence interval for the mean of the specified variable
    conf_interval_mean <- t.test(weight[[variable_name]])$conf.int
    cat(paste("95% Confidence Interval for Mean", variable_name, ":", conf_interval_mean, "\n\n"))
    
    # Confidence interval for the regression coefficients
    formula <- as.formula(paste(input$dependent_variable, "~ Sex +", input$independent_variable))
    model <- lm(formula, data = weight)
    conf_interval_regression <- confint(model)
    cat("95% Confidence Intervals for Regression Coefficients:\n")
    print(conf_interval_regression)
  })
}

# Run the Shiny app
shinyApp(ui, server)
