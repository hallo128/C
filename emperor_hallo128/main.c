#include <stdio.h>
#include <stdlib.h>
#include <string.h> //�ַ�������
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")
#define MAX 6//�����������

int main()
{
    int i,k,temp,day,exit_d=0;
    int count=5;            //��ǰδ�����乬����������
    //ʹ���ַ������ʾ�ַ���
    char emperorName[50];   //�ʵ۵�����
    int choice;             //�ʵ۵�ѡ��1-4
    char choiceName[20];    //ѡ�������
    int choiceLocal= -1;    //ѡ�������
    char names[MAX][20]={"����","����","��ʩ","�绨","��֪����"};    //������������
    char levelNames[5][10]={"����","����","����","�ʹ���","�ʺ�"};     //������������
    int levels[MAX]={1,2,0,0,0,-1};                                     //ÿ�����Ӷ�Ӧ�ĵ�ǰ����
    int loves[MAX]={100,100,100,100,100,-1};                            //ÿ�����Ӷ�Ӧ��ǰ�øжȣ���ʼ��Ϊ100


    printf("�����뵱ǰ�ǻ��Ļʵ����ţ�");
    scanf("%s",emperorName);    //¼���ַ���ʱ������Ҫ&����

    //printf("****************************\n");

    for(day=0;day<10;day++){
        PlaySound(TEXT("sounds\\��������.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        printf("\n�ʵ�[%s]�ϳ���[%d]��\n�������࣬�����˳���\n",emperorName,day+1);
        printf("****************************\n");
        printf("��ǰ������״̬��\n");
        printf("%-10s����\t�øж�\n","����");
        for(i=0;i<count;i++){
                printf("%-10s%s\t%d\n",names[i],levelNames[(levels[i])],loves[i]);
        }

        printf("\n1���ʵ���ּѡ����\t�����ӣ�\n");
        printf("2�����Ƴ���\t\t���޸�״̬��\n");
        printf("3�������乬��\t\t��ɾ����\n");
        printf("4���޵İ����أ�\t\t�����ң�\n");

        printf("������ѡ��");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1: //�ʵ���ּѡ����\t\t(���ӹ���)
            //1.��������Ԫ��(names,levels)
            //2.����ǰ��Ҫ�ж�������û�пռ�
            PlaySound(TEXT("sounds\\ѡ��.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            if(count >= MAX)
            {  printf("���£����ĺ�������(���ʧ��)\n");}
            else
            {
                printf("���£���������������䣺");
                scanf("%s",names[count]);
                levels[count]=0;
                loves[count]=100;
                printf("��ӭ%s�����빬��\n",names[count]);
                //��������øж�-10
                for(i=0;i<count;i++){
                    loves[i] -= 10;
                }
                count++;
            }
            break;
        case 2: //2�����Ƴ��ң�\t\t(�޸�״̬����)\n
            //1.�ҵ������ӵ�λ��
            //2.���Ӹ����ӵļ���ͺøжȣ������������ӵļ���ͺøж�
            PlaySound(TEXT("sounds\\����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            printf("���£����������Ҫ������������䣺");
            scanf("%s",choiceName);
            //1���ַ�������strcmp,��Ҫ����<string.h>��
            //strcmp(choiceName,"abc")   0-2���ַ�����ȣ�1-ǰһ�����ں�һ����-1����һ������ǰһ��
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
            //2����ʧ��
            if(choiceLocal == -1) printf("���£�����û����λ�����ر��¼Ǵ��ˣ�(����ʧ��)\n");
            break;
        case 3: //3�������乬��\t\t(ɾ������)\n
            //1. ����������λ��
            //2. ��һ��������ǰ
            //3. ɾ������1�����-1
            //4. �޸��������Ӻøж�+10
            PlaySound(TEXT("sounds\\�乬.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            printf("���£�����λ��������乬��");
            scanf("%s",choiceName);
        //1
            for(i=0;i<count;i++){
                if(strcmp(choiceName,names[i]) == 0) {choiceLocal=i;break;}
            }
            //2
            if(choiceLocal == -1)
                printf("�龪һ�����������޴�Ů�ӣ���ر��¼Ǵ��ˣ�(����ʧ��)\n");
            else
            {
                for(i=choiceLocal;i<count-1;i++)
                {
                //names[i]=names[i+1];  ��Ϊ���ַ�����C���Բ�֧�������ֱ�Ӹ�ֵ
                //ʹ��strcpy����ʵ������ĸ�ֵ
                    strcpy(names[i],names[i+1]);
                    loves[i]=loves[i+1];
                    levels[i]=levels[i+1];
                }
                count--;
            }
        //4 �������Ӻøжȶ�+10
            for(i=0;i<count;i++) loves[i] += 10;

            break;
        case 4://4�������ټ�����ȥС������������¡�
            //1. ����
            //2. ���Ӹ��˺øж�
            PlaySound(TEXT("sounds\\һЦ���.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            printf("���£��ټ���λ����ȥС������������£�");
            scanf("%s",choiceName);
        //1
            for(i=0;i<count;i++){
                if(strcmp(choiceName,names[i]) == 0) {choiceLocal=i;loves[i] += 10;break;}
            }
        //2
            if(choiceLocal == -1)
                printf("���£�����û����λ�����ر��¼Ǵ��ˣ�\n����ʧ��\n");

            break;
        default:
            printf("����Ϸ�ԣ��������ٴ�ȷ�ϣ�");
        }

    //����ӡ��������״̬ǰ���Լ����������ʹ��ð������
        do{ k=0;
            for(i=0;i<count-1;i++){
                if(levels[i]<levels[i+1])
                {temp=levels[i];levels[i]=levels[i+1];levels[i+1]=temp;
                temp=loves[i];loves[i]=loves[i+1];loves[i+1]=temp;
             //ע���ַ�������
                strcpy(choiceName,names[i]);
                strcpy(names[i],names[i+1]);
                strcpy(names[i+1],choiceName);
                k += 1;}
            }
        }while(k != 0);
        printf("\n");
        printf("\n");

        //�鿴���������ĺøж��������50�����Ƴ���Ϸ
        for(i=0;i<count;i++){
                if(loves[i] <= 50) {exit_d=1;break;}
        }
        if(exit_d==1) break;

    }
//------------------------------------------

    printf("\n****************************\n");
    if(day==10)
        printf("������λ�ڼ������ƽ��\n");
    else
        printf("�ʵ�[%s]һ���ϳ�[%d]�죬����̫���б������Ʒ���\n",emperorName,day+1);




    //printf("****************************\n");


/*
    printf("****************************\n");
    printf("��ǰ������״̬��\n");
    printf("%-10s����\t�øж�\n","����");
    for(i=0;i<count;i++){
        printf("%-10s%s\t%d\n",names[i],levelNames[(levels[i])],loves[i]);
    }
    printf("****************************\n");
*/
    return 0;
}
