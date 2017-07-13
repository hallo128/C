//
//  Game.h
//  MyWorldDemo
//
//  Created by apple on 2017/6/4.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef Game_h
#define Game_h
/**
 * 文件名：Game.h
 * 描述：用来定义游戏的一些核心结构和函数
 * 版本：1.0
 */

#include <stdio.h>
#include <string.h>
//#include <windows.h>

/******游戏的结构类型定义*********/
//玩家、地图、装备、怪物

/*游戏地图结构*/
typedef struct _map{
    int id;         //地图编号
    char name[50];  //地图名称
    int minLevel;   //玩家进入的最小等级
    //坐标结构
    //COORD coord;    //地图坐标（x,y）     windows默认的坐标结构--------------#include <windows.h>
    char desc[500]; //地图介绍
}Map;



/*游戏道具类型枚举 - 武器、防具、消耗品、卡片、碎片*/
typedef enum _proptype{
   Weapon,Armor,Con,Card,Frag
}PropType;

/*游戏道具*/
typedef struct _prop{
    int id;//道具编号
    char name[50];//道具名称
    int level;//道具级别
    int stock;//道具商店库存或背包中的叠加数
    double price; //道具的价格
    PropType type;//道具类型
    union{  //联合：多选1
        int minAttack;  //武器对应攻击力
        int minDefence; //防具对应防御力
        int minPower;   //消耗品对应增加的能量值
    };
    union{  //联合：多选1
        int maxAttack;  //武器对应攻击力
        int maxDefence; //防具对应防御力
        int maxPower;   //消耗品对应增加的能量值
    };
    char desc[200];//道具的功能描述
}Prop;

void Init();//初始化函数
void Show();//显示数据


#endif /* Game_h */
