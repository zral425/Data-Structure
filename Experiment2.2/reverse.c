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

void ReverseSqList(SqList *L){
    int i=0,j=L->length-1;
    while(i<j){
        char temp=L->data[i];
        L->data[i]=L->data[j];
        L->data[j]=temp;
        i++;
        j--;
    }
}

void PrintList(SqList L){
    for(int i=0;i<L.length;++i){
        printf("%c",L.data[i]);
    }
}

int main(){
    char str[]="abcdefgh";
    SqList L;
    InitList(&L);
    for(int i=0;str[i]!='\0';++i){
        Append(&L,str[i]);
    }
    ReverseSqList(&L);
    PrintList(L);
    return 0;
}