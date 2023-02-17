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

User *logIn(HashTable *table)
{
    char username[20];
    char password[20];

    do
    {
        clear();
        printf("\nLOGIN");
        printf("\n\nEnter username: ");
        scanf("%s", username);
        printf("\nEnter password: ");
        scanf("%s", password);

    } while (!getUserFromHashTable(table, username));
    // User* user = getUserFromHashTable(table, username);
    // printf("%s", user->username);
    // scanf("%s", username);
    // printList(user->tweets);

    return getUserFromHashTable(table, username);
}

/**
 * This function allows the user to sign in by entering their username, password and verifying their password
 * It returns a User struct containing the entered information
 * @return User: a struct containing the entered username and password
 */
User *signIn(HashTable *table)
{
    char username[20];
    char password[20];
    char passwordVerification[20];

    do
    {
        int i = 0;
        clear();
        printf("\033[0;31m");
        printf("\n\nSIGN IN");
        printf("\n\nEnter username: ");
        scanf("%19s", username);

        printf("\033[0;31m");
        printf("\nEnter password: ");
        printf("\033[0;37m");
        scanf("%19s", password);

        do
        {
            if (i == 0)
            {
                printf("\033[0;31m");
                printf("\nRepeat password: ");
                printf("\033[0;37m");
                scanf("%19s", passwordVerification);
            }
            else
            {
                printf("\033[0;31m");
                printf("\nPasswords do not match");
                printf("\nRepeat password: ");
                printf("\033[0;37m");
                scanf("%19s", passwordVerification);
            }
            i = 1;
        } while (strcmp(password, passwordVerification) != 0);
    } while (getUserFromHashTable(table, username));

    User *user = malloc(sizeof(User));
    if (!user)
    {
        printf("Error: could not allocate memory for User\n");
        return NULL;
    }
    initUser(user, username, password);
    addToHashTable(table, user);
    return getUserFromHashTable(table, username);
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

    // clear();
    printf("\033[0;31m");
    printf("\n\nARE YOU LEAVING?");
    printf("\n\nEnter username: ");

    printf("\033[0;37m");
    scanf("%s", username);

    printf("\033[0;31m");
    printf("\nEnter password: ");

    printf("\033[0;37m");
    scanf("%s", password);

    printf("\n%i\n", strcmp(username, user->username));

    while (!isLoggedOut)
    {
        if (strcmp(username, user->username) == 0 && verifyPassword(user, password))
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
User *logger(HashTable *table)
{

    int option = loggerOptions();
    if (option == 1)
    {
        return logIn(table);
    }
    else if (option == 2)
    {
        return signIn(table);
    }
    else
    {
        printf("\033[0;36m");
        printf("\nCOME BACK SOON!\n");
        return NULL;
    }
}