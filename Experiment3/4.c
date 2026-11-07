#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 7        
typedef char ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int front;             
    int rear;            
} SqQueue;

void InitQueue(SqQueue *Q) { Q->front = Q->rear = 0; }

int QueueEmpty(SqQueue *Q) { return Q->front == Q->rear; }

int QueueFull(SqQueue *Q) { return (Q->rear + 1) % MAXSIZE == Q->front; }

int QueueLength(SqQueue *Q) { return (Q->rear - Q->front + MAXSIZE) % MAXSIZE; }

int EnQueue(SqQueue *Q, ElemType e) {
    if (QueueFull(Q)) return 0;        
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;   
    return 1;
}

int DeQueue(SqQueue *Q, ElemType *e) {
    if (QueueEmpty(Q)) return 0;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}

void PrintQueue(SqQueue *Q) {
    int i = Q->front;
    printf("[");
    while (i != Q->rear) {
        printf("%c", Q->data[i]); 
        i = (i + 1) % MAXSIZE; 
    }
    printf("]\n");
}

int main(void) {
    SqQueue Q;
    const char *s = "ABCDEF";
    ElemType e;
    int i;

    InitQueue(&Q);
    for (i = 0; s[i] != '\0'; i++) {
        EnQueue(&Q,s[i]);
        PrintQueue(&Q);
    }
    while (DeQueue(&Q, &e)) printf("%c ", e);
    return 0;
}