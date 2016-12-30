library(data.table)
library(magrittr)

EMPTYLINES2STOP <- 10
PROB <- 0.00001

conRead <- file("../data/en_US.twitter.clean.txt", "r")
##conRead <- file("../data/test.txt", "r")
emptylines <- 0
while ( TRUE ) {
  line = readLines(conRead, n = 1)
  if ( length(line) == 0 ) {
    emptylines <- emptylines + 1
  } else {
    emptylines <- 0
    if (rbinom(1, 1, PROB) == 1) {
      print(line)
    }
  }
  if (emptylines == EMPTYLINES2STOP) {
    break
  }
}
close(conRead)
conWrite <- file("testData.csv", "w")

rbinom(n, size, prob)



close(conWrite)
