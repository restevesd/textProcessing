shinyUI(bootstrapPage(

    
fluidPage(
  tags$head(tags$script(src = "message-handler.js")),
  titlePanel("Text Prediction"),
  
  fluidRow(
    column(
      9, 
      textAreaInput(
        "textEnter",
        label = h3("Text input"),
        width="300%",
        rows=10
      ),
      actionButton("addPredict", "Add prediction to text")
    ),
    column(
      3,
      h2("Prediction:"),
      textOutput("text1")
    )
  )
  )
))
