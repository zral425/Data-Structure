#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node *next;
}Node,*LinkList;

Node* CreateNode(char ch){
    Node *p=(Node*)malloc(sizeof(Node));
    if(p==NULL){
        printf("Error\n");
        exit(1);
    }
    p->data=ch;
    p->next=NULL;
    return p;
}

void InitList(Node **head){
    *head=CreateNode(0);   
}

void Append(Node *head,char ch){
    Node *t=head;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=CreateNode(ch);
}

void PrintList(Node *head){
    Node *t=head->next;
    while(t!=NULL){
        printf("%c",t->data);
        t=t->next;
    }
}

void FreeList(Node *head){
    Node *t;
    while(head!=NULL){
        t=head;
        head=head->next;
        free(t);
    }
}

void Insert(Node *head,int i,char ch){
    if(!head||i<1)return;
    Node *t=head;
    int j=0;
    while(t->next!=NULL&&j<i-1){  
        t=t->next;
        j++;
    }
    if(j<i-1)return;               
    Node *s=CreateNode(ch);
    s->next=t->next;
    t->next=s;
}

int main(){
    Node *head;
    InitList(&head);
    char ch[]="asdfghjkl";
    for(int i=0;ch[i]!='\0';i++){
        Append(head,ch[i]);
    }
    Insert(head,4,'z');
    PrintList(head);
    FreeList(head);
    return 0;
}
