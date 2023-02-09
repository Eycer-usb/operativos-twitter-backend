#ifndef USER_HEADER
#define USER_HEADER

typedef struct User User;

# include "list.h"

struct User
{
    char username[20];
    char password[20];
    char description[255];
    List* follows;
};

#endif