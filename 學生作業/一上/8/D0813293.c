#include<stdio.h>
#include<stdlib.h>

int main() {
    //char1=�p���|�a
    char char1_name[24] = "�p���|�a";
    char char1_type[7] = {"W"};
    int char1_atk[7] = {15};
    int char1_hp[7] = {50};
    int char1_def[7] = {5};
    //����j�׹w��
    float char1_predict[7]= {(char1_hp[0] * 1 + char1_atk[0] * 0.8 + char1_def[0] * 0.5 - 50) * 6.5};
    //char2=�p�ޭ�޳
    char char2_name[24] = {"�p�ޭ�޳"};
    char char2_type[7] = {"F"};
    int char2_atk[7] = {18};
    int char2_hp[7] = {47};
    int char2_def[7] = {5};
    //����j�׹w��
    float char2_predict[7] = {(char2_hp[0] * 1 + char2_atk[0] * 0.8 + char2_def[0] * 0.5 - 50) * 6.5};
    //char3=���a�x�o��
    char chae3_name[24] = {"���a�x�o��"};
    char char3_type[7] = {"A"};
    int char3_atk[7] = {15};
    int char3_hp[7] = {45};
    int char3_def[7] = {7};
    //����j�׹w��
    float char3_predict[7] = {(char3_hp[0] * 1 + char3_atk[0] * 0.8 + char3_def[0] * 0.5 - 50) * 6.5};
    //�s�W����1=newchar1
    char newchar1_name[24];
    char newchar1_type[7];
    int newchar1_atk[7] = {0};
    int newchar1_hp[7] = {0};
    int newchar1_def[7] = {0};
    //�s�W����j�׹w��
    float newchar1_predict;
    int cho;//��ܾ԰��e�ﶵ
    //�ݩʧJ��
    float addchar1_ret=1;
    float addchar2_ret=1;
    //�ݦ孿�v
    float addchar1_jca=1;
    float addchar2_jca=1;
    int addchar1=0;//����
    int addchar2=0;//���
    //�s�W�Ȧs�����x�s��Ը��
    int addchar1_type[7];
    int addchar1_atk[7] = {0};
    int addchar1_hp[7] = {0};
    int addchar1_def[7] = {0};
    int addchar2_type[7];
    int addchar2_atk[7] = {0};
    int addchar2_hp[7] = {0};
    int addchar2_def[7] = {0};
    //�P�_�b��
    int char1hp_helf;
    int char2hp_helf;
    int val=0;//�P�_���L�s�W�L����
    int count=3;//�p��ثe�X�Ө���
    //��ܹC���}�l�e�ﶵ
    while(1) {
        printf("\n1. �s�W�έק�s�W����\n");
        printf("2. ��ܩҦ�������\n");
        printf("3. �԰�\n");
        printf("0. �����C��\n\n");
        printf("�п�� : ");
        scanf("%d",&cho);
        if(cho == 2) { //��ܥثe��T
            printf("\n����1\n�W��:�p���|�a\n");
            printf("�ݩ�:%c\t����:%d\n",char1_type[0],char1_atk[0]);
            printf("��q:%d\t���m:%d\n",char1_hp[0],char1_def[0]);
            printf("����j�׹w��:%.2f\n\n",char1_predict[0]);
            printf("����2\n�W��:�p�ޭ�޳\n");
            printf("�ݩ�:%c\t����:%d\n",char2_type[0],char2_atk[0]);
            printf("��q:%d\t���m:%d\n",char2_hp[0],char2_def[0]);
            printf("����j�׹w��:%.2f\n\n",char2_predict[0]);
            printf("����3\n�W��:���a�x�o��\n");
            printf("�ݩ�:%c\t����:%d\n",char3_type[0],char3_atk[0]);
            printf("��q:%d\t���m:%d\n",char3_hp[0],char3_def[0]);
            printf("����j�׹w��:%.2f\n\n",char3_predict[0]);
        } else if(cho == 1) { //�Y��ܷs�W����A�h��ܷs�W��J��T
            while(1) {
                if(val==0) {
                    count = 4;//�p��ثe����
                    printf("\n�s�W����\n�W��:");
                    scanf("%s",&newchar1_name);
                    printf("�ݩ�:");
                    scanf(" %c", &newchar1_type[0]);
                    printf("����:");
                    scanf("%d",&newchar1_atk[0]);
                    printf("��q:");
                    scanf("%d", &newchar1_hp[0]);
                    printf("���m:");
                    scanf("%d",&newchar1_def[0]);
                } else if(val>0) {
                    printf("\n�ק�s�W����\n�W��:");
                    scanf("%s",&newchar1_name);
                    printf("�ݩ�:");
                    scanf(" %c", &newchar1_type[0]);
                    printf("����:");
                    scanf("%d",&newchar1_atk[0]);
                    printf("��q:");
                    scanf("%d", &newchar1_hp[0]);
                    printf("���m:");
                    scanf("%d",&newchar1_def[0]);
                }
                //�ഫ�j�p�g
                if (newchar1_type[0]== 'f' ) {
                    newchar1_type[0]= 'F';
                } else if(newchar1_type[0]== 'w' ) {
                    newchar1_type[0]= 'W';
                } else if(newchar1_type[0]== 'g' ) {
                    newchar1_type[0]= 'G';
                } else if(newchar1_type[0]== 'a' ) {
                    newchar1_type[0]= 'A';
                } else if(newchar1_type[0]== 'F' ) {
                    newchar1_type[0]= 'F';
                } else if(newchar1_type[0]== 'W' ) {
                    newchar1_type[0]= 'W';
                } else if(newchar1_type[0]== 'G' ) {
                    newchar1_type[0]= 'G';
                } else if(newchar1_type[0]== 'A' ) {
                    newchar1_type[0]= 'A';
                } else {
                    printf("���~: �L���ݩ�\n");
                }
                //�P�_����ƭ�
                if((newchar1_atk[0] < 15)|(newchar1_atk[0] > 20)) {
                    printf("���~ : ��O�ƭȦb�d�򤧥~\n");
                } else if((newchar1_hp[0] < 40)|(newchar1_hp[0] > 50)) {
                    printf("���~ : ��O�ƭȦb�d�򤧥~\n");
                } else if((newchar1_def[0] < 5)|(newchar1_def[0] > 10)) {
                    printf("���~ : ��O�ƭȦb�d�򤧥~\n");
                } else if(((newchar1_hp[0] + newchar1_atk[0] + newchar1_def[0])< 65 )|((newchar1_hp[0] + newchar1_atk[0] + newchar1_def[0])> 70 )) {
                    printf("���~ : ��O�ƭȦb�d�򤧥~\n");
                } else {
                    val = val +1;
                    break;
                }
            }

            //�s�W����w���j��
            float newchar1_predict[7] = {(newchar1_hp[0] * 1 + newchar1_atk[0] * 0.8 + newchar1_def[0] * 0.5 - 50) * 6.5};
            //�s�W�����T
            printf("\n����4\n�W��:%s\n�ݩ�:%c\n����:%d\n��q:%d\n���m:%d\n����j�׹w��:%.2f\n\n"
                   ,newchar1_name,newchar1_type[0],newchar1_atk[0],newchar1_hp[0],newchar1_def[0],newchar1_predict[0]);
        }
        //��ܧ�������
        else if(cho == 3) {
            while(1) {
                printf("\n��ܥ��𨤦�: ");
                scanf("%d",&addchar1);
                if((addchar1>count)|(addchar1<1)) {
                    printf("���~: �L������\n");
                } else {
                    break;
                }
            }
            while(1) { //���s��J�j��
                printf("��ܫ�𨤦�: ");
                scanf("%d",&addchar2);
                if((addchar2>count)|(addchar2<1)) {
                    printf("���~: �L������\n");
                } else if((addchar2<=count)&(addchar2>=1)) {
                    if(addchar2 == addchar1) {
                        printf("���~: ���i���ƿ��\n");
                    } else {
                        printf("\n���𬰨���%d�B��𬰨���%d\n",addchar1,addchar2);
                        printf("�԰��}�l\n");
                        break;
                    }
                }
            }
            //�]�w�Ȧs���⪺������
            if(addchar1==1) {
                addchar1_atk[0]=char1_atk[0],addchar1_hp[0]=char1_hp[0],addchar1_def[0]=char1_def[0],addchar1_type[0]=char1_type[0];
            } else if(addchar1==2) {
                addchar1_atk[0]=char2_atk[0],addchar1_hp[0]=char2_hp[0],addchar1_def[0]=char2_def[0],addchar1_type[0]=char2_type[0];
            } else if(addchar1==3) {
                addchar1_atk[0]=char3_atk[0],addchar1_hp[0]=char3_hp[0],addchar1_def[0]=char3_def[0],addchar1_type[0]=char3_type[0];
            } else if(addchar1==4) {
                addchar1_atk[0]=newchar1_atk[0],addchar1_hp[0]=newchar1_hp[0],addchar1_def[0]=newchar1_def[0],addchar1_type[0]=newchar1_type[0];
            }
            if(addchar2==1) {
                addchar2_atk[0]=char1_atk[0],addchar2_hp[0]=char1_hp[0],addchar2_def[0]=char1_def[0],addchar2_type[0]=char1_type[0];
            } else if(addchar2==2) {
                addchar2_atk[0]=char2_atk[0],addchar2_hp[0]=char2_hp[0],addchar2_def[0]=char2_def[0],addchar2_type[0]=char2_type[0];
            } else if(addchar2==3) {
                addchar2_atk[0]=char3_atk[0],addchar2_hp[0]=char3_hp[0],addchar2_def[0]=char3_def[0],addchar2_type[0]=char3_type[0];
            } else if(addchar2==4) {
                addchar2_atk[0]=newchar1_atk[0],addchar2_hp[0]=newchar1_hp[0],addchar2_def[0]=newchar1_def[0],addchar2_type[0]=newchar1_type[0];
            }
            if((addchar1_type[0]=='W')&&(addchar2_type[0]=='F')) {
                addchar1_ret = 1.2;
                addchar2_ret = 0.8;
            } else if((addchar1_type[0]=='F')&&(addchar2_type[0]=='A')) {
                addchar1_ret = 1.2;
                addchar2_ret = 0.8;
            } else if((addchar1_type[0]=='A')&&(addchar2_type[0]=='G')) {
                addchar1_ret = 1.2;
                addchar2_ret = 0.8;
            } else if((addchar1_type[0]=='G')&&(addchar2_type[0]=='W')) {
                addchar1_ret = 1.2;
                addchar2_ret = 0.8;
            } else if((addchar1_type[0]=='F')&&(addchar2_type[0]=='W')) {
                addchar1_ret = 0.8;
                addchar2_ret = 1.2;
            } else if((addchar1_type[0]=='A')&&(addchar2_type[0]=='F')) {
                addchar1_ret = 0.8;
                addchar2_ret = 1.2;
            } else if((addchar1_type[0]=='G')&&(addchar2_type[0]=='A')) {
                addchar1_ret = 0.8;
                addchar2_ret = 1.2;
            } else if((addchar1_type[0]=='W')&&(addchar2_type[0]=='G')) {
                addchar1_ret = 0.8;
                addchar2_ret = 1.2;
            }
            if(addchar1_hp[0]<char1hp_helf/2) {
                addchar1_jca = 1.2;
            }
            if(addchar2_hp[0]<char2hp_helf/2) {
                addchar2_jca = 1.2;
            }
            char2hp_helf=addchar2_hp[0];
            char1hp_helf=addchar1_hp[0];
            //�԰��j��
            while(1) {
                printf("\n����%d �� ����%d �o�ʧ����A�y��%.llf�I�ˮ`\n",addchar1,addchar2,(addchar1_atk[0]*addchar1_ret*addchar1_jca-addchar2_def[0]));
                addchar2_hp[0]=addchar2_hp[0]-(addchar1_atk[0]*addchar1_ret*addchar1_jca-addchar2_def[0]);
                printf("����%d HP: %d ����%d HP: %d\n\n",addchar1,addchar1_hp[0],addchar2,addchar2_hp[0]);
                if(addchar2_hp[0]<=0) {
                    printf("\n����%d ���h�԰���O\n�԰�����\n\n����%d ���\n",addchar2,addchar1);
                    break;
                }
                printf("����%d �� ����%d �o�ʧ����A�y��%.llf�I�ˮ`\n",addchar2,addchar1,(addchar2_atk[0]*addchar2_ret*addchar2_jca-addchar1_def[0]));
                addchar1_hp[0]=addchar1_hp[0]-(addchar2_atk[0]*addchar2_ret*addchar2_jca-addchar1_def[0]);
                printf("����%d HP: %d ����%d HP: %d\n",addchar1,addchar1_hp[0],addchar2,addchar2_hp[0]);
                if(addchar1_hp[0]<=0) {
                    printf("\n����%d ���h�԰���O\n�԰�����\n\n����%d ���\n",addchar1,addchar2);
                    break;
                }
            }
        } else if(cho == 0) {
            printf("\n�����C��\n");
            return 0;
        } else {
            printf("\n��J���~!\n\n");
        }
    }
}

