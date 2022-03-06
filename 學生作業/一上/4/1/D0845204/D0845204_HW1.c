#include<stdio.h>
int main()
{
    char char1_type='F';
    int  char1_hp=42;
    int  char1_atk=18;
    int  char1_def=9;
    float char1_power=(char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;
    char char2_type='W';
    int  char2_hp=47;
    int  char2_atk=15;
    int  char2_def=6;
    float char2_power=(char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
    char char3_type='G';
    int  char3_hp=46;
    int  char3_atk=19;
    int  char3_def=5;
    float char3_power=(char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
    char char4_type;
    int  char4_hp;
    int  char4_atk;
    int  char4_def;
    printf("角色1\n"
           "名稱:所羅門\n"
           "屬性:%-6c    血量:%-6d\n"
           "攻擊:%-6d    防禦:%-6d\n"
           "角色強度預測:%.2f\n\n",char1_type,char1_hp,char1_atk,char1_def,char1_power);
    printf("角色2\n"
           "名稱:瑪娜\n"
           "屬性:%-6c    血量:%-6d\n"
           "攻擊:%-6d    防禦:%-6d\n"
           "角色強度預測:%.2f\n\n",char2_type,char2_hp,char2_atk,char2_def,char2_power);
    printf("角色3\n"
           "名稱:摩西\n"
           "屬性:%-6c    血量:%-6d\n"
           "攻擊:%-6d    防禦:%-6d\n"
           "角色強度預測:%.2f\n\n",char3_type,char3_hp,char3_atk,char3_def,char3_power);

    printf("新增角色4\n");
    printf("屬性:");
    scanf ("%c",&char4_type);
    printf("血量:");
    scanf ("%d",&char4_hp);
    printf("攻擊:");
    scanf ("%d",&char4_atk);
    printf("防禦:");
    scanf ("%d",&char4_def);
    float char4_power=(char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;
    printf("\n角色4\n"
           "屬性:%-6c   血量:%-6d\n"
           "攻擊:%-6d   防禦:%-6d\n"
           "角色強度預測:%.2f\n\n",char4_type,char4_hp,char4_atk,char4_def,char4_power);
    return 0;
}
