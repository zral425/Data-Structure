#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkList;

Node* CreateNode(int x){
    Node *p=(Node*)malloc(sizeof(Node));
    if(p==NULL){
        printf("Error\n");
        exit(1);
    }
    p->data=x;
    p->next=NULL;
    return p;
}

void InitList(Node **head){
    *head=CreateNode(0); 
}

void Append(Node *head,int x){
    Node *t=head;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=CreateNode(x);
}

void PrintList(Node *head){
    Node *t=head->next;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}

void FreeList(Node *head){
    Node *t;
    while(head!=NULL){
        t=head;
        head=head->next;
        free(t);
    }
}

Node* Merge(Node *a,Node *b){
    Node *head=a;        
    Node *bh=b;        
    a=a->next;            
    b=b->next;
    head->next=NULL;      
    while(a!=NULL&&b!=NULL){
        Node *p;
        if(a->data<=b->data){
            p=a;
            a=a->next;
        }else{
            p=b;
            b=b->next;
        }
        p->next=head->next;   
        head->next=p;
    }

    while(a!=NULL){
        Node *p=a;
        a=a->next;
        p->next=head->next;
        head->next=p;
    }
    while(b!=NULL){
        Node *p=b;
        b=b->next;
        p->next=head->next;
        head->next=p;
    }
    free(bh);
    return head;
}

int main(){
    Node *a,*b;
    int x[4]={3,7,8,9},y[3]={2,5,7};
    InitList(&a);
    InitList(&b);
    for(int i=0;i<4;i++){
        Append(a,x[i]);
    }
    for(int i=0;i<3;i++){
        Append(b,y[i]);
    }
    Node *head=Merge(a,b);
    PrintList(head);
    FreeList(head);
    return 0;
}
