#include<stdio.h>

int main()
{
    char char1_name[21] = "���N";
    char char2_name[21] = "�d��";
    char char3_name[21] = "�p��";
    char char4_name[21];

    char type[4] = {'F', 'W', 'W'};//�ݩ�
    int hp[4] = {43, 46, 45, 0};//��q
    int atk[4] = {19, 15, 17, 0};//����
    int def[4] = {7, 8, 6, 0};//���m


    int choice;//���(0~3)
    int NewChar = 0;//�P�_�O�_�w�s�W����0���_�A1���O
    //��while�j����L�X��ܵ��A�M���J�A��J < 0 �� > 3 �h��X"��J���~"
    while (printf("1. �s�W�έק�s�W����\n2. ��ܩҦ�������\n3. �԰�\n0. �����C��\n�п��: ")&&scanf("%d", &choice))
    {
        if (choice < 0 || choice > 3)
        {
            printf("\n��J���~!\n\n");
            continue;
        }
        if (choice == 0)//�����C��
        {
            printf("\n�����C��\n");
            break;
        }
        else if (choice == 1)
        {
            int error_type = 0, error_val = 0;//error_type �����ݩʬO�_���~, error_val ������O�ƭȬO�_���~ 0-> ���T, 1-> ���~

            do { //��do while�j�� ����J�����T��P�_�O�_��J���~
                if (NewChar == 0)
                    printf("\n�s�W����\n");
                else if (NewChar == 1)
                    printf("\n�ק�s�W����\n");
                getchar();
                printf("�W�� : ");
                gets(char4_name);
                printf("�ݩ� : ");
                scanf("%c", &type[3]);
                printf("��q : ");
                scanf("%d", &hp[3]);
                printf("���� : ");
                scanf("%d", &atk[3]);
                printf("���m : ");
                scanf("%d", &def[3]);
                int sum = atk[3] + hp[3] + def[3];
                if (type[3] == 102 || type[3] == 119 || type[3] == 103 || type[3] == 97)//��ASCII code �N�p�g�ন�j�g
                    type[3] = type[3] - 32;
                //���P�_�ݩ�
                if (type[3] != 'F' && type[3] != 'W' && type[3] != 'G' && type[3] != 'A')
                {
                    printf("���~:�L���ݩ�\n");
                    error_type = 1;
                    //�P�_�ݩʿ��~�ᱵ�ۧP�_��O�ƭȻP���`�M
                    if (atk[3] < 15 || atk[3] > 20 || hp[3] < 40 || hp[3] > 50 || def[3] < 5 || def[3] > 10)
                    {
                        printf("���~:��O�ƭȦb����d�򤧥~\n");
                        error_val = 1;
                    }
                    else if (sum < 65 || sum > 70)
                    {
                        printf("���~:��O�ƭȦb����d�򤧥~\n");
                        error_val = 1;
                    }
                    continue;
                }
                //�ݩʵL�~���ۧP�_��O�ƭȻP���`�M
                if (atk[3] < 15 || atk[3] > 20 || hp[3] < 40 || hp[3] > 50 || def[3] < 5 || def[3] > 10)
                {
                    printf("���~:��O�ƭȦb����d�򤧥~\n");
                    error_val = 1;
                }
                else if (sum < 65 || sum > 70)
                {
                    printf("���~:��O�ƭȦb����d�򤧥~\n");
                    error_val = 1;
                }
                else
                {
                    error_type = 0, error_val = 0;//��J�ҥ��T�Nerror�k�s
                    float predict = (hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5 - 50) * 6.5;
                    printf("\n����4\n�W��: %s\n�ݩ�: %c      ����: %d\n", char4_name, type[3], atk[3]);
                    printf("��q: %d     ���m: %d\n", hp[3], def[3]);
                    printf("�j�׹w��: %.2f\n\n", predict);
                    NewChar = 1;
                }
            }while (error_type == 1 || error_val == 1);
        }
        else if (choice == 2)
        {
            //����1
            float predict_char1 = (hp[0] * 1.0 + atk[0] * 0.8 + def[0] * 0.5 - 50) * 6.5;
            printf("\n����1\n�W��: %s\n�ݩ�: %c      ����: %d\n", char1_name, type[0], atk[0]);
            printf("��q: %d     ���m: %d\n", hp[0], def[0]);
            printf("�j�׹w��: %.2f\n", predict_char1);
            //����2
            float predict_char2 = (hp[1] * 1.0 + atk[1] * 0.8 + def[1] * 0.5 - 50) * 6.5;
            printf("\n����2\n�W��: %s\n�ݩ�: %c      ����: %d\n", char2_name, type[1], atk[1]);
            printf("��q: %d     ���m: %d\n", hp[1], def[1]);
            printf("�j�׹w��: %.2f\n", predict_char2);
            //����3
            float predict_char3 = (hp[2] * 1.0 + atk[2] * 0.8 + def[2] * 0.5 - 50) * 6.5;
            printf("\n����3\n�W��: %s\n�ݩ�: %c      ����: %d\n", char3_name, type[2], atk[2]);
            printf("��q: %d     ���m: %d\n", hp[2], def[2]);
            printf("�j�׹w��: %.2f\n\n", predict_char3);
            //����4(�YNewChar��1�h��X)
            if (NewChar == 1)
            {
                float predict_char4 = (hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5 - 50) * 6.5;
                printf("\n����4\n�W��: %s\n�ݩ�: %c      ����: %d\n", char4_name, type[3], atk[3]);
                printf("��q: %d     ���m: %d\n", hp[3], def[3]);
                printf("�j�׹w��: %.2f\n\n", predict_char4);
            }
        }
        else if (choice == 3)
        {
            int FirstAtk, SecondAtk;//����,���
            int error_first, error_second, error;//���𨤦���~,��𨤦���~,���ƿ��
            do{
                printf("��ܥ��𨤦�:");//�M�w���𨤦�
                scanf(" %d", &FirstAtk);
                if (NewChar == 0)//�S������4
                {
                    if (FirstAtk != 1 && FirstAtk != 2 && FirstAtk != 3)
                    {
                        printf("���~:�L������\n");
                        error_first = 1;//���𨤦���~
                    }
                    else
                        error_first = 0;
                }
                else if (NewChar == 1)//������4
                {
                    if (FirstAtk != 1 && FirstAtk != 2 && FirstAtk != 3 && FirstAtk != 4)
                    {
                        printf("���~:�L������\n");
                        error_first = 1;//���𨤦���~
                    }
                    else
                        error_first = 0;//��J�L�~�Nerror_first�k�s
                }
                else
                    error_first = 0;//��J�L�~�Nerror_first�k�s
            }while(error_first == 1);
            do{
                printf("��ܫ�𨤦�:");//�M�w��𨤦�
                scanf(" %d", &SecondAtk);
                if (NewChar == 0)//�S������4
                {
                    if (SecondAtk != 1 && SecondAtk != 2 && SecondAtk != 3)
                    {
                        printf("���~:�L������\n");
                        error_second = 1;//��𨤦���~
                    }
                    else
                        error_second = 0;
                }
                else if (NewChar == 1)//������4
                {
                    if (SecondAtk != 1 && SecondAtk != 2 && SecondAtk != 3 && SecondAtk != 4)
                    {
                        printf("���~:�L������\n");
                        error_second = 1;//��𨤦���~
                    }
                    else
                        error_second = 0;
                }
                else if (FirstAtk == SecondAtk)//���ƿ���P�@�Ө���
                {
                    printf("���~:���i���ƿ��\n");
                    error = 1;//���⭫�ƿ��
                }
                else
                {
                    error_second = 0;//��J�L�~�Nerror_second�k�s
                    error = 0;//�S�����ƱNerror�k�s
                }
            }while(error_second == 1 || error == 1);
            printf("\n���𬰨���%d�B��𬰨���%d\n", FirstAtk, SecondAtk);
            printf("�԰��}�l\n");
            //���𨤦���
            char FirstAtk_type;
            int FirstAtk_hp, FirstAtk_atk, FirstAtk_def;
            //��𨤦���
            char SecondAtk_type;
            int SecondAtk_hp, SecondAtk_atk, SecondAtk_def;
            //�N���𨤦��ƨ��X
            if (FirstAtk == 1)
                FirstAtk_type = type[0], FirstAtk_hp = hp[0], FirstAtk_atk = atk[0], FirstAtk_def = def[0];
            else if (FirstAtk == 2)
                FirstAtk_type = type[1], FirstAtk_hp = hp[1], FirstAtk_atk = atk[1], FirstAtk_def = def[1];
            else if (FirstAtk == 3)
                FirstAtk_type = type[2], FirstAtk_hp = hp[2], FirstAtk_atk = atk[2], FirstAtk_def = def[2];
            else if (FirstAtk == 4)
                FirstAtk_type = type[3], FirstAtk_hp = hp[3], FirstAtk_atk = atk[3], FirstAtk_def = def[3];
            //�N��𨤦��ƨ��X
            if (SecondAtk == 1)
                SecondAtk_type = type[0], SecondAtk_hp = hp[0], SecondAtk_atk = atk[0], SecondAtk_def = def[0];
            else if (SecondAtk == 2)
                SecondAtk_type = type[1], SecondAtk_hp = hp[1], SecondAtk_atk = atk[1], SecondAtk_def = def[1];
            else if (SecondAtk == 3)
                SecondAtk_type = type[2], SecondAtk_hp = hp[2], SecondAtk_atk = atk[2], SecondAtk_def = def[2];
            else if (SecondAtk == 4)
                SecondAtk_type = type[3], SecondAtk_hp = hp[3], SecondAtk_atk = atk[3], SecondAtk_def = def[3];
            ("%d %d\n", FirstAtk_hp, SecondAtk_hp);
            float FirstAtk_type_val, SecondAtk_type_val;//�ݩʬ۫g���v
            float first_low_hp = 1.0, second_low_hp = 1.0;//�ݦ孿�v
            //�ݩʬ۫g���v
            if (FirstAtk_type == 'W' && SecondAtk_type == 'F')//W > F
                FirstAtk_type_val = 1.2, SecondAtk_type_val = 0.8;
            else if (FirstAtk_type == 'F' && SecondAtk_type == 'A')// F > A
                FirstAtk_type_val = 1.2, SecondAtk_type_val = 0.8;
            else if (FirstAtk_type == 'A' && SecondAtk_type == 'G')// A > G
                FirstAtk_type_val = 1.2, SecondAtk_type_val = 0.8;
            else if (FirstAtk_type == 'G' && SecondAtk_type == 'W')// G > W
                FirstAtk_type_val = 1.2, SecondAtk_type_val = 0.8;
            else
                FirstAtk_type_val = 1.0, SecondAtk_type_val = 1.0;
            //printf("%d\n", FirstAtk_hp);
            int FirstAtk_dam, SecondAtk_dam;
                int first_initial_hp = FirstAtk_hp;
                int second_initial_hp = SecondAtk_hp;
            for (int i = 1; i != 0; i++)//�Q��for�j�����԰�
            {
                //����^�X
                FirstAtk_dam = (int)(FirstAtk_atk * FirstAtk_type_val * first_low_hp - SecondAtk_def);
                printf("\n����%d �﨤��%d �o�ʧ����A�y�� %d �I�ˮ`\n", FirstAtk, SecondAtk, FirstAtk_dam);
                SecondAtk_hp -= FirstAtk_dam;//�Q������Ѿl��q
                printf("����%d HP: %d  ����%d HP: %d\n", FirstAtk, FirstAtk_hp, SecondAtk, SecondAtk_hp);
                if (FirstAtk_hp <= 0 || SecondAtk_hp <= 0)//�P�_����P���O�_���@���q�C��0
                {
                    i = -1;//�����@���q�C��0�h�Ni�ܦ�-1 �g�Li++�ܬ�0 ���X�j��
                    continue;//�Yif�P�_�����߫h������U�����ԭz�y
                }

                if (SecondAtk_hp < second_initial_hp / 2)
                    second_low_hp = 1.2;
                //���^�X
                SecondAtk_dam = (int)(SecondAtk_atk * SecondAtk_type_val * second_low_hp - FirstAtk_def);
                printf("\n����%d �﨤��%d �o�ʧ����A�y�� %d �I�ˮ`\n", SecondAtk, FirstAtk, SecondAtk_dam);
                FirstAtk_hp -= SecondAtk_dam;//�Q������Ѿl��q
                printf("����%d HP: %d  ����%d HP: %d\n", FirstAtk, FirstAtk_hp, SecondAtk, SecondAtk_hp);
                if (FirstAtk_hp <= 0 || SecondAtk_hp <= 0)//�P�_����P���O�_���@���q�C��0
                {
                    i = -1;//�����@���q�C��0�h�Ni�ܦ�-1 �g�Li++�ܬ�0 ���X�j��
                }
                if (FirstAtk_hp < first_initial_hp / 2)
                    first_low_hp = 1.2;
            }
            if (FirstAtk_hp <= 0)
                printf("\n����%d ���h�԰���O\n�԰�����\n\n����%d ���\n\n", FirstAtk, SecondAtk);
            else if (SecondAtk_hp <= 0)
                printf("\n����%d ���h�԰���O\n�԰�����\n\n����%d ���\n\n", SecondAtk, FirstAtk);
        }
    }
    return 0;
}
