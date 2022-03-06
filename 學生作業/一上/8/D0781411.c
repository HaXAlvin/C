#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    //角色 能力 / 姓名 
    char name[200][200] ={"豆豆","薛薛","貓咪"};
    char char_type [5] = {'F','W','G'};
    char counter_type[4] ={'W','F','A','G'};//　W>F>A>G>W 
    int char_hp [5] = {40,50,45};
    int weak_hp [5] = {20,25,22};
    int char_atk [5] = {20,15,15};
    int char_def [5] = {10,5,10};
    double  char_power [5]={0};
    int i=0;//迴圈用的 
    for(i=0;i<4;i++)
    { 
    	char_power [i] = (char_hp[i]*1.0+char_atk[i]*0.8+char_def[i]*0.5-50)*6.5;
    } 
    //角色 能力 / 姓名 
    int attack_first; //先攻角色 
    int attack_second; //後攻角色 
    int attack_first_hp;//先攻角色的生命
    int attack_first_atk;//先攻角色的攻擊
    int attack_first_def;//先攻角色的防禦
    char attack_first_type;//先攻屬性 
    int attack_second_hp;//後攻角色的生命
    int attack_second_atk;//後攻角色的攻擊
    int attack_second_def;//後攻角色的防禦
	char attack_second_type;//後攻屬性	
    int j;//迴圈用我 
    int type_control;//相剋判定用 
    int game_type=1;//你要幹嘛 
    int max_char=3;//角色最大值 
    int attack_first_weak_hp;//先攻角色的虛弱血量 
    int attack_second_weak_hp;//後攻角色的虛弱血量 
    int first_char_hurt;//先攻角色受到的傷害 
    int second_char_hurt;//後攻角色受到的傷害 
    double  attack_first_count=1;//先攻角色打出傷害的count倍率
    double  attack_second_count=1;//後攻角色打出傷害的count倍率
    double  attack_first_weak=1;//先攻角色打出傷害的虛弱倍率  
    double  attack_second_weak=1;//後攻角色打出傷害的虛弱倍率  
    double  first_complex_magnification;//先攻角色被打到的綜合倍率 
    double  second_complex_magnification;//後攻角色被打到的綜合倍率 
    int  damage_first;
    int  damage_second;
    //while大迴圈開始
	//進入遊戲   
    printf("1. 新增或修改角色\n");
    printf("2. 顯示所有角色資料\n");
    printf("3. 戰鬥\n");
    printf("0. 結束遊戲\n");
    printf("請選擇:");
    while(scanf("%d%*c",&game_type)&&game_type!=0)  //是0就結束 
    {
		// 選項1  新增角色 
	    if (game_type==1)
	    {
	    	if(max_char==3)   //沒有新增的角色 
	    	{
	    		printf("\n新增角色\n");
			}
			if(max_char==4)	  //我現在要修改角色 
			{
				printf("修改新增角色\n");
			}
			printf("角色名稱:");   //從這裡開始是新角色的 能力值/ID  還有一些戰鬥用的設定 
	    	gets(name[3]);
	        printf("角色屬性:");
	        scanf ("%c%*c",&char_type[3]);
	        char_type[3]=toupper(char_type[3]);//小寫轉大寫
	        printf("血量:");
	        scanf ("%d",&char_hp[3]);
	        printf("攻擊:");
	        scanf ("%d",&char_atk[3]);
	        printf("防禦:");
	        scanf ("%d%*c",&char_def[3]);
	        while(char_type[3]!=65&&char_type[3]!=70&&char_type[3]!=71&&char_type[3]!=87||char_atk[3]>20||char_atk[3]<15||char_hp[3]>50||char_hp[3]<40||char_def[3]<5||char_def[3]>10||(char_def[3]+char_hp[3]+char_atk[3])>70||(char_def[3]+char_hp[3]+char_atk[3])<65)
	        {
	            if(char_type[3]!=65&&char_type[3]!=70&&char_type[3]!=71&&char_type[3]!=87)
	            {
	                printf("錯誤:無此屬性\n\n");
	            }
	            if(char_atk[3]>20||char_atk[3]<15||char_hp[3]>50||char_hp[3]<40||char_def[3]<5||char_def[3]>10||(char_def[3]+char_hp[3]+char_atk[3])>70||(char_def[3]+char_hp[3]+char_atk[3])<65)
	            {
	                printf("錯誤:能力數值在限制範圍之外\n\n");
	            }
	            printf("角色名稱:");
		    	gets(name[3]);
		        printf("角色屬性:");
		        scanf ("%c%*c",&char_type[3]);
		        char_type[3]=toupper(char_type[3]);//小寫轉大寫
		        printf("血量:");
		        scanf ("%d",&char_hp[3]);
		        printf("攻擊:");
		        scanf ("%d",&char_atk[3]);
		        printf("防禦:");
		        scanf ("%d%*c",&char_def[3]);
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
	        weak_hp [3] = char_hp[3]/2;
		    max_char=4;
	    }
	    //選項2   丟出角色資料 
	    else if(game_type==2)
	    {
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
	    //選項3  戰鬥 
	    //修改點
	    else if(game_type==3)
        {
        	attack_first_count=1; //克制倍率重置 
        	attack_second_weak=1; //虛弱倍率重置 
			attack_first_weak=1;  //虛弱倍率重置 
            printf("\n輸入先攻角色:");  //這裡開始選角色 
            scanf("%d",&attack_first);
            while (attack_first>max_char||attack_first<1) //角色只有1~max_char 角色範圍  1<=角色<=max_char
            {
                printf("錯誤:無此角色\n");
                printf("選取先攻角色");
                scanf("%d",&attack_first);
            }
            if(attack_first<=max_char||attack_first>=1)
            {
                printf("輸入後攻角色");
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
                    printf("輸入後攻角色");
                    scanf("%d", &attack_second);
                }
            }
            //選角結束 
            printf("\n先攻角色為%d,後攻角色為%d\n",attack_first,attack_second);
            printf("戰鬥開始\n\n");
            // 先攻角色能力值 
            attack_first_atk=char_atk[attack_first-1];
            attack_first_hp=char_hp[attack_first-1];
            attack_first_def=char_def[attack_first-1];
            attack_first_type=char_type[attack_first-1];
            attack_first_weak_hp=attack_first_hp/2;
			//後攻角色能力值 
            attack_second_atk=char_atk[attack_second-1];
            attack_second_hp=char_hp[attack_second-1];
            attack_second_def=char_def[attack_second-1];
            attack_second_type=char_type[attack_second-1];
			attack_second_weak_hp=attack_second_hp/2;
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
			} 
			if(counter_type[(type_control+3)%4]==attack_second_type) //後攻克制先攻 
			{
				attack_first_count=0.8;
			}
			attack_second_count=2-attack_first_count; //倍率相加為2 
			//printf("我是先攻的康特倍率: %f\n",attack_first_count);
			//printf("我是後攻的康特倍率: %f\n",attack_second_count);
			//戰鬥環節
			while(attack_first_hp>0&&attack_second_hp>0)
			{
				if(attack_first_hp<attack_first_weak_hp) //當先攻角虛弱時 
				{
					attack_second_weak=1.2;  //後攻角的倍率上升 
					//printf("先攻角色虛弱\n\n");
				}
				if(attack_second_hp<attack_second_weak_hp) //當先攻角虛弱時 
				{
					attack_first_weak=1.2; //先攻角的倍率上升 
					//printf("後攻角色虛弱\n\n");
				}
				first_char_hurt=attack_second_atk*(attack_second_count*attack_second_weak)-attack_first_def;//先攻角色 受到的傷害   這裡不正常  我不是debug用的 
				second_char_hurt=attack_first_atk*(attack_first_count*attack_first_weak)-attack_second_def;//後攻角色 受到的傷害   我不是debug用的  
				//戰鬥時動態數值設定結束
				if(attack_first_hp>0&&attack_second_hp>0)
				{
					attack_second_hp=attack_second_hp-second_char_hurt;
					printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n",attack_first,attack_second,second_char_hurt);
					printf("角色%d HP :%d\n",attack_first,attack_first_hp);
	       		 	printf("角色%d HP :%d\n\n",attack_second,attack_second_hp);
	       		}
       		 	if(attack_second_hp<=0)
        		{
		            printf("角色%d 失去戰鬥能力\n",attack_second);
		            printf("戰鬥結束\n\n");
		            printf("角色%d 獲勝\n\n",attack_first);
        		}
        		
        		if(attack_first_hp>0&&attack_second_hp>0)
				{
					attack_first_hp=attack_first_hp-first_char_hurt;
					printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n",attack_second,attack_first,first_char_hurt);
					printf("角色%d HP :%d\n",attack_first,attack_first_hp);
       		 		printf("角色%d HP :%d\n\n",attack_second,attack_second_hp);
	       		}
  
       		 	if(attack_first_hp<=0&&attack_second_hp>0)
		        {
		            printf("角色%d 失去戰鬥能力\n",attack_first);
		            printf("戰鬥結束\n\n");
		            printf("角色%d 獲勝\n\n",attack_second);
		        }
			} 
        }
	    //選項其他
		else
		{
			printf("\n輸入錯誤!\n");
		}
    	printf("1. 新增或修改角色\n");
		printf("2. 顯示所有角色資料\n");
		printf("3. 戰鬥\n");
		printf("0. 結束遊戲\n");	
		printf("請選擇:");
	}
}	// 結束的大括號
