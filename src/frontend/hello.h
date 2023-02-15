#if !defined(HELLO)
#define HELLO

#include "./../backend/user.h"

User logger();
int logIn();
User signIn();
void printImage(User user);
void dashBoard(User user);
void printTwitts(User user);
int prompt();
int interface();

#endif