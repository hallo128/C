//
//  BookView.h
//  BookDemo2
//
//  Created by apple on 2017/7/6.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef BookView_h
#define BookView_h

/**
 * 包含了图书的打印、菜单
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Book.h"

/**打印传入的图书数组*/
void PrintBookArray(Book * bookArray,int bookCount);

/**打印登录菜单*/
int ShowLoginMenu();

/**打印主菜单*/
int ShowMainMenu();

/**根据借阅状态，打印相应的图书数组*/
void PrintBookStatus(Book * bookArray,int bookCount,BookStatus givenStatus);



#endif /* BookView_h */
