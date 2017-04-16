//
//  Hotel.h
//  酒店
//
//  Created by apple on 2017/2/21.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef Hotel_h
#define Hotel_h

#define Hotel1 872.00    //各家酒店的房费
#define Hotel2 1838.00
#define Hotel3 789.00
#define Hotel4 1658.00
#define Discount 0.95     //折扣率

int menu(void); //菜单函数：显示菜单选项，接受并返回用户输入
int getNight(void); //返回预定的天数
void showPrice(int nights); //根据天数显示最终支付金额

#endif /* Hotel_h */
