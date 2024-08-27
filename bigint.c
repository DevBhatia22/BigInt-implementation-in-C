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
int absCompI(BigInt* num1, BigInt* num2);
int compI(BigInt* num1, BigInt* num2);
void _reBuildI(BigInt* num);
void _printI(BigInt* num);




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

//Rebuild
void _reBuildI(BigInt* num){
    
    Node* tempNode = num->head;
    
    while(tempNode != num->tail && tempNode->digits == 0){
        tempNode = tempNode->next;
        free(tempNode->prev);
        tempNode->prev = NULL;
        num->size--;
    }
    
    num->head = tempNode;
    
    return;
    
}

//Print
void printI(BigInt* numI){
    
    _reBuildI(numI);
    
    Node* tempNode = numI->head;
    
    if(numI->sign){
        printf("-");
    }
    
    int zero = 0;
    while(tempNode){
        if(tempNode != numI->head){    
            int limit = 4;
            
            if(tempNode->digits < 10){
                limit = 1;
            }
            else if(tempNode->digits < 100){
                limit = 2;
            }
            else if(tempNode->digits < 1000){
                limit = 3;
            }

            for(int i = 0; i < 4 - limit; i++){
                printf("0");
            }
        }
        printf("%d", tempNode->digits);
        tempNode = tempNode->next;
        zero = 1;
    }
    
}

//_PrintI
void _printI(BigInt* numI){
    
    Node* tempNode = numI->head;
    
    if(numI->sign){
        printf("-");
    }
    
    while(tempNode){
        printf("%d ", tempNode->digits);
        tempNode = tempNode->next;
    }
    
}

//Compare 1
int absCompI(BigInt* num1, BigInt* num2){
    
    if(num1->size > num2->size){
        return 1;
    }
    if(num1->size < num2->size){
        return -1;
    }
    
    Node* n1 = num1->head, *n2 = num2->head;
    
    while(n1){
        if(n1->digits > n2->digits){
            return 1;
        }
        if(n1->digits < n2->digits){
            return -1;
        }
        
        n1 = n1->next;
        n2 = n2->next;
    }
    
    return 0;
    
}

//Compare 2
int compI(BigInt* num1, BigInt* num2){
    
    if(num1->size > num2->size || (!num1->sign && num2->sign)){
        return 1;
    }
    if(num1->size < num2->size || (num1->sign && !num2->sign)){
        return -1;
    }
    
    Node* n1 = num1->head, *n2 = num2->head;
    
    while(n1){
        if(n1->digits > n2->digits){
            return 1;
        }
        if(n1->digits < n2->digits){
            return -1;
        }
        
        n1 = n1->next;
        n2 = n2->next;
    }
    
    return 0;
    
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
    else{
        BigInt* answer;
        if(num2->sign){
            num2->sign = 0;
            answer = subI(num1, num2);
            num2->sign = 1;
        }
        else{
            num1->sign = 0;
            answer = subI(num2, num1);
            num1->sign = 1;
        }
        return answer;
    }
}

//sub
BigInt* subI(BigInt* num1, BigInt* num2){
    
    if(num1->sign && !num2->sign){ // (-x) - y => (-x) + (-y)
        num2->sign = 1;
        BigInt* answer = addI(num1, num2);
        num2->sign = 0;
        return answer;
    }
    if(!num1->sign && num2->sign){ // x - (-y) => x + y
        num2->sign = 0;
        BigInt* answer = addI(num1, num2);
        num2->sign = 1;
        return answer;
    }
    
    int borrow = 0;
    BigInt* answer = (BigInt*) malloc(sizeof(BigInt));
    answer->head = (Node*) malloc(sizeof(Node));
    answer->tail = answer->head;
    Node* tempNode = answer->head;
    
    int comp = absCompI(num1, num2);
    if(!comp){
        answer->head->digits = 0;
        return answer;
    }
    Node* n1, *n2;
    if(comp == -1){
        n1 = num2->tail;
        n2 = num1->tail;
        answer->sign = !num2->sign;
    }
    else{
        n1 = num1->tail;
        n2 = num2->tail;
        answer->sign = num2->sign;
    }
    
    while(n1 || n2){
        int sub = borrow;
        borrow = 0;
        if(n1){
            if(n1->digits + sub < 0){
                borrow--;
                int num = 10000 + n1->digits;
                sub += num;
            }
            else{
                sub += n1->digits;
            }
        }
        if(n2){
            if((sub - n2->digits) < 0){
                borrow--;
                sub += 10000;
            }
            sub -= n2->digits;
        }
        
        tempNode->digits = sub;
        if(n1){
            n1 = n1->prev;
        }
        if(n2){
            n2 = n2->prev;
        }
        if(n1 || n2){
            tempNode->prev = (Node*) malloc(sizeof(Node));
            tempNode->prev->next = tempNode;
            tempNode = tempNode->prev;
            answer->size++;
        }
    }
    
    answer->head = tempNode;
    
    _reBuildI(answer);
    
    return answer;
    
}

//mul
BigInt* mulI(BigInt* num1, BigInt* num2){
    
    int size = num1->size + num2->size;
    
    BigInt* answer = (BigInt *) malloc(sizeof(BigInt));
    answer->head = (Node* ) malloc(sizeof(Node));
    answer->tail = answer->head;
    answer->size++;
    Node* tempNode = answer->tail;
    Node* array[size];
    answer->sign = num1->sign ^ num2->sign;
    
    for(int i = 0; i < size; i++){
        array[i] = tempNode;
        tempNode->digits = 0;
        Node* temp = (Node*) malloc(sizeof(Node));
        tempNode->prev = temp;
        temp->next = tempNode;
        tempNode = tempNode->prev;
        answer->size++;
    }
    answer->head = tempNode;
    
    Node* n1 = num1->tail, *n2 = num2->tail;
    int i = 0, j = 0;
    
    while(n1){
        while(n2){
            array[i + j]->digits += n1->digits * n2->digits;
            array[i + j + 1]->digits += array[i + j]->digits / 10000;
            array[i + j]->digits %= 10000;
            n2 = n2->prev;
            j++;
        }
        i++;
        n1 = n1->prev;
        n2 = num2->tail;
        j = 0;
    }
    
    _reBuildI(answer);
    
    return answer;
    
}

int main(){
    BigInt* num1 = createI("-99999999");
    BigInt* num2 = createI("-99999999");
    BigInt* num = mulI(num1, num2);
    printI(num);
    printf("\n%d\n", 100);
    // printf("%d\n", num->tail->prev->digits);
}

// #endif