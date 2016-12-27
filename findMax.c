#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "wordCounter.h"

//#define FILE_NAME "data/en_US.twitter.clean.txt"
#define FILE_NAME "data/test.txt"

int main() {
  GramBT *gramBT = NULL;
  gramBT = readFileBT(FILE_NAME, gramBT, 1);
  GramBT **maxtable=malloc(sizeof(GramBT*)*MAX_TABLE_SIZE);
  for (int i = 0; i < MAX_TABLE_SIZE; i++) {
    maxtable[i] = NULL;
  }
  findMaxBT(gramBT, maxtable);
  //Gram **maxtable = findMax(table);
  for (int i = 0; i < MAX_TABLE_SIZE; i++) {
    printf("%s: %d\n",
         maxtable[i]->word,
         maxtable[i]->count);
  }
}
