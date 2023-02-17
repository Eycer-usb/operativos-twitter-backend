#ifndef USER_HEADER
#define USER_HEADER

typedef struct User User;

#include "list.h"

struct User
{
    char username[20];
    long int password;
    char description[161];
    int tweetCount;
    List *tweets;
    List *follows;
    List *followedBy;
    int followersCount;
    int followingCount;
};

int initUser(User *user, char *username, char *password, char* description);
void setPassword(User *user, char *password);
int verifyPassword(User *user, char *password);
int follow(User *follower, User *followed);
int newTweet(User *user, char *text);
List *getUserTimeLine(User *user);

#endif