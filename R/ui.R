shinyUI(bootstrapPage(
  
fluidPage(
  titlePanel("Text Prediction"),
  
  fluidRow(
    column(
      5, 
      textInput(
        "text",
        label = h3("Text input")
      ),
      submitButton("Predict next word")
    ),
    column(
      7,
      h2("Prediction:"),
      textOutput("text1")
    )
  )
  )
))
