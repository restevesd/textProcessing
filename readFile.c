#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "wordCounter.h"


GramBT *readFileBT(char *file_name, GramBT *gramBT, int K) {
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  char word[MAX_WORD];
  char wordm1[MAX_WORD];
  char wordm2[MAX_WORD];
  char wordm3[MAX_WORD];
  int lines_counter = 0;
  fp = fopen(file_name, "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);

  GramBT **gram_added = malloc(sizeof(GramBT*));
  GramBT **gramm1_added = malloc(sizeof(GramBT*));
  GramBT **gramm2_added = malloc(sizeof(GramBT*));
  GramBT **gramm3_added = malloc(sizeof(GramBT*));
  
  while ((read = getline(&line, &len, fp)) != -1) {
    if ((rand() % K) ==  0) {
      if (lines_counter % 10000 == 0) printf("line: %d\n", lines_counter);
      wordm1[0] = '\0';
      wordm2[0] = '\0';
      wordm3[0] = '\0';
      int j = 0;
      for (int i = 0; i < read; i++) {
        if (line[i] != 13) {
          if (line[i] == ' ' || line[i] == '\n')  {
            if (j != 0) {
              word[j] = '\0';
              if (wordm3[0] != '\0') {
                (*gramm2_added)->next =
                    addWordBT((*gramm2_added)->next, word, gramm3_added);
              } 
              if (wordm2[0] != '\0') {
                strcpy(wordm3, wordm2);
                (*gramm1_added)->next =
                    addWordBT((*gramm1_added)->next, word, gramm2_added);
              } 
              if (wordm1[0] != '\0') {
                strcpy(wordm2, wordm1);
                (*gram_added)->next =
                    addWordBT((*gram_added)->next, word, gramm1_added);
              } 
              gramBT = addWordBT(gramBT, word, gram_added);
              strcpy(wordm1, word);
              j = 0;
            }
          } else {
            word[j++] = line[i];
          }
        }
      }
      lines_counter++;
    } 
  }
  
  fclose(fp);
  if (line)
    free(line);
  return gramBT;
}
