#include<stdio.h>
#include<stdlib.h>

int main()
{
    //角色1
    char char1_type = 'G';
    int char1_hp = 50;
    int char1_atk = 15;
    int char1_def = 5;

    //角色2
    char char2_type = 'F';
    int char2_hp = 42;
    int char2_atk = 19;
    int char2_def = 7;

    //角色3
    char char3_type = 'A';
    int char3_hp = 44;
    int char3_atk = 17;
    int char3_def = 8;

    //角色4(自行輸入)
    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;

    //強度預測公式
    float hp_pd = 1.0;
    float atk_pd = 0.8;
    float def_pd = 0.5;


    printf("角色1\n"
           "名稱:aibo \n"
           "屬性:%c   攻擊:%d\n"
           "血量:%d  防禦:%d\n"
           ,char1_type,char1_atk,char1_hp,char1_def);

    printf("角色強度預測:%.2f\n\n",(char1_hp*hp_pd)+(char1_atk*atk_pd)+(char1_def*def_pd)-50);

    printf("角色2\n"
           "名稱:公道伯  \n"
           "屬性:%c   攻擊:%d\n"
           "血量:%d  防禦:%d\n"
           ,char2_type,char2_atk,char2_hp,char2_def);

    printf("角色強度預測:%.2f\n\n",(char2_hp*hp_pd)+(char2_atk*atk_pd)+(char2_def*def_pd)-50);

    printf("角色3\n"
           "名稱:滅滅子  \n"
           "屬性:%c   攻擊:%d  \n"
           "血量:%d  防禦:%d  \n"
           ,char3_type,char3_atk,char3_hp,char3_def);

    printf("角色強度預測:%.2f\n\n",(char3_hp*hp_pd)+(char3_atk*atk_pd)+(char3_def*def_pd)-50);


//角色4


    printf("新增角色\n"
           "角色名稱:自訂角色\n");
    printf("屬性:");
    scanf("%c",&char4_type);

    printf("血量:");
    scanf("%d",&char4_hp);

    printf("攻擊:");
    scanf("%d",&char4_atk);

    printf("防禦:");
    scanf("%d",&char4_def);

    printf("\n");

    printf("角色4\n"
           "名稱:自訂角色  \n"
           "屬性:%c   攻擊:%d  \n"
           "血量:%d  防禦:%d   \n"
           ,char4_type,char4_atk,char4_hp,char4_def);
    printf("角色強度預測:%.2f\n\n",(char4_hp*hp_pd)+(char4_atk*atk_pd)+(char4_def*def_pd)-50);

    return 0;
}

