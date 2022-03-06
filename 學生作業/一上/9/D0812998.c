#include <stdio.h>
#include <stdlib.h>

char type[4]="WAF";
int hp[4]= {50,40,45};
int atk[4]= {15,20,17};
int def[4]= {5,8,7};

char char1_name[21]="���w�w";
char char2_name[21]="�p�i�R";
char char3_name[21]="�f���D�D";
char char4_name[21];


int main() {
    float type1,type2;
    float blood1,blood2;

    int char4_is_create=0;
    int is_correct,choose;
    while(1) {
        printf("1. �s�W�έק�s�W����\n");
        printf("2. ��ܩҦ�������\n");
        printf("3. �԰�\n");
        printf("0. �����C��\n");
        printf("�п�ܡG");
        scanf("%d",&choose);
        switch(choose) {
        case 1:
            EditNewChar(char4_is_create);
            char4_is_create = 1;
            break;
        case 2:
            PrintCharData(char4_is_create);
            break;
        case 3:
            SelectAndBattle(char4_is_create);
            break;
        case 0:
            printf("�����C��\n");
            return 0;

        default :
            printf("��J���~�I\n\n");

        }



        puts("");
    }
}

int EditNewChar(int char4_is_create) {
    int is_correct;

    do {
        is_correct = 1; //��l��flag
        if(char4_is_create == 0) {
            printf("\n�s�W����\n");
        } else {
            printf("\n�ק�s�W����\n");
        }

        printf("�W�١G");
        scanf("%s",char4_name);
        printf("�ݩʡG");
        scanf("%*c%c", &type[3]);
        printf("��q�G");
        scanf("%d", &hp[3]);
        printf("�����G");
        scanf("%d", &atk[3]);
        printf("���m�G");
        scanf("%d", &def[3]);
        //�˹��ݩ�
        if(type[3] != 'F' && type[3] != 'W' && type[3] != 'G' && type[3] != 'A' &&
                type[3] != 'f' && type[3] != 'w' && type[3] != 'g' && type[3] != 'a') {
            printf("���~�G�L���ݩ�\n");
            is_correct = 0;
        } else if(type[3] >= 'a')
            type[3] -= 32;
        //�ˬd��O�ƭ�
        int char4_sum = hp[3] + atk[3] + def[3];
        if(hp[3] < 40 || hp[3] > 50 || atk[3] < 15 || atk[3] > 20 ||
                def[3] < 5 || def[3] > 10 || char4_sum < 65 || char4_sum > 70) {
            printf("���~�G��O�ƭȦb����d�򤧥~\n");
            is_correct = 0;
        }
    } while(!is_correct);

    printf("\n����4\n�W�١G%s\n",char4_name);
    printf("�ݩʡG%c     �����G%d\n", type[3], atk[3]);
    printf("��q�G%d    ���m�G%d\n", hp[3], def[3]);
    printf("����j�׹w���G%.2f\n", (hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5 - 50.0) * 6.5 );

    printf("\n");
    //return choose;
}

