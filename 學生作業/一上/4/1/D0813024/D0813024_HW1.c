#include<stdio.h>
#include<stdlib.h>

int main()
{
    //����1
    char char1_type = 'G';
    int char1_hp = 50;
    int char1_atk = 15;
    int char1_def = 5;

    //����2
    char char2_type = 'F';
    int char2_hp = 42;
    int char2_atk = 19;
    int char2_def = 7;

    //����3
    char char3_type = 'A';
    int char3_hp = 44;
    int char3_atk = 17;
    int char3_def = 8;

    //����4(�ۦ��J)
    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;

    //�j�׹w������
    float hp_pd = 1.0;
    float atk_pd = 0.8;
    float def_pd = 0.5;


    printf("����1\n"
           "�W��:aibo \n"
           "�ݩ�:%c   ����:%d\n"
           "��q:%d  ���m:%d\n"
           ,char1_type,char1_atk,char1_hp,char1_def);

    printf("����j�׹w��:%.2f\n\n",(char1_hp*hp_pd)+(char1_atk*atk_pd)+(char1_def*def_pd)-50);

    printf("����2\n"
           "�W��:���D�B  \n"
           "�ݩ�:%c   ����:%d\n"
           "��q:%d  ���m:%d\n"
           ,char2_type,char2_atk,char2_hp,char2_def);

    printf("����j�׹w��:%.2f\n\n",(char2_hp*hp_pd)+(char2_atk*atk_pd)+(char2_def*def_pd)-50);

    printf("����3\n"
           "�W��:�����l  \n"
           "�ݩ�:%c   ����:%d  \n"
           "��q:%d  ���m:%d  \n"
           ,char3_type,char3_atk,char3_hp,char3_def);

    printf("����j�׹w��:%.2f\n\n",(char3_hp*hp_pd)+(char3_atk*atk_pd)+(char3_def*def_pd)-50);


//����4


    printf("�s�W����\n"
           "����W��:�ۭq����\n");
    printf("�ݩ�:");
    scanf("%c",&char4_type);

    printf("��q:");
    scanf("%d",&char4_hp);

    printf("����:");
    scanf("%d",&char4_atk);

    printf("���m:");
    scanf("%d",&char4_def);

    printf("\n");

    printf("����4\n"
           "�W��:�ۭq����  \n"
           "�ݩ�:%c   ����:%d  \n"
           "��q:%d  ���m:%d   \n"
           ,char4_type,char4_atk,char4_hp,char4_def);
    printf("����j�׹w��:%.2f\n\n",(char4_hp*hp_pd)+(char4_atk*atk_pd)+(char4_def*def_pd)-50);

    return 0;
}

