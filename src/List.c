#include <time.h>
#include "user.h"
#include "list.h"

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

List listPush( List old, listContent content, time_t time)
{
    List new;
    new.next = &old;
    new.content = content;
    new.time = time;
    return new;
};



