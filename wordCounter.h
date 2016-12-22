#define HASH_SIZE 200013
#define MAX_WORD 2000

unsigned int hashString(char *);

typedef struct gram Gram;

struct gram {
  char *word;
  int count;
  struct gram *next;
};

void initHashTable(Gram **table);
Gram *lookupWord(Gram **table, char *word);
int addWord(Gram **table, char *word);
Gram *findMax(Gram **table);
