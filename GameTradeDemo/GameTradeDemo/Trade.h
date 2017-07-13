//
//  Trade.h
//  GameTradeDemo
//
//  Created by apple on 2017/5/31.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef Trade_h
#define Trade_h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*定义结构: 
 商品,背包，玩家
*/
 
/*商品结构*/
typedef struct _prop{
    int id;         //编号
    char name[50];  //名称
    double price;   //价格
    int stock;      //商店-库存量（如果在背包中，是该商品的叠加数量）
    char desc[200]; //描述
}Prop;

/*背包结构*/
typedef struct _bag{
    int palyerId;   //玩家的编号
    int count;      //当前背包，道具的数量
    int max;        //背包中插槽总数
    Prop props[8];     //背包中，道具数组
}Bag;

/*玩家结构*/
typedef struct _player{
    int id; //玩家编号
    char name[50];  //用户名
    char pass[50];  //密码
    Bag bag;        //玩家背包
    double gold;    //玩家金币-银币-铜币
    double sysee;   //元宝数量
}Player;

//定义全局变量
Prop * props;
Player * players;
int propsCount=0;
int playerCount=0;


/*函数：初始化，打印*/
/*初始化函数*/
void Init();
void ShowProps();
void ShowPlayers();
/**
 *交易函数
 *参数1：参与交易的玩家指针，方便直接修改玩家的金额
 *参数2：玩家所购买的商品id
 */
void Trade(Player * player,int propId);


#endif /* Trade_h */
