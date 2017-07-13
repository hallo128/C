//
//  FileOpt.c
//  NewBookDemo
//
//  Created by apple on 2017/6/22.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "FileOpt.h"

/**将传入的图书保存到文件中*/
void SaveBook(Book * book){
    //判断传入图书指针是否存在
    if (book == NULL) {
        printf("无法保存一个不存在的文件！\n");
        return;
    }
    
    FILE * file =fopen(BookInfoPath, "a+b");          //以二进制追加的方式打开
    int result=fwrite(book, sizeof(Book), 1, file);   //将1个Book类型的指针的内容，写入到file中
    //如果返回成功就返回()内的1
    //判断是否添加成功
    if (result > 0) {     //
        printf("添加成功\n");
    }else{
        printf("添加失败\n");
    }
    
    fclose(file);
}

/**从文件中获取所有的图书信息*/
Book * GetAllBooks(Book* book,int * bookCount){

    //1、获得文件中一共有多少图书信息
    *bookCount = GetBookCount();
    
    Book * bookList = NULL;
    //2、将图书结构数组填充数据
    if(NULL == book){
        bookList = (Book *)malloc(sizeof(Book) * (*bookCount));//构建图书数组
    }
    
    FILE * file =fopen(BookInfoPath, "r");
    int result=fread(bookList, sizeof(Book), *bookCount, file);
    //判断是否读取成功
    if (result == *bookCount) {
        printf("读取成功\n");
    }else{
        printf("读取失败\n");
    }
    fclose(file);
    //3、返回图书结构数组
    book = bookList;
    return book;
}

/**获得文件中所包含的图书信息总数*/
int GetBookCount(){
    FILE * file =fopen(BookInfoPath, "r");
    if (file == NULL) {
        return 0;      // 文件不存在，返回0本书
    }
    
    fseek(file, 0L, SEEK_END); // 将文件指针移到文件末尾
    int bookCount = ftell(file) / sizeof(Book); //当前一共的字节数/每个图书结构的字节数
    fclose(file);
    return bookCount;
}
