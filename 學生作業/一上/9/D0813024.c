#include<stdio.h>
#include<stdlib.h>
char char_type[4] = "GAW";
int char_hp[4] = {50,40,44,0};
int char_atk[4] = {15,20,17,0};
int char_def[4] = {5,8,8,0};
char char_name[4][20] = {"Aibo", "公道伯", "滅滅子"};
//flag堆
int is_error=0;
int is_error1=0;
int is_error2=0;
int is_creat=0;//角色4是否存在
int select;
int player1=0;
int player2=0;

void EditNewChar()
{
    is_error = 0;   //將flag歸回0
    is_error1 = 0;
    printf("\n新增角色\n");
    printf("名稱:");
    scanf("%s",char_name[3]);
    getchar();
    printf("屬性:");
    scanf("%c",&char_type[3]);

    printf("血量:");
    scanf("%d",&char_hp[3]);

    printf("攻擊:");
    scanf("%d",&char_atk[3]);

    printf("防禦:");
    scanf("%d",&char_def[3]);
    getchar();
    //數值限制
    if(char_type[3] != 'F' && char_type[3] != 'W' && char_type[3] != 'G' && char_type[3] != 'A' &&
        char_type[3] != 'f' && char_type[3] != 'w' && char_type[3] != 'g' && char_type[3] != 'a')
    {
        printf("錯誤:無此屬性\n"),is_error=1;
    }
    //將屬性小寫轉成大寫
    else if(char_type[3] == 'f')
        char_type[3] = 'F';
    else if(char_type[3] == 'w')
        char_type[3] = 'W';
    else if(char_type[3] == 'g')
        char_type[3] = 'G';
    else if(char_type[3] == 'a')
        char_type[3] = 'A';
    if(char_hp[3] >50 || char_hp[3] <40 ||
        char_atk[3] >20 || char_atk[3] <15 ||
        char_def[3] >10 ||  char_def[3] <5 ||
        (char_hp[3] + char_atk[3]  + char_def[3]) >70 || (char_hp[3] + char_atk[3]  + char_def[3]) <65)
    {
        printf("錯誤:能力數值在限制範圍之外\n");
        is_error1=1;
    }

}
void PrintCharData(char name[],int hp,int atk,int def,char type)
{
    printf("\n名稱:%s\n",name);
    printf("屬性:%c     攻擊:%d\n", type, atk);
    printf("血量:%d    防禦:%d\n", hp, def);
    printf("角色強度預測：%.2f\n",
   (hp * 1.0 + atk * 0.8 + def * 0.5 - 50.0) * 6.5 );
   return;
}
void SelectAndBattle()
{
    while(1)    //重複角色輸入的迴圈
    {
        while(1)
        {
            is_error2=0;
            printf("\n選擇先攻角色:");
            scanf("%d",&player1);
            if(player1 < 1 || player1 > 3 + is_creat) //角色4是否存在的flag
            {
                printf("錯誤:無此角色\n");
                is_error2=1;
            }
            if(is_error2==0)
            {
                break;
            }
        }
        while(1)
        {
            is_error2=0;
            printf("選擇後攻角色:");
            scanf("%d",&player2);
            if(player2 < 1 || player2 > 3 + is_creat)
            {
                printf("錯誤:無此角色\n");
                is_error2=1;
            }
            if(is_error2==0)
            {
                break;
            }
        }

        is_error2=0;
        if(player1 == player2)
        {
            printf("錯誤:角色重複輸入\n",is_error2=1);
        }
        if(is_error2 == 0)
        {
            break;
        }

    }
    printf("\n先攻為角色%d、後攻為角色%d\n",player1,player2);
    printf("戰鬥開始\n\n");
    int first_hp,first_def;
    int later_hp,later_def;
    double first_atk,later_atk;
    char first_type,later_type;
    //先攻
    if(player1==1)
    {
        first_hp=char_hp[0];
        first_atk=char_atk[0];
        first_def=char_def[0];
        first_type=char_type[0];
    }
    else if(player1==2)
    {
        first_hp=char_hp[1];
        first_atk=char_atk[1];
        first_def=char_def[1];
        first_type=char_type[1];
    }
    else if(player1==3)
    {
        first_hp=char_hp[2];
        first_atk=char_atk[2];
        first_def=char_def[2];
        first_type=char_type[2];
    }
    else if(player1==4)
    {
        first_hp=char_hp[3];
        first_atk=char_atk[3];
        first_def=char_def[3];
        first_type=char_type[3];
    }
    //後攻
    if(player2==1)
    {
        later_hp=char_hp[0];
        later_atk=char_atk[0];
        later_def=char_def[0];
        later_type=char_type[0];
    }
    else if(player2==2)
    {
        later_hp=char_hp[1];
        later_atk=char_atk[1];
        later_def=char_def[1];
        later_type=char_type[1];
    }
    else if(player2==3)
    {
        later_hp=char_hp[2];
        later_atk=char_atk[2];
        later_def=char_def[2];
        later_type=char_type[2];
    }
    else if(player2==4)
    {
        later_hp=char_hp[3];
        later_atk=char_atk[3];
        later_def=char_def[3];
        later_type=char_type[3];
    }
    //屬性相剋
    if(first_type=='F'&&later_type=='A')
    {
        first_atk*=1.2;
        later_atk*=0.8;
    }
    else if(first_type=='A'&&later_type=='F')
    {
        first_atk*=0.8;
        later_atk*=1.2;
    }
    else if(first_type=='A'&&later_type=='G')
    {
        first_atk*=1.2;
        later_atk*=0.8;
    }
    else if(first_type=='G'&&later_type=='A')
    {
        first_atk*=0.8;
        later_atk*=1.2;
    }
    else if(first_type=='G'&&later_type=='W')
    {
        first_atk*=1.2;
        later_atk*=0.8;
    }
    else if(first_type=='W'&&later_type=='G')
    {
        first_atk*=0.8;
        later_atk*=1.2;
    }
    else if(first_type=='W'&&later_type=='F')
    {
        first_atk*=1.2;
        later_atk*=0.8;
    }
    else if(first_type=='F'&&later_type=='W')
    {
        first_atk*=0.8;
        later_atk*=1.2;
    }
    int damage,damage2;
    int turn = 1;
    int first_atk_origin_hp = first_hp; //先後攻原始血量
    int later_atk_origin_hp = later_hp;
    int first_is_hp50=0; //殘血倍率flag
    int later_is_hp50=0;
    void Battling()
    {   while(1)
        {
            while(first_hp > 0 && later_hp > 0)
            {
                if(first_hp<=first_atk_origin_hp/2 && first_is_hp50==0) //殘血倍率
                {
                    first_atk*=1.2;
                    first_is_hp50=1;
                }
                if(later_hp<=later_atk_origin_hp/2 && later_is_hp50==0)
                {
                    later_atk*=1.2;
                    later_is_hp50=1;
                }
                int atk;
                if(turn == 1)
                {
                    atk =(int)first_atk - later_def;
                    later_hp -= atk;
                    printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n", player1, player2, atk);
                    turn = 2; //交換攻擊方
                }
                else
                {
                    atk =(int)later_atk - first_def;
                    first_hp -= atk;
                    printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n", player2, player1, atk);
                    turn = 1; //交換攻擊方
                }
                printf("角色%d HP: %d  角色%d HP: %d\n\n", player1, first_hp, player2, later_hp);
            }
            printf("角色%d 失去戰鬥能力\n", (first_hp > 0) ? player1 : player2);
            printf("戰鬥結束\n\n");
            printf("角色%d 獲勝\n\n", (first_hp > 0) ? player1 : player2);
            break;
        }
    }
    Battling();
}
int main()
{
    while(1){
        while(1){
            is_error=0;
            printf("1. 新增或新增修改新增角色\n");
            printf("2. 顯示所有角色資料\n");
            printf("3. 戰鬥\n");
            printf("0. 結束遊戲\n");
            printf("請選擇:");
            scanf("%d",&select);
            if(select == 0)
            {
                printf("\n結束遊戲\n");
                return 0;
            }
            if(select != 1 && select != 2 && select != 3)
            {
                printf("\n輸入錯誤!\n\n");
                is_error=1;
            }
            if(is_error == 0)
            {
                break;
            }
        }
        if(select == 1) //新增角色或修改
        {
            while(1)            //設置輸入錯誤的迴圈
            {
                EditNewChar();
                //輸入有誤重新輸入的flag
                if(is_error==0 && is_error1==0)
                    break;
            }
            PrintCharData(char_name[3],char_hp[3],char_atk[3],char_def[3],char_type[3]);
            is_creat=1;
        }
        else if(select == 2)
        {
            for(int i = 0; i < 3 + is_creat ; i++)
            {
                printf("\n角色%d", i + 1);
                PrintCharData(char_name[i],char_hp[i],char_atk[i],char_def[i],char_type[i]);
            }
            printf("\n");
        }
        else if(select == 3) //戰鬥
        {
            SelectAndBattle();
        }
    }
}







