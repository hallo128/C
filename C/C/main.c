//
//  main.c
//  C
//
//  Created by apple on 2017/5/18.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>

int main()
{
    int m,i,j;
    int a[11] = { 2, 6, 7, 9, 13, 16, 19, 21, 25, 29 }; /* 由于后面有插入1个元素的操作，故数组长度定为11（虽然数组中只有10个元素） */
    scanf("%d",&m);
    for ( i = 0; i < 10; i++){
        if ( m < a[i]){
            for (j = 9; j >= i;j--)
                 {a[j + 1] = a[j];}
            a[i] = m;
            break;
        }
    }
    
    for ( i = 0; i < 11; i++)
    printf( "%d\t", a[i]);
    return 0;
}
