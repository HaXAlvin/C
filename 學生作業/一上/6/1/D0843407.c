#include <stdio.h>

int main(){
//�ŧi�ܼ�
    char Char1_type='W',Char2_type='F',Char3_type='G';//�ŧi�ݩ�
    int Char1_atk=15,Char2_atk=20,Char3_atk=15;//�ŧi����
    int Char1_hp=50,Char2_hp=40,Char3_hp=45;//�ŧi��q
    int Char1_def=5,Char2_def=5,Char3_def=10;//�ŧi���m
//����|
    char Char4_type;//����4���ݩ�,����,��q,���m,����4�ƭ��`�M
    int Char4_atk,Char4_hp,Char4_def,Char4_all;//����4������,��q,���m,����4�ƭ��`�M
//�ˬd�ܼ�
    int Add,Char_num=3,Char_frist,Char_last;//�s�W����,�����`��,����,���
    int is_nf1=0,is_nf2=0,is_ntf=0,is_nf3=0,is_nf4=0,is_nf5=0;/*�s�W���~flag(1),�����J���~flag(2),�����J�u���ݩ�flag
                                                                                                    ���������~flag(3),��������~flag(4),����𭫽ƿ��~flag(5)*/
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
    printf("�ݩ�:%c    ����:%d  \n",Char3_type,Char3_atk);
    printf("��q:%d   ���m:%d  \n",Char3_hp,Char3_def);
    printf("�j�׹w��:%.2f\n",( Char3_hp * 1.0 + Char3_atk * 0.8 + Char3_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
//�s�W������~���Ӫ��j��(1){�t�j��2}
    while(is_nf1==0){
        printf("�O�_�s�W����(1.Yes/2.No)?");
        scanf("%d",&Add);
        getchar();
        printf ("\n");
        if(Add==1){
            is_nf1=1;//�����ưj��(1)
            Char_num++;
//�����J���~���Ӫ��j��(2)
            while(is_nf2==0){
                is_nf2=1;//�����ưj��(2)
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
                if(Char4_type!='F'&&Char4_type!='f'&&Char4_type!='W'&&Char4_type!='w'&&
                   Char4_type!='G'&&Char4_type!='g'&&Char4_type!='A'&&Char4_type!='a'){
                    printf("���~:�L���ݩ�\n");
                    //��ԣ��&&���O||
                    is_nf2=0;//���ưj��(2)
                    is_ntf=1;//�ݩʦ���
                }
//�p�g���j�g
                else if(Char4_type=='f'){
                    Char4_type='F';
                }
                else if(Char4_type=='w'){
                    Char4_type='W';
                }
                else if(Char4_type=='g'){
                    Char4_type='G';
                }
                else if(Char4_type=='a'){
                    Char4_type='A';
                }
//�ˬd�ƭ�
                Char4_all = Char4_hp+Char4_atk+Char4_def;
                if((Char4_hp<40||Char4_hp>50)||(Char4_atk<15||Char4_atk>20)||
                (Char4_def<5||Char4_def>10)||(Char4_all<65||Char4_all>70)){
                    printf("���~:��O�ƭȦb����d�򤧥~\n\n");
                    is_nf2=0;//���ưj��(2)
                    is_ntf=0;//�s�����,����Ĳ�o�����J�u���ݩ�flag
                }
//�����J�u���ݩ�,��\n���L-flag
                if(is_ntf==1){
                    printf ("\n");
                }
            }
//��ܨ���4
            printf ("\n");
            printf("����4 \n");
            printf("�W��:�ۭq���� \n");
            printf("�ݩ�:%c    ����:%d  \n",Char4_type,Char4_atk);
            printf("��q:%d   ���m:%d  \n",Char4_hp,Char4_def);
            printf("�j�׹w��:%.2f\n",( Char4_hp * 1.0 + Char4_atk * 0.8 + Char4_def * 0.5 - 50 ) * 6.5);
            printf ("\n");
        }
//���u���ݩʦ�\n
        else if(Add==2){
            is_nf1=1;//�����ưj��(1)
        }
        else{
            printf("��J���~\n\n");
        }
    }
//���⭫�ƿ�����Ӫ��j��(5){�t�j��3.4}
    while(is_nf5==0){
        is_nf5=1;//�����ưj��(5)
//���������~���Ӫ��j��(3)
        while(is_nf3==0){
            is_nf3=1;//�����ưj��(3)
            printf("��ܥ��𨤦�: ");
            scanf("%d",&Char_frist);
            if(Char_frist<=0||Char_frist>Char_num){
                printf("���~:�L������\n");
                is_nf3=0;//���ưj��(3)
            }
        }
//��������~���Ӫ��j��(4)
        while(is_nf4==0){
            is_nf4=1;//�����ưj��(4)
            printf("��ܫ�𨤦�: ");
            scanf("%d",&Char_last);
            if(Char_last<=0||Char_last>Char_num){
                printf("���~:�L������\n");
                is_nf4=0;//���ưj��(4)
            }
        }
        if(Char_last==Char_frist){
            printf("���~:���i���ƿ��\n\n");
            is_nf5=0;//���ưj��(5)
            is_nf3=0;//���s�j��(3)
            is_nf4=0;//���s�j��(4)
        }
    }
    printf("\n���𬰨���%d�B��𬰨���%d\n",Char_frist,Char_last);
//���X����ƭ�
    int FA_atk,FA_hp,FA_def;//�ŧi����ƭ�
    int LA_atk,LA_hp,LA_def;//�ŧi���ƭ�
//���𨤦�ƭȨ��X
    if(Char_frist==1){
        FA_atk=Char1_atk;
        FA_hp=Char1_hp;
        FA_def=Char1_def;
    }
    else if(Char_frist==2){
        FA_atk=Char2_atk;
        FA_hp=Char2_hp;
        FA_def=Char2_def;
    }
    else if(Char_frist==3){
        FA_atk=Char3_atk;
        FA_hp=Char3_hp;
        FA_def=Char3_def;
    }
    else if(Char_frist==4){
        FA_atk=Char4_atk;
        FA_hp=Char4_hp;
        FA_def=Char4_def;
    }
//��𨤦�ƭȨ��X
    if(Char_last==1){
        LA_atk=Char1_atk;
        LA_hp=Char1_hp;
        LA_def=Char1_def;
    }
    else if(Char_last==2){
        LA_atk=Char2_atk;
        LA_hp=Char2_hp;
        LA_def=Char2_def;
    }
    else if(Char_last==3){
        LA_atk=Char3_atk;
        LA_hp=Char3_hp;
        LA_def=Char3_def;
    }
    else if(Char_last==4){
        LA_atk=Char4_atk;
        LA_hp=Char4_hp;
        LA_def=Char4_def;
    }
//�԰��}�l
    int demage,is_whowin,winner,loser;//�ŧi�ˮ`,�ֳ�flag,�ӧQ��,���Ѫ�
    printf("�԰��}�l\n\n");
//�԰��j��(6)
    while(1){
        demage = FA_atk - LA_def;
        LA_hp -= demage;
        printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n",Char_frist,Char_last,demage);
        printf("����%d HP: %d\t����%d HP:%d\n\n",Char_frist,FA_hp,Char_last,LA_hp);
        if(LA_hp<=0){
            is_whowin=1;//�����
            break;//���X�j��(6)
        }
        demage = LA_atk - FA_def;
        FA_hp -= demage;
        printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n",Char_last,Char_frist,demage);
        printf("����%d HP: %d\t����%d HP:%d\n\n",Char_frist,FA_hp,Char_last,LA_hp);
        if(FA_hp<=0){
            is_whowin=0;//����
            break;//���X�j��(6)
        }
    }
//�ӱѧP�w
    if(is_whowin==1){
        winner=Char_frist;
        loser=Char_last;
    }
    else{
        winner=Char_last;
        loser=Char_frist;
    }
//��ܳӱ�
    printf("����%d ���h�԰���O\n",loser);
    printf("�԰�����\n\n");
    printf("����%d ���\n",winner);
    return 0;
}

