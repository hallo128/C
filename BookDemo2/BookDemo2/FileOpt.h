//
//  FileOpt.h
//  BookDemo2
//
//  Created by apple on 2017/7/5.
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
#include <string.h>
#include "Book.h"   //对图书进行操作，所以需要导入图书的结构
#define BookInfoPath "BookInfo.dat"   //定义全局变量

/**将传入的图书保存到文件中（增加）*/
void SaveBook(Book * book);  //将新的图书保存到图书系统，用指针传参，可以方便在以后的操作中对该图书直接进行修改

/**从文件中获取所有的图书信息*/
Book * GetAllBooks(Book * book,int * bookCount);

/**获得文件中包含的图书信息总数*/
int GetBookCount();

/**打印图书数组*/
void printAllBooks();

/**(查询)
 * 根据图书的id查找对应的图书信息
 * @param id 要查找的图书id
 * @return 如果查到，返回该图书信息；如果没有查到，返回NULL
 */
Book * GetBookById(int id);

/**(删除)
 * 根据图书的id删除对应的图书信息
 * @param id 要删除的图书id
 * @return 如果删除成功，返回1；如果失败，返回0
 */
int DeleteBookById(int id);

/**(更新)
 * 根据图书的id更新文件中的图书信息
 * @param book 要更新的确定id的图书的新结构内容（某一本书）
 * @return 如果更新成功，返回1；如果更新，返回0
 */
int UpdateBook(Book * book);

/**获得文件中最后一本书的id+1*/
int GetNewBookId();



#endif /* FileOpt_h */
