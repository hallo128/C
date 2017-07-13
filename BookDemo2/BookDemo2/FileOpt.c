//
//  FileOpt.c
//  BookDemo2
//
//  Created by apple on 2017/7/5.
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
Book * GetAllBooks(Book * book,int * bookCount){
    //1、获得文件中一共有多少图书信息
    *bookCount = GetBookCount();
    if (*bookCount == 0) {
        printf("没有任何图书请添加后再试！\n");
        return NULL;
    }
    //2、将图书结构数组填充数据
    if( NULL == book){
        book = (Book *)malloc(sizeof(Book) * (*bookCount));//构建图书数组
    }

    FILE * file =fopen(BookInfoPath, "r");
    int result=fread(book, sizeof(Book), (*bookCount), file);
    //判断是否读取成功
//    if (result == *bookCount) {
//        printf("读取成功\n");
//    }else{
//        printf("读取失败\n");
//    }
    fclose(file);
    //3、返回图书结构数组
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


/**打印文件中的图书*/
void printAllBooks(){
    int bookCount = -1;//图书总数
    int i;
    Book * bookArray = NULL;
    bookArray = GetAllBooks(NULL, &bookCount);
    //GetAllBooks(bookArray, &bookCount);
    if (bookArray == NULL) {
        printf("文件中暂时没有图书！");
        return;
    }
    printf("\n所有图书信息如下：\n");
    printf("--------------------------------------------------------\n");
    printf("%-15s%-15s%-15s%-15s%-15s%-15s\n",
           "内部编号","图书名称","出版号","借阅状态","图书单价","借出时间");
    printf("--------------------------------------------------------\n");
    for (i=0; i<bookCount; i++) {
        printf("%-10d%-15s%-11s%-12s%-9.2lf",
               bookArray[i].id,
               bookArray[i].name,
               bookArray[i].isbn,
               bookArray[i].status == CAN ? "可借" :"不可借",
               bookArray[i].price );
        //打印时间
        if (bookArray[i].borrowTime == 0) {//时间为空
            printf("---\n");
        }else{
            struct tm * pTime = localtime(&bookArray[i].borrowTime);
            printf("%d-%d-%d %2d:%2d:%2d\n",
                   pTime->tm_year+1900,
                   pTime->tm_mon+1,
                   pTime->tm_mday,
                   pTime->tm_hour,
                   pTime->tm_min,
                   pTime->tm_sec);
        }
        
    }
    printf("--------------------------------------------------------\n");
    
}


/** 根据图书的id查找对应的图书信息*/
Book * GetBookById(int id){
    //获得文件中所有的图书数量
    int bookCount = GetBookCount();
    if (bookCount == 0) return NULL;
    FILE * file = fopen(BookInfoPath, "r");
    int i;
    for (i=0; i<bookCount; i++) {
        Book * tempBook = (Book * )malloc(sizeof(Book)); //先分配一个临时空间
        fread(tempBook, sizeof(Book), 1, file);
        if (tempBook->id == id) {
            fclose(file);
            return tempBook;
        }
        free(tempBook); //每次销毁临时变量
    }
    fclose(file);
    return NULL;//遍历了当前文件中的所有图书，仍然没有找到，返回NULL（如果不是void函数，最后一行必须有返回值）
}


/**(删除) 根据图书的id删除对应的图书信息*/
int DeleteBookById(int id){
    //删除的思路
    //1、取出所有的图书（数组）
    //2、在图书数组中进行删除操作
    //3、将数组中的所有图书以覆盖的方式写回到文件中
    int i,bookCount = -1, delIndex = -1;
    Book * bookArray = NULL;
    Book * tempBook = NULL; //临时变量
    
    bookArray=GetAllBooks(NULL, &bookCount);//1、取出所有的图书（数组）
    
    for (i=0; i<bookCount; i++) {
        if (id == bookArray[i].id) {
            delIndex = i;           //找到要删除的下标
            break;
        }
    }
    if (delIndex == -1)  return 0; //没有，删除失败，跳出
    
    //2、进行数组的删除操作
    if(delIndex == 0){
        //要删除的是第一个（第一个为数组名，若改变，则不再是原来的数组）
        tempBook = (Book *)malloc(sizeof(Book) * (bookCount-1));//构建存放后面的临时数组
        for (i=0; i<bookCount-1; i++) {
            tempBook[i] = bookArray[i+1];
        }
    }else if (delIndex == bookCount){
        //要删除的是最后一个(将长度-1，即可)
    }else{
        //要删除的是中间位置(先交换，再将长度-1)
        for (i = delIndex; i< bookCount-1; i++) {
            bookArray[i] = bookArray[i+1]; //后一个赋值给前一个（除了第一个和最后一个，都适用）
        }
    }
    bookCount--;//不管位置如何，最后长度都-1
    
    //3、将数组中的所有图书以覆盖的方式写回到文件中
    //进行数组复制(除第一个元素外进行-复制前面的元素到临时数组中)
    if(tempBook==NULL) {
        tempBook = (Book *)malloc(sizeof(Book) * bookCount);//构建存放后面的临时数组
        memcpy(tempBook,bookArray,bookCount*sizeof(Book));
    }
    //写入
    FILE * file = fopen(BookInfoPath, "w+b");
    int result = fwrite(tempBook, sizeof(Book), bookCount, file);
    //判断是否删除成功
    if (result == bookCount) {
        printf("删除成功\n");
    }else{
        printf("删除失败\n");
    }
    fclose(file);

    return result;//只要不在return 0处跳出，就是删除成功，返回1
}



int UpdateBook(Book * book){
    int bookCount = GetBookCount();
    //如果没有传入需要更新的书数组指针，或者当前文件中的图书数量为0，则更新失败
    if (book == NULL || bookCount ==0) return 0;
    
    int i;
    FILE * file=fopen(BookInfoPath, "r+b"); //----只读
    Book * tempBook = (Book *)malloc(sizeof(Book));//一本书
    for (i=0; i< bookCount; i++) {
        fseek(file, i*sizeof(Book), SEEK_SET); //---添加代码：保证每次读入tempBook时，都能从下个位置继续
        fread(tempBook, sizeof(Book), 1, file);
        if (book->id == tempBook->id) { //找到了要更新的这本书（按id进行查找）
            //将文件指针置于当前书籍的开始处，以便覆盖
            fseek(file, i*sizeof(Book), SEEK_SET);  //---再次重置位置
            fwrite(book, sizeof(Book), 1, file);
            break;
        }
    }
    free(tempBook);
    fclose(file);
    return i == bookCount ? 0 : 1; //如果没有找到返回0，找到返回1
}

/**获得文件中最后一本书的id+1*/
int GetNewBookId(){
    int bookCount = GetBookCount();
    if (bookCount == 0) return 1;
    FILE * file =fopen(BookInfoPath, "r");
    //移动文件指针,到最后一本书的开头（方便直接读最后一本书）
    fseek(file, (bookCount-1) * sizeof(Book), SEEK_SET);
    Book * lastBook = (Book *)malloc(sizeof(Book));
    fread(lastBook, sizeof(Book), 1, file);
    fclose(file);
    
    int newId = lastBook->id +1;
    free(lastBook);
    
    return newId;
}





