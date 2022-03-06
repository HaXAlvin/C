#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>
#include<stdbool.h>
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

int main(){

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
    while(RanInt(YN,1,2)==1)//當輸入的值超過範圍，令使用者重新輸入
    {
        printf("輸入錯誤\n");
        printf("是否新增角色(1.Yes/2.No)?");
        scanf("%d",&YN);
    }
    bool Error404=false;//用一個bool來判斷使用者是否輸入錯誤
    if(YN==1)
    {
        do
        {
            Error404=false;//每次輸入錯誤，回到這裡時，令其為假，然後重新判斷
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
            switch(char4_type){//屬性字元判斷
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
                    Error404=true;//當錯誤時，令404為真，讓while轉一輪
                    break;
            }
            if(RanInt(char4_hp,40,50)==1)
            {
                printf("錯誤：能力數值在限制範圍之外\n");
                Error404=true;
            }
            else if(RanInt(char4_atk,15,20)==1)
            {
                printf("錯誤：能力數值在限制範圍之外\n");
                Error404=true;
            }
            else if(RanInt(char4_def,5,10)==1)
            {
                printf("錯誤：能力數值在限制範圍之外\n");
                Error404=true;
            }
            else if(RanInt(Total,65,70)==1){
                printf("錯誤：能力數值在限制範圍之外\n");
                Error404=true;
            }
        }while(Error404==true);
        puts("");
        Print(4,char4_name,char4_type,char4_hp,char4_atk,char4_def);
        puts("");
        chara_Total++;//角色總數，超過的都是錯誤輸入
    }
    int AtkChara1;//存使用者輸入先後攻角色值
    int AtkChara2;
    do
    {
        Error404=false;
        printf("選擇先攻角色：");
        scanf("%d",&AtkChara1);
        if(RanInt(AtkChara1,1,chara_Total)==1)
        {
            printf("錯誤：無此角色\n");
            Error404=true;//跟上面一樣用法
        }
    }while(Error404==true);
    do
    {
        Error404=false;
        printf("選擇後攻角色：");
        scanf("%d",&AtkChara2);
        if(RanInt(AtkChara2,1,chara_Total)==1)
        {
            printf("錯誤：無此角色\n");
            Error404=true;
        }
        else if(AtkChara1 == AtkChara2)
        {
            printf("錯誤：不可重複選取\n");
            Error404=true;
        }
    }while(Error404==true);
    Error404=false;
    printf("\n先攻為角色%d、後攻為角色%d",AtkChara1,AtkChara2);
    Fight(AtkChara1,AtkChara2);//戰鬥函數:在裡面進行戰鬥相關運算輸出
    return 0;
}
//自製萬用輸出函數P
int Print(int Count,char name[] ,int type,int hp,int atk,int def)
{
    printf("角色%d\n名稱：%s\n屬性：%c     攻擊：%d\n血量：%d    防禦：%d\n",Count,name,type,atk,hp,def);
    float Power  = ( hp * 1.0 + atk * 0.8 + def * 0.5 - 50 ) * 6.5;
    printf("角色強度預測：%.2f\n",Power);
    return 0;
}
int RanInt(int num,int min,int max)//限制數字在指定範圍
{
    if(num < min || num > max)
        return 1;
    else
        return 0;
}
int Fight(int Chara1,int Chara2)
{
    int Hp1,Hp2,Atk1,Atk2,Def1,Def2;
    printf("\n戰鬥開始\n");
    switch(Chara1)
    {
        case 1:
            Hp1 = char1_hp;
            Atk1 = char1_atk;
            Def1 = char1_def;
            break;
        case 2:
            Hp1 = char2_hp;
            Atk1 = char2_atk;
            Def1 = char2_def;
            break;
        case 3:
            Hp1 = char3_hp;
            Atk1 = char3_atk;
            Def1 = char3_def;
            break;
        case 4:
            Hp1 = char4_hp;
            Atk1 = char4_atk;
            Def1 = char4_def;
            break;
    }
    switch(Chara2)
    {
        case 1:
            Hp2 = char1_hp;
            Atk2 = char1_atk;
            Def2 = char1_def;
            break;
        case 2:
            Hp2 = char2_hp;
            Atk2 = char2_atk;
            Def2 = char2_def;
            break;
        case 3:
            Hp2 = char3_hp;
            Atk2 = char3_atk;
            Def2 = char3_def;
            break;
        case 4:
            Hp2 = char4_hp;
            Atk2 = char4_atk;
            Def2 = char4_def;
            break;
    }
    int AtkPower ;
    bool swi=false;//交換攻擊手
    do{
        if(swi==false)//
        {
            AtkPower = Atk1 - Def2;
            Hp2-=AtkPower;
            printf("\n角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n角色%d  HP: %d  角色%d HP: %d\n",Chara1,Chara2,AtkPower,Chara1,Hp1,Chara2,Hp2);
            swi=true;//為假則讓攻擊手1進攻，並且攻擊完切換成真
        }
        else
        {
            AtkPower = Atk2 - Def1;
            Hp1-=AtkPower;
            printf("\n角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n角色%d  HP: %d  角色%d HP: %d\n",Chara2,Chara1,AtkPower,Chara1,Hp1,Chara2,Hp2);
            swi=false;//為真則讓攻擊手2進攻，並且攻擊完切換成假
        }

      }while(Hp1>0 && Hp2>0);

    if(Hp1<=0)
    {
        printf("\n角色%d 失去戰鬥能力",Chara1);
        printf("\n戰鬥結束\n");
        printf("\n角色%d 獲勝\n",Chara1);//戰鬥結束的輸出以及判定勝者
    }
    else if(Hp2<=0)
    {
        printf("\n角色%d 失去戰鬥能力",Chara2);
        printf("\n戰鬥結束\n");
        printf("\n角色%d 獲勝\n",Chara2);//戰鬥結束的輸出以及判定勝者
    }


}

