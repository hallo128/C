//
//  main.c
//  NewBookDemo
//
//  Created by apple on 2017/6/22.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Book.h"
#include "FileOpt.h"

int main(int argc, const char * argv[]) {
    
//    Book book;
//    book.id=1;
//    strcpy(book.name, "天龙"); //name不是指针
//    book.status=CAN;
//    
//    SaveBook(&book);
//    printf("图书总数：%d\n",GetBookCount());
//    printAllBooks();
    
//
    time_t timet;
    time(&timet);//1970-1-1到当前为止的秒数
    //等价于timet=time(NULL)
    
    printf("%d\n",timet);
    printf("year:%d\n",timet/60/60/24/365 + 1970);
    
    struct tm * pTime=localtime(&timet);
    printf("%d-%d-%d\n",pTime->tm_year + 1900,pTime->tm_mon + 1,pTime->tm_mday);

    
    
    return 0;
}
