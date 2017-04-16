//
//  main.c
//  自定义函数
//
//  Created by apple on 2017/2/11.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#define PI 3.14

/*
void s_circle();     //计算圆面积
void s_rectangle();  //计算矩形面积
void s_triangle();   //计算三角形面积
int calcSum();      //求1-100之间的偶数和
*/


int main(int argc, const char * argv[]) {
 /*
 三种图形的面积计算公式如下:
 圆:s = PI * r * r;
 矩形:s = width * height;
 三角形:s = width * height / 2;
 使用函数分别实现三种图形的面积计算，打印计算结果
 
 //s_circle();
 //s_rectangle();
 //s_triangle();
 
 printf("1-100之间的偶数和:%d",calcSum());
 */
return 0;
}

/*
void s_circle(){
    double s,r;
    printf("圆的半径：");
    scanf("%lf",&r);
    s = PI * r * r;
    printf("圆的面积：%.2lf\n",s);
}

void s_rectangle(){
    double s,width,height;
    printf("矩形的宽度：");
    scanf("%lf",&width);
    printf("矩形的高度：");
    scanf("%lf",&height);
    s = width * height;
    printf("矩形的面积：%.2lf\n",s);
}

void s_triangle(){
    double s,width,height;
    printf("三角形的宽度：");
    scanf("%lf",&width);
    printf("三角形的高度：");
    scanf("%lf",&height);
    s = width * height / 2;
    printf("三角形的面积：%.2lf\n",s);
}

int calcSum(){
    int i,s=0;
    for(i=0;i<=100;i += 2) s += i;
    return s;
}
*/



