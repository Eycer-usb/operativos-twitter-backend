#include <stdio.h>
#include <string.h>
#include "./../backend/user.h"
#include "auth.h"
#define clearColor() printf("\033[H\033[J");

int prompt(User *user)
{
    int i = 1;
    do
    {
        char prompt[50];
        printf("\033[0;31m");
        printf("\nPrompt: ");

        printf("\033[0;37m");
        fgets(prompt, 50, stdin);
        if (prompt[0] == '+')
        {
            /*
                USAR CODIGO PARA ELIMINAR SIMBOLO + DEL PROMPT Y RESET
            */
            newTweet(user, prompt);
            printf("\nTWITT ENVIADO");
            i = 0;
        }
        else if (prompt[0] == '@')
        {
            /*
                BUSCAR LOS TWITTS DEL OTRO USUARIO
            */
            printf("USUARIO BUSCADO");
            i = 0;
        }
        else if (!strcmp(prompt, "logout"))
        {
            /*
                SALIR
            */
            printf("\nLOGOUT");
            i = 0;
        }
        else
        {
            printf("\033[0;31m");
            printf("\nINVALID ENTRY");
        }
    } while (i);

    return 1;
}

int searchUser(char *username)
{

    // strcmp()
}

void dashboard(User user)
{
    printf("\n@%s", user.username);
    printf("\nMy number of Tweets: %i", 1548);
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
    User user1;
    initUser(&user1, "eycer", "Eros#123");

    User user = logger();
    do
    {
        clearColor();
        dashboard(user);
        printList(user.tweets);
        prompt(&user);
    } while (1);

    /*
    SEPARAR OPCIONES ENTRE USER y OWNER
    */
}