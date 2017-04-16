//
//  Hotel.c
//  酒店
//
//  Created by apple on 2017/2/21.
//  Copyright © 2017年 apple. All rights reserved.
// 对应Hotel.h的实现

#include <stdio.h>
#include "Hotel.h"  //包含自定义头文件时，用双引号

char hotelName[4][50]={
    "贝罗酒店","榭舍酒店","阿斯图里酒店","斯克里布酒店"
};

//菜单函数：显示菜单选项，接受并返回用户输入
int menu(void){
    int i,choice;  //用户的选择
    printf("请选择入住的酒店：\n");
    for (i=0; i<4; i++) {
        printf("%d、%s\n",i+1, hotelName[i]);
    }
    printf("5、退出程序\n");
    printf("请输入您选择入住的酒店：");
    //用户的选择不能是非数字
    //选择只能是1-5
    scanf("%d",&choice);
    return choice;
}



int getNight(void); //返回预定的天数
void showPrice(int nights); //根据天数显示最终支付金额

