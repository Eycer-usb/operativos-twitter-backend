#include "frontend.h"
#include "user.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

char image[12][27] = 
{{"**************************"},
{"**************************"},
{"*********          *******"},
{"*******             ******"},
{"*******             ******"},
{"*******             ******"},
{"*******              *****"},
{"*******              *****"},
{"********            ******"},
{"*********          *******"},
{"********           *******"},
{"*******             ******"}};

/*
prints a standard profile image and centers it on the screen
*/
void printImage(User user) 
{
    printf("\n");
    for (int i = 0; i < 12 ;i++) {
        printf("%2c", image[i][0]);
        for (int j = 1; j < 26; j++) {
            printf("%c", image[i][j]);
        }
        printf("\n");
    } 
    printf("\n");
    printf("%*s\n", 1+strlen(user.username), user.username);
}

void printTwitts(User user) 
{
    printf("\n");
    printf("%7s", "TWITTS");
    printf("\n %s", user.tweets);
    for (int i = 0; i < 10; i++) {
        printf("msj");
    }
}

int loggerOptions()
{   
    int i = 0;
    do
    {
        system("cls");
        printf("\n1. Login");
        printf("\n2. Sign in");
        if (i = 0) {
            printf("\n\nSelect an option to continue");
        } else {
            printf("\n\nSelect one of the options shown");
        }
        switch (getch())
        {
        case '1':
            return 1;
            break;
        case '2':
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
    system("cls");
    char* username; 
    char* password;
    printf("\n LOGIN");
    printf("\n\n Enter username: ");
    scanf("%s", &username);
    printf("\n Enter password: ");
    scanf("%s", &password);

    return 1;
}

int signIn() {
    char* username; 
    char* password;
    char* passwordVerification;
    int i = 0;

    system("cls");
    printf("\n\n Sing in");
    printf("\n\n Enter username: ");
    scanf("%s", &username);
    printf("\n Enter password: ");
    scanf("%s", &password);
    do {
        if (i == 0) {
            printf("\n Repeat password: ");
            scanf("%s", &passwordVerification);
        } else {
            printf("\n passwords do not match");
            printf("\n Repeat password: ");
            scanf("%s", &passwordVerification);   
        }
        i = 0;
    } while (password == passwordVerification);
}

int logger() {

    int option = loggerOptions();
    if (option == 1){
        logIn();
    } else if (option == 2) {
        signIn();
    }
}
