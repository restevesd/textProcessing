library(data.table)
library(magrittr)

source("splitText.R")

EMPTYLINES2STOP <- 10
PROB <- 0.0003




##conRead <- file("../data/test.txt", "r")
createTestFile <- function() {
  emptylines <- 0
  linecounts <- 0
  while ( TRUE ) {
    line = readLines(conRead, n = 1)
    if ( length(line) ==  0 || nchar(line) == 0 ) {
      emptylines <- emptylines + 1
    } else {
      linecounts <- linecounts + 1
      if (linecounts %% 100000 == 0) {
        cat(sprintf("%.0f lines read\n", linecounts))
      }
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
}

conWrite <- file("testData.txt", "w")
conRead <- file("../data/en_US.twitter.clean.txt", "r")
createTestFile()
close(conRead)
conRead <- file("../data/en_US.news.clean.txt", "r")
createTestFile()
close(conRead)
conRead <- file("../data/en_US.blogs.clean.txt", "r")
createTestFile()
close(conRead)
close(conWrite)


