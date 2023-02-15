#ifndef USER_HEADER
#define USER_HEADER

typedef struct User User;

#include "list.h"

struct User
{
    char username[20];
    long int password;
    char description[255];
    List* follows;
    List* tweets;
};
int initUser( User* user, char* username, char* password );
void setPassword( User* user, char* password );
int verifyPassword( User* user, char* password );
int follow( User* follower, User* fillowed );
int newTweet( User* user, char* text  );
List* getUserTimeLine( User* user );


#endif