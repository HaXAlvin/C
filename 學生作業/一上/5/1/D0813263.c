#include<stdio.h>
int main() {
    //����1
    char char1_type = 'F';
    int char1_hp = 48;
    int char1_atk = 16;
    int char1_def = 6;
    //����2
    char char2_type = 'G';
    int char2_hp = 41;
    int char2_atk = 19;
    int char2_def = 9;
    //����3
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
    //����1 �W��:���O�� �ݩ�:F ��q:48 �����O:16 ���m�O:6 �`�M70
    //����2 �W��:�����N �ݩ�:G ��q:41�����O:19 ���m�O:9 �`�M69
    //����3 �W��:�_�դ�� �ݩ�:A ��q:46 �����O:15 ���m�O:7 �`�M68
    printf("����1\n�W��:���O��\n�ݩ�:%c\t\t��q:%d\n�����O:%d\t���m�O:%d\n�j�׹w��:%.2f\n\n",char1_type,char1_hp,char1_atk,char1_def,va1);
    printf("����2\n�W��:�����N\n�ݩ�:%c\t\t��q:%d\n�����O:%d\t���m�O:%d\n�j�׹w��:%.2f\n\n",char2_type,char2_hp,char2_atk,char2_def,va2);
    printf("����3\n�W��:�_�դ��\n�ݩ�:%c\t\t��q:%d\n�����O:%d\t���m�O:%d\n�j�׹w��:%.2f\n\n",char3_type,char3_hp,char3_atk,char3_def,va3);
    //��ܬO�_�s�W����
    printf("�O�_�s�W����(1.Yes/2.No)? ");
    //�O�@�s���num
    int num;
    //��J���1��2�Ψ�L�Ʀr
    scanf("%d",&num);
    //�O�_�s�W������1.Yes
    if (num==1){
        printf("�s�W����\n");
        printf("�ݩ�:");
        scanf(" %c",&char4_type);
        printf("��q:");
        scanf("%d",&char4_hp);
        printf("�����O:");
        scanf("%d",&char4_atk);
        printf("���m�O:");
        scanf("%d",&char4_def);
        //�ݩʦr���]�w
        if (char4_type!='F'&&char4_type!='W'&&char4_type!='G'&&char4_type!='A'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a'){
            printf("���~:�L���ݩ�\n");
        }
        //atk,def,hp�T���`�M
        int sum=char4_atk+char4_def+char4_hp;
        //��O�ȱ���]�w
        if (char4_atk<15||char4_atk>20||char4_def<5||char4_def>10||char4_hp<40||char4_hp>50||sum<65||sum>70){
            printf("���~:��O�ƭȦb����d�򤧥~");
        }
        //�p�G�ݩʩί�O�Ȧ��@����Ψ�̿��Nreturn 0
        if ((char4_type!='F'&&char4_type!='W'&&char4_type!='G'&&char4_type!='A'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a')||char4_atk<15||char4_atk>20||char4_def<5||char4_def>10||char4_hp<40||char4_hp>50||sum<65||sum>70)
            return 0;
        //�ݩʤj�p�g�ഫ
        if (islower(char4_type)){
           char4_type=toupper(char4_type);
        }
        //�j�׹w����k
        float va4=((char4_hp*1.0)+(char4_atk*0.8)+(char4_def*0.5)-50)*6.5;

        printf("\n����4\n����W��:�ۭq����\n�ݩ�:%c\t\t��q:%d\n�����O:%d\t���m�O:%d\n�j�׹w��:%.2f\n\n",char4_type,char4_hp,char4_atk,char4_def,va4);
        //��ܥ���𨤦�
        printf("��ܥ��𨤦�:");
        int atk1;
        scanf("%d",&atk1);
        printf("��ܫ�𨤦�:");
        int atk2;
        scanf("%d",&atk2);
        //�����𪺭Ȥ��o�W�L4
        if (atk1>4||atk2>4){
            printf("���~:�L������");
            return 0;
        }
        //�����𤣱o�۵�
        if (atk1==atk2){
            printf("���~:���i���ƿ��");
            return 0;
        }
        printf("\n���𬰨���%d�B��𬰨���%d",atk1,atk2);
    }
    //�O�_�s�W������2.No
    if (num==2){
        printf("��ܥ��𨤦�:");
        int atk1;
        scanf("%d",&atk1);
        printf("��ܫ�𨤦�:");
        int atk2;
        scanf("%d",&atk2);
        //�����𪺭Ȥ��o�W�L4
        if (atk1>4||atk2>4){
            printf("���~:�L������");
            return 0;
        }
        printf("���𬰨���%d�B��𬰨���%d",atk1,atk2);
        //�����𤣱o�۵�
        if (atk1==atk2){
            printf("���~:���i���ƿ��");
        }
    }
    //�O�_�s�W�����ܤ�����1.2.
    if (num!=1&&num!=2){
        printf("��J���~");
    }
    return 0;
}
