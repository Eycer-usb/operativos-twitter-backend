#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

int initList(List* list)
{
    list->content = NULL;
    list->next = NULL;
    list->time = -1;
}

List* listPush( List* old, ListContent* content, time_t time)
{
    List* new = (List*) malloc(sizeof(List));
    new->next = old;
    new->content = content;
    new->time = time;
    return new;
};


int getSavedDateTime( List* list, char* buffer )
{
    time_t timer = (list->time);
    struct tm* tm_info;
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%d-%m-%Y %H:%M", tm_info);
    return 1;
}

void printList(List* list)
{
    List* i = list;
    while (i)
    {
        
        if(i && i->content == NULL && i->next == NULL && i->time == -1)
        {
            printf("ENDLIST\n");
        }
        else
        {
            char buffer_time[17];
            getSavedDateTime(i, buffer_time);
            printf("%s\n", i->content->text);
            printf("%s\n", buffer_time);    
        }
        i = i->next;
    }
}

int mergeListByTimeOrder(List* oneList, List** outListPtr)
{
    
    List* i = oneList;
    List* outList = *outListPtr;
    List* j = outList;
    List* prev = NULL;

    while ( i->next && j->next )
    {
        if (i->time >= j->time)
        {
            if (prev == NULL)
            {
                outList = listPush( outList, i->content, i->time );
                j = outList;
            }
            else
            {
                List* new = (List*) malloc(sizeof(List));
                new->content = i->content;
                new->time = i->time;
                prev->next = new;
                new->next = j;
                j = new;
            }
            
            i = i->next;
        }
        else if( i->time < j->time)
        {
            prev = j;
            j = j->next;            
        }        
    }

    while (i->next)
    {
        List* new = (List*) malloc(sizeof(List));
        new->content = i->content;
        new->time = i->time;
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

