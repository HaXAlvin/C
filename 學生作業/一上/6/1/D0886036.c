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
    char ch4_type;
    int ch4_hp, ch4_attack, ch4_defense;
    if (want==1) { //Yesssss�����G

        for(; ;) {


            printf("�s�W����\n");//�s�W����
            printf("�ݩ�:");
            scanf("%c", &ch4_type);
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
                    ch4_type=='W'||ch4_type=='w') { //�ݩʤ�
                if (ch4_attack<15||ch4_attack>20||
                        ch4_hp<40    ||ch4_hp>50||
                        ch4_defense<5||ch4_defense>10) { //����ƭȽd��
                    printf("���~:��O�ƭȦb����d�򤧥~\n");
                    continue;
                }
                if ((ch4_attack+ch4_hp+ch4_defense)<65||(ch4_attack+ch4_hp+ch4_defense)>70) {
                    printf("���~:��O�ƭȦb����d�򤧥~\n");
                    continue;
                }
            }

            if (ch4_type!='F'&&ch4_type!='f'&&
                    ch4_type!='G'&&ch4_type!='g'&&
                    ch4_type!='A'&&ch4_type!='a'&&
                    ch4_type!='W'&&ch4_type!='w') { //�ݩʥ~
                if (ch4_attack<15||ch4_attack>20||
                        ch4_hp<40    ||ch4_hp>50||
                        ch4_defense<5||ch4_defense>10) { //����ƭȽd��
                    printf("���~�G�L���ݩ�\n");
                    printf("���~:��O�ƭȦb����d�򤧥~\n");
                    continue;
                }
                if ((ch4_attack+ch4_hp+ch4_defense)<65||(ch4_attack+ch4_hp+ch4_defense)>70) {
                    printf("���~�G�L���ݩ�\n");
                    printf("���~:��O�ƭȦb����d�򤧥~\n");
                    continue;
                }
            }
            break;
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
        int one1,two1,f_attack,f_defense,f_hp,l_attack,l_defense,l_hp;
        for(; ;) {
            printf("��ܥ��𨤦�:");
            scanf("%d",&one1);



            if (one1<1||one1>4) {
                printf("���~:�L������\n");//��J�W�L�d��Ʀr�����p
                continue;
            }
            for(; ;) {
                if (4>=one1>=1) {
                    printf("��ܫ�𨤦�:");
                }
                scanf("%d",&two1);
                if (two1<1||two1>4) {
                    printf("���~:�L������\n");
                    continue;
                }
                if (one1==two1) {
                    printf("���~:���i���ƿ��\n");//��J�P�˼Ʀr�����p
                    continue;
                }
                break;
            }
            break;
        }
        printf("���𬰨���:%d�B",one1);
        printf("��𬰨���:%d\n",two1);
        printf("�԰��}�l\n\n");
        if(one1==1&&two1==2) { //����1��Ԩ���2
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 46 ����2 HP: 36\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 37 ����2 HP: 36\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 37 ����2 HP: 27\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 28 ����2 HP: 27\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 28 ����2 HP: 18\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 19 ����2 HP: 18\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 19 ����2 HP: 9\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 10 ����2 HP: 9\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 10 ����2 HP: 0\n\n");
            printf("����2 ���h�԰���O\n");
            printf("�԰�����\n\n");
            printf("����1���\n");

        }
        if(one1==1&&two1==3) { //����1��Ԩ���3
            printf("����1 �� ����3 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����1 HP: 46 ����3 HP: 32\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��12�I�ˮ`\n");
            printf("����1 HP: 34 ����3 HP: 32\n\n");
            printf("����1 �� ����3 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����1 HP: 34 ����3 HP: 21\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��12�I�ˮ`\n");
            printf("����1 HP: 22 ����3 HP: 21\n\n");
            printf("����1 �� ����3 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����1 HP: 22 ����3 HP: 10\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��12�I�ˮ`\n");
            printf("����1 HP: 10 ����3 HP: 10\n\n");
            printf("����1 �� ����3 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����1 HP: 10 ����3 HP: -1\n\n");
            printf("����3 ���h�԰���O\n");
            printf("�԰�����\n\n");
            printf("����1���\n");

        }
        if(one1==2&&two1==1) { //����2��Ԩ���1
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 45 ����1 HP: 37\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 36 ����1 HP: 37\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 36 ����1 HP: 28\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 27 ����1 HP: 28\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 27 ����1 HP: 19\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 18 ����1 HP: 19\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 18 ����1 HP: 10\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 9  ����1 HP: 10\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 9  ����1 HP: 1\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 0  ����1 HP: 1\n\n");
            printf("����2 ���h�԰���O\n");
            printf("�԰�����\n\n");
            printf("����1���\n");

        }
        if(one1==2&&two1==3) { //����2��Ԩ���3
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����2 HP: 45 ����3 HP: 33\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����2 HP: 34 ����3 HP: 33\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����2 HP: 34 ����3 HP: 23\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����2 HP: 23 ����3 HP: 23\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����2 HP: 23 ����3 HP: 13\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����2 HP: 12 ����3 HP: 13\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����2 HP: 12 ����3 HP: 3\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����2 HP: 1  ����3 HP: 3\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����2 HP: 1  ����3 HP: -7\n\n");
            printf("����3 ���h�԰���O\n");
            printf("�԰�����\n\n");
            printf("����2���\n");

        }
        if(one1==3&&two1==1) { //����3��Ԩ���1
            printf("����3 �� ����1 �o�ʧ���,�y��12�I�ˮ`\n");
            printf("����3 HP: 43 ����1 HP: 34\n\n");
            printf("����1 �� ����3 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 32 ����1 HP: 34\n\n");
            printf("����3 �� ����1 �o�ʧ���,�y��12�I�ˮ`\n");
            printf("����3 HP: 32 ����1 HP: 22\n\n");
            printf("����1 �� ����3 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 21 ����1 HP: 22\n\n");
            printf("����3 �� ����1 �o�ʧ���,�y��12�I�ˮ`\n");
            printf("����3 HP: 21 ����1 HP: 10\n\n");
            printf("����1 �� ����3 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 10 ����1 HP: 10\n\n");
            printf("����3 �� ����1 �o�ʧ���,�y��12�I�ˮ`\n");
            printf("����3 HP: 10 ����1 HP: -2\n\n");
            printf("����1 ���h�԰���O\n");
            printf("�԰�����\n\n");
            printf("����3���\n");

        }
        if(one1==3&&two1==2) { //����3��Ԩ���2
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 43 ����2 HP: 34\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����3 HP: 33 ����2 HP: 34\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 33 ����2 HP: 23\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����3 HP: 23 ����2 HP: 23\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 23 ����2 HP: 12\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����3 HP: 13 ����2 HP: 12\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 13 ����2 HP: 1\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����3 HP: 3  ����2 HP: 1\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 3  ����2 HP: -10\n\n");
            printf("����2 ���h�԰���O\n");
            printf("�԰�����\n\n");
            printf("����3���\n");

        }
        if(one1==1&&two1==4) { //����1��Ԩ���4
            f_attack=ch1_attack,f_defense=ch1_defense,f_hp=ch1_hp;
            l_attack=ch4_attack,l_defense=ch4_defense,l_hp=ch4_hp;

            while(f_hp>0&&l_hp>0) {
                printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",one1,two1,f_attack-l_defense);
                l_hp-=f_attack-l_defense;
                printf("����%d HP:%d ����%d HP:%d\n",one1,f_hp,two1,l_hp);

                printf("\n");
                if(l_hp<=0) {
                    printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",two1,one1);
                    return 0;
                }
                printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",two1,one1,l_attack-f_defense);
                f_hp-=l_attack-f_defense;
                printf("����%d HP:%d ����%d HP:%d\n",one1,f_hp,two1,l_hp);
                printf("\n");
                if(f_hp<=0) {
                    printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",one1,two1);
                    return 0;
                }
            }
        }
        if(one1==4&&two1==1) { //����4��Ԩ���1
            f_attack=ch4_attack,f_defense=ch4_defense,f_hp=ch4_hp;
            l_attack=ch1_attack,l_defense=ch1_defense,l_hp=ch1_hp;

            while(f_hp>0&&l_hp>0) {
                printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",one1,two1,f_attack-l_defense);
                l_hp-=f_attack-l_defense;
                printf("����%d HP:%d ����%d HP:%d\n",one1,f_hp,two1,l_hp);

                printf("\n");
                if(l_hp<=0) {
                    printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",two1,one1);
                    return 0;
                }
                printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",two1,one1,l_attack-f_defense);
                f_hp-=l_attack-f_defense;
                printf("����%d HP:%d ����%d HP:%d\n",one1,f_hp,two1,l_hp);
                printf("\n");
                if(f_hp<=0) {
                    printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",one1,two1);
                    return 0;
                }
            }
        }
        if(one1==2&&two1==4) { //����2��Ԩ���4
            f_attack=ch2_attack,f_defense=ch2_defense,f_hp=ch2_hp;
            l_attack=ch4_attack,l_defense=ch4_defense,l_hp=ch4_hp;

            while(f_hp>0&&l_hp>0) {
                printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",one1,two1,f_attack-l_defense);
                l_hp-=f_attack-l_defense;
                printf("����%d HP:%d ����%d HP:%d\n",one1,f_hp,two1,l_hp);

                printf("\n");
                if(l_hp<=0) {
                    printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",two1,one1);
                    return 0;
                }
                printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",two1,one1,l_attack-f_defense);
                f_hp-=l_attack-f_defense;
                printf("����%d HP:%d ����%d HP:%d\n",one1,f_hp,two1,l_hp);
                printf("\n");
                if(f_hp<=0) {
                    printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",one1,two1);
                    return 0;
                }
            }
        }
        if(one1==4&&two1==2) { //����4��Ԩ���2
            f_attack=ch4_attack,f_defense=ch4_defense,f_hp=ch4_hp;
            l_attack=ch2_attack,l_defense=ch2_defense,l_hp=ch2_hp;

            while(f_hp>0&&l_hp>0) {
                printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",one1,two1,f_attack-l_defense);
                l_hp-=f_attack-l_defense;
                printf("����%d HP:%d ����%d HP:%d\n",one1,f_hp,two1,l_hp);

                printf("\n");
                if(l_hp<=0) {
                    printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",two1,one1);
                    return 0;
                }
                printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",two1,one1,l_attack-f_defense);
                f_hp-=l_attack-f_defense;
                printf("����%d HP:%d ����%d HP:%d\n",one1,f_hp,two1,l_hp);
                printf("\n");
                if(f_hp<=0) {
                    printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",one1,two1);
                    return 0;
                }
            }
        }
        if(one1==3&&two1==4) { //����3��Ԩ���4
            f_attack=ch3_attack,f_defense=ch3_defense,f_hp=ch3_hp;
            l_attack=ch4_attack,l_defense=ch4_defense,l_hp=ch4_hp;

            while(f_hp>0&&l_hp>0) {
                printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",one1,two1,f_attack-l_defense);
                l_hp-=f_attack-l_defense;
                printf("����%d HP:%d ����%d HP:%d\n",one1,f_hp,two1,l_hp);

                printf("\n");
                if(l_hp<=0) {
                    printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",two1,one1);
                    return 0;
                }
                printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",two1,one1,l_attack-f_defense);
                f_hp-=l_attack-f_defense;
                printf("����%d HP:%d ����%d HP:%d\n",one1,f_hp,two1,l_hp);
                printf("\n");
                if(f_hp<=0) {
                    printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",one1,two1);
                    return 0;
                }
            }
        }
        if(one1==4&&two1==3) { //����4��Ԩ���3
            f_attack=ch4_attack,f_defense=ch4_defense,f_hp=ch4_hp;
            l_attack=ch3_attack,l_defense=ch3_defense,l_hp=ch3_hp;

            while(f_hp>0&&l_hp>0) {
                printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",one1,two1,f_attack-l_defense);
                l_hp-=f_attack-l_defense;
                printf("����%d HP:%d ����%d HP:%d\n",one1,f_hp,two1,l_hp);

                printf("\n");
                if(l_hp<=0) {
                    printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",two1,one1);
                    return 0;
                }
                printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",two1,one1,l_attack-f_defense);
                f_hp-=l_attack-f_defense;
                printf("����%d HP:%d ����%d HP:%d\n",one1,f_hp,two1,l_hp);
                printf("\n");
                if(f_hp<=0) {
                    printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",one1,two1);
                    return 0;
                }
            }
        }

    }

    int one2,two2;
    if (want==2) { //Nooooo�����G
        for(; ;) {
            printf("��ܥ��𨤦�:");
            scanf("%d",&one2);

            if(one2<1||one2>3) {
                printf("���~:�L������\n");//��J�W�L�d��Ʀr�����p
                continue;
            }
            for(; ;) {
                if(3>=one2>=1) {
                    printf("��ܫ�𨤦�:");
                }
                scanf("%d",&two2);
                if(two2<1||two2>3) {
                    printf("���~:�L������\n");//��J�W�L�d��Ʀr�����p
                    continue;
                }
                if(one2==two2) {
                    printf("���~:���i���ƿ��\n");//��J�P�˼Ʀr�����p
                    continue;
                }
                break;
            }
            break;
        }
        printf("���𬰨���:%d�B",one2);
        printf("��𬰨���:%d\n",two2);
        printf("�԰��}�l\n\n");
        if(one2==1&&two2==2) { //����1��Ԩ���2
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 46 ����2 HP: 36\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 37 ����2 HP: 36\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 37 ����2 HP: 27\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 28 ����2 HP: 27\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 28 ����2 HP: 18\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 19 ����2 HP: 18\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 19 ����2 HP: 9\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 10 ����2 HP: 9\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����1 HP: 10 ����2 HP: 0\n\n");
            printf("����2 ���h�԰���O\n");
            printf("�԰�����\n\n");
            printf("����1���\n");

        }
        if(one2==1&&two2==3) { //����1��Ԩ���3
            printf("����1 �� ����3 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����1 HP: 46 ����3 HP: 32\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��12�I�ˮ`\n");
            printf("����1 HP: 34 ����3 HP: 32\n\n");
            printf("����1 �� ����3 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����1 HP: 34 ����3 HP: 21\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��12�I�ˮ`\n");
            printf("����1 HP: 22 ����3 HP: 21\n\n");
            printf("����1 �� ����3 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����1 HP: 22 ����3 HP: 10\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��12�I�ˮ`\n");
            printf("����1 HP: 10 ����3 HP: 10\n\n");
            printf("����1 �� ����3 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����1 HP: 10 ����3 HP: -1\n\n");
            printf("����3 ���h�԰���O\n");
            printf("�԰�����\n\n");
            printf("����1���\n");

        }
        if(one2==2&&two2==1) { //����2��Ԩ���1
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 45 ����1 HP: 37\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 36 ����1 HP: 37\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 36 ����1 HP: 28\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 27 ����1 HP: 28\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 27 ����1 HP: 19\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 18 ����1 HP: 19\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 18 ����1 HP: 10\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 9  ����1 HP: 10\n\n");
            printf("����2 �� ����1 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 9  ����1 HP: 1\n\n");
            printf("����1 �� ����2 �o�ʧ���,�y��9�I�ˮ`\n");
            printf("����2 HP: 0  ����1 HP: 1\n\n");
            printf("����2 ���h�԰���O\n");
            printf("�԰�����\n\n");
            printf("����1���\n");

        }
        if(one2==2&&two2==3) { //����2��Ԩ���3
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����2 HP: 45 ����3 HP: 33\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����2 HP: 34 ����3 HP: 33\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����2 HP: 34 ����3 HP: 23\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����2 HP: 23 ����3 HP: 23\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����2 HP: 23 ����3 HP: 13\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����2 HP: 12 ����3 HP: 13\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����2 HP: 12 ����3 HP: 3\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����2 HP: 1  ����3 HP: 3\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����2 HP: 1  ����3 HP: -7\n\n");
            printf("����3 ���h�԰���O\n");
            printf("�԰�����\n\n");
            printf("����2���\n");

        }
        if(one2==3&&two2==1) { //����3��Ԩ���1
            printf("����3 �� ����1 �o�ʧ���,�y��12�I�ˮ`\n");
            printf("����3 HP: 43 ����1 HP: 34\n\n");
            printf("����1 �� ����3 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 32 ����1 HP: 34\n\n");
            printf("����3 �� ����1 �o�ʧ���,�y��12�I�ˮ`\n");
            printf("����3 HP: 32 ����1 HP: 22\n\n");
            printf("����1 �� ����3 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 21 ����1 HP: 22\n\n");
            printf("����3 �� ����1 �o�ʧ���,�y��12�I�ˮ`\n");
            printf("����3 HP: 21 ����1 HP: 10\n\n");
            printf("����1 �� ����3 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 10 ����1 HP: 10\n\n");
            printf("����3 �� ����1 �o�ʧ���,�y��12�I�ˮ`\n");
            printf("����3 HP: 10 ����1 HP: -2\n\n");
            printf("����1 ���h�԰���O\n");
            printf("�԰�����\n\n");
            printf("����3���\n");

        }
        if(one2==3&&two2==2) { //����3��Ԩ���2
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 43 ����2 HP: 34\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����3 HP: 33 ����2 HP: 34\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 33 ����2 HP: 23\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����3 HP: 23 ����2 HP: 23\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 23 ����2 HP: 12\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����3 HP: 13 ����2 HP: 12\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 13 ����2 HP: 1\n\n");
            printf("����2 �� ����3 �o�ʧ���,�y��10�I�ˮ`\n");
            printf("����3 HP: 3  ����2 HP: 1\n\n");
            printf("����3 �� ����2 �o�ʧ���,�y��11�I�ˮ`\n");
            printf("����3 HP: 3  ����2 HP: -10\n\n");
            printf("����2 ���h�԰���O\n");
            printf("�԰�����\n\n");
            printf("����3���\n");

        }
    }

    if (want!=1&&want!=2) { //�гy�����J��L���O1��2�����p
        printf("��J���~");
    }



    return 0;
}
