//
//  main.c
//  酒店
//
//  Created by apple on 2017/2/21.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#include "Hotel.h" 

//显示菜单
//double all_money(int,int);  //函数：让用户指定酒店和入住天数，返回总费用

extern char hotelName[4][50];

//int hotel[]={872,1838,789,1658};

int main(int argc, const char * argv[]) {
    int choice;
    
    //printf("%.2lf",all_money(0,2));
    choice=menu();
    if (choice >0 && choice < 5) {
        printf("当前用户的选择是：%s",hotelName[choice-1]);
    }
    
    return 0;
}


/*
//函数：让用户指定酒店和入住天数，返回总费用
double all_money(int rank,int n_day){
    int i;
    double s=0,day_money=hotel[rank];
    for (i=0; i<n_day; i++) {
        s += day_money;
        day_money *= 0.95;
    }
    return s;
}
*/
