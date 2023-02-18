#include <stdio.h>
#include <string.h>
#include "./../backend/user.h"
#include "./../backend/hashtable.h"
#include "auth.h"
#include "./../utils/searchMentions.h"
#define clear() printf("\033[H\033[J");

/**
 * Prints the user's timeline to the console.
 * @param user The user whose timeline will be shown.
 */
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

/**
 * Prints the list of users that the given user is following.
 * @param user The user whose following list will be shown.
 */
void printFollowing(User *user)
{
    if (user->follows == NULL)
    {
        printf("\nThere is no user following.\n");
    }
    else
    {
        List *followings = user->follows;
        printf("\033[0;36m");
        printf("\nFOLLOWING\n");
        printf("\033[0m");
        for (; followings->content != NULL; followings = followings->next)
        {
            printf("\n- %s", followings->content->user->username);
        }
        printf("\n");
    }
}

/**
 * Prints the list of users that follow the given user.
 * @param user The user whose list of followers will be shown.
 */
void printFollowers(User *user)
{
    if (user->followedBy == NULL)
    {
        printf("\nThere is no followers.\n");
    }
    else
    {
        List *followers = user->followedBy;
        printf("\033[0;36m");
        printf("\nFOLLOWERS\n");
        printf("\033[0m");
        for (; followers->content != NULL; followers = followers->next)
        {
            printf("\n- %s", followers->content->user->username);
        }
        printf("\n");
    }
}

/**
 * Prompts the user to visit another user's profile and displays options to follow, see the following list or the followers list.
 * @param user The user who is visiting the other user's profile.
 * @param userVisited The user whose profile is being visited.
 * @return 0 if the user wants to continue, -1 if the user wants to return to the previous page.
 */
int promptVisit(User *user, User *userVisited)
{
    int should_continue = 0;

    while (!should_continue)
    {
        char prompt[281];
        printf("\nYou can either 'follow' or 'return' to the previous page.\n\n");
        printf("\033[0;31mPrompt: ");
        printf("\033[0;37m");
        scanf(" %[^\n]", prompt);

        if (!strcmp(prompt, "follow"))
        {
            follow(user, userVisited);
            break;
        }
        else if (!strcmp(prompt, "following"))
        {
            clear();
            printFollowing(userVisited);
        }
        else if (!strcmp(prompt, "followers"))
        {
            clear();
            printFollowers(userVisited);
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
/**
 * Display the dashboard of a visited user and allows the user to interact with it.
 * @param user The user who is currently logged in and visiting another user's dashboard.
 * @param userVisited The user whose dashboard is being visited.
 */
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

/**
 * Prompts the user for an action and handles it accordingly.
 *
 * @param user          The user currently logged in.
 * @param table         The hash table containing all registered users.
 *
 * @return              -1 if the user wants to log out, 0 otherwise.
 */
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
            searchAtWords(table, user, prompt);
            printf("saliendo de atwords");
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
            if (!strcmp(prompt, "mentions"))
            {
                clear();
                printf("\nList mentions\n\n");
                printList(user->mentions);
            }
            else if (!strcmp(prompt, "logout"))
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

/*
 * interface - handles the main menu and user interface of the program
 *
 * This function initializes the hash table to store the registered users and
 * enters a loop where the user can log in, view their timeline, and interact with
 * the system by sending tweets, searching for other users, and viewing their own
 * followers and following list.
 *
 * Returns:
 * - nothing, the function runs indefinitely until the program is terminated
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