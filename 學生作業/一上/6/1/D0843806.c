#include <stdio.h>
int char1_atk;
int main()
{
    //����1
    char char1_type = 'F';
    int char1_atk = 19;
    int char1_hp = 43;
    int char1_def = 7;
    float char1_str = (char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;
    printf("����1\n�W��: ���N\n�ݩ�: %c      ����: %d\n", char1_type, char1_atk);
    printf("��q: %d     ���m: %d\n", char1_hp, char1_def);
    printf("�j�׹w��: %.2f\n\n", char1_str);
    //����2
    char char2_type = 'W';
    int char2_atk = 15;
    int char2_hp = 46;
    int char2_def = 8;
    float char2_str = (char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
    printf("����2\n�W��: �d��\n�ݩ�: %c      ����: %d\n", char2_type, char2_atk);
    printf("��q: %d     ���m: %d\n", char2_hp, char2_def);
    printf("�j�׹w��: %.2f\n\n", char2_str);
    //����3
    char char3_type = 'W';
    int char3_atk = 17;
    int char3_hp = 45;
    int char3_def = 6;
    float char3_str = (char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
    printf("����3\n�W��: �p��\n�ݩ�: %c      ����: %d\n", char3_type, char3_atk);
    printf("��q: %d     ���m: %d\n", char3_hp, char3_def);
    printf("�j�׹w��: %.2f\n\n", char3_str);

    int reply;
    char char4_type;//�ݩ�
    int char4_atk;//����
    int char4_hp;//��q
    int char4_def;//���m
    int fir, sec;//����,���

    //printf("�O�_�s�W����(1.Yes/2.No)? ");
    //scanf(" %d", &reply);
    while (printf("�O�_�s�W����(1.Yes/2.No)? "), scanf("%d", &reply) && (reply != 1 && reply != 2))
    {
        printf("��J���~!\n");//�Y�D��J1 or 2 �h��ܿ�J���~�B���s��J
    }
    if (reply == 2)
    {
        int error1, error2, error3;
        do{
            printf("\n��ܥ��𨤦�:");//�M�w���𨤦�
            scanf(" %d", &fir);
            if (fir != 1 && fir != 2 && fir != 3)
            {
                printf("���~:�L������");//�D����1~3
                error1 = 1;//���𨤦���~
            }
            else
                error1 = 0;//��J�L�~�Nerror1�k0
        }while (error1 == 1);
        do{
            printf("��ܫ�𨤦�:");//�M�w��𨤦�
            scanf(" %d", &sec);
            if (sec != 1 && sec != 2 && sec != 3)//�D����1~3
            {
                printf("���~:�L������\n");
                error2 = 1;//��𨤦���~
            }
            else if (fir == sec)//���ƿ���P�@�Ө���
            {
                printf("���~:���i���ƿ��\n");
                error3 = 1;//���⭫�ƿ��
            }
            else
            {
                error2 = 0;//��J�L�~�Nerror2�k0
                error3 = 0;//�S�����ƱNerror3�k0
            }
        }while (error2 == 1 || error3 == 1);
        printf("\n���𬰨���%d�B��𬰨���%d\n", fir, sec);
        printf("�԰��}�l\n");
        int fir_atk, fir_hp, fir_def;//�ŧi���𨤦⪺���
        switch (fir){//���𨤦�
            case 1://�N����1����ƨ��X
                fir_atk = char1_atk;
                fir_hp = char1_hp;
                fir_def = char1_def;
                break;
            case 2://�N����2����ƨ��X
                fir_atk = char2_atk;
                fir_hp = char2_hp;
                fir_def = char2_def;
                break;
            case 3://�N����3����ƨ��X
                fir_atk = char3_atk;
                fir_hp = char3_hp;
                fir_def = char3_def;
                break;
        }
        int sec_atk, sec_hp, sec_def;//�ŧi��𨤦⪺���
        switch (sec){//��𨤦�
            case 1://�N����1����ƨ��X
                sec_atk = char1_atk;
                sec_hp = char1_hp;
                sec_def = char1_def;
                break;
            case 2://�N����2����ƨ��X
                sec_atk = char2_atk;
                sec_hp = char2_hp;
                sec_def = char2_def;
                break;
            case 3://�N����3����ƨ��X
                sec_atk = char3_atk;
                sec_hp = char3_hp;
                sec_def = char3_def;
                break;
        }
        for (int i = 1; i != 0; i++)//�Q��for�j�����԰�
        {
            //����^�X
            printf("\n����%d �﨤��%d �o�ʧ����A�y�� %d �I�ˮ`\n", fir, sec, fir_atk - sec_def);
            sec_hp = sec_hp - (fir_atk - sec_def);//�Q������Ѿl��q
            printf("����%d HP: %d  ����%d HP: %d\n", fir, fir_hp, sec, sec_hp);
            if (fir_hp <= 0 || sec_hp <= 0)//�P�_����P���O�_���@���q�C��0
            {
                i = -1;//�����@���q�C��0�h�Ni�ܦ�-1 �g�Li++�ܬ�0 ���X�j��
                continue;//�Yif�P�_�����߫h������U�����ԭz�y
            }
            printf("����%d �﨤��%d �o�ʧ����A�y�� %d �I�ˮ`\n", sec, fir, sec_atk - fir_def);
            fir_hp = fir_hp - (sec_atk - fir_def);
            printf("����%d HP: %d  ����%d HP: %d\n", fir, fir_hp, sec, sec_hp);
            if (fir_hp <= 0 || sec_hp <= 0)//�P�_����P���O�_���@���q�C��0
            {
                i = -1;//�����@���q�C��0�h�Ni�ܦ�-1 �g�Li++�ܬ�0 ���X�j��
            }
        }
        if (fir_hp <= 0)
            printf("\n����%d ���h�԰���O\n�԰�����\n\n����%d ���\n", fir, sec);
        else if (sec_hp <= 0)
            printf("\n����%d ���h�԰���O\n�԰�����\n\n����%d ���\n", sec, fir);
    }
    else if (reply == 1)//��J�s�W����ƭ�
    {
        int error1, error2;//error1���ݩʿ�J���~, error2����O�W�X�d��
        do {    //�Q��do while�j�� ����J�����T��P�_�O�_��J���~
            printf("\n�s�W����\n�ݩ�:");
            scanf(" %c", &char4_type);
            printf("����:");
            scanf(" %d", &char4_atk);
            printf("��q:");
            scanf(" %d", &char4_hp);
            printf("���m:");
            scanf(" %d", &char4_def);
            int char4_sum = char4_atk + char4_hp + char4_def;//����,��q,���m���`�M
            if (char4_type == 'f')//f�ܦ�F
            {
                char4_type = 'F';
            }
            else if (char4_type == 'w')//w�ܦ�W
            {
                char4_type = 'W';
            }
            else if (char4_type == 'g')//g�ܦ�G
            {
                char4_type = 'G';
            }
            else if (char4_type == 'a')//a�ܦ�A
            {
                char4_type = 'A';
            }
            if (char4_type != 'F' && char4_type != 'W' && char4_type != 'G' && char4_type != 'A')//�P�_�ݩʭ���
            {
                printf("���~:�L���ݩ�\n");
                error1 = 1;//�ݩʿ�J���~
                if (char4_atk < 15 || char4_atk > 20 || char4_hp < 40 || char4_hp > 50 || char4_def < 5 || char4_def > 10)//�P�_�ݩʿ��~��A�P�_��O�ƭȭ���
                {
                    printf("���~:��O�ƭȦb����d�򤧥~\n");
                    error2 = 1;//��O�W�X�d��
                }
                else if (char4_sum < 65 || char4_sum > 70)//�P�_�ݩʿ��~��A�P�_�T���`�M�O�_�W�X�d��
                {
                    printf("���~:��O�ƭȦb����d�򤧥~\n");
                    error2 = 1;//��O�W�X�d��
                }
                continue;
            }
            if (char4_atk < 15 || char4_atk > 20 || char4_hp < 40 || char4_hp > 50 || char4_def < 5 || char4_def > 10)//�ݩʵL�~����P�_��O�ƭȭ���
            {
                printf("���~:��O�ƭȦb����d�򤧥~\n");
                error2 = 1;//��O�W�X�d��
            }
            else if (char4_sum < 65 || char4_sum > 70)//�ݩʵL�~����P�_�T���`�M�W�X�d��
            {
                printf("���~:��O�ƭȦb����d�򤧥~\n");
                error2 = 1;//��O�W�X�d��
            }
            else //�Y�ݩʵL�~�B��O�ƭȬҦb�d�򤺫h��ܨ���4
            {
                error1 = 0, error2 = 0;//�Y��J�ҥ��T�h�Nerror�k0
                float char4_str = (char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5; //����4���j�׹w����
                printf("\n����4\n�W��: �۸�\n�ݩ�: %c      ����: %d\n", char4_type, char4_atk);
                printf("��q: %d     ���m: %d\n", char4_hp, char4_def);
                printf("�j�׹w��: %.2f\n\n", char4_str);
            }
        }while (error1 == 1 || error2 == 1);
        int error3, error4, error5;
        do{
            printf("��ܥ��𨤦�:");
            scanf(" %d", &fir);//�M�w���𨤦�
            if (fir != 1 && fir != 2 && fir != 3 && fir != 4)//�D����1~4
            {
                printf("���~:�L������\n");
                error3 = 1;//���𨤦���~
            }
            else
                error3 = 0;//���𨤦�L�~�Nerror3�k0
        }while (error3 == 1);
        do{
            printf("��ܫ�𨤦�:");//�M�w��𨤦�
            scanf(" %d", &sec);
            if (sec != 1 && sec != 2 && sec != 3 && sec != 4)//�D����1~4
            {
                printf("���~:�L������\n");
                error4 = 1;//��𨤦���~
            }
            else if (fir == sec)//���ƿ���P�@�Ө���
            {
                printf("���~:���i���ƿ��\n");
                error5 = 1;//���ƿ��
            }
            else
            {
                 error4 = 0;//��𨤦�L�~�Nerror4�k0
                 error5 = 0;//�S�����ƿ���Nerror5�k0
            }
        }while (error4 == 1 || error5 == 1);

        printf("\n���𬰨���%d�B��𬰨���%d\n", fir, sec);//��ܥ���P��𨤦�
        printf("�԰��}�l\n");
        int fir_atk, fir_hp, fir_def;//�ŧi���𨤦⪺���
        switch (fir){//���𨤦�
            case 1:
                fir_atk = char1_atk;
                fir_hp = char1_hp;
                fir_def = char1_def;
                break;
            case 2:
                fir_atk = char2_atk;
                fir_hp = char2_hp;
                fir_def = char2_def;
                break;
            case 3:
                fir_atk = char3_atk;
                fir_hp = char3_hp;
                fir_def = char3_def;
                break;
            case 4:
                fir_atk = char4_atk;
                fir_hp = char4_hp;
                fir_def = char4_def;
                break;
        }
        int sec_atk, sec_hp, sec_def;//�ŧi��𨤦⪺���
        switch (sec){
            case 1:
                sec_atk = char1_atk;
                sec_hp = char1_hp;
                sec_def = char1_def;
                break;
            case 2:
                sec_atk = char2_atk;
                sec_hp = char2_hp;
                sec_def = char2_def;
                break;
            case 3:
                sec_atk = char3_atk;
                sec_hp = char3_hp;
                sec_def = char3_def;
                break;
            case 4:
                sec_atk = char4_atk;
                sec_hp = char4_hp;
                sec_def = char4_def;
                break;
        }
        for (int i = 1; i != 0; i++)//�Q��for�j�����԰�
        {
            //����^�X
            printf("\n����%d �﨤��%d �o�ʧ����A�y�� %d �I�ˮ`\n", fir, sec, fir_atk - sec_def);
            sec_hp = sec_hp - (fir_atk - sec_def);//�Q������Ѿl��q
            printf("����%d HP: %d  ����%d HP: %d\n", fir, fir_hp, sec, sec_hp);
            if (fir_hp <= 0 || sec_hp <= 0)//�P�_����P���O�_���@���q�C��0
            {
                i = -1;//�����@���q�C��0�h�Ni�ܦ�-1 �g�Li++�ܬ�0 ���X�j��
                continue;//�Yif�P�_�����߫h������U�����ԭz�y
            }
            printf("����%d �﨤��%d �o�ʧ����A�y�� %d �I�ˮ`\n", sec, fir, sec_atk - fir_def);
            fir_hp = fir_hp - (sec_atk - fir_def);
            printf("����%d HP: %d  ����%d HP: %d\n", fir, fir_hp, sec, sec_hp);
            if (fir_hp <= 0 || sec_hp <= 0)//�P�_����P���O�_���@���q�C��0
            {
                i = -1;//�����@���q�C��0�h�Ni�ܦ�-1 �g�Li++�ܬ�0 ���X�j��
            }
        }
        if (fir_hp <= 0)
            printf("\n����%d ���h�԰���O\n�԰�����\n\n����%d ���\n", fir, sec);
        else if (sec_hp <= 0)
            printf("\n����%d ���h�԰���O\n�԰�����\n\n����%d ���\n", sec, fir);
    }
    return 0;
}
