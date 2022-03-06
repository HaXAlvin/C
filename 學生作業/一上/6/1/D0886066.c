#include<stdio.h>
#include<stdlib.h>
int main(){
	//角色一變數宣告 
	char char1_type = 'F';
    int char1_hp = 45;
	int char1_atk = 20;
	int char1_def = 5; 
	//角色二變數宣告 
	char char2_type = 'W';
    int char2_hp = 40;
	int char2_atk = 15;
	int char2_def = 10;
	//角色三變數宣告
	char char3_type = 'A';
    int char3_hp = 45;
	int char3_atk = 15;
	int char3_def = 10;
	//角色四變數宣告
	char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
	//先攻 後攻 的相關屬性
	int firstone_atk;
	int firstone_hp;
	int firstone_def;
	int lastone_atk;
	int lastone_hp;
	int lastone_def;
    //前三個的角色強度預測
    int power1 = (char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5 - 50 ) * 6.5;
    int power2 = (char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5 - 50 ) * 6.5;
    int power3 = (char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5 - 50 ) * 6.5;
	//角色一資訊     
    printf("角色1\n名稱:瑞斯叔叔\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char1_type,char1_atk,char1_hp,char1_def,power1);
    //角色二資訊
    printf("\n角色2\n名稱:幸福教主刮哥\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char2_type,char2_atk,char2_hp,char2_def,power2);
    //角色三資訊
    printf("\n角色3\n名稱:垃圾車\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char3_type,char3_atk,char3_hp,char3_def,power3); 
    printf("\n");
    inthebeginning:
     //判斷是否新增第四個角色 
	printf("是否新增角色(1.Yes/2.No)?");
	int whethertrue;
	scanf("%d",&whethertrue);
	//先攻 
	int firstone;
	//後攻 
	int lastone;
	//角色輸入屬性flag
	int attributes_true = 1;
	//存取資料用到的變數
	int data_hp,data_atk,data_def,data_line; 
	//血量、攻擊、防禦、綜合屬性輸入flag
	int mix_true = 1 , hp_true = 1 , atk_true = 1 , def_true = 1 , happening = 1;	
	if(whethertrue == 1){ 
		do{
			//輸出錯誤訊息 並要求重新輸入數值 
			if(attributes_true == 0){
				printf("錯誤 : 無此屬性\n");
			}
			if(mix_true + hp_true + atk_true + def_true!= 4){
				printf("錯誤 : 能力數值在範圍之外\n");
			}
			//新增角色相關素質 
    		printf("\n新增角色\n屬性:");
    		scanf(" %c",&char4_type);
    		printf("血量:");
    		scanf("%d",&char4_hp);
    		printf("攻擊:");
    		scanf("%d",&char4_atk);
    		printf("防禦:");
    		scanf("%d",&char4_def);
    		//屬性大小寫問題 利用flag判斷是否重新輸入 
	    	if(char4_type == 'f'){
	    		char4_type = 'F';
	    		attributes_true = 1;
			}else if(char4_type == 'w'){
				char4_type = 'W';
				attributes_true = 1;
			}else if(char4_type == 'g'){
				char4_type = 'G';
				attributes_true = 1;
			}else if(char4_type == 'a'){
				char4_type = 'A';
				attributes_true = 1;
			}else if(char4_type == 'F'){
				char4_type = 'F';
				attributes_true = 1;
			}else if(char4_type == 'W'){
				char4_type = 'W';
				attributes_true = 1;
			}else if(char4_type == 'G'){
				char4_type = 'G';
				attributes_true = 1;
			}else if(char4_type == 'A'){
				char4_type = 'A';
				attributes_true = 1;
			}else{
				attributes_true = 0;
			}
			//角色素質是否皆在值域內 利用flag判斷是否重新輸入 
			if((char4_hp < 40)||(char4_hp > 50)){
	    		hp_true = 0;
			}else if((char4_hp >= 40)&&(char4_hp <= 50)){
				hp_true = 1;
			}
			if((char4_atk < 15)||(char4_atk > 20)){
	    		atk_true = 0;
			}else if((char4_atk >= 15)&&(char4_atk <= 20)){
	    		atk_true = 1;
			}
			if((char4_def >= 5)&&(char4_def <= 10)){
				def_true = 1;
			}else if((char4_def < 5)||(char4_def > 10)){
	    		def_true = 0;
			}
			if(((char4_hp + char4_atk + char4_def)>=65)||((char4_hp + char4_atk + char4_def)<=70)){
				mix_true = 1;
			}else if(((char4_hp + char4_atk + char4_def)<65)||((char4_hp + char4_atk + char4_def)>70)){
				mix_true = 0;
			}
		}while((attributes_true == 0)|(mix_true + hp_true + atk_true + def_true != 4));
   	    //自訂角色的強度預測
    	int power4=(char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5 - 50 ) * 6.5;
    	//角色四資訊 
    	printf("\n角色4\n名稱:自訂角色\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char4_type,char4_atk,char4_hp,char4_def,power4);
    	//攻擊順序決定 
		//選擇的人 是否符合題目所說(先攻、後攻，是否重複選取)
		printf("\n");
		first1_choose:
		compare1_choose:
    	printf("選擇先攻角色 : ");
		scanf("%d",&firstone);
		while((firstone>4)||(firstone<1)){
			printf("錯誤 : 無此角色\n");
			goto first1_choose;
		}
		while((firstone<=4)&&(firstone>=1)){
			last1_choose:
			printf("選擇後攻角色 : ");
			scanf("%d",&lastone);
			if((lastone>4)||(lastone<1)){
				printf("錯誤 : 無此角色\n");
				goto last1_choose;
			}else if((lastone<=4)&&(lastone>=1)){
				if(firstone == lastone){
					printf("錯誤 : 不可重複選取\n");
					goto compare1_choose;
				}else{
					printf("\n先攻為角色%d、後攻為角色%d\n戰鬥開始\n\n" , firstone , lastone);
					if(firstone==1){
						firstone_hp = char1_hp;
						firstone_atk = char1_atk;
						firstone_def = char1_def;
					}else if(firstone==2){
			 			firstone_hp = char2_hp;
						firstone_atk = char2_atk;
						firstone_def = char2_def;
					}else if(firstone==3){
						firstone_hp = char3_hp;
						firstone_atk = char3_atk;
						firstone_def = char3_def;
					}else if(firstone==4){
						firstone_hp = char4_hp;
						firstone_atk = char4_atk;
						firstone_def = char4_def;
					}
             		if(lastone==1){
					 	lastone_hp = char1_hp;
						lastone_atk = char1_atk;
						lastone_def = char1_def;
					}else if(lastone==2){
						lastone_hp = char2_hp;
						lastone_atk = char2_atk;
						lastone_def = char2_def;
					}else if(lastone==3){
						lastone_hp = char3_hp;
						lastone_atk = char3_atk;
						lastone_def = char3_def;
					}else if(lastone==4){
						lastone_hp = char4_hp;
						lastone_atk = char4_atk;
						lastone_def = char4_def;
					}
					do{                                
             		  	printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n" , firstone , lastone , (firstone_atk - lastone_def));
         			  	lastone_hp = lastone_hp - (firstone_atk - lastone_def);
      				  	printf("角色%d HP: %d 角色%d HP:%d\n\n", firstone , firstone_hp , lastone , lastone_hp);
      				  		if(firstone_hp <= 0){
         						printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n", firstone , lastone);
         						return 0;
         					}
							if(lastone_hp <= 0){
       							printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n", lastone , firstone);
       							return 0;
							}
           				printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", lastone , firstone , (lastone_atk - firstone_def));
          				firstone_hp = firstone_hp - (lastone_atk - firstone_def);
        				printf("角色%d HP: %d 角色%d HP:%d\n\n", firstone , firstone_hp , lastone , lastone_hp);
        					if(firstone_hp <= 0){
         						printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n", firstone , lastone);
         						return 0;
         					}
       						if(lastone_hp <= 0){
       							printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n", lastone , firstone);
       							return 0;
							}
					}while((firstone_hp>=0)&&(lastone_hp>=0));
				}
			}
		}
	}else if(whethertrue == 2){
    	//攻擊順序決定 
		//選擇的人 是否符合題目所說(先攻、後攻，是否重複選取)
		printf("\n");
		first2_choose:
		compare2_choose:
    	printf("選擇先攻角色 : ");
		scanf("%d",&firstone);
		while((firstone>3)||(firstone<1)){
			printf("錯誤 : 無此角色\n");
			goto first2_choose;
		}
		while((firstone<=3)&&(firstone>=1)){
			last2_choose:
			printf("選擇後攻角色 : ");
			scanf("%d",&lastone);
			if((lastone>3)||(lastone<1)){
				printf("錯誤 : 無此角色\n");
				goto last2_choose;
			}else if((lastone<=3)&&(lastone>=1)){
				if(firstone == lastone){
					printf("錯誤 : 不可重複選取\n");
					goto compare2_choose;
				}else{
					printf("\n先攻為角色%d、後攻為角色%d\n戰鬥開始\n\n" , firstone , lastone);
					if(firstone==1){
						firstone_hp = char1_hp;
						firstone_atk = char1_atk;
						firstone_def = char1_def;
					}else if(firstone==2){
			 			firstone_hp = char2_hp;
						firstone_atk = char2_atk;
						firstone_def = char2_def;
					}else if(firstone==3){
						firstone_hp = char3_hp;
						firstone_atk = char3_atk;
						firstone_def = char3_def;
					}
             		if(lastone==1){
					 	lastone_hp = char1_hp;
						lastone_atk = char1_atk;
						lastone_def = char1_def;
					}else if(lastone==2){
						lastone_hp = char2_hp;
						lastone_atk = char2_atk;
						lastone_def = char2_def;
					}else if(lastone==3){
						lastone_hp = char3_hp;
						lastone_atk = char3_atk;
						lastone_def = char3_def;
					}
					do{                                
             			printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n" , firstone , lastone , (firstone_atk - lastone_def));
         				lastone_hp = lastone_hp - (firstone_atk - lastone_def);
      					printf("角色%d HP: %d 角色%d HP:%d\n\n", firstone , firstone_hp , lastone , lastone_hp);
      					  	if(firstone_hp <= 0){
         						printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n", firstone , lastone);
         						return 0;
         					}
							if(lastone_hp <= 0){
       							printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n", lastone , firstone);
       							return 0;
							}
           				printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", lastone , firstone , (lastone_atk - firstone_def));
          				firstone_hp = firstone_hp - (lastone_atk - firstone_def);
        				printf("角色%d HP: %d 角色%d HP:%d\n\n", firstone , firstone_hp , lastone , lastone_hp);
        					if(firstone_hp <= 0){
         						printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n", firstone , lastone);
         						return 0;
         					}
       						if(lastone_hp <= 0){
       							printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n", lastone , firstone);
       							return 0;
							}
					}while((firstone_hp>=0)&&(lastone_hp>=0));
				}
			}
		}
	}else{
		printf("輸入錯誤\n");
		goto inthebeginning;
	}
    return 0;
}

