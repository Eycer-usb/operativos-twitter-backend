#include "hashtable.h"
unsigned long int hashFun( char string[20] ){
    unsigned long hash = 5381;
    char* str = string;
    int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}