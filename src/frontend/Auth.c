#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "auth.h"
#include "./../backend/hashtable.h"
#define clear() printf("\033[H\033[J");

/**
 * This function prompts the user to select one of three options: login, signup, or leave.
 * It continues prompting until a valid option is selected. If "login" is selected, the function returns 1.
 *  "signup" is selected, the function returns 2. If "leave" is selected, the function clears the screen and
 * returns 3. If an invalid option is selected, the function prints an error message and continues prompting.
 */

int loggerOptions()
{
    char *option = (char *)malloc(sizeof(char) * 20);

    do
    {
        clear();
        printf("\033[0;32m");
        printf("DON'T MISS WHAT'S HAPPENING! LOGIN, SIGNUP OR LEAVE\n");
        printf("\033[0m");
        printf("\n- login");
        printf("\n- signup");
        printf("\n- leave");

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
            clear();
            return 3;
        }
        else
        {
            printf("\nInvalid option. Try again.\n");
        }

    } while (1);
}

/**
 * This function logs in a user by prompting the user to enter a valid username and password
 * from a hash table of users. If the username entered does not exist in the hash table, the user
 * is prompted to enter a valid username again. If the password entered for the username is
 * incorrect, the user is prompted to enter the correct password. Once a valid username and
 * password are entered, the function returns the corresponding User struct from the hash
 * table.
 */
User *logIn(HashTable *table)
{
    char *username = malloc(20 * sizeof(char));
    char *password = malloc(20 * sizeof(char));

    clear();
    int i = 0;
    do
    {
        if (i == 0)
        {
            printf("\033[0;32m");
            printf("\nLOGIN");
            printf("\033[0m");
            printf("\n\nEnter username (or type 'back' to return to the main menu): ");
            scanf("%s", username);
        }
        else
        {
            printf("\033[0;32m");
            printf("\nLOGIN");
            printf("\033[0m");
            printf("\n\nUsername does not exist");
            printf("\nEnter username (or type 'back' to return to the main menu): ");
            scanf("%s", username);
        }
        i = 1;
    } while (!getUserFromHashTable(table, username));

    i = 1;
    do
    {
        if (i == 1)
        {
            printf("\nEnter password: ");
            scanf("%s", password);
        }
        else
        {
            printf("\n\nWrong Password!");
            printf("\nEnter password again: ");
            scanf("%s", password);
        }
        i = 2;
    } while (!verifyPassword(getUserFromHashTable(table, username), password));
    clear();
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
    char description[161];
    int i = 0;
    clear();

    do
    {
        if (i == 0)
        {
            printf("\033[0;31m");
            printf("SIGN UP");
            printf("\033[0m");
            printf("\n\nEnter username: ");
            scanf("%19s", username);
        }
        else
        {
            printf("\033[0;31m");
            printf("\n\nThe user name already exists");
            printf("\nEnter username: ");
            printf("\033[0m");
            scanf("%19s", username);
        }
        i = 1;
    } while (getUserFromHashTable(table, username));

    printf("\nEnter password: ");
    scanf("%19s", password);

    i = 0;
    do
    {
        if (i == 0)
        {
            printf("\nRepeat password: ");
            scanf("%19s", passwordVerification);
        }
        else
        {
            printf("\033[0;31m");
            printf("\nPasswords do not match");
            printf("\nRepeat password: ");
            printf("\033[0m");
            scanf("%19s", passwordVerification);
        }
        i = 1;
    } while (strcmp(password, passwordVerification) != 0);

    User *user = malloc(sizeof(User));
    if (!user)
    {
        printf("Error: could not allocate memory for User\n");
        return NULL;
    }
    printf("\nWould you like to add a description to your profile? (y/n) ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y')
    {
        printf("\nEnter your description (max 160 characters): ");
        scanf(" %160[^\n]", description);
        initUser(user, username, password, description);
    }
    else
    {
        initUser(user, username, password, "");
    }

    addToHashTable(table, user);

    clear();
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