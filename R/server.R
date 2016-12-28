source("splitText.R")

shinyServer(function(input, output) {

  textCleaned <- reactive({
    cleanText(input$text)
  })

  
  output$text1 <- renderText({
    if (textCleaned() !=  "") {
      textCleaned()
    } 
  })

})
