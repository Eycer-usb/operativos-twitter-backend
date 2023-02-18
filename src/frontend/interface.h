#if !defined(INTERFACE)
#define INTERFACE

#include "./../backend/user.h"
#include "./../backend/hashtable.h"
#include "./../utils/searchMentions.h"

void printImage(User user);
void timeline(User *user, HashTable *table);
void dashboardVisit(User *user, User *userVisited);
void printFollowing(User *user);
int prompt(User user, HashTable *table);
int promptVisit(User *user, User *userVisited);
int interface();

#endif