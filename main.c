#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

int is_operator(const char *token){
    if(strlen(token) != 1) return 0;

    switch(token[0]){
        case '+': case '-': case '*': case '/':
            return 1;
        default:
            return 0;
    }
}

int converte_numero(const char *token, int *valor){
    char *endptr;
    long resultado = strtol(token, &endptr, 10);

    if(endptr == token || *endptr != '\0') return 0;

    *valor = (int)resultado;
    return 1;
}

int aplica_operacao(char op, int a, int b, int *resultado){
    switch(op){
        case '+': *resultado = a + b; return 1;
        case '-': *resultado = a - b; return 1;
        case '*': *resultado = a * b; return 1;
        case '/':
            if(b == 0) return -1;
            *resultado = a / b;
            return 1;
        default:
            return -1;
    }
}

int main(){
    Stack *pilha = create_stack();
    char token[32];

    while(scanf("%s", token) == 1){
        int valor;

        if(converte_numero(token, &valor)){
            if(push(pilha, valor) == -1){
                free_stack(&pilha);
                return -1;
            }
        }
        else if(is_operator(token)){
            int a, b, resultado;

            if(pop(pilha, &b) == -1 || pop(pilha, &a) == -1){
                free_stack(&pilha);
                return -1;
            }

            if(aplica_operacao(token[0], a, b, &resultado) == -1){
                free_stack(&pilha);
                return -1;
            }

            if(push(pilha, resultado) == -1){
                free_stack(&pilha);
                return -1;
            }
        }
        else {
            free_stack(&pilha);
            return -1;
        }
    }

    int resposta;
    if(pop(pilha, &resposta) == -1){
        free_stack(&pilha);
        return -1;
    }

    printf("%d\n", resposta);

    free_stack(&pilha);

    return 1;
}