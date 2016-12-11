#define HASH_SIZE 100
#define MAX_WORD 100

unsigned int hashString(char *);

typedef struct gram Gram;

struct gram {
  char word[MAX_WORD];
  int count;
  struct gram *next;
};

void initHashTable(Gram **table);
Gram *lookupWord(Gram **table, char *word);
int addWord(Gram **table, char *word);
Gram *findMax(Gram **table);
