#include <stdio.h>
#include <stdlib.h>

int main()
{
    //�ѥ��ܥk���O��:"�O�_�n�s�W����"����J�B�O�_�~��j��P�_�ȡB���𨤦�B��𨤦�BĹ�a�B��a
    int user_input=0,repeat_value=1,select_char1,select_char2,win,lose;
    //�����𪺼ƾڸ��
    int select_char1_hp,select_char1_atk,select_char1_def;
    int select_char2_hp,select_char2_atk,select_char2_def;

    char char1_type = 'F';
    int char1_hp = 50;
    int char1_atk = 15;
    int char1_def = 5;
    char char2_type = 'W';
    int char2_hp = 45;
    int char2_atk = 20;
    int char2_def = 5;
    char char3_type = 'A';
    int char3_hp = 40;
    int char3_atk = 20;
    int char3_def = 10;
    char char4_type;
    int char4_hp,char4_atk,char4_def ;

    printf("����1\n�W�١GSKY\n�ݩ�\�G%c     ����\�G%d\n��q\�G%d    ���m\�G%d\n����j�׹w���G%.2f\n\n"
           ,char1_type,char1_atk,char1_hp,char1_def,(char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5);
    printf("����2\n�W�١GSUN\n�ݩ�\�G%c     ����\�G%d\n��q\�G%d    ���m\�G%d\n����j�׹w���G%.2f\n\n"
           ,char2_type,char2_atk,char2_hp,char2_def,(char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5);
    printf("����3\n�W�١GDUST\n�ݩ�\�G%c     ����\�G%d\n��q\�G%d    ���m\�G%d\n����j�׹w���G%.2f\n\n"
           ,char3_type,char3_atk,char3_hp,char3_def,(char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5);

    //�p�Guser_input������1or2�A�h�A���߰�"�O�_�n�s�W����"
    while(user_input!=1&&user_input!=2){
        printf("�O�_�n�s�W����(1.YES/2.NO)? ");
        scanf("%d%*c",&user_input);
        if(user_input==1){
            while(repeat_value==1){
                repeat_value=0;
                printf("\n�s�W����(�ݩ��`�M=65~70)\n�ݩ�(F/W/G/A):");
                scanf("%c",&char4_type);
                //�p�G�O�p�g�A�h�ഫ���j�g
                if((char4_type=='f')||(char4_type=='w')||(char4_type=='g')||(char4_type=='a')){
                    char4_type=char4_type-32;
                }
                printf("��J��q(40~50):");
                scanf("%d",&char4_hp);
                printf("��J����(15~20):");
                scanf("%d",&char4_atk);
                printf("��J���m(5~10):");
                scanf("%d%*c",&char4_def);
                //�p�G�ݩʤ�����FWGA�A�hrepeat_value=1�A�~�򭫽ƿ�J������
                if((char4_type!='F')&&(char4_type!='W')&&(char4_type!='G')&&(char4_type!='A')){
                    printf("���~:�L���ݩ�\n");
                    repeat_value=1;
                }
                //�P�_��O�ƭȬO�_�b����d�򤺡A�p�G���_�A�hrepeat_value=1�A�~�򭫽ƿ�J������
                if(!(char4_atk>=15&&char4_atk<=20)||!(char4_hp>=40&&char4_hp<=50)||!(char4_def>=5&&char4_def<=10)||
                   !(char4_atk+char4_hp+char4_def>=65&&char4_atk+char4_hp+char4_def<=70)){
                    printf("���~:��O�ƭȦb����d�򤧥~\n");
                    repeat_value=1;
                }
                //�p�G�e�ⶵif���󳣬����A�h�L�X�ۭq����
                if(repeat_value==0){
                    printf("\n");
                    printf("����4\n�W�١G�ۭq����\n�ݩ�\�G%c     ����\�G%d\n��q\�G%d    ���m\�G%d\n����j�׹w���G%.2f\n\n"
                           ,char4_type,char4_atk,char4_hp,char4_def,(char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5);
                }
            }
        }

        //�p�G"�O�_�n�s�W����"����J������1 or 2�A�h�L�X"��J���~"
        else if(user_input!=1&&user_input!=2){
            printf("��J���~\n");
        }
    }

    repeat_value=1;
    while(repeat_value==1){
        repeat_value=0;
        printf("��ܥ��𨤦�:");
        scanf("%d",&select_char1);
        //�P�_����O�_�s�b(�ѩ�"�O�_�n�s�W����"=1�ɡA�|�s�W����4�A�ҥH����|��3��)
        //�p�G��J���~�A�hrepeat_value=1�A���ƿ�J���𨤦�
        if(select_char1<1||(select_char1>3&&user_input!=1)||(select_char1>4&&user_input==1)){
            printf("���~:�L������\n");
            repeat_value=1;
        }
    }
    repeat_value=1;
    //�p�G"���~:�L������"��"���~:���i���ƿ��"�A�hrepeat_value=1�A���ƿ�J��𨤦�
    while(repeat_value==1){
        printf("��ܫ�𨤦�:");
        scanf("%d",&select_char2);
        //�P�_����O�_�s�b
        if(select_char2<1||(select_char2>3&&user_input!=1)||(select_char2>4&&user_input==1)){
            printf("���~:�L������\n");
            repeat_value=1;
        }
        else if(select_char1==select_char2){
            printf("���~:���i���ƿ��\n");
            repeat_value=1;
        }
        //�p�G��J���T�A�h�N�����𨤦�ƭȨ��X
        else{
            printf("\n���𨤦⬰%d�B��𨤦⬰%d\n",select_char1,select_char2);
            switch(select_char1){
                case 1:
                    select_char1_hp=char1_hp;
                    select_char1_atk=char1_atk;
                    select_char1_def=char1_def;
                    break;
                case 2:
                    select_char1_hp=char2_hp;
                    select_char1_atk=char2_atk;
                    select_char1_def=char2_def;
                    break;
                case 3:
                    select_char1_hp=char3_hp;
                    select_char1_atk=char3_atk;
                    select_char1_def=char3_def;
                    break;
                case 4:
                    select_char1_hp=char4_hp;
                    select_char1_atk=char4_atk;
                    select_char1_def=char4_def;

            }
            switch(select_char2){
                case 1:
                    select_char2_hp=char1_hp;
                    select_char2_atk=char1_atk;
                    select_char2_def=char1_def;
                    break;
                case 2:
                    select_char2_hp=char2_hp;
                    select_char2_atk=char2_atk;
                    select_char2_def=char2_def;
                    break;
                case 3:
                    select_char2_hp=char3_hp;
                    select_char2_atk=char3_atk;
                    select_char2_def=char3_def;
                    break;
                case 4:
                    select_char2_hp=char4_hp;
                    select_char2_atk=char4_atk;
                    select_char2_def=char4_def;

            }
            repeat_value=0;//���X�j��
        }
    }
    printf("�԰��}�l\n\n");
    //�p�G�����q���S�p��0�A�h�~��԰�
    while(select_char1_hp>0&&select_char2_hp>0){
        //���𪺧���
        select_char2_hp=select_char2_hp-(select_char1_atk-select_char2_def);
        printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n����%d HP: %d ����%d HP: %d\n\n"
               ,select_char1,select_char2,select_char1_atk-select_char2_def,select_char1,select_char1_hp,select_char2,select_char2_hp);
        //�P�_�����q�A�ӨM�w�O�_���X�j��
        if(select_char1_hp<=0||select_char2_hp<=0){
            break;
        }
        //��𪺧���
        select_char1_hp=select_char1_hp-(select_char2_atk-select_char1_def);
        printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n����%d HP: %d ����%d HP: %d\n\n"
               ,select_char2,select_char1,select_char2_atk-select_char1_def,select_char1,select_char1_hp,select_char2,select_char2_hp);
    }
    //�P�_��Ĺ�a
    if(select_char1_hp<=0){
        win=select_char2;
        lose=select_char1;
    }
    else{
        win=select_char1;
        lose=select_char2;
    }
    printf("����%d ���h�԰���O\n�԰�����\n\n����%d ���",lose,win);

    return 0;
}


