#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coef;
    int exp;
    struct Node *next;
}Node,*LinkList;

Node* CreateNode(int coef,int exp){
    Node *p=(Node*)malloc(sizeof(Node));
    if(p==NULL){
        printf("Error\n");
        exit(1);
    }
    p->coef=coef;
    p->exp=exp;
    p->next=NULL;
    return p;
}

void InitList(Node **head){
    *head=CreateNode(0,0); 
}

void Append(Node *head,int coef,int exp){
    Node *t=head;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=CreateNode(coef,exp);
}

void PrintPoly(Node *head){
    Node *t=head->next;
    int first=1;
    if(t==NULL){
        printf("0\n");
        return;
    }
    while(t!=NULL){
        if(!first&&t->coef>0)printf(" + ");
        else if(!first)printf(" - ");
        else if(t->coef<0)printf("-");
        int c=t->coef<0?-t->coef:t->coef;
        if(t->exp==0)printf("%d",c);
        else if(t->exp==1)printf("%dx",c);
        else printf("%dx%d",c,t->exp);
        first=0;
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

Node* PolyAdd(Node *a,Node *b){
    Node *c;
    InitList(&c);          
    a=a->next;            
    b=b->next;
    while(a!=NULL&&b!=NULL){
        if(a->exp>b->exp){
            Append(c,a->coef,a->exp);
            a=a->next;
        }else if(a->exp<b->exp){
            Append(c,b->coef,b->exp);
            b=b->next;
        }else{
            int s=a->coef+b->coef;
            if(s!=0)Append(c,s,a->exp);
            a=a->next;
            b=b->next;
        }
    }
    while(a!=NULL){
        Append(c,a->coef,a->exp);
        a=a->next;
    }
    while(b!=NULL){
        Append(c,b->coef,b->exp);
        b=b->next;
    }
    return c;
}

int main(){
    int acoef[4]={7,3,9,5},aexp[4]={0,1,8,17};
    int bcoef[3]={8,22,-9},bexp[3]={1,7,8};
    Node *a,*b,*c;
    InitList(&a);
    InitList(&b);
    for(int i=3;i>=0;i--){
        Append(a,acoef[i],aexp[i]);
    }
    for(int i=2;i>=0;i--){
        Append(b,bcoef[i],bexp[i]);
    }
    c=PolyAdd(a,b);
    PrintPoly(c);
    FreeList(a);
    FreeList(b);
    FreeList(c);
    return 0;
}
