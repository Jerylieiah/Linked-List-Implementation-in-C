#ifndef ASS2_LINKED_LIST_H
#define ASS2_LINKED_LIST_H
#include <stdio.h>

typedef struct iorb
{
    int base_pri; //Block priority
    struct iorb *link; //Pointer to the next block
    char filler[100]; //Description about the block
} IORB;


#endif //ASS2_LINKED_LIST_H