#include "list.h"
#include <stdlib.h>

List* listPush( List* old, ListContent* content, time_t time)
{
    List* new = (List*) malloc(sizeof(List));
    new->next = old;
    new->content = content;
    new->time = time;
    return new;
};



