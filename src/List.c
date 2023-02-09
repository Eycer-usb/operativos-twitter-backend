# include "user.h"
#include <time.h>
struct List
{
    union
    {
        User* user;
        char text[280];
    };
    struct List* next;
    time_t time;
};
