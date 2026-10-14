#include<stdio.h>
#include<stdlib.h>

#define max 20

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

void ReverseLinkList(Node **head){
    Node *prev=NULL;
    Node *curr=(*head)->next;
    Node *next=NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    (*head)->next=prev;
}
int main(){
    Node *head;
    InitList(&head);
    char ch[]="abcdefgh";
    for(int i=0;ch[i]!='\0';i++){
        Append(head,ch[i]);
    }
    ReverseLinkList(&head);
    PrintList(head);
    return 0;
}