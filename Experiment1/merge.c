#include<stdio.h>

#define max 30

typedef struct{
    int data[max];
    int length;
}SqList;

void InitList(SqList *L){
    L->length=0;
}

void Append(SqList *L,int x){
    if(L->length>=max)
    return;
    L->data[L->length]=x;
    L->length++;
}

void PrintList(SqList L){
    for(int i=0;i<L.length;++i){
        printf("%d ",L.data[i]);
    }
}

void merge(SqList *L1,SqList *L2,SqList *L3){
    int i=0,j=0,k=0;
    while(i<L1->length&&j<L2->length){
        if(L1->data[i]<L2->data[j]){
            L3->data[k++]=L1->data[i++];
        }
        else{
            L3->data[k++]=L2->data[j++];
        }
    }
    while(i<L1->length){
        L3->data[k++]=L1->data[i++];
    }
    while(j<L2->length){
        L3->data[k++]=L2->data[j++];
    }
    L3->length=k;
}

int main(){
    int a[]={3,5,8,10},b[]={2,6,8,9,11,15,20};
    SqList L1,L2,L3;
    InitList(&L1);
    InitList(&L2);
    InitList(&L3);
    for(int i=0;i<(int)(sizeof(a)/sizeof(a[0]));++i){
        Append(&L1,a[i]);
    }
    for(int i=0;i<(int)(sizeof(b)/sizeof(b[0]));++i){
        Append(&L2,b[i]);
    }
    merge(&L1,&L2,&L3);
    PrintList(L3);
    return 0;
}