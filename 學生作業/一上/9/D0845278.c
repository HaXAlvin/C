#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
void playerchoose() {
    printf("1.�s�W�έק�s�W����\n");
    printf("2.��ܩҦ�������\n");
    printf("3.�԰�\n");
    printf("0.�����C��\n");
    printf("�п�ܡG");
    return;
}
void print_char_data(int i,char char_name[],char type,int atk,int hp,int def) {//����j�׭p��M�L�X�����T
    //����j�׹w�� = ( ��q * 1.0 + ���� * 0.8 + ���m * 0.5 - 50 ) * 6.5
    float strongpre = (hp*1.0 + atk * 0.8 + def * 0.5 -50 ) * 6.5;
    printf("����%d\n�W��:%s\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w��:%.2f\n\n",i,char_name,type,atk,hp,def,strongpre);
}
int does_addchar_correct(char type,int atk,int hp,int def) {//�P�_����s�W��T�O�_���T
    int correctflag=1;
    if(type != 'F' && type != 'W' && type != 'G' && type != 'A'&& type != 'f' && type != 'w' && type != 'g' && type != 'a') {
        printf("���~�G�L���ݩ�\n");
        correctflag = 0;
    }
    int char4_total = hp + atk + def;
    if(hp < 40 || hp > 50 || atk < 15 || atk > 20 || def < 5 || def > 10 || char4_total < 65 || char4_total > 70) {
        printf("���~�G��O�ƭȦb����d�򤧥~\n");
        printf("\n");
        correctflag = 0;
    }
    if(correctflag==0)
        return 0;
    else if(correctflag==1)
        return 1;
}
void addchar(int addcharflag,char char_name[][21],char type[],int hp[],int atk[],int def[]) {//�s�W�P�ק﨤��
    if(addcharflag==0) {
        printf("�s�W����\n");
        printf("�W��:");
        scanf("%s",&char_name[4]);
        printf("����(F=���BW=���BG=�g�BA=��):");
        scanf(" %c", &type[4]);
        printf("��q(40~50):");
        scanf("%d", &hp[4]);
        printf("����(15~20):");
        scanf("%d", &atk[4]);
        printf("���m(5~10):");
        scanf("%d", &def[4]);
        printf("\n");
        return;
    } else if(addcharflag==1) {
        printf("�ק�s�W����\n");
        printf("�W��:");
        scanf("%s",&char_name[4]);
        printf("����(F=���BW=���BG=�g�BA=��):");
        scanf(" %c", &type[4]);
        printf("��q(40~50):");
        scanf("%d", &hp[4]);
        printf("����(15~20):");
        scanf("%d", &atk[4]);
        printf("���m(5~10):");
        scanf("%d", &def[4]);
        printf("\n");
        return;
    }
}
float first_blood_rate(char first_atk_type,char last_atk_type) {//�p��ݮh���v
    if((first_atk_type=='W'&&last_atk_type=='F')||(first_atk_type=='F'&&last_atk_type=='A')||
            (first_atk_type=='A'&&last_atk_type=='G')||(first_atk_type=='G'&&last_atk_type=='W'))
        return 1.2;//firstatkhurt = first_atk_atk*1.2;
    else if((first_atk_type=='F'&&last_atk_type=='W')||(first_atk_type=='A'&&last_atk_type=='F')||
            (first_atk_type=='G'&&last_atk_type=='A')||(first_atk_type=='W'&&last_atk_type=='G'))
        return 0.8;//firstatkhurt = first_atk_atk*0.8;
    else
        return 1.0;
}
float last_blood_rate(char first_atk_type,char last_atk_type) {//�p��ݮh���v
    if((last_atk_type=='W'&&first_atk_type=='F')||(last_atk_type=='F'&&first_atk_type=='A')||
            (last_atk_type=='A'&&first_atk_type=='G')||(last_atk_type=='G'&&first_atk_type=='W'))
        return 1.2;//lastatkhurt = last_atk_atk*1.2;
    else if((last_atk_type=='F'&&first_atk_type=='W')||(last_atk_type=='A'&&first_atk_type=='F')||
            (last_atk_type=='G'&&first_atk_type=='A')||(last_atk_type=='W'&&first_atk_type=='G'))
        return 0.8;//lastatkhurt = last_atk_atk*0.8;
}
//�����ˮ` = (int)(����������O * �۫g���v * �ݦ孿�v - �Q�����訾�m�O)
//�ݩʬ۫g���v�G�ݩ����YW>F>A>G>W
//�Y���۫g���Y�G�u�ժ�1.2���A�H�ժ�0.8��,�Y����L�۫g�h�����O�U��1.0��
//�ݦ孿�v�G�������q�p��쥻��50%�ɴݦ孿�v��1.2��
//battling(first_atk_char,last_atk_char,first_atk_type,last_atk_type,first_atk_atk,last_atk_atk,first_atk_hp,last_atk_hp,first_atk_def,last_atk_def);
void battling(int first_atk_char,int last_atk_char,char first_atk_type,char last_atk_type,int first_atk_atk,int last_atk_atk,int first_atk_hp,int last_atk_hp,int first_atk_def,int last_atk_def) {
    int round = 0;
    float firstatkhurt=0;//��������Oaddchar(addchar_flag,char_name[4],type[4],hp[4],atk[4],def[4]);
    float lastatkhurt=0;//�������O
    int max_first_atk_hp = first_atk_hp;
    int max_last_atk_hp = last_atk_hp;
    while(first_atk_char> 0||last_atk_char> 0) {
        //�����ˮ` = ����������O*�۫g���v*�ݦ孿�v - �Q�����訾�m�O
        float firstbloodrate = first_blood_rate(first_atk_type,last_atk_type);
        float lastbloodrate = last_blood_rate(first_atk_type,last_atk_type);
        firstatkhurt = first_atk_atk * firstbloodrate;
        lastatkhurt = last_atk_atk * lastbloodrate;
        //�P�_�ĴX�^�X�H������𶶧ǥ洫
        if(round%2==0) {
            if(first_atk_hp<(0.5 * max_first_atk_hp))//�P�_�ݼg���v
                firstatkhurt = firstatkhurt*1.2;
            int finalfirstatkhurt = firstatkhurt-last_atk_def;//����m�O
            printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n",first_atk_char,last_atk_char,finalfirstatkhurt);
            last_atk_hp = last_atk_hp - finalfirstatkhurt;
            printf("����%d HP: %d ����%d HP: %d\n\n",first_atk_char,first_atk_hp,last_atk_char,last_atk_hp);
        } else if(round%2==1) {
            if(last_atk_hp<(0.5 * max_last_atk_hp))
                lastatkhurt=lastatkhurt*1.2;
            int finallastatkhurt = lastatkhurt-first_atk_def;
            printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n",last_atk_char,first_atk_char,finallastatkhurt);
            first_atk_hp = first_atk_hp - finallastatkhurt;
            printf("����%d HP: %d ����%d HP: %d\n\n",first_atk_char,first_atk_hp,last_atk_char,last_atk_hp);
        }
        round++;//����@���j��h�@�^�X
        if(first_atk_hp<=0) {
            printf("����%d ���h�԰���O\n",first_atk_char);
            printf("�԰�����\n");
            printf("\n����%d ���\n\n",last_atk_char);
            break;//�@������S����ܰT���ᵲ���j��
        } else if(last_atk_hp<=0) {
            printf("����%d ���h�԰���O\n",last_atk_char);
            printf("�԰�����\n");
            printf("\n����%d ���\n\n",first_atk_char);
            break;//�@������S����ܰT���ᵲ���j��
        }
    }
}
void SelectAndBattle(int first_atk_char,int last_atk_char,char type[],int hp[],int atk[],int def[]) {//��J�԰������T�ΧP�_�O�_��J���~
    int first_atk_hp, first_atk_atk,first_atk_def,last_atk_hp,last_atk_atk,last_atk_def,first_atk_type,last_atk_type;
    do {
        do {
            printf("��ܥ��𨤦�:");
            scanf("%d",&first_atk_char);
            if(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3&&first_atk_char!=4)  //�@����J�ëD�w�w�q����A��X���~
                printf("���~:�L������\n");
        } while(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3&&first_atk_char!=4);
        do {
            printf("��ܫ�𨤦�:");
            scanf("%d",&last_atk_char);
            if(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3&&last_atk_char!=4)  //�@����J�ëD�w�w�q����A��X���~
                printf("���~:�L������\n");
        } while(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3&&last_atk_char!=4);
        if(first_atk_char==last_atk_char)   //�@�����𨤦ⵥ���𨤦�A��X���~
            printf("���~:���i���ƿ��\n");
    } while(first_atk_char==last_atk_char);
    printf("\n���𨤦⬰%d �A��𨤦⬰%d\n",first_atk_char,last_atk_char);  //�L�X�̲׿�J
    printf("�}�l�԰�\n\n");
    if(first_atk_char == 1) {
        first_atk_hp = hp[1];
        first_atk_atk = atk[1];
        first_atk_def = def[1];
        first_atk_type = type[1];
    } else if (first_atk_char == 2) {
        first_atk_hp = hp[2];
        first_atk_atk = atk[2];
        first_atk_def = def[2];
        first_atk_type = type[2];
    } else if (first_atk_char ==3) {
        first_atk_hp = hp[3];
        first_atk_atk = atk[3];
        first_atk_def = def[3];
        first_atk_type = type[3];
    } else if (first_atk_char ==4) {
        first_atk_hp = hp[4];
        first_atk_atk = atk[4];
        first_atk_def = def[4];
        first_atk_type = type[4];
    }
    if(last_atk_char == 1) {
        last_atk_hp = hp[1];
        last_atk_atk = atk[1];
        last_atk_def = def[1];
        last_atk_type = type[1];
    } else if (last_atk_char == 2) {
        last_atk_hp = hp[2];
        last_atk_atk = atk[2];
        last_atk_def = def[2];
        last_atk_type = type[2];
    } else if (last_atk_char == 3) {
        last_atk_hp = hp[3];
        last_atk_atk = atk[3];
        last_atk_def = def[3];
        last_atk_type = type[3];
    } else if (last_atk_char == 4) {
        last_atk_hp = hp[4];
        last_atk_atk = atk[4];
        last_atk_def = def[4];
        last_atk_type = type[4];
    }//�԰�
    battling(first_atk_char,last_atk_char,first_atk_type,last_atk_type,first_atk_atk,last_atk_atk,first_atk_hp,last_atk_hp,first_atk_def,last_atk_def);
}
void SelectAndBattle123(int first_atk_char,int last_atk_char,char type[],int hp[],int atk[],int def[]) {//��J�԰������T�ΧP�_�O�_��J���~
    int first_atk_hp, first_atk_atk,first_atk_def,last_atk_hp,last_atk_atk,last_atk_def,first_atk_type,last_atk_type;
    do {
        do {
            printf("��ܥ��𨤦�:");
            scanf("%d",&first_atk_char);
            if(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3)  //�@����J�ëD�w�w�q����A��X���~
                printf("���~:�L������\n");
        } while(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3);
        do {
            printf("��ܫ�𨤦�:");
            scanf("%d",&last_atk_char);
            if(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3)  //�@����J�ëD�w�w�q����A��X���~
                printf("���~:�L������\n");
        } while(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3);
        if(first_atk_char==last_atk_char)   //�@�����𨤦ⵥ���𨤦�A��X���~
            printf("���~:���i���ƿ��\n");
    } while(first_atk_char==last_atk_char);
    printf("\n���𨤦⬰%d �A��𨤦⬰%d\n",first_atk_char,last_atk_char);  //�L�X�̲׿�J
    printf("�}�l�԰�\n\n");
    if(first_atk_char == 1) {
        first_atk_hp = hp[1];
        first_atk_atk = atk[1];
        first_atk_def = def[1];
        first_atk_type = type[1];
    } else if (first_atk_char == 2) {
        first_atk_hp = hp[2];
        first_atk_atk = atk[2];
        first_atk_def = def[2];
        first_atk_type = type[2];
    } else if (first_atk_char ==3) {
        first_atk_hp = hp[3];
        first_atk_atk = atk[3];
        first_atk_def = def[3];
        first_atk_type = type[3];
    }
    if(last_atk_char == 1) {
        last_atk_hp = hp[1];
        last_atk_atk = atk[1];
        last_atk_def = def[1];
        last_atk_type = type[1];
    } else if (last_atk_char == 2) {
        last_atk_hp = hp[2];
        last_atk_atk = atk[2];
        last_atk_def = def[2];
        last_atk_type = type[2];
    } else if (last_atk_char == 3) {
        last_atk_hp = hp[3];
        last_atk_atk = atk[3];
        last_atk_def = def[3];
        last_atk_type = type[3];
    }//�԰�
    battling(first_atk_char,last_atk_char,first_atk_type,last_atk_type,first_atk_atk,last_atk_atk,first_atk_hp,last_atk_hp,first_atk_def,last_atk_def);
}
int main() {
    int playerchose;
    float strongpre[5];
    char type[5]= {'0','W','A','F','0'};
    char char_name [5][21]= {"","�C���a��","�V�嬰��","�W���S�u",""};
    int hp[5] = {0,50,40,45,0};
    int atk[5] = {0,15,20,17,0};
    int def[5] = {0,5,8,7,0};
    int i,j,k;
    int first_atk_char,last_atk_char,addchar_flag=0,correctflag = 1;
    while(5) { //�@���`�����D���쵲��
        playerchoose();
        scanf("%d",&playerchose);
        printf("\n");
        if(playerchose==1) {
            int exit = 0;
            if (addchar_flag==0) {
                while(!exit) {//�p��s�W���⪺�j�סA�æL�X����4���̲׸�T
                    addchar(addchar_flag,char_name,type,hp,atk,def);
                    if(type[4] >= 'a')
                        type[4] -= 32;
                    exit = does_addchar_correct(type[4],atk[4],hp[4],def[4]);
                }
                print_char_data(4,char_name[4],type[4],atk[4],hp[4],def[4]);
                addchar_flag=1;//�����O�_������4
            } else if(addchar_flag==1) {//�p��ק�s�W���⪺�j�סA�æL�X����4���̲׸�T
                while(!exit) {
                    addchar(addchar_flag,char_name,type,hp,atk,def);
                    if(type[4] >= 'a')
                        type[4] -= 32;
                    exit = does_addchar_correct(type[4],atk[4],hp[4],def[4]);
                }
                print_char_data(4,char_name[4],type[4],atk[4],hp[4],def[4]);
                addchar_flag=1;//�����O�_������4
            }
        } else if(playerchose==2) {
            if(addchar_flag==0) { //�S������4
                print_char_data(1,char_name[1],type[1],atk[1],hp[1],def[1]);
                print_char_data(2,char_name[2],type[2],atk[2],hp[2],def[2]);
                print_char_data(3,char_name[3],type[3],atk[3],hp[3],def[3]);
            } else if (addchar_flag==1) { //������4
                print_char_data(1,char_name[1],type[1],atk[1],hp[1],def[1]);
                print_char_data(2,char_name[2],type[2],atk[2],hp[2],def[2]);
                print_char_data(3,char_name[3],type[3],atk[3],hp[3],def[3]);
                print_char_data(4,char_name[4],type[4],atk[4],hp[4],def[4]);
            }
        } else if(playerchose==3) {
            if(addchar_flag==0) {
                SelectAndBattle123(first_atk_char,last_atk_char,type,hp,atk,def);
            } else if(addchar_flag==1) {
                SelectAndBattle(first_atk_char,last_atk_char,type,hp,atk,def);
            }
        } else if(playerchose==0) {
            printf("�����C��\n");
            return 0;
        } else
            printf("��J���~�I\n\n");
    }
    return 0;
}


