#include<stdio.h>
#include<stdlib.h>
#include <wchar.h>
int main() {
    int chara_Total=3;
    //角色1
    char char1_name[] = "Momi";
    char char1_type = 'W';
    int char1_hp = 45;
    int char1_atk = 15;
    int char1_def = 7;
    //角色2
    char char2_name[] = "Kirito";
    char char2_type = 'F';
    int char2_hp = 44;
    int char2_atk = 16;
    int char2_def = 8;
    //角色3
    char char3_name[] = "Miku";
    char char3_type = 'G';
    int char3_hp = 43;
    int char3_atk = 17;
    int char3_def = 9;
    //角色4
    char char4_name[] = "自訂角色";
    char char4_type = 'G';
    int char4_hp = 46;
    int char4_atk = 17;
    int char4_def = 9;
    //輸入輸出
    Print(1,char1_name,char1_type,char1_hp,char1_atk,char1_def);
    puts("");//換行
    Print(2,char2_name,char2_type,char2_hp,char2_atk,char2_def);
    puts("");
    Print(3,char3_name,char3_type,char3_hp,char3_atk,char3_def);
    puts("");
    printf("是否新增角色(1.Yes/2.No)?");
    int YN;//存儲yes or no
    scanf("%d",&YN);
    if(RanInt(YN,1,2)==1) { //自製function判斷範圍是否超出
        printf("輸入錯誤");
        return 0;
    }
    if(YN==1) {
        chara_Total++;
        getchar();
        printf("\n新增角色\n");
        printf("屬性：");
        scanf("%c",&char4_type);
        printf("血量：");
        scanf("%d",&char4_hp);
        printf("攻擊：");
        scanf("%d",&char4_atk);
        printf("防禦：");
        scanf("%d",&char4_def);
        int Total  = char4_hp + char4_atk + char4_def;
        switch(char4_type) { //屬性字元判斷
        case 'F':
            break;
        case 'W':
            break;
        case 'G':
            break;
        case 'A':
            break;
        case 'f':
            break;
        case 'w':
            break;
        case 'g':
            break;
        case 'a':
            break;
        default:
            printf("錯誤：無此屬性\n");
            if(RanInt(char4_hp,40,50)==1)
                printf("錯誤：能力數值在限制範圍之外\n");
            else if(RanInt(char4_atk,15,20)==1)
                printf("錯誤：能力數值在限制範圍之外\n");
            else if(RanInt(char4_def,5,10)==1)
                printf("錯誤：能力數值在限制範圍之外\n");
            else if(RanInt(Total,65,70)==1)
                printf("錯誤：能力數值在限制範圍之外\n");
            return 0;
            break;
        }
        if(RanInt(char4_hp,40,50)==1) {
            printf("錯誤：能力數值在限制範圍之外\n");
            return 0;
        } else if(RanInt(char4_atk,15,20)==1) {
            printf("錯誤：能力數值在限制範圍之外\n");
            return 0;
        } else if(RanInt(char4_def,5,10)==1) {
            printf("錯誤：能力數值在限制範圍之外\n");
            return 0;
        } else if(RanInt(Total,65,70)==1) {
            printf("錯誤：能力數值在限制範圍之外\n");
            return 0;
        }
        puts("");
        Print(4,char4_name,char4_type,char4_hp,char4_atk,char4_def);
    }
    int AtkChara1;//存使用者輸入先後攻角色值
    int AtkChara2;
    printf("\n選擇先攻角色：");
    scanf("%d",&AtkChara1);
    if(RanInt(AtkChara1,1,chara_Total)==1) {
        printf("錯誤：無此角色\n");
        return 0;
    }
    printf("選擇後攻角色：");
    scanf("%d",&AtkChara2);
    if(RanInt(AtkChara2,1,chara_Total)==1) {
        printf("無此角色\n");
        return 0;
    }
    if(AtkChara1 == AtkChara2) {
        printf("錯誤：不可重複選取\n");
        return 0;
    }
    printf("\n先攻為角色%d、後攻為角色%d",AtkChara1,AtkChara2);
}
//自製萬用輸出函數P
int Print(int Count,char name[],int type,int hp,int atk,int def) {
    printf("角色%d\n名稱：%s\n屬性：%c     攻擊：%d\n血量：%d    防禦：%d\n",Count,name,type,atk,hp,def);
    float Power  = ( hp * 1.0 + atk * 0.8 + def * 0.5 - 50 ) * 6.5;
    printf("角色強度預測：%.2f\n",Power);
    return 0;
}
int RanInt(int num,int min,int max) { //限制數字在指定範圍
    if(num < min || num > max)
        return 1;
    else
        return 0;
}

