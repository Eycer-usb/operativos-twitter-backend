#include <stdio.h>
#include <string.h>
#include "./../backend/user.h"
#include "auth.h"
#define clear() printf("\033[H\033[J");

int prompt(User *user)
{
    int should_continue = 1;

    while (should_continue)
    {
        char prompt[50];

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
            should_continue = 0;
            break;

        case '@':
            /* Busca los tweets del otro usuario */
            printf("Usuario buscado\n");
            should_continue = 0;
            break;

        default:
            if (!strcmp(prompt, "logout"))
            {
                printf("Logout\n");
                should_continue = 0;
            }
            else
            {
                printf("\033[0;31mEntrada inválida\n");
            }
            break;
        }
    }

    return 1;
}

int searchUser(char *username)
{

    // strcmp()
}

void dashboard(User user)
{
    printf("\n@%s", user.username);
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
    clear();
    User user = logger();
    do
    {
        clear();
        dashboard(user);
        prompt(&user);
        printList(user.tweets);
    } while (1);
}