#include<stdio.h>
#include<stdlib.h>

int main(){

	char char1_type = 'W'; char char2_type = 'F'; char char3_type = 'A';
	int char1_hp  = 40; int char2_hp  = 45; int char3_hp  = 42;
	int char1_atk = 20; int char2_atk = 15; int char3_atk = 17;
	int char1_def = 5 ; int char2_def = 10; int char3_def = 7 ;
	float char1_strongpre ;float char2_strongpre ;float char3_strongpre ;
	char1_strongpre = (char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5-50) * 6.5;
	char2_strongpre = (char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5-50) * 6.5;
	char3_strongpre = (char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5-50) * 6.5;
//	強度預測 = ( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5
    printf("角色1\n名稱:劍指蒼穹\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n強度預測:%.2f\n\n",char1_type,char1_atk,char1_hp,char1_def,char1_strongpre);
    printf("角色2\n名稱:敲血為凝\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n強度預測:%.2f\n\n",char2_type,char2_atk,char2_hp,char2_def,char2_strongpre);
    printf("角色3\n名稱:超鬼特工\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n強度預測:%.2f\n\n",char3_type,char3_atk,char3_hp,char3_def,char3_strongpre);

	char char4_name[10]; char char4_type ; int char4_hp; int char4_atk; int char4_def;float char4_strongpre;

    printf("名稱(字數10字內):");
    scanf("%s", &char4_name);
    fflush(stdin);
    printf("\n類型(F=火、W=水、G=土、A=風):");
	scanf("%c", &char4_type);
	fflush(stdin);
	printf("\n血量(40~50):");
	scanf("%d", &char4_hp);
	fflush(stdin);
	do{
		if (char4_hp<40||char4_hp>50){
		printf("輸入有誤!");
		printf("\n血量(40~50):");
		scanf("%d", &char4_hp);
		fflush(stdin);
		}
	}while(char4_hp<40||char4_hp>50);

	printf("\n攻擊(15~20):");
	scanf("%d", &char4_atk);
	fflush(stdin);
	do{
		if (char4_atk<15||char4_atk>20){
		printf("輸入有誤!");
		printf("\n攻擊(15~20):");
		scanf("%d", &char4_atk);
		fflush(stdin);
		}
	}while(char4_atk<15||char4_atk>20);

	printf("\n防禦(5~10):");
	scanf("%d", &char4_def);
	fflush(stdin);
	do{
		if (char4_def<5||char4_def>10){
		printf("輸入有誤!");
		printf("\n防禦(5~10):");
		scanf("%d", &char4_def);
		fflush(stdin);
		}
	}while(char4_def<5||char4_def>10);

	char4_strongpre = (char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5-50) * 6.5;

	printf("\n角色4\n名稱:%s\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n強度預測:%.2f\n\n",char4_name,char4_type,char4_atk,char4_hp,char4_def,char4_strongpre);

    return 0;
}
