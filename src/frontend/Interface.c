#include <stdio.h>
#include <string.h>
#include "./../backend/user.h"
#include "./../backend/hashtable.h"
#include "auth.h"
#define clear() printf("\033[H\033[J");

void timeline(User *user)
{
    printf("\033[0;36m");
    printf("\nYOUR TIMELINE\n");
    printf("\033[0;37m");

    List *timeline = getUserTimeLine(user);
    if (timeline == NULL)
    {
        printf("\nThere are no tweets on your timeline yet, follow someone to see their tweets.\n");
    }
    if (user->follows->content == NULL)
    {
        printf("\nYou haven't followed anyone yet. There are no tweets to show.\n");
    }
    else
    {
        printf("\n\n");
        printf("%s", user->follows->content->user->username);
        printf("\n\n");
    }

    printList(timeline);
}

int promptVisit(User *user, User *userVisited)
{
    int should_continue = 0;

    while (!should_continue)
    {
        char prompt[281];

        printf("\033[0;31mPrompt: ");
        printf("\033[0;37m");
        scanf(" %[^\n]", prompt);

        if (!strcmp(prompt, "follow"))
        {
            follow(user, userVisited);
            break;
        }
        else
        {
            if (!strcmp(prompt, "return"))
            {
                should_continue = -1;
            }
            else if (strcmp(prompt, "return") && strlen(prompt) > 1)
            {
                printf("\033[0;31mInvalid input\n");
            }
            break;
        }
    }
    clear();
    return should_continue;
}

void dashboardVisit(User *user, User *userVisited)
{
    do
    {
        printf("\033[0;32m");
        printf("\n%s's Profile", userVisited->username);
        printf("\033[0m");
        printf("\nTweets: %i", userVisited->tweetCount);
        printf("\nFollowing: %i", userVisited->followingCount);
        printf("\nFollowers: %i", userVisited->followersCount);
        printf("\nDescription: %s", userVisited->description);
        printf("\n");
        printf("\033[0;36m");
        printf("\n%s's Tweets\n", userVisited->username);
        printf("\033[0m");
        printList(userVisited->tweets);
    } while (promptVisit(user, userVisited) != -1);
}

void printFollowing(User *user)
{
    if (user->follows == NULL)
    {
        printf("\nYou don't have followings.\n");
    }
    else
    {
        List *followings = user->follows;
        printf("\nThis is a list of your followings\n");
        for (; followings->content != NULL; followings = followings->next)
        {
            printf("\n- %s", followings->content->user->username);
        }
        printf("\n");
    }
}

void printFollowers(User *user)
{
    if (user->followedBy == NULL)
    {
        printf("\nYou don't have followers.\n");
    }
    else
    {
        List *followers = user->followedBy;
        printf("\nThis is a list of your followers\n");
        for (; followers->content != NULL; followers = followers->next)
        {
            printf("\n- %s", followers->content->user->username);
        }
        printf("\n");
    }
}

int prompt(User *user, HashTable *table)
{
    int should_continue = 0;

    while (!should_continue)
    {
        char prompt[281];
        printf("\033[0;34m");
        printf("\nTWEET, SEARCH AN USER OR TYPE AN OPTION FROM BELOW\n\n");
        printf("\033[0m");
        printf("tweets\n");
        printf("followers\n");
        printf("following\n");
        printf("logout\n\n");
        printf("( @[username] to search an user, +[tweet] to tweet ): ");
        scanf(" %280[^\n]", prompt);

        switch (prompt[0])
        {
        case '+':
            memmove(prompt, prompt + 1, strlen(prompt));
            newTweet(user, prompt);
            printf("Tweet enviado\n");
            should_continue = 1;
            clear();
            break;

        case '@':
            clear();
            memmove(prompt, prompt + 1, strlen(prompt));
            if (strcmp(prompt, user->username) == 0)
            {
                printf("\nYOU CAN'T LOOK FOR YOURSELF");
            }
            else if (getUserFromHashTable(table, prompt))
            {
                dashboardVisit(user, getUserFromHashTable(table, prompt));
            }
            else
            {
                printf("\nThe user you're trying to search for doesn't exist");
            }
            should_continue = 1;
            break;

        default:
            if (!strcmp(prompt, "logout"))
            {
                printf("Logout\n");
                should_continue = -1;
            }
            else if (!strcmp(prompt, "following"))
            {
                clear();
                printFollowing(user);
            }
            else if (!strcmp(prompt, "followers"))
            {
                clear();
                printFollowers(user);
            }
            else if (!strcmp(prompt, "tweets"))
            {
                clear();
                printList(user->tweets);
            }
            else
            {
                printf("\033[0;31mInvalid Input\n");
                printf("\033[0m");
            }
            break;
        }
    }
    return should_continue;
}

int searchUser(char *username)
{

    // strcmp()
}

/**
 * This function allows the user to see the GUI and interact with the differents Auth
 * and twitter options.
 */
int interface()
{

    HashTable table;
    initHashTable(&table);
    do
    {
        User *user;
        user = logger(&table);
        if (user == NULL)
        {
            break;
        }
        do
        {
            clear();
            timeline(user);
        } while (prompt(user, &table) != -1);
    } while (1);
}