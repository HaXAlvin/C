#include<stdio.h>
#include<stdlib.h>
int main(){
	//����@�ܼƫŧi 
	char char1_type = 'F';
    int char1_hp = 45;
	int char1_atk = 20;
	int char1_def = 5; 
	
	//����G�ܼƫŧi 
	char char2_type = 'W';
    int char2_hp = 40;
	int char2_atk = 15;
	int char2_def = 10;
	
	//����T�ܼƫŧi
	char char3_type = 'A';
    int char3_hp = 45;
	int char3_atk = 15;
	int char3_def = 10;
	
	//����|�ܼƫŧi
	char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    
    //�e�T�Ӫ�����j�׹w��
    int power1=(char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5 - 50 ) * 6.5;
    int power2=(char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5 - 50 ) * 6.5;
    int power3=(char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5 - 50 ) * 6.5;
    
	//����@��T     
    printf("����1\n�W��:�紵����\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n",char1_type,char1_atk,char1_hp,char1_def,power1);
    //����G��T
    printf("\n����2\n�W��:���ֱХD���\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n",char2_type,char2_atk,char2_hp,char2_def,power2);
    //����T��T
    printf("\n����3\n�W��:�U����\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n",char3_type,char3_atk,char3_hp,char3_def,power3);
    //�P�_�O�_�s�W�ĥ|�Ө��� 
	printf("\n�O�_�s�W����(1.Yes/2.No)?");
	int whethertrue;
	scanf(" %d",&whethertrue);
	//���� 
	int firstone;
	//��� 
	int lastone;	
	if(whethertrue == 1){
    	//�s�W����������� 
    	printf("\n�s�W����\n�ݩ�:");
    	scanf(" %c",&char4_type);
    	printf("��q:");
    	scanf("%d",&char4_hp);
    	printf("����:");
    	scanf("%d",&char4_atk);
    	printf("���m:");
    	scanf("%d",&char4_def);
		//�ݩʤj�p�g���D 
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
			printf("���~ : �L���ݩ�\n");
		}
		//�������O�_�Ҧb�Ȱ줺 
		if((char4_hp < 40)|(char4_hp > 50)){
    		printf("���~ : ��O�ƭȦb�d�򤧥~\n");
    		return 0;
		}
		if((char4_atk < 15)|(char4_atk > 20)){
    		printf("���~ : ��O�ƭȦb�d�򤧥~\n");
    		return 0;
		}
		if((char4_def < 5)|(char4_def > 10)){
    		printf("���~ : ��O�ƭȦb�d�򤧥~\n");
    		return 0;
		}
		if(((char4_hp + char4_atk + char4_def)<65)|((char4_hp + char4_atk + char4_def)>70)){
			printf("���~ : ��O�ƭȦb�d�򤧥~\n");
			return 0;
		}
   	    //�ۭq���⪺�j�׹w��
    	int power4=(char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5 - 50 ) * 6.5;
    	//����|��T 
    	printf("\n����4\n�W��:�ۭq����\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n",char4_type,char4_atk,char4_hp,char4_def,power4);
    	//�������ǨM�w 
    	printf("��ܥ��𨤦� : ");
		scanf("%d",&firstone);
		if((firstone>4)|(firstone<1)){
			printf("���~ : �L������\n");
		}else{
			printf("��ܫ�𨤦� : ");
			scanf("%d",&lastone);
			if((lastone>4)|(lastone<1)){
				printf("���~ : �L������\n");
			}else if((lastone<=4)&(lastone>=1)){
				if(lastone == firstone){
					printf("���~ : ���i���ƿ��\n");
				}else{
					printf("\n���𬰨���%d�B��𬰨���%d\n" , firstone, lastone);
				}
			}
		}   
	}else if(whethertrue == 2){
		//�������ǨM�w 
		printf("��ܥ��𨤦� : ");
		scanf("%d",&firstone);
		if((firstone>3)|(firstone<1)){
			printf("���~ : �L������\n");
		}else{
			printf("��ܫ�𨤦� : ");
			scanf("%d",&lastone);
			if((lastone>3)|(lastone<1)){
				printf("���~ : �L������\n");
			}else if((lastone<=3)&(lastone>=1)){
				if(lastone == firstone){
					printf("���~ : ���i���ƿ��\n");
				}else{
					printf("\n���𬰨���%d�B��𬰨���%d\n" , firstone, lastone);
				}
			}
		}
	}else{
		printf("��J���~\n");
	}
    return 0;
}

