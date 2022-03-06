#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdbool.h>
#include <ctype.h>
int chara_Total=3;
char char1_name[21]="Momi";
char char2_name[21]="Kirito";
char char3_name[21]="Miku";
char char4_name[21]={0};
char type[4]={0}; //屬性
int hp[4]={0};  //血量
int atk[4]={0};  //攻擊
int def[4]={0};  //防禦
/*
EditNewChar()
PrintCharData()
SelectAndBattle()
Battling()
Battling()須由SelectAndBattle()呼叫*/
//自製萬用輸出函數P
int PrintCharData(int Count,char name[] ,int type,int hp,int atk,int def)
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
int Battling(int Chara1,int Chara2)
{
    int  Hp1,Hp2,Atk1,Atk2,Def1,Def2;
    char type1,type2;
    printf("\n戰鬥開始\n");
    type1 =toupper(type[Chara1-1]);
    Hp1 = hp[Chara1-1];
    Atk1 = atk[Chara1-1];
    Def1 = def[Chara1-1];
    type2 =toupper(type[Chara2-1]);
    Hp2 = hp[Chara2-1];
    Atk2 = atk[Chara2-1];
    Def2 = def[Chara2-1];
    int AtkPower ;
    int Blood50_1=Hp1/2;//剩餘
    int Blood50_2=Hp2/2;//剩餘
    bool swi=false;//交換攻擊手
    do{
        float Phase=1;
        float MinBlood=1;
        if(swi==false)//
        {//W>F>A>G>W 攻擊傷害 = (int)(攻擊方攻擊力 * 相剋倍率 * 殘血倍率 - 被攻擊方防禦力)
        //相剋關係：優勢者1.2倍，劣勢者0.8倍
        //攻擊方血量小於原本的50%時殘血倍率為1.2倍
            if(type1 =='W'&&type2=='F')
                Phase =1.2;
            else if(type1=='F'&&type2=='A')
                Phase =1.2;
            else if(type1=='A'&&type2=='G')
                Phase =1.2;
            else if(type1=='G'&&type2=='W')
                Phase =1.2;
            else if(type1=='F'&&type2=='W')
                Phase =0.8;
            else if(type1=='G'&&type2=='A')
                Phase =0.8;
            else if(type1=='A'&&type2=='F')
                Phase =0.8;
            else if(type1=='W'&&type2=='G')
                Phase =0.8;
            if(Hp1<Blood50_1)
                MinBlood=1.2;
            AtkPower =(int)(Atk1*Phase*MinBlood - Def2) ;
            Hp2-=AtkPower;
            printf("\n角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n角色%d  HP: %d  角色%d HP: %d\n",Chara1,Chara2,AtkPower,Chara1,Hp1,Chara2,Hp2);
            swi=true;//為假則讓攻擊手1進攻，並且攻擊完切換成真
        }
        else
        {
            if(type1 =='W'&&type2=='F')
                Phase =0.8;
            else if(type1=='F'&&type2=='A')
                Phase =0.8;
            else if(type1=='A'&&type2=='G')
                Phase =0.8;
            else if(type1=='G'&&type2=='W')
                Phase =0.8;
            else if(type1=='F'&&type2=='W')
                Phase =1.2;
            else if(type1=='G'&&type2=='A')
                Phase =1.2;
            else if(type1=='A'&&type2=='F')
                Phase =1.2;
            else if(type1=='W'&&type2=='G')
                Phase =1.2;
            float MinBlood=1;
            if(Hp2<Blood50_2)
                MinBlood=1.2;
            AtkPower =(int)(Atk2*Phase*MinBlood - Def1) ;
            Hp1-=AtkPower;
            printf("\n角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n角色%d  HP: %d  角色%d HP: %d\n",Chara2,Chara1,AtkPower,Chara1,Hp1,Chara2,Hp2);
            swi=false;//為真則讓攻擊手2進攻，並且攻擊完切換成假
        }

    }while(Hp1>0 && Hp2>0);

    if(Hp1<=0)
    {
        printf("\n角色%d 失去戰鬥能力",Chara1);
        printf("\n戰鬥結束\n");
        printf("\n角色%d 獲勝\n\n",Chara2);//戰鬥結束的輸出以及判定勝者
    }
    else if(Hp2<=0)
    {
        printf("\n角色%d 失去戰鬥能力",Chara2);
        printf("\n戰鬥結束\n");
        printf("\n角色%d 獲勝\n\n",Chara1);//戰鬥結束的輸出以及判定勝者
    }
}
void EditNewChar()
{
    bool Error404;
    do
    {
        Error404=false;//每次輸入錯誤，回到這裡時，令其為假，然後重新判斷
        if(chara_Total==3)
            printf("\n新增角色\n");
        else
            printf("\n修改新增角色\n");
        printf("名稱：");
        scanf("%s%*c",&char4_name);
        printf("屬性：");
        scanf("%c%*c",&type[3]);
        printf("血量：");
        scanf("%d%*c",&hp[3]);
        printf("攻擊：");
        scanf("%d%*c",&atk[3]);
        printf("防禦：");
        scanf("%d%*c",&def[3]);
        int Total  = hp[3] + atk[3] + def[3];
        switch(type[3]){//屬性字元判斷
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
        if(RanInt(hp[3],40,50)==1)
        {
            printf("錯誤：能力數值在限制範圍之外\n");
            Error404=true;
        }
        else if(RanInt(atk[3],15,20)==1)
        {
            printf("錯誤：能力數值在限制範圍之外\n");
            Error404=true;
        }
        else if(RanInt(def[3],5,10)==1)
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
    PrintCharData(4,char4_name,toupper(type[3]),hp[3],atk[3],def[3]);
    puts("");
    chara_Total=4;//角色總數，超過的都是錯誤輸入
}
void SelectAndBattle()
{
    bool Error404=false;
    puts("");
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
    Battling(AtkChara1,AtkChara2);//戰鬥函數:在裡面進行戰鬥相關運算輸出
}
int main(){
    type[0]='W';
    type[1]='A';
    type[2]='F';
    hp[0]=50;
    hp[1]=40;
    hp[2]=45;
    atk[0]=15;
    atk[1]=20;
    atk[2]=17;
    def[0]=5;
    def[1]=8;
    def[2]=7;
    while(1)
    {
        int choose;
        bool Error404=false;//用一個bool來判斷使用者是否輸入錯誤
        puts("1. 新增或修改新增角色");
        puts("2. 顯示所有角色資料");
        puts("3. 戰鬥");
        puts("0. 結束遊戲");
        printf("請選擇：");
        scanf("%d",&choose);
       // puts("");
        if(choose==0)
        {
            printf("\n結束遊戲\n");
            return 0;
        }
        else if(choose==1)
        {
            EditNewChar();
        }
        else if(choose==2)
        {
            puts("");
            PrintCharData(1,char1_name,toupper(type[0]),hp[0],atk[0],def[0]);
            puts("");
            PrintCharData(2,char1_name,toupper(type[1]),hp[1],atk[1],def[1]);
            puts("");
            PrintCharData(3,char1_name,toupper(type[2]),hp[2],atk[2],def[2]);
            puts("");
            if(chara_Total>3)
            {
                PrintCharData(4,char4_name,toupper(type[3]),hp[3],atk[3],def[3]);
                puts("");
            }
        }
        else if(choose==3)
        {
            SelectAndBattle();
        }
        else
        {
            puts("\n輸入錯誤!\n");
        }



    }
}


