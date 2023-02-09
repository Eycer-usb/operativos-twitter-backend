#include "list.h"

List listPush( List old, listContent content, time_t time)
{
    List new;
    new.next = &old;
    new.content = content;
    new.time = time;
    return new;
};



