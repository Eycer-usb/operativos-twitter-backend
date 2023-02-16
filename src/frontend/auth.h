#if !defined(AUTH)
#define AUTH

#include "./../backend/user.h"
#include "./../backend/hashtable.h"

User logger(HashTable* table);
User logIn(HashTable* table);
User signIn(HashTable* table);
void logOut(User *user, HashTable *table);

#endif