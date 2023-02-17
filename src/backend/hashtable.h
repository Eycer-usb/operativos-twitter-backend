#if !defined(HASH_TABLE)

#define HASH_TABLE

typedef struct hash_table HashTable;

#include "list.h"

struct hash_table
{
	List** tablePtr;	
};

int initHashTable( HashTable* );
unsigned long int hashFun( char string[20] );
int addToHashTable( HashTable* hashtable, User* user );
User* getUserFromHashTable( HashTable* hashtable, char* username );

#endif // HASH_TABLE
