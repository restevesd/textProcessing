#define HASH_SIZE 100
#define MAX_WORD 100

unsigned int hashString(char *);

typedef struct gram Gram;
void initHashTable(Gram **table);
Gram *lookupWord(Gram **table, char *word);

struct gram {
  char word[MAX_WORD];
  int count;
  struct gram *next;
};


int addWord(Gram **table, char *word);



