//
//  main.c
//  组合情况
//
//  Created by apple on 2017/4/20.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int i,j,k,s,count=0; //i-5;j-3;k-1
    
    printf("5\t3\t1/3的组合情况：\n");
   
     for (i=1; i<=20; i++) {
         for (j=1; j<=33; j++) {
             for (k=3; k<=300; k+=3) {
                 s=5*i+3*j+k/3;
                 if (s==100 && i+j+k==100) {
                     printf("%d\t%d\t%d\n",i,j,k);count++;break;
                 }
             }
         }
     }
    printf("共有%d种组合情况\n",count);
    
    return 0;
}

