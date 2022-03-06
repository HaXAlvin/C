#include<stdio.h>
#include<stdlib.h>

int main()
{
    //角色1
    char char1_type='F';
    int char1_hp=43;
    int char1_atk=18;
    int char1_def=7;
    float char1_pow=( char1_hp * 1.0 +  char1_atk  * 0.8 + char1_def * 0.5 - 50 ) * 6.5;
    printf("角色1\n名稱:花花\n");
    printf("屬性:%-4c",char1_type);
    printf("血量:%d\n",char1_hp);
    printf("攻擊:%-4d",char1_atk);
    printf("防禦:%d\n",char1_def);
    printf("角色預測強度:%.2f\n\n",char1_pow);

    //角色2
    char char2_type='W';
    int char2_hp=43;
    int char2_atk=16;
    int char2_def=9;
    float char2_pow=( char2_hp * 1.0 +  char2_atk  * 0.8 + char2_def * 0.5 - 50 ) * 6.5;
    printf("角色2\n名稱:泡泡\n");
    printf("屬性:%-4c",char2_type);
    printf("血量:%d\n",char2_hp);
    printf("攻擊:%-4d",char2_atk);
    printf("防禦:%d\n",char2_def);
    printf("角色預測強度:%.2f\n\n",char2_pow);

    //角色3
    char char3_type='A';
    int char3_hp=45;
    int char3_atk=19;
    int char3_def=5;
    float char3_pow=( char3_hp * 1.0 +  char3_atk  * 0.8 + char3_def * 0.5 - 50 ) * 6.5;
    printf("角色3\n名稱:毛毛\n");
    printf("屬性:%-4c",char3_type);
    printf("血量:%d\n",char3_hp);
    printf("攻擊:%-4d",char3_atk);
    printf("防禦:%d\n",char3_def);
    printf("角色預測強度:%.2f\n\n",char3_pow);

    //新增角色
    printf("新增角色\n屬性:");

    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    float char4_pow;

    scanf("%c",&char4_type);
    printf("血量:");
    scanf("%d",&char4_hp);
    printf("攻擊:");
    scanf("%d",&char4_atk);
    printf("防禦:");
    scanf("%d",&char4_def);

    printf("\n");

    printf("角色4\n名稱:尤教授\n");
    printf("屬性:%-4c",char4_type);
    printf("血量:%d\n",char4_hp);
    printf("攻擊:%-4d",char4_atk);
    printf("防禦:%d\n",char4_def);
    printf("角色預測強度:%.2f\n",( char4_hp * 1.0 +  char4_atk  * 0.8 + char4_def * 0.5 - 50 ) * 6.5);

    return 0;
}
