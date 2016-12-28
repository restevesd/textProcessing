#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "wordCounter.h"


int main() {
  GramBT *gram=NULL;
  if (lookupWordBT(gram, "ala") == NULL) {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }
  
  GramBT **gram_added = malloc(sizeof(GramBT*));
  GramBT **gramm1_added = malloc(sizeof(GramBT*));
  gram = addWordBT(gram, "B", gram_added);
  if ((gram != NULL) &&
      (strcmp(gram->word, "B") == 0) &&
      (gram->count == 1)) {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }
  (*gram_added)->next = addWordBT((*gram_added)->next, "BA", gramm1_added); 
  gram = addWordBT(gram, "BA", gram_added);
  if ((gram != NULL) &&
      (strcmp(gram->word, "B") == 0) &&
      (gram->count == 1)) {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }

  GramBT *grama = lookupWordBT(gram, "B");
  if ((grama != NULL) &&
      (strcmp(grama->word, "B") == 0) &&
      (grama->count == 1)) {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }
  if ((grama->r != NULL) &&
    (strcmp(grama->r->word, "BA") == 0) &&
    (grama->r->count == 1))
  {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }
  if ((grama->next != NULL) &&
      (strcmp(grama->next->word, "BA") == 0) &&
      (grama->next->count == 1)) {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }
  if ((grama != NULL) &&
      (strcmp(grama->word, "B") == 0) &&
      (grama->count == 1)) {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }
  gram = addWordBT(gram, "AB", gram_added);
  gram = addWordBT(gram, "AB", gram_added);
  if ((gram != NULL) &&
      (strcmp(gram->word, "B") == 0) &&
      (gram->count == 1)) {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }

  if ((gram->l != NULL) &&
    (strcmp(gram->l->word, "AB") == 0) &&
     (gram->l->count == 2))
  {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }

  /* Gram *gramaa = lookupWord(table, "AA"); */
  /* if ((gramaa != NULL) && */
  /*     (strcmp(gramaa->word, "AA") == 0) && */
  /*     (gramaa->count == 1)) { */
  /*   printf("OK\n"); */
  /* } else { */
  /*   printf("not ok\n"); */
  /* } */
  /* Gram *gramMax = findMax(table)[0]; */
  /* printf("%s\n", gramMax->word); */
}
