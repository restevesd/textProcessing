library("data.table")
library("magrittr")

source("splitText.R")

prepare1gram <- function() {
  "../data/gram1final.csv" %>%
    fread %>%
    setnames(c("word1", "count1")) %>%
    .[order(-count1)] %>%
    .[1, .(word1)] %>%
    write.csv("simple1gram.csv", row.names = FALSE, quote=FALSE)
}

prepare2gram <- function() {
  dt2 <-
    "../data/gram2final.csv" %>%
    fread %>%
    setnames(c("word1", "word2", "count2")) %>%
    .[count2 > 1]
  dt1 <-
    "../data/gram1final.csv" %>%
    fread %>%
    setnames(c("word1", "count1")) %>%
    .[count1 > 1]
  merge(dt2, dt1, by="word1") %>%
    .[order(-count2, -count1)] %>%
    .[,.SD[1], by=.(word1)] %>%
    .[, .(word1, word2)] %>%
    write.csv("simple2gram.csv", row.names = FALSE, quote=FALSE)
}

prepare3gram <- function() {
  dt3 <-
    "../data/gram3final.csv" %>%
    fread %>%
    setnames(c("word1", "word2", "word3", "count3")) %>%
    .[count3 > 1]
  dt2 <-
    "../data/gram2final.csv" %>%
    fread %>%
    setnames(c("word1", "word2", "count2")) %>%
    .[count2 > 1]
  dt1 <-
    "../data/gram1final.csv" %>%
    fread %>%
    setnames(c("word1", "count1")) %>%
    .[count1 > 1]
  merge(dt3, dt2, by=c("word1", "word2")) %>%
    merge(dt1, by="word1") %>%
    .[order(-count3, -count2, -count1)] %>%
    .[,.SD[1], by=.(word1, word2)] %>%
    .[, .(word1, word2, word3)] %>%
    write.csv("simple3gram.csv", row.names = FALSE, quote=FALSE)
}

simplePredictor1 <- function() {
  dt1 <- fread("simple1gram.csv", header=TRUE)
  f <- function(splitted) {
    dt1[1, word1]
  }
  return(f)
}

simplePredictor2 <- function(f1) {
  dt2 <- fread("simple2gram.csv", header=TRUE)
  f <- function(splitted) {
    n <- length(splitted)
    pred <- dt2[word1 == splitted[n], word2]
    if (length(pred) != 0) {
      pred
    } else {
      f1(splitted)
    }
  }
  return(f)
}

simplePredictor3 <- function(f2) {
  dt3 <- fread("simple3gram.csv", header=TRUE)
  f <- function(splitted) {
    n <- length(splitted)
    pred <- dt3[word1 == splitted[n-1] & word2 == splitted[n], word3]
    if (length(pred) != 0) {
      pred
    } else {
      f2(splitted)
    }
  }
  return(f)
}

simplePredictor <- function() {
  f1 <- simplePredictor1()
  f2 <- simplePredictor2(f1)
  f3 <- simplePredictor3(f2)
  
  sp <- function(text) {
    splitted <- splitText(text)[[1]]
    n <- length(splitted)
    if (n == 0) {
      f1(splitted)
    } else {
      if (n == 1) {
        f2(splitted)
      } else {
        f3(splitted)
      }
    }
    
  }
  return(sp)
}
