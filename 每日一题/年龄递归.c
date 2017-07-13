#include <stdio.h>

int relAge(int);

int main(){
    int n;
    
    printf("你想知道第几个人的年龄输入[1-5]:");
    scanf("%d",&n);
    printf("第%d个人的年龄为%d\n",n,relAge(n));
    
    return 0;
}

int relAge(int n){
    int age;
    
    if (n == 1)
        age = 18;
    else if(n==5)
        age = relAge(n-1) + 2;
    else
        age = relAge(n-1) + 3;
    
    return age;
}