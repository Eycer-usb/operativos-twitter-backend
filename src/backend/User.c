/*
Data Structure for Users
The members are:
    username: Identify name of the user
    password: hash of the password
    description: Short description of the user, something like a bio
*/
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "user.h"
#include "hashtable.h"

/*
Initializate User Struct
*/
int initUser(User *user, char *username, char *password)
{
    // Tails Definition
    user->follows = (List *)malloc(sizeof(List));
    user->followedBy = (List *)malloc(sizeof(List));
    user->tweets = (List *)malloc(sizeof(List));
    user->password = -1;
    user->tweetCount = 0;
    user->followersCount = 0;
    user->followingCount = 0;
    initList(user->follows);
    initList(user->followedBy);
    initList(user->tweets);
    strcpy(user->username, username);
    setPassword(user, password);
    return 1;
}

/*
Given a user and a password. The password is hashed and
set as password.
*/
void setPassword(User *user, char *password)
{
    user->password = hashFun(password);
}

/*
Given a user and a password. Return 1 if the password
corresponds to the stored hashed password, and 0 otherwise.
*/
int verifyPassword(User *user, char password[20])
{
    long int hashed = hashFun(password);
    return (*user).password == hashed;
}

/*
Add the followed to the follow list of the follower
*/
int follow(User *follower, User *followed)
{
    /* Updating follows list */
    ListContent *content = (ListContent *)malloc(sizeof(ListContent));
    content->user = followed;
    follower->follows = listPush(follower->follows, content, time(NULL), NULL);

    /* Updating followedBy list */
    ListContent *followedContent = (ListContent *)malloc(sizeof(ListContent));
    followedContent->user = follower;
    follower->followedBy = listPush(follower->followedBy, followedContent, time(NULL), NULL);

    follower->followingCount++;
    followed->followersCount++;
    return 1;
}

/*
Add a new tweet to the user tweet list
*/
// WIP
int newTweet(User *user, char *text)
{
    ListContent *content = (ListContent *)malloc(sizeof(ListContent));
    char *owner;
    content->text = (char *)malloc(sizeof(char) * 280);
    strcpy(content->text, text);
    owner = user->username;
    user->tweets = listPush(user->tweets, content, time(NULL), owner);
    user->tweetCount++;
    return 1;
}

/*
Return the Timeline of tweets to the given user
*/
List *getUserTimeLine(User *user)
{
    /*  Memory alocation to store the merged list */
    List *outList = (List *)malloc(sizeof(List));
    initList(outList);
    List *follow_i = user->follows;
    while (follow_i->next)
    {
        if (mergeListByTimeOrder(follow_i->content->user->tweets, &outList))
        {
            follow_i = follow_i->next;
        }
        else
        {
            return 0;
        }
    }
    return outList;
}
