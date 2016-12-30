library(data.table)
library(magrittr)

source("splitText.R")

EMPTYLINES2STOP <- 10
PROB <- 0.0001

conRead <- file("../data/en_US.twitter.clean.txt", "r")
conWrite <- file("testData.txt", "w")
##conRead <- file("../data/test.txt", "r")
emptylines <- 0
while ( TRUE ) {
  line = readLines(conRead, n = 1)
  if ( length(line) ==  0 || nchar(line) == 0 ) {
    emptylines <- emptylines + 1
  } else {
    emptylines <- 0
    if (rbinom(1, 1, PROB) == 1) {
      line_split <- splitClean(line)
      N <- length(line_split)
      k <- sample(2:(N-1), 1)
      line_split[1:k] %>%
        paste(collapse=" ") %>%
        paste0(",", line_split[k+1]) %>%
        writeLines(conWrite)
    }
  }
  if (emptylines == EMPTYLINES2STOP) {
    break
  }
}
close(conRead)
close(conWrite)
