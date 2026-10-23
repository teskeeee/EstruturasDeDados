#include "Stack.h"
#include <stdlib.h>

#define MAX 100

struct stack{
   int vetor[MAX];
   int qtd;
};

Stack* create_stack(void){
    Stack *s = malloc(sizeof(Stack));

    if(!s) return NULL;

    s->qtd = 0;

    return s;
}

int is_empty(const Stack *s){
    if(!s) return -1;

    if(s->qtd <= 0) return 1;

    return 0;

}
int is_full(const Stack *s){
    if(!s) return -1;

    if(s->qtd >= MAX) return 1;

    return 0;
}
int push(Stack *s, int value){
    if(!s) return -1;

    if(s->qtd >= MAX) return -1;

    s->vetor[s->qtd] = value;

    s->qtd++;

    return 1;
}

int pop(Stack *s, int *value){
    if(!s) return -1;

    if(s->qtd <= 0) return -1;

    *value = s->vetor[s->qtd - 1];
    s->qtd--;

    return 1;
}

int peek(const Stack *s, int *value){
    if(!s) return -1;

    *value = s->vetor[s->qtd - 1];

    return 1;
}

void free_stack(Stack **s){
    if(!s || !*s) return;

    free(*s);

    *s = NULL;
}