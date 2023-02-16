#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "auth.h"
#include "./../backend/hashtable.h"
#define clear() printf("\033[H\033[J"); // clear() ya es una función del sistema.

int loggerOptions()
{
    char option[6];

    do
    {
        clear();
        printf("\033[0;32m");
        printf("DON'T MISS WHAT'S HAPPENING! LOGIN, SIGNUP OR LEAVE\n");
        printf("\033[0m");
        printf("\n1. login");
        printf("\n2. signup");
        printf("\n3. leave");

        printf("\n\nPlease type an option to continue: ");
        scanf("%s", option);

        if (strcmp(option, "login") == 0)
        {
            return 1;
        }
        else if (strcmp(option, "signup") == 0)
        {
            return 2;
        }
        else if (strcmp(option, "leave") == 0)
        {
            return 3;
        }
        else
        {
            printf("\nInvalid option. Try again.\n");
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
 * Register the current user logger in the bucket, then logout.
 */
void logOut(User *user, HashTable *table)
{
    int isLoggedOut = 0;
    char username[20];
    char password[20];
    int i = 0;

    clear();
    printf("\033[0;31m");
    printf("\n\nARE YOU LEAVING?");
    printf("\n\nEnter username: ");

    printf("\033[0;37m");
    scanf("%s", username);

    printf("\033[0;31m");
    printf("\nEnter password: ");

    printf("\033[0;37m");
    scanf("%s", password);
    while (!isLoggedOut)
    {
        if (username == user->username && verifyPassword(user, password))
        {
            addToHashTable(table, user);
            loggerOptions();
            isLoggedOut = 1;
        }
        else
        {
            printf("\033[0;31m");
            printf("WRONG USERNAME OR PASSWORD, TRY AGAIN!\n");
            printf("\033[0m");
            logOut(user, table);
        }
    }
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