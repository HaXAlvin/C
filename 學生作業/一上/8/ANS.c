#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char char1_name[21] = "����";
	char char2_name[21] = "�ȵ��R";
	char char3_name[21] = "�p�i";
	char char4_name[21];

	char type[4] = {'W', 'A', 'F'}; //�ݩ�
	int hp[4] = {50, 40, 45};  //��q
	int atk[4] = {15, 20, 17};  //����
	int def[4] = {5, 8, 7};  //���m

    int first_atk;
    int first_atk_type;
    int first_atk_hp;
    int second_atk;
	int second_atk_type;
	int second_atk_hp;
	int type_rate;

    int char4_is_create = 0;
    int is_correct, turn, select;

    while (1) {
		printf("1. �s�W�έק�s�W����\n"
			   "2. ��ܩҦ�������\n"
			   "3. �԰�\n"
			   "0. �����C��\n"
			   "�п�ܡG");
		scanf("%d", &select);
		printf("\n");
		switch ((0 > select || select > 3) ? -1 : select) {
			case -1:
				printf("��J���~!\n");
				break;
			case 0:
				printf("�����C��\n");
				return 0;
			case 1:
				do {
					is_correct = 1; //��l��flag
                    printf("%s",char4_is_create?"�ק�s�W����\n":"�s�W����\n");
					printf("�W�١G");
					scanf("%s", char4_name);
		            printf("�ݩʡG");
		            scanf("%*c%c", &type[3]);
		            printf("��q�G");
		            scanf("%d", &hp[3]);
		            printf("�����G");
		            scanf("%d", &atk[3]);
		            printf("���m�G");
		            scanf("%d", &def[3]);
		            //�˹��ݩ�
		            if (type[3] != 'F' && type[3] != 'W' && type[3] != 'G' && type[3] != 'A' &&
		                type[3] != 'f' && type[3] != 'w' && type[3] != 'g' && type[3] != 'a') {
		                printf("���~�G�L���ݩ�\n");
		                is_correct = 0;
		            }
		            else if (type[3] >= 'a')
		                type[3] -= 32;
		            //�ˬd��O�ƭ�
		            int char4_sum = hp[3] + atk[3] + def[3];
		            if (hp[3] < 40 || hp[3] > 50 || atk[3] < 15 || atk[3] > 20 ||
		                def[3] < 5 || def[3] > 10 || char4_sum < 65 || char4_sum > 70) {
		                printf("���~�G��O�ƭȦb����d�򤧥~\n");
		                is_correct = 0;
		            }
		            if (!is_correct)
		            	printf("\n");
				} while (!is_correct);
				char4_is_create = 1;
	            printf("\n����4\n�W�١G%s\n", char4_name);
		        printf("�ݩʡG%c     �����G%d\n", type[3], atk[3]);
		        printf("��q�G%d    ���m�G%d\n", hp[3], def[3]);
		        printf("����j�׹w���G%.2f\n", (hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5 - 50.0) * 6.5 );
		        break;
		    case 2:
		    	for (int i = 0; i < 3 + char4_is_create; i++) {
		    		if (i)
		    			printf("\n");
					printf("����%d\n�W�١G%s\n", i + 1, i == 0 ? char1_name : i == 1 ? char2_name : i == 2 ? char3_name : char4_name);
				    printf("�ݩʡG%c     �����G%d\n", type[i], atk[i]);
				    printf("��q�G%d    ���m�G%d\n", hp[i], def[i]);
				    printf("����j�׹w���G%.2f\n", (hp[i] * 1.0 + atk[i] * 0.8 + def[i] * 0.5 - 50.0) * 6.5 );
				}
				break;
			case 3:
				do{
			        is_correct = 1; //��l��flag
			        printf("��ܥ��𨤦�G");
			        scanf("%d", &first_atk);
			        if(first_atk < 1 || first_atk > 3 + char4_is_create){
			            printf("���~�G�L������\n");
			            is_correct = 0;
			        }
			    }while(!is_correct);
			    do{
			        is_correct = 1; //��l��flag
			        printf("��ܫ�𨤦�G");
			        scanf("%d", &second_atk);
			        if(second_atk < 1 || second_atk > 3 + char4_is_create){
			            printf("���~�G�L������\n");
			            is_correct = 0;
			        }
			        else if(second_atk == first_atk){
			            printf("���~�G���i���ƿ��\n");
			            is_correct = 0;
			        }
			    }while(!is_correct);
			    printf("\n���𬰨���%d�B��𬰨���%d\n", first_atk--, second_atk--);
			    turn = 1; //��l�Ƨ�����
			    first_atk_hp = hp[first_atk];
			    second_atk_hp = hp[second_atk];
			    //�p���ݩʬ۫g
			    first_atk_type = type[first_atk] == 'W' ? 0 : type[first_atk] == 'F' ? 1 : type[first_atk] == 'A' ? 2 : 3;
			    second_atk_type = type[second_atk] == 'W' ? 0 : type[second_atk] == 'F' ? 1 : type[second_atk] == 'A' ? 2 : 3;
				type_rate = second_atk_type - first_atk_type;//1 : first �g second
				type_rate = type_rate == 3 ? -1 : type_rate == -3 ? 1 : type_rate < -1 || type_rate > 1 ? 0 : type_rate;
			    printf("�԰��}�l\n\n");
			    while (first_atk_hp > 0 && second_atk_hp > 0) {
			        int atking;
			        if(turn == 1){
			            atking = atk[first_atk] * (1 + type_rate * 0.2) * (first_atk_hp < hp[first_atk] * 0.5 ? 1.2 : 1) - def[second_atk];
			            second_atk_hp -= atking;
			            printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", first_atk + 1, second_atk + 1, atking);
			            turn = 2; //�洫������
			        }
			        else{
			            atking = atk[second_atk] * (1 - type_rate * 0.2) * (second_atk_hp < hp[second_atk] * 0.5 ? 1.2 : 1) - def[first_atk];
			            first_atk_hp -= atking;
			            printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", second_atk + 1, first_atk + 1, atking);
			            turn = 1; //�洫������
			        }
			        printf("����%d HP: %d  ����%d HP: %d\n\n", first_atk + 1, first_atk_hp, second_atk + 1, second_atk_hp);
			    }
			    printf("����%d ���h�԰���O\n", (first_atk_hp > 0) ? second_atk + 1 : first_atk + 1);
			    printf("�԰�����\n\n");
			    printf("����%d ���\n", (first_atk_hp > 0) ? first_atk + 1 : second_atk + 1);
		}
		printf("\n");
	}
}
