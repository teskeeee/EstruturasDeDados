#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Stack.h"

int main(){
    Stack *resto = create_stack();

    int decimal, n;

    scanf("%d", &decimal);

    int quociente = decimal;

    while(quociente != 0){
        push(resto, quociente%2);
        quociente = quociente/2;
    }
    
    if(decimal == 0){
            printf("0\n");
    }

    else {
        while(is_empty(resto) == 0){
        pop(resto, &n);
        printf("%d", n);
        }

    printf("\n");
}


    return 0;
}