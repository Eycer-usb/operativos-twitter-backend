#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
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
    newTweet( &user, "This is the second User Tweet!"  );
    newTweet( &user, "This is the last User Tweet!"  );

    return 1;
}

/*
This function is an example for generate timeline of tweets
*/
int testTimeLine()
{
    User eycer, cesar, blanyer;
    initUser(&eycer, "eycer", "Eros#123");
    initUser(&cesar, "cesar", "Cesar#123");
    initUser(&blanyer, "blanyer", "Blanyer#123");
    follow(&eycer, &eycer);
    follow(&eycer, &cesar);
    follow(&eycer, &blanyer);
    newTweet( &eycer, "1"  );
    sleep(1);
    newTweet( &cesar, "2"  );
    sleep(1);
    newTweet( &blanyer, "3"  );
    sleep(1);
    newTweet( &eycer, "4"  );
    sleep(1);
    newTweet( &cesar, "5"  );
    sleep(1);
    newTweet( &blanyer, "6"  );
    sleep(1);
    List* timeLine = getUserTimeLine(&eycer);
    printList(timeLine);

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

    //testUser();
    //testList();
    testTimeLine();


    getch(); // eliminar
    return 0;
}