#include <stdio.h>
#include <stdlib.h>

int main()
{
	//����1
	char charl_type = 'G'; //����1���ݩ�
	int charl_hp = 40; //����1����q
	int charl_atk = 20; //����1�������q
	int charl_def = 5; //����1�����m�q
	//����2
    char char2_type = 'W'; //����2���ݩ�
	int char2_hp = 50;  //����2����q
	int char2_atk = 15; //����2�������q
	int char2_def = 5; //����2�����m�q
	//����3
    char char3_type = 'F'; //����3���ݩ�
	int char3_hp = 40; //����3����q
	int char3_atk = 15;  //����3�������q
	int char3_def = 10; //����3�����m�q
	//�j�׹w��
    double power;

	printf("����1\n");
	printf("����W�١GĨۣ\n");
	printf("�ݩʡG%-6c��q�G%d\n" ,charl_type ,charl_hp);
	printf("�����G%-6d���m�G%d\n" ,charl_atk ,charl_def);
	power = (charl_hp*1 + charl_atk*0.8 + charl_def*0.5 - 50)*6.5;
	printf("����j�׹w�� : %.2lf\n\n", power);

    printf("����2\n");
	printf("����W�١G��ۣ\n");
	printf("�ݩʡG%-6c��q�G%d\n" ,char2_type ,char2_hp);
	printf("�����G%-6d���m�G%d\n" ,char2_atk ,char2_def);
	power = (char2_hp*1 + char2_atk*0.8 + char2_def*0.5 - 50)*6.5;
	printf("����j�׹w�� : %.2lf\n\n", power);

    printf("����3\n");
	printf("����W�١G���jۣ\n");
	printf("�ݩʡG%-6c��q�G%d\n" ,char3_type ,char3_hp);
	printf("�����G%-6d���m�G%d\n" ,char3_atk ,char3_def);
	power = (char3_hp*1 + char3_atk*0.8 + char3_def*0.5 - 50)*6.5;
	printf("����j�׹w�� : %.2lf\n\n", power);

    //����4
    char char4_type; //�w�q����4�ݩ��ܼ�
	int char4_hp; //�w�q����4��q�ܼ�
	int char4_atk; //�w�q����4�����ܼ�
	int char4_def; //�w�q����4���m�ܼ�

    printf("�s�W����\n");
    printf("�ݩʡG");
    scanf("%c" ,&char4_type); //�ϥΪ̿�J�ݩʡA�s�J����4�ݩ��ܼ� char4_type
    printf("��q�G");
    scanf("%d" ,&char4_hp); //�ϥΪ̿�J��q�A�s�J����4��q�ܼ� char4_hp
    printf("�����G");
    scanf("%d" ,&char4_atk); //�ϥΪ̿�J�����A�s�J����4�����ܼ� char4_atk
    printf("���m�G");
    scanf("%d" ,&char4_def); //�ϥΪ̿�J���m�A�s�J����4���m�ܼ� char4_def
    printf("\n");

    printf("����4\n");
    printf("����W�١G�ۭq����\n");
    printf("�ݩʡG%-6c��q�G%d\n" ,char4_type ,char4_hp);
    printf("�����G%-6d���m�G%d\n" ,char4_atk ,char4_def);
    power = (char4_hp*1 + char4_atk*0.8 + char4_def*0.5 - 50)*6.5;
    printf("����j�׹w�� : %.2lf\n", power);

    return 0;
}
