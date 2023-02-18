#include "list.h"
#include "../utils/formatTweet.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

/**
 * Initializes a linked list.
 * Inputs:
 *  - list: a pointer to a List structure to be initialized
 * Outputs:
 *  - none
 */
int initList(List *list)
{
    list->owner = NULL;
    list->content = NULL;
    list->next = NULL;
    list->time = -1;
}

/**
 * Inserts a new element at the beginning of the linked list pointed by old.
 * @param old The pointer to the head of the linked list to be modified.
 * @param content The pointer to the content of the new element to be inserted.
 * @param time The time value associated with the new element.
 * @param owner The string identifying the owner of the new element.
 * @return The pointer to the new head of the modified linked list.
 */
List *listPush(List *old, ListContent *content, time_t time, char *owner)
{
    List *new = (List *)malloc(sizeof(List));
    new->next = old;
    new->content = content;
    new->time = time;
    new->owner = owner;
    return new;
};

/**
 * Given a pointer to a linked list node `list` and a character buffer `buffer`,
 * fills `buffer` with the formatted string representing the time stored in
 * `list->time`. The time is formatted as "dd-mm-yyyy hh:mm:ss".
 *
 * Returns 1 on success and 0 if `list` is NULL.
 */
int getSavedDateTime(List *list, char *buffer)
{
    if (list == NULL)
    {
        return 0; // puntero nulo
    }

    time_t timer = (list->time);
    struct tm *tm_info;
    tm_info = localtime(&timer);

    strftime(buffer, 27, "%d-%m-%Y %H:%M:%S", tm_info);
    return 1;
}

/**
 * Print the contents of a linked list of tweets.
 *
 * @param list The list to be printed.
 * @return void
 */
void printList(List *list)
{
    List *i = list;
    while (i)
    {
        if (i == NULL)
        {
            break;
        }

        if (i->content == NULL && i->next == NULL && i->time == -1)
        {
            printf("\nENDLIST\n");
        }
        else
        {
            char buffer_time[27];
            getSavedDateTime(i, buffer_time);
            formatTweet(i->content->text, i->owner, buffer_time);
        }
        i = i->next;
    }
}

/**
 * Merges two linked lists of tweets in time order into one new linked list.
 *
 * @param oneList      A pointer to the first linked list to be merged, sorted in time order
 * @param outListPtr   A pointer to a pointer to the second linked list to be merged, sorted in time order
 * @return             1 if the merge was successful, 0 otherwise
 */
int mergeListByTimeOrder(List *oneList, List **outListPtr)
{

    List *i = oneList;
    List *outList = *outListPtr;
    List *j = outList;
    List *prev = NULL;

    while (i->next && j->next)
    {
        if (i->time >= j->time)
        {
            if (prev == NULL)
            {
                outList = listPush(outList, i->content, i->time, i->owner);
                j = outList;
            }
            else
            {
                List *new = (List *)malloc(sizeof(List));
                new->content = i->content;
                new->time = i->time;
                new->owner = i->owner;
                prev->next = new;
                new->next = j;
                j = new;
            }

            i = i->next;
        }
        else if (i->time < j->time)
        {
            prev = j;
            j = j->next;
        }
    }

    while (i->next)
    {
        List *new = (List *)malloc(sizeof(List));
        new->content = i->content;
        new->time = i->time;
        new->owner = i->owner;
        if (prev != NULL)
        {
            new->next = prev->next;
            prev->next = new;
            prev = new;
        }
        else
        {
            new->next = outList;
            prev = new;
            outList = prev;
        }
        i = i->next;
    }

    *outListPtr = outList;
    return 1;
}
