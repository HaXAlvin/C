#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void EditNewChar (char name[200][200],char char_type[],int char_hp[],int char_atk[],int char_def[])//選項1  新增/新增修改角色
{
	int sum=0;//攻擊,防禦,血量 總和
	int max_char=3;//角色數
	float char_power[10]={0};//角色強度
	int i;
	if(char_hp[3]!=0)//判斷有沒有角色4
	{
		max_char=4;
	}
	if(max_char==3)   //沒有角色4
    {
    	printf("\n新增角色\n");
	}
	if(max_char==4)	  //修改角色
	{
		printf("\n修改新增角色\n");
	}
	printf("角色名稱:");   //從這裡開始是新角色的 能力值/ID  還
    gets(name[3]);
    printf("角色屬性 (F,W,G,A):");
    scanf ("%c%*c",&char_type[3]);
    char_type[3]=toupper(char_type[3]);//小寫轉大寫
    printf("血量(40-50):");
    scanf ("%d",&char_hp[3]);
    printf("攻擊(15-20):");
    scanf ("%d",&char_atk[3]);
    printf("防禦(5-10):");
    scanf ("%d%*c",&char_def[3]);
    sum=char_hp[3]+char_atk[3]+char_def[3];
	while(char_type[3]!='F'&&char_type[3]!='W'&&char_type[3]!='G'&&char_type[3]!='A'||char_atk[3]>20||char_atk[3]<15||char_hp[3]>50||char_hp[3]<40||char_def[3]<5||char_def[3]>10||sum>70||sum<65)
	{
		if(char_type[3]!='F'&&char_type[3]!='W'&&char_type[3]!='G'&&char_type[3]!='A')
	    {
	    	printf("錯誤:無此屬性\n\n");
	    }
	    if(char_atk[3]>20||char_atk[3]<15||char_hp[3]>50||char_hp[3]<40||char_def[3]<5||char_def[3]>10||sum>70||sum<65)
	    {
	        printf("錯誤:能力數值在限制範圍之外\n\n");
	    }
	    printf("角色名稱:");
		gets(name[3]);
		printf("角色屬性:");
		scanf ("%c",&char_type[3]);
		char_type[3]=toupper(char_type[3]);//小寫轉大寫
		printf("血量(40-50):");
		scanf ("%d",&char_hp[3]);
		printf("攻擊(15-20):");
		scanf ("%d",&char_atk[3]);
		printf("防禦(5-10):");
		scanf ("%d",&char_def[3]);
	}
	printf("\n");
	char_power [3] = (char_hp[3]*1.0+char_atk[3]*0.8+char_def[3]*0.5-50)*6.5;
	for(i=3;i<=3;i++)
	{
	   	printf("角色%d\n",i+1);
	    printf("名稱:%s\n",name[i]);
	   	printf("屬性:%c    攻擊:%d\n",char_type[i],char_atk[i]);
		printf("血量:%d   防禦:%d\n",char_hp[i],char_def[i]);
	    printf("角色強度:%.2f\n\n",char_power[i]);
	}
}


void PrintCharData(char name[200][200],char char_type[],int char_hp[],int char_atk[],int char_def[])//選項2 丟出東西
{
    int i=0;//迴圈用的
    int max_char;//有多少角色
	max_char=3;
    double char_power[5]={0}; //角色強度
	if(char_atk[3]!=0)
	{
		max_char=4;
	}
    for(i=0;i<max_char;i++)
    {
    	char_power [i] = (char_hp[i]*1.0+char_atk[i]*0.8+char_def[i]*0.5-50)*6.5;
    }
	printf("\n");
	for(i=0;i<max_char;i++)
	{
	    printf("角色%d\n",i+1);
	    printf("名稱:%s\n",name[i]);
	 	printf("屬性:%c    攻擊:%d\n",char_type[i],char_atk[i]);
	 	printf("血量:%d   防禦:%d\n",char_hp[i],char_def[i]);
	    printf("角色強度:%.2f\n\n",char_power[i]);
	}
}

