#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "auth.h"
#define clear() printf("\033[H\033[J"); // clear() ya es una función del sistema.

int loggerOptions()
{
    int option;

    do
    {
        clear();
        printf("\033[0;32m");
        printf("DON'T MISS WHAT'S HAPPENING! LOGIN, SIGNUP OR LEAVE\n");
        printf("\033[0m");
        printf("\n1. Login");
        printf("\n2. Sign in");
        printf("\n3. Leave");

        if (option == 0)
        {
            printf("\n\nSelect an option to continue: ");
        }
        else
        {
            printf("\n\nSelect one of the options shown: ");
        }

        scanf("%i", &option);

        if (1 <= option <= 3)
        {
            return option;
        }
        else
        {
            printf("\nInvalid option. Try again.\n");
            option = 0; // Si la opción ingresada es inválida, se restablece la opción a 0 para mostrar el mensaje correcto
        }
    } while (1);
}

User logIn()
{
    clear();
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

/**
 * This function allows the user to sign in by entering their username, password and verifying their password
 * It returns a User struct containing the entered information
 * @return User: a struct containing the entered username and password
 */
User signIn()
{
    char username[20];
    char password[20];
    char passwordVerification[20];
    int i = 0;

    clear();
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

/**
 * Prompts the user to either log in, sign up or leave.
 * @return User: the user that logged in or signed up
 */
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
    else
    {
        printf("\033[0;36m");
        printf("\nCOME BACK SOON!\n");
        exit(0);
    }
    return user;
}