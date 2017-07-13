//
//  main.c
//  transform
//
//  Created by apple on 2017/5/21.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>

//十进制-
void ten2num(int num,int want_transform);  //十进制-二、八、十六进制（由want_transform指定需要转换的进制2、8、16）
/*
void ten2eight(int num);    //十进制-八进制
void ten2two(int num);    //十进制-二进制
void ten2sixteen(int num);    //十进制-十六进制
 */
//-十进制
void num2ten(int num,int now_transform);  //二、八-十进制（由now_transform指定目前的进制2、8）
//8进制（以0开头）与16进制（以0X开头）只需要进行强制转换（int）



int main(int argc, const char * argv[]) {
    int num;
    
    printf("请输入待转换的十进制数：\n");
    scanf("%d",&num);
    printf("二进制表示：");
    ten2num(num,2);
    printf("八进制表示：");
    ten2num(num,8);
    printf("十六进制表示：");
    ten2num(num,16);
    printf("\n其他进制转换为十进制：\n");
    /*
    ten2eight(num);
    ten2two(num);
    ten2sixteen(num);
     */
    printf("二进制[%d]的十进制表示：",11110);
    num2ten(11110,2);
    printf("八进制[%d]的十进制表示：",36);
    printf("%d",(int)036);   //或者num2ten(36,8);
    printf("\n十六进制[%s]的十进制表示：","1E");
    printf("%d",(int)0X1E);
    return 0;
}

void ten2num(int num,int want_transform){
    int j,i=0;
    int nums[100];    //用来存放余数的数组,指定最多为100的个数
    char c_nums[100];    //用来存放余数的数组,指定最多为100的个数
    //16进制转换的字符数组
    char charNum[] = {'1','2','3','4','5','6','7','8','9',
        'A','B','C','D','E','F'};
    if (want_transform == 2 || want_transform == 8) {
        while (num != 0) {
            nums[i++]=num % want_transform;
            num /= want_transform;
        }
        //倒序余数数组
        for (j=i-1; j>=0; j--) {
            printf("%d",nums[j]);
        }
        printf("\n");
    }
    if (want_transform == 16) {
        while (num != 0) {
            c_nums[i++]=charNum[(num % 16)-1];
            num /= 16;
        }
        //倒序余数数组
        for (j=i-1; j>=0; j--) {
            printf("%c",c_nums[j]);
        }
        printf("\n");
    }
}

//二、八进制-十进制（由now_transform指定目前的进制2、8）
void num2ten(int num,int now_transform){
    int j,k,i=0;
    int e;          //为每个位置需要乘的次方数
    int now_num=0;
    int nums[100];    //用来存放余数的数组,指定最多为100的个数
      //  'A','B','C','D','E','F'};
    if (now_transform == 2 || now_transform == 8) {
        while (num != 0) {
            nums[i++]=num % 10;
            num /= 10;
        }
        //倒序余数数组
        for (j=i-1; j>=0; j--) {
            e=1;
            for (k=1; k<=j; k++) {   //第j个位置的次方数为：当前进制的（j-1）次方
                e *= now_transform;
            }
            now_num += nums[j]*e;
        }
        printf("%d\n",now_num);
    }
}


/*
void ten2eight(int num){
    int nums[100];    //用来存放余数的数组,指定最多为100的个数
    int j,i=0;
    while (num != 0) {
        nums[i++]=num % 8;
        num /= 8;
    }
    //倒序余数数组
    for (j=i-1; j>=0; j--) {
        printf("%d",nums[j]);
    }
    printf("\n");
}

//十进制-二进制
void ten2two(int num){
    int nums[100];    //用来存放余数的数组,指定最多为100的个数
    int j,i=0;
    while (num != 0) {
        nums[i++]=num % 2;
        num /= 2;
    }
    //倒序余数数组
    for (j=i-1; j>=0; j--) {
        printf("%d",nums[j]);
    }
    printf("\n");
}

//十进制-十六进制
void ten2sixteen(int num){
    char nums[100];    //用来存放余数的数组,指定最多为100的个数
    int j,i=0;
    //转换的字符数组
    char charNum[] = {'1','2','3','4','5','6','7','8','9',
                      'A','B','C','D','E','F'};
    while (num != 0) {
        nums[i++]=charNum[(num % 16)-1];
        num /= 16;
    }
    //倒序余数数组
    for (j=i-1; j>=0; j--) {
        printf("%c",nums[j]);
    }
    printf("\n");
}
*/


