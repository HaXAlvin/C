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
//	�j�׹w�� = ( ��q * 1.0 + ���� * 0.8 + ���m * 0.5 - 50 ) * 6.5
    printf("����1\n�W��:�C���a��\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n�j�׹w��:%.2f\n\n",char1_type,char1_atk,char1_hp,char1_def,char1_strongpre);
    printf("����2\n�W��:�V�嬰��\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n�j�׹w��:%.2f\n\n",char2_type,char2_atk,char2_hp,char2_def,char2_strongpre);
    printf("����3\n�W��:�W���S�u\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n�j�׹w��:%.2f\n\n",char3_type,char3_atk,char3_hp,char3_def,char3_strongpre);

	char char4_name[10]; char char4_type ; int char4_hp; int char4_atk; int char4_def;float char4_strongpre;

    printf("�W��(�r��10�r��):");
    scanf("%s", &char4_name);
    fflush(stdin);
    printf("\n����(F=���BW=���BG=�g�BA=��):");
	scanf("%c", &char4_type);
	fflush(stdin);
	printf("\n��q(40~50):");
	scanf("%d", &char4_hp);
	fflush(stdin);
	do{
		if (char4_hp<40||char4_hp>50){
		printf("��J���~!");
		printf("\n��q(40~50):");
		scanf("%d", &char4_hp);
		fflush(stdin);
		}
	}while(char4_hp<40||char4_hp>50);

	printf("\n����(15~20):");
	scanf("%d", &char4_atk);
	fflush(stdin);
	do{
		if (char4_atk<15||char4_atk>20){
		printf("��J���~!");
		printf("\n����(15~20):");
		scanf("%d", &char4_atk);
		fflush(stdin);
		}
	}while(char4_atk<15||char4_atk>20);

	printf("\n���m(5~10):");
	scanf("%d", &char4_def);
	fflush(stdin);
	do{
		if (char4_def<5||char4_def>10){
		printf("��J���~!");
		printf("\n���m(5~10):");
		scanf("%d", &char4_def);
		fflush(stdin);
		}
	}while(char4_def<5||char4_def>10);

	char4_strongpre = (char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5-50) * 6.5;

	printf("\n����4\n�W��:%s\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n�j�׹w��:%.2f\n\n",char4_name,char4_type,char4_atk,char4_hp,char4_def,char4_strongpre);

    return 0;
}
