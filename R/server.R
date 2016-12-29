source("simplePrediction.R")

simplePredictorFun <- simplePredictor()

shinyServer(function(input, output) {

  prediction <- reactive({
    simplePredictorFun(input$text)
  })

  
  output$text1 <- renderText({
    if (input$text !=  "") {
      prediction()
    } 
  })

})
