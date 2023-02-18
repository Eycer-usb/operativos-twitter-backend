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
#include "./../utils/searchMentions.h"

/**
 *
 * Initializes a new User object with the given parameters, and initializes the
 * user's follow, follower, tweets, and mention Lists with initList().
 * @param user A pointer to the User object to be initialized.
 * @param username A pointer to the string containing the user's username.
 * @param password A pointer to the string containing the user's password.
 * @param description A pointer to the string containing the user's description.
 * @return Returns 1 if initialization is successful, 0 otherwise.
 */
int initUser(User *user, char *username, char *password, char *description)
{
    // Tails Definition
    user->follows = (List *)malloc(sizeof(List));
    user->followedBy = (List *)malloc(sizeof(List));
    user->tweets = (List *)malloc(sizeof(List));
    user->mentions = (List *)malloc(sizeof(List));
    user->password = -1;
    user->tweetCount = 0;
    user->followersCount = 0;
    user->followingCount = 0;
    initList(user->follows);
    initList(user->followedBy);
    initList(user->tweets);
    initList(user->mentions);
    strcpy(user->username, username);
    strcpy(user->description, description);
    setPassword(user, password);
    return 1;
}

/**
 * Sets the password of the user by generating a hash from the given string.
 *
 * @param user      Pointer to the User struct
 * @param password  String representing the password
 */
void setPassword(User *user, char *password)
{
    user->password = hashFun(password);
}

/**
 * Verifies whether the provided password matches the user's password.
 *
 * @param user      Pointer to the User struct
 * @param password  String representing the password to verify
 * @return          1 if the password is correct, 0 otherwise
 */
int verifyPassword(User *user, char password[20])
{
    long int hashed = hashFun(password);
    return (*user).password == hashed;
}

/**
 * Follows a user by updating the corresponding lists and counters.
 *
 * @param follower  Pointer to the follower User struct
 * @param followed  Pointer to the followed User struct
 * @return          1 if the operation was successful, 0 if the follower is already following the followed
 */
int follow(User *follower, User *followed)
{
    /* Verifying if the followed user is already being followed */
    List *temp = follower->follows;
    while (temp != NULL)
    {
        if (temp->content != NULL && temp->content->user == followed)
        {
            printf("You are already following %s.\n", followed->username);
            return 0;
        }
        temp = temp->next;
    }

    /* Updating follows list */
    ListContent *content = (ListContent *)malloc(sizeof(ListContent));
    content->user = followed;
    follower->follows = listPush(follower->follows, content, time(NULL), NULL);

    /* Updating followedBy list */
    ListContent *followedContent = (ListContent *)malloc(sizeof(ListContent));
    followedContent->user = follower;
    followed->followedBy = listPush(followed->followedBy, followedContent, time(NULL), NULL);

    follower->followingCount++;
    followed->followersCount++;
    printf("You are now following %s.\n", followed->username);
    return 1;
}

/*
 * Adds a new tweet to the tweets list of the given user.
 *
 * @param user: pointer to a User struct that represents the user who created the tweet
 * @param text: pointer to the string that contains the text of the tweet
 *
 * @return: 1 if the tweet was successfully added to the list, 0 otherwise
 */
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
 * Adds a new mention to the mentions list of the given user.
 *
 * @param userOwner: pointer to a User struct that represents the user who created the tweet that mentioned the other user
 * @param user: pointer to a User struct that represents the user who was mentioned in the tweet
 * @param text: pointer to the string that contains the text of the tweet
 *
 * @return: 1 if the mention was successfully added to the list, 0 otherwise
 */
int newMention(User *userOwner, User *user, char *text)
{
    ListContent *content = (ListContent *)malloc(sizeof(ListContent));
    char *owner = userOwner->username;
    content->text = (char *)malloc(sizeof(char) * 280);
    strcpy(content->text, text);
    user->mentions = listPush(user->mentions, content, time(NULL), owner);
    return 1;
}

/*
 * Returns a list with the tweets of the given user and the tweets of the users he/she follows, sorted by time.
 *
 * @param user: pointer to a User struct that represents the user whose timeline will be returned
 *
 * @return: pointer to a List struct that contains the tweets sorted by time, or NULL if an error occurred
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
