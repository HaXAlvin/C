#include <stdio.h>

int main() {
//�ŧi�ܼ�
    char Char1_type='W',Char2_type='F',Char3_type='G',Char4_type;//�ݩ�
    int Char1_atk=15,Char2_atk=20,Char3_atk=15,Char4_atk;//����
    int Char1_hp=50,Char2_hp=40,Char3_hp=45,Char4_hp;//��q
    int Char1_def=5,Char2_def=5,Char3_def=10,Char4_def;//���m
    int Add,Char4_all,Char_num=3,Char_frist,Char_last,is_tf=0;//�s�W����,����4�ƭ��`�M,�����`��,����,���,����Ӫ�flag
//���ب���
    printf("����1 \n");
    printf("�W��:�ǥ��t \n");
    printf("�ݩ�:%c    ����:%d  \n",Char1_type,Char1_atk);
    printf("��q:%d   ���m:%d  \n",Char1_hp,Char1_def);
    printf("�j�׹w��:%.2f\n",( Char1_hp * 1.0 + Char1_atk * 0.8 + Char1_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
    printf("����2 \n");
    printf("�W��:�p���s \n");
    printf("�ݩ�:%c    ����:%d  \n",Char2_type,Char2_atk);
    printf("��q:%d   ���m:%d  \n",Char2_hp,Char2_def);
    printf("�j�׹w��:%.2f\n",( Char2_hp * 1.0 + Char2_atk * 0.8 + Char2_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
    printf("����3 \n");
    printf("�W��:�p���� \n");
    printf("�ݩ�:%c    ����:%d  \n",Char2_type,Char2_atk);
    printf("��q:%d   ���m:%d  \n",Char2_hp,Char2_def);
    printf("�j�׹w��:%.2f\n",( Char3_hp * 1.0 + Char3_atk * 0.8 + Char3_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
//�s�W����
    printf("�O�_�s�W����(1.Yes/2.No)?");
    scanf("%d",&Add);
    getchar();
    printf ("\n");
    if(Add==1) {
        Char_num++;
        printf("�s�W����\n");
        printf("�ݩ�:");
        scanf("%c",&Char4_type);
        getchar();
        printf("��q:");
        scanf("%d",&Char4_hp);
        getchar();
        printf("����:");
        scanf("%d",&Char4_atk);
        getchar();
        printf("���m:");
        scanf("%d",&Char4_def);
        getchar();
//�ˬd�ݩ�
        if(Char4_type!='F'&&Char4_type!='f'&&Char4_type!='W'&&Char4_type!='w'&&
                Char4_type!='G'&&Char4_type!='g'&&Char4_type!='A'&&Char4_type!='a') {
            printf("���~:�L���ݩ�\n");
            //��ԣ��&&���O||
            is_tf = 1;
        }
//�p�g���j�g
        else if(Char4_type=='f') {
            Char4_type='F';
        } else if(Char4_type=='w') {
            Char4_type='W';
        } else if(Char4_type=='g') {
            Char4_type='G';
        } else if(Char4_type=='a') {
            Char4_type='A';
        }
//�ˬd�ƭ�
        Char4_all = Char4_hp+Char4_atk+Char4_def;
        if((Char4_hp<40||Char4_hp>50)||(Char4_atk<15||Char4_atk>20)||(Char4_def<5||
                Char4_def>10)||(Char4_all<65||Char4_all>70)) {
            printf("���~:��O�ƭȦb����d�򤧥~\n");
            return 0;
        }
//�ݩʿ���
        if(is_tf==1) {
            return 0;
        }
//��ܨ���4
        printf ("\n");
        printf("����4 \n");
        printf("�W��:�ۭq���� \n");
        printf("�ݩ�:%c    ����:%d  \n",Char4_type,Char4_atk);
        printf("��q:%d   ���m:%d  \n",Char4_hp,Char4_def);
        printf("�j�׹w��:%.2f\n",( Char4_hp * 1.0 + Char4_atk * 0.8 + Char4_def * 0.5 - 50 ) * 6.5);
        printf ("\n");
    } else if(Add==2) {
    } else {
        printf("��J���~\n");
        return 0;
    }
//��ܥ����
    printf("��ܥ��𨤦�: ");
    scanf("%d",&Char_frist);
    if(Char_frist<=0||Char_frist>Char_num) {
        printf("���~:�L������\n");
        return 0;
    }
    printf("��ܫ�𨤦�: ");
    scanf("%d",&Char_last);
    if(Char_last<=0||Char_last>Char_num) {
        printf("���~:�L������\n");
        return 0;
    }
    printf("\n���𬰨���%d�B��𬰨���%d\n",Char_frist,Char_last);
}

