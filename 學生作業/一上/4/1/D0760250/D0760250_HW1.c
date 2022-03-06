#include <stdio.h>
#include <stdlib.h>

int main()
{
    char char1_type = 'F';
    int char1_hp = 40;
    int char1_atk = 15;
    int char1_def = 10;
    char char2_type = 'W';
    int char2_hp = 45;
    int char2_atk = 20;
    int char2_def = 5;
    char char3_type = 'A';
    int char3_hp = 40;
    int char3_atk = 20;
    int char3_def = 10;
    char char0_type;
    int char0_hp,char0_atk,char0_def ;

    printf("角色1\n名稱：SKY\n屬性\：%c     攻擊\：%d\n血量\：%d    防禦\：%d\n角色強度預測：%.2f\n\n"
           ,char1_type,char1_atk,char1_hp,char1_def,(char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5);
    printf("角色2\n名稱：SUN\n屬性\：%c     攻擊\：%d\n血量\：%d    防禦\：%d\n角色強度預測：%.2f\n\n"
           ,char2_type,char2_atk,char2_hp,char2_def,(char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5);
    printf("角色3\n名稱：DUST\n屬性\：%c     攻擊\：%d\n血量\：%d    防禦\：%d\n角色強度預測：%.2f\n\n"
           ,char3_type,char3_atk,char3_hp,char3_def,(char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5);

    printf("輸入屬性:");
    scanf("%c",&char0_type);
    printf("輸入攻擊:");
    scanf("%d",&char0_atk);
    printf("輸入血量:");
    scanf("%d",&char0_hp);
    printf("輸入防禦:");
    scanf("%d",&char0_def);
    printf("\n");
    printf("角色4\n名稱：自訂角色\n屬性\：%c     攻擊\：%d\n血量\：%d    防禦\：%d\n角色強度預測：%.2f\n\n"
           ,char0_type,char0_atk,char0_hp,char0_def,(char0_hp*1.0+char0_atk*0.8+char0_def*0.5-50)*6.5);


    return 0;
}

