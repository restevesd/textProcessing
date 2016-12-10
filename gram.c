#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordCounter.h"

void initHashTable(Gram **table) {
  for (int i = 0; i < HASH_SIZE; i++) {
    table[i] = 0;
  }
}

Gram *lookupWord(Gram **table, char *word) {
  Gram *entry = table[hashString(word)];
  while (entry != NULL) {
    if (strcmp(entry->word, word) == 0) {
      return entry;
    } else {
      entry = entry->next;
    }
  }
  return NULL;
}

int addWord(Gram **table, char *word) {
  Gram *entry = lookupWord(table, word);
  if (entry == NULL) {
    int idx = hashString(word);
    Gram *old_entry = table[idx];
    Gram *new_entry = malloc(sizeof(Gram));
    strcpy(new_entry->word, word);
    new_entry->count = 1;
    new_entry->next = old_entry;
    table[idx] = new_entry;
  } else {
    entry->count++;
  }
  return -1;
}




