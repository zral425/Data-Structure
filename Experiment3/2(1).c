#include<stdio.h>
long long fun(int n){
    if(n==0||n==1){
        return 1;
    }
    else{
        return n*fun(n-1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    if(n<0)return 0;
    printf("%lld",fun(n));
    return 0;
}