#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordCounter.h"


GramBT *lookupWordBT(GramBT *gramBT, char *word) {
  if (gramBT == NULL) {
    return NULL;
  }
  short int c = strcmp(gramBT->word, word);
  if (c == 0) return gramBT;
  if (c == -1) return lookupWordBT(gramBT->l, word);
  return lookupWordBT(gramBT->r, word);
} 

GramBT *addWordBT(GramBT *gramBT, char *word, GramBT **gram_added) {
  if (gramBT == NULL) {
    GramBT *new_gram = malloc(sizeof(GramBT));
    new_gram->word = malloc(sizeof(char) * (strlen(word)+1));
    strcpy(new_gram->word, word);
    new_gram->count = 1;
    new_gram->l = NULL;
    new_gram->r = NULL;
    new_gram->next = NULL;
    *gram_added = new_gram;
    return new_gram;
  } 
  short int c = strcmp(gramBT->word, word);
  if (c == 0) {
    (gramBT->count)++;
    *gram_added = gramBT;
    return gramBT;
  }
  if (c == -1) {
    (gramBT->l) = addWordBT(gramBT->l, word, gram_added);
  } else {
    (gramBT->r) = addWordBT(gramBT->r, word, gram_added);
  }
  return gramBT;
}

int findMaxBT(GramBT *gramBT, GramBT **maxtable) {

  if (gramBT == NULL) return 0;
  findMaxBT(gramBT->l, maxtable);
  int j = MAX_TABLE_SIZE-1;
  while(j > 0 &&
        (maxtable[j] == NULL ||
         (maxtable[j]->count) < (gramBT->count))) {
    maxtable[j] = maxtable[j-1];
    j--;
  }
  if (j < MAX_TABLE_SIZE-1) {
    if (maxtable[j] == NULL || (maxtable[j]->count) < (gramBT->count)) {
      maxtable[j] = gramBT;
    } else {
      maxtable[j+1] = gramBT;
    } 
  } 
  findMaxBT(gramBT->r, maxtable);
  return 0;
}

void print_grams(GramBT *gram, char *prefix) {
  if (gram != NULL) {
    print_grams(gram->l, prefix);
    printf("%s%s:%d\n", prefix, gram->word, gram->count);
    /* if (gram->next != NULL) { */
    /*   print_grams(gram->next, "---"); */
    /* } */
    print_grams(gram->r, prefix);
  }
}
