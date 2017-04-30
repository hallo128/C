//
//  Hero.c
//  game1
//
//  Created by apple on 2017/4/27.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "Hero.h"

Hero heros[5];
//设定一个职业数组,让用户进行选择
Job jobs[]={
    {1,"法师","bilibii专家"},
    {2,"刺客","千年杀"},
    {3,"战士","肉特别厚"},
    {4,"机甲师","靠机甲吃饭"},
    {5,"射手","指哪打哪"}
};
/*
 int id;
 char * name; //英雄名称
 char sex;   //英雄性别
 Job job;    //英雄职业
 double hp;  //英雄生命值
 double speed;//英雄速度
 Ability ability;//英雄特殊能力
 PubTime pubTime;//英雄上线时间
 */

//用来输入英雄的值
void InputHero(){
    //动态录入
    int i,j,jobChoice;
    for (i=0; i<1; i++) { //5
        printf("请输入第%d位英雄的信息：\n",i+1);
        heros[i].id = i+1;
        printf("名称:");
        heros[i].name=(char *)malloc(50);
        scanf("%s",heros[i].name);
        printf("性别:");
        scanf("%c",&heros[i].sex);
        fflush(stdin);                  //录入字符后记得清空缓冲区
        //设定一个职业数组,让用户进行选择
        for (j=0; j<5; j++) {
            printf("%d.%s\n",j+1,jobs[j].name);
        }
        printf("请选择职业（1-5之间的整数）:");
        scanf("%d",&jobChoice);
        heros[i].job=jobs[jobChoice-1];
        printf("%s\的当前职业：[%s]\n",heros[i].name,heros[i].job.name);
        
    }
    
}

//用来输出英雄的值
void ShowHero(){
    
}
