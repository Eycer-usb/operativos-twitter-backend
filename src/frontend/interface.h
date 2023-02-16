#if !defined(INTERFACE)
#define INTERFACE

#include "./../backend/user.h"
#include "./../backend/hashtable.h"

void printImage(User user);
void dashboard(User user);
int prompt(User *user, HashTable *table);
int interface();

#endif