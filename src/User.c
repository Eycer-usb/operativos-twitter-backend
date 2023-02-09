/*
Data Structure for Users
The members are:
    username: Identify name of the user
    password: hash of the password
    description: Short description of the user, something like a bio
*/
# include "user.h"
# include "list.h"

struct User
{
    char username[20];
    char password[20];
    char description[255];
    List* follows;
};
