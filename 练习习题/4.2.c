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
    int n;
    
    printf("Enter a three-digit number: ");
    scanf("%d", &n);
    printf("The reversal is: %d%d%d\n", n % 10, (n / 10) % 10, n / 100);
    
    return 0;
}

