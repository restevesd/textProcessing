library("magrittr")
library("data.table")

cleanText <- function(text) {
  text %>%
    tolower %>%
    gsub("[^a-z ]", "", .)
}

splitClean <- function(text) {
  text %>%
    strsplit(" ")
}

splitText <- function(text) {
  text %>%
    cleanText %>%
    splitClean
}


