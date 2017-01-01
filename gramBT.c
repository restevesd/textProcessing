#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordCounter.h"

GramBT *lookupWordBT(GramBT *gramBT, char *word) {
  if (gramBT == NULL) {
    return NULL;
  }
  short int c = strcmp(gramBT->word, word);
  if (c == 0) return gramBT;
  if (c > 0) return lookupWordBT(gramBT->l, word);
  return lookupWordBT(gramBT->r, word);
} 

GramBT *addWordBT(GramBT *gramBT, char *word, GramBT **gram_added) {
  if (gramBT == NULL) {
    GramBT *new_gram = malloc(sizeof(GramBT));
    new_gram->word = malloc(sizeof(char) * (strlen(word)+1));
    strcpy(new_gram->word, word);
    new_gram->count = 1;
    new_gram->l = NULL;
    new_gram->r = NULL;
    new_gram->next = NULL;
    *gram_added = new_gram;
    return new_gram;
  } 
  short int c = strcmp(gramBT->word, word);
  if (c == 0) {
    (gramBT->count)++;
    *gram_added = gramBT;
    return gramBT;
  }
  if (c > 0) {
    (gramBT->l) = addWordBT(gramBT->l, word, gram_added);
  } else {
    (gramBT->r) = addWordBT(gramBT->r, word, gram_added);
  }
  return gramBT;
}

int findMaxBT(GramBT *gramBT, GramBT **maxtable) {

  if (gramBT == NULL) return 0;
  findMaxBT(gramBT->l, maxtable);
  int j = MAX_TABLE_SIZE-1;
  while(j > 0 &&
        (maxtable[j] == NULL ||
         (maxtable[j]->count) < (gramBT->count))) {
    maxtable[j] = maxtable[j-1];
    j--;
  }
  if (j < MAX_TABLE_SIZE-1) {
    if (maxtable[j] == NULL || (maxtable[j]->count) < (gramBT->count)) {
      maxtable[j] = gramBT;
    } else {
      maxtable[j+1] = gramBT;
    } 
  } 
  findMaxBT(gramBT->r, maxtable);
  return 0;
}

void fprint_1grams(FILE *f, GramBT *gram) {
  if (gram != NULL) {
    fprint_1grams(f, gram->l);
    fprintf(f, "%s,%d\n", gram->word, gram->count);
    fprint_1grams(f, gram->r);
  }
}

void fprint_2grams(FILE *f, char *prefix, GramBT *gram) {
  if (gram != NULL) {
    fprint_2grams(f, prefix, gram->l);
    fprintf(f, "%s,%s,%d\n", prefix, gram->word, gram->count);
    fprint_2grams(f, prefix, gram->r);
  }
}

void fprint_12grams(FILE *f, GramBT *gram) {
  if (gram != NULL) {
    fprint_12grams(f, gram->l);
    fprint_2grams(f, gram->word, gram->next);
    fprint_12grams(f, gram->r);
  }
}

void fprint_3grams(FILE *f, char *word1, char *word2, GramBT *gram) {
  if (gram != NULL) {
    fprint_3grams(f, word1, word2, gram->l);
    fprintf(f, "%s,%s,%s,%d\n", word1, word2, gram->word, gram->count);
    fprint_3grams(f, word1, word2, gram->r);
  }
}

void fprint_23grams(FILE *f, char *word1, GramBT *gram) {
  if (gram != NULL) {
    fprint_23grams(f, word1, gram->l);
    fprint_3grams(f, word1, gram->word, gram->next);
    fprint_23grams(f, word1, gram->r);
  }
}

void fprint_123grams(FILE *f, GramBT *gram) {
  if (gram != NULL) {
    fprint_123grams(f, gram->l);
    fprint_23grams(f, gram->word, gram->next);
    fprint_123grams(f, gram->r);
  }
}

void fprint_4grams(FILE *f, char *word1, char *word2, char *word3, GramBT *gram) {
  if (gram != NULL) {
    fprint_4grams(f, word1, word2, word3, gram->l);
    fprintf(f, "%s,%s,%s,%s,%d\n", word1, word2, word3, gram->word, gram->count);
    fprint_4grams(f, word1, word2, word3, gram->r);
  }
}

void fprint_34grams(FILE *f, char *word1, char *word2, GramBT *gram) {
  if (gram != NULL) {
    fprint_34grams(f, word1, word2, gram->l);
    fprint_4grams(f, word1, word2, gram->word, gram->next);
    fprint_34grams(f, word1, word2, gram->r);
  }
}

void fprint_234grams(FILE *f, char *word1, GramBT *gram) {
  if (gram != NULL) {
    fprint_234grams(f, word1, gram->l);
    fprint_34grams(f, word1, gram->word, gram->next);
    fprint_234grams(f, word1, gram->r);
  }
}

void fprint_1234grams(FILE *f, GramBT *gram) {
  if (gram != NULL) {
    fprint_1234grams(f, gram->l);
    fprint_234grams(f, gram->word, gram->next);
    fprint_1234grams(f, gram->r);
  }
}

void print_grams(GramBT *gram, char *prefix) {
  if (gram != NULL) {
    print_grams(gram->l, prefix);
    printf("%s%s:%d\n", prefix, gram->word, gram->count);
    if (gram->next != NULL) {
      print_grams(gram->next, "---");
    }
    print_grams(gram->r, prefix);
  }
}


