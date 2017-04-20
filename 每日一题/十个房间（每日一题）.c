//
//  main.c
//  每日一题
//
//  Created by apple on 2017/4/17.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int select[9];//选择到的教室数
    int post,num,i,j,count;     //post-添加到选择函数的位置;num-循环计数;i-增加循次数;count-不在增加选择数时，再次循环的次数
    
    //初试化
    post=0;
    num=1;
    i=1;
    select[post]=num;
    post++;
    count=0;
    
    do{
        //pre_num=num;
        num=(num+i+1); //循环计数
        i++;  //循环计数
        //将计数转换为1-10的房间数
        if (num % 10 ==0)
            num=10;
        else
            num=num % 10;
        //-----判断是否添加到select中
        int isexist=0;     //先判断是否已经存在于select中
        for(j=0;j<post;j++){
            if (select[j]==num) {
                isexist=1;count++;break;
            }
        }
        if (isexist==0) {     //对不存在的数进行添加
            select[post]=num;
            post++;count=0;   //重置count
        }
    }while (post<9 && count<10);//最多9个循环数。重复循环时，如果10轮计算都未进行更新，则跳出

    printf("从未被选到的房间数：\n");
    for (i=1; i<=10;i++) {
        int isexist=0;
        for (j=0; j<post; j++) {
            if (i==select[j]) {isexist=1;break;}
        }
        if (isexist==0) printf("%d\n",i);
    }
    
    return 0;
}
