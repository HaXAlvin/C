 #include<stdio.h>
 #include<stdlib.h>
 int main(){
    //����1
	char char1_type = 'W';
	int char1_hp = 45;
	int char1_atk = 18;
	int char1_def = 6;
	float char1=(char1_hp* 1.0 + char1_atk* 0.8 + char1_def* 0.5 - 50 ) * 6.5;
	//����2
	char char2_type = 'G';
	int char2_hp = 43;
	int char2_atk = 17;
	int char2_def = 5;
	float char2=(char2_hp* 1.0 + char2_atk* 0.8 + char2_def* 0.5 - 50 ) * 6.5;
	//����3
	char char3_type = 'A';
	int char3_hp = 48;
	int char3_atk = 15;
	int char3_def = 7;
    float char3=(char3_hp* 1.0 + char3_atk* 0.8 + char3_def* 0.5 - 50 ) * 6.5;
	//�ۭq����
	char char4_type ;
	int char4_hp ;
	int char4_atk ;
	int char4_def ;

	 printf("����1\n�W��:�p�Q\n�ݩ�:W    ����:18\n��q:45   ���m:6\n����j�׹w��:%.2f\n"
            "����2\n�W��:���I\n�ݩ�:G    ����:17\n��q:43   ���m:5\n����j�׹w��:%.2f\n"
            "����3\n�W��:���B\n�ݩ�:A    ����:15\n��q:48   ���m:7\n����j�׹w��:%.2f\n",char1,char2,char3
			);

	printf("�Ъ��a�]�w�ۭq����\n");
	printf("�п�J�ݩ�(F=���BW=���BG=�g�BA=��):");
	scanf("%c",&char4_type);
	printf("�п�J�����O:");
	scanf("%d",&char4_atk);
	printf("�п�J��q:");
	scanf("%d",&char4_hp);
	printf("�п�J���m�O:");
	scanf("%d",&char4_def);
	printf("�ۭq����\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w��:%.2f\n",char4_type,char4_atk,char4_hp,char4_def,(char4_hp* 1.0 + char4_atk* 0.8 + char4_def* 0.5 - 50 ) * 6.5);
	return 0;
 }
