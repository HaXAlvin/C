#include <stdio.h>
#include <stdlib.h>

char type[4]={'F','G','A'};
int hp[4]={45,45,50};
int atk[4]={17,15,15};
int def[4]={8,10,5};
char char4_name[20];

int first_atk;//�q�w���𨤦��ܼ�
int first_atk_origin_hp;
int first_atk_hp;
int first_atk_atk;
int first_atk_def;
char first_atk_type;

int second_atk;//�q�w��𨤦��ܼ�
int second_atk_origin_hp;
int second_atk_hp;
int second_atk_atk;
int second_atk_def;
char second_atk_type;

int char4_is_create=0;
int char4_is_delete=0;
int is_correct, turn;
int chs;


void EditNewChar(){
    do{
        is_correct = 1;//��l��flag
        printf("\n");
        if(char4_is_delete == 1)//�p�G�w�g����L�s�W���⪺��ơA�L�X�ק�s�W����
            printf("�ק�s�W����\n");
        else
            printf("�s�W����\n");
        char4_is_create = 1;
        printf("�W�١G");
        scanf("%*c%s",&char4_name);
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
           type[3] != 'f' && type[3] != 'w' && type[3] != 'g' && type[3] != 'a'){
            printf("���~�G�L���ݩ�\n");
            is_correct = 0;
        }
        else if(type[3] >= 'a')
            type[3] -= 32;
        //�ˬd��O�ƭ�
        int char4_sum = hp[3] + atk[3] + def[3];
        if(hp[3] < 40 || hp[3] > 50 || atk[3] < 15 || atk[3] > 20 ||
            def[3] < 5 || def[3] > 10 || char4_sum < 65 || char4_sum > 70){
                printf("���~�G��O�ƭȦb����d�򤧥~\n");
                is_correct = 0;
        }
    }while(!is_correct);

    printf("\n����4\n�W�١G%s\n",char4_name);
    printf("�ݩʡG%c     �����G%d\n", type[3],atk[3]);
    printf("��q�G%d    ���m�G%d\n", hp[3],def[3]);
    printf("����j�׹w���G%.2f\n\n", (hp[3]*1.0+atk[3]*0.8+def[3]*0.5-50)*6.5);
}
void PrintCharData(){
    printf("\n����1\n");
    printf("�W��:����\n");
    printf("�ݩ�:%c     ����:%d\n",type[0],atk[0]);
    printf("��q:%d    ���m:%d\n",hp[0],def[0]);
    printf("����j�׹w��:%.2f\n\n",(hp[0]*1.0+atk[0]*0.8+def[0]*0.5-50)*6.5);

    printf("����2\n");
    printf("�W��:����\n");
    printf("�ݩ�:%c     ����:%d\n",type[1],atk[1]);
    printf("��q:%d    ���m:%d\n",hp[1],def[1]);
    printf("����j�׹w��:%.2f\n\n",(hp[1]*1.0+atk[1]*0.8+def[1]*0.5-50)*6.5);

    printf("����3\n");
    printf("�W��:�ڵ�\n");
    printf("�ݩ�:%c     ����:%d\n",type[2],atk[2]);
    printf("��q:%d    ���m:%d\n",hp[2],def[2]);
    printf("����j�׹w��:%.2f\n\n",(hp[2]*1.0+atk[2]*0.8+def[2]*0.5-50)*6.5);

    if(char4_is_create == 1){
        printf("����4\n�W�١G%s\n",char4_name);
        printf("�ݩʡG%c     �����G%d\n", type[3],atk[3]);
        printf("��q�G%d    ���m�G%d\n", hp[3],def[3]);
        printf("����j�׹w���G%.2f\n\n", (hp[3]*1.0+atk[3]*0.8+def[3]*0.5-50)*6.5);
    }
}
void SelectAndBattle(){
    printf("\n");
    do{
        is_correct = 1; //��l��flag
        printf("��ܥ��𨤦�G");
        scanf("%d", &first_atk);
        if(first_atk < 1 || first_atk > 3 + char4_is_create){
            printf("���~�G�L������\n");
            is_correct = 0;
        }
    }while(!is_correct);
    do{
        is_correct = 1; //��l��flag
        printf("��ܫ�𨤦�G");
        scanf("%d", &second_atk);
        if(second_atk < 1 || second_atk > 3 + char4_is_create){
            printf("���~�G�L������\n");
            is_correct = 0;
        }
        else if(second_atk == first_atk){
            printf("���~�G���i���ƿ��\n");
            is_correct = 0;
        }
    }while(!is_correct);
    if(is_correct=1)
        Battling();
}
void Battling(){
    printf("\n���𬰨���%d�B��𬰨���%d\n", first_atk, second_atk);
    //�N���𪺯�O��ƨ��X
    first_atk_type = (first_atk == 1) ? type[0] : (first_atk == 2) ? type[1] : (first_atk == 3) ? type[2] : type[3];
    first_atk_hp = (first_atk == 1) ? hp[0] : (first_atk == 2) ? hp[1] : (first_atk == 3) ? hp[2] : hp[3];
    first_atk_atk = (first_atk == 1) ? atk[0] : (first_atk == 2) ? atk[1] : (first_atk == 3) ? atk[2] : atk[3];
    first_atk_def = (first_atk == 1) ? def[0] : (first_atk == 2) ? def[1] : (first_atk == 3) ? def[2] : def[3];
    //�N��𪺯�O��ƨ��X
    second_atk_type = (second_atk == 1) ? type[0] : (second_atk == 2) ? type[1] : (second_atk == 3) ? type[2] : type[3];
    second_atk_hp = (second_atk == 1) ? hp[0] : (second_atk == 2) ? hp[1] : (second_atk == 3) ? hp[2] : hp[3];
    second_atk_atk = (second_atk == 1) ? atk[0] : (second_atk == 2) ? atk[1] : (second_atk == 3) ? atk[2] : atk[3];
    second_atk_def = (second_atk == 1) ? def[0] : (second_atk == 2) ? def[1] : (second_atk == 3) ? def[2] : def[3];

    turn = 1; //��l�Ƨ�����
    first_atk_origin_hp = first_atk_hp;
    second_atk_origin_hp = second_atk_hp;

    printf("�԰��}�l\n\n");
        //W>F>A>G>W �۫g���v
        int count1,count2=0;
        if(first_atk_type =='W')
            count1=4;
        if(first_atk_type =='F')
            count1=3;
        if(first_atk_type =='A')
            count1=2;
        if(first_atk_type =='G')
            count1=1;
        if(second_atk_type =='W')
            count2=4;
        if(second_atk_type =='F')
            count2=3;
        if(second_atk_type =='A')
            count2=2;
        if(second_atk_type =='G')
            count2=1;

        if(count1==1&&count2==4){
            count1=4;
            count2=1;
        }
        else if(count1==4&&count2==1){
            count1=1;
            count2=4;
        }
        if(count1>count2){
            first_atk_atk*=1.2;
            second_atk_atk*=0.8;
        }
        else if(count1<count2){
            first_atk_atk*=0.8;
            second_atk_atk*=1.2;
        }
    while(first_atk_hp > 0 && second_atk_hp > 0){
        int atk;
        if(turn == 1){
            if(first_atk_hp<first_atk_origin_hp*0.5){//�ݦ孿�v
                first_atk_atk*=1.2;
            }
            atk = first_atk_atk - second_atk_def;
            second_atk_hp -= atk;
            printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", first_atk, second_atk, atk);
            turn = 2;//�洫������
        }
        else{
            if(second_atk_hp<second_atk_origin_hp*0.5){//�ݦ孿�v
                second_atk*=1.2;
            }
            atk = second_atk_atk - first_atk_def;
            first_atk_hp -= atk;
            printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", second_atk, first_atk, atk);
            turn = 1;//�洫������
        }
        printf("����%d HP: %d  ����%d HP: %d\n\n", first_atk, first_atk_hp, second_atk, second_atk_hp);
    }
    printf("����%d ���h�԰���O\n", (first_atk_hp > 0) ? second_atk : first_atk);
    printf("�԰�����\n\n");
    printf("����%d ���\n", (first_atk_hp > 0) ? first_atk : second_atk);
    printf("\n");

    if(char4_is_create=1){
        char4_is_delete =1;//�p�G����4���Q��L��ơA�N�[ 1
    }
    char4_is_create =0;
}

int main(){
    do{
        printf("1. �s�W�έק�s�W����\n"
               "2. ��ܩҦ�������\n"
               "3. �԰�\n"
               "0. �����C��\n"
               "�п�ܡG");
        scanf("%d",&chs);
        switch(chs){
            case 1:
                EditNewChar();break;
            case 2:
                PrintCharData();break;
            case 3:
                SelectAndBattle();break;
            case 0:
                printf("\n�����C��\n");break;
            default :
                printf("\n��J���~!\n\n");break;
        }
        if(chs==0)
            break;
    }while(1);
    return 0;
}
