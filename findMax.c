#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "wordCounter.h"

#define FILE_NAME1 "data/en_US.twitter.clean.txt"
#define FILE_NAME2 "data/en_US.blogs.clean.txt"
#define FILE_NAME3 "data/en_US.news.clean.txt"
//#define FILE_NAME "data/test.txt"

int main() {
  GramBT *gramBT = NULL;
  gramBT = readFileBT(FILE_NAME1, gramBT, 1);
  gramBT = readFileBT(FILE_NAME2, gramBT, 1);
  gramBT = readFileBT(FILE_NAME3, gramBT, 1);
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
  //printf("----\n");
  FILE *f1 = fopen("data/gram1final.csv", "w");
  fprint_1grams(f1, gramBT);
  fclose(f1);

  FILE *f2 = fopen("data/gram2final.csv", "w");
  fprint_12grams(f2, gramBT);
  fclose(f2);

  FILE *f3 = fopen("data/gram3final.csv", "w");
  fprint_123grams(f3, gramBT);
  fclose(f3);

}
