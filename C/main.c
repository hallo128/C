//
//  main.c
//  C
//
//  Created by apple on 2017/1/8.
//  Copyright © 2017年 apple. All rights reserved.
//实现字符串的加密与解密

#include <stdio.h>
#include <math.h>

int main(){
    int i,j,isprime;
    int s=2; //特别的指定第一个素数为2
    
    //3以后使用的素数选择
    for(i=3;i<=10;i++){
        isprime=1;
        
        if(i % 2 == 0)
            isprime=0;
        else{
            for(j=3;j<=sqrt(i);j += 2){
                if(i % j == 0) {isprime=0;break;}
            }
        }
        
        if(isprime){
            //printf("%d\t",i);
            s *= i;
        }		
    }
    printf("\n1-10素数的乘积为:%d\n",s);
    
    return 0;
}
