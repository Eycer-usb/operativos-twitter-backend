#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchMentions.h"
#include "./../backend/hashtable.h"
#include "./../backend/user.h"

/**
 * Given a HashTable, an owner User and a string, this function searches the string
 * for any words starting with '@' and creates a new mention in the owner User's mentions
 * list for each User that matches a word. The mention consists of the original string and a
 * reference to the User mentioned.
 *
 * @param table A pointer to the HashTable to search for mentioned Users.
 * @param owner A pointer to the User who made the original tweet.
 * @param str The string to search for mentions.
 */
void searchAtWords(HashTable *table, User *owner, char *str)
{
    char *tweet = (char *)malloc(280 * sizeof(char));
    char *token;
    const char *delimiter = " \t\n";
    strcpy(tweet, str);
    token = strtok(tweet, delimiter);
    while (token != NULL)
    {
        if (token[0] == '@')
        {
            memmove(token, token + 1, strlen(token));
            printf("token %s\n\n\n", token);
            printf("encontrado %s\n\n\n", getUserFromHashTable(table, token)->username);
            newMention(owner, getUserFromHashTable(table, token), str);
            printf("Palabra encontrada: %s\n", token);
        }
        token = strtok(NULL, delimiter);
    }
    free(tweet);
}