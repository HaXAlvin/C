#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char PrintCharData(int char_name,int hp,int atk,int def) {
    printf("����1\n"
           "�W��:�ѼQ\n"
           "�ݩ�:F     ����:15\n"
           "��q:40    ���m:5\n"
           "����j�׹w��:29.25\n\n");
    printf("����2\n"
           "�W��:���t\n"
           "�ݩ�:W    ����:16\n"
           "��q:41   ���m:6\n"
           "����j�׹w��:44.20\n\n");
    printf("����3\n"
           "�W��:�ѥ�\n"
           "�ݩ�G    ����:17\n"
           "��q:42   ���m:7\n"
           "����j�׹w��:59.15\n\n");
    return;
}
char EditNewChar(int *is_create_char4,char type,int char4_hp,int char4_atk,int char4_def,char char4_name[21]) {
    printf("\n");
    int test=0,err_type=0;
    if(*is_create_char4==0) {           ///////��s�W�}�⪺�W�r�O�Ū��N�s�W
        printf("�s�W����\n");
    } else {
        printf("�ק﨤��\n");
    }
    printf("�W��:");
    scanf("%s%*c",char4_name);
    printf("�ݩ�:");
    scanf("%c%*c",&type);
    printf("��q:");
    scanf("%d",&char4_hp);
    printf("����:");
    scanf("%d",&char4_atk);
    printf("���m:");
    scanf("%d",&char4_def);
    switch(type) { //�P�_�����ݩ�
    case'f':
            break;
    case 'g':
        break;
    case 'a':
        break;
    case 'w':
        break;
    case 'F':
        break;
    case 'G':
        break;
    case 'A':
        break;
    case 'W':
        break;
    default:
        test=1;
        err_type = 1; //�Хܿ��~����
    }
    if (char4_hp<40||char4_hp>50||char4_atk<15||char4_atk>20||char4_def<5||char4_def>10) {
        test=1;
        err_type = 2;
    }//�P�_��O�Ƚd��
    switch(err_type) { //�P�_��ܪ��F��
    case 0:
        break;
    case 1:
        printf("���~:�L���ݩ�\n");
        break;
    case 2:
        printf("���~:�L���ݩ�\n���~:��O�ƭȦb�d�򤧥~\n");
        break;
    }
    if(test==0) {
        *is_create_char4=1;
        float a = (char4_hp*1.0+char4_atk*0.8+char4_def*0.5);
        float b = (a-50)*6.5;
        printf("\n");
        printf("����4\n");
        printf("�W��:%s\n",char4_name);
        switch(type) {
        case'f':
                printf("�ݩ�:F  ");
            break;
        case'g':
            printf("�ݩ�:G  ");
            break;
        case'a':
                printf("�ݩ�:A  ");
            break;
        case'w':
            printf("�ݩ�:W  ");
            break;
        default:
            printf("�ݩ�:%c   ",type);
            break;
        }
        printf("����:%d\n",char4_atk);
        printf("��q:%d   ",char4_hp);
        printf("���m:%d\n",char4_def);
        printf("����j�׹w��:%.2lf",b);
        printf("\n");
        printf(" ");
        printf("\n");
    } else {
        EditNewChar(is_create_char4,type,char4_hp,char4_atk,char4_def,char4_name);
    }
}

char SelectAndBattle(int first1,int second1) {
    int first,second;
    printf(" ");
    printf("\n");
    printf("��ܥ��𨤦�:");
    scanf("%d",&first);
    while(first>4) {                                      ////////�Y��ܥ��𨤦⤣�s�b(�̦h�u���|�Ө���)
        printf("���~:�L������\n");
        printf("��ܥ��𨤦�:");
        scanf("%d",&first);
    }
    printf("��ܫ�𨤦�:");
    scanf("%d",&second);
    while(second>4) {                                     ////////�Y��ܫ�𨤦⤣�s�b(�̦h�u���|�Ө���)
        printf("���~:�L������\n");
        printf("��ܫ�𨤦�:");
        scanf("%d",&second);
    }
    if(first==second) {                                   ////////�Y��ܥ����𨤦�ۦP��
        printf("���~:���i���ƿ��\n");
        printf("��ܥ��𨤦�:");
        scanf("%d",&first);
        while(first>4) {
            printf("���~:�L������\n");
            printf("��ܥ��𨤦�:");
            scanf("%d",&first);
        }
        printf("��ܫ�𨤦�:");
        scanf("%d",&second);
        while(second>4) {
            printf("���~:�L������\n");
            printf("��ܫ�𨤦�:");
            scanf("%d",&second);
        }
    }
    printf("\n");
    printf("���𨤦⬰%d\n",first);
    printf("��𨤦⬰%d",second);
    printf("\n");
    printf("     ");
    printf("\n");
    printf("���𨤦⬰%d�B",first);
    printf("��𨤦⬰%d",second);
    printf("\n");
}
int main() {
    char char4_name[21]= {0};
    int is_create_char4=0;
    char type;
    char type1;
    int  char_hp,char_atk,char_def;
    char char_name;
    int hp,atk,def;
    int hp1,atk1,def1;
    int hp2,atk2,def2;
    int num;
    int hp_1,hp_2;
    char type_1,type_2,type_3;
    int char4_hp,char4_atk,char4_def;
    int test=0;
    int err_type = 0;
    char first_type,second_type;
    int first,second;
    int first_hp,first_atk,first_def;
    int second_hp,second_atk,second_def;
    int first_dam,second_dam;
    int first1,second1;
    while(num!=EOF) {
        printf("1.�s�W�έק�s����\n2.��ܩҦ�������\n3.�԰�\n0.�����C��\n");
        printf("�п��:");
        scanf("%d",&num);
        if(num<0||num>3) {
            printf("\n");
            printf("��J���~!\n",num);
            printf("\n");
            printf("1.�s�W�έק�s����\n2.��ܩҦ�������\n3.�԰�\n0.�����C��\n");
            printf("�п��:");
            scanf("%d",&num);
        }
        switch(num) {                               //////��ܼҦ�
        case 0: {
            printf("�����C��");
            return 0;
        }
        case 1: {

            EditNewChar(&is_create_char4,type,char4_hp,char4_atk,char4_def,char4_name);
            break;
        }
        case 2: {
            PrintCharData(char_name,hp,atk,def);
            if(char4_name[0]!=0) {
                printf("����4\n");
                printf("�W��:%s\n",char4_name);
                printf("�ݩ�:%c   ",type);
                printf("����:%d\n",char4_atk);
                printf("��q:%d   ",char4_hp);
                printf("���m:%d\n",char4_def);
                printf("\n");
            }
            break;
        }
        case 3: {
            SelectAndBattle(first1,second1);
            printf("�԰��}�l");
            printf("\n");
            printf("     ");
            printf("\n");
            switch(first) {                            ////////////�s�J���𨤦⪺�����ƾ�
            case 1:
                hp1=40;
                hp_1=40;
                atk1=15;
                def1=5;
                break;
            case 2:
                hp1=41;
                hp_1=41;
                atk1=16;
                def1=6;
                break;
            case 3:
                hp1=42;
                hp_1=42;
                atk1=17;
                def1=7;
                break;
            case 4:
                hp1=char4_hp;
                atk1=char4_atk;
                def1=char4_def;
                break;
            default:
                hp1=0;
                break;
            }
            switch(second) {                          ////////////�s�J��𨤦⪺�����ƾ�
            case 1:
                hp2=40;
                hp_2=40;
                atk2=15;
                def2=5;
                break;
            case 2:
                hp2=41;
                hp_2=41;
                atk2=16;
                def2=6;
                break;
            case 3:
                hp2=42;
                hp_2=42;
                atk2=17;
                def2=7;
                break;
            case 4:
                hp2=char4_hp;
                atk2=char4_atk;
                def2=char4_def;
                break;
            default:
                hp2=0;
                break;
            }
            first_dam=atk1-def2;               //////////�p��ˮ`���򥻤���(���۫g�B��q����̤j�Ȧ�q���@�b)
            second_dam=atk2-def1;
            switch(first) {                            ///////�M�w���𨤦��ݩ�
            case 1:
                type_1='F';
                break;
            case 2:
                type_2='W';
                break;
            case 3:
                type_3='G';
                break;
            case 4:
                break;

            }
            switch(second) {                              ///////�M�w��𨤦��ݩ�
            case 1:
                type_1='F';
                break;
            case 2:
                type_2='W';
                break;
            case 3:
                type_3='G';
                break;
            case 4:
                break;

            }

            while(hp1>0&&hp2>0) { ///////////��Ⱖ�}�ⳣ�٬���
                if(first==1&&second==2) { ///////////�P�_����𨤦���O���ݩʡA�å[�J�ݩʬ۫g���ˮ`�[���H�δݦ孿�v
                    first_dam=atk1*0.8-def2;
                    if(hp1<(hp_1)/2) {
                        first_dam=atk1*0.8*1.2-def2;
                    }
                    second_dam=atk2*1.2-def1;
                    if(hp2<(hp_2)/2) {
                        second_dam=atk2*1.2*1.2-def1;
                    }
                } else if(first==2&&second==1) {
                    first_dam=atk1*1.2-def2;

                    if(hp1<(hp_1)/2) {
                        first_dam=atk1*1.2*1.2-def2;
                    }
                    second_dam=atk2*0.8-def1;
                    if(hp2<(hp_2)/2) {
                        second_dam=atk2*0.8*1.2-def1;

                    }
                } else if(first==2&&second==3) {
                    first_dam=atk1*0.8-def2;
                    if(hp1<(hp_1)/2) {
                        first_dam=atk1*0.8*1.2-def2;
                    }
                    second_dam=atk2*1.2-def1;
                    if(hp2<(hp_2)/2) {
                        second_dam=atk2*1.2*1.2-def1;
                    }
                } else if(first==3&&second==2) {
                    first_dam=atk1*1.2-def2;
                    if(hp1<(hp_1)/2) {
                        first_dam=atk1*1.2*1.2-def2;
                    }
                    second_dam=atk2*0.8-def1;
                    if(hp2<(hp_2)/2) {
                        second_dam=atk2*0.8*1.2-def1;
                    }
                } else if(first==1&&second==3) {
                    if(hp1<(hp_1)/2) {
                        first_dam=atk1*1.2-def2;
                    }
                    if(hp2<(hp_2)/2) {
                        second_dam=atk2*1.2-def1;
                    }
                } else if(first==3&&second==1) {
                    if(hp1<(hp_1)/2) {
                        first_dam=atk1*1.2-def2;
                    }
                    if(hp2<(hp_2)/2) {
                        second_dam=atk2*1.2-def1;
                    }
                }
                if(first==4&&second==1) {

                    if(type=='W'||type=='w') {
                        first_dam=atk1*1.2-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;
                        }
                    }

                    else if(type=='A'||type=='a') {
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    } else if(type=='F'||type=='f') {

                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    } else if(type=='G'||type=='g') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    }
                }
                if(first==1&&second==4) {
                    if(type=='W'||type=='w') {
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    } else if(type=='A'||type=='a') {
                        first_dam=atk1*1.2-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;
                        }
                    } else if(type=='F'||type=='f') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    } else if(type=='G'||type=='g') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    }
                }
                if(first==4&&second==2) {
                    if(type=='G'||type=='g') {
                        first_dam=atk1*1.2-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;
                        }
                    } else if(type=='F'||type=='f') {
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    } else if(type=='A'||type=='a') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    } else if(type=='W'||type=='w') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    }
                }
                if(first==2&&second==4) {
                    if(type=='G'||type=='g') {
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    }
                    if(type=='F'||type=='f') {
                        first_dam=atk1*1.2-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;
                        }
                    } else if(type=='A'||type=='a') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    } else if(type=='W'||type=='w') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    }
                }
                if(first==4&&second==3) {
                    if(type=='A'||type=='a') {
                        first_dam=atk1*1.2-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;
                        }
                    }
                    if(type=='W'||type=='w') {
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    } else if(type=='F'||type=='f') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    } else if(type=='G'||type=='g') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    }
                }
                if(first==3&&second==4) {
                    if(type=='A'||type=='a') {
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    }
                    if(type=='W'||type=='w') {
                        first_dam=atk1*1.2-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;
                        }
                    } else if(type=='F'||type=='f') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    } else if(type=='G'||type=='g') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    }
                }

                hp2=hp2-first_dam; ///////�p���`�ˮ`
                printf("����%d �﨤��%d �o�ʧ����A�y��%d�ˮ`\n����%d HP %d  ����%d  HP %d\n",first,second,first_dam,first,hp1,second,hp2);
                printf("\n");
                if(hp2>0) {

                    if(first==1&&second==2) { ///////////�P�_����𨤦���O���ݩʡA�å[�J�ݩʬ۫g���ˮ`�[���H�δݦ孿�v
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    } else if(first==2&&second==1) {
                        first_dam=atk1*1.2-def2;

                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;

                        }
                    } else if(first==2&&second==3) {
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    } else if(first==3&&second==2) {
                        first_dam=atk1*1.2-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;
                        }
                    }
                    if(first==4&&second==1) {
                        if(type=='W'||type=='w') {
                            first_dam=atk1*1.2-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2*1.2-def2;
                            }
                            second_dam=atk2*0.8-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*0.8*1.2-def1;
                            }
                        }

                        else if(type=='A'||type=='a') {
                            first_dam=atk1*0.8-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*0.8*1.2-def2;
                            }
                            second_dam=atk2*1.2-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2*1.2-def1;
                            }
                        } else if(type=='f'||type=='F') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        } else if(type=='G'||type=='g') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        }
                    }
                    if(first==1&&second==4) {
                        if(type=='W'||type=='w') {
                            first_dam=atk1*0.8-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*0.8*1.2-def2;
                            }
                            second_dam=atk2*1.2-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2*1.2-def1;
                            }
                        } else if(type=='A'||type=='a') {
                            first_dam=atk1*1.2-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2*1.2-def2;
                            }
                            second_dam=atk2*0.8-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*0.8*1.2-def1;
                            }
                        } else if(type=='F'||type=='f') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        } else if(type=='G'||type=='g') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        }
                    }
                    if(first==4&&second==2) {
                        if(type=='G'||type=='g') {
                            first_dam=atk1*1.2-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2*1.2-def2;
                            }
                            second_dam=atk2*0.8-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*0.8*1.2-def1;
                            }
                        } else if(type=='F'||type=='f') {
                            first_dam=atk1*0.8-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*0.8*1.2-def2;
                            }
                            second_dam=atk2*1.2-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2*1.2-def1;
                            }
                        } else if(type=='A'||type=='a') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        } else if(type=='W'||type=='w') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        }
                    }
                    if(first==2&&second==4) {
                        if(type=='G'||type=='g') {
                            first_dam=atk1*0.8-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*0.8*1.2-def2;
                            }
                            second_dam=atk2*1.2-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2*1.2-def1;
                            }
                        }
                        if(type=='F'||type=='f') {
                            first_dam=atk1*1.2-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2*1.2-def2;
                            }
                            second_dam=atk2*0.8-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*0.8*1.2-def1;
                            }
                        } else if(type=='A'||type=='a') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        } else if(type=='W'||type=='w') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        }
                    }
                    if(first==4&&second==3) {
                        if(type=='A'||type=='a') {
                            first_dam=atk1*1.2-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2*1.2-def2;
                            }
                            second_dam=atk2*0.8-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*0.8*1.2-def1;
                            }
                        }
                        if(type=='W'||type=='w') {
                            first_dam=atk1*0.8-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*0.8*1.2-def2;
                            }
                            second_dam=atk2*1.2-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2*1.2-def1;
                            }
                        } else if(type=='F'||type=='f') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        } else if(type=='G'||type=='g') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        }
                    }
                    if(first==3&&second==4) {
                        if(type=='A'||type=='a') {
                            first_dam=atk1*0.8-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*0.8*1.2-def2;
                            }
                            second_dam=atk2*1.2-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2*1.2-def1;
                            }
                        }
                        if(type=='W'||type=='w') {
                            first_dam=atk1*1.2-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2*1.2-def2;
                            }
                            second_dam=atk2*0.8-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*0.8*1.2-def1;
                            }
                        } else if(type=='F'||type=='f') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        } else if(type=='G'||type=='g') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        }
                    }
                    hp1=hp1-second_dam; ///////�p���`�ˮ`
                    printf("����%d �﨤��%d �o�ʧ����A�y��%d�ˮ`\n����%d HP %d  ����%d  HP %d\n",second,first,second_dam,first,hp1,second,hp2);
                    printf("\n");
                }

            }
            if(hp1<=0||hp2<=0) { ////////��ӹ�Ԩ��⪺��q�k�s
                if(hp1<=0) {
                    printf("����%d  ���h�԰���O\n�԰�����\n",first);
                    printf("\n");
                    printf("����%d ���",second);
                } else {
                    printf("����%d  ���h�԰���O\n�԰�����\n",second);
                    printf("\n");
                    printf("����%d ���",first);
                }
                printf("\n");
                printf(" ");
                printf("\n");
            }
        }
        }
    }
    return 0;
}
