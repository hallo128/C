//
//  main.c
//  C
//
//  Created by apple on 2017/1/8.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>


int main(void)
{
    int p,i,j,k;
    printf("Enter a dollar amount:");
    scanf("%d",&p);

    i=p/20;
    j=(p-i*20)/10;
    k=(p-i*20-j*10)/5;
    printf("$20 bills:%d\n",i);
    printf("$10 bills:%d\n",j);
    printf("$5 bills:%d\n",k);
    printf("$1 bills:%d\n",p-i*20-j*10-k*5);
    
    return 0;
}
