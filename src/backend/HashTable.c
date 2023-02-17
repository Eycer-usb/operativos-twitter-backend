/*
    Hash Table Implementation to store user pointers
    The hash table is implemented as an array of linked lists.
*/
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

#define TABLE_SIZE  3581

/*
The Array of Pointers to Linked Lists is created.
*/
int initHashTable( HashTable* table )
{
    table->tablePtr = ( List** ) malloc(sizeof(List*)*TABLE_SIZE);
    if (table->tablePtr == NULL)
    {
        return 0;
    }
    
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table->tablePtr[i] = (List*) malloc(sizeof(List));
        if (table->tablePtr[i] == NULL)
        {
            return 0;
        }
        
        initList(table->tablePtr[i]);
    }
    return 1;
        
}


/*
Hash function to use for mapping
*/
unsigned long int hashFun( char* string ){
    unsigned long hash = TABLE_SIZE;
    char* str = string;
    int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}


/*
Insert a User into the hash table
*/
int addToHashTable( HashTable* hashtable, User* user )
{
    char* key = user->username;
    unsigned long int hashed_key = hashFun( key );
    List* bucket = hashtable->tablePtr[hashed_key % TABLE_SIZE];
    ListContent* content = (ListContent*) malloc(sizeof(ListContent));
    content->user = user;
    bucket = listPush(bucket, content, time(NULL), key);
    if (bucket != NULL)
    {
        hashtable->tablePtr[hashed_key % TABLE_SIZE] = bucket;
        return 1;
    }
    
    return 0;
}

/*
Given the hash table and the username, a pointer to the 
corresponding user structure is returned.
*/
User* getUserFromHashTable( HashTable* hashtable, char* username )
{
    unsigned long int hashed_key = hashFun( username );
    List* bucket = hashtable->tablePtr[hashed_key % TABLE_SIZE];
    while (bucket->next)
    {
        if ( strcmp(bucket->owner, username) == 0)
        {
            return bucket->content->user;
        }
        
        bucket = bucket->next;
    }
    return NULL;
    
}
