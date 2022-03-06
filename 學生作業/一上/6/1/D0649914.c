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
role npc[]={{"星爆氣流",'F',48,17,5},               //人物能力值設定 取名為npc
	        {"不是不爆",'W',45,15,7},
	        {"十秒未到",'G',40,20,10}};
int num=3,first_atk,after_atk;                                          //計算人物有幾隻的變數 儲存先攻與後攻的順序
bool storage[2];                                    //偵測有無錯誤的布林值
void npc_call(){										//NPC的呼叫
	int i;
	for(i=0;i<3;i++){                                    //打印NPC的數值
	    npc[i].prediction=	(npc[i].hp*1.0+npc[i].atk*0.8+npc[i].def*0.5-50)*6.5;
		printf("角色%d\n"
	           "名稱:%s\n"
		       "屬性:%c   攻擊:%d\n"
		       "血量:%d  防禦:%d\n"
			   "強度預測:%0.2f\n\n",i+1,npc[i].name,npc[i].type,npc[i].atk,npc[i].hp,npc[i].def,npc[i].prediction);
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
void create(){											//新增角色和賦予能力值
	int i=num;
	printf("\n新增角色\n");
	printf("屬性:");
	scanf(" %c",&npc[i].type);
	printf("血量:");
	scanf("%d",&npc[i].hp);
	printf("攻擊:");
	scanf("%d",&npc[i].atk);
	printf("防禦:");
	scanf("%d",&npc[i].def);
	type_judgement(i);
	ability_judge(i);
	if(storage[0] == true ||storage[1] == true)          //利用storage[]來驗證有無錯誤  錯誤時再呼叫create函數
	create(i);
	else
	num+=1;
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
	       "名稱:自訂角色\n"
		   "屬性:%c   攻擊:%d\n"
		   "血量:%d  防禦:%d\n"
		   "強度預測:%0.2f\n",i+1,npc[i].type,npc[i].atk,npc[i].hp,npc[i].def,npc[i].prediction);
}
void preparation_of_war(){								//預備戰鬥的函數
	int whether;
    npc_call();                                         //npc呼叫
    while(1){
    printf("是否新增角色(1.YES/2.NO)? ");
    scanf("%d",&whether);
	if(whether==1){
		create();                                           //創立的角色建立
	if(storage[0]==false && storage[1]==false){
		create_call(num-1);                                 //創立的角色呼叫
		printf("\n");
		choice_atk_role();                                  //選擇角色先攻，後攻的呼叫
		break;
		}
	}
    else if(whether==2){									//選擇角色先攻，後攻的呼叫
    	choice_atk_role();
    	break;
    }
	else
	printf("輸入錯誤\n");
	}
}
void pvp(int first_atk,int after_atk,int hp_1,int hp_2){               //單挑 pvp的呼叫
	printf("戰鬥開始\n");
	int damage;                                                        //儲存傷害的變數
	while(hp_1 > 0){                                                   //如果先攻的血量沒有大於0時 跳出迴圈
		damage=npc[first_atk-1].atk-npc[after_atk-1].def;
		hp_2-=damage;
		printf("\n角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n"
			   "角色%d HP: %d  角色%d HP: %d\n",first_atk,after_atk,damage,first_atk,hp_1,after_atk,hp_2);
		if(hp_2 < 0)                                                   //如果後攻的血量小於0 就break
			break;
		damage=npc[after_atk-1].atk-npc[first_atk-1].def;
		hp_1-=damage;
		printf("\n角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n"
			   "角色%d HP: %d  角色%d HP: %d\n",after_atk,first_atk,damage,first_atk,hp_1,after_atk,hp_2);
	}
	if(hp_1 < 0){
		printf("\n角色%d 失去戰鬥能力\n"
			   "戰鬥結束\n"
			   "\n角色%d獲勝\n",first_atk,after_atk);
	}
	else{
		printf("\n角色%d 失去戰鬥能力\n"
			   "戰鬥結束\n"
			   "\n角色%d獲勝\n",after_atk,first_atk);
	}
}
int main(){
	preparation_of_war();                                                 //pvp的事前準備的呼叫
	pvp(first_atk,after_atk,npc[first_atk-1].hp,npc[after_atk-1].hp);     //pvp單挑模式的呼叫
	return 0;
}
