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
#include "frontend/interface.h"
#include "frontend/auth.h"

// Start Point
int main(int argc, char const *argv[])
{
    // User eycer;
    // initUser(&eycer, "eycer", "Eros#123");
    // newTweet(&eycer, "First Tweet From Main");
    // newTweet(&eycer, "This is a second Tweet, a large one to test the functionality, i hope this project get us a good grade. Eros did a great work, almost put us out of work, but we can do the things better.");
    // newTweet(&eycer, "Just finished reading The Hitchhiker's Guide to the Galaxy and I can't believe I waited so long to read it. The humor is witty and clever, and the characters are so charming. Highly recommend this book.");
    // printhelloworld();
    // printList(eycer.tweets);
    interface();
    return 0;
}
