#if !defined(HELLO)
#define HELLO

#include "./../backend/user.h"

int logger();
int logIn();
int signIn();
void printImage(User user);
void dashBoard(User user);
void printTwitts(User user);

#endif