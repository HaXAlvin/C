#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����@�ܼƫŧi
char char1_name[] = "�紵����";
char char1_type[] = "F";
int char1_hp[] = {45};
int char1_atk[] = {20};
int char1_def[] = {5};
//����G�ܼƫŧi
char char2_name[] = "���ֱХD���";
char char2_type[] = "W";
int char2_hp[] = {40};
int char2_atk[] = {15};
int char2_def[] = {10};
//����T�ܼƫŧi
char char3_name[] = "�U����";
char char3_type[] = "A";
int char3_hp[] = {45};
int char3_atk[] = {15};
int char3_def[] = {10};
//����|�ܼƫŧi
char char4_name[20];
char char4_type[10];
int char4_hp[5];
int char4_atk[5];
int char4_def[5];
//���� ��� �������ݩ�
int firstone_atk;
int firstone_hp;
int firstone_def;
int firstone_type;
int lastone_atk;
int lastone_hp;
int lastone_def;
int lastone_type;
//�e�|�Ӫ�����j�׹w��
int power1;
int power2;
int power3;
//�s�W�������ܼ�
int start;
//�s�W�έק�s�W���⪺�p�ƾ�
int count_character=0;
//�s�W�ݩʬ۫g�����ܼ�
int happening_type = 0;
void EditNewChar() {
    //�����J�ݩ�flag
    int attributes_true = 1;
    //��q�B�����B���m�B��X�ݩʿ�Jflag
    int mix_true = 1, hp_true = 1, atk_true = 1, def_true = 1, happening = 1;
    do {
        //��X���~�T�� �ín�D���s��J�ƭ�
        if(attributes_true == 0) {
            printf("���~ : �L���ݩ�\n");
        }
        if(mix_true + hp_true + atk_true + def_true!= 4) {
            printf("���~ : ��O�ƭȦb�d�򤧥~\n");
        }
        //�s�W�����������
        if(count_character != 0) {
            printf("\n�ק�s�W����\n\n����4\n�W��:%s\n�ݩ�:%s    ����:%d\n��q:%d   ���m:%d\n",char4_name,char4_type,char4_atk[0],char4_hp[0],char4_def[0]);
            printf("\n�W��:");
        } else if(count_character == 0) {
            printf("\n�s�W����\n�W��:");
            count_character++;
        }
        scanf("%s",char4_name);
        printf("�ݩ�:");
        scanf("%s",char4_type);
        printf("��q:");
        scanf("%d",&char4_hp[0]);
        printf("����:");
        scanf("%d",&char4_atk[0]);
        printf("���m:");
        scanf("%d",&char4_def[0]);
        //�ݩʤj�p�g���D �Q��flag�P�_�O�_���s��J
        if(char4_type[0] == 'f') {
            char4_type[0] = 'F';
            attributes_true = 1;
        } else if(char4_type[0] == 'w') {
            char4_type[0] = 'W';
            attributes_true = 1;
        } else if(char4_type[0] == 'g') {
            char4_type[0] = 'G';
            attributes_true = 1;
        } else if(char4_type[0] == 'a') {
            char4_type[0] = 'A';
            attributes_true = 1;
        } else if(char4_type[0] == 'F') {
            attributes_true = 1;
        } else if(char4_type[0] == 'W') {
            attributes_true = 1;
        } else if(char4_type[0] == 'G') {
            attributes_true = 1;
        } else if(char4_type[0] == 'A') {
            attributes_true = 1;
        } else {
            attributes_true = 0;
        }
        //�������O�_�Ҧb�Ȱ줺 �Q��flag�P�_�O�_���s��J
        if((char4_hp[0] < 40)||(char4_hp[0] > 50)) {
            hp_true = 0;
        } else if((char4_hp[0] >= 40)&&(char4_hp[0] <= 50)) {
            hp_true = 1;
        }
        if((char4_atk[0] < 15)||(char4_atk[0] > 20)) {
            atk_true = 0;
        } else if((char4_atk[0] >= 15)&&(char4_atk[0] <= 20)) {
            atk_true = 1;
        }
        if((char4_def[0] >= 5)&&(char4_def[0] <= 10)) {
            def_true = 1;
        } else if((char4_def[0] < 5)||(char4_def[0] > 10)) {
            def_true = 0;
        }
        if(((char4_hp[0] + char4_atk[0] + char4_def[0])>=65)||((char4_hp[0] + char4_atk[0] + char4_def[0])<=70)) {
            mix_true = 1;
        } else if(((char4_hp[0] + char4_atk[0] + char4_def[0])<65)||((char4_hp[0] + char4_atk[0] + char4_def[0])>70)) {
            mix_true = 0;
        }
    } while((attributes_true == 0)|(mix_true + hp_true + atk_true + def_true != 4));
    //����|��T
    int power4 = (char4_hp[0] * 1.0 + char4_atk[0] * 0.8 + char4_def[0] * 0.5 - 50 ) * 6.5;
    printf("\n����4\n�W��:%s\n�ݩ�:%s    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n\n",char4_name,char4_type,char4_atk[0],char4_hp[0],char4_def[0],power4);
    printf("\n");
}
//�s�W�@��PrintCharData���禡(��ܩҦ����⪺���)
void PrintCharData() {
    power1 = (char1_hp[0] * 1.0 + char1_atk[0] * 0.8 + char1_def[0] * 0.5 - 50 ) * 6.5;
    power2 = (char2_hp[0] * 1.0 + char2_atk[0] * 0.8 + char2_def[0] * 0.5 - 50 ) * 6.5;
    power3 = (char3_hp[0] * 1.0 + char3_atk[0] * 0.8 + char3_def[0] * 0.5 - 50 ) * 6.5;
    printf("����1\n�W��:%s\n�ݩ�:%s    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n",char1_name,char1_type,char1_atk[0],char1_hp[0],char1_def[0],power1);
    printf("\n����2\n�W��:%s\n�ݩ�:%s    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n",char2_name,char2_type,char2_atk[0],char2_hp[0],char2_def[0],power2);
    printf("\n����3\n�W��:%s\n�ݩ�:%s    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n",char3_name,char3_type,char3_atk[0],char3_hp[0],char3_def[0],power3);
    if(count_character != 0) {
        int power4 = (char4_hp[0] * 1.0 + char4_atk[0] * 0.8 + char4_def[0] * 0.5 - 50 ) * 6.5;
        printf("\n����4\n�W��:%s\n�ݩ�:%s    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n\n",char4_name,char4_type,char4_atk[0],char4_hp[0],char4_def[0],power4);
    }
    if(count_character == 0) {
        printf("\n");
    }
}
//�s�W�@��PrintCharData���禡�A�]�tBattling�Ƶ{��(�����������O����̡A���۾԰��}�l!!)
void SelectAndBattle() {
    //����A���
    int firstone,lastone;
    //�s����ƥΨ쪺�ܼ�
    int sum1_hp,sum2_hp,data_hp,data_atk,data_def,data_line;
    printf("\n");
    if(count_character == 0) {
        //���𨤦���~�ɡA�^�Ӫ��a��
first1_choose:
        //���i���ƿ���ɡA�^�Ӫ��a��
compare1_choose:
        printf("��ܥ��𨤦� : ");
        scanf("%d",&firstone);
        while((firstone>3)||(firstone<1)) {
            printf("���~ : �L������\n");
            goto first1_choose;
        }
        while((firstone<=3)&&(firstone>=1)) {
            //��𨤦���~�ɡA�^�Ӫ��a��
last1_choose:
            printf("��ܫ�𨤦� : ");
            scanf("%d",&lastone);
            if((lastone>3)||(lastone<1)) {
                printf("���~ : �L������\n");
                goto last1_choose;
            } else if((lastone<=3)&&(lastone>=1)) {
                if(firstone == lastone) {
                    printf("���~ : ���i���ƿ��\n");
                    goto compare1_choose;
                }
                Battling(firstone,lastone,sum1_hp,sum2_hp);
            }
            break;
        }
    } else if(count_character != 0) {
first2_choose:
compare2_choose:
        printf("��ܥ��𨤦� : ");
        scanf("%d",&firstone);
        while((firstone>4)||(firstone<1)) {
            printf("���~ : �L������\n");
            goto first2_choose;
        }
        while((firstone<=4)&&(firstone>=1)) {
last2_choose:
            printf("��ܫ�𨤦� : ");
            scanf("%d",&lastone);
            if((lastone>4)||(lastone<1)) {
                printf("���~ : �L������\n");
                goto last2_choose;
            } else if((lastone<=4)&&(lastone>=1)) {
                if(firstone == lastone) {
                    printf("���~ : ���i���ƿ��\n");
                    goto compare2_choose;
                }
                Battling(firstone,lastone,sum1_hp,sum2_hp);
            }
            break;
        }
    }
}
//PrintCharData���Ƶ{��Battleing(�԰��}�l!!)
void Battling(int firstone,int lastone,int sum1_hp,int sum2_hp) {
    printf("\n���𬰨���%d�B��𬰨���%d\n�԰��}�l\n\n", firstone, lastone);
    if(firstone==1) {
        firstone_type = char1_type[0];
        firstone_hp = char1_hp[0];
        firstone_atk = char1_atk[0];
        firstone_def = char1_def[0];
    } else if(firstone==2) {
        firstone_type = char2_type[0];
        firstone_hp = char2_hp[0];
        firstone_atk = char2_atk[0];
        firstone_def = char2_def[0];
    } else if(firstone==3) {
        firstone_type = char3_type[0];
        firstone_hp = char3_hp[0];
        firstone_atk = char3_atk[0];
        firstone_def = char3_def[0];
    } else if(firstone==4) {
        firstone_type = char4_type[0];
        firstone_hp = char4_hp[0];
        firstone_atk = char4_atk[0];
        firstone_def = char4_def[0];
    }
    if(lastone==1) {
        lastone_type = char1_type[0];
        lastone_hp = char1_hp[0];
        lastone_atk = char1_atk[0];
        lastone_def = char1_def[0];
    } else if(lastone==2) {
        lastone_type = char2_type[0];
        lastone_hp = char2_hp[0];
        lastone_atk = char2_atk[0];
        lastone_def = char2_def[0];
    } else if(lastone==3) {
        lastone_type = char3_type[0];
        lastone_hp = char3_hp[0];
        lastone_atk = char3_atk[0];
        lastone_def = char3_def[0];
    } else if(lastone==4) {
        lastone_type = char4_type[0];
        lastone_hp = char4_hp[0];
        lastone_atk = char4_atk[0];
        lastone_def = char4_def[0];
    }
    sum1_hp = firstone_hp;
    sum2_hp = lastone_hp;
    if((firstone_type == 'W' && lastone_type == 'F')||(firstone_type == 'F' && lastone_type == 'A')||(firstone_type == 'A' && lastone_type == 'G')||(firstone_type == 'G' && lastone_type == 'W')) {
        happening_type = 1;
    } else if((firstone_type == 'F' && lastone_type == 'W')||(firstone_type == 'A' && lastone_type == 'F')||(firstone_type == 'G' && lastone_type == 'A')||(firstone_type == 'W' && lastone_type == 'G')) {
        happening_type = 2;
    } else {
        happening_type = 0;
    }
    do {
        if(lastone_hp < sum2_hp/2.0) {
            if(happening_type == 1) {
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", firstone, lastone, (int)(firstone_atk*1.2*1.2 - lastone_def));
                lastone_hp = (int)(lastone_hp - (firstone_atk*1.2*1.2 - lastone_def));
            } else if(happening_type == 0) {
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", firstone, lastone, (int)(firstone_atk*1.2 - lastone_def));
                lastone_hp = (int)(lastone_hp - (firstone_atk*1.2 - lastone_def));
            } else if(happening_type == 2) {
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", firstone, lastone, (int)(firstone_atk*1.2*0.8 - lastone_def));
                lastone_hp = (int)(lastone_hp - (firstone_atk*1.2*0.8 - lastone_def));
            }
        } else if(lastone_hp >= sum2_hp/2.0) {
            if(happening_type == 1) {
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", firstone, lastone, (int)(firstone_atk*1.2 - lastone_def));
                lastone_hp = (int)(lastone_hp - (firstone_atk*1.2 - lastone_def));
            } else if(happening_type == 0) {
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", firstone, lastone, (int)(firstone_atk - lastone_def));
                lastone_hp = (int)(lastone_hp - (firstone_atk - lastone_def));
            } else if(happening_type == 2) {
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", firstone, lastone, (int)(firstone_atk*0.8 - lastone_def));
                lastone_hp = (int)(lastone_hp - (firstone_atk*0.8 - lastone_def));
            }
        }
        printf("����%d HP: %d ����%d HP:%d\n\n", firstone, firstone_hp, lastone, lastone_hp);
        if(firstone_hp <= 0) {
            printf("����%d ���h�԰���O\n�԰�����\n\n����%d ���\n\n", firstone, lastone);
            break;
        }
        if(lastone_hp <= 0) {
            printf("����%d ���h�԰���O\n�԰�����\n\n����%d ���\n\n", lastone, firstone);
            break;
        }
        if(lastone_hp < sum2_hp/2.0) {
            if(happening_type == 2) {
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", lastone, firstone, (int)(lastone_atk*1.2*1.2 - firstone_def));
                firstone_hp = (int)(firstone_hp - (lastone_atk*1.2*1.2 - firstone_def));
            } else if(happening_type == 0) {
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", lastone, firstone, (int)(lastone_atk*1.2 - firstone_def));
                firstone_hp = (int)(firstone_hp - (lastone_atk*1.2 - firstone_def));
            } else if(happening_type == 1) {
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", lastone, firstone, (int)(lastone_atk*1.2*0.8 - firstone_def));
                firstone_hp = (int)(firstone_hp - (lastone_atk*1.2*0.8 - firstone_def));
            }
        } else if(lastone_hp >= sum2_hp/2.0) {
            if(happening_type == 2) {
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", lastone, firstone, (int)(lastone_atk*1.2 - firstone_def));
                firstone_hp = (int)(firstone_hp - (lastone_atk*1.2 - firstone_def));
            } else if(happening_type == 0) {
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", lastone, firstone, (int)(lastone_atk - firstone_def));
                firstone_hp = (int)(firstone_hp - (lastone_atk - firstone_def));
            } else if(happening_type == 1) {
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", lastone, firstone, (int)(lastone_atk*0.8 - firstone_def));
                firstone_hp = (int)(firstone_hp - (lastone_atk*0.8 - firstone_def));
            }
        }
        printf("����%d HP: %d ����%d HP:%d\n\n", firstone, firstone_hp, lastone, lastone_hp);
        if(firstone_hp <= 0) {
            printf("����%d ���h�԰���O\n�԰�����\n\n����%d ���\n\n", firstone, lastone);
            break;
        }
        if(lastone_hp <= 0) {
            printf("����%d ���h�԰���O\n�԰�����\n\n����%d ���\n\n", lastone, firstone);
            break;
        }
    } while((firstone_hp>=0)&&(lastone_hp>=0));
}
int main(void) {
    power1 = (char1_hp[0] * 1.0 + char1_atk[0] * 0.8 + char1_def[0] * 0.5 - 50 ) * 6.5;
    power2 = (char2_hp[0] * 1.0 + char2_atk[0] * 0.8 + char2_def[0] * 0.5 - 50 ) * 6.5;
    power3 = (char3_hp[0] * 1.0 + char3_atk[0] * 0.8 + char3_def[0] * 0.5 - 50 ) * 6.5;
    //����@��T
    printf("����1\n�W��:%s\n�ݩ�:%s    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n",char1_name,char1_type,char1_atk[0],char1_hp[0],char1_def[0],power1);
    //����G��T
    printf("\n����2\n�W��:%s\n�ݩ�:%s    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n",char2_name,char2_type,char2_atk[0],char2_hp[0],char2_def[0],power2);
    //����T��T
    printf("\n����3\n�W��:%s\n�ݩ�:%s    ����:%d\n��q:%d   ���m:%d\n����j�׹w���G%d\n\n",char3_name,char3_type,char3_atk[0],char3_hp[0],char3_def[0],power3);
    while(1) {
        //�����԰��ɡAgoto�^��
start_battle:
        //�P�_���U�Ӫ��y�{����
        printf("1�B�s�W�έק�s�W����\n2�B��ܩҦ�������\n3�B�԰�\n0�B�����C��\n�п�� : ");
        scanf("%d",&start);
        if(start == 1) {
            //EditNewChar���禡�N�J
            EditNewChar();
        } else if(start == 2) {
            //PrintCharData���禡�N�J
            PrintCharData();
        } else if(start == 3) {
            SelectAndBattle();
        } else if(start == 0) {
            //��J0�����C��
            printf("\n�����C��\n");
            return 0;
        } else {
            //��A�N�O��J���~
            printf("��J���~\n");
        }
    }
    return 0;
}

