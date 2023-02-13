#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "user.h"
#include "list.h"
#include "frontend.h"
#include <conio.h> // eliminar

/*
Set of proof to User Struct
*/
int testUser()
{
    User user;
    initUser(&user, "eycer", "Eros#123");
    newTweet( &user, "This is the first User Tweet!"  );
    printf("%s", user.tweets->content->text);
    return 1;
}

/*
*/
int testInterface()
{   
    User user;
    initUser(&user, "eycer", "Eros#123");
    newTweet(&user, "This is the first User Tweet!"  );
    printImage(user);
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
    strcpy(l.content->text, "This is the first tweet ever!");
    //printf("%s\n", u.username);
    printf("%p\n", l.next);
    printf("%ld\n", l.time);
    printf("%s\n", l.content->text);
    return 1;
}

/*
Execute Proof Suite to Backend
*/
int main(int argc, char const *argv[])
{
    logger();

    getch(); // eliminar
    return 0;
}