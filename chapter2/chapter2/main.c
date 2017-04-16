//
//  main.c
//  chapter2
//
//  Created by apple on 2017/2/10.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {

/*    // 常用内置函数
    printf("%d\n",isupper('a'));
    printf("%d\n",islower('a'));
    printf("%d\n",isalpha('a'));
    printf("%d\n",isdigit('9')); //数字一定要带''
    //转换大小写
    printf("%c",toupper('a'));
*/
    
    //思考题：如何将数字转换为中文大写 1234-壹仟贰佰叁拾肆元整
    int j,pf,temp,stop_n=0,n=0;
    printf("\n请输入小于4位数字：");
    scanf("%d",&pf);
    
    //n计算有几位数
    temp=pf;
    do{
        n++;
        temp = temp / 10;
    }while (temp != 0);

    //将数字由低位向高位，从s[0]开始储存
    int s[n];
    for (j=0,temp=pf; j<n; j++) {
        s[j] = temp % 10;
        temp = temp / 10;
    }
    
    //将数字转换为中文
    char c[13][4]={"零","壹","贰","叁","肆","伍","陆","柒","扒","玖","拾","佰","仟"};

    
    
    //每个数字重新排序输出
    printf("\n中文数字表示：");
    //如果末尾有0重新调整读法
    j=0;
    while (s[j]==0){
        stop_n += 1;
        j++;
    }
    
    for (j=n-1,temp=pf; j>=stop_n; j--) {
        //printf("%s",c[s[j]]);
        
        //出现连续的零
        if (j<n-1 & s[j]==0) {
            if (s[j] != s[j+1]) {
                printf("%s",c[s[j]]);
            }
        }
        else
        {printf("%s",c[s[j]]);}
        
        if (s[j] != 0) {
            switch (j) {
                case 3:
                    printf("%s",c[12]);
                    break;
                case 2:
                    printf("%s",c[11]);
                    break;
                case 1:
                    printf("%s",c[10]);
                    break;
                default:
                    break;
            }
        }
    }
    printf("元整");

/*
    //打印所有ASCI表示的内容
    int i;
    for (i=0; i<127; i++) {
        printf("%c\t",i);
    }
*/
    return 0;
}
