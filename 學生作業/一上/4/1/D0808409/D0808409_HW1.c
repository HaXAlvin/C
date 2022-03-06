#include<stdio.h>
#include<stdlib.h>
#include <wchar.h>
int main(){
    //角色1
    char char1_name[] = "Momi";
    char char1_type = 'W';
    int char1_hp = 50;
    int char1_atk = 15;
    int char1_def = 7;
    //角色2
    char char2_name[] = "Kirito";
    char char2_type = 'F';
    int char2_hp = 48;
    int char2_atk = 16;
    int char2_def = 8;
    //角色3
    char char3_name[] = "Miku";
    char char3_type = 'G';
    int char3_hp = 46;
    int char3_atk = 17;
    int char3_def = 9;
    //角色4
    char char4_name[] = "Chaos";
    char char4_type = 'G';
    int char4_hp = 46;
    int char4_atk = 17;
    int char4_def = 9;
    //輸入輸出
    Print(1,char1_name,char1_type,char1_hp,char1_atk,char1_def);
    Print(2,char2_name,char2_type,char2_hp,char2_atk,char2_def);
    Print(3,char3_name,char3_type,char3_hp,char3_atk,char3_def);
    printf("新增角色\n");
    printf("屬性：");
    scanf("%c",&char4_type);
    printf("血量：");
    scanf("%d",&char4_hp);
    printf("攻擊：");
    scanf("%d",&char4_atk);
    printf("防禦：");
    scanf("%d",&char4_def);
    printf("\n");
    Print(4,char4_name,char4_type,char4_hp,char4_atk,char4_def);
    return 0;
}
//自製萬用輸出函數P
int Print(int Count,char name[] ,int type,int hp,int atk,int def)
{   printf("角色%d\n名稱：",Count);
    for(int x=0;x<strlen(name);x++)
    {
    printf("%c",name[x]);
    }
    printf("\n屬性：%c     攻擊：%d\n血量：%d    防禦：%d\n",type,atk,hp,def);

    float Power  = ( hp * 1.0 + atk * 0.8 + def * 0.5 - 50 ) * 6.5;
    printf("角色強度預測：%.2f\n\n",Power);
    return 0;
}

