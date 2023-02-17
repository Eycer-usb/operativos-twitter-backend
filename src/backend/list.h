#ifndef LIST_HEADER
#define LIST_HEADER


typedef union listContent ListContent;
typedef struct List List;

#include <time.h>
#include "user.h"

union listContent
{
    User* user;
    char* text;
};
struct List
{
    List* next;
    char* owner;
    ListContent* content;
    time_t time;
};

int initList( List* list );
List* listPush( List* old, ListContent* content, time_t time, char* owner);
int getSavedDateTime( List* list, char* buffer );
int mergeListByTimeOrder(List* oneList, List** outList);
void printList(List* list);

#endif