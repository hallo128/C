//
//  Trade.c
//  GameTradeDemo
//
//  Created by apple on 2017/5/31.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "Trade.h"



//1.初始化数据
void Init(){
    /*初始化商品*/
    static Prop propArray[]={              //static整个应用程序都不会被销毁内存
        {1,"双倍经验卡",3000,10,"双击666"},
        {2,"腐烂的道袍",5000,8,"魔法"},
        {3,"生锈的铁剑",8000,10,"新手专用"},
        {4,"无极道袍",13000,5,"刀枪不入水火不侵"},
        {5,"直升1级丹药",83000,10,"快速升级"}
    };
    propsCount = sizeof(propArray)/sizeof(Prop);
    props = propArray;      //设定指针指向
    /*初始化玩家*/
    static Player playerArray[]={
        {1,"超级毛毛虫","123456",.gold=50000,.bag.max=8},
        {2,"奥特曼","123456",.gold=150000,.bag.max=8},
        {3,"元始天尊","123456",.gold=500000,.bag.max=8},
        {4,"新河","123456",.gold=1150000,.bag.max=8}
    };
    playerCount=4;
    players = playerArray;
}




/*打印函数*/
void ShowProps(){
    int i;
    if (props == NULL) return;
    printf("%-5s%-14s%-7s\t库存\t商品描述\n","编号","名称","单价");
    for (i=0; i<propsCount; i++) {
        printf("%-5d%-14s%-7.0lf\t%d\t%s\n",
               (props+i)->id,(props+i)->name,(props+i)->price,(props+i)->stock,(props+i)->desc);
    }
}

void ShowPlayers(){
    int i,j;
    if (players == NULL) return;
    printf("编号\t%-14s金币\n","名称");
    for (i=0; i<playerCount; i++) {
        printf("%d\t%-14s%.0lf\n",
               players[i].id,players[i].name,players[i].gold);
        for (j=0; j<players[i].bag.count; j++) {
            printf("\t%s\t%d\t",players[i].bag.props[j].name,players[i].bag.props[j].stock);
        }
       printf("\n");
    }
}

/**
 *交易函数
 *参数1：参与交易的玩家指针，方便直接修改玩家的金额
 *参数2：玩家所购买的商品id
 */
void Trade(Player * player,int propId){
    int i;
    Prop * tradeProp = NULL;//需要购买的商品指针
    //1.1查找该商品
    for (i=0; i<propsCount; i++) {
        if (props[i].id == propId) {
            tradeProp = props+i;
            break;
        }
    }
    //判断：商品的库存；玩家的余额；玩家的背包空间
    //2.1-商品的库存
    if (tradeProp ->stock <= 0) {
        printf("地主家都没有余粮，商店都被买空了！！");
        return;
    }
    //2.2-玩家的余额
    if (player->gold <= 0) {
        printf("没有钱，交易失败！！");
        return;
    }
    //2.3-玩家的背包空间
    if (player->bag.count >= player->bag.max  && player->bag.count != 0) {
        printf("背包已满，交易失败！！");
        return;
    }
    //满足交易条件，执行义务操作
    //1-库存-1
    tradeProp->stock--;
    //2-玩家金币-单价
    player->gold -= tradeProp->price;
    //3-玩家背包道具增加
    //判断玩家背包中是否有该商品
    //没有该商品，就将该商品添加到背包中
    //有该商品，就数量+1
    for (i=0; i< player->bag.count; i++) {
        //若购买商品的id 与 背包中某个商品的id相同
        if (propId == player->bag.props[i].id) {
            player->bag.props[i].stock++;
            break;
        }
    }
    //没有该商品，就将该商品添加到背包中
    if (i == player->bag.count) {
        //向背包中创建一个商品(复制一份要交易的商品的信息到背包中)
        int newIndex = player->bag.count;
        player->bag.props[newIndex].id = tradeProp->id;
        player->bag.props[newIndex].price = tradeProp->price;
        player->bag.props[newIndex].stock = 1;
        strcpy(player->bag.props[newIndex].name, tradeProp->name);
        strcpy(player->bag.props[newIndex].desc, tradeProp->desc);
        player->bag.count ++;
        
    }
    
}




