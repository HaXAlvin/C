#include <stdio.h>

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
    printf("�O�_�s�W����(1.Yes/2.No)? ");
    scanf(" %d", &reply);
    if (reply == 2)
    {
        printf("\n��ܥ��𨤦�:");//�M�w���𨤦�
        scanf(" %d", &fir);
        if (fir != 1 && fir != 2 && fir != 3)
        {
            printf("���~:�L������");//�D����1~3
            return 0;
        }
        printf("��ܫ�𨤦�:");//�M�w��𨤦�
        scanf(" %d", &sec);
        if (sec != 1 && sec != 2 && sec != 3)//�D����1~3
        {
             printf("���~:�L������");
            return 0;
        }
        if (fir == sec)//���ƿ���P�@�Ө���
            printf("���~:���i���ƿ��");
        printf("\n���𬰨���%d�B��𬰨���%d\n", fir, sec);
        return 0;
    }
    else if (reply == 1)//��J�s�W����ƭ�
    {
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
            if (char4_atk < 15 || char4_atk > 20 || char4_hp < 40 || char4_hp > 50 || char4_def < 5 || char4_def > 10)//�P�_�ݩʿ��~��A�P�_��O�ƭȭ���
            {
                printf("���~:��O�ƭȦb����d�򤧥~\n");
            }
            else if (char4_sum < 65 || char4_sum > 70)//�P�_�ݩʿ��~��A�P�_�T���`�M�O�_�W�X�d��
            {
                printf("���~:��O�ƭȦb����d�򤧥~\n");
            }
            return 0;
        }
        if (char4_atk < 15 || char4_atk > 20 || char4_hp < 40 || char4_hp > 50 || char4_def < 5 || char4_def > 10)//�ݩʵL�~����P�_��O�ƭȭ���
        {
            printf("���~:��O�ƭȦb����d�򤧥~\n");
            return 0;
        }
        else if (char4_sum < 65 || char4_sum > 70)//�ݩʵL�~����P�_�T���`�M�W�X�d��
        {
            printf("���~:��O�ƭȦb����d�򤧥~\n");
            return 0;
        }
        else //�Y�ݩʵL�~�B��O�ƭȬҦb�d�򤺫h��ܨ���4
        {
            float char4_str = (char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5; //����4���j�׹w����
            printf("\n����4\n�W��: �۸�\n�ݩ�: %c      ����: %d\n", char4_type, char4_atk);
            printf("��q: %d     ���m: %d\n", char4_hp, char4_def);
            printf("�j�׹w��: %.2f\n\n", char4_str);
        }
        printf("��ܥ��𨤦�:");
        scanf(" %d", &fir);//�M�w���𨤦�
        if (fir != 1 && fir != 2 && fir != 3 && fir != 4)//�D����1~4
        {
            printf("���~:�L������\n");
            return 0;
        }
        printf("��ܫ�𨤦�:");//�M�w��𨤦�
        scanf(" %d", &sec);
        if (sec != 1 && sec != 2 && sec != 3 && sec != 4)//�D����1~4
        {
            printf("���~:�L������\n");
            return 0;
        }
        if (fir == sec)//���ƿ���P�@�Ө���
        {
            printf("���~:���i���ƿ��\n");
            return 0;
        }
        printf("\n���𬰨���%d�B��𬰨���%d\n", fir, sec);//��ܥ���P��𨤦�
    }
    else
    {
        printf("��J���~!\n");//reply �D1&2
        return 0;
    }
    return 0;
}
