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
    new_entry->word = malloc(sizeof(char) * (strlen(word)+1));
    strcpy(new_entry->word, word);
    new_entry->count = 1;
    new_entry->next = old_entry;
    table[idx] = new_entry;
  } else {
    entry->count++;
  }
  return -1;
}

Gram **findMax(Gram **table) {
  Gram **maxtable=malloc(sizeof(Gram*)*MAX_TABLE_SIZE);
  for (int i = 0; i < MAX_TABLE_SIZE; i++) {
    maxtable[i] = NULL;
  }
  Gram *gramMax = NULL;
  for (int i = 0; i < HASH_SIZE; i++) {
    for (Gram *entry = table[i]; entry != NULL; entry=(entry->next)) {
      if (gramMax == NULL || (gramMax->count) < (entry->count)) {
        gramMax = entry;
      }
    
  
      int j = MAX_TABLE_SIZE-1;
      while(j > 0 &&
            (maxtable[j] == NULL ||
             (maxtable[j]->count) < (entry->count))) {
        maxtable[j] = maxtable[j-1];
        j--;
      }
      if (j < MAX_TABLE_SIZE-1) {
        if (maxtable[j] == NULL || (maxtable[j]->count) < (entry->count)) {
          maxtable[j] = entry;
        } else {
          maxtable[j+1] = entry;
        } 
      } 
    }
  }
  return maxtable;
}
