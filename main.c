#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bigint.h"

int main(){
    char str[1000];
    fgets(str, 1000, stdin);
    printf("%s", str);
    BigInt* temp = createI(str);
    printI(temp);
    printf("\n");
    return 0;
}