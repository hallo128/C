//
//  FprintfAndFscanfDemo.h
//  FileDemo_C
//
//  Created by apple on 2017/6/25.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef FprintfAndFscanfDemo_h
#define FprintfAndFscanfDemo_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//读取一个文件，写入到另一个文件中
void ReadFileByFscanf(){
    
    FILE * fileIn = fopen("test.txt","r");//读的文件
    FILE * fileOut = fopen("写出的文件.txt","w+");//需要写入的文件
    
    char str[50];
    while (fscanf(fileIn,"%s",str) > 0) {//正确读取
        fprintf(fileOut,"%s\n",str);
    }
    
    //printf("fscanf读出的文件内容:%s\n",str);
    
    fclose(fileIn);
    fclose(fileOut);
}

#endif /* FprintfAndFscanfDemo_h */
