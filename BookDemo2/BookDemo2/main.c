//
//  main.c
//  BookDemo2
//
//  Created by apple on 2017/7/5.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Book.h"
#include "FileOpt.h"
#include "BookBiz.h"
#include "BookView.h"

int main(int argc, const char * argv[]) {
    
    int choice = ShowLoginMenu();
    if (choice != 1) {
        exit(EXIT_SUCCESS); //不进行退出，就是成功登录了
    }
    
    while (1) {
        choice = ShowMainMenu();
        switch (choice) {
            case 1:
                //增加
                AddBook();
                break;
            case 2:
                //删除
                DeleteBook();
                break;
            case 3:
                //查找
                SearchBook();
                break;
            case 4:
                //借出
                BorrowBook();
                break;
            case 5:
                //归还
                RevertBook();
                break;
            case 6:
                //查看图书系统的所有图书
                printAllBooks();
                break;
            default:
                exit(EXIT_SUCCESS);
        }
    }
    
    return 0;
}
