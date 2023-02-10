#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "user.h"
#include "list.h"

/*
Set of proof to User Struct
*/
int testUser()
{
    User user;
    strcpy( user.username , "eycer");
    setPassword( &user, "Eros#123" );
    printf("%ld\n", user.password);
    printf("%d\n", verifyPassword( &user, "Eros#123" ));
    return 1;
}

/*
Set of proof to List Struct
*/
int testList()
{
    List l;
    l.next = NULL;
    l.time = time(NULL);
    strcpy(l.content.text, "This is the first tweet ever!");
    //printf("%s\n", u.username);
    printf("%p\n", l.next);
    printf("%ld\n", l.time);
    printf("%s\n", l.content.text);
    return 1;
}

/*
Execute Proof Suite to Backend
*/
int main(int argc, char const *argv[])
{
    testUser();
    testList();

    return 0;
}