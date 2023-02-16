#include <stdio.h>
#include <string.h>
#include "auth.h"
#define clearColor() printf("\033[H\033[J");  // clear() ya es una función del sistema.

int loggerOptions()
{
    int option;

    do
    {
        clearColor();
        printf("\n1. Login");
        printf("\n2. Sign in");

        if (option == 0)
        {
            printf("\n\nSelect an option to continue: ");
        }
        else
        {
            printf("\n\nSelect one of the options shown: ");
        }

        scanf("%i", &option);

        switch (option)
        {
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            printf("\nInvalid option. Try again.\n");
            option = 0; // Si la opción ingresada es inválida, se restablece la opción a 0 para mostrar el mensaje correcto
            break;
        }
    } while (1);
}

User logIn()
{
    clearColor();
    char username[20];
    char password[20];
    printf("\nLOGIN");
    printf("\n\nEnter username: ");
    scanf("%s", username);
    printf("\nEnter password: ");
    scanf("%s", password);

    /*
    DETERMINAR EXISTENCIA DE USUARIO
    */

    User user;
    initUser(&user, username, password);

    return user;
}

User signIn()
{
    char username[20];
    char password[20];
    char passwordVerification[20];
    int i = 0;

    clearColor();
    printf("\033[0;31m");
    printf("\n\nSIGN IN");
    printf("\n\nEnter username: ");

    printf("\033[0;37m");
    scanf("%s", username);

    printf("\033[0;31m");
    printf("\nEnter password: ");

    printf("\033[0;37m");
    scanf("%s", password);

    do
    {
        if (i == 0)
        {
            printf("\033[0;31m");
            printf("\nRepeat password: ");

            printf("\033[0;37m");
            scanf("%s", passwordVerification);
        }
        else
        {
            printf("\033[0;31m");
            printf("\nPasswords do not match");
            printf("\nRepeat password: ");

            printf("\033[0;37m");
            scanf("%s", passwordVerification);
        }
        i = 1;
    } while (strcmp(password, passwordVerification) != 0);

    /*
        DETERMINAR EXISTENCIA DEL USUARIO
    */

    User user;
    initUser(&user, username, password);

    return user;
}

User logger()
{
    User user;
    int option = loggerOptions();
    if (option == 1)
    {
        user = logIn();
    }
    else if (option == 2)
    {
        user = signIn();
    }
    return user;
}