//
//  main.c
//  冒泡排序
//
//  Created by apple on 2017/2/18.
//  Copyright © 2017年 apple. All rights reserved.
//书写一个小型的学生成绩管理系统

#include <stdio.h>
#define N 5    //确定了数组的个数

void input(double[]); //录入函数
void sort(double[]); //排序函数
void show(double[]); //显示函数
int find(double *,double);        //查找函数(向传入的数组查找num,如果存在返回下标，不存在返回-1)

int main(int argc, const char * argv[]) {
    //量数组大小
    double test[]={3,6,7,8,0};
    printf("数组元素的个数为：%d\n", (sizeof(test)/sizeof(test[0])));
    
    
    double scores[N];
    double num;
    //1、录入
    input(scores);
/*
    printf("排序前");
    show(scores);
    //排序
    sort(scores);
    printf("排序后");
    show(scores);
*/
    //查找
    printf("请输入要在数组中查找的数字：");
    scanf("%lf",&num);
    if (find(scores, num) == -1) {
        printf("数组中不存在该数");
    }
    else
        printf("该数在数组中的下标：%d",find(scores, num));

}

//录入函数
void input(double scores[]){
    int i;
    for (i=0; i<N; i++) {
        printf("socres里的第%d个元素：",i+1);
        scanf("%lf",&scores[i]);
    }
}

//冒泡排序(从大到小)
void sort(double scores[]){
    int i,k;
    double temp;
    do{
        k=0;
        for (i=0; i<N; i++) {
            if (scores[i]<scores[i+1]) {
                temp=scores[i];
                scores[i]=scores[i+1];
                scores[i+1]=temp;
                k++;
            }
        }
    }while (k != 0);
    
}

//查找函数
int find(double * scores,double num){
    int i,num_index = -1;
    for (i=0; i<N; i++) {
        if (scores[i] == num) {
            num_index=i;
            break;
        }
    }
    return num_index;
}


//显示函数
void show(double scores[]){
    int i;
    printf("\n***************************************\n");
    //printf("语文\t数学\t英语\t物理\t化学\n");
    for (i=0; i<N; i++) {
        printf("%.2lf\t",scores[i]);
    }
    printf("\n***************************************\n");
}
