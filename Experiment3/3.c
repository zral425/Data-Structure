#include<stdio.h>
#define max 100

typedef struct{
    char data[max];
    int front;
    int rear;
}quene;

void Initquene(quene *q){
    q->front=0;
    q->rear=0;
}
int Isempty(quene *q){
    return q->front==q->rear;
}
int Isfull(quene *q){
    return (q->rear+1)%max==q->front;
}

int Enter(quene *q,char x){
    if(Isfull(q))return 0;
    q->data[q->rear]=x;
    q->rear=(q->rear+1)%max;
    return 1;
}

int Out(quene *q,char *x){
    if(Isempty(q))return 0;
    *x=q->data[q->front];
    q->front=(q->front+1)%max;
    return 1;
}

void Print(quene *q){
    printf("[");
    int i=q->front;
    while(i!=q->rear){
        printf("%c",q->data[i]);
        i=(i+1)%max;
        if(i!=q->rear)printf(",");
    }
    printf("]");
}

int main(){
    quene q;
    Initquene(&q);
    char str[]="asdfghjkl";
    for(int i=0;str[i]!='\0';i++){
        Enter(&q,str[i]);
        Print(&q);
    }
    char x;
    while(!Isempty(&q)){
        Out(&q,&x);
        Print(&q);
    }
    return 0;
}