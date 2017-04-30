#include <stdio.h>
#include <stdlib.h>
#include <string.h> //字符串操作
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")
#define MAX 6//最大妃子数量

int main()
{
    int i,k,temp,day,exit_d=0;
    int count=5;            //当前未打入冷宫的嫔妃个数
    //使用字符数组表示字符串
    char emperorName[50];   //皇帝的名号
    int choice;             //皇帝的选择1-4
    char choiceName[20];    //选择的姓名
    int choiceLocal= -1;    //选择的索引
    char names[MAX][20]={"貂蝉","杨玉环","西施","如花","不知火舞"};    //嫔妃姓名数组
    char levelNames[5][10]={"贵人","嫔妃","贵妃","皇贵妃","皇后"};     //嫔妃级别数组
    int levels[MAX]={1,2,0,0,0,-1};                                     //每个妃子对应的当前级别
    int loves[MAX]={100,100,100,100,100,-1};                            //每个妃子对应当前好感度，初始都为100


    printf("请输入当前登基的皇帝名号：");
    scanf("%s",emperorName);    //录入字符串时，不需要&符号

    //printf("****************************\n");

    for(day=0;day<10;day++){
        PlaySound(TEXT("sounds\\背景音乐.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        printf("\n皇帝[%s]上朝第[%d]天\n有事上奏，无事退朝！\n",emperorName,day+1);
        printf("****************************\n");
        printf("当前嫔妃的状态：\n");
        printf("%-10s级别\t好感度\n","姓名");
        for(i=0;i<count;i++){
                printf("%-10s%s\t%d\n",names[i],levelNames[(levels[i])],loves[i]);
        }

        printf("\n1、皇帝下旨选妃！\t（增加）\n");
        printf("2、翻牌宠幸\t\t（修改状态）\n");
        printf("3、打入冷宫！\t\t（删除）\n");
        printf("4、朕的爱妃呢？\t\t（查找）\n");

        printf("陛下请选择：");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1: //皇帝下旨选妃：\t\t(增加功能)
            //1.增加数组元素(names,levels)
            //2.增加前需要判断数组有没有空间
            PlaySound(TEXT("sounds\\选妃.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            if(count >= MAX)
            {  printf("陛下，您的后宫已满！(添加失败)\n");}
            else
            {
                printf("陛下，请输入娘娘的名讳：");
                scanf("%s",names[count]);
                levels[count]=0;
                loves[count]=100;
                printf("欢迎%s娘娘入宫！\n",names[count]);
                //其他娘娘好感度-10
                for(i=0;i<count;i++){
                    loves[i] -= 10;
                }
                count++;
            }
            break;
        case 2: //2、翻牌宠幸：\t\t(修改状态功能)\n
            //1.找到该妃子的位置
            //2.增加该妃子的级别和好感度，降低其他妃子的级别和好感度
            PlaySound(TEXT("sounds\\翻牌.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            printf("陛下，请输入今天要翻牌娘娘的名讳：");
            scanf("%s",choiceName);
            //1（字符串查找strcmp,需要引入<string.h>）
            //strcmp(choiceName,"abc")   0-2个字符串相等；1-前一个大于后一个；-1：后一个大于前一个
            for(i=0;i<count;i++){
                if(strcmp(choiceName,names[i])==0)
                    {choiceLocal=i;
                    levels[i] = (levels[i] < 4) ? (levels[i] += 1) : 4;
                    loves[i] += 10;
                    }
                else
                {
                    loves[i] -= 10;
                }
            }
            //2查找失败
            if(choiceLocal == -1) printf("陛下，宫中没有这位娘娘！想必陛下记错了！(查找失败)\n");
            break;
        case 3: //3、打入冷宫！\t\t(删除功能)\n
            //1. 查找姓名与位置
            //2. 后一个交换向前
            //3. 删除总量1，最后-1
            //4. 修改其他妃子好感度+10
            PlaySound(TEXT("sounds\\冷宫.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            printf("陛下，将哪位娘娘打入冷宫：");
            scanf("%s",choiceName);
        //1
            for(i=0;i<count;i++){
                if(strcmp(choiceName,names[i]) == 0) {choiceLocal=i;break;}
            }
            //2
            if(choiceLocal == -1)
                printf("虚惊一场，宫中尚无此女子，想必陛下记错了！(查找失败)\n");
            else
            {
                for(i=choiceLocal;i<count-1;i++)
                {
                //names[i]=names[i+1];  因为是字符串，C语言不支持数组的直接赋值
                //使用strcpy函数实现数组的赋值
                    strcpy(names[i],names[i+1]);
                    loves[i]=loves[i+1];
                    levels[i]=levels[i+1];
                }
                count--;
            }
        //4 现有妃子好感度都+10
            for(i=0;i<count;i++) loves[i] += 10;

            break;
        case 4://4、单独召见爱妃去小树林做纯洁的事。
            //1. 查找
            //2. 增加该人好感度
            PlaySound(TEXT("sounds\\一笑倾城.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            printf("陛下，召见哪位娘娘去小树林做纯洁的事：");
            scanf("%s",choiceName);
        //1
            for(i=0;i<count;i++){
                if(strcmp(choiceName,names[i]) == 0) {choiceLocal=i;loves[i] += 10;break;}
            }
        //2
            if(choiceLocal == -1)
                printf("陛下，宫中没有这位娘娘，想必陛下记错了！\n查找失败\n");

            break;
        default:
            printf("君无戏言，陛下请再次确认！");
        }

    //最后打印所有妃子状态前，以级别进行排序，使用冒泡排序
        do{ k=0;
            for(i=0;i<count-1;i++){
                if(levels[i]<levels[i+1])
                {temp=levels[i];levels[i]=levels[i+1];levels[i+1]=temp;
                temp=loves[i];loves[i]=loves[i+1];loves[i+1]=temp;
             //注意字符串交换
                strcpy(choiceName,names[i]);
                strcpy(names[i],names[i+1]);
                strcpy(names[i+1],choiceName);
                k += 1;}
            }
        }while(k != 0);
        printf("\n");
        printf("\n");

        //查看各个嫔妃的好感度如果低于50，则推出游戏
        for(i=0;i<count;i++){
                if(loves[i] <= 50) {exit_d=1;break;}
        }
        if(exit_d==1) break;

    }
//------------------------------------------

    printf("\n****************************\n");
    if(day==10)
        printf("陛下在位期间歌舞升平！\n");
    else
        printf("皇帝[%s]一共上朝[%d]天，治理太过残暴，被推翻！\n",emperorName,day+1);




    //printf("****************************\n");


/*
    printf("****************************\n");
    printf("当前嫔妃的状态：\n");
    printf("%-10s级别\t好感度\n","姓名");
    for(i=0;i<count;i++){
        printf("%-10s%s\t%d\n",names[i],levelNames[(levels[i])],loves[i]);
    }
    printf("****************************\n");
*/
    return 0;
}
