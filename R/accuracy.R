library(data.table)
library(magrittr)

source("simplePrediction.R")
simplePredictorFun <- simplePredictor()

con <- file("testData.txt", "r")

correct <- 0
total <- 0
while ( TRUE ) {
  line = readLines(con, n = 1)
  if ( length(line) ==  0 || nchar(line) == 0 ) {
    break
  }
  s <- strsplit(line, ",")[[1]]
  w <- s[2]
  w_tilde <- simplePredictorFun(s[1])
  total <- total + 1
  if (w_tilde == w) {
    correct <- correct + 1
  } 
}

close(con)

print(correct/total)
