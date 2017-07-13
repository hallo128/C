//
//  main.c
//  FileDemo_C
//
//  Created by apple on 2017/6/25.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "FgetcAndFputcDemo.h"
#include "FgetsAndFputsDemo.h"
#include "FprintfAndFscanfDemo.h"
#include "FseekAndFtellDemo.h"

int main(int argc, const char * argv[]) {
    
//    WriteFileByFputc();
//    ReadFileByGetc();
    
//    WriteFileByFputs();
//    ReadFileByGets();
    
//    ReadFileByFscanf();
    
    GetFileLength();
    
    //1-打开文件
    //1.1-如果是相对路径，默认在当前工程目录下
    //相对路径查找-点击Products的某个文件，右键“show in finder”
    //FILE * file = fopen("test.txt", "w+");
    //FILE * file = fopen("test.rtf", "r");
    
    //1.2-绝对路径（test.txt/中文测试.txt
    //FILE * file = fopen("/Users/apple/code_tool/C/FileDemo_C/test.txt", "w+");
    

    return 0;
}
