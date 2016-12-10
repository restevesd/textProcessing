#include <stdio.h>

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
  if (lookupWord(table, "ala") == -1) {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }
  addWord(table, "ala");
  if (lookupWord(table, "ala") == 1) {
    printf("OK\n");
  } else {
    printf("not ok\n");
  }

}
