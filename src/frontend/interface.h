#if !defined(INTERFACE)
#define INTERFACE

#include "./../backend/user.h"
#include "./../backend/hashtable.h"

void printImage(User user);
void dashboard(User* user);
void dashboardVisit(User* user, User* userV);
int prompt(User user, HashTable *table);
int promptVisit(User *user, User *userV);
int interface();

#endif