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
role npc[]={{"星爆氣流",'F',50,10,5},               //人物能力值設定 取名為npc
	        {"不是不爆",'W',45,15,7},
	        {"十秒未到",'G',40,20,10}};
int num=4;                                          //計算人物有幾隻的變數
bool storage[2];                                    //偵測有無錯誤的布林值
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
	sum=npc[i].hp+npc[i].atk+npc[i].def;
	if(sum<65 || sum>70){
        storage[1]=1;
        printf("錯誤:能力數值在限制範圍之外\n");
    }
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
	num+=1;
}
void choice_atk_role(){                                 //選擇角色先攻，後攻
	int role,repeat;
	printf("\n選擇先攻角色:");
	scanf("%d",&role);
	repeat=role;
	if(role>0 && role<num){
		printf("選擇後攻角色:");
		scanf("%d",&role);
		if(role>0 && role<num && role!=repeat)
			printf("\n先攻角色為:%d、後攻角色為:%d\n",repeat,role);
		else if(role<=0 || role>=num)
			printf("錯誤:無此角色\n");
		else
			printf("錯誤:不可重複選取\n");
	}
	else
		printf("錯誤:無此角色\n");
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
	int whether;
    npc_call();                                         //npc呼叫
    printf("是否新增角色(1.YES/2.NO)? ");
    scanf("%d",&whether);
	if(whether==1){
		create();                                           //創立的角色建立
        if(storage[0]==false && storage[1]==false){
            create_call(num-1);                                 //創立的角色呼叫
            printf("\n");
            choice_atk_role();                                  //選擇角色先攻，後攻的呼叫
        }
	}
    else if(whether==2)										//選擇角色先攻，後攻的呼叫
    	choice_atk_role();
	else
        printf("輸入錯誤\n");

	return 0;
}