void Battling(int attack_first,int attack_second,double attack_data[2][6],int char_hp[])//戰鬥
{
	int attack_char[2]={attack_first,attack_second};
	int change;
	int a1;
	int a2;
    //戰鬥 ~  每攻擊一次算一回合 每回合攻擊的人只打一次
    a1=0;
    a2=1;
    while(attack_data[0][0]>0&&attack_data[1][0]>0)//判斷雙方血量，來決定是否繼續迴圈
	{
        attack_data[0][5]=(int)(attack_data[0][1]*attack_data[0][3]*attack_data[0][4]-attack_data[1][2]);//設定先攻攻擊
        attack_data[1][5]=(int)(attack_data[1][1]*attack_data[1][3]*attack_data[1][4]-attack_data[0][2]);//設定後攻攻擊
        attack_data[a2][0]=attack_data[a2][0]-attack_data[a1][5];//防守方hp=防守方hp-攻擊方atk
        printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n角色%d HP: %d \n角色%d HP: %d\n\n",attack_char[a1],attack_char[a2],(int)attack_data[a1][5],attack_first,(int)attack_data[0][0],attack_second,(int)attack_data[1][0]);
        //殘血倍率檢查
        if(char_hp[attack_first-1]/2>attack_data[0][0])//先攻血量小於原本的50%時殘血倍率為1.2倍
        {
            attack_data[1][4]=1.2;
            //printf("先攻虛弱~\n\n");
        }
        if(char_hp[attack_second-1]/2>attack_data[1][0])//後攻血量小於原本的50%
        {
            attack_data[0][4]=1.2;
            //printf("後攻虛弱~\n\n");
        }
        //攻守交換
        change=a1;
        a1=a2;
        a2=change;
    }

    if(attack_data[1][0]<=0)
    {
        printf("角色%d 失去戰鬥能力\n",attack_second);
        printf("戰鬥結束\n\n");
        printf("角色%d 獲勝\n\n",attack_first);
    }

    else
    {
        printf("角色%d 失去戰鬥能力\n",attack_first);
        printf("戰鬥結束\n\n");
        printf("角色%d 獲勝\n\n",attack_second);
    }
}

