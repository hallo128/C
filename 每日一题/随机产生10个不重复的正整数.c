#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    
    int i,j,temp,nMin,nMax,isExit;    //isExit用于判断产生的随机数是否已经存在
    int nArray[10];
    
    //1-输入
    printf("请输入下限(要求输入-正整数)：");
    scanf("%d",&nMin);
    printf("请输入上限(要求输入-正整数)：");
    scanf("%d",&nMax);
    //1.1-判断：上限-下限是否含有9个整数
    while (nMax-nMin < 9) {
        printf("\n-----------------\n");
        printf("错误提示：\n上下限之间可能不存在10个正整数、上限必须大于下限\n请扩大上限，重新输入上限！！\n");
        printf("-----------------\n");
        printf("请输入上限(要求输入-正整数)：");
        scanf("%d",&nMax);
    }
    
    //2-产生随机数
    srand((unsigned)time(NULL)); //随机种子
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
        if (isExit == 0) {               //不存在,保留到数组
            nArray[i] = temp;
        }
        else
          {i--;}                         //存在,重新生成一次(技巧：只需要退回一步i-1)
    }
    
    //3-打印随机数
    printf("\n在[%d,%d]内的10个不重复随机数：\n",nMin,nMax);
    for (i=0; i<10; i++) {
        printf("%d\t",nArray[i]);
    }

    return 0;
}
