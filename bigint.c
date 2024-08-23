// #ifndef BIGINT_H
// #define BIGINT_H
//Handle case where we include file multiple times

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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




//Functions

//Create
BigInt* createI(char* str){
    
    BigInt* num = (BigInt*) malloc(sizeof(BigInt));
    num->head = (Node*) malloc(sizeof(Node));
    num->tail = num->head;
    Node* tempNode = num->head;
    num->size = 0;
    int n = 0;
    if(str[0] == '-'){
        num->sign = 1;
        n++;
    }
    
    for(int i = strlen(str) - 1; i >= n ; i--){
        
        int tempNum = 0;
        int limit = 4;
        
        int mul = 1;
        while(limit-- && i >= n){
            tempNum += (str[i] - '0') * mul;
            mul *= 10;
            i--;
        }
        i++;
        
        tempNode->digits = tempNum;
        
        if(i != n){
            tempNode->prev = (Node*) malloc(sizeof(Node));
            tempNode->prev->next = tempNode;
            tempNode = tempNode->prev;
            
        }
        num->size++;
    }
    num->head = tempNode;
    return num;
}

//Print
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

//add
BigInt* addI(BigInt* num1, BigInt* num2){
    
    if(num1->sign == num2->sign){
        int carry = 0;
        BigInt* answer = (BigInt*) malloc(sizeof(BigInt));
        answer->head = (Node*) malloc(sizeof(Node));
        answer->tail = answer->head;
        answer->sign = num2->sign;
        
        Node* tempNode = answer->head;
        answer->size = 0;
        
        Node* x = num1->tail, *y = num2->tail;
        
        while(x || y){
            int sum = carry;
            if(x){
                sum += x->digits;
            }
            if(y){
                sum += y->digits;
            }
            
            tempNode->digits = sum % 10000;
            carry = sum / 10000;
            // printf("%d \n", sum);
            if(x){
                x = x->prev;
            }
            if(y){
                y = y->prev;
            }
            
            if(x || y){
                tempNode->prev = (Node*) malloc(sizeof(Node));
                tempNode->prev->next = tempNode;
                tempNode = tempNode->prev;
                answer->size++;
            }
        }
        
        if(carry){
            tempNode->prev = (Node*) malloc(sizeof(Node));
            tempNode->prev->next = tempNode;
            tempNode = tempNode->prev;
            tempNode->digits = carry;
            answer->size++;
        }
        answer->head = tempNode;
        return answer;
    }
}

int main(){
    BigInt* num1 = createI("-99999999");
    BigInt* num2 = createI("-99999999");
    BigInt* num = addI(num1, num2);
    printI(num);
    printf("\n");
    printf("%d\n", num->head->digits);
}

// #endif