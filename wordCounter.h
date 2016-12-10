#define HASH_SIZE 100

unsigned int hashString(char *);

typedef struct gram Gram;
void initHashTable(Gram **table);
int lookupWord(Gram **table, char *word);
int addWord(Gram **table, char *word);



