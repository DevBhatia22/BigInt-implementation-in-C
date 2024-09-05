//Handle case where we include file multiple times
#ifndef BIGINT_H
#define BIGINT_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <errno.h> 

//Linked List Node Struct
typedef struct Node{
    int digits;
    struct Node *next;
    struct Node *prev;
} Node;

//BigInt Struct
typedef struct BigInt{
    Node *head;
    Node *tail;
    int size;
    int sign;
} BigInt;



// Function prototypes
void printI(BigInt* num);
void freeI(BigInt* num);
BigInt* createI(char* str);
BigInt* addI(BigInt* num1, BigInt* num2);
BigInt* subI(BigInt* num1, BigInt* num2);
BigInt* mulI(BigInt* num1, BigInt* num2);
BigInt* divI(BigInt* num1, BigInt* num2);
BigInt* powI(BigInt* num1, BigInt* num2);
BigInt* _clone(BigInt* num1);
BigInt* gcdI(BigInt* num1, BigInt* num2);
BigInt* lcmI(BigInt* num1, BigInt* num2);
BigInt* modI(BigInt* num1, BigInt* num2);
void _halfI(BigInt* num1);
int absCompI(BigInt* num1, BigInt* num2);
int compI(BigInt* num1, BigInt* num2);
void _reBuildI(BigInt* num);
void _printI(BigInt* num);


#endif