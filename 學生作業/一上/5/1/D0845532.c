#include<stdio.h>//���Y��
int main() {
    //�D�禡
    char char1type='G',char2type='A',char3type='F',char4type;//type
    int  char1atk=20,char2atk=15,char3atk=16,char4atk;//atk
    int  char1hp=40,char2hp=35,char3hp=44,char4hp;//hp
    int  char1def=10,char2def=10,char3def=5,char4def;//def
    int  add;//yes or no
    int first,last,first1,last1;//���� ���

    printf("����1\n"//�L�X��r
           "�W��:���\n");
    printf("�ݩ�:G    ����:20\n",char1type,char1atk);
    printf("��q:40   ���m:10\n", char2type,char2atk);
    printf("����w���j��:%.2f\n\n",((char1hp*1)+(char1atk*0.8)+(char1def*0.5)-50)*6.5);

    printf("����2\n"
           "�W��:�֥�\n");
    printf("�ݩ�:A    ����:15\n",char2type,char2atk);
    printf("��q:35   ���m:10\n",char2hp,char2def);
    printf("����w���j��:%.2f\n\n",((char2hp*1)+(char2atk*0.8)+(char2def*0.5)-50)*6.5);

    printf("����3\n"
           "�W��:�紵\n");
    printf("�ݩ�:F    ����:16\n",char3type,char3atk);
    printf("��q:44   ���m:5\n",char3hp,char3def);
    printf("����w���j��:%.2f\n\n",((char1hp*1)+(char1atk*0.8)+(char1def*0.5)-50)*6.5);
    printf("�O�_�s�W����(1.yes 2.no)?");
    scanf("%d",&add);
    getchar();
    if (add==1) {

        printf("");
        printf("�s�W����\n");//�s�W����
        printf("�ݩ�:");
        scanf("%c",&char4type);
        getchar();
        printf("����:");
        scanf("%d",&char4atk);
        getchar();
        printf("��q:");
        scanf("%d",&char4hp);
        getchar();
        printf("���m:");
        scanf("%d",&char4def);
        getchar();
        if (char4type =='F' || char4type =='f' || char4type =='W' || char4type =='w' ||//�ݩʥH�~
                char4type =='G' || char4type =='g' || char4type =='A' || char4type =='a') {
            if (char4hp<40 || char4hp>50||//�ƭȭ���
                    char4atk<15||char4atk>20||
                    char4def<5||char4def>10) {
                printf("���~:��O�ƭȦb����~\n");
                return 0;

            }
            if ((char4def+char4atk+char4hp)<65||(char4def+char4atk+char4hp)>70) {
                printf("���~:��O�ƭȦb����~\n");
                return 0;
            }
        } else {
            if (char4hp<40 || char4hp>50||//�ƭȭ���
                    char4atk<15||char4atk>20||
                    char4def<5||char4def>10) {
                if ((char4def+char4atk+char4hp)<65||(char4def+char4atk+char4hp)>70) {

                    printf("�L���ݩ�\n");
                    printf("���~:��O�ƭȦb����~\n");
                    return 0;
                }
            }
        }
        if (char4type=='f') { //�j�p�g�ഫ
            char4type='F';
        } else if (char4type=='w') {
            char4type='W';
        } else if (char4type=='g') {
            char4type='G';
        } else if (char4type=='a') {
            char4type='A';
        }
        if (char4hp<40 || char4hp>50||//�ƭȭ���
                char4atk<15||char4atk>20||
                char4def<5||char4def>10) {
            printf("���~:��O�ƭȦb����~\n");
            return 0;
        }
        if ((char4def+char4atk+char4hp)<65||(char4def+char4atk+char4hp)>70) {
            printf("���~:��O�ƭȦb����~\n");
            return 0;
        }
        printf("\n");

        printf("����4\n");
        printf("�W��:�ۭq����\n");
        printf("�ݩ�:%c ����%d\n",char4type,char4atk);
        printf("��q:%d ���m%d\n",char4hp,char4def);
        printf("����w���j��:%.2f\n",((char4hp*1)+(char4atk*0.8)+(char4def*0.5)-50)*6.5);
        printf("\n");
        printf("��J���𨤦�:");
        scanf("%d",&first1);

        if (first1==1||first1==2||first1==3||first1==4) {
            printf("��J��𨤦�:");
        }

        else {
            printf("���~:�L������");
            return 0;
        }
        scanf("%d",&last1);//��𨤦�
        if (last1==1||last1==2||last1==3||last1==4) {
            printf("��J��𨤦�:");
        }

        else {
            printf("���~:�L������");
            return 0;
        }
        if (first1==last1) { //���ƿ��
            printf("���~:���i���ƿ��\n");
            return 0;
        }
        printf("���𨤦�:%d�B��𨤦�:%d",first1,last1);

    }

    else if (add==2) { //��J2�����u
        printf("��J���𨤦�:\n");
        scanf("%d",&first);
        if (first!=1&&first!=2&&first!=3) {
            printf("���~:���⤣�s�b");
            return 0;
        }
        printf("��J��𨤦�:\n");
        scanf("%d",&last);
        if (last!=1&&last!=2&&last!=3) {
            printf("���~:���⤣�s�b");
            return 0;
        }
        if (first==last) {
            printf("���~:���i���ƿ��");
            return 0;
        }
        printf("���𬰨���%d�B��𬰨���%d",first,last);

    }


    return 0;//����

}
