#include <stdio.h>
#include <string.h>

#include "wordCounter.h"


int main() {
  FILE *file = fopen("data/en_US.test.clean.txt", "r");
  //FILE *file = fopen("data/test.txt", "r");
  char word[MAX_WORD];
  Gram *table[HASH_SIZE];
  initHashTable(table);

  while (!feof(file)) {
    fscanf(file, "%s", word);
    addWord(table, word);
  }
  Gram *entry = lookupWord(table, word);
  (entry->count)--;

  Gram **maxtable = findMax(table);
  for (int i = 0; i < MAX_TABLE_SIZE; i++) {
    printf("%s: %d\n",
         maxtable[i]->word,
         maxtable[i]->count);
  }
}

  
