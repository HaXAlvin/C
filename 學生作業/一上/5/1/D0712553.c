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
	printf("����j�׹w���G%.2lf\n\n", power);

    printf("����2\n");
	printf("����W�١G��ۣ\n");
	printf("�ݩʡG%-6c��q�G%d\n" ,char2_type ,char2_hp);
	printf("�����G%-6d���m�G%d\n" ,char2_atk ,char2_def);
	power = (char2_hp*1 + char2_atk*0.8 + char2_def*0.5 - 50)*6.5;
	printf("����j�׹w���G%.2lf\n\n", power);

    printf("����3\n");
	printf("����W�١G���jۣ\n");
	printf("�ݩʡG%-6c��q�G%d\n" ,char3_type ,char3_hp);
	printf("�����G%-6d���m�G%d\n" ,char3_atk ,char3_def);
	power = (char3_hp*1 + char3_atk*0.8 + char3_def*0.5 - 50)*6.5;
	printf("����j�׹w���G%.2lf\n\n", power);

    //����4
    char char4_type; //�w�q����4�ݩ��ܼ�
	int char4_hp; //�w�q����4��q�ܼ�
	int char4_atk; //�w�q����4�����ܼ�
	int char4_def; //�w�q����4���m�ܼ�

    int ans, order1, order2;
	printf("�O�_�s�W����(1.YES/2.NO)?");
	scanf("%d%*c", &ans);
	if (ans == 1){ //��ܷs�W����A�L�X�H�U��T�A�ШϥΪ̿�J�T��
        printf("�ݩʡG");
        scanf("%c" ,&char4_type); //�ϥΪ̿�J�ݩʡA�s�J����4�ݩ��ܼ� char4_type
        if(char4_type>97){
            char4_type = char4_type - 32;
        }
        printf("��q�G");
        scanf("%d" ,&char4_hp); //�ϥΪ̿�J��q�A�s�J����4��q�ܼ� char4_hp
        printf("�����G");
        scanf("%d" ,&char4_atk); //�ϥΪ̿�J�����A�s�J����4�����ܼ� char4_atk
        printf("���m�G");
        scanf("%d" ,&char4_def); //�ϥΪ̿�J���m�A�s�J����4���m�ܼ� char4_def

        //�p�G��O�ƭȬҲŦX�A�h�P�_�ݩʬO�_�ŦX
        if(char4_hp<51 && char4_hp>39 && char4_atk<21 && char4_atk>14 && char4_def<11 && char4_def>4){
            switch (char4_type){
                case 'F':
                case 'W':
                case 'A':
                case 'G': //�H�W�ҲŦX�h�L�X�U�C��T
                    printf("\n");
                    printf("����4\n");
                    printf("����W�١G�ۭq����\n");
                    printf("�ݩʡG%-6c��q�G%d\n" ,char4_type ,char4_hp);
                    printf("�����G%-6d���m�G%d\n" ,char4_atk ,char4_def);
                    power = (char4_hp*1 + char4_atk*0.8 + char4_def*0.5 - 50)*6.5;
                    printf("����j�׹w���G%.2lf\n\n", power);

                    //����s�W�����A��ܥ����𨤦�
                    printf("�п�ܥ��𨤦�G");
                    scanf("%d", &order1);
                    switch (order1){
                        case 1 ... 4: //��J���󶷬�1-4������
                            printf("�п�ܫ�𨤦�G");
                            scanf("%d", &order2);
                            if (order2 == order1){ //�����𤣥i�O�P�@����
                                printf("���~�G���i���ƿ��\n");
                            }
                            else { //�H�W�P�_���T�A�L�X�H�U�T��
                                printf("\n");
                                printf("���𨤦⬰%d�B��𨤦⬰%d\n", order1, order2);
                            }
                            break; //���������P�_����
                        default: //��J��T���b����ƶq�d��
                            printf("���~�G�L������\n");
                    }
                    break; //�ݩʧP�_����
                default: //��J�ݩʡA���b�d���ݩʤ�
                    printf("���~�G�L���ݩ�\n");
            }
        }
        //�p�G��O�ƭȨ�@���ŦX�A�h�P�_�ݩʬO�_�ŦX
        else {
            switch (char4_type){
                case 'F':
                case 'W':
                case 'A':
                case 'G': //�H�W�ҲŦX�h�L�X�U�C��T
                    printf("���~�G��O�ƭȦb����d�򤧥~\n");
                    break;
                default: //���ŦX�h�L�X�U�C��T
                    printf("���~�G�L���ݩ�\n");
                    printf("���~�G��O�ƭȦb����d�򤧥~\n");
            }
        }
	}
    else if (ans == 2){ //��ܤ��s�W����A���L�s�W����A��ܥ����𨤦�
            printf("\n");
            printf("�п�ܥ��𨤦�G");
            scanf("%d", &order1);
            switch (order1){
                case 1:
                case 2:
                case 3: //�P�_��J��T�O�_��������
                    printf("�п�ܫ�𨤦�G");
                    scanf("%d", &order2);
                    if (order2 == order1){ //���i���ƧP�_
                        printf("���~�G���i���ƿ��\n");
                    }
                    else { //�H�W�ҥ��T�A�h�L�X�H�U��T
                        printf("\n");
                        printf("���𬰨���%d�B��𬰨���%d\n", order1, order2);
                    }
                    break;
                default: //��J��T���b����ƶq�d��
                    printf("���~�G�L������\n");
            }
    }
    else { //�ϥΪ̿�J1.yes/2.no�H�~����T
        printf("��J���~\n");
    }
return 0;
}
