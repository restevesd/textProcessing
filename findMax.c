#include <stdio.h>
#include <string.h>

#include "wordCounter.h"


int main() {
  FILE *file = fopen("data/test.txt", "r");
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
  printf("%s\n", gramMax->word);
}
