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
    int p = 1; //�O�_�s�W����flag
    int q = 1; //�i�J�s�W����flag
    int r = 0; //�w�]�G�s�W����A�������i�J�������ǰj��
    while(p){
        printf("�O�_�s�W����(1.YES/2.NO)?");
        scanf("%d", &ans);
        if(ans == 1){
            q = 1; //�n�Ш�flag
            p = 0; //���}���j��
        }else if(ans == 2){
            q = 0; //���Ш�flag
            p = 0; //���}���j��
            r = 1; //���s�W����A�����i�J�������ǰj��
        }else{
            printf("��J���~\n");
        }
    }

    while(q){
        printf("�ݩʡG");
        scanf("%*c%c" ,&char4_type); //�ϥΪ̿�J�ݩʡA�s�J����4�ݩ��ܼ� char4_type
        //scanf("%*[^\n]");
        if(char4_type>97){
        char4_type = char4_type - 32;
        }
        printf("��q�G");
        scanf("%d" ,&char4_hp); //�ϥΪ̿�J��q�A�s�J����4��q�ܼ� char4_hp
        printf("�����G");
        scanf("%d" ,&char4_atk); //�ϥΪ̿�J�����A�s�J����4�����ܼ� char4_atk
        printf("���m�G");
        scanf("%d" ,&char4_def); //�ϥΪ̿�J���m�A�s�J����4���m�ܼ� char4_def

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
                    q = 0; //���}�Ш��j��flag
                    p = 1;
                    break; //�ݩʧP�_����
                default: //��J�ݩʡA���b�d���ݩʤ�
                    printf("���~�G�L���ݩ�\n\n");
            }
        }
        //�p�G��O�ƭȨ�@���ŦX�A�h�P�_�ݩʬO�_�ŦX
        else {
            switch (char4_type){
                case 'F':
                case 'W':
                case 'A':
                case 'G': //�H�W�ҲŦX�h�L�X�U�C��T
                    printf("���~�G��O�ƭȦb����d�򤧥~\n\n");
                    break;
                default: //���ŦX�h�L�X�U�C��T
                    printf("���~�G�L���ݩ�\n");
                    printf("���~�G��O�ƭȦb����d�򤧥~\n\n");
            }
        }
    }
    int stchar;
    int sthp;
    int statk;
    int stdef;
    int ndchar;
    int ndhp;
    int ndatk;
    int nddef;
    while(r){
        printf("\n");
        printf("�п�ܥ��𨤦�G");
        scanf("%d", &order1);
        switch (order1){
            case 1:
                stchar = order1;
                sthp = charl_hp;
                statk = charl_atk;
                stdef = charl_def;
                break;
            case 2:
                stchar = order1;
                sthp = char2_hp;
                statk = char2_atk;
                stdef = char2_def;
                break;
            case 3:
                stchar = order1;
                sthp = char3_hp;
                statk = char3_atk;
                stdef = char3_def;
        }
        switch (order1){
            case 1:
            case 2:
            case 3: //�P�_��J��T�O�_��������
                printf("�п�ܫ�𨤦�G");
                scanf("%d", &order2);
                if (order2 == order1){ //���i���ƧP�_
                    printf("���~�G���i���ƿ��\n");
                }
                else if (order2 > 3){
                    printf("���~�G�L������\n");
                }
                else { //�H�W�ҥ��T�A�h�L�X�H�U��T
                    printf("\n");
                    printf("���𬰨���%d�B��𬰨���%d\n", order1, order2);
                    switch (order2){
                        case 1:
                            ndchar = order2;
                            ndhp = charl_hp;
                            ndatk = charl_atk;
                            nddef = charl_def;
                            break;
                        case 2:
                            ndchar = order2;
                            ndhp = char2_hp;
                            ndatk = char2_atk;
                            nddef = char2_def;
                            break;
                        case 3:
                            ndchar = order2;
                            ndhp = char3_hp;
                            ndatk = char3_atk;
                            nddef = char3_def;
                    }
                    r = 0; //���}�������ǰj��
                }
                break;
            default: //��J��T���b����ƶq�d��
                printf("���~�G�L������\n");
        }
    }
    while(p) {
        printf("\n");
        printf("�п�ܥ��𨤦�G");
        scanf("%d", &order1);
        switch (order1){
            case 1:
                stchar = order1;
                sthp = charl_hp;
                statk = charl_atk;
                stdef = charl_def;
                break;
            case 2:
                stchar = order1;
                sthp = char2_hp;
                statk = char2_atk;
                stdef = char2_def;
                break;
            case 3:
                stchar = order1;
                sthp = char3_hp;
                statk = char3_atk;
                stdef = char3_def;
            case 4:
                stchar = order1;
                sthp = char4_hp;
                statk = char4_atk;
                stdef = char4_def;
        }
        switch (order1){
            case 1:
            case 2:
            case 3:
            case 4: //��J���󶷬�1-4������
                printf("�п�ܫ�𨤦�G");
                scanf("%d", &order2);
                if (order2 == order1){ //�����𤣥i�O�P�@����
                    printf("���~�G���i���ƿ��\n");
                }
                else if (order2 > 4){
                    printf("���~�G�L������\n");
                }
                else { //�H�W�P�_���T�A�L�X�H�U�T��
                    printf("\n");
                    printf("���𨤦⬰%d�B��𨤦⬰%d\n", order1, order2);
                    switch (order2){
                        case 1:
                            ndchar = order2;
                            ndhp = charl_hp;
                            ndatk = charl_atk;
                            nddef = charl_def;
                            break;
                        case 2:
                            ndchar = order2;
                            ndhp = char2_hp;
                            ndatk = char2_atk;
                            nddef = char2_def;
                            break;
                        case 3:
                            ndchar = order2;
                            ndhp = char3_hp;
                            ndatk = char3_atk;
                            nddef = char3_def;
                        case 4:
                            ndchar = order2;
                            ndhp = char4_hp;
                            ndatk = char4_atk;
                            nddef = char4_def;
                    }
                    p = 0;
                }
                break; //���������P�_����
            default: //��J��T���b����ƶq�d��
                printf("���~�G�L������\n");
        }
    }
    printf("�԰��}�l\n");
    printf("\n");
    int firstatk = statk - nddef;
    int lastatk = ndatk - stdef;
    while(sthp>0 && ndhp>0){
        printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", order1, order2, firstatk);
        ndhp = ndhp -  firstatk;
        printf("����%d HP�G%d  ����%d HP�G%d\n", order1, sthp, order2, ndhp);
        printf("\n");
        if (ndhp<=0 && sthp!=0){
            printf("����%d ���h�԰���O\n", order2);
            printf("�԰�����\n");
            printf("\n");
            printf("����%d ���",order1);
            q = 0;
            return 0;
        }
        printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", order2, order1, lastatk);
        sthp = sthp - lastatk;
        printf("����%d HP�G%d  ����%d HP�G%d\n", order1, sthp, order2, ndhp);
        printf("\n");
        if(sthp<=0 && ndhp!=0){
            printf("����%d ���h�԰���O\n", order1);
            printf("�԰�����\n");
            printf("\n");
            printf("����%d ���",order2);
            q = 0;
            return 0;
        }
    }
return 0;
}
