#include<stdio.h>
#include<stdlib.h>

#define max 20

typedef struct{
    char data[max];
    int length;
}SqList;

void InitList(SqList *L){
    L->length=0;
}

void Append(SqList *L,char ch){
    if(L->length>=max)
    return;
    L->data[L->length]=ch;
    L->length++;
}

void Insert(SqList *L,int i,char ch){
    if(i<1||i>L->length+1)
    return;
    if(L->length>=max)
    return;
    for(int j=L->length;j>=i;j--){
        L->data[j]=L->data[j-1];
    }
    L->data[i-1]=ch;
    L->length++;
}

void PrintList(SqList L){
    for(int i=0;i<L.length;++i){
        printf("%c",L.data[i]);
    }
    printf("\n");
}

int main(){
    char str[]="ajcniydu";
    SqList L;
    InitList(&L);
    for(int i=0;str[i]!='\0';++i){
        Append(&L,str[i]);
    }
    Insert(&L,3,'p');
    PrintList(L);
    return 0;
}