#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
int main() {
    int playerchose;
    char char1_name [21]= "�C���a��";
    char char2_name [21]= "�V�嬰��";
    char char3_name [21]= "�W���S�u";
    char char4_name [21];
    char type[5]= {'0','W','A','F'};
    int hp[5];
    int atk[5];
    int def[5];
    float strongpre[4];
    int i,j,k;
    hp[1]= 50;
    hp[2]= 40;
    hp[3]= 45;
    atk[1]=15;
    atk[2]=20;
    atk[3]=17;
    def[1]=5;
    def[2]=8;
    def[3]=7;
    //�j�׹w�� = ( ��q * 1.0 + ���� * 0.8 + ���m * 0.5 - 50 ) * 6.5
    strongpre[1]= (hp[1] * 1.0 + atk[1] * 0.8 + def[1] * 0.5-50) * 6.5 ;
    strongpre[2]= (hp[2] * 1.0 + atk[2] * 0.8 + def[2] * 0.5-50) * 6.5 ;
    strongpre[3] = (hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5-50) * 6.5 ;
    int addchar,first_atk_char,last_atk_char,addchar_flag=0,correctflag = 1;
    while(5) { //�@���`�����D���쵲��
        printf("1.�s�W�έק�s�W����\n");
        printf("2.��ܩҦ�������\n");
        printf("3.�԰�\n");
        printf("0.�����C��\n");
        printf("�п�ܡG");
        scanf("%d",&playerchose);
        printf("\n");
        if(playerchose==1) {
            if (addchar_flag==0) {
                do {
                    correctflag = 1; //��lflag
                    printf("�s�W����\n");
                    printf("�W��:");
                    scanf("%s",&char4_name);
                    type[4]=getchar();
                    printf("����(F=���BW=���BG=�g�BA=��):");
                    scanf("%c", &type[4]);
                    printf("��q(40~50):");
                    scanf("%d", &hp[4]);
                    printf("����(15~20):");
                    scanf("%d", &atk[4]);
                    printf("���m(5~10):");
                    scanf("%d", &def[4]);
                    if(type[4] != 'F' && type[4] != 'W' && type[4] != 'G' && type[4] != 'A' && type[4] != 'f' && type[4] != 'w' && type[4] != 'g' && type[4] != 'a') {
                        printf("���~�G�L���ݩ�\n");
                        correctflag = 0;
                    } else if(type[4] >= 'a')
                        type[4] -= 32;
                    int char4_total = hp[4] + atk[4] + def[4];
                    if(hp[4] < 40 || hp[4] > 50 || atk[4] < 15 || atk[4] > 20 || def[4] < 5 || def[4] > 10 || char4_total < 65 || char4_total > 70) {
                        printf("���~�G��O�ƭȦb����d�򤧥~\n\n");
                        correctflag = 0;
                    }
                } while(!correctflag);
                //�p��s�W���⪺�j�סA�æL�X����4���̲׸�T
                strongpre[4] = (hp[4] * 1.0 + atk[4] * 0.8 + def[4] * 0.5-50) * 6.5;
                printf("\n����4\n�W��:%s\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w��:%.2f\n\n",char4_name,type[4],atk[4],hp[4],def[4],strongpre[4]);
                addchar_flag=1;
            } else if(addchar_flag==1) {
                do {
                    correctflag = 1; //��lflag
                    printf("�ק�s�W����\n");
                    printf("�W��:");
                    scanf("%s",&char4_name);
                    type[4] = getchar();
                    printf("����(F=���BW=���BG=�g�BA=��):");
                    scanf("%c", &type[4]);
                    printf("��q(40~50):");
                    scanf("%d", &hp[4]);
                    printf("����(15~20):");
                    scanf("%d", &atk[4]);
                    printf("���m(5~10):");
                    scanf("%d", &def[4]);
                    if(type[4] != 'F' && type[4] != 'W' && type[4] != 'G' && type[4] != 'A' && type[4] != 'f' && type[4] != 'w' && type[4] != 'g' && type[4] != 'a') {
                        printf("���~�G�L���ݩ�\n");
                        correctflag = 0;
                    } else if(type[4] >= 'a')
                        type[4] -= 32;
                    int char4_total = hp[4] + atk[4] + def[4];
                    if(hp[4] < 40 || hp[4] > 50 || atk[4] < 15 || atk[4] > 20 || def[4] < 5 || def[4] > 10 || char4_total < 65 || char4_total > 70) {
                        printf("\n���~�G��O�ƭȦb����d�򤧥~\n\n");
                        correctflag = 0;
                    }
                } while(!correctflag);
                //�p��s�W���⪺�j�סA�æL�X����4���̲׸�T
                strongpre[4] = (hp[4] * 1.0 + atk[4] * 0.8 + def[4] * 0.5-50) * 6.5;
                printf("\n����4\n�W��:%s\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w��:%.2f\n\n",char4_name,type[4],atk[4],hp[4],def[4],strongpre[4]);
                addchar_flag=1;//�����O�_������4
            }
        } else if(playerchose==2) {
            if(addchar_flag==0) { //�S������4
                printf("����1\n�W��:%s\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w��:%.2f\n\n",char1_name,type[1],atk[1],hp[1],def[1],strongpre[1]);
                printf("����2\n�W��:%s\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w��:%.2f\n\n",char2_name,type[2],atk[2],hp[2],def[2],strongpre[2]);
                printf("����3\n�W��:%s\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w��:%.2f\n\n",char3_name,type[3],atk[3],hp[3],def[3],strongpre[3]);
            } else if (addchar_flag==1) { //������4
                printf("����1\n�W��:%s\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w��:%.2f\n\n",char1_name,type[1],atk[1],hp[1],def[1],strongpre[1]);
                printf("����2\n�W��:%s\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w��:%.2f\n\n",char2_name,type[2],atk[2],hp[2],def[2],strongpre[2]);
                printf("����3\n�W��:%s\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w��:%.2f\n\n",char3_name,type[3],atk[3],hp[3],def[3],strongpre[3]);
                printf("����4\n�W��:%s\n�ݩ�:%c    ����:%d\n��q:%d   ���m:%d\n����j�׹w��:%.2f\n\n",char4_name,type[4],atk[4],hp[4],def[4],strongpre[4]);
            }
        } else if(playerchose==3) {
            do {
                do {
                    printf("��ܥ��𨤦�:");
                    first_atk_char = getchar();
                    scanf("%d",&first_atk_char);
                    if(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3&&first_atk_char!=4)  //�@����J�ëD�w�w�q����A��X���~
                        printf("���~:�L������\n");
                } while(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3&&first_atk_char!=4);
                do {
                    printf("��ܫ�𨤦�:");
                    last_atk_char = getchar();
                    scanf("%d",&last_atk_char);
                    if(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3&&last_atk_char!=4)  //�@����J�ëD�w�w�q����A��X���~
                        printf("���~:�L������\n");
                } while(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3&&last_atk_char!=4);
                if(first_atk_char==last_atk_char)   //�@�����𨤦ⵥ���𨤦�A��X���~
                    printf("���~:���i���ƿ��\n");
            } while(first_atk_char==last_atk_char);
            printf("\n���𨤦⬰%d �A��𨤦⬰%d\n",first_atk_char,last_atk_char);  //�L�X�̲׿�J
            printf("�}�l�԰�\n\n");
            //�s�W�x�s��T���ܼ�
            int first_atk_hp=0,first_atk_atk=0,first_atk_def=0,last_atk_hp=0,last_atk_atk=0,last_atk_def=0,round = 0;//�]�w�̪�^�X��0
            char first_atk_type,last_atk_type;
            //�P�_��J������A���ƿ�J�Ȧs��
            if(first_atk_char == 1) {
                first_atk_type = type[1];
                first_atk_hp = hp[1];
                first_atk_atk = atk[1];
                first_atk_def = def[1];
            } else if (first_atk_char == 2) {
                first_atk_type = type[2];
                first_atk_hp = hp[2];
                first_atk_atk = atk[2];
                first_atk_def = def[2];
            } else if (first_atk_char ==3) {
                first_atk_type = type[3];
                first_atk_hp = hp[3];
                first_atk_atk = atk[3];
                first_atk_def = def[3];
            } else if (first_atk_char ==4) {
                first_atk_type = type[4];
                first_atk_hp = hp[4];
                first_atk_atk = atk[4];
                first_atk_def = def[4];
            }
            if(last_atk_char == 1) {
                last_atk_type = type[1];
                last_atk_hp = hp[1];
                last_atk_atk = atk[1];
                last_atk_def = def[1];
            } else if (last_atk_char == 2) {
                last_atk_type = type[2];
                last_atk_hp = hp[2];
                last_atk_atk = atk[2];
                last_atk_def = def[2];
            } else if (last_atk_char == 3) {
                last_atk_type = type[3];
                last_atk_hp = hp[3];
                last_atk_atk = atk[3];
                last_atk_def = def[3];
            } else if (last_atk_char == 4) {
                last_atk_type = type[4];
                last_atk_hp = hp[4];
                last_atk_atk = atk[4];
                last_atk_def = def[4];
            }
            //�����ˮ` = (int)(����������O * �۫g���v * �ݦ孿�v - �Q�����訾�m�O)
            //�ݩʬ۫g���v�G�ݩ����YW>F>A>G>W
            //�Y���۫g���Y�G�u�ժ�1.2���A�H�ժ�0.8��,�Y����L�۫g�h�����O�U��1.0��
            //�ݦ孿�v�G�������q�p��쥻��50%�ɴݦ孿�v��1.2��
            float firstatkhurt=first_atk_atk;//��������O
            float lastatkhurt=last_atk_atk;//�������O
            int max_first_atk_hp = first_atk_hp;
            int max_last_atk_hp = last_atk_hp;
            while(first_atk_char> 0||last_atk_char> 0) {
                //�����ˮ` = ����������O*�۫g���v*�ݦ孿�v - �Q�����訾�m�O
                if((first_atk_type=='W'&&last_atk_type=='F')||(first_atk_type=='F'&&last_atk_type=='A')||
                        (first_atk_type=='A'&&last_atk_type=='G')||(first_atk_type=='G'&&last_atk_type=='W'))
                    firstatkhurt = first_atk_atk*1.2;
                else if((last_atk_type=='W'&&first_atk_type=='F')||(last_atk_type=='F'&&first_atk_type=='A')||
                        (last_atk_type=='A'&&first_atk_type=='G')||(last_atk_type=='G'&&first_atk_type=='W'))
                    lastatkhurt = last_atk_atk*1.2;
                else if((first_atk_type=='F'&&last_atk_type=='W')||(first_atk_type=='A'&&last_atk_type=='F')||
                        (first_atk_type=='G'&&last_atk_type=='A')||(first_atk_type=='W'&&last_atk_type=='G'))
                    firstatkhurt = first_atk_atk*0.8;
                else if((last_atk_type=='F'&&first_atk_type=='W')||(last_atk_type=='A'&&first_atk_type=='F')||
                        (last_atk_type=='G'&&first_atk_type=='A')||(last_atk_type=='W'&&first_atk_type=='G'))
                    lastatkhurt = last_atk_atk*0.8;
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
        } else if(playerchose==0) {
            printf("�����C��\n");
            return 0;
        } else
            printf("��J���~�I\n\n");
    }
    return 0;
}
