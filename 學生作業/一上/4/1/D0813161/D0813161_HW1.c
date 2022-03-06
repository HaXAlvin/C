#include<stdio.h>
#include<stdlib.h>
int main()
{
    char charl_type ='F';
    int char1_hp = 42;
    int char1_atk = 19;
    int char1_def = 5;
    char char2_type ='W';
    int char2_hp = 48;
    int char2_atk = 16;
    int char2_def = 5;
    char char3_type ='G';
    int char3_hp = 45;
    int char3_atk = 16;
    int char3_def = 7;
    char char4_type;
    int char4_atk;
    int char4_hp;
    int char4_def;
    printf("角色1\n"
           "名稱:死亡之翼\n"
           "屬性:%c\t攻擊:%d\n"
           "血量:%d\t防禦:%d\n",charl_type,char1_atk,char1_hp,char1_def);
    printf("角色強度預測:%.2f\n\n",(char1_atk*0.8+char1_hp*1.0+char1_def*0.5-50)*6.5);
    printf("角色2\n"
           "名稱:我阿嬤\n"
           "屬性:%c\t攻擊:%d\n"
           "血量:%d\t防禦:%d\n"
           ,char2_type,char2_atk,char2_hp,char2_def);
    printf("角色強度預測:%.2f\n\n",(char2_atk*0.8+char2_hp*1.0+char2_def*0.5-50)*6.5);
            "\n";
    printf("角色3\n"
           "名稱:阿公\n"
           "屬性:%c\t攻擊:%d\n"
           "血量:%d\t防禦:%d\n"
           ,char3_type,char3_atk,char3_hp,char3_def);
    printf("角色強度預測:%.2f\n\n",(char3_atk*0.8+char3_hp*1.0+char3_def*0.5-50)*6.5);
    printf("新增角色//這邊是輸入喔\n");
    printf("屬性:",char4_type);
    scanf("%c",&char4_type);
    printf("攻擊:",char4_atk);
    scanf("%d",&char4_atk);
    printf("血量:",char4_hp);
    scanf("%d",&char4_hp);
    printf("防禦:",char4_def);
    scanf("%d",&char4_def);
    printf("\n");
    printf("角色4\n"
           "名稱:自訂角色\n"
           "屬性:%c\t攻擊:%d\n"
           "血量:%d\t防禦:%d\n\n",char4_type,char4_atk,char4_hp,char4_def);
    printf("角色強度預測:%.2f",(char4_atk*0.8+char4_hp*1.0+char4_def*0.5-50)*6.5);
    return 0;
}
