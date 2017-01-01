source("simplePrediction.R")

simplePredictorFun <- simplePredictor()

shinyServer(function(input, output, session) {

  prediction <- reactive({
    pred <- simplePredictorFun(input$textEnter)
    pred
  })

  output$text1 <- renderText({
    if (input$textEnter != "") {
      pred <- prediction()
      pred
    }
  })
  
  observeEvent(input$addPredict, {
    updateTextAreaInput(
      session, 
      "textEnter",
      value = paste(input$textEnter, prediction())
    )
  })
})
