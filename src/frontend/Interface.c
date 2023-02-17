#include <stdio.h>
#include <string.h>
#include "./../backend/user.h"
#include "./../backend/hashtable.h"
#include "auth.h"
#define clear() printf("\033[H\033[J");

int prompt(User *user, HashTable *table)
{
    int should_continue = 0;

    while (!should_continue)
    {
        char prompt[281];

        printf("\033[0;31mPrompt: ");
        printf("\033[0;37m");
        scanf(" %[^\n]", prompt);

        switch (prompt[0])
        {
        case '+':
            /* Elimina el símbolo "+" del prompt */
            memmove(prompt, prompt + 1, strlen(prompt));
            newTweet(user, prompt);
            printf("Tweet enviado\n");
            should_continue = 1;
            break;

        case '@':
            /* Busca los tweets del otro usuario */
            printf("Usuario buscado\n");
            should_continue = 1;
            break;

        default:
            if (!strcmp(prompt, "logout"))
            {
                printf("Logout\n");
                // logOut(user, table);
                should_continue = -1;
            }
            else if (strcmp(prompt, "logout") && strlen(prompt) > 1)
            {
                printf("\033[0;31mEntrada inválida\n");
            }
            break;
        }
    }
    return should_continue;
}

int searchUser(char *username)
{

    // strcmp()
}

void dashboard(User *user)
{
    printf("\n@%s", user->username);
    printf("\nTweets: %i", 1550);
    printf("\nFollowing: %i", 123);
    printf("\nFollowers: %i", 9321);
    printf("\n");
    printf("\nMy Tweets\n");
    /*
    IMPRMIR LISTA DE TWITTS DE SEGUIDORES
    */
}

/**
 * This function allows the user to see the GUI and interact with the differents Auth
 * and twitter options.
 */
int interface()
{

    HashTable table;
    initHashTable(&table);
    // newTweet(&blanyer, "primer twitt");
    do
    {
        User *user;
        user = logger(&table);
        do
        {
            printf("probando");
            clear();
            dashboard(user);
            printList(user->tweets);
        } while (prompt(user, &table) != -1);
    } while (1);
}