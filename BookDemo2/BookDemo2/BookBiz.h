//
//  BookBiz.h
//  BookDemo2
//
//  Created by apple on 2017/7/6.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef BookBiz_h
#define BookBiz_h

#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "FileOpt.h"
#include "BookView.h"

/**
 * 添加图书
 * 功能：1-自动添加id；2-让用户录入新书信息；3-将新书信息追加到文件中
 */

/**增加*/
void AddBook();

/**删除*/
void DeleteBook();

/**查找*/
void SearchBook();

/**借出*/
void BorrowBook();

/**归还*/
void RevertBook();



#endif /* BookBiz_h */
