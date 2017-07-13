//
//  main.c
//  MyPointerDemo
//
//  Created by apple on 2017/5/28.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
/*
 typedef union{
 double magic;
 int anger;
 char *stars;
 }Power;
 */

struct monster{
    int id;
    char name[25];
    //指向下一个元素的指针
    struct monster * pNext;
};
//定义新的类型：Monster
typedef struct monster Monster;
//链表中包含的元素总数
int monsterCount = 0;
/** 创建链表，返回链表首元素的指针 */
Monster * CreateList();
/** 根据删除下标，删除链表中对应的元素 */
void DeleteByIndex(Monster * pHead, int delIndex); //修改前的局限：不能删除尾元素和首元素；修改后的局限：不能删除首元素
/** 根据传入的链表首元素指针，打印链表中的所有元素信息 */
void OutputMonsters(Monster * pHead);


//作业：自行添加insert
//---------------------------insert
/** 链表的最后插入元素 */
void TailInsert(Monster * pHead);
/** 链表的开头插入元素（不能直接对原有链表进行操作，只能重新返回一个新的链表）*/
Monster * HeadInsert(Monster * pHead);
/** 根据插入下标1、2、3···，链表的中间位置插入元素（局限：不能在开头插入。其他位置都可以插入）*/
void MidInsert(Monster * pHead, int insertIndex);

//---------------------------


int main()
{
    
    //Monster * newMonster;   //新的链表对象
    //调用方法创建链表结构对象
    printf("请创建链表结构对象\n");
    Monster * monsterHead = CreateList();
    //打印链表
    OutputMonsters(monsterHead);
    
    //删除后，打印链表
    printf("\n************************\n");
    DeleteByIndex(monsterHead, 2);
    OutputMonsters(monsterHead);
    /*
    //末尾插入后，打印链表
    printf("\n************************\n");
    TailInsert(monsterHead);
    OutputMonsters(monsterHead);
     */
    /*
    //开头插入后，打印链表
    printf("\n************************\n");
    newMonster = HeadInsert(monsterHead);
    OutputMonsters(newMonster);
     */
    //中间插入后，打印链表
    printf("\n************************\n");
    MidInsert(monsterHead, 2);
    OutputMonsters(monsterHead);
    
    return 0;
}
/** 创建链表，返回链表首元素的指针 */
Monster * CreateList()
{
    Monster * pHead;    //指向链表首元素的指针
    Monster * pEnd;     //指向链表尾元素的指针
    Monster * pNew;     //当前新增元素的指针
    monsterCount = 0;   //当前链表中元素的总数
    while(1)
    {
        //1.创造一个元素 并赋值
        pNew = (Monster *)malloc(sizeof(Monster));
        printf("请输入第%d个怪物的id和名称：", ++monsterCount);
        scanf("%d%s", &pNew->id, pNew->name);
        pNew->pNext = NULL;
        //假设用户输入负id时强制退出输入循环
        if(pNew->id <= 0)
        {
            printf("成功构建了%d个新的怪物对象！\n", --monsterCount);
            free(pNew);
            break;
        }
        if(monsterCount == 1)//当输入的是第一个元素的时候-一人吃饱，全家不饿
        {
            pHead = pNew;
            pEnd = pNew;
        }
        else
        {
            pEnd->pNext = pNew;
            //扩大下限 - 小王子退位给新创建的对象
            pEnd = pNew;
        }
    }
    return pHead;
}

void OutputMonsters(Monster * pHead)
{
    //创建一个小弟来遍历链表
    Monster * tempMonster;
    //老大授权给小弟
    tempMonster = pHead;
    int index = 1;
    printf("\n当前链表中怪物的信息\n");        //----------------
    while(tempMonster != NULL)
    {
        printf("第%d个怪物的信息：", index++);
        printf("%d\t%s\n", tempMonster->id, tempMonster->name);
        tempMonster = tempMonster->pNext;
    }
}
/** 根据删除下标，删除链表中对应的元素 */
void DeleteByIndex(Monster * pHead, int delIndex)
{
    if(delIndex < 0) return;
    Monster * preMonster;   //前一个元素的指针
    Monster * tempMonster;  //临时变量 - 相当于带我们参观的小弟
    int i = 0;
    //给小弟授权
    //tempMonster = pHead;
    preMonster = tempMonster = pHead;
    while(tempMonster != NULL)   //---------------（原来代码的意思的不足，无法删除最后一个元素）修改
    {
        if(i == delIndex)//找到了要删除的元素
        {
            preMonster->pNext = tempMonster->pNext;
            //卸磨杀驴
            free(tempMonster);
        }
        preMonster = tempMonster;       //记录下上一个元素指针
        tempMonster = tempMonster->pNext;//可以到下个“房间”去搜索了
        i++;
    }
    
}

/** 根据插入下标1、2、3···，链表的中间位置插入元素（局限：不能在开头插入。其他位置都可以插入）*/
void MidInsert(Monster * pHead, int insertIndex){
    if(insertIndex < 0) return;
    int i = 0;
    Monster * preMonster;   //前一个元素的指针
    Monster * tempMonster;  //临时变量 - 相当于带我们参观的小弟(针对pHead)
    Monster * tempMonster2;   //临时变量 - 相当于带我们参观的小弟(针对insertMonsterHead)
    Monster * insertMonsterHead;     //需要插入的链表部分
    preMonster = tempMonster = pHead;   //老大授权给小弟
    
    //1-输入需要插入的链表部分
    printf("请输入需要在该位置插入的新的链表部分(以输入id为负数结束):\n");
    insertMonsterHead = CreateList();
    tempMonster2 = insertMonsterHead;    //新链表的大哥授权给小弟
    
    //2-查找需要插入的位置（假设都在元素个数内，先不考虑溢出问题）
    while(tempMonster != NULL)
    {
        if(i == insertIndex)//找到了要插入的位置
        {
            //2.1-前一个元素连接(插入的开头)
            preMonster->pNext = insertMonsterHead;
            //2.2-(插入的结尾)连接当前元素
            //2.2.1-找到最后的元素,赋值给tempMonster2
            while(tempMonster2->pNext != NULL)
            {
                tempMonster2 = tempMonster2->pNext; //只要不是最后一个元素，就进入下一个房间继续搜索
            }
            //2.2.3-在原来的链表上接入
            tempMonster2->pNext = tempMonster;
            //free(tempMonster2);
            free(tempMonster);//卸磨杀驴
        }
        preMonster = tempMonster;       //记录下上一个元素指针
        tempMonster = tempMonster->pNext;//可以到下个“房间”去搜索了
        i++;
    }
}


/** 链表的最后插入元素 */
void TailInsert(Monster * pHead){
    Monster * tempMonster;  //临时变量 - 相当于带我们参观的小弟
    tempMonster = pHead;    //老大授权给小弟
    Monster * insertMonsterHead;    //需要插入的链表部分
    //1-找到最后的元素,赋值给tempMonster
    while(tempMonster->pNext != NULL)
    {
        tempMonster = tempMonster->pNext; //只要不是最后一个元素，就进入下一个房间继续搜索
    }

    //2-输入需要插入的链表部分
    printf("请输入末尾需要插入的新的链表部分(以输入id为负数结束):\n");
    insertMonsterHead = CreateList();
    //3-在原来的链表上接入
    tempMonster->pNext = insertMonsterHead;
    //free(tempMonster);
}


/** 链表的开头插入元素 */
Monster * HeadInsert(Monster * pHead){
    Monster * tempMonster;  //临时变量 - 相当于带我们参观的小弟(针对于新插入链表)
    Monster * insertMonsterHead;    //需要插入的链表部分
    
    //1-输入需要插入的链表部分
    printf("请输入开头需要插入的新的链表部分(以输入id为负数结束):\n");
    insertMonsterHead = CreateList();
    //2--------把原来的链表上接入到开头部分的链表中（分2步）
    //2.1-找到insertMonsterHead最后的元素,赋值给tempMonster
    tempMonster = insertMonsterHead;
    while(tempMonster->pNext != NULL)
    {
        tempMonster = tempMonster->pNext; //只要不是最后一个元素，就进入下一个房间继续搜索
    }
    //2.2-在新链表上接入原来的链表
    tempMonster->pNext = pHead;
    //free(tempMonster);
    //3-返回新的链表首元素指针(原来的大哥退位，新大哥上位)
    return insertMonsterHead;
}
