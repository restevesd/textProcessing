#include <stdio.h>

#define HASH_SIZE 30017
#define MAX_WORD 20000
#define MAX_TABLE_SIZE 30

unsigned int hashString(char *);

typedef struct gram Gram;

struct gram {
  char *word;
  unsigned int count;
  Gram *next;
};

void initHashTable(Gram **table);

Gram *lookupWord(Gram **table, char *word);
int addWord(Gram **table, char *word);

Gram **findMax(Gram **table);

typedef struct _gramBT GramBT;

struct _gramBT {
  char *word;
  unsigned int count;
  GramBT *l, *r;
  GramBT *next;
};

GramBT *lookupWordBT(GramBT *gramBT, char *word);
GramBT *addWordBT(GramBT *gramBT, char *word, GramBT **gram_added);
int findMaxBT(GramBT *gramBT, GramBT **maxtable);
void print_grams(GramBT *gram, char *prefix);
void fprint_1grams(FILE *f, GramBT *gram);
void fprint_12grams(FILE *f, GramBT *gram);

GramBT *readFileBT(char *file_name, GramBT *gramBT, int K);

