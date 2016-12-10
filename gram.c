#include "wordCounter.h"

struct gram {
  char *word;
  int *count;
  struct gram *next;
};

void initHashTable(Gram **table) {
  for (int i = 0; i < HASH_SIZE; i++) {
    table[i] = 0;
  }
}

int lookupWord(Gram **table, char *word) {
  return -1;
}

int addWord(Gram **table, char *word) {
  return -1;
}




