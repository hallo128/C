//
//  main.c
//  C
//
//  Created by apple on 2017/1/8.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#define AO (4.0f/3.0f)
#define PI 3.14159f

int main(void)
{
    float r,v;
    printf("Please input r:");
    scanf("%f",&r);

    v=AO*r*r*r*PI;
    printf("The V is %f\n",v);
    
    
    return 0;
}
