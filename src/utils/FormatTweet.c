#include <stdio.h>
#include <string.h>
#include "formatTweet.h"

#define MAX_LINE_LENGTH 70

/**
 * Prints a formatted tweet with username and creation time.
 *
 * @param tweet A pointer to the tweet to be printed.
 * @param username A pointer to the username of the tweet.
 * @param buffer_time A pointer to the time buffer of the tweet.
 */
void format_tweet(char *tweet, char *username, char *buffer_time)
{
    int j;
    for (j = 0; j < 70; j++)
    {
        printf("-");
    }
    printf("\n\n");
    printf("\033[0;34m");
    printf("@%s\n", username);
    printf("\033[0m");
    int tweet_len = strlen(tweet);
    if (tweet_len > MAX_LINE_LENGTH)
    {
        int i = 0;
        while (i < tweet_len)
        {
            int j = i + MAX_LINE_LENGTH;
            if (j >= tweet_len)
            {
                j = tweet_len - 1;
            }
            else
            {
                while (!isspace(tweet[j]) && j > i)
                {
                    j--;
                }
            }

            printf("%.*s\n", j - i, &tweet[i]);

            i = j + 1;
            while (isspace(tweet[i]) && i < tweet_len)
            {
                i++;
            }
        }
    }
    else
    {
        printf("%s", tweet);
    }
    printf("\033[0;34m");
    printf("%s\n", buffer_time);
    printf("\033[0m");

    for (j = 0; j < 70; j++)
    {
        printf("-");
    }
    printf("\n");
}