#include<stdio.h>
#include<string.h>
#define MAX 100

typedef struct{
    char data[MAX];
    int length;
}String;

void init(String *s,char *str){
    int i=0;
    while(str[i]!='\0'&&i<MAX){
        s->data[i]=str[i];
        i++;
    }
    s->length=i;
}

void Longest(String *s,String *t,String *r){
    int max=0;
    int start=0;
    for (int i=0;i<s->length;i++){
        for(int j=0;j<t->length;j++){
            int k=0;
            while(i+k<s->length&&j+k<t->length&&s->data[i+k]==t->data[j+k]){
                k++;
            }
            if(k>max){
                max=k;
                start=i;
            }
        }
    }
    r->length=max;
    for(int i=0;i<max;i++){
        r->data[i]=s->data[start+i];
    }
}
void print(String *s){
    for(int i=0;i<s->length;i++){
        printf("%c",s->data[i]);
    }
    printf("\n");
}

int main(){
    String s,t,r;
    char str1[MAX],str2[MAX];
    scanf("%s",str1);
    scanf("%s",str2);
    init(&s,str1);
    init(&t,str2);
    Longest(&s,&t,&r);
    if(r.length==0){
        printf("No common substring\n");
    }else{
        print(&r);
    }
    return 0;
}