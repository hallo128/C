//
//  main.c
//  GameTradeDemo
//
//  Created by apple on 2017/5/31.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "Trade.h"



int main(int argc, const char * argv[]) {
    //1.初始化数据
    Init();
    printf("\n------交易前-------------\n");
    //2.打印这些初始化数据
    ShowProps();
    ShowPlayers();
    
    Trade(&players[0], 3); //进行交易
    printf("\n------交易后-------------\n");
    ShowProps();
    ShowPlayers();
    
    return 0;
}