int PrintCharData(int char4_is_create) {

    printf("����1\n�W�١G%s\n",char1_name);
    printf("�ݩʡG%c     �����G%d\n", type[0], atk[0]);
    printf("��q�G%d    ���m�G%d\n", hp[0], def[0]);
    printf("����j�׹w���G%.2f\n\n",
           (hp[0] * 1.0 + atk[0] * 0.8 + def[0] * 0.5 - 50.0) * 6.5 );
    printf("����2\n�W�١G%s\n",char2_name);
    printf("�ݩʡG%c     �����G%d\n", type[1], atk[1]);
    printf("��q�G%d    ���m�G%d\n", hp[1], def[1]);
    printf("����j�׹w���G%.2f\n\n",
           (hp[1] * 1.0 + atk[1] * 0.8 + def[1] * 0.5 - 50.0) * 6.5 );
    printf("����3\n�W�١G%s\n",char3_name);
    printf("�ݩʡG%c     �����G%d\n", type[2], atk[2]);
    printf("��q�G%d    ���m�G%d\n", hp[2], def[2]);
    printf("����j�׹w���G%.2f\n\n",
           (hp[2] * 1.0 + atk[2] * 0.8 + def[2] * 0.5 - 50.0) * 6.5 );
    if(char4_is_create == 1) {
        printf("\n����4\n�W�١G%s\n",char4_name);
        printf("�ݩʡG%c     �����G%d\n", type[3], atk[3]);
        printf("��q�G%d    ���m�G%d\n", hp[3], def[3]);
        printf("����j�׹w���G%.2f\n", (hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5 - 50.0) * 6.5 );
    }

    return ;
}
int SelectAndBattle(int char4_is_create) {
    int is_correct;
    int first_atk;


    int second_atk;

    do {
        is_correct = 1; //��l��flag
        printf("��ܥ��𨤦�G");
        scanf("%d", &first_atk);
        if(first_atk < 1 || first_atk > 3 + char4_is_create) {
            printf("���~�G�L������\n");
            is_correct = 0;
        }
    } while(!is_correct);
    do {
        is_correct = 1; //��l��flag
        printf("��ܫ�𨤦�G");
        scanf("%d", &second_atk);
        if(second_atk < 1 || second_atk > 3 + char4_is_create) {
            printf("���~�G�L������\n");
            is_correct = 0;
        } else if(second_atk == first_atk) {
            printf("���~�G���i���ƿ��\n");
            is_correct = 0;
        }
    } while(!is_correct);
    printf("\n���𬰨���%d�B��𬰨���%d\n", first_atk, second_atk);

    battle(first_atk, second_atk);

}
int battle(int first_atk,int second_atk) {
    char first_atk_type;
    int first_atk_origin_hp;
    int first_atk_hp;
    int first_atk_atk;
    int first_atk_def;

    char second_atk_type;
    int second_atk_origin_hp;
    int second_atk_hp;
    int second_atk_atk;
    int second_atk_def;

    int turn;
    float type1,type2;
    float blood1,blood2;

    //�N���𪺯�O��ƨ��X
    first_atk_type =  (first_atk == 1) ? type[0] : (first_atk == 2) ? type[1] : (first_atk == 3) ? type[2] : type[3];
    first_atk_hp = (first_atk == 1) ? hp[0] : (first_atk == 2) ? hp[1] : (first_atk == 3) ? hp[2] : hp[3];
    first_atk_atk = (first_atk == 1) ? atk[0] : (first_atk == 2) ? atk[1] : (first_atk == 3) ? atk[2] : atk[3];
    first_atk_def = (first_atk == 1) ? def[0] : (first_atk == 2) ? def[1] : (first_atk == 3) ? def[2] : def[3];
    //�N��𪺯�O��ƨ��X
    second_atk_type =  (second_atk == 1) ? type[0] : (second_atk == 2) ? type[1] : (second_atk == 3) ? type[2] : type[3];
    second_atk_hp = (second_atk == 1) ? hp[0] : (second_atk == 2) ? hp[1] : (second_atk == 3) ? hp[2] : hp[3];
    second_atk_atk = (second_atk == 1) ? atk[0] : (second_atk == 2) ? atk[1] : (second_atk == 3) ? atk[2] : atk[3];
    second_atk_def = (second_atk == 1) ? def[0] : (second_atk == 2) ? def[1] : (second_atk == 3) ? def[2] : def[3];

    turn = 1; //��l�Ƨ�����
    first_atk_origin_hp = first_atk_hp;
    second_atk_origin_hp = second_atk_hp;

    if( (first_atk_type == 'W' && second_atk_type == 'F') || (first_atk_type == 'F' && second_atk_type == 'A') ||(first_atk_type == 'A' && second_atk_type == 'G') ||(first_atk_type == 'G' && second_atk_type == 'W') ) {
        type1=1.2;
        type2=0.8;
    } else if( (first_atk_type == 'F' && second_atk_type == 'W') || (first_atk_type == 'A' && second_atk_type == 'F') ||(first_atk_type == 'G' && second_atk_type == 'A') ||(first_atk_type == 'W' && second_atk_type == 'G') ) {
        type1=0.8;
        type2=1.2;
    } else {
        type1=1;
        type2=1;
    }
    blood1=1;
    blood2=1;
    printf("�԰��}�l\n\n");
    while(first_atk_hp > 0 && second_atk_hp > 0) {
        int atk;
        if(turn == 1) {
            atk =(int) (first_atk_atk * type1 * blood1 - second_atk_def);
            second_atk_hp -= atk;
            if(second_atk_hp < second_atk_origin_hp/2) {
                blood2=1.2;
            }
            printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", first_atk, second_atk, atk);
            turn = 2; //�洫������
        } else {
            atk =(int) (second_atk_atk * type2 * blood2 - first_atk_def);
            first_atk_hp -= atk;
            if(first_atk_hp < first_atk_origin_hp/2) {
                blood1=1.2;
            }
            printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", second_atk, first_atk, atk);
            turn = 1; //�洫������
        }
        printf("����%d HP: %d  ����%d HP: %d\n\n", first_atk, first_atk_hp, second_atk, second_atk_hp);
    }
    printf("����%d ���h�԰���O\n", (first_atk_hp > 0) ? second_atk : first_atk);
    printf("�԰�����\n\n");
    printf("����%d ���\n\n", (first_atk_hp > 0) ? first_atk : second_atk);


}







