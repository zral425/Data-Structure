#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct{
    int data[max];
    int top;
}SqStack;

void InitStack(SqStack *S){
    S->top=-1;
}

int StackEmpty(SqStack *S){
    return S->top==-1;
}

int Push(SqStack *S,int x){
    if(S->top==max){
        return 0;
    }
    S->data[++S->top]=x;
    return 1;
}

int Pop(SqStack *S,int *x){
    if(StackEmpty(S))
        return 0;
    *x=S->data[S->top--];
    return 1;
}

void Converse(int n){
    SqStack S;
    InitStack(&S);
    while(n>0){
        Push(&S,n%8);
        n/=8;
    }
    int x;
    while(!StackEmpty(&S)){
        Pop(&S,&x);
        printf("%d",x);
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t<0){
        return 1;
    }
    Converse(t);
    return 0;
}