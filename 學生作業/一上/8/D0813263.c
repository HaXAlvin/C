#include<stdio.h>
#include<ctype.h>

int main() {
    char name[][100] = {"���O��","�����N","�_�դ��",""};
    char type[10] = "WAF";
    int hp[4] = {50,40,45};
    int atk[4] = {15,20,17};
    int def[4] = {5,8,7};
    int n = 1;//flag
    int role = 3;//�@�}�l������ƥ�
    float T_ratio[2] = {0};//�۫g���v
    float B_ratio;//�ݦ孿�v
    int num,i,first_atk,second_atk;
    float val[4] = {.0};//�j�׹w��

    while (n == 1){
        do {
            n = 1;
            printf("1. �s�W����έק﨤��\n2. ��ܩҦ�������\n3. �԰�\n0. �����C��\n�п��:");
            scanf("%d",&num);
            printf("\n");
            if ((num < 0) || (num > 3)){
                printf("��J���~!\n\n");
                n = 0;
            }
        }while (n == 0);

        switch (num){
            case 1:
                do {
                    n = 0;
                    if (role < 4){
                        printf("\n�s�W����\n");
                    }
                    else {
                        printf("\n�ק�s�W����\n");
                    }
                    printf("�W��:");
                    scanf("%s",name[3]);
                    printf("�ݩ�:");
                    scanf(" %c",&type[3]);
                    printf("��q:");
                    scanf("%d",&hp[3]);
                    printf("�����O:");
                    scanf("%d",&atk[3]);
                    printf("���m�O:");
                    scanf("%d",&def[3]);

                    //�ݩʿ��~���s��J
                    int sum = atk[3] + def[3] + hp[3];
                    val[3] = ((hp[3]*1.0)+(atk[3]*0.8)+(def[3]*0.5)-50)*6.5;
                    if (type[3] != 'F' && type[3] != 'W' && type[3] != 'G' && type[3] != 'A' && type[3] != 'f' && type[3] != 'w' && type[3] != 'g' && type[3] != 'a'){
                        printf("���~:�L���ݩ�\n");
                        n = 1;
                    }
                    //��O�ȿ��~���s��J
                    if (atk[3] < 15 || atk[3] > 20 || def[3] < 5 || def[3] > 10 || hp[3] < 40 || hp[3] > 50 || sum < 65 || sum > 70){
                        printf("���~:��O�ƭȦb����d�򤧥~\n");
                        n = 1;
                    }
                    //�ݩʤj�p�g�ഫ
                    if (islower(type[3])){
                       type[3] = toupper(type[3]);
                    }
                }while (n == 1);
                printf("\n����4\n�W��:%s\n�ݩ�:%c\t\t����:%d\n��q:%d\t\t���m:%d\n����j�׹w��:%.2f\n\n",name[3],type[3],atk[3],hp[3],def[3],val[3]);
                n = 1;
                role = 4;
                break;
            case 2:
                for (i = 0 ; i < role ; i++ ){
                    val[i] = ((hp[i] * 1.0) + (atk[i] * 0.8) + (def[i] * 0.5) - 50) * 6.5;
                    printf("����%d\n�W��:%s\n�ݩ�:%c\t\t����:%d\n��q:%d\t\t���m:%d\n����j�׹w��:%.2f\n\n",i+1,name[i],type[i],atk[i],hp[i],def[i],val[i]);
                }
                n = 1;
                break;
            case 3:
                do {
                    do{
                        n = 0;
                        printf("��ܥ��𨤦�:");
                        scanf("%d",&first_atk);
                        if (first_atk > role || first_atk < 1){
                            printf("���~:�L������\n");
                            n = 1;
                        }
                    }while(n == 1);
                    do{
                        n = 0;
                        printf("��ܫ�𨤦�:");
                        scanf("%d",&second_atk);
                        if (second_atk > role || second_atk < 1){
                            printf("���~:�L������\n");
                            n = 1;
                        }
                    }while(n == 1);
                    if (first_atk == second_atk){
                        printf("���~:���i���ƿ��\n\n");
                        n = 1;
                    }
                }while (n == 1);

                int atk1_hp,atk2_hp,atk1_atk,atk2_atk,atk1_def,atk2_def,atk1_type,atk2_type;

                printf("\n���𬰨���%d�B��𬰨���%d",first_atk,second_atk);
                printf("\n�԰��}�l");

                switch (first_atk){
                    case 1:
                        atk1_hp = hp[0];
                        atk1_atk = atk[0];
                        atk1_def = def[0];
                        atk1_type = type[0];
                        break;
                    case 2:
                        atk1_hp = hp[1];
                        atk1_atk = atk[1];
                        atk1_def = def[1];
                        atk1_type = type[1];
                        break;
                    case 3:
                        atk1_hp = hp[2];
                        atk1_atk = atk[2];
                        atk1_def = def[2];
                        atk1_type = type[2];
                        break;
                    case 4:
                        atk1_hp = hp[3];
                        atk1_atk = atk[3];
                        atk1_def = def[3];
                        atk1_type = type[3];
                        break;
                }
                switch (second_atk){
                    case 1:
                        atk2_hp = hp[0];
                        atk2_atk = atk[0];
                        atk2_def = def[0];
                        atk2_type = type[0];
                        break;
                    case 2:
                        atk2_hp = hp[1];
                        atk2_atk = atk[1];
                        atk2_def = def[1];
                        atk2_type = type[1];
                        break;
                    case 3:
                        atk2_hp = hp[2];
                        atk2_atk = atk[2];
                        atk2_def = def[2];
                        atk2_type = type[2];
                        break;
                    case 4:
                        atk2_hp = hp[3];
                        atk2_atk = atk[3];
                        atk2_def = def[3];
                        atk2_type = type[3];
                        break;
                }
                //�۫g���v
                T_ratio[0] = 1.0;
                T_ratio[1] = 1.0;
                switch (atk1_type){
                    case 'W':
                        if (atk2_type == 'F'){
                            T_ratio[0] = 1.2;
                            T_ratio[1] = 0.8;
                        }
                        if (atk2_type == 'G'){
                            T_ratio[0] = 0.8;
                            T_ratio[1] = 1.2;
                        }
                        break;
                    case 'F':
                        if (atk2_type == 'A'){
                            T_ratio[0] = 1.2;
                            T_ratio[1] = 0.8;
                        }
                        if (atk2_type == 'W'){
                            T_ratio[0] = 0.8;
                            T_ratio[1] = 1.2;
                        }
                        break;
                    case 'A':
                        if (atk2_type == 'G'){
                            T_ratio[0] = 1.2;
                            T_ratio[1] = 0.8;
                        }
                        if (atk2_type == 'F'){
                            T_ratio[0] = 0.8;
                            T_ratio[1] = 1.2;
                        }
                        break;
                    case 'G':
                        if (atk2_type == 'W'){
                            T_ratio[0] = 1.2;
                            T_ratio[1] = 0.8;
                        }
                        if (atk2_type == 'A'){
                            T_ratio[0] = 0.8;
                            T_ratio[1] = 1.2;
                        }
                        break;
                }

                int atk1_hurt,atk2_hurt;
                int half_atk1 = atk1_hp / 2;//�������q�p��쥻��50%
                int half_atk2 = atk2_hp / 2;
                //�����^�X���
                while (atk1_hp > 0 || atk2_hp > 0){
                    //�ݦ孿�v
                    if (atk1_hp < half_atk1){
                        B_ratio = 1.2;
                    }
                    else {
                        B_ratio = 1.0;
                    }
                    //�����ˮ`
                    atk1_hurt = (int)(atk1_atk * T_ratio[0] * B_ratio - atk2_def);
                    atk2_hp -= atk1_hurt;//���ۧ����ᤧ��q
                    printf("\n\n����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n����%d HP:%d ����%d HP:%d\n",first_atk,second_atk,atk1_hurt,first_atk,atk1_hp,second_atk,atk2_hp);
                    if (atk2_hp <= 0){
                        printf("\n����%d ���h�԰���O\n�԰�����\n\n",second_atk);
                        printf("����%d ���\n\n",first_atk);
                        break;
                    }
                    //�ݦ孿�v
                    if (atk2_hp < half_atk2){
                        B_ratio = 1.2;
                    }
                    else {
                        B_ratio = 1.0;
                    }
                    //�����ˮ`
                    atk2_hurt = (int)(atk2_atk * T_ratio[1] * B_ratio - atk1_def);
                    atk1_hp -= atk2_hurt;//���ۧ����ᤧ��q
                    printf("\n\n����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n����%d HP:%d ����%d HP:%d\n",second_atk,first_atk,atk2_hurt,first_atk,atk1_hp,second_atk,atk2_hp);
                    if (atk1_hp <= 0){
                        printf("\n����%d ���h�԰���O\n�԰�����\n\n",first_atk);
                        printf("����%d ���\n\n",second_atk);
                        break;
                    }
                }
                n = 1;
                break;
            case 0:
                printf("�����C��\n");
                n = 0;
                break;
        }
    }
}
