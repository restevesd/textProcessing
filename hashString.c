#include "wordCounter.h"

unsigned int hashString(char *word) {
  int hashValue = 0;
  for (int i = 0; word[i] != '\0'; i++) {
    hashValue = (hashValue + (word[i] - 'A')) % HASH_SIZE;
  }
  return hashValue;
}
