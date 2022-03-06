#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct{                                         //人物的能力值 建立結構role 
	char name[100];                                     //名稱 
	char type;                                          //屬性 
	int hp;                                             //血量 
	int atk;                                            //攻擊 
	int def;                                            //防禦 
	float prediction;                                   //強度預測 
}role;
role npc[100]={{"星爆氣流",'W',50,15,5},               //人物能力值設定 取名為npc 
	          {"不是不爆",'A',40,20,8},
	          {"十秒未到",'G',40,20,10}};
int num=3,first_atk,after_atk;                           //計算人物有幾隻的變數 儲存先攻與後攻的順序 
bool storage[3]={0};                                    //偵測有無錯誤的布林值  storage[2]偵測有沒有被新增過角色 
void npc_call(){										//NPC的呼叫 
	int i;
	for(i=0;i<num;i++){                                    //打印NPC的數值   
	    npc[i].prediction=	(npc[i].hp*1.0+npc[i].atk*0.8+npc[i].def*0.5-50)*6.5;							
		printf("角色%d\n"
	           "名稱:%s\n"
		       "屬性:%c   攻擊:%d\n"
		       "血量:%d  防禦:%d\n"
			   "角色強度預測:%0.2f\n\n",i+1,npc[i].name,npc[i].type,npc[i].atk,npc[i].hp,npc[i].def,npc[i].prediction);
	}		   
}
void type_judgement(int i){                                                                   //屬性判斷 
    if(npc[i].type=='f' || npc[i].type=='w' || npc[i].type=='g' ||npc[i].type=='a')          //如果是f,w,g,a的話，換成F W G A
    	npc[i].type=npc[i].type-' ';
    if(npc[i].type=='F' ^ npc[i].type=='W' ^ npc[i].type=='G' ^ npc[i].type=='A')           //判斷如果不是f,w,g,a,F,W,G,A的話，輸出:錯誤 
    	storage[0]=0;
    else{
    	storage[0]=1;
 		printf("錯誤:無此屬性\n");
    }
}
void ability_judge(int i){                               //判斷新增角色是不是在能力值範圍以內 
	int sum;
	storage[1]=0;
	sum=npc[i].hp+npc[i].atk+npc[i].def;
	if(npc[i].hp <40 || npc[i].hp > 50)                       //角色的血量要在 40~50  
		storage[1]=1;
	else if(npc[i].atk < 15 || npc[i].atk > 20)               //角色的攻擊要在 15~20 
		storage[1]=1;
	else if(npc[i].def < 5 || npc[i].def > 10)                //角色的防禦要在 5~10  
		storage[1]=1;
	else if(sum<65 || sum>70)                                 //角色的能力值總和要在65~70 
		storage[1]=1;
	if(storage[1]==true)
    	printf("錯誤:能力數值在限制範圍之外\n");
}
void create(){										//新增角色和賦予能力值 
	num=3;
	int i=num;
	if(storage[2]==0)                               //判斷有沒有新增過角色 
		printf("新增角色\n");
	else
		printf("修改新增角色\n");
	printf("名稱:");
	scanf("%s",&npc[i].name);
	printf("屬性:");
	scanf("%*c%c",&npc[i].type);
	printf("血量:");     	
	scanf("%d",&npc[i].hp);
	printf("攻擊:");  	    
	scanf("%d",&npc[i].atk);
	printf("防禦:");        
	scanf("%d",&npc[i].def);
	type_judgement(i);
	ability_judge(i);
	if(storage[0] == true ||storage[1] == true)          //利用storage[]來驗證有無錯誤  錯誤時再呼叫create函數 
		create();
	else{
		storage[2]=1; 
		num=4;
	} 
}
void choice_atk_role(){                                 //選擇角色先攻，後攻 
	printf("選擇先攻角色:");
	scanf("%d",&after_atk);
	first_atk=after_atk;
	if(after_atk > 0 && after_atk <= num){                  //判斷先攻有無超過範圍  
		while(1){
			printf("選擇後攻角色:");
			scanf("%d",&after_atk);
			if(after_atk > 0 && after_atk <= num && after_atk!=first_atk){          //判斷後攻有無超過範圍 
				printf("\n先攻角色為%d、後攻角色為%d\n",first_atk,after_atk);
				break;	
			}
			else if( after_atk <= 0 || after_atk > num){
				printf("錯誤:無此角色\n");
			}
			else{
				printf("錯誤:不可重複選取\n");
			}
		}
	}
	else{
		printf("錯誤:無此角色\n");
		choice_atk_role();
	}
}
void create_call(int i){                                //新增角色的呼叫 
    npc[i].prediction=	(npc[i].hp*1.0+npc[i].atk*0.8+npc[i].def*0.5-50)*6.5;
	printf("\n角色%d\n"
	       "名稱:%s\n"
		   "屬性:%c   攻擊:%d\n"
		   "血量:%d  防禦:%d\n"
		   "角色強度預測:%0.2f\n\n",i+1,npc[i].name,npc[i].type,npc[i].atk,npc[i].hp,npc[i].def,npc[i].prediction);
}
void pvp(int first_atk,int after_atk,int hp_1,int hp_2,char type_1,char type_2){               //單挑 pvp的呼叫 
	printf("戰鬥開始\n");
	int damage,status=0;                                                        				//儲存傷害的變數 
	if((type_1 =='W' && type_2 == 'F'))          				//如果status變為1或2的話 代表角色有被相剋 
		status=1;
	else if((type_1 == 'F' && type_2 == 'W'))
		status=2;
	else if((type_1 =='F' && type_2 == 'A'))
		status=1;
	else if((type_1 == 'A' && type_2 == 'F'))
		status=2;
	else if((type_1 =='A' && type_2 == 'G'))
		status=1;
	else if((type_1 == 'G' && type_2 == 'A'))
		status=2;
	else if((type_1 =='G' && type_2 == 'W'))
		status=1;
	else if((type_1 == 'W' && type_2 == 'G'))
		status=2;
	while(hp_1 > 0){                                                   //如果先攻的血量沒有大於0時 跳出迴圈
		if(status == 1){
			damage=npc[first_atk-1].atk*1.2-npc[after_atk-1].def;
			if(hp_1 < npc[first_atk-1].hp/2){
				damage=npc[first_atk-1].atk*1.2*1.2-npc[after_atk-1].def;
			}
		}
		else if(status ==2){
			damage=npc[first_atk-1].atk*0.8-npc[after_atk-1].def;
			if(hp_1 < npc[first_atk-1].hp/2){
				damage=npc[first_atk-1].atk*0.8*1.2-npc[after_atk-1].def;
			}
		}
		else{
			damage=npc[first_atk-1].atk-npc[after_atk-1].def;
			if(hp_1 < npc[first_atk-1].hp/2){
				damage=npc[first_atk-1].atk*1.2-npc[after_atk-1].def;
			}
		}
		hp_2-=damage;
		printf("\n角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n"
			   "角色%d HP: %d  角色%d HP: %d\n",first_atk,after_atk,damage,first_atk,hp_1,after_atk,hp_2);
		if(hp_2 < 0)                                                   //如果後攻的血量小於0 就break 
			break;
		if(status == 1){
			damage=npc[after_atk-1].atk*0.8-npc[first_atk-1].def;
			if(hp_2 < npc[after_atk-1].hp/2){
				damage=npc[after_atk-1].atk*0.8*1.2-npc[first_atk-1].def;
			}
		}
		else if(status == 2){
			damage=npc[after_atk-1].atk*1.2-npc[first_atk-1].def;
			if(hp_2 < npc[after_atk-1].hp/2){
				damage=npc[after_atk-1].atk*1.2*1.2-npc[first_atk-1].def;
			}
		}
		else{
			damage=npc[after_atk-1].atk-npc[first_atk-1].def;
			if(hp_2 < npc[after_atk-1].hp/2){
				damage=npc[after_atk-1].atk*1.2-npc[first_atk-1].def;
			}
		}		
		hp_1-=damage;
		printf("\n角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n"
			   "角色%d HP: %d  角色%d HP: %d\n",after_atk,first_atk,damage,first_atk,hp_1,after_atk,hp_2);
	}
	if(hp_1 < 0){
		printf("\n角色%d 失去戰鬥能力\n"
			   "戰鬥結束\n"
			   "\n角色%d獲勝\n\n",first_atk,after_atk);
	}
	else{
		printf("\n角色%d 失去戰鬥能力\n"
			   "戰鬥結束\n"
			   "\n角色%d獲勝\n\n",after_atk,first_atk);
	}
}
int main(){
	int number;
	do{
		printf("1. 新增或修改新增角色\n"
			   "2. 顯示所有角色資料\n"
   			   "3. 戰鬥\n"
   			   "0. 結束遊戲\n"
			   "請選擇:");
		scanf("%d",&number);
		printf("\n");
		switch(number){
			case 1:
				create();																										//角色新增的呼叫 
				create_call(num-1);																								//角色新增後顯示能力的呼叫 
				break;
			case 2:
				npc_call();																										 //顯示角色資料的呼叫 
				break;
			case 3:
				choice_atk_role();																								  //選擇先攻或後攻的呼叫	
				pvp(first_atk,after_atk,npc[first_atk-1].hp,npc[after_atk-1].hp,npc[first_atk-1].type,npc[after_atk-1].type);     //pvp單挑模式的呼叫
				break;
			case 0:
				break;
			default:
				printf("輸入錯誤!\n\n"); 
		}
	}while(number!=0);                                                             //如果是0的話 跳出while 結束遊戲 
	printf("結束遊戲\n");                                              
	 
	return 0;
} 
