#include <stdio.h>
#include <stdlib.h>


int main() {
    char ch1_type= 'F';
    int ch1_hp=46;
    int ch1_attack=17;
    int ch1_defense=7;

    printf("����@\n");
    printf("����W��:����\n");
    printf("�ݩ�:%c    ",ch1_type);
    printf("����:%d\n",ch1_attack);
    printf("��q:%d   ",ch1_hp);
    printf("���m:%d\n",ch1_defense);
    printf("����w���j��:%.2f\n\n",((ch1_hp*1)+(ch1_attack*0.8)+(ch1_defense*0.5)-50)*6.5);
    printf("\n");

    char ch2_type= 'W';
    int ch2_hp=45;
    int ch2_attack=16;
    int ch2_defense=8;

    printf("����G\n");
    printf("����W��:����\n");
    printf("�ݩ�:%c    ",ch2_type);
    printf("����:%d\n",ch2_attack);
    printf("��q:%d   ",ch2_hp);
    printf("���m:%d\n",ch2_defense);
    printf("����w���j��:%.2f\n\n",((ch2_hp*1)+(ch2_attack*0.8)+(ch2_defense*0.5)-50)*6.5);
    printf("\n");

    char ch3_type= 'G';
    int ch3_hp=43;
    int ch3_attack=19;
    int ch3_defense=6;

    printf("����T\n");
    printf("����W��:���A\n");
    printf("�ݩ�:%c    ",ch3_type);
    printf("����:%d\n",ch3_attack);
    printf("��q:%d   ",ch3_hp);
    printf("���m:%d\n",ch3_defense);
    printf("����w���j��:%.2f\n\n",((ch3_hp*1)+(ch3_attack*0.8)+(ch3_defense*0.5)-50)*6.5);
    printf("\n");
    int want;
    printf("�O�_�s�W����(Yesssss=1),(Nooooo=2) : ");
    scanf("%d", & want);
    getchar();

    if (want==1) { //Yesssss�����G

        char ch4_type;
        printf("�s�W����\n");//�s�W����
        printf("�ݩ�:");
        scanf("%c", &ch4_type);
        int ch4_hp, ch4_attack, ch4_defense;
        printf("����:");
        scanf("%d", &ch4_attack);
        printf("��q:");
        scanf("%d", &ch4_hp);
        printf("���m:");
        scanf("%d", &ch4_defense);
        getchar();
        if (ch4_type=='f') { //�ഫ�j�p�g
            ch4_type='F';
        }
        if (ch4_type=='g') {
            ch4_type='G';
        }
        if (ch4_type=='a') {
            ch4_type='A';
        }
        if (ch4_type=='w') {
            ch4_type='W';
        }
        if (ch4_type=='F'||ch4_type=='f'||
                ch4_type=='G'||ch4_type=='g'||
                ch4_type=='A'||ch4_type=='a'||
                ch4_type=='W'||ch4_type=='w') { //�ݩʤ����ݩʥ~
            if (ch4_attack<15||ch4_attack>20||
                    ch4_hp<40    ||ch4_hp>50||
                    ch4_defense<5||ch4_defense>10) { //����ƭȽd��
                printf("���~:��O�ƭȦb����d�򤧥~\n");
                return 0;
            }
            if ((ch4_attack+ch4_hp+ch4_defense)<65||(ch4_attack+ch4_hp+ch4_defense)>70) {
                printf("���~:��O�ƭȦb����d�򤧥~\n");
                return 0;
            }
        }

        else {
            if (ch4_attack<15||ch4_attack>20||
                    ch4_hp<40    ||ch4_hp>50||
                    ch4_defense<5||ch4_defense>10) {
                if ((ch4_attack+ch4_hp+ch4_defense)<65||(ch4_attack+ch4_hp+ch4_defense)>70) {
                    printf("���~:�L���ݩ�\n");
                    printf("���~:��O�ƭȦb����d�򤧥~\n");
                    return 0;
                }
            }
        }




        printf("\n");
        printf("����|\n");
        printf("�W��:����\n");
        printf("�ݩ�:%c    ",ch4_type);
        printf("����:%d\n", ch4_attack);
        printf("��q:%d    ", ch4_hp);
        printf("���m:%d\n", ch4_defense);
        printf("����w���j��:%.2f\n\n",((ch4_hp*1)+(ch4_attack*0.8)+(ch4_defense*0.5)-50)*6.5);
        printf("\n");
        int one1,two1;
        printf("��ܥ��𨤦�:");
        scanf("%d",&one1);
        if (4>=one1>=1) {
            printf("��ܫ�𨤦�:");
        }
        if (one1<1,one1>4) {
            printf("���~:�L������");//��J�W�L�d��Ʀr�����p
            return 0;
        }
        scanf("%d",&two1);
        if (two1<1,two1>4) {
            printf("���~:�L������");
            return 0;
        }
        if (one1==two1) {
            printf("���~:���i���ƿ��");//��J�P�˼Ʀr�����p
            return 0;
        }
        printf("���𬰨���:%d�B",one1);
        printf("��𬰨���:%d",two1);

    }

    int one2,two2;
    if (want==2) { //Nooooo�����G
        printf("��ܥ��𨤦�:");
        scanf("%d",&one2);
        if(3>=one2>=1) {
            printf("��ܫ�𨤦�:");
        }
        if(one2<1,one2>3) {
            printf("���~:�L������");//��J�W�L�d��Ʀr�����p
            return 0;
        }
        scanf("%d",&two2);
        if(two2<1,two2>3) {
            printf("���~:�L������");//��J�W�L�d��Ʀr�����p
            return 0;
        }
        if(one2==two2) {
            printf("���~:���i���ƿ��");//��J�P�˼Ʀr�����p
            return 0;
        }
        printf("���𬰨���:%d�B",one2);
        printf("��𬰨���:%d",two2);
    }
    if (want!=1&&want!=2) { //�гy�����J��L���O1��2�����p
        printf("��J���~");
    }



    return 0;
}
