#include "frontend.h"
#include "user.h"
#include <stdio.h>
#include <string.h>

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
void printImage (User user) {
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

void printTwitts (User user) {
    printf("\n");
    printf("%7s", "TWITTS");
    printf("\n %s", user.tweets);
    for (int i = 0; i < 10; i++) {
        printf("msj");
    }
}
