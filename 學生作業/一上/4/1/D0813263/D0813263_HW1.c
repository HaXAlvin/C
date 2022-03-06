#include<stdio.h>
int main() {
    //角色1
    char char1_type = 'F';
    int char1_hp = 48;
    int char1_atk = 16;
    int char1_def = 6;
    //角色2
    char char2_type = 'G';
    int char2_hp = 41;
    int char2_atk = 19;
    int char2_def = 9;
    //角色3
    char char3_type = 'A';
    int char3_hp = 50;
    int char3_atk = 14;
    int char3_def = 4;
    //自訂角色
    char char4_type ;
    int char4_hp ;
    int char4_atk;
    int char4_def ;

    float va1=((char1_hp*1.0)+(char1_atk*0.8)+(char1_def*0.5)-50)*6.5;//強度預測算法
    float va2=((char2_hp*1.0)+(char2_atk*0.8)+(char2_def*0.5)-50)*6.5;//強度預測算法
    float va3=((char3_hp*1.0)+(char3_atk*0.8)+(char3_def*0.5)-50)*6.5;//強度預測算法

    printf("角色1\n名稱:馬力歐\n屬性:%c\t\t血量:%d\n攻擊力:%d\t防禦力%d\n強度預測:%.2f\n\n",char1_type,char1_hp,char1_atk,char1_def,va1);
    printf("角色2\n名稱:路易吉\n屬性:%c\t\t血量:%d\n攻擊力:%d\t防禦力%d\n強度預測:%.2f\n\n",char2_type,char2_hp,char2_atk,char2_def,va2);
    printf("角色3\n名稱:奇諾比奧\n屬性:%c\t\t血量:%d\n攻擊力:%d\t防禦力%d\n強度預測:%.2f\n\n",char3_type,char3_hp,char3_atk,char3_def,va3);
    //printf("角色1\n名稱:馬力歐\n屬性:F\t\t血量:48\n攻擊力:16\t防禦力6\n\n");//總和70
    //printf("角色2\n名稱:路易吉\n屬性:G\t\t血量:41\n攻擊力:19\t防禦力9\n\n");//總和69
    //printf("角色3\n名稱:奇諾比奧\n屬性:A\t\t血量:50\n攻擊力:14\t防禦力4\n\n");//總和68

    printf("新增角色\n");
    printf("屬性:");
    scanf("%c",&char4_type);
    printf("血量:");
    scanf("%d",&char4_hp);
    printf("攻擊力:");
    scanf("%d",&char4_atk);
    printf("防禦力:");
    scanf("%d",&char4_def);

    float va4=((char4_hp*1.0)+(char4_atk*0.8)+(char4_def*0.5)-50)*6.5;//強度預測算法
    printf("\n角色4\n角色名稱:自訂角色\n屬性:%c\t\t血量:%d\n攻擊力:%d\t防禦力:%d\n強度預測:%.2f\n\n",char4_type,char4_hp,char4_atk,char4_def,va4);

    return 0;
}
