#include<stdio.h>
#include<stdlib.h>
int main()
{
    //角色1
    char char1_type='F';
    int char1_hp=45;
    int char1_atk=17;
    int char1_def=8;
    float char1_pre=(char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;
    //角色2
    char char2_type='G';
    int char2_hp=45;
    int char2_atk=15;
    int char2_def=10;
    float char2_pre=(char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
    //角色3
    char char3_type='A';
    int char3_hp=50;
    int char3_atk=15;
    int char3_def=5;
    float char3_pre=(char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
    //角色4
    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    float char4_pre;

    printf("角色1\n");
    printf("名稱:阿柴\n");
    printf("屬性:%c\t",char1_type);
    printf("攻擊:%d\n",char1_atk);
    printf("血量:%d\t",char1_hp);
    printf("防禦:%d\n",char1_def);
    printf("角色強度預測:%.2f\n",char1_pre);
    printf("\n");

    printf("角色2\n");
    printf("名稱:豆桑\n");
    printf("屬性:%c\t",char2_type);
    printf("攻擊:%d\n",char2_atk);
    printf("血量:%d\t",char2_hp);
    printf("防禦:%d\n",char2_def);
    printf("角色強度預測:%.2f\n",char2_pre);
    printf("\n");

    printf("角色3\n");
    printf("名稱:蘿絲 \n");
    printf("屬性:%c\t",char3_type);
    printf("攻擊:%d\n",char3_atk);
    printf("血量:%d\t",char3_hp);
    printf("防禦:%d\n",char3_def);
    printf("角色強度預測:%.2f\n",char3_pre);
    printf("\n");

    printf("新增角色\n"
           "屬性:");
    scanf("%c",&char4_type);
    printf("血量:");
    scanf("%d",&char4_hp);
    printf("攻擊:");
    scanf("%d",&char4_atk);
    printf("防禦:");
    scanf("%d",&char4_def);
    char4_pre=(char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;
    printf("\n");

    printf("角色4\n");
    printf("名稱:無名\n");
    printf("屬性:%c\t",char4_type);
    printf("攻擊:%d\n",char4_atk);
    printf("血量:%d\t",char4_hp);
    printf("防禦:%d\n",char4_def);
    printf("角色強度預測:%.2f\n",char4_pre);
    printf("\n");

    return 0;
}
