#include <stdio.h>
#include <string.h>

#include "wordCounter.h"


int main() {
  FILE *file = fopen("data/en_US.test.clean.txt", "r");
  char word[MAX_WORD];
  Gram *table[HASH_SIZE];
  initHashTable(table);

  while (!feof(file)) {
    fscanf(file, "%s", word);
    addWord(table, word);
  }
  Gram *entry = lookupWord(table, word);
  (entry->count)--;

  Gram *gramMax = findMax(table);
  printf("%s: %d\n", gramMax->word, gramMax->count);
}
