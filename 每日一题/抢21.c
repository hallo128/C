//
//  main.c
//  抢21
//
//  Created by apple on 2017/4/21.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int compter_select(int use);   //电脑选择赢的数
void compter_print(int computer_num); //电脑输出
int use_max(int use_num[]);      //判断用户输入数的个数

int use_max_num;

int main(int argc, const char * argv[]) {
    //抢21游戏，第一个人是键盘输入者，第二个人是电脑（第二个人必胜）
    //电脑一定要位于(3,6,9,12,15,18,21)必胜
    
    int use_num[2];
    int computer_num,nextnum=1;

    do{
        use_num[1]=1000;
        printf("请您输入数字(%d或%d,%d)：\n",nextnum,nextnum,nextnum+1);
        scanf("%d,%d",&use_num[0],&use_num[1]);
        use_max_num=use_max(use_num);
        computer_num=compter_select(use_max_num);
        compter_print(computer_num);
        nextnum=computer_num+1;
    }while (use_max(use_num)<21 && computer_num<21);
    
    if (computer_num==21)
        printf("你输掉了21点，电脑赢了!\n");
    else
        printf("你赢了21点，电脑输了!\n");
    return 0;
}

void compter_print(int computer_num){
    if (computer_num-use_max_num==2)
        printf("电脑输入数字：%d,%d\n",computer_num-1,computer_num);
    else
        printf("电脑输入数字：%d\n",computer_num);

}

int use_max(int use_num[]){
    int use;
    use=use_num[1];
    if (use_num[1]>100) {
        use=use_num[0];
    }
    return use;
}

int compter_select(int use){
    int i,num;
    int post[]={3,6,9,12,15,18,21};
    for (i=0;i<7;i++) {
        if (use+1==post[i]) {
            num=use +1;break;
        }
        if (use+2==post[i]) {
            num=use+2;break;
        }
    }
    return num;
}
