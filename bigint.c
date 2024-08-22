#ifndef BIGINT_H
#define BIGINT_H
//Handle case where we include file multiple times

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Linked List Node Struct
typedef struct Node{
    int digits;
    int size;
    struct Node *next;
} Node;

//BigInt Struct
typedef struct BigInt{
    Node *head;
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




//Functions

//Create
BigInt* createI(char* str){
    
    BigInt* num = (BigInt*) malloc(sizeof(BigInt));
    num->head = (Node*) malloc(sizeof(Node));
    Node* tempNode = num->head;
    num->head->size = 0;
    int i = 0;
    if(str[i] == '-'){
        num->sign = 1;
        i++;
    }
    
    for(i; i < strlen(str); i++){
        
        char temp[4] = {'0'};
        int limit = 4;
        
        while(limit-- && i < strlen(str)){
            temp[3 - limit] = str[i];
            i++;
        }
        i--;
        
        int tempNum = atoi(temp);
        tempNode->digits = tempNum;
        
        if(i != strlen(str) - 1){
            Node* SN = (Node*) malloc(sizeof(Node));
            tempNode->next= SN;
            tempNode = SN;
            tempNode->next = NULL;
            
        }
        num->head->size++;
    }
    
    return num;
}

void printI(BigInt* numI){
    Node* tempNode = numI->head;
    if(numI->sign){
        printf("-");
    }
    while(tempNode){
        printf("%d", tempNode->digits);
        tempNode = tempNode->next;
    }
}

int main(){
    BigInt* num = createI("-123456");
    printI(num);
    printf("\n");
    printf("%d", num->head->size);
}

#endif