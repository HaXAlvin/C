#include<stdio.h>
#include<stdlib.h>

int main()
{
    //����1
    char char1_type='F';
    int char1_hp=43;
    int char1_atk=18;
    int char1_def=7;
    float char1_pow=( char1_hp * 1.0 +  char1_atk  * 0.8 + char1_def * 0.5 - 50 ) * 6.5;
    printf("����1\n�W��:���\n");
    printf("�ݩ�:%-4c",char1_type);
    printf("��q:%d\n",char1_hp);
    printf("����:%-4d",char1_atk);
    printf("���m:%d\n",char1_def);
    printf("����w���j��:%.2f\n\n",char1_pow);

    //����2
    char char2_type='W';
    int char2_hp=43;
    int char2_atk=16;
    int char2_def=9;
    float char2_pow=( char2_hp * 1.0 +  char2_atk  * 0.8 + char2_def * 0.5 - 50 ) * 6.5;
    printf("����2\n�W��:�w�w\n");
    printf("�ݩ�:%-4c",char2_type);
    printf("��q:%d\n",char2_hp);
    printf("����:%-4d",char2_atk);
    printf("���m:%d\n",char2_def);
    printf("����w���j��:%.2f\n\n",char2_pow);

    //����3
    char char3_type='A';
    int char3_hp=45;
    int char3_atk=19;
    int char3_def=5;
    float char3_pow=( char3_hp * 1.0 +  char3_atk  * 0.8 + char3_def * 0.5 - 50 ) * 6.5;
    printf("����3\n�W��:���\n");
    printf("�ݩ�:%-4c",char3_type);
    printf("��q:%d\n",char3_hp);
    printf("����:%-4d",char3_atk);
    printf("���m:%d\n",char3_def);
    printf("����w���j��:%.2f\n\n",char3_pow);

    //�s�W����
    printf("�s�W����\n�ݩ�:");

    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    float char4_pow;

    scanf("%c",&char4_type);
    printf("��q:");
    scanf("%d",&char4_hp);
    printf("����:");
    scanf("%d",&char4_atk);
    printf("���m:");
    scanf("%d",&char4_def);

    printf("\n");

    printf("����4\n�W��:�ױб�\n");
    printf("�ݩ�:%-4c",char4_type);
    printf("��q:%d\n",char4_hp);
    printf("����:%-4d",char4_atk);
    printf("���m:%d\n",char4_def);
    printf("����w���j��:%.2f\n",( char4_hp * 1.0 +  char4_atk  * 0.8 + char4_def * 0.5 - 50 ) * 6.5);

    return 0;
}
