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
    int score;
    
    printf("Enter student' score: ");
    scanf("%d", &score);
    
    if (score < 60)
        printf("the student belongs to group: C\n");
    else if (score < 90)
        printf("the student belongs to group: B\n");
    else
        printf("the student belongs to group: A\n");
   
    
    return 0;
}


