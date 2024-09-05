#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bigint.h"

int main(){
    char str[1000];
    printf("ENTER DISTANCE IN KM : ");
    fgets(str, 1000, stdin);
    BigInt* num = createI(str);
    BigInt* temp = createI("1000");
    
    BigInt* answer = mulI(num, temp);
    
    freeI(temp);
    temp = createI("100");
    answer = mulI(answer, temp);
    
    freeI(temp);
    temp = createI("6250000000000000000000000000000");
    answer = mulI(answer, temp);
    
    printf("THIS IS THAT DISTANCE IN PLANKS LENGTH : ");
    printI(answer);
    printf("\n");
    return 0;
}