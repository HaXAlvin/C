#include <stdio.h>
#include <stdlib.h>
char type[4]="FWG";
int hp[4]= {46,45,43,0};
int attack[4]= {17,16,19,0};
int defense[4]= {7,8,6,0};

char name[4][100]= {"����","����","���A"};

char ch4_type;
int ch4_hp;
int ch4_attack;
int ch4_defense;

int first_atk;
int first_type;
int first_atk_hp;
int first_atk_atk;
int first_atk_def;

int second_atk;
int second_type;
int second_atk_hp;
int second_atk_atk;
int second_atk_def;

int choose;
int blood1;
int blood2;
int char4_is_create=0;

void PrintCharData(char name[],int hp,int attack,int defense,char type) {
    printf("\n�W�١G%s\n",name);
    printf("�ݩʡG%c     �����G%d\n", type, attack);
    printf("��q�G%d    ���m�G%d\n", hp, defense);
    printf("����j�׹w���G%.2f\n\n",
           (hp * 1.0 + attack * 0.8 + defense * 0.5 - 50.0) * 6.5 );
    return ;
}
void EditNewChar() {
    while(1) {

        printf("\n�s�W����\n");
        printf("�W��:");
        scanf("%s",name[3]);
        printf("�ݩʡG");
        scanf("%*c%c", &type[3]);
        printf("��q�G");
        scanf("%d", &hp[3]);
        printf("�����G");
        scanf("%d", &attack[3]);
        printf("���m�G\n");
        scanf("%d", &defense[3]);
        if(type[3] != 'F' && type[3] != 'W' && type[3] != 'G' && type[3] != 'A' &&
                type[3] != 'f' && type[3] != 'w' && type[3] != 'g' && type[3] != 'a') {
            printf("���~�G�L���ݩ�\n");
            continue;
            char4_is_create=0;
        }//�ݩʭ���
        else if(type[3] >= 'a')
            type[3] -= 32;

        int ch4_sum = hp[3] + attack[3] + defense[3];
        if(hp[3] < 40 || hp[3] > 50 || attack[3] < 15 || attack[3] > 20 ||
                defense[3] < 5 || defense[3] > 10 || ch4_sum < 65 || ch4_sum > 70) {
            printf("���~�G��O�ƭȦb����d�򤧥~\n");
            continue;
        }
        break;
    }//�ƭȭ���
}
void SelectAndBattle() {
    while(1) { //������
        printf("��ܥ��𨤦�G");
        scanf("%d", &first_atk);
        if(first_atk!=1&&first_atk!=2&&first_atk!=3&&first_atk!=4 ) {
            printf("���~�G�L������\n");
            continue;
        }
        break;
    }
    while(1) { //�����
        printf("��ܫ�𨤦�G");
        scanf("%d", &second_atk);
        if(second_atk!=1&&second_atk!=2&&second_atk!=3&&second_atk!=4) {
            printf("���~�G�L������\n");
            continue;
        } else if(second_atk == first_atk) {
            printf("���~�G���i���ƿ��\n");
            continue;
        }
        break;
    }
    printf("\n���𬰨���%d�B��𬰨���%d\n", first_atk, second_atk);

    if (first_atk == 1) { //���𬰨���1
        first_type = type[0];
        first_atk_hp = hp[0] ;
        first_atk_atk = attack[0] ;
        first_atk_def = defense[0];
    }

    if (first_atk == 2) { //���𬰨���2
        first_type = type[1];
        first_atk_hp = hp[1] ;
        first_atk_atk = attack[1] ;
        first_atk_def = defense[1];
    }

    if (first_atk == 3) { //���𬰨���3
        first_type = type[2];
        first_atk_hp = hp[2] ;
        first_atk_atk = attack[2] ;
        first_atk_def = defense[2];
    }

    if (first_atk == 4) { //���𬰨���4
        first_type = type[3];
        first_atk_hp = hp[3] ;
        first_atk_atk = attack[3] ;
        first_atk_def = defense[3];
    }

    if (second_atk == 1) { //��𬰨���1
        second_type = type[0];
        second_atk_hp = hp[0] ;
        second_atk_atk = attack[0] ;
        second_atk_def = defense[0];
    }

    if (second_atk == 2) { //��𬰨���2
        second_type = type[1];
        second_atk_hp = hp[1] ;
        second_atk_atk = attack[1] ;
        second_atk_def = defense[1];
    }

    if (second_atk == 3) { //��𬰨���3
        second_type = type[2];
        second_atk_hp = hp[2] ;
        second_atk_atk = attack[2] ;
        second_atk_def = defense[2];
    }

    if (second_atk == 4) { //��𬰨���4
        second_type = type[3];
        second_atk_hp = hp[3] ;
        second_atk_atk = attack[3] ;
        second_atk_def = defense[3];
    }
    //�ݩʧJ��
    if(first_type=='W'&&second_type=='F') {
        first_atk_atk*1.2;
        second_atk_atk*0.8;
    }
    if(first_type=='F'&&second_type=='A') {
        first_atk_atk*1.2;
        second_atk_atk*0.8;
    }
    if(first_type=='A'&&second_type=='G') {
        first_atk_atk*1.2;
        second_atk_atk*0.8;
    }
    if(first_type=='G'&&second_type=='W') {
        first_atk_atk*1.2;
        second_atk_atk*0.8;
    }
    if(first_type=='F'&&second_type=='W') {
        first_atk_atk*0.8;
        second_atk_atk*1.2;
    }
    if(first_type=='A'&&second_type=='F') {
        first_atk_atk*0.8;
        second_atk_atk*1.2;
    }
    if(first_type=='G'&&second_type=='A') {
        first_atk_atk*0.8;
        second_atk_atk*1.2;
    }
    if(first_type=='W'&&second_type=='G') {
        first_atk_atk*0.8;
        second_atk_atk*1.2;
    }
    Battling();

}
void Battling() {
    printf("�԰��}�l\n\n");
    while(1) {
        blood1=first_atk_hp/2;
        blood2=second_atk_hp/2;
        if(second_atk_hp<blood2)
            first_atk_atk*1.2;
        if(first_atk_hp<blood1)
            second_atk_atk*1.2;
        //�ݦ孿�v
        printf("����%d �� ����%d �o�ʧ����A�y�� %d �ˮ`\n", first_atk, second_atk, first_atk_atk - second_atk_def);
        second_atk_hp = second_atk_hp - (first_atk_atk - second_atk_def);
        printf("����%d HP: %d  ����%d HP: %d\n\n", first_atk, first_atk_hp, second_atk, second_atk_hp);
        if(second_atk_hp<=0) {
            printf("����%d ���h�԰���O", second_atk);
            printf("�԰�����\n\n");
            printf("����%d ���\n", first_atk);
            break;
        }
        printf("����%d �� ����%d �o�ʧ����A�y�� %d �ˮ`\n", second_atk, first_atk, second_atk_atk - first_atk_def);
        first_atk_hp = first_atk_hp - (second_atk_atk - first_atk_def);
        printf("����%d HP: %d  ����%d HP: %d\n\n", first_atk, first_atk_hp, second_atk, second_atk_hp);
        if(first_atk_hp<=0) {
            printf("����%d ���h�԰���O", first_atk);
            printf("�԰�����\n\n");
            printf("����%d ���\n", second_atk);
            break;
        }
        continue;
    }
}



int main() {

    while(1) {
        printf("1.�s�W�έק﨤����\n");
        printf("2.��ܩҦ�������\n");
        printf("3.�԰�\n");
        printf("0.�����C��\n");
        printf("�п��:");
        scanf("%d",&choose);
        if(choose==0)//�����C���ﶵ
            return 0;

        if(choose==2) { //��ܩҦ�������
            for(int i = 0; i < 3 + char4_is_create; i++) {
                printf("����%d",i+1);
                PrintCharData(name[i],hp[i],attack[i],defense[i],type[i]);
            }
        }
        if(choose==1) { //�s�W�έק�s�W������
            EditNewChar();
            char4_is_create=1;
            printf("����4");
            PrintCharData(name[3],hp[3],attack[3],defense[3],type[3]);
        }
        if(choose==3) { //�԰�
            SelectAndBattle();
        }
    }
}
