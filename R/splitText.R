library("magrittr")
library("data.table")

cleanText <- function(text) {
  text %>%
    tolower %>%
    gsub("[^a-z ]", "", .)
}

splitClean <- function(text) {
  text %>%
    strsplit(" ")[[1]]
}

splitText <- function(text) {
  text %>%
    cleanText %>%
    splitClean
}


