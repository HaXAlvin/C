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
    
    //前三個的角色強度預測
    int power1=(char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5 - 50 ) * 6.5;
    int power2=(char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5 - 50 ) * 6.5;
    int power3=(char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5 - 50 ) * 6.5;
    
	//角色一資訊     
    printf("角色1\n名稱:瑞斯叔叔\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char1_type,char1_atk,char1_hp,char1_def,power1);
    //角色二資訊
    printf("\n角色2\n名稱:幸福教主刮哥\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char2_type,char2_atk,char2_hp,char2_def,power2);
    //角色三資訊
    printf("\n角色3\n名稱:垃圾車\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char3_type,char3_atk,char3_hp,char3_def,power3);
    //判斷是否新增第四個角色 
	printf("\n是否新增角色(1.Yes/2.No)?");
	int whethertrue;
	scanf(" %d",&whethertrue);
	//先攻 
	int firstone;
	//後攻 
	int lastone;	
	if(whethertrue == 1){
    	//新增角色相關素質 
    	printf("\n新增角色\n屬性:");
    	scanf(" %c",&char4_type);
    	printf("血量:");
    	scanf("%d",&char4_hp);
    	printf("攻擊:");
    	scanf("%d",&char4_atk);
    	printf("防禦:");
    	scanf("%d",&char4_def);
		//屬性大小寫問題 
    	if(char4_type == 'f'){
    		char4_type = 'F';
		}else if(char4_type == 'w'){
			char4_type = 'W';
		}else if(char4_type == 'g'){
			char4_type = 'G';
		}else if(char4_type == 'a'){
			char4_type = 'A';
		}else if(char4_type == 'F'){
			char4_type = 'F';
		}else if(char4_type == 'W'){
			char4_type = 'W';
		}else if(char4_type == 'G'){
			char4_type = 'G';
		}else if(char4_type == 'A'){
			char4_type = 'A';
		}else{
			printf("錯誤 : 無此屬性\n");
		}
		//角色素質是否皆在值域內 
		if((char4_hp < 40)|(char4_hp > 50)){
    		printf("錯誤 : 能力數值在範圍之外\n");
    		return 0;
		}
		if((char4_atk < 15)|(char4_atk > 20)){
    		printf("錯誤 : 能力數值在範圍之外\n");
    		return 0;
		}
		if((char4_def < 5)|(char4_def > 10)){
    		printf("錯誤 : 能力數值在範圍之外\n");
    		return 0;
		}
		if(((char4_hp + char4_atk + char4_def)<65)|((char4_hp + char4_atk + char4_def)>70)){
			printf("錯誤 : 能力數值在範圍之外\n");
			return 0;
		}
   	    //自訂角色的強度預測
    	int power4=(char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5 - 50 ) * 6.5;
    	//角色四資訊 
    	printf("\n角色4\n名稱:自訂角色\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char4_type,char4_atk,char4_hp,char4_def,power4);
    	//攻擊順序決定 
    	printf("選擇先攻角色 : ");
		scanf("%d",&firstone);
		if((firstone>4)|(firstone<1)){
			printf("錯誤 : 無此角色\n");
		}else{
			printf("選擇後攻角色 : ");
			scanf("%d",&lastone);
			if((lastone>4)|(lastone<1)){
				printf("錯誤 : 無此角色\n");
			}else if((lastone<=4)&(lastone>=1)){
				if(lastone == firstone){
					printf("錯誤 : 不可重複選取\n");
				}else{
					printf("\n先攻為角色%d、後攻為角色%d\n" , firstone, lastone);
				}
			}
		}   
	}else if(whethertrue == 2){
		//攻擊順序決定 
		printf("選擇先攻角色 : ");
		scanf("%d",&firstone);
		if((firstone>3)|(firstone<1)){
			printf("錯誤 : 無此角色\n");
		}else{
			printf("選擇後攻角色 : ");
			scanf("%d",&lastone);
			if((lastone>3)|(lastone<1)){
				printf("錯誤 : 無此角色\n");
			}else if((lastone<=3)&(lastone>=1)){
				if(lastone == firstone){
					printf("錯誤 : 不可重複選取\n");
				}else{
					printf("\n先攻為角色%d、後攻為角色%d\n" , firstone, lastone);
				}
			}
		}
	}else{
		printf("輸入錯誤\n");
	}
    return 0;
}

