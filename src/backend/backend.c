/*
Test function set for the backend
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "user.h"
#include "list.h"
#include "hashtable.h"

/*
Set of test to User Struct
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
Set of test to List Struct
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
Set of test to hash Table
*/
int testHashTable()
{
    HashTable table;
    initHashTable(&table);
    User eycer;
    initUser(&eycer, "eycer", "Eros#123");
    newTweet( &eycer, "New Tweet from HashTable!"  );
    addToHashTable(&table, &eycer);
    //printf("%d\n", addToHashTable(&table, &eycer));
    User* search = getUserFromHashTable( &table, "eycer");
    printList(search->tweets);
    printf("Password Hashed in User: %ld\n", search->password);
    return 1;
}

/*
Test for standar workflow
*/
int testAll()
{
    // Create Hash table to store users
    HashTable table;
    initHashTable(&table);

    // To register Users
    User eycer;
    initUser(&eycer, "eycer", "Eros#123");
    addToHashTable(&table, &eycer);

    User blanyer;
    initUser(&blanyer, "blanyer", "blanyer#123");
    addToHashTable(&table, &blanyer);

    User cesar;
    initUser(&cesar, "cesar", "cesar#123");
    addToHashTable(&table, &cesar);
    
    // To tweet
    newTweet( &eycer, "Hi, This is a eycer's tweet" );
    newTweet( &blanyer, "Hi, This is a blanyer's tweet" );
    newTweet( &cesar, "Hi, This is a cesar's tweet" );

    // To Follow
    follow(&eycer, &blanyer);
    follow(&eycer, &cesar);

    // To Login
    User* search = getUserFromHashTable( &table, "eycer");
    if (verifyPassword(search, "Eros#123"))
    {
        // Timeline list
        List* timeline = getUserTimeLine( search );
        printList(timeline);

    }
    
    // Reject bad password
    if (verifyPassword(&blanyer, "Eros#123"))
    {
        printf("Rejecting Not Working\n");
    }
    else{
        printf("Wrong Password!\n");
    }
    
}

/*
Execute tests Suite to Backend
*/
int main(int argc, char const *argv[])
{
    testAll();

    return 0;
}