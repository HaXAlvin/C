#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    //����j�פ����G( ��q * 1.0 + ���� * 0.8 + ���m * 0.5 - 50 ) * 6.5
    //�ܼƨ̧Ǭ��G1.�ݩ� 2.��q 3.���� 4.���m 5.����j��
    //����j�רϥ�float�Ӭ����p���I

    //����1
    char char1_type = 'F';
    int  char1_hp = 45;
    int  char1_atk = 20;
    int  char1_def = 5;
    float char1_combat = (char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5 - 50) * 6.5;

    //����2
    char char2_type = 'G';
    int  char2_hp = 50;
    int  char2_atk = 15;
    int  char2_def = 5;
    float char2_combat = (char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5 - 50) * 6.5;

    //����3
    char char3_type = 'W';
    int  char3_hp = 45;
    int  char3_atk = 15;
    int  char3_def = 10;
    float char3_combat = (char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5 - 50) * 6.5;

    //�`�N���n�d�V��q�M�������ܼƶ���

    printf("����1\n"
           "�W�١G����\n"
           "�ݩʡG%c     �����G%d\n"
           "��q�G%d    ���m�G%d\n", char1_type, char1_atk, char1_hp, char1_def);

    printf("����j�׹w���G%.2f\n\n", char1_combat);

    printf("����2\n"
           "�W�١G����\n"
           "�ݩʡG%c     �����G%d\n"
           "��q�G%d    ���m�G%d\n", char2_type, char2_atk, char2_hp, char2_def);

    printf("����j�׹w���G%.2f\n\n", char2_combat);

    printf("����3\n"
           "�W�١G�굲\n"
           "�ݩʡG%c     �����G%d\n"
           "��q�G%d    ���m�G%d\n", char3_type, char3_atk, char3_hp, char3_def);

    printf("����j�׹w���G%.2f\n\n", char3_combat);

    //�s�W����
    //�ܼƨ̧Ǭ��G1.����j�� 2.�ݩ� 3.��q 4.���� 5.���m 6.���𨤦� 7.��𨤦� 8.�j�鱱�� 9.�T�{�O�_�s�W����

    float charN_combat;
    char charN_type;
    int charN_hp;
    int charN_atk;
    int charN_def;
    int firstattack;
    int lastattack;
    int check;
    int create = 0;

    //�T�{�O�_�s�W����
    while (create == 0)
    {
        create = 1;
        printf("�O�_�s�W����(1.Yes/2.No)�H");
        scanf("%d", &check);

        //�s�W��������J���~ ��^�j��_�I
        if (!(check == 1 || check == 2))
        {
            printf("��J���~\n");
            create = 0;
        }
    }

    //�ƾڭ���G
    //�ݩʡGF = ���BW = ���BG = �g�BA = ���C���i��JF�BW�BG�BA�Bf�Bw�Bg�Ba�H�~���^��r���C
    //��q�G40~50�����
    //�����G15~20�����
    //���m�G5~10�����
    //�T���`�M�b65~70����

    //��ܷs�W���� �i�J��J�ƭȰj��
    while (check == 1)
    {
        check = 0;

        //��J����ƭ�
        printf("\n�s�W����\n"
               "�ݩʡG");
        //getchar();                  //�ϥ� getchar �Y�����Enter�U�Ӫ��r��
        scanf(" %c", &charN_type);
        printf("��q�G");
        scanf("%d", &charN_hp);
        printf("�����G");
        scanf("%d", &charN_atk);
        printf("���m�G");
        scanf("%d", &charN_def);

        //�p�g��j�g
        if (islower(charN_type))
            charN_type = toupper(charN_type);

        //�ݩʤ��s�b ��^��J�ƭȰj��
        if (!(charN_type == 'F' || charN_type == 'W' || charN_type == 'G' || charN_type == 'A'))
        {
            printf("���~�G�L���ݩ�\n");
            check = 1;
        }

        //�ƾڽd����~ ��^��J�ƭȰj��
        if (!(charN_hp >= 40 && charN_hp <= 50 && charN_atk >= 15 && charN_atk <= 20 && charN_def >= 5 &&
            charN_def <= 10 && charN_hp + charN_atk + charN_def >= 65 && charN_hp + charN_atk + charN_def <= 70))
        {
            printf("���~�G��O�ƭȦb����d�򤧥~\n");
            check = 1;
        }
    }

    //�ŦX�]�w���d��
    if (check == 0 && (charN_type == 'F' || charN_type == 'W' || charN_type == 'G' || charN_type == 'A') &&
        charN_hp >= 40 && charN_hp <= 50 && charN_atk >= 15 && charN_atk <= 20 && charN_def >= 5 &&
        charN_def <= 10 && charN_hp + charN_atk + charN_def >= 65 && charN_hp + charN_atk + charN_def <= 70)
    {
        //�L�X�s�W���⪺�ƭ�
        printf("\n����4\n"
               "�W�١G�ۭq����\n"
               "�ݩʡG%c     �����G%d\n"
               "��q�G%d    ���m�G%d\n", charN_type, charN_atk, charN_hp, charN_def);

        charN_combat = (charN_hp * 1.0 + charN_atk * 0.8 + charN_def * 0.5 - 50) * 6.5;

        printf("����j�׹w���G%.2f\n\n", charN_combat);

        //�﨤�j��
        while (check == 0)
        {
            check = 1;

            //������𨤦�j�� �Y������T�hcheck = 3
            while (check == 1)
            {
                check = 3;
                printf("��ܥ��𨤦�G");
                scanf("%d", &firstattack);

                //�Y���⤣�s�b �h��^������𨤦⪺�j��
                if (firstattack > 4 || firstattack < 1)
                {
                    printf("�L������\n");
                    check = 1;
                }
            }

            //�����𨤦�j�� check==3�~�|�i�J
            while (check == 3)
            {
                check = 1;
                printf("��ܫ�𨤦�G");
                scanf("%d", &lastattack);

                //�Y���⤣�s�b �h��^�����𨤦⪺�j��
                if (lastattack > 4 || lastattack < 1)
                {
                    printf("�L������\n");
                    check = 3;
                }
            }

            //�Y���ƿ�� �h��^�﨤�j��
            if (lastattack == firstattack)
            {
                printf("���~�G���i���ƿ��\n");
                check = 0;
            }
        }

        printf("\n���𬰨���%d�A��𬰨���%d\n", firstattack, lastattack);
        check = 4;    //�ǳƶi�J�԰�
    }


    //��ܤ��s�W����
    if (check == 2)
    {
        printf("\n");  //�ƪ���

        //�﨤�j��
        while (check == 2)
        {
            check = 0;

            //������𨤦�j�� �Y������T�hcheck = 3
            while (check == 0)
            {
                check = 3;
                printf("��ܥ��𨤦�G");
                scanf("%d", &firstattack);

                //�Y���⤣�s�b �h��^������𨤦⪺�j��
                if (firstattack > 3 || firstattack < 1)
                {
                    printf("�L������\n");
                    check = 0;
                }
            }

            //�����𨤦�j�� check==3�~�|�i�J
            while (check == 3)
            {
                check = 0;
                printf("��ܫ�𨤦�G");
                scanf("%d", &lastattack);

                //�Y���⤣�s�b �h��^�����𨤦⪺�j��
                if (lastattack > 3 || lastattack < 1)
                {
                    printf("�L������\n");
                    check = 3;
                }
            }

            //�Y���ƿ�� �h��^�﨤�j��
            if (lastattack == firstattack)
            {
                printf("���~�G���i���ƿ��\n");
                check = 2;
            }
        }

        printf("\n���𬰨���%d�A��𬰨���%d\n", firstattack, lastattack);
        check = 4;    //�ǳƶi�J�԰�
    }

    //�ŧi�ܼ� ���𨤦⪺�ƭ� �H�� ��𨤦⪺�ƭ�
    char first_type;
    int  first_hp;
    int  first_atk;
    int  first_def;
    char last_type;
    int  last_hp;
    int  last_atk;
    int  last_def;

    //�N�����������ƭȭӧO�ɤJ
    if (check == 4)
    {
        printf("�԰��}�l\n\n");

        if (firstattack == 1)
        {
            first_type = char1_type;
            first_hp   = char1_hp;
            first_atk  = char1_atk;
            first_def  = char1_def;
        }
        if (firstattack == 2)
        {
            first_type = char2_type;
            first_hp   = char2_hp;
            first_atk  = char2_atk;
            first_def  = char2_def;
        }
        if (firstattack == 3)
        {
            first_type = char3_type;
            first_hp   = char3_hp;
            first_atk  = char3_atk;
            first_def  = char3_def;
        }
        if (firstattack == 4)
        {
            first_type = charN_type;
            first_hp   = charN_hp;
            first_atk  = charN_atk;
            first_def  = charN_def;
        }
        if (lastattack == 1)
        {
            last_type = char1_type;
            last_hp   = char1_hp;
            last_atk  = char1_atk;
            last_def  = char1_def;
        }
        if (lastattack == 2)
        {
            last_type = char2_type;
            last_hp   = char2_hp;
            last_atk  = char2_atk;
            last_def  = char2_def;
        }
        if (lastattack == 3)
        {
            last_type = char3_type;
            last_hp   = char3_hp;
            last_atk  = char3_atk;
            last_def  = char3_def;
        }
        if (lastattack == 4)
        {
            last_type = charN_type;
            last_hp   = charN_hp;
            last_atk  = charN_atk;
            last_def  = charN_def;
        }

        check = 5; //�i�J�԰�

    }

    if (check == 5)
    {
        //�԰��j�� �@�^�X�U�ۧ����@�� �Y���𨤦⵲�������� ��𨤦��q�C��0 �h����break�X��
        while (first_hp > 0 && last_hp > 0)
        {
            last_hp = last_hp - (first_atk - last_def);
            printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", firstattack, lastattack, first_atk - last_def);
            printf("����%d HP: %d  ����%d HP: %d\n\n", firstattack, first_hp, lastattack, last_hp);

            if (last_hp <= 0)
            {
                break;
            }

            first_hp = first_hp - (last_atk - first_def);
            printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", lastattack, firstattack, last_atk - first_def);
            printf("����%d HP: %d  ����%d HP: %d\n\n", firstattack, first_hp, lastattack, last_hp);
        }
        //�P�w�ӭt
        if (first_hp <= 0)
        {
            printf("%d ���h�԰���O\n", firstattack);
            printf("�԰�����\n\n");
            printf("����%d �ӧQ\n", lastattack);
        }
        //�P�w�ӭt
        if (last_hp <= 0)
        {
            printf("����%d ���h�԰���O\n", lastattack);
            printf("�԰�����\n\n");
            printf("����%d �ӧQ\n", firstattack);
        }
    }
    return 0;
}

