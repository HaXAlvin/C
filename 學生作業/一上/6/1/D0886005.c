#include<stdio.h>
#include<stdlib.h>
int main() {
    //����1
    char char1_type = 'W';
    int char1_hp = 45;
    int char1_atk = 18;
    int char1_def = 6;
    float char1=(char1_hp* 1.0 + char1_atk* 0.8 + char1_def* 0.5 - 50 ) * 6.5;
    //����2
    char char2_type = 'G';
    int char2_hp = 43;
    int char2_atk = 17;
    int char2_def = 5;
    float char2=(char2_hp* 1.0 + char2_atk* 0.8 + char2_def* 0.5 - 50 ) * 6.5;
    //����3
    char char3_type = 'A';
    int char3_hp = 48;
    int char3_atk = 15;
    int char3_def = 7;
    float char3=(char3_hp* 1.0 + char3_atk* 0.8 + char3_def* 0.5 - 50 ) * 6.5;


    printf("����1\n�W��:�p�Q\n�ݩ�:W    ����:18\n��q:45   ���m:6\n����j�׹w��:%.2f\n"
           "����2\n�W��:���I\n�ݩ�:G    ����:17\n��q:43   ���m:5\n����j�׹w��:%.2f\n"
           "����3\n�W��:���B\n�ݩ�:A    ����:15\n��q:48   ���m:7\n����j�׹w��:%.2f\n",char1,char2,char3
          );
    //�ۭq����
    char char4_type ;
    int char4_hp ;
    int char4_atk ;
    int char4_def ;
    int hurt1; //��������y�����ˮ`
    int hurt2; //�������y�����ˮ`
    int char5; //���𨤦⪺�ܼ�
    int char5_hp ;
    int char5_atk ;
    int char5_def ;
    int char6;   //��𨤦⪺�ܼ�
    int char6_hp  ;
    int char6_atk ;
    int char6_def ;
    int fall; //�����J���~
    int ans; //�^���O�_�s�W����

    do {
        printf("�O�_�s�W�s����(1.yes/2.no)?");
        scanf("%d",&ans);
        if(ans==1) {
            do {
                printf("�s�W����\n");
                printf("�п�J�ݩ�(F=���BW=���BG=�g�BA=��):");
                scanf(" %c",&char4_type);
                printf("�п�J�����O:");
                scanf("%d",&char4_atk);
                printf("�п�J��q:");
                scanf("%d",&char4_hp);
                printf("�п�J���m�O:");
                scanf("%d",&char4_def);
                int sum=char4_hp+char4_atk+char4_def; //����ƭ��`�M
                if((char4_type=='F'||char4_type=='W'||char4_type=='G'||char4_type=='A')&&(char4_atk>15&&char4_atk<20)&&(char4_hp<50&&char4_hp>40)&&(char4_def>5&&char4_def<10)&&(sum<70&&sum>65)) { //�Y�ݩʬ��j�g �B��O�ƭȬҩM��O�d��ҥ��T
                    printf("�ۭq����\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w��:%.2f\n",char4_type,char4_atk,char4_hp,char4_def, (char4_hp* 1.0 + char4_atk* 0.8 + char4_def* 0.5 - 50 ) * 6.5);
                    fall=1;
                    break;
                } else if((char4_type==102||char4_type==119||char4_type==103||char4_type==97)&&(char4_atk>15&&char4_atk<20)&&(char4_hp<50&&char4_hp>40)&&(char4_def>5&&char4_def<10)&&(sum<70&&sum>65)) { //�Y�ݩʬ��p�g �B��O�ƭȬҩM��O�d��ҥ��T
                    printf("�ۭq����\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w��:%.2f\n",char4_type-32,char4_atk,char4_hp,char4_def, (char4_hp* 1.0 + char4_atk* 0.8 + char4_def* 0.5 - 50 ) * 6.5);
                    fall=1;
                    break;
                } else if((char4_type=='f'||char4_type=='w'||char4_type=='g'||char4_type=='a'||char4_type=='F'||char4_type=='W'||char4_type=='G'||char4_type=='A')&&((char4_atk<15||char4_atk>20)||(char4_hp>50||char4_hp<40)||(char4_def<5||char4_def>10)||(sum>=70||sum<=65))) {
                    printf("���~:��O�ƭȦb����d�򤧥~\n"); //�Y�ݩʿ�J���T ����O�ƭȩί�O�d�򦳿�
                    fall=0;
                } else if((char4_type!='f'||char4_type!='w'||char4_type!='g'||char4_type!='a'||char4_type!='F'||char4_type!='W'||char4_type!='G'||char4_type!='A')&&((char4_atk<15||char4_atk>20)||(char4_hp>50||char4_hp<40)||(char4_def<5||char4_def>10)||(sum>=70||sum<=65))) {
                    printf("���~:�L���ݩ�\n���~:��O�ƭȦb����d�򤧥~\n"); // //�Y�ݩʿ�J�����T �B��O�ƭȩί�O�d�򦳿�
                    fall=0;
                } else if((char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a'&&char4_type!='F'&&char4_type!='W'&&char4_type!='G'&&char4_type!='A')&&((char4_atk>15||char4_atk<20)||(char4_hp<50||char4_hp>40)||(char4_def>5||char4_def<10)||(sum<70||sum>65))) {
                    printf("���~:�L���ݩ�\n"); // //�Y�ݩʿ�J�����T ����O�ƭȩM��O�d�򥿽T
                    fall=0;
                }
            } while(fall==0);
        }
        if(ans==2) {
            do {
                fall=1;
                printf("��ܥ��𨤦�:");
                scanf("%d",&char5);
                if (1<=char5&&char5<=3) { //�Y����Ʀr��J���T
                    do {
                        printf("��ܫ�𨤦�:");
                        scanf("%d",&char6);
                        if(char5==char6) { //�Y����ۦP
                            printf("���i���ƿ��\n");
                            fall=0;
                        } else if (1<=char6&&char6<=3) { // �Y����Ʀr��J���T �B���⤣�ۦP
                            printf("���𬰨���%d�B��𨤦⬰%d\n",char5,char6);
                            switch(char5) {
                            case 1: //�Y��J��1
                                char5_hp= char1_hp;
                                char5_atk= char1_atk;
                                char5_def= char1_def;
                                break;
                            case 2: //�Y��J��2
                                char5_hp= char2_hp;
                                char5_atk= char2_atk;
                                char5_def= char2_def;
                                break;
                            case 3: //�Y��J��3
                                char5_hp= char3_hp;
                                char5_atk= char3_atk;
                                char5_def= char3_def;
                                break;
                            case 4: //�Y��J��4
                                char5_hp= char4_hp;
                                char5_atk= char4_atk;
                                char5_def= char4_def;
                                break;
                            }
                            switch(char6) {
                            case 1: //�Y��J��1
                                char6_hp= char1_hp;
                                char6_atk= char1_atk;
                                char6_def= char1_def;
                                break;
                            case 2: //�Y��J��2
                                char6_hp= char2_hp;
                                char6_atk= char2_atk;
                                char6_def= char2_def;
                                break;
                            case 3: //�Y��J��3
                                char6_hp= char3_hp;
                                char6_atk= char3_atk;
                                char6_def= char3_def;
                                break;
                            case 4: //�Y��J��4
                                char6_hp= char4_hp;
                                char6_atk= char4_atk;
                                char6_def= char4_def;
                                break;
                            }
                            printf("�԰��}�l\n");
                            while(char5_hp>0) {
                                hurt1=char5_atk-char6_def; //���𪺧����ˮ`�ƭ�
                                char6_hp=char6_hp-hurt1;//���Q�����᪺��q
                                printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n",char5,char6,hurt1);
                                printf("���� %d HP:%d ���� %d HP:%d\n",char5,char5_hp,char6,char6_hp);
                                if(char6_hp>0) {
                                    hurt2=char6_atk-char5_def; //��𪺧����ˮ`�ƭ�
                                    char5_hp=char5_hp-hurt2;//����Q�����᪺��q
                                    printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n",char6,char5,hurt2);
                                    printf("���� %d HP:%d ���� %d HP:%d\n",char6,char6_hp,char5,char5_hp);
                                    continue;
                                } else
                                    printf("���� %d ���h�԰��O\n�԰�����\n\n���� %d ���\n",char6,char5);
                                return 0;
                            }
                        } else //��J�L�����Ÿ�
                            printf("���~:�L������\n");
                        fall=0;
                    } while(fall==0);
                }

                else //��J�L�����Ÿ�
                    printf("���~:�L������\n");
                fall=0;
            } while(fall==0);
        } else if(ans>2) { //��J���~����
            printf("��J���~\n");
            fall=0;
        }
    } while(fall==0);


    do {
        printf("��ܥ��𨤦�:");
        scanf("%d",&char5);
        if (1<=char5&&char5<=4) { //�Y����Ʀr��J���T
            do {
                printf("��ܫ�𨤦�:");
                scanf("%d",&char6);
                if(char5==char6) { //�Y����ۦP
                    printf("���i���ƿ��\n");
                    fall=0;
                } else if (1<=char6&&char6<=4) { // �Y����Ʀr��J���T �B���⤣�ۦP
                    printf("���𬰨���%d�B��𨤦⬰%d\n",char5,char6);
                    switch(char5) {
                    case 1: //�Y��J��1
                        char5_hp= char1_hp;
                        char5_atk= char1_atk;
                        char5_def= char1_def;
                        break;
                    case 2: //�Y��J��2
                        char5_hp= char2_hp;
                        char5_atk= char2_atk;
                        char5_def= char2_def;
                        break;
                    case 3: //�Y��J��3
                        char5_hp= char3_hp;
                        char5_atk= char3_atk;
                        char5_def= char3_def;
                        break;
                    case 4: //�Y��J��4
                        char5_hp= char4_hp;
                        char5_atk= char4_atk;
                        char5_def= char4_def;
                        break;
                    }
                    switch(char6) {
                    case 1: //�Y��J��1
                        char6_hp= char1_hp;
                        char6_atk= char1_atk;
                        char6_def= char1_def;
                        break;
                    case 2: //�Y��J��2
                        char6_hp= char2_hp;
                        char6_atk= char2_atk;
                        char6_def= char2_def;
                        break;
                    case 3: //�Y��J��3
                        char6_hp= char3_hp;
                        char6_atk= char3_atk;
                        char6_def= char3_def;
                        break;
                    case 4: //�Y��J��4
                        char6_hp= char4_hp;
                        char6_atk= char4_atk;
                        char6_def= char4_def;
                        break;
                    }
                    printf("�԰��}�l\n");
                    while(char5_hp>0) { //������q�j��0
                        hurt1=char5_atk-char6_def; //���𪺧����ˮ`�ƭ�
                        char6_hp=char6_hp-hurt1;//���Q�����᪺��q
                        printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n",char5,char6,hurt1);
                        printf("���� %d HP:%d ���� %d HP:%d\n",char5,char5_hp,char6,char6_hp);
                        if(char6_hp>0) { //�p�G����q�j��0
                            hurt2=char6_atk-char5_def; //��𪺧����ˮ`�ƭ�
                            char5_hp=char5_hp-hurt2;//����Q�����᪺��q
                            printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n",char6,char5,hurt2);
                            printf("���� %d HP:%d ���� %d HP:%d\n",char6,char6_hp,char5,char5_hp);
                            continue;
                        } else
                            printf("���� %d ���h�԰��O\n�԰�����\n\n���� %d ���\n",char6,char5);
                        return 0;
                    }
                } else //��J�L�����Ÿ�
                    printf("���~:�L������\n");
                fall=0;
            } while(fall==0);
        }

        else //��J�L�����Ÿ�
            printf("���~:�L������\n");
        fall=0;
    } while(fall==0);

    return 0;
}

