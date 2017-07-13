//
//  FgetsAndFputsDemo.h
//  FileDemo_C
//
//  Created by apple on 2017/6/25.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef FgetsAndFputsDemo_h
#define FgetsAndFputsDemo_h
#include <stdio.h>
#include <stdlib.h>

void ReadFileByGets(){
    FILE * file = fopen("test.txt","r");
    //省略判断
    char str[50]; //每次读50个，可以设计为每行的容量
    while (fgets(str,sizeof(str),file) != NULL) {
        printf("%s\n",str);
    }
    fclose(file);
}

void WriteFileByFputs(){
    FILE * file = fopen("test.txt","a+");
    char * str = "这是fputs函数的读入文件操作!";
    int result=fputs(str, file);
    if (result != -1) {
        printf("写入成功!\n");
    }else{
        printf("写入失败!\n");
    }
    fclose(file);
}

#endif /* FgetsAndFputsDemo_h */

