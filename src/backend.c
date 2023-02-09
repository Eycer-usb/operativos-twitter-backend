#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "user.h"
#include "list.h"
int main(int argc, char const *argv[])
{
    List l;
    User u;
    l.next = NULL;
    strcpy(u.username, "eycer");
    strcpy(l.content.text, "Hola");
    printf("%s\n", l.content.text);
    printf("%s\n", u.username);
    return 0;
}
