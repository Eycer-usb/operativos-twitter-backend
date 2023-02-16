#if !defined(AUTH)
#define AUTH

#include "./../backend/user.h"
#include "./../backend/hashtable.h"

User logger();
User logIn();
User signIn();
void logOut();

#endif