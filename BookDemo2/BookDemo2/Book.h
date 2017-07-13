//
//  Book.h
//  BookDemo2
//
//  Created by apple on 2017/7/5.
//  Copyright © 2017年 apple. All rights reserved.
//



#ifndef Book_h
#define Book_h

#include <time.h>

/**图书状态枚举*/
typedef enum {
    CAN=1,
    NOT
}BookStatus;

//图书结构
typedef struct{
    int id;       //图书的内部编号
    char name[50];//图书名称
    char isbn[50];//出版号
    double price; //图书单价
    BookStatus status;//图书状态
    time_t borrowTime;// 借出时间
}Book;



#endif /* Book_h */

