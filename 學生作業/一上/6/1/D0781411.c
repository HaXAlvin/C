
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    //角色1
    char char1_type = 'F';
    int char1_hp = 40;
    int char1_atk = 20;
    int char1_def = 10;
    float char_1 = (char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;
    printf("角色1\n名稱：豆豆\n");
    printf("屬性： %c  ",char1_type);
    printf("攻擊：%d\n",char1_atk);
    printf("血量：%d  ",char1_hp);
    printf("防禦：%d\n\n",char1_def);
    printf("角色強度：%.2f\n\n",char_1);
    //角色2
    char char2_type = 'W';
    int char2_hp = 50;
    int char2_atk = 15;
    int char2_def = 5;
    float char_2 = (char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
    printf("角色2\n名稱：薛薛\n");
    printf("屬性： %c  ",char2_type);
    printf("攻擊：%d\n",char2_atk);
    printf("血量：%d  ",char2_hp);
    printf("防禦：%d\n\n",char2_def);
    printf("角色強度：%.2f\n\n",char_2);
    //角色3
    char char3_type = 'G';
    int char3_hp = 45;
    int char3_atk = 15;
    int char3_def = 10;
    float char_3 = (char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
    printf("角色3\n名稱：貓咪\n");
    printf("屬性： %c  ",char3_type);
    printf("攻擊：%d\n",char3_atk);
    printf("血量：%d  ",char3_hp);
    printf("防禦：%d\n\n",char3_def);
    printf("角色強度：%.2f\n\n",char_3);
    //角色4分隔線
    int new_char; //是否新增角色
    char char4_type; //屬性字元
    int char4_atk;
    int char4_hp;
    int char4_def;
    int attack1; //先攻
    int attack2; //後攻
    int attack1_hp;//先攻角色的生命
    int attack1_atk;//先攻角色的攻擊
    int attack1_def;//先攻角色的防禦
    int hurt_1;//先攻角色獲得的傷害
    int attack2_hp;//後攻角色的生命
    int attack2_atk;//後攻角色的攻擊
    int attack2_def;//後攻角色的防禦
    int hurt_2;//後攻角色獲得的傷害
    printf("是否新增角色(1.Yes 2.No)  ");
    scanf("%d%*c",&new_char);
    while(new_char!=1&&new_char!=2)//其他的錯誤數字 (選角部分)
    {
        printf("輸入錯誤\n\n");
        printf("是否新增角色(1.Yes 2.No)  ");
        scanf("%d%*c",&new_char);
    }
    if (new_char==1)
    {
        printf("角色屬性:");
        scanf ("%c%*c",&char4_type);
        char4_type=toupper(char4_type);//小寫轉大寫
        printf("血量:");
        scanf ("%d",&char4_hp);
        printf("攻擊:");
        scanf ("%d",&char4_atk);
        printf("防禦:");
        scanf ("%d%*c",&char4_def);
        while(char4_type!=65&&char4_type!=70&&char4_type!=71&&char4_type!=87||char4_atk>20||char4_atk<15||char4_hp>50||char4_hp<40||char4_def<5||char4_def>10||(char4_def+char4_hp+char4_atk)>70||(char4_def+char4_hp+char4_atk)<65)
        {
            if(char4_type!=65&&char4_type!=70&&char4_type!=71&&char4_type!=87)
            {
                printf("錯誤:無此屬性\n");
            }
            if(char4_atk>20||char4_atk<15||char4_hp>50||char4_hp<40||char4_def<5||char4_def>10||(char4_def+char4_hp+char4_atk)>70||(char4_def+char4_hp+char4_atk)<65)
            {
                printf("錯誤:能力數值在限制範圍之外\n");
            }
            printf("角色屬性:");
            scanf ("%c%*c",&char4_type);
            char4_type=toupper(char4_type);
            printf("血量:");
            scanf ("%d",&char4_hp);
            printf("攻擊:");
            scanf ("%d",&char4_atk);
            printf("防禦:");
            scanf ("%d%*c",&char4_def);
        }
        float char_4 = (char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;
        printf("\n角色4\n名稱：破腦\n");
        printf("屬性： %c  ",char4_type);
        printf("攻擊：%d\n",char4_atk);
        printf("血量：%d  ",char4_hp);
        printf("防禦：%d\n",char4_def);
        printf("角色強度：%.2f\n",char_4);
        printf("選取先攻角色:");
        scanf("%d",&attack1);
        while (attack1>=5||attack1<1) //角色只有1~4  attack範圍  1<= attack <=4
        {
            printf("錯誤:無此角色\n");
            printf("選取先攻角色");
            scanf("%d",&attack1);
        }
        if(attack1<=4||attack1>=1)
        {
            printf("選取後攻角色");
            scanf("%d",&attack2);
            while(attack2>=5||attack2<1)//角色只有1~5  attack範圍  1<= attack <=4
            {
                printf("錯誤:無此角色\n");
                printf("選取後攻角色");
                scanf("%d",&attack2);
            }
            while(attack1==attack2)//角色不能重複
            {
                printf("錯誤:不可重複選取\n");
                printf("選取後攻角色");
                scanf("%d",&attack2);
            }
            while(attack2>=5||attack2<1)//角色只有1~5  attack範圍  1<= attack <=4
            {
                printf("錯誤:無此角色\n");
                printf("選取後攻角色");
                scanf("%d",&attack2);
            }
        }
        if(attack1!=attack2&&attack1>=1&&attack1<=4&&attack2>=1&&attack2<=4)
        {
            printf("先攻角色為%d,後攻角色為%d\n",attack1,attack2);
        }
    }
    if(new_char==2)//不新增角色
    {
        printf("選取先攻角色");
        scanf("%d",&attack1);
        while (attack1>=4||attack1<1) //角色只有1~3  attack範圍  1<= attack <=3
        {
            printf("錯誤:無此角色\n");
            printf("選取先攻角色");
            scanf("%d",&attack1);
        }
        if(attack1<=3||attack1>=1)
        {
            printf("選取後攻角色");
            scanf("%d",&attack2);
            while(attack2>=4||attack2<1)//角色只有1~5  attack範圍  1<= attack <=4
            {
                printf("錯誤:無此角色\n");
                printf("選取後攻角色");
                scanf("%d",&attack2);
            }
            while(attack1==attack2)//角色不能重複
            {
                printf("錯誤:不可重複選取\n");
                printf("選取後攻角色");
                scanf("%d",&attack2);
            }
            while(attack2>=4||attack2<1)//角色只有1~5  attack範圍  1<= attack <=4
            {
                printf("錯誤:無此角色\n");
                printf("選取後攻角色");
                scanf("%d",&attack2);
            }
        }
        if(attack1!=attack2&&attack1>=1&&attack1<=3&&attack2>=1&&attack2<=3)
        {
            printf("先攻角色為%d,後攻角色為%d\n",attack1,attack2);
        }
    }
    printf("戰鬥開始");
    if(attack1==1) //先攻角為角色1的能力值
    {
        attack1_hp=char1_hp;
        attack1_atk=char1_atk;
        attack1_def=char1_def;
    }
    if(attack1==2) //先攻角為角色2的能力值
    {
        attack1_hp=char2_hp;
        attack1_atk=char2_atk;
        attack1_def=char2_def;
    }
    if(attack1==3) //先攻角為角色3的能力值
    {
        attack1_hp=char3_hp;
        attack1_atk=char3_atk;
        attack1_def=char3_def;
    }
    if(attack1==4) //先攻角為角色4的能力值
    {
        attack1_hp=char4_hp;
        attack1_atk=char4_atk;
        attack1_def=char4_def;
    }
    if(attack2==1) //後攻角為角色1的能力值
    {
        attack2_hp=char1_hp;
        attack2_atk=char1_atk;
        attack2_def=char1_def;
    }
    if(attack2==2) //後攻角為角色2的能力值
    {
        attack2_hp=char2_hp;
        attack2_atk=char2_atk;
        attack2_def=char2_def;
    }
    if(attack2==3) //後攻角為角色3的能力值
    {
        attack2_hp=char3_hp;
        attack2_atk=char3_atk;
        attack2_def=char3_def;
    }
    if(attack2==4) //後攻角為角色4的能力值
    {
        attack2_hp=char4_hp;
        attack2_atk=char4_atk;
        attack2_def=char4_def;
    }
    hurt_1=(attack2_atk-attack1_def);
    hurt_2=(attack1_atk-attack2_def);
    while(attack1_hp>0&&attack2_hp>0)  //進入戰鬥
    {
        attack2_hp=attack2_hp-hurt_2;
        printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n",attack1,attack2,hurt_2);
        printf("角色%d HP :%d\n",attack1,attack1_hp);
        printf("角色%d HP :%d\n",attack2,attack2_hp);
        attack1_hp=attack1_hp-hurt_1;
        if(attack2_hp<=0)
        {
            printf("角色%d 失去戰鬥能力\n",attack2);
            printf("戰鬥結束\n");
            printf("角色%d 獲勝",attack1);
            return 0;
        }
        printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n",attack2,attack1,hurt_1);
        printf("角色%d HP :%d\n",attack1,attack1_hp);
        printf("角色%d HP :%d\n",attack2,attack2_hp);
        if(attack1_hp<=0)
        {
            printf("角色%d 失去戰鬥能力\n",attack1);
            printf("戰鬥結束\n");
            printf("角色%d 獲勝",attack2);
            return 0;
        }
    }
}	// 結束的大括號
