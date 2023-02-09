#ifndef LIST_HEADER
#define LIST_HEADER


typedef union listContent listContent;
typedef struct List List;

#include <time.h>
#include "user.h"

union listContent
{
    User* user;
    char text[280];
};
struct List
{
    List* next;
    listContent content;
    time_t time;
};

List listPush( List old, listContent content, time_t time);

#endif