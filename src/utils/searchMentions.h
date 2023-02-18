#ifndef SEARCHMENTIONS_H
#define SEARCHMENTIONS_H

#include "./../backend/hashtable.h"
#include "./../backend/user.h"

void searchAtWords(HashTable* table, User* owner, char *str);

#endif
