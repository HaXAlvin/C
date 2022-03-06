#include<stdio.h>
#include<stdlib.h>
int main(){
	char char1_type = 'F';
    int char1_hp = 45;
	int char1_atk = 20;
	int char1_def = 5;//角色一變數宣告 
	
	char char2_type = 'W';
    int char2_hp = 40;
	int char2_atk = 15;
	int char2_def = 10;//角色二變數宣告 
	  
	char char3_type = 'A';
    int char3_hp = 45;
	int char3_atk = 15;
	int char3_def = 10;//角色三變數宣告 
	
	char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;//角色四變數宣告 
    
    int power1=(char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5 - 50 ) * 6.5;
    int power2=(char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5 - 50 ) * 6.5;
    int power3=(char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5 - 50 ) * 6.5;//前三個的角色強度預測
	     
    printf("角色1\n名稱:瑞斯叔叔\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char1_type,char1_atk,char1_hp,char1_def,power1);//角色一資訊 
    printf("\n角色2\n名稱:幸福教主刮哥\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char2_type,char2_atk,char2_hp,char2_def,power2);//角色二資訊 
    printf("\n角色3\n名稱:垃圾車\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char3_type,char3_atk,char3_hp,char3_def,power3);//角色三資訊
    printf("\n新增角色\n屬性:");
    scanf("%c,",&char4_type);
    printf("血量:");
    scanf("%d,",&char4_hp);
    printf("攻擊:");
    scanf("%d,",&char4_atk);
    printf("防禦:");
    scanf("%d,",&char4_def);
    int power4=(char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5 - 50 ) * 6.5;//自訂角色的強度預測
    printf("\n角色4\n名稱:自訂角色\n屬性:%c    攻擊:%d\n血量:%d    防禦:%d\n角色強度預測：%d\n",char4_type,char4_atk,char4_hp,char4_def,power4);//角色四資訊 
    
    return 0;
}
