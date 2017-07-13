//
//  FseekAndFtellDemo.h
//  FileDemo_C
//
//  Created by apple on 2017/6/25.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef FseekAndFtellDemo_h
#define FseekAndFtellDemo_h
#include <stdio.h>
#include <stdlib.h>

/**测量某个文件的长度/大小*/
void GetFileLength(){
    char * filePath="/Users/apple/Desktop/老九君课堂/补充C语言/老九学堂C\&C++补充课之文件操作IO_直播版.pdf";

    FILE * file = fopen(filePath,"r");  //二进制文件改为"rb"
    fseek(file,0L,SEEK_END);//把文件指针移动到文件的末尾
    long fileLength=ftell(file); //返回当前的文件指针偏移量（单位：字节）
    rewind(file); //重置文件指针到开头，等价于fseek(file,0L,SEEK_SET);
    
    printf("文件大小：\n%ld字节\n%ldkb(千字节)\n%.2lfMb(兆字节)\n",fileLength,fileLength/1024,fileLength/1024/1024.0);
    
    fclose(file);
}

#endif /* FseekAndFtellDemo_h */
