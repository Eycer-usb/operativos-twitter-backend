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
        printf("\n1. Login");
        printf("\n2. Sign in");
        if (i = 0) {
            printf("\n\nSelect an option to continue: ");
        } else {
            printf("\n\nSelect one of the options shown: ");
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

User logIn() {   
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

User signIn() {
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

    do {
        if (i == 0) {
            printf("\033[0;31m");
            printf("\nRepeat password: ");

            printf("\033[0;37m");
            scanf("%s", passwordVerification);
        } else {
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

User logger() {
    User user;
    int option = loggerOptions();
    if (option == 1){
        user = logIn();
    } else if (option == 2) {
        user = signIn();
    }
    return user;
}

void dashBoard(User user) {
    printf("\n@%s", user.username);
    printf("\nMy number of Tweets: %i", 1548);
    printf("\nMy number of Following: %i", 123);
    printf("\nMy numer of Followers: %i", 9321);
    printf("\n");
    printf("\nMy Twitts\n");
    /*
    IMPRMIR LISTA DE TWITTS DE SEGUIDORES
    */
}

int prompt(User* user) {
    int i = 1;
    do {
        char prompt[50];
        printf("\033[0;31m");
        printf("\nPrompt: ");

        printf("\033[0;37m");
        fgets(prompt, 50, stdin);
        if (prompt[0] == '+') {
            /*
                USAR CODIGO PARA ELIMINAR SIMBOLO + DEL PROMPT Y RESET
            */
           newTweet(user, prompt);
           printf("\nTWITT ENVIADO");
           i = 0;
            
        } else if (prompt[0] == '@') {
            /*
                BUSCAR LOS TWITTS DEL OTRO USUARIO
            */
           printf("USUARIO BUSCADO");
           i = 0;
        } else if (!strcmp(prompt, "logout")) {
            /*
                SALIR
            */
           printf("\nLOGOUT");
           i = 0;
        } else {
            printf("\033[0;31m");
            printf("\nINVALID ENTRY");
        }
    } while (i);

    return 1;
}

// int followeProfile() {
//     print
// }
int searchUser(char* username) {

    //strcmp()
}

int interface() {
    User user1;
    initUser(&user1, "eycer", "Eros#123");

    User user = logger();
    do {
        clear();
        dashBoard(user);
        printList(user.tweets);
        prompt(&user);
    } while(1);
    
    /*
    SEPARAR OPCIONES ENTRE USER y OWNER
    */
}