#include<stdio.h>
#include<string.h>
typedef struct{                                         //人物的能力值 建立結構role 
	char name[100];                                     //名稱 
	char type;                                          //屬性 
	int hp;                                             //血量 
	int atk;                                            //攻擊 
	int def;                                            //防禦 
	float prediction;                                   //強度預測 
}role;
role npc[]={{"星爆氣流",'F',50,10,5},               //人物能力值設定 取名為npc 
	        {"不是不爆",'W',45,15,7},
	        {"十秒未到",'G',40,20,10}};
int num=4;                                          //計算人物有幾隻的變數 
void npc_call(){										//NPC的呼叫 
	int i;
	for(i=0;i<3;i++){
	    npc[i].prediction=	(npc[i].hp*1.0+npc[i].atk*0.8+npc[i].def*0.5-50)*6.5;							
		printf("角色%d\n"
	           "名稱:%s\n"
		       "屬性:%c   攻擊:%d\n"
		       "血量:%d  防禦:%d\n"
			   "強度預測:%0.2f\n\n",i+1,npc[i].name,npc[i].type,npc[i].atk,npc[i].hp,npc[i].def,npc[i].prediction);
	}		   
}
void create(){											//新增角色和賦予能力值 
	int i=num;
	printf("新增角色:\n");	
	printf("屬性:");	 	
	scanf(" %c",&npc[i].type);
	printf("血量:");     	
	scanf("%d",&npc[i].hp);
	printf("攻擊:");  	    
	scanf("%d",&npc[i].atk);
	printf("防禦:");        
	scanf("%d",&npc[i].def);
	num+=1;
}
void create_call(int i){                                //新增角色的呼叫 
    npc[i].prediction=	(npc[i].hp*1.0+npc[i].atk*0.8+npc[i].def*0.5-50)*6.5;
	printf("\n角色%d\n"
	       "名稱:自訂角色\n"
		   "屬性:%c   攻擊:%d\n"
		   "血量:%d  防禦:%d\n"
		   "強度預測:%0.2f\n",i,npc[i].type,npc[i].atk,npc[i].hp,npc[i].def,npc[i].prediction);
}
int main(){
    npc_call();                                         //npc呼叫 
	create();                                           //創立的角色建立 
	create_call(4);                                     //創立的角色呼叫 
	return 0;
} 
