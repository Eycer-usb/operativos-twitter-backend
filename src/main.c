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
    interface();
    return 0;
}
