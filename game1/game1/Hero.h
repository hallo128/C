//
//  Hero.h
//  game1
//
//  Created by apple on 2017/4/27.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef Hero_h
#define Hero_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//结构体：英雄、职业、英雄能力、时间
//职业
typedef struct _job{
    int id;
    char * name; //职业名称
    char * desc;  //事业描述
} Job;                           //整个结构体的别名为Job等价于 struct _job
//能力/技能
typedef struct _ability{
    int id;
    char * name; //特殊能力名称
    char * intro;  //特殊能力说明
} Ability;
//时间
typedef struct _pubTime{
    int year;
    int mouth;
    int day;
}PubTime;
//英雄
typedef struct _hero{
    int id;
    char * name; //英雄名称
    char sex;   //英雄性别
    Job job;    //英雄职业
    double hp;  //英雄生命值
    double speed;//英雄速度
    Ability ability;//英雄特殊能力
    PubTime pubTime;//英雄上线时间
}Hero;

/*
 *定义函数
 */
//用来输入英雄的值
void InputHero();

//用来输出英雄的值
void ShowHero();

#endif /* Hero_h */
