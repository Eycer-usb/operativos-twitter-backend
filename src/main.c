/*
Main Function for twitter implementation
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Backend Includes
#include "backend/user.h"
#include "backend/list.h"
#include "backend/hashtable.h"

// Frontend Includes
#include "frontend/hello.h"

// Start Point
int main(int argc, char const *argv[])
{
    User eycer;
    initUser(&eycer, "eycer", "Eros#123");
    //newTweet(&eycer, "First Tweet From Main");
    //printList(eycer.tweets);
    //dashBoard(eycer);
    logger();
    return 0;
}