void SelectAndBattle(char char_type[],int char_hp[],int char_atk[],int char_def[],int attack_first,int attack_second)//選角
{
	double attack_first_count=1;
	double attack_second_count=1;
	int attack_second_weak=1;
	int attack_first_weak=1;
	char counter_type[4] ={'W','F','A','G'};//　W>F>A>G>W
	int type_control;
	int max_char;
	int first_char_hurt;
	int second_char_hurt;
	max_char=3;
	if(char_atk[3]!=0)
	{
		max_char=4;
	}
	printf("\n輸入先攻角色:");  //這裡開始選角色
    scanf("%d",&attack_first);
    while (attack_first>max_char||attack_first<1) //角色只有1~max_char 角色範圍  1<=角色<=max_char
    {
        printf("錯誤:無此角色\n");
        printf("選取先攻角色:");
        scanf("%d",&attack_first);
    }
    if(attack_first<=max_char||attack_first>=1)
    {
        printf("輸入後攻角色:");
        scanf("%d",&attack_second);
        while(attack_first==attack_second||attack_second>max_char||attack_second<1)//角色只有1~max_char 角色範圍  1<=角色<=max_char
        {
            if(attack_first==attack_second)
            {
               printf("錯誤:不可重複選取\n");
            }
            if(attack_second>max_char||attack_second<1)
            {
                printf("錯誤:無此角色\n");
            }
            printf("輸入後攻角色:");
            scanf("%d", &attack_second);
        }
    }
	// 先攻角色能力值
    int attack_first_atk=char_atk[attack_first-1];
    int attack_first_hp=char_hp[attack_first-1];
    int attack_first_def=char_def[attack_first-1];
    int attack_first_type=char_type[attack_first-1];
    int attack_first_weak_hp=attack_first_hp/2;
	//後攻角色能力值
    int attack_second_atk=char_atk[attack_second-1];
    int attack_second_hp=char_hp[attack_second-1];
    int attack_second_def=char_def[attack_second-1];
    int attack_second_type=char_type[attack_second-1];
	int attack_second_weak_hp=attack_second_hp/2;
	// 能力值(相剋)
    if(attack_first_type=='W')
    {
       	type_control=0;
	}
	if(attack_first_type=='F')
    {
   		type_control=1;
	}
	if(attack_first_type=='A')
    {
       	type_control=2;
	}
	if(attack_first_type=='G')
    {
       	type_control=3;
	}
	if(counter_type[(type_control+1)%4]==attack_second_type) //先攻克制後攻   記得倍率重置
	{
		attack_first_count=1.2;
		//printf("先攻克制後攻\n");
	}
	if(counter_type[(type_control+3)%4]==attack_second_type) //後攻克制先攻
	{
		attack_first_count=0.8;
		//printf("後攻克制先攻\n");
	}
	attack_second_count=2-attack_first_count; //倍率相加為2
	//printf("我是先攻的康特倍率: %f\n",attack_first_count);
	//printf("我是後攻的康特倍率: %f\n",attack_second_count);
	//戰鬥環節

	first_char_hurt=attack_second_atk*(attack_second_count*attack_second_weak)-attack_first_def;//先攻角色 受到的傷害   這裡不正常  我不是debug用的
	second_char_hurt=attack_first_atk*(attack_first_count*attack_first_weak)-attack_second_def;//後攻角色 受到的傷害   我不是debug用的
	// 以下是攻擊數據//
	//attack_data[2][6]:先攻資料(第一列):hp、atk、def、先攻角打後攻角的相剋倍率、先攻角打後攻角的殘血倍率、先攻角下個回合受到傷害
    //                  後攻資料(第二列):hp、atk、def、後攻角打先攻角的相剋倍率、後攻角打先攻角的殘血倍率、後攻角下個回合受到傷害
	double attack_data[2][6]={{attack_first_hp,attack_first_atk,attack_first_def,attack_first_count,1,first_char_hurt},
                              {attack_second_hp,attack_second_atk,attack_second_def,attack_second_count,1,second_char_hurt}};
    //選角結束
    printf("\n先攻角色為%d,後攻角色為%d\n",attack_first,attack_second);
    printf("戰鬥開始\n\n");
    Battling(attack_first, attack_second, attack_data, char_hp);
}


int main()//主程式
{
    //角色 能力 / 姓名
    int game_type=1;
    int attack_first;
    int attack_second;
    char name[200][200] ={"豆豆","薛薛","貓咪"};
    char char_type [5] = {'F','W','G',' '};
    char counter_type[4] ={'W','F','A','G'};//　W>F>A>G>W
    int char_hp [5] = {40,50,45,0};
    int char_atk [5] = {20,15,15,0};
    int char_def [5] = {10,5,10,0};
	//進入遊戲
	while(game_type!=0)
	{
        printf("1. 新增或修改角色\n");
		printf("2. 顯示所有角色資料\n");
		printf("3. 戰鬥\n");
		printf("0. 結束遊戲\n");
		printf("請選擇:");
        scanf("%d%*c",&game_type);
        if(game_type==1) //新增或修改角色
		{
            EditNewChar(name,char_type,char_hp,char_atk,char_def);
        }
        else if(game_type==2) //丟出角色
		{
            PrintCharData(name,char_type,char_hp,char_atk,char_def);
        }
        else if(game_type==3) //戰鬥
		{
            SelectAndBattle(char_type,char_hp,char_atk,char_def,attack_first,attack_second);
        }
        else if(game_type!=0)//選項其他
		{
           printf("\n輸入錯誤!\n");
    	}
	}
	printf("\n結束遊戲\n");
}

















