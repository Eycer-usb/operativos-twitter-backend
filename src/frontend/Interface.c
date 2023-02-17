#include <stdio.h>
#include <string.h>
#include "./../backend/user.h"
#include "./../backend/hashtable.h"
#include "auth.h"
#define clear() printf("\033[H\033[J");

void dashboard(User *user)
{   
    printf("\n@%s", user->username);
    printf("\nTweets: %i", 1550);
    printf("\nFollowing: %i", 123);
    printf("\nFollowers: %i", 9321);
    printf("\n");
    printf("\nMy Tweets\n");
    printList(user->tweets);

}

int promptVisit(User *user, User *userV) 
{
    int should_continue = 0;

    while (!should_continue)
    {
        char prompt[281];

        printf("\033[0;31mPrompt: ");
        printf("\033[0;37m");
        scanf(" %[^\n]", prompt);

        if (prompt == "follow") {
            follow(user, userV);
            break;
        } else {
            if (!strcmp(prompt, "return"))
            {
                should_continue = -1;
            }
            else if (strcmp(prompt, "return") && strlen(prompt) > 1)
            {
                printf("\033[0;31mEntrada inválida\n");
            }
            break;
        }
    }
    clear();
    return should_continue;
}

void dashboardVisit(User *user, User *userV)
{   
    do
    {   
        printf("\n%s's profile  %s", userV->username, "seguido");
        printf("\nFollowing: %i", 123);
        printf("\nFollowers: %i", 9321);
        printf("\n");
        printf("\nMy Tweets\n");
        printList(userV->tweets);
    } while (promptVisit(user, userV) != -1);
}

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
            clear();
            break;

        case '@':
            /* Busca los tweets del otro usuario */
            clear();
            dashboardVisit(user, getUserFromHashTable(table, memmove(prompt, prompt + 1, strlen(prompt))));
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
        if (user == NULL)
        {
            break;
        }
        do
        {
            dashboard(user);
        } while (prompt(user, &table) != -1);
    } while (1);
}