#include "hello.h"
#include <stdio.h>
#include <string.h>

#define clear() printf("\033[H\033[J");

// void printTwitts(User user) 
// {
//     printf("\n");
//     printf("%7s", "TWITTS");
//     printf("\n %s", user.tweets);
//     for (int i = 0; i < 10; i++) {
//         printf("msj");
//     }
// }

int loggerOptions()
{   
    int i = 0;
    int option;
    do
    {
        clear();
        printf("\n 1. Login");
        printf("\n 2. Sign in");
        if (i = 0) {
            printf("\n\n Select an option to continue: ");
        } else {
            printf("\n\n Select one of the options shown: ");
        }
        scanf("%i", &option);
        switch (option)
        {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        default:
            break;
        }
        i += 1;
    } while (1);
}

int logIn() 
{   
    clear();
    char username[20]; 
    char password[20];
    printf("\n LOGIN");
    printf("\n\n Enter username: ");
    scanf("%s", username);
    printf("\n Enter password: ");
    scanf("%s", password);

    /*
        DETERMINAR EXISTENCIA DEL USUARIO
    */

    return 1;
}

int signIn() {
    char username[20]; 
    char password[20]; 
    char passwordVerification[20];
    int i = 0;

    clear();
    printf("\n\n Sing in");
    printf("\n\n Enter username: ");
    scanf("%s", username);
    printf("\n Enter password: ");
    scanf("%s", password);
    do {
        if (i == 0) {
            printf("\n Repeat password: ");
            scanf("%s", passwordVerification);
        } else {
            printf("\n passwords do not match");
            printf("\n Repeat password: ");
            scanf("%s", passwordVerification);   
        }
        i = 0;
    } while (strcmp(password, passwordVerification) != 0);

    User user;
    initUser(&user, username, password);
}

int logger() {
    int option = loggerOptions();
    if (option == 1){
        logIn();
    } else if (option == 2) {
        signIn();
    }
}

void dashBoard(User user) {
    printf("\n @%s", "usuario");
    printf("\n My number of Tweets: %i", 1548);
    printf("\n My number of Following: %i", 123);
    printf("\n My numer of Followers: %i", 9321);
    printf("\n");
}