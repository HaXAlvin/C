#include <stdio.h>
#include <stdlib.h>

int main()
{
    //����1
	char char1_type = 'F';
	int char1_hp = 40;
	int char1_atk = 20;
	int char1_def = 10;
	float char_1 = (char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;
	printf("����1\n�W�١G����\n");
	printf("�ݩʡG %c  ",char1_type);
	printf("�����G%d\n",char1_atk);
	printf("��q�G%d  ",char1_hp);
	printf("���m�G%d\n\n",char1_def);
	printf("����j�סG%.2f\n\n",char_1);
	//����2
	char char2_type = 'W';
	int char2_hp = 50;
	int char2_atk = 15;
	int char2_def = 5;
	float char_2 = (char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
	printf("����2\n�W�١G����\n");
	printf("�ݩʡG %c  ",char2_type);
	printf("�����G%d\n",char2_atk);
	printf("��q�G%d  ",char2_hp);
	printf("���m�G%d\n\n",char2_def);
	printf("����j�סG%.2f\n\n",char_2);
	//����3
	char char3_type = 'G';
	int char3_hp = 45;
	int char3_atk = 15;
	int char3_def = 10;
	float char_3 = (char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
	printf("����3\n�W�١G�߫}\n");
	printf("�ݩʡG %c  ",char3_type);
	printf("�����G%d\n",char3_atk);
	printf("��q�G%d  ",char3_hp);
	printf("���m�G%d\n\n",char3_def);
	printf("����j�סG%.2f\n\n",char_3);
	//����4
	int main();
	int char4_type;
	int char4_atk;
	int char4_hp;
	int char4_def;
	printf("�s�W����\n�ݩ�:");
	scanf ("%c",&char4_type);
	printf("��q:");
	scanf ("%d",&char4_hp);
	printf("����:");
	scanf ("%d",&char4_atk);
	printf("���m:");
	scanf ("%d",&char4_def);
	float char_4 = (char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;
	printf("\n����4\n�W�١G�}��\n");
	printf("�ݩʡG %c  ",char4_type);
	printf("�����G%d\n",char4_atk);
	printf("��q�G%d  ",char4_hp);
	printf("���m�G%d\n",char4_def);
	printf("����j�סG%.2f\n\n",char_4);
	return 0;
}	
