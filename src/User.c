/*
Data Structure for Users
The members are:
    username: Identify name of the user
    password: hash of the password
    description: Short description of the user, something like a bio
*/
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "user.h"
#include "hashtable.h"


/*
Initializate User Struct
*/
int initUser( User* user, char* username, char* password )
{
    // Tails Definition
    user->follows = NULL;
    user->tweets = NULL;
    strcpy( user->username, username );
    setPassword(user, password);
    return 1;
}

/*
Given a user and a password. The password is hashed and
set as password.
*/
void setPassword( User* user, char* password )
{
    (*user).password = hashFun( password );
}

/*
Given a user and a password. Return 1 if the password
corresponds to the stored hashed password, and 0 otherwise.
*/
int verifyPassword( User* user, char password[20] )
{
    long int hashed = hashFun(password);
    return (*user).password == hashed;
}

/*
Add the followed to the follow list of the follower
*/
int follow( User* follower, User* followed )
{
    ListContent* content = (ListContent*) malloc(sizeof(ListContent));
    content->user = followed;
    follower->follows = listPush( follower->follows, content, time(NULL) );
}

/*
Add a new tweet to the user tweet list
*/
//WIP
int newTweet( User* user, char* text  )
{
    ListContent* content = (ListContent*) malloc(sizeof(ListContent));
    content->text = text;
    user->tweets = listPush( user->tweets, content, time(NULL) );
    return 1;
}