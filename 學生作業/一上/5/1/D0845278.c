#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
int main() {

    char char1_type = 'W';
    char char2_type = 'F';
    char char3_type = 'A';
    int char1_hp  = 40;
    int char2_hp  = 45;
    int char3_hp  = 42;
    int char1_atk = 20;
    int char2_atk = 15;
    int char3_atk = 17;
    int char1_def = 5 ;
    int char2_def = 10;
    int char3_def = 7 ;
    float char1_strongpre ;
    float char2_strongpre ;
    float char3_strongpre ;
    char1_strongpre = (char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5-50) * 6.5;
    char2_strongpre = (char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5-50) * 6.5;
    char3_strongpre = (char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5-50) * 6.5;
    //�j�׹w�� = ( ��q * 1.0 + ���� * 0.8 + ���m * 0.5 - 50 ) * 6.5
    printf("����1\n�W��:�C���a��\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n�j�׹w��:%.2f\n\n",char1_type,char1_atk,char1_hp,char1_def,char1_strongpre);
    printf("����2\n�W��:�V�嬰��\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n�j�׹w��:%.2f\n\n",char2_type,char2_atk,char2_hp,char2_def,char2_strongpre);
    printf("����3\n�W��:�W���S�u\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n�j�׹w��:%.2f\n\n",char3_type,char3_atk,char3_hp,char3_def,char3_strongpre);
    int addchar;
    int first_atk_char;
    int last_atk_char;
    printf("�O�_�s�W����(1.Yes/2.No)?");
    scanf("%d",&addchar);
    if(addchar==1) {	//�ϥΪ̿��"�O"
        char char4_type ;
        int char4_hp;
        int char4_atk;
        int char4_def;
        float char4_strongpre;//�s�W����4
        printf("\n�s�W����\n");
        char4_type = getchar();
        printf("����(F=���BW=���BG=�g�BA=��):");
        scanf("%c", &char4_type);
        //fflush(stdin);
        if(char4_type!='F'&&char4_type!='W'&&char4_type!='G'&&char4_type!='A'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a') { //�@���ϥεۿ�J�D�ݩʪ��r���A��ܿ��~
            printf("���~:�L���ݩ�");
            return 0;
        }
        do {
            printf("��q(40~50):");
            scanf("%d",&char4_hp);
            //fflush(stdin);
            //�W�w�ϥεۿ�J�d��,�çP�_�O�_�X�G�W�w
            do {
                if (char4_hp<40||char4_hp>50) {
                    printf("\n���~:��O�ƭȦb����d�򤧥~\n");
                    printf("��q(40~50):");
                    scanf("%d",&char4_hp);
                    //fflush(stdin);
                }
            } while(char4_hp<40||char4_hp>50);
            printf("����(15~20):");
            scanf("%d",&char4_atk);
            //fflush(stdin);
            do {
                if (char4_atk<15||char4_atk>20) {
                    printf("\n���~:��O�ƭȦb����d�򤧥~\n");
                    printf("����(15~20):");
                    scanf("%d",&char4_atk);
                    fflush(stdin);
                }
            } while(char4_atk<15||char4_atk>20);
            printf("���m(5~10):");
            scanf("%d", &char4_def);
            //fflush(stdin);
            do {
                if (char4_def<5||char4_def>10) {
                    printf("\n���~:��O�ƭȦb����d�򤧥~\n");
                    printf("���m(5~10):");
                    scanf("%d", &char4_def);
                    // 	fflush(stdin);
                }
            } while(char4_def<5||char4_def>10);
            if(char4_def + char4_hp + char4_atk<65||char4_def + char4_hp + char4_atk>70) {
                printf("\n���~:��O�ƭȦb����d�򤧥~\n");
            }
        } while(!(char4_def + char4_hp + char4_atk>=65&&char4_def + char4_hp + char4_atk<=70));
        //�p��s�W���⪺�j�סA�æL�X����4���̲׸�T
        char4_strongpre = (char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5-50) * 6.5;
        printf("\n����4\n�W��:�ۭq����\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n�j�׹w��:%.2f\n\n",toupper(char4_type),char4_atk,char4_hp,char4_def,char4_strongpre);

        printf("��ܥ��𨤦�:");
        scanf("%d",&first_atk_char);
        if(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3&&first_atk_char!=4) {	//�@����J�ëD�w�w�q����A��X���~
            printf("�L������\n");
            return 0;
        }
        printf("��ܫ�𨤦�:");
        scanf("%d",&last_atk_char);
        if(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3&&last_atk_char!=4) {	//�@����J�ëD�w�w�q����A��X���~
            printf("���~:�L������\n");
            return 0;
        }
        if(first_atk_char==last_atk_char) {	//�@�����𨤦ⵥ���𨤦�A��X���~
            printf("���~:���i���ƿ��\n");
            return 0;
        }
        printf("���𨤦⬰%d�A��𨤦⬰%d",first_atk_char,last_atk_char);	//�L�X�̲׿�J
    } else if(addchar==2) {	//�ϥΪ̿��"�_"
        printf("��ܥ��𨤦�:\n");
        scanf("%d",&first_atk_char);
        if(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3) {	//�@����J�ëD�w�w�q����A��X���~
            printf("�L������\n");
            return 0;
        }
        printf("��ܫ�𨤦�:\n");
        scanf("%d",&last_atk_char);
        if(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3) {	//�@����J�ëD�w�w�q����A��X���~
            printf("���~:�L������\n");
            return 0;
        }
        if(first_atk_char==last_atk_char) {	//�@�����𨤦ⵥ���𨤦�A��X���~
            printf("���~:���i���ƿ��\n");
            return 0;
        }
        printf("���𨤦⬰%d�A��𨤦⬰%d",first_atk_char,last_atk_char);	//�L�X�̲׿�J
    } else {
        printf("��J���~\n");//�ϥΪ̿�J�D���]�D�_��X���~
        return 0;
    }

    return 0;
}
