//
//  FileOpt.h
//  NewBookDemo
//
//  Created by apple on 2017/6/22.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef FileOpt_h
#define FileOpt_h

/**
 *文件操作
 *包含对文件的一些增删改查
 */
#include <stdio.h>
#include <stdlib.h>
#include "Book.h"   //对图书进行操作，所以需要导入图书的结构
#define BookInfoPath "BookInfo.dat"   //定义全局变量

/**将传入的图书保存到文件中*/
void SaveBook(Book * book);  //将新的图书保存到图书系统，用指针传参，可以方便在以后的操作中对该图书直接进行修改

/**从文件中获取所有的图书信息*/
Book* GetAllBooks(Book * book,int * bookCount);

/**获得文件中包含的图书信息总数*/
int GetBookCount();

/**打印图书数组*/
void printAllBooks(){
    int bookCount = -1;//图书总数
    int i;
    Book * bookArray = NULL;
    bookArray = GetAllBooks(NULL, &bookCount);
    //GetAllBooks(bookArray, &bookCount);
    printf("编号\t名称\t\t出版号\t单价\t状态\t借出日期\n");
    for (i=0; i<bookCount; i++) {
        printf("%d\t%s\t\t%s\t%.2lf\t%s\t",
               bookArray[i].id,
               bookArray[i].name,
               bookArray[i].isbn,
               bookArray[i].price,
               bookArray[i].status == CAN ? "可借" : "不可借"
               );
        printf("%ld",bookArray[i].borrowTime);  //时间随后处理
    }
    
}

#endif /* FileOpt_h */
