
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

/*
   The number of buckets in the hash table.
*/
#define TABLE_SIZE 3581

/**
 * Initializes a HashTable instance with a given table size, creates a dynamic array of List pointers and initializes each
 * of them using the initList function. If any memory allocation fails, the function returns 0 to indicate an error.
 * @param table: A pointer to the HashTable instance to be initialized.
 * @return: Returns 1 on success, 0 on failure.
 */
int initHashTable(HashTable *table)
{
    table->tablePtr = (List **)malloc(sizeof(List *) * TABLE_SIZE);
    if (table->tablePtr == NULL)
    {
        return 0;
    }

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table->tablePtr[i] = (List *)malloc(sizeof(List));
        if (table->tablePtr[i] == NULL)
        {
            return 0;
        }

        initList(table->tablePtr[i]);
    }
    return 1;
}

/**
 * Hashes the given string using the djb2 algorithm and returns the resulting hash.
 *
 * @param string a null-terminated string to be hashed
 * @return an unsigned long integer representing the hash value of the given string
 */
unsigned long int hashFun(char *string)
{
    unsigned long hash = TABLE_SIZE;
    char *str = string;
    int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

/**
 * Add a User to the Hash Table
 *
 * @param hashtable: A pointer to the HashTable.
 * @param user: A pointer to the User to be added.
 *
 * @return 1 if the User is successfully added to the HashTable, 0 otherwise.
 */
int addToHashTable(HashTable *hashtable, User *user)
{
    char *key = user->username;
    unsigned long int hashed_key = hashFun(key);
    List *bucket = hashtable->tablePtr[hashed_key % TABLE_SIZE];
    ListContent *content = (ListContent *)malloc(sizeof(ListContent));
    content->user = user;
    bucket = listPush(bucket, content, time(NULL), key);
    if (bucket != NULL)
    {
        hashtable->tablePtr[hashed_key % TABLE_SIZE] = bucket;
        return 1;
    }

    return 0;
}

/**
 * Returns a pointer to the User object in the hashtable with the given username, if it exists.
 * If no User object is found, returns NULL.
 *
 * Parameters:
 * - hashtable: a pointer to the hashtable to search in
 * - username: a pointer to a string with the username of the user to look up
 *
 * Returns:
 * - a pointer to the User object with the given username, if it exists in the hashtable
 * - NULL if no User object with the given username is found in the hashtable
 */
User *getUserFromHashTable(HashTable *hashtable, char *username)
{
    unsigned long int hashed_key = hashFun(username);
    List *bucket = hashtable->tablePtr[hashed_key % TABLE_SIZE];
    while (bucket->next)
    {
        if (strcmp(bucket->owner, username) == 0)
        {
            return bucket->content->user;
        }

        bucket = bucket->next;
    }
    return NULL;
}
