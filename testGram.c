#include <stdio.h>
#include <string.h>

#include "wordCounter.h"


int main() {
  Gram *table[HASH_SIZE];
  initHashTable(table);

  Gram *entry0 = table[0];
  if (entry0 == NULL) {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }
  if (lookupWord(table, "ala") == NULL) {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }
  addWord(table, "A");
  addWord(table, "A");
  addWord(table, "AA");
  Gram *grama = lookupWord(table, "A");
  Gram *gramaa = lookupWord(table, "AA");
  if ((grama != NULL) &&
      (strcmp(grama->word, "A") == 0) &&
      (grama->count == 2)) {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }
  if ((gramaa != NULL) &&
      (strcmp(gramaa->word, "AA") == 0) &&
      (gramaa->count == 1)) {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }
}
