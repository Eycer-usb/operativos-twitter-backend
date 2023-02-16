#include <stdio.h>
#include <string.h>
#include "./../backend/user.h"
#include "auth.h"
#define clearColor() printf("\033[H\033[J");

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
    printf("\nMy number of Tweets: %i", 1550);
    printf("\nMy number of Following: %i", 123);
    printf("\nMy number of Followers: %i", 9321);
    printf("\n");
    printf("\nMy Twitts\n");
    /*
    IMPRMIR LISTA DE TWITTS DE SEGUIDORES
    */
}

int interface()
{

    User user = logger();
    do
    {
        clearColor();
        dashboard(user);
        printList(user.tweets);
        prompt(&user);
    } while (1);
}