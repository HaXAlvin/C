#include<stdio.h>
#include<stdlib.h>
int main()
{
    //����1
    char char1_type='F';
    int char1_hp=45;
    int char1_atk=17;
    int char1_def=8;
    float char1_pre=(char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;
    //����2
    char char2_type='G';
    int char2_hp=45;
    int char2_atk=15;
    int char2_def=10;
    float char2_pre=(char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
    //����3
    char char3_type='A';
    int char3_hp=50;
    int char3_atk=15;
    int char3_def=5;
    float char3_pre=(char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
    //����4
    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    float char4_pre;

    printf("����1\n");
    printf("�W��:����\n");
    printf("�ݩ�:%c\t",char1_type);
    printf("����:%d\n",char1_atk);
    printf("��q:%d\t",char1_hp);
    printf("���m:%d\n",char1_def);
    printf("����j�׹w��:%.2f\n",char1_pre);
    printf("\n");

    printf("����2\n");
    printf("�W��:����\n");
    printf("�ݩ�:%c\t",char2_type);
    printf("����:%d\n",char2_atk);
    printf("��q:%d\t",char2_hp);
    printf("���m:%d\n",char2_def);
    printf("����j�׹w��:%.2f\n",char2_pre);
    printf("\n");

    printf("����3\n");
    printf("�W��:�ڵ� \n");
    printf("�ݩ�:%c\t",char3_type);
    printf("����:%d\n",char3_atk);
    printf("��q:%d\t",char3_hp);
    printf("���m:%d\n",char3_def);
    printf("����j�׹w��:%.2f\n",char3_pre);
    printf("\n");

    printf("�s�W����\n"
           "�ݩ�:");
    scanf("%c",&char4_type);
    printf("��q:");
    scanf("%d",&char4_hp);
    printf("����:");
    scanf("%d",&char4_atk);
    printf("���m:");
    scanf("%d",&char4_def);
    char4_pre=(char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;
    printf("\n");

    printf("����4\n");
    printf("�W��:�L�W\n");
    printf("�ݩ�:%c\t",char4_type);
    printf("����:%d\n",char4_atk);
    printf("��q:%d\t",char4_hp);
    printf("���m:%d\n",char4_def);
    printf("����j�׹w��:%.2f\n",char4_pre);
    printf("\n");

    return 0;
}
