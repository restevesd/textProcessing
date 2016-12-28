shinyUI(bootstrapPage(
  
fluidPage(
  titlePanel("Text Prediction"),
  
  fluidRow(
    column(
      3, 
      textInput(
        "text",
        label = h3("Text input")
      ),
      submitButton("Submit")
    ),
    column(
      3, 
      textOutput("text1")
    )
  )
  )
))
