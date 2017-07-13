//
//  FgetcAndFputcDemo.h
//  FileDemo_C
//
//  Created by apple on 2017/6/25.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef FgetcAndFputcDemo_h
#define FgetcAndFputcDemo_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**用fgetc()读取文件*/
void ReadFileByGetc(){
    //1、打开文件
    FILE * file = fopen("test.txt","r");
    char ch;//临时变量
    //2、使用固定的代码结构读取文件（循环）
    while ((ch = fgetc(file))!= EOF) {
        putchar(ch); //每读一个字符就打印出来
    }
    //3、打印读取结果
    //4、关闭文件
    fclose(file);
}

void WriteFileByFputc(){
    //判断文件是否存在,成功还是失败?
    FILE * file1=fopen("test12.txt", "r");
    if (file1 == NULL) { //等价于!file  文件打开失败
        printf("文件打开失败，请检查文件路径！");
        //fputc("文件打开失败，请检查文件路径！", stderr);//写入标准错误流中
        exit(1);//等价于exit(EXIT_FAILURE);/
    }
    
    FILE * file = fopen("test.txt","a+");
    char * str = "这是fputc函数的读入文件操作!";
    int i;
    for (i=0; i<strlen(str); i++) {
        fputc(str[i], file);
    }
    
    fclose(file1);
    fclose(file);
}


#endif /* FgetcAndFputcDemo_h */
