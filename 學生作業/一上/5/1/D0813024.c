#include<stdio.h>
#include<stdlib.h>

int main() {

    //����1
    char char1_type = 'G';
    int char1_hp = 50;
    int char1_atk = 15;
    int char1_def = 5;

    //����2
    char char2_type = 'F';
    int char2_hp = 42;
    int char2_atk = 19;
    int char2_def = 7;

    //����3
    char char3_type = 'A';
    int char3_hp = 44;
    int char3_atk = 17;
    int char3_def = 8;

    //����4(�ۦ��J)
    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;

    //�j�׹w������
    float hp_pd = 1.0;
    float atk_pd = 0.8;
    float def_pd = 0.5;
    //�Ͽ��~�⦸��������
    int is_error=0;
    //����1�ƭ�
    printf("����1\n"
           "�W��:aibo \n"
           "�ݩ�:%c   ����:%d\n"
           "��q:%d  ���m:%d\n"
           ,char1_type,char1_atk,char1_hp,char1_def);

    printf("����j�׹w��:%.2f\n\n",(char1_hp*hp_pd)+(char1_atk*atk_pd)+(char1_def*def_pd)-50);
    //����2�ƭ�
    printf("����2\n"
           "�W��:���D�B  \n"
           "�ݩ�:%c   ����:%d\n"
           "��q:%d  ���m:%d\n"
           ,char2_type,char2_atk,char2_hp,char2_def);

    printf("����j�׹w��:%.2f\n\n",(char2_hp*hp_pd)+(char2_atk*atk_pd)+(char2_def*def_pd)-50);
    //����3�ƭ�
    printf("����3\n"
           "�W��:�����l  \n"
           "�ݩ�:%c   ����:%d  \n"
           "��q:%d  ���m:%d  \n"
           ,char3_type,char3_atk,char3_hp,char3_def);

    printf("����j�׹w��:%.2f\n\n",(char3_hp*hp_pd)+(char3_atk*atk_pd)+(char3_def*def_pd)-50);


    int quest;

    //�O�_�s�W����
    printf("�O�_�s�W����(1.Yes/2.No)? ");

    scanf("%d",&quest);
    getchar();
    //�Y�ﶵ��1�A��ܳХߨ���4
    if(quest == 1) {
        printf("�s�W����\n"
               "����W��:�ۭq����\n");
        printf("�ݩ�:");
        scanf("%c",&char4_type);

        printf("��q:");
        scanf("%d",&char4_hp);

        printf("����:");
        scanf("%d",&char4_atk);

        printf("���m:");
        scanf("%d",&char4_def);
        //�ƭȭ���
        if(char4_type != 'F' && char4_type != 'W' && char4_type != 'G' && char4_type != 'A' &&
                char4_type != 'f' && char4_type != 'w' && char4_type != 'g' && char4_type != 'a') {
            printf("���~:�L���ݩ�\n"),is_error=1;
        }
        //�N�ݩʤp�g�ন�j�g
        else if(char4_type == 'f') {
            char4_type = 'F';
        } else if(char4_type == 'w') {
            char4_type = 'W';
        } else if(char4_type == 'g') {
            char4_type = 'G';
        } else if(char4_type == 'a') {
            char4_type = 'A';
        }

        if(char4_hp >50 || char4_hp <40 ||
                char4_atk >20 || char4_atk <15 ||
                char4_def >10 ||  char4_def <5) {
            printf("���~:��O�ƭȦb����d�򤧥~");
            return 0;
        }
        if((char4_hp + char4_atk  + char4_def) >70 || (char4_hp + char4_atk  + char4_def) <65 ) {
            printf("���~:��O�ƭȦb����d�򤧥~");
            return 0;
        }
        if(is_error==1) {
            return 0;
        }

        printf("\n");

        printf("����4\n"
               "�W��:�ۭq����  \n"
               "�ݩ�:%c   ����:%d  \n"
               "��q:%d  ���m:%d   \n"
               ,char4_type,char4_atk,char4_hp,char4_def);
        printf("����j�׹w��:%.2f\n\n",(char4_hp*hp_pd)+(char4_atk*atk_pd)+(char4_def*def_pd)-50);
    }

    //�Y�ﶵ��2�A�����i�J�﨤���`

    else if(quest == 2) {
        int player1;
        int player2;

        printf("��ܥ��𨤦�:");
        scanf("%d",&player1);
        if(player1 !=1 &&  player1 !=2 && player1 !=3) { //�u�i��ܨ���1,2,3
            printf("�����⤣�s�b");
            return 0;
        }

        printf("��ܫ�𨤦�:");
        scanf("%d",&player2);
        if(player2 !=1 &&  player2 !=2 && player2 !=3) { //�u�i��ܨ���1,2,3
            printf("�����⤣�s�b");
            return 0;
        }

        if(player1 == player2) {                        //���⤣�i����
            printf("���i���ƿ��");
            return 0;
        }

        printf("���𬰨���%d�B��𬰨��⬰%d",player1,player2);
        return 0;
    }

    //��J���~��

    else if(quest !=1 & quest !=2) {
        printf("��J���~");
        return 0;
    }

    //����4�[�J�ɿ﨤���`

    int player1;
    int player2;

    printf("��ܥ��𨤦�:");
    scanf("%d",&player1);
    if(player1 !=1 &&  player1 !=2 && player1 !=3 && player1 !=4) { //�u�i��ܨ���1,2,3,4
        printf("�����⤣�s�b");
        return 0;
    }

    printf("��ܫ�𨤦�:");
    scanf("%d",&player2);
    if(player2 !=1 &&  player2 !=2 && player2 !=3&& player2 !=4) {  //�u�i��ܨ���1,2,3,4
        printf("�����⤣�s�b");
        return 0;
    }

    if(player1 == player2) {                                        //���⤣�i����
        printf("���i���ƿ��");
        return 0;
    }

    printf("���𬰨���%d�B��𬰨��⬰%d",player1,player2);
    return 0;



    return 0;

}
