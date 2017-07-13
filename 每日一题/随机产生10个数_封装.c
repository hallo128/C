//
//  main.c
//  C1
//
//  Created by apple on 2017/5/17.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertSort(int);                   //插入排序算法（从小到大），参数：（插入的数）
void Input(int * p_nMin,int * p_nMax);  //输入上下限
void Create(int nMin,int nMax);         //产生10个随机数并排序
void Show();                            //打印数组
void Add(int * p_num);                  //新增数据到数组
void Delete(int index);                 //根据下标删除数组中的数
void Modif(int index,int newNum);       //根据下标找到数组中的数，进行修改为新的数，并排序

const int N = 11;
int nArray[N];
int count=0;//count-当前在数组的下标位置

int main(){

    int nMin,nMax;//下限与上限
    int addNum;
    
    Input(&nMin,&nMax);    //输入上下限
    Create(nMin,nMax);     //产生10个随机数并排序
    Show();   //打印数组
    
    Add(&addNum);         //新增数据到数组
    Show();
    
    printf("\n\n删除下标为3的数字%d:\n",nArray[3]);
    Delete(3);            //根据下标删除数组中的数
    Show();
    
    printf("\n\n将下标为8的数字%d替换为100:\n",nArray[8]);
    Modif(8,100);         //根据下标找到数组中的数，进行修改为新的数，并排序
    Show();
    
    return 0;
}


//根据下标找到数组中的数，进行修改为新的数，并排序
void Modif(int index,int newNum){
    //1-根据下标删除数组中的数（Delete）
    Delete(index);
    //2-插入排序(InsertSort)
    InsertSort(newNum);
}

//根据下标删除数组中的数
void Delete(int index){
    int j;
    if(index > count) return; //当下标超过当前已经存在的下标时，直接跳出
    if (index < count) {              //不是最后一位时，向前挪一位
        for (j = index; j < count; j++) {
            nArray[j] = nArray[j+1];
        }
    }
    count--;//不是/是最后一位时，所占位置都少一位
}


//新增数据到数组
void Add(int * p_num){
    int i,isExit = 1;
    //1-先判断原始数组中是否包括该数
    while (isExit) {  //只要在数组中存在，更改添加的数，并重新再次判断
        printf("\n请输入你想要添加的数：");
        scanf("%d",p_num);
        for (i=0; i<=count; i++) {
            if (*p_num == nArray[i]) {
                isExit = 1;
                printf("你输入的数已经存在，请重新输入一个数！！");
                break;
            }
        }
        if(i == count+1) {break;} //当不在数组中存在时，跳出循环
    }
    //2-对新增数进行插入排序
    InsertSort(*p_num);
}


//打印数组
void Show(){
    int i;
    printf("当前数组有%d个数并排序：\n",count+1);
    for (i=0; i<=count; i++) {
        printf("%d\t",nArray[i]);
    }
}

//插入排序算法
void InsertSort(int num){
    int k,g;
    count++;//每次插入自动增1----------
    for(k = 0;k < count;k++){
        if(num < nArray[k]){
            for (g = count-1; g >= k;g--)  {nArray[g + 1] = nArray[g];}
            nArray[k] = num;
            break;
        }
    }
    if (k == count) {    //最后一位
        nArray[count] = num;
    }
}

 //输入上下限
void Input(int * p_nMin,int * p_nMax){
    printf("请输入下限(要求输入-正整数)：");
    scanf("%d",p_nMin);
    printf("请输入上限(要求输入-正整数)：");
    scanf("%d",p_nMax);
    //1.1-判断：上限-下限是否含有9个整数
    while (*p_nMax-*p_nMin < 9) {
        printf("\n-----------------\n");
        printf("错误提示：\n上下限之间可能不存在10个正整数、上限必须大于下限\n请扩大上限，重新输入上限！！\n");
        printf("-----------------\n");
        printf("请输入上限(要求输入-正整数)：");
        scanf("%d",p_nMax);
    }
}

//产生10个随机数并排序
void Create(int nMin,int nMax){
    int i,j,temp,isExit;  //isExit用于判断产生的随机数是否已经存在
    
    //2-产生随机数；: 查找到插入的位置，将后面的数据向后挪一位
    srand((unsigned)time(NULL)); //随机种子
    count=0;//记录当前下标-当前位置--------
    nArray[0]=rand()%(nMax-nMin+1)+nMin;
    for (i=1; i<10; i++) {
        isExit=0;
        temp=rand()%(nMax-nMin+1)+nMin;   //rand()%100:产生0-99的随机数
        for(j = 0; j < i; j++) {
            if(temp == nArray[j]) {
                isExit = 1;;
                break;
            }
        }
        if (isExit == 0) {              //不存在,保留到数组（3-产生新的数，进行插入排序）
            InsertSort(temp);           //3-插入排序法
        }
        else
        {i--;}                         //存在,重新生成一次(技巧：只需要退回一步i-1)
    }

}
