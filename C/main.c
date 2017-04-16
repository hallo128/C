//
//  main.c
//  C
//
//  Created by apple on 2017/1/8.
//  Copyright © 2017年 apple. All rights reserved.
//实现字符串的加密与解密


#include <stdio.h>

int main(){
    int n,m;
    double p;
    
    printf("请输入总人数n：");
    scanf("%d",&n);
    printf("请输入初始位置m：");
    scanf("%d",&m);
    
    if (n % 2 == 0) {
        if (m % 2 == 0)
            p=2*m/(n*n);
        else
            p=2*(m-1)/(n*n);
    }
    else{
        if (m % 2 == 0)
            p=2*m/(n*n-1);
        else
            p=2*(m-1)/(n*n-1);
    }
    
    printf("%lf",p);
    
    return 0;
}



