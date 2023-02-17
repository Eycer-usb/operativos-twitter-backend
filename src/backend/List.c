#include "list.h"
#include "../utils/formatTweet.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

/*
Initializate a List Node
*/
int initList(List *list)
{
    list->owner = NULL;
    list->content = NULL;
    list->next = NULL;
    list->time = -1;
}

/*
Add a node List at the start of the old List
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

/*
Given a List store Datetime formated in buffer
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

/*
Given a list, printlist will print element by element including
the ENDLIST node
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

/*
Given a List pointer and a pointer to the pointer of a second list
It will store in the outListPtr the result of merge both descending ordered by time list
into one unique descending ordered by time list
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
