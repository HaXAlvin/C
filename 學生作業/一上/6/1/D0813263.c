#include<stdio.h>
int main() {
    //����1 �j��70
    char char1_type = 'F';
    int char1_hp = 48;
    int char1_atk = 16;
    int char1_def = 6;
    //����2 �j��69
    char char2_type = 'G';
    int char2_hp = 41;
    int char2_atk = 19;
    int char2_def = 9;
    //����3 �j��68
    char char3_type = 'A';
    int char3_hp = 46;
    int char3_atk = 15;
    int char3_def = 7;
    //�ۭq����
    char char4_type ;
    int char4_hp ;
    int char4_atk;
    int char4_def ;
    //�j�׹w����k
    float va1=((char1_hp*1.0)+(char1_atk*0.8)+(char1_def*0.5)-50)*6.5;
    float va2=((char2_hp*1.0)+(char2_atk*0.8)+(char2_def*0.5)-50)*6.5;
    float va3=((char3_hp*1.0)+(char3_atk*0.8)+(char3_def*0.5)-50)*6.5;

    printf("����1\n�W��:���O��\n�ݩ�:%c\t\t��q:%d\n�����O:%d\t���m�O:%d\n�j�׹w��:%.2f\n\n",char1_type,char1_hp,char1_atk,char1_def,va1);
    printf("����2\n�W��:�����N\n�ݩ�:%c\t\t��q:%d\n�����O:%d\t���m�O:%d\n�j�׹w��:%.2f\n\n",char2_type,char2_hp,char2_atk,char2_def,va2);
    printf("����3\n�W��:�_�դ��\n�ݩ�:%c\t\t��q:%d\n�����O:%d\t���m�O:%d\n�j�׹w��:%.2f\n\n",char3_type,char3_hp,char3_atk,char3_def,va3);

    int num;
    int n=0;
    int first_atk,second_atk;

    printf("�O�_�s�W����(1.Yes/2.No)? ");
    scanf("%d",&num);
    //�O�_�s�W�����ܤ�����1.2.�h���s��J
    if (num!=1&&num!=2)
        do {
            n=0;
            printf("��J���~\n");
            printf("�O�_�s�W����(1.Yes/2.No)? ");
            scanf("%d",&num);
        }while(n==1);
    //�O�_�s�W������1.Yes
    if (num==1){
        do {
            n=0;
            printf("\n�s�W����\n");
            printf("�ݩ�:");
            scanf(" %c",&char4_type);
            printf("��q:");
            scanf("%d",&char4_hp);
            printf("�����O:");
            scanf("%d",&char4_atk);
            printf("���m�O:");
            scanf("%d",&char4_def);
            //�ݩʿ��~���s��J
            int sum=char4_atk+char4_def+char4_hp;
            if (char4_type!='F'&&char4_type!='W'&&char4_type!='G'&&char4_type!='A'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a'){
                printf("���~:�L���ݩ�\n");
                n=1;
            }
            //��O�ȿ��~���s��J
            if (char4_atk<15||char4_atk>20||char4_def<5||char4_def>10||char4_hp<40||char4_hp>50||sum<65||sum>70){
                printf("���~:��O�ƭȦb����d�򤧥~\n");
                n=1;
            }
        }while(n==1);
        //�ݩʤj�p�g�ഫ
        if (islower(char4_type)){
           char4_type=toupper(char4_type);
        }
        //�j�׹w����k
        float va4=((char4_hp*1.0)+(char4_atk*0.8)+(char4_def*0.5)-50)*6.5;

        printf("\n����4\n����W��:�ۭq����\n�ݩ�:%c\t\t��q:%d\n�����O:%d\t���m�O:%d\n�j�׹w��:%.2f\n\n",char4_type,char4_hp,char4_atk,char4_def,va4);
        //��ܥ���𨤦�
        do{
            n=0;
            printf("��ܥ��𨤦�:");
            scanf("%d",&first_atk);
            if (first_atk>4){
                printf("���~:�L������\n");
                n=1;
            }
        }while(n==1);
        do{
            n=0;
            printf("��ܫ�𨤦�:");
            scanf("%d",&second_atk);
            if (second_atk>4){
                printf("���~:�L������\n");
                n=1;
            }
        }while(n==1);
        if (first_atk==second_atk){
            printf("���~:���i���ƿ��\n");
            n=1;
        }
    }
    //�O�_�s�W������2.No�B��ܥ���𨤦�
    if (num==2){
        do{
            n=0;
            printf("��ܥ��𨤦�:");
            scanf("%d",&first_atk);
            if (first_atk>4){
                printf("���~:�L������\n");
                n=1;
            }
        }while(n==1);
        do{
            n=0;
            printf("��ܫ�𨤦�:");
            scanf("%d",&second_atk);
            if (second_atk>4){
                printf("���~:�L������\n");
                n=1;
            }
        }while(n==1);
        if (first_atk==second_atk){
            printf("���~:���i���ƿ��\n");
            n=1;
        }
    }
    printf("\n���𬰨���%d�B��𬰨���%d",first_atk,second_atk);
    printf("\n�԰��}�l");
    //���X����ƾ�
    int atk1_hp,atk2_hp,atk1_atk,atk2_atk,atk1_def,atk2_def;
    switch (first_atk){
        case 1:
            atk1_hp=char1_hp;
            atk1_atk=char1_atk;
            atk1_def=char1_def;
            break;
        case 2:
            atk1_hp=char2_hp;
            atk1_atk=char2_atk;
            atk1_def=char2_def;
            break;
        case 3:
            atk1_hp=char3_hp;
            atk1_atk=char3_atk;
            atk1_def=char3_def;
            break;
        case 4:
            atk1_hp=char4_hp;
            atk1_atk=char4_atk;
            atk1_def=char4_def;
            break;
    }
    switch (second_atk){
        case 1:
            atk2_hp=char1_hp;
            atk2_atk=char1_atk;
            atk2_def=char1_def;
            break;
        case 2:
            atk2_hp=char2_hp;
            atk2_atk=char2_atk;
            atk2_def=char2_def;
            break;
        case 3:
            atk2_hp=char3_hp;
            atk2_atk=char3_atk;
            atk2_def=char3_def;
            break;
        case 4:
            atk2_hp=char4_hp;
            atk2_atk=char4_atk;
            atk2_def=char4_def;
            break;
    }
    int atk1_hurt,atk2_hurt;
    atk1_hurt=atk1_atk-atk2_def;//����1�����O-����2���m�O
    atk2_hurt=atk2_atk-atk1_def;//����2�����O-����1���m�O
    //�����^�X���
    while (atk1_hp>0||atk2_hp>0){
        atk2_hp-=atk1_hurt;//���ۧ����ᤧ��q
        printf("\n\n����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n����%d HP:%d ����%d HP:%d\n",first_atk,second_atk,atk1_hurt,first_atk,atk1_hp,second_atk,atk2_hp);
        if (atk2_hp<=0){
            printf("\n����%d ���h�԰���O\n�԰�����\n\n",second_atk);
            printf("����%d ���",first_atk);
            return 0;
        }
        atk1_hp-=atk2_hurt;//���ۧ����ᤧ��q
        printf("\n\n����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n����%d HP:%d ����%d HP:%d\n",second_atk,first_atk,atk2_hurt,first_atk,atk1_hp,second_atk,atk2_hp);
        if (atk1_hp<=0){
            printf("\n����%d ���h�԰���O\n�԰�����\n\n",first_atk);
            printf("����%d ���",second_atk);
            return 0;
        }
    }
    return 0;
}







