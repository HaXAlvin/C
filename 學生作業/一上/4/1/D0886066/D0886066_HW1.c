#include<stdio.h>
#include<stdlib.h>
int main(){
	char char1_type = 'F';
    int char1_hp = 45;
	int char1_atk = 20;
	int char1_def = 5;//����@�ܼƫŧi 
	
	char char2_type = 'W';
    int char2_hp = 40;
	int char2_atk = 15;
	int char2_def = 10;//����G�ܼƫŧi 
	  
	char char3_type = 'A';
    int char3_hp = 45;
	int char3_atk = 15;
	int char3_def = 10;//����T�ܼƫŧi 
	
	char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;//����|�ܼƫŧi 
    
    int power1=(char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5 - 50 ) * 6.5;
    int power2=(char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5 - 50 ) * 6.5;
    int power3=(char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5 - 50 ) * 6.5;//�e�T�Ӫ�����j�׹w��
	     
    printf("����1\n�W��:�紵����\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n",char1_type,char1_atk,char1_hp,char1_def,power1);//����@��T 
    printf("\n����2\n�W��:���ֱХD���\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n",char2_type,char2_atk,char2_hp,char2_def,power2);//����G��T 
    printf("\n����3\n�W��:�U����\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n",char3_type,char3_atk,char3_hp,char3_def,power3);//����T��T
    printf("\n�s�W����\n�ݩ�:");
    scanf("%c,",&char4_type);
    printf("��q:");
    scanf("%d,",&char4_hp);
    printf("����:");
    scanf("%d,",&char4_atk);
    printf("���m:");
    scanf("%d,",&char4_def);
    int power4=(char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5 - 50 ) * 6.5;//�ۭq���⪺�j�׹w��
    printf("\n����4\n�W��:�ۭq����\n�ݩ�:%c    ����:%d\n��q:%d    ���m:%d\n����j�׹w���G%d\n",char4_type,char4_atk,char4_hp,char4_def,power4);//����|��T 
    
    return 0;
}
