//
//  BookView.c
//  BookDemo2
//
//  Created by apple on 2017/7/6.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "BookView.h"

void PrintBookArray(Book * bookArray,int bookCount){
    int i;
    if (bookArray == NULL) {
        printf("文件中暂时没有图书！/图书数组读取失败！");
        return;
    }
    printf("-------------------------------------------------------------------\n");
    printf("%-15s%-15s%-15s%-15s%-15s%-15s\n",
           "内部编号","图书名称","出版号","借阅状态","图书单价","借出时间");
    printf("-------------------------------------------------------------------\n");
    for (i=0; i<bookCount; i++) {
        printf("%-10d%-15s%-11s%-12s%-9.2lf",
               bookArray[i].id,
               bookArray[i].name,
               bookArray[i].isbn,
               bookArray[i].status == CAN ? "可借" :"不可借",
               bookArray[i].price );
        //打印时间
        if (bookArray[i].borrowTime == 0) {//时间为空
            printf("---\n");
        }else{
            struct tm * pTime = localtime(&bookArray[i].borrowTime);
            printf("%d-%d-%d %2d:%2d:%2d\n",
                   pTime->tm_year+1900,
                   pTime->tm_mon+1,
                   pTime->tm_mday,
                   pTime->tm_hour,
                   pTime->tm_min,
                   pTime->tm_sec);
        }
        
    }
    printf("-------------------------------------------------------------------\n");
}

/**打印登录菜单*/
int ShowLoginMenu(){
    //系统名称-可以从文件中读取
    char * sys_name = "Extreme Acadamy";
    printf("欢迎使用%s图书管理系统\n",sys_name);
    printf("1、登录系统\t2、退出\n");
    printf("请选择：");
    int choice =-1;
    scanf("%d",&choice);
    return choice;
}

/**打印主菜单*/
int ShowMainMenu(){
    printf("--------------\n");
    printf("1、增加\n2、删除\n3、查找\n4、借出\n5、归还\n6、查看图书系统的所有图书\n");
    printf("--------------\n");
    printf("欢迎进入图书管理系统！\n请选择您想要进行的操作(选择1-6以外的任意键，可以退出系统)：");
    int choice = -1;
    scanf("%d",&choice);
    return choice;
}


/**根据借阅状态，打印数组中相应的图书数组*/
void PrintBookStatus(Book * bookArray,int bookCount,BookStatus givenStatus){
    int i;int tempTime;
//    int bookCount = sizeof(bookArray)/sizeof(Book);
    if (bookArray == NULL || bookCount ==0) {
        printf("文件中暂时没有图书！");
        return;
    }
    
    int choiceTime=-1;//将状态转换为借出时间，方便判断
    if (givenStatus == CAN) {
        choiceTime=0;
    }

    
    printf("---------------------------%s状态的所有图书-----------------------\n"
           ,(givenStatus == CAN ? "可借" :"可归还"));
    printf("%-15s%-15s%-15s%-15s%-15s%-15s\n",
           "内部编号","图书名称","出版号","借阅状态","图书单价","借出时间");
    printf("-------------------------------------------------------------------\n");
    for (i=0; i<bookCount; i++) {
        tempTime=-1;
        if (bookArray[i].borrowTime == 0) {
            tempTime=0;
        }
        if(tempTime == choiceTime){ //只打印给定状态的数组
            printf("%-10d%-15s%-11s%-12s%-9.2lf",
                   bookArray[i].id,
                   bookArray[i].name,
                   bookArray[i].isbn,
                   bookArray[i].status == CAN ? "可借" :"不可借",
                   bookArray[i].price );
            //打印时间
            if (bookArray[i].borrowTime == 0) {//时间为空
                printf("---\n");
            }else{
                struct tm * pTime = localtime(&bookArray[i].borrowTime);
                printf("%d-%d-%d %2d:%2d:%2d\n",
                       pTime->tm_year+1900,
                       pTime->tm_mon+1,
                       pTime->tm_mday,
                       pTime->tm_hour,
                       pTime->tm_min,
                       pTime->tm_sec);
            }
        }
    }
    printf("-------------------------------------------------------------------\n");
}



