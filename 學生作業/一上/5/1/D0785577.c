#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

int main()
{
    //�ܼƨ̧Ǭ��G1.�ݩ� 2.��q 3.���� 4.���m 5.����j��    
    //����j�רϥ�float�Ӭ����p���I
    //����j�פ����G( ��q * 1.0 + ���� * 0.8 + ���m * 0.5 - 50 ) * 6.5

    //����1 
    char char1_type = 'F';
    int char1_hp  = 45;
    int char1_atk = 20;
    int char1_def = 5;
    float char1_combat = (char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5 - 50) * 6.5; 

    //����2 
    char char2_type = 'G';
    int char2_hp  = 50;
    int char2_atk = 15;
    int char2_def = 5;
    float char2_combat = (char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5 - 50) * 6.5;

    //����3
    char char3_type = 'W';
    int char3_hp  = 45;
    int char3_atk = 15;
    int char3_def = 10;
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
    //�ܼƨ̧Ǭ��G1.����j�� 2.�ݩ� 3.��q 4.���� 5.���m 6.���𨤦� 7.��𨤦� 8.�T�{�O�_�s�W����

    float charN_combat; 
    char charN_type;
    int charN_hp;
    int charN_atk;
    int charN_def;
    int firstattack;
    int nextattack;
    int check;

    printf("�O�_�s�W����(1.Yes/2.No)�H");
    scanf("%d", &check);

  
    //�ƾڭ���G
    //�ݩʡGF = ���BW = ���BG = �g�BA = ���C���i��JF�BW�BG�BA�Bf�Bw�Bg�Ba�H�~���^��r���C
    //��q�G40~50�����
    //�����G15~20�����
    //���m�G5~10�����
    //�T���`�M�b65~70����

    //��ܷs�W����
    if(check==1)
    {
        //��J����ƭ�
        printf("\n�s�W����\n"
               "�ݩʡG");
        getchar();                  //�ϥ� getchar �Y�����Enter�U�Ӫ��r��
        scanf("%c", &charN_type);
        printf("��q�G");
        scanf("%d", &charN_hp);
        printf("�����G");
        scanf("%d", &charN_atk);
        printf("���m�G");
        scanf("%d", &charN_def);
        
        //�p�g��j�g
        if (islower(charN_type))
            charN_type = toupper(charN_type);

        //�ݩʤ��s�b
        if (!(charN_type == 'F' || charN_type == 'W' || charN_type == 'G' || charN_type == 'A'))
        {
            printf("���~�G�L���ݩ�\n");
        }

        //�ƾڽd����~
        if (!(charN_hp >= 40 && charN_hp <= 50 && charN_atk >= 15 && charN_atk <= 20 && charN_def >= 5 &&
            charN_def <= 10 && charN_hp + charN_atk + charN_def >= 65 && charN_hp + charN_atk + charN_def <= 70))
        {
            printf("���~�G��O�ƭȦb����d�򤧥~\n");
        }

        //�ŦX�]�w���d��
        if ((charN_type == 'F' || charN_type == 'W' || charN_type == 'G' || charN_type == 'A') &&
            charN_hp >= 40 && charN_hp <= 50 && charN_atk >= 15 && charN_atk <= 20 && charN_def >= 5 &&
            charN_def <= 10 && charN_hp + charN_atk + charN_def >= 65 && charN_hp + charN_atk + charN_def <= 70)
        {
            printf("\n����4\n"
                   "�W�١G�ۭq����\n"
                   "�ݩʡG%c     �����G%d\n"
                   "��q�G%d    ���m�G%d\n", charN_type, charN_atk, charN_hp, charN_def);

            charN_combat = (charN_hp * 1.0 + charN_atk * 0.8 + charN_def * 0.5 - 50) * 6.5;

            printf("����j�׹w���G%.2f\n", charN_combat);

            printf("\n��ܥ��𨤦�G");
            scanf("%d", &firstattack);

            //�T�{����O�_�s�b
            if (firstattack > 4)
            {
                printf("�L������\n");
                return 0;
            }

            printf("��ܫ�𨤦�G");
            scanf("%d", &nextattack);

            if (nextattack > 4)
            {
                printf("�L������\n");
                return 0;
            }

            //�T�{�O�_���ƿ��
            if (nextattack == firstattack)
            {
                printf("���~�G���i���ƿ��\n");
                return 0;
            }

            printf("\n���𨤦⬰%d�A��𨤦⬰%d\n", firstattack, nextattack);

        }

        //���ŦX�s�W������� �����{��

        else 
            return 0;

    }

    //��ܤ��s�W����
    else if (check == 2)

    {

        printf("\n��ܥ��𨤦�G");
        scanf("%d", &firstattack);

        //�T�{����O�_�s�b
        if (firstattack > 3)
        {
            printf("�L������\n");
            return 0;
        }

        printf("��ܫ�𨤦�G");
        scanf("%d", &nextattack);

        if (nextattack > 3)
        {
            printf("�L������\n");
            return 0;
        }

        //�T�{�O�_���ƿ��
        if (nextattack == firstattack)
        {
            printf("���~�G���i���ƿ��\n");
            return 0;
        }

        printf("\n���𨤦⬰%d�A��𨤦⬰%d\n", firstattack, nextattack);

    }

    //�s�W��������J���~
    else
        printf("��J���~\n");

    return 0;
}

