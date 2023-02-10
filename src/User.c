/*
Data Structure for Users
The members are:
    username: Identify name of the user
    password: hash of the password
    description: Short description of the user, something like a bio
*/
#include "user.h"
#include "hashtable.h"
/*
Given a user and a password. The password is hashed and
set as password.
*/
void setPassword( User* user, char password[20] )
{
    (*user).password = hashFun( password ); // WIP
}

/*
Given a user and a password. Return 1 if the password
corresponds to the stored hashed password, and 0 otherwise.
*/
int verifyPassword( User* user, char password[20] )
{
    long int hashed = hashFun(password);
    return (*user).password == hashed; //WIP
}
