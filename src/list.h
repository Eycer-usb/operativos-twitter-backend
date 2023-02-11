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
    ListContent* content;
    time_t time;
};

List* listPush( List* old, ListContent* content, time_t time);

#endif