#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define max 100

typedef struct{
    double data[max];
    int top;
}OpndStack;

void InitOpnd(OpndStack *s){
    s->top=-1;
}

int OpndEmpty(OpndStack *s){
    return s->top==-1;
}

int OpndPush(OpndStack *s,double x){
    if(s->top==max-1)return 0;
    s->data[++s->top]=x;
    return 1;
}

int OpndPop(OpndStack *s,double *x){
    if(OpndEmpty(s))return 0;
    *x=s->data[s->top--];
    return 1;
}

int OpndTop(OpndStack *s,double *x){
    if(OpndEmpty(s))return 0;
    *x=s->data[s->top];
    return 1;
}

typedef struct{
    char data[max];
    int top;
}OptrStack;

void InitOptr(OptrStack *s){
    s->top=-1;
}

int OptrEmpty(OptrStack *s){
    return s->top==-1;
}

int OptrPush(OptrStack *s,char x){
    if(s->top==max-1)return 0;
    s->data[++s->top]=x;
    return 1;
}
int OptrPop(OptrStack *s,char *x){
    if(OptrEmpty(s))return 0;
    *x=s->data[s->top--];
    return 1;
}

int OptrTop(OptrStack *s,char *x){
    if(OptrEmpty(s))return 0;
    *x=s->data[s->top];
    return 1;
}

int IsOperator(char c){
    return c=='+'||c=='-'||c=='*'||c=='/'
            ||c=='('||c==')'||c=='#';
}

char Precede(char a,char b){
    if(a=='+'||a=='-'){
        if(b=='+'||b=='-'||b==')'||b=='#')return '>';
        else return '<';
    }
    if(a=='*'||a=='/'){
        if(b=='(')return '<';
        else return '>';
    }
    if(a=='('){
        if(b==')')return '=';
        else if(b=='#')return 'E';
        else return '<';
    }
    if(a==')'){
        return '>';
    }
    if(a=='#'){
        if(b=='#')return '=';
        if(b==')')return 'E';
        else return '<';
    }
}

double Operate(double a,char op,double b){
    switch(op){
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':
            if(b==0){
                printf("除数不能为零\n");
                exit(1);
            }
            return a/b;
    }
    return 0;
}

double Evaluate(char *expr){
    OpndStack opnd;
    OptrStack optr;
    double result=0;
    char c,topOp,op;
    double a,b;
    int i=0;
    int expectOperand=1; 
    InitOpnd(&opnd);
    InitOptr(&optr);
    OptrPush(&optr,'#');
    c=expr[i];
    while(1){
        if(c==' '||c=='\t'){c=expr[++i];continue;}
        OptrTop(&optr,&topOp);
        if(c=='#'&&topOp=='#')break;
        if(!IsOperator(c)){                
            double num=0,base=0.1;
            while(isdigit((unsigned char)expr[i])){  
                num=num*10+(expr[i]-'0');
                i++;                                   
            }
            if(expr[i]=='.'){                      
                i++;                                   
                while(isdigit((unsigned char)expr[i])){
                    num+=(expr[i]-'0')*base;
                    base*=0.1;
                    i++;
                }
            }
            OpndPush(&opnd,num);
            expectOperand=0;
            c=expr[i];                               
        }
        OptrTop(&optr,&topOp);
        if(c=='-'&&expectOperand){
            OpndPush(&opnd,0.0);
            OptrPush(&optr,'-');
            c=expr[++i];
            continue;
        }
        switch(Precede(topOp,c)){
            case '<':
                OptrPush(&optr,c);
                expectOperand=1;              
                c=expr[++i];
                break;
            case '>':
                if(!OptrPop(&optr,&op)||!OpndPop(&opnd,&b)||!OpndPop(&opnd,&a)){
                    printf("表达式有误：操作数不足\n");   
                    exit(1);
                }
                OpndPush(&opnd,Operate(a,op,b));    
                break;                                 
            case '=':                                    
                OptrPop(&optr,&op);
                if(op=='(')expectOperand=0;       
                c=expr[++i];
                break;
            default:
                printf("表达式有误：括号不匹配\n");
                exit(1);
        }
    }
    if (!OpndPop(&opnd,&result)){
        printf("表达式为空\n");
        exit(1);
    }
    return result;
}
int main(){
    char expr[200];
    if(!fgets(expr,sizeof(expr),stdin)) return 0;
    size_t len=0;
    while(expr[len]&&expr[len]!='\n'&&expr[len]!='\r') len++;
    if(expr[len-1]!='#'){ expr[len]='#'; expr[len+1]='\0'; }
    else expr[len]='\0';
    printf("=%g\n",Evaluate(expr));
    return 0;
}