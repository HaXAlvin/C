#include <stdio.h>
#include <stdlib.h>

int main()
{
    //����1
    char char1_type='F';//�ݩ�
    int char1_hp=45;//��q
    int char1_atk=17;//����
    int char1_def=8;//���m
    float char1_pre=(char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;//�j�׹w��
    //����2
    char char2_type='G';
    int char2_hp=45;
    int char2_atk=15;
    int char2_def=10;
    float char2_pre=(char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
    //����3
    char char3_type='A';
    int char3_hp=50;
    int char3_atk=15;
    int char3_def=5;
    float char3_pre=(char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
    //����4
    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    char char4_name[20];
    float char4_pre;

    int first_atk;//�q�w���𨤦��ܼ�
    int first_atk_origin_hp;
    int first_atk_hp;
    int first_atk_atk;
    int first_atk_def;

    int second_atk;//�q�w��𨤦��ܼ�
    int second_atk_origin_hp;
    int second_atk_hp;
    int second_atk_atk;
    int second_atk_def;

    int char4_is_create=0;
    int char4_is_delete=0;
    int is_correct, turn;
    int chs;

    do{
        printf("1. �s�W�έק�s�W����\n");
        printf("2. ��ܩҦ�������\n");
        printf("3. �԰�\n");
        printf("0. �����C��\n");
        printf("�п�ܡG");
        scanf("%d",&chs);


        if(chs<0 || chs>3){
            printf("\n��J���~!\n\n");

        }

        if(chs==2){
            printf("\n");
            printf("����1\n");
            printf("�W��:����\n");
            printf("�ݩ�:%c     ",char1_type);
            printf("����:%d\n",char1_atk);
            printf("��q:%d    ",char1_hp);
            printf("���m:%d\n",char1_def);
            printf("����j�׹w��:%.2f\n",char1_pre);
            printf("\n");

            printf("����2\n");
            printf("�W��:����\n");
            printf("�ݩ�:%c     ",char2_type);
            printf("����:%d\n",char2_atk);
            printf("��q:%d    ",char2_hp);
            printf("���m:%d\n",char2_def);
            printf("����j�׹w��:%.2f\n",char2_pre);
            printf("\n");

            printf("����3\n");
            printf("�W��:�ڵ� \n");
            printf("�ݩ�:%c     ",char3_type);
            printf("����:%d\n",char3_atk);
            printf("��q:%d    ",char3_hp);
            printf("���m:%d\n",char3_def);
            printf("����j�׹w��:%.2f\n",char3_pre);
            printf("\n");

            if(char4_is_create = 1){
                printf("����4\n�W�١G%s\n",char4_name);
                printf("�ݩʡG%c     �����G%d\n", char4_type, char4_atk);
                printf("��q�G%d    ���m�G%d\n", char4_hp, char4_def);
                printf("����j�׹w���G%.2f\n", (char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5 - 50.0) * 6.5 );
                printf("\n");
            }
        }

        if(chs==1){
            do{
                is_correct = 1; //��l��flag
                printf("\n");
                if(char4_is_delete == 1)//�p�G�w�g����L�s�W���⪺��ơA�L�X�ק�s�W����
                    printf("�ק�s�W����\n");
                else
                    printf("�s�W����\n");
                char4_is_create = 1;
                printf("�W�١G");
                scanf("%*c%s",&char4_name);
                printf("�ݩʡG");
                scanf("%*c%c", &char4_type);
                printf("��q�G");
                scanf("%d", &char4_hp);
                printf("�����G");
                scanf("%d", &char4_atk);
                printf("���m�G");
                scanf("%d", &char4_def);
                //�˹��ݩ�
                if(char4_type != 'F' && char4_type != 'W' && char4_type != 'G' && char4_type != 'A' &&
                   char4_type != 'f' && char4_type != 'w' && char4_type != 'g' && char4_type != 'a'){
                     printf("���~�G�L���ݩ�\n");
                     is_correct = 0;
                }
                else if(char4_type >= 'a')
                    char4_type -= 32;
                //�ˬd��O�ƭ�
                int char4_sum = char4_hp + char4_atk + char4_def;
                if(char4_hp < 40 || char4_hp > 50 || char4_atk < 15 || char4_atk > 20 ||
                   char4_def < 5 || char4_def > 10 || char4_sum < 65 || char4_sum > 70){
                     printf("���~�G��O�ƭȦb����d�򤧥~\n");
                     is_correct = 0;
                }
            }while(!is_correct);

            printf("\n����4\n�W�١G%s\n",char4_name);
            printf("�ݩʡG%c     �����G%d\n", char4_type, char4_atk);
            printf("��q�G%d    ���m�G%d\n", char4_hp, char4_def);
            printf("����j�׹w���G%.2f\n", (char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5 - 50.0) * 6.5 );
            printf("\n");
        }

        if(chs==3){
            printf("\n");
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

            printf("\n���𬰨���%d�B��𬰨���%d\n", first_atk, second_atk);
            //�N���𪺯�O��ƨ��X
            first_atk_hp = (first_atk == 1) ? char1_hp : (first_atk == 2) ? char2_hp : (first_atk == 3) ? char3_hp : char4_hp;
            first_atk_atk = (first_atk == 1) ? char1_atk : (first_atk == 2) ? char2_atk : (first_atk == 3) ? char3_atk : char4_atk;
            first_atk_def = (first_atk == 1) ? char1_def : (first_atk == 2) ? char2_def : (first_atk == 3) ? char3_def : char4_def;
            //�N��𪺯�O��ƨ��X
            second_atk_hp = (second_atk == 1) ? char1_hp : (second_atk == 2) ? char2_hp : (second_atk == 3) ? char3_hp : char4_hp;
            second_atk_atk = (second_atk == 1) ? char1_atk : (second_atk == 2) ? char2_atk : (second_atk == 3) ? char3_atk : char4_atk;
            second_atk_def = (second_atk == 1) ? char1_def : (second_atk == 2) ? char2_def : (second_atk == 3) ? char3_def : char4_def;

            turn = 1; //��l�Ƨ�����
            first_atk_origin_hp = first_atk_hp;
            second_atk_origin_hp = second_atk_hp;

            printf("�԰��}�l\n\n");
            while(first_atk_hp > 0 && second_atk_hp > 0){
                int atk;
                if(turn == 1){
                    atk = first_atk_atk - second_atk_def;
                    second_atk_hp -= atk;
                    printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", first_atk, second_atk, atk);
                    turn = 2; //�洫������
                }
                else{
                    atk = second_atk_atk - first_atk_def;
                    first_atk_hp -= atk;
                    printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", second_atk, first_atk, atk);
                    turn = 1; //�洫������
                }
                printf("����%d HP: %d  ����%d HP: %d\n\n", first_atk, first_atk_hp, second_atk, second_atk_hp);
            }
            printf("����%d ���h�԰���O\n", (first_atk_hp > 0) ? second_atk : first_atk);
            printf("�԰�����\n\n");
            printf("����%d ���\n", (first_atk_hp > 0) ? first_atk : second_atk);
            printf("\n");
            char4_is_create =0;
            char4_is_delete =1;//�p�G����4���Q��L��ơA�N�[ 1
        }

        if(chs==0){
            printf("\n");
            printf("�����C��\n");
            break;
        }
    }while(1);

    return 0;
}
