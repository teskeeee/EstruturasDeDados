#include <stdlib.h>
#include "Queue.h"

#define MAX 100

struct queue {
    int dados[MAX];
    int inicio;
    int fim;
    int qtd;
};

Queue* create_queue() {
    Queue *q = malloc(sizeof(Queue));

    if (q == NULL)
        return NULL;

    q->inicio = 0;
    q->fim = 0;
    q->qtd = 0;

    return q;
}

int is_empty(const Queue *q) {
    if (q == NULL)
        return -1;

    return q->qtd == 0;
}

int is_full(const Queue *q) {
    if (q == NULL)
        return -1;

    return q->qtd == MAX;
}

int enqueue(Queue *q, int value) {
    if (q == NULL)
        return -1;

    if (is_full(q))
        return 0;

    q->dados[q->fim] = value;

    q->fim++;

    if (q->fim == MAX)
        q->fim = 0;

    q->qtd++;

    return 1;
}

int dequeue(Queue *q, int *value) {
    if (q == NULL || value == NULL)
        return -1;

    if (is_empty(q))
        return 0;

    *value = q->dados[q->inicio];

    q->inicio++;

    if (q->inicio == MAX)
        q->inicio = 0;

    q->qtd--;

    return 1;
}

int front(const Queue *q, int *value) {
    if (q == NULL || value == NULL)
        return -1;

    if (is_empty(q))
        return 0;

    *value = q->dados[q->inicio];

    return 1;
}

int size(const Queue *q) {
    if (q == NULL)
        return -1;

    return q->qtd;
}

void free_queue(Queue **q) {
    if (q != NULL && *q != NULL) {
        free(*q);
        *q = NULL;
    }
}