#ifndef USER_HEADER
#define USER_HEADER

typedef struct User User;

# include "list.h"

struct User
{
    char username[20];
    long int password;
    char description[255];
    List* follows;
};

int verifyPassword( User* user, char password[20] );
void setPassword( User* user, char password[20] );

#endif