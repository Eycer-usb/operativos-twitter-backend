#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchMentions.h"
#include "./../backend/hashtable.h"
#include "./../backend/user.h"

void searchAtWords(HashTable* table, User* owner, char *str)
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
            /* Aquí se implementa el proceso de agregar los mentions.  */
            memmove(token, token + 1, strlen(token));
            printf("token %s\n\n\n", token);
            printf("encontrado %s\n\n\n", getUserFromHashTable(table, token)->username);
            newMention(owner, getUserFromHashTable(table, token), str);
            printf("Palabra encontrada: %s\n", token);
            //return getUserFromHashTable(table, token);
        }
        token = strtok(NULL, delimiter);
    }
    free(tweet);
}