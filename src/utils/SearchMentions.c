#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchMentions.h"

void searchAtWords(char *str)
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
            printf("Palabra encontrada: %s\n", token);
        }
        token = strtok(NULL, delimiter);
    }
    free(tweet);
}