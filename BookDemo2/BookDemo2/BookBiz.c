//
//  BookBiz.c
//  BookDemo2
//
//  Created by apple on 2017/7/6.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "BookBiz.h"
#include <time.h>

void AddBook(){
    Book newBook;
    //1、获得添加的新书的id
    int newId = GetNewBookId();
    newBook.id = newId;
    //2、让用户录入书籍的信息
    printf("-------------(增加)\n");
    printf("请录入需要添加图书的信息：\n");
    printf("当前书籍的id: %d\n",newBook.id);
    printf("书籍名称：");
    scanf("%s",newBook.name);
    printf("出版号：");
    scanf("%s",newBook.isbn);
    printf("图书单价：");
    scanf("%lf",&(newBook.price));
    newBook.status = CAN;
    newBook.borrowTime = 0;//time(NULL);一开始增加的图书并不存在借出时间
    //3、调用函数将newbook的信息写入到文件中
    SaveBook(&newBook);    
}


void SearchBook(){
    int bookId = -1;
    printf("-------------(查找)\n");
    printf("请输入要查找的图书编号：");
    scanf("%d",&bookId);
    Book * book = GetBookById(bookId);
    if (NULL == book) {
        printf("没有找到这本书的任何信息，请重试！\n");
        return;
    }
    PrintBookArray(book,1);
}

/**删除*/
void DeleteBook(){
    int bookId = -1;
    printf("-------------(删除)\n");
    printf("请输入要删除的图书编号：");
    scanf("%d",&bookId);
    int result = DeleteBookById(bookId);
    if (result == 0) {
        printf("没有找到这本书的任何信息，请重试！");
        return;
    }
    if (result == 1) {
        printf("删除成功！");
        return;
    }
}




/**借出*/
void BorrowBook(){
    int bookId = -1;
    printf("################(借出)\n");
    //--打印可借图书
    int bookCount=-1;
    Book * bookArray = NULL;
    bookArray=GetAllBooks(NULL, &bookCount);
    PrintBookStatus(bookArray,bookCount,CAN);
    //--打印可借图书
    printf("请输入要借出的图书编号：");
    scanf("%d",&bookId);
    Book * book = GetBookById(bookId); //1-找到该图书
    if (NULL == book) {
        printf("没有找到这本书的任何信息，请重试！\n");
        return;
    }
    //2-判断图书是否可借
    if (book->status == CAN) {
        //3-修改图书借出时间,为当前时间
        book->borrowTime = time(NULL);
        book->status = NOT;
        //4-将修改信息，覆盖到文件中
        int result=UpdateBook(book);
        if (result==1) {
            printf("成功借出！\n");
        }else{
            printf("借出失败！\n");
        }
        
    }else{
        printf("抱歉，别人正在使用该本图书，借阅失败！\n");
        return;
    }

}

/**归还*/
void RevertBook(){
    int bookId = -1;
    printf("################(归还)\n");
    //--打印不可借图书
    int bookCount=-1;
    Book * bookArray = NULL;
    bookArray=GetAllBooks(NULL, &bookCount);
    PrintBookStatus(bookArray,bookCount,NOT);
    //--打印不可借图书
    printf("请输入要回归的图书编号：");
    scanf("%d",&bookId);
    Book * book = GetBookById(bookId); //1-找到该图书
    if (NULL == book) {
        printf("没有找到这本书的任何信息，请重试！\n");
        return;
    }
    //2-判断图书是否借出
    if (book->borrowTime != 0) {
        //3-修改图书回归时间
        book->borrowTime = 0;
        book->status = CAN;
        //4-将修改信息，覆盖到文件中
        int result=UpdateBook(book);
        if (result==1) {
            printf("归还成功！\n");
        }else{
            printf("归还失败！\n");
        }
    }else{
        printf("该本图书未被借出，不需要回归，您可以直接借阅！\n");
        return;
    }
}


