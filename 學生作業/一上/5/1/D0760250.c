#include <stdio.h>
#include <stdlib.h>

int main()
{
    //�ѥ��ܥk���O��:"�O�_�n�s�W����"����J�B�פ�{���P�_�ȡB���𨤦�B��𨤦�
    int user_input,end_value=0,select_char1,select_char2;

    char char1_type = 'F';
    int char1_hp = 40;
    int char1_atk = 15;
    int char1_def = 10;
    char char2_type = 'W';
    int char2_hp = 45;
    int char2_atk = 20;
    int char2_def = 5;
    char char3_type = 'A';
    int char3_hp = 40;
    int char3_atk = 20;
    int char3_def = 10;
    char char0_type;
    int char0_hp,char0_atk,char0_def ;

    printf("����1\n�W�١GSKY\n�ݩ�\�G%c     ����\�G%d\n��q\�G%d    ���m\�G%d\n����j�׹w���G%.2f\n\n"
           ,char1_type,char1_atk,char1_hp,char1_def,(char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5);
    printf("����2\n�W�١GSUN\n�ݩ�\�G%c     ����\�G%d\n��q\�G%d    ���m\�G%d\n����j�׹w���G%.2f\n\n"
           ,char2_type,char2_atk,char2_hp,char2_def,(char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5);
    printf("����3\n�W�١GDUST\n�ݩ�\�G%c     ����\�G%d\n��q\�G%d    ���m\�G%d\n����j�׹w���G%.2f\n\n"
           ,char3_type,char3_atk,char3_hp,char3_def,(char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5);

    printf("�O�_�n�s�W����(1.YES/2.NO)? ");
    scanf("%d%*c",&user_input);
    if(user_input==1){
        printf("\n�s�W����(�ݩ��`�M=65~70)\n�ݩ�(F/W/G/A):");
        scanf("%c",&char0_type);
        //�p�G�O�p�g�A�h�ഫ���j�g
        if((char0_type=='f')||(char0_type=='w')||(char0_type=='g')||(char0_type=='a')){
            char0_type=char0_type-32;
        }
        printf("��J����(15~20):");
        scanf("%d",&char0_atk);
        printf("��J��q(40~50):");
        scanf("%d%*c",&char0_hp);
        printf("��J���m(5~10):");
        scanf("%d",&char0_def);
        //�p���ݩʤ�����FWGA�A�hend_value+1
        if((char0_type!='F')&&(char0_type!='W')&&(char0_type!='G')&&(char0_type!='A')){
            printf("���~:�L���ݩ�\n");
            end_value++;
        }
        //�P�_��O�ƭȬO�_�b����d�򤺡A�p�G���_�A�hend_value+1
        if(!(char0_atk>=15&&char0_atk<=20)||!(char0_hp>=40&&char0_hp<=50)||!(char0_def>=5&&char0_def<=10)||
           !(char0_atk+char0_hp+char0_def>=65&&char0_atk+char0_hp+char0_def<=70)){
            printf("���~:��O�ƭȦb����d�򤧥~\n");
            end_value++;
        }
        //�p�G�e�ⶵif���󳣬����A�h�L�X�ۭq����
        if(end_value==0){
            printf("\n");
            printf("����4\n�W�١G�ۭq����\n�ݩ�\�G%c     ����\�G%d\n��q\�G%d    ���m\�G%d\n����j�׹w���G%.2f\n\n"
                   ,char0_type,char0_atk,char0_hp,char0_def,(char0_hp*1.0+char0_atk*0.8+char0_def*0.5-50)*6.5);
        }
        //�p�G�̫e���ⶵif���󦳤@�Ӭ��u�A�h�פ�{��
        else{
            return 0;
        }
    }
    //�p�G"�O�_�n�s�W����"����J������1 or 2�A�h�פ�{��
    else if(user_input!=1&&user_input!=2){
        printf("��J���~");
        return 0;
    }
    if(user_input==1||user_input==2){
        printf("��ܥ��𨤦�:");
        scanf("%d",&select_char1);
        //�P�_����O�_�s�b(�ѩ�"�O�_�n�s�W����"=1�ɡA�|�s�W����4�A�ҥH����|��3��)
        if(select_char1<1||(select_char1>3&&user_input!=1)||(select_char1>4&&user_input==1)){
            printf("���~:�L������");
            return 0;
        }
        printf("��ܫ�𨤦�:");
        scanf("%d",&select_char2);
        //�P�_����O�_�s�b
        if(select_char2<1||(select_char2>3&&user_input!=1)||(select_char2>4&&user_input==1)){
            printf("���~:�L������");
            return 0;
        }
        else if(select_char1==select_char2){
            printf("���~:���i���ƿ��");
            return 0;
        }
        else{
            printf("\n");
            printf("���𨤦⬰%d�B��𨤦⬰%d",select_char1,select_char2);
        }
    }
    return 0;
}


