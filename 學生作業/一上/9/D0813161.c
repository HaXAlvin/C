#include<stdio.h>//���Y��
#include<stdlib.h>
//���Y��


char type[4]= {'F','W','G'}; //�ݩ�
int hp[4]= {42,48,45,0}; //��q
int atk[4]= {19,16,16,0}; //����
int def[4]= {5,5,7,0}; //���m
char char_n[][21]= {"���`���l","�ڪ���","����"};
int inputchar=0;

int is_correct,turn;

float bloodatk=1.2;
float first_restraintatk;
float second_restraintatk;

int first_atk, second_atk;

int first_atk_origin_hp;
int first_atk_type;
int first_atk_hp;
int first_atk_atk;
int first_atk_def;

int second_atk_origin_hp;
int second_atk_type;
int second_atk_hp;
int second_atk_atk;
int second_atk_def;
int choice=6;
char F,G,W,A,f,g,w,a;

int printf_player(int num) {
    printf("\n�W��:%s\n",char_n[num]);
    printf( "�ݩ�:%c  ����:%d\n",type[num],atk[num]);
    printf("��q:%d   ���m:%d\n",hp[num],def[num]);
    printf("����j�׹w��:%.2f\n\n",(atk[num]*0.8+hp[num]*1.0+def[num]*0.5-50)*6.5);//�j�׹w�� =( ��q * 1.0 + ���� * 0.8 + ���m * 0.5 - 50 ) * 6.5
}
int editnewchar(int num) {
    do {
        if( inputchar==1) {
            printf("�ק�s�W����\n");//�L�X�s�W����
        } else {
            printf("�s�W����\n");//�L�X�s�W����
        }
        printf("�W��:");
        scanf("%s",&char_n[3]);
        getchar();
        printf("�ݩ�:");//�L�X�ݩ�
        scanf(" %c",&type[3]);
        printf("��q:");//�L�X��q
        scanf("%d",&hp[3]);
        printf("����:");//�L�X����
        scanf("%d",&atk[3]);
        printf("���m:");//�L�X���m
        scanf("%d",&def[3]);
        printf("\n");
        if(type[3]!='F'&&type[3]!='G'&&type[3]!='A'&&type[3]!='W'&&type[3]!='f'&&type[3]!='a'&&type[3]!='w'&&type[3]!='g')
            printf("���~:�L���ݩ�\n");//�˹��ݩ�
        if((atk[3]+hp[3]+def[3]<50)||(atk[3]+hp[3]+def[3]>70)||(atk[3]>20)||(atk[3]<15)||(hp[3]>50)||(hp[3]<40)||(def[3]<5)||(def[3]>10))
            printf("���~:��O�ƭȦb����d�򤧥~\n");//�ˬd��O�ƭ�
        if(type[3]=='f')//if char4_type����f,�ର�j�g
            type[3]='F';
        if(type[3]=='a')//if char4_type����a,�ର�j�g
            type[3]='A';
        if(type[3]=='g')//if char4_type����g,�ର�j�g
            type[3]='G';
        if(type[3]=='w')//if char4_type����w,�ର�j�g
            type[3]='W';
    } while((atk[3]+hp[3]+def[3]<50)||(atk[3]+hp[3]+def[3]>70)||(atk[3]>20)||(atk[3]<15)||(hp[3]>50)||(hp[3]<40)||(def[3]<5)||(def[3]>10)
            ||type[3]!='F'&&type[3]!='G'&&type[3]!='A'&&type[3]!='W'&&type[3]!='f'&&type[3]!='a'&&type[3]!='w'&&type[3]!='g');


    printf("����4\n"//�L�X����4
           "�W��:%s\n"
           "�ݩ�:%c\t����:%d\n"
           "��q:%d\t���m:%d\n\n",char_n[3],type[3],atk[3],hp[3],def[3]);
    printf("����j�׹w��:%.2f\n\n",(atk[3]*0.8+hp[3]*1.0+def[3]*0.5-50)*6.5);//�j�׹w�� =( ��q * 1.0 + ���� * 0.8 + ���m * 0.5 - 50 ) * 6.5
    inputchar=1;
}

int SelectAndBattle(int first_atk,int second_atk) {
    do {
        is_correct = 1; //��l��flag
        printf("��ܥ��𨤦�G");
        scanf("%d", &first_atk);
        if(first_atk < 1 || first_atk > 3 + inputchar) {
            printf("���~�G�L������\n");
            is_correct = 0;
        }
    } while(!is_correct);
    do {
        is_correct = 1; //��l��flag
        printf("��ܫ�𨤦�G");
        scanf("%d", &second_atk);
        if(second_atk < 1 || second_atk > 3 + inputchar) {
            printf("���~�G�L������\n");
            is_correct = 0;
        } else if(second_atk == first_atk) {
            printf("���~�G���i���ƿ��\n");
            is_correct = 0;
        }
    } while(!is_correct);
    printf("\n���𬰨���%d�B��𬰨���%d\n", first_atk, second_atk);

    //�N���𪺯�O��ƨ��X
    first_atk_hp = (first_atk == 1) ? hp[0] : (first_atk == 2) ? hp[1] : (first_atk == 3) ? hp[2] : hp[3];
    first_atk_atk = (first_atk == 1) ? atk[0] : (first_atk == 2) ? atk[1] : (first_atk == 3) ?atk[2] : atk[3];
    first_atk_def = (first_atk == 1) ? def[0] : (first_atk == 2) ? def[1] : (first_atk == 3) ? def[2] : def[3];
    first_atk_type = (first_atk == 1) ? type[0] : (first_atk == 2) ? type[1] : (first_atk == 3) ? type[2] : type[3];
    //�N��𪺯�O��ƨ��X
    second_atk_hp = (second_atk == 1) ? hp[0] : (second_atk == 2) ? hp[1] : (second_atk == 3) ? hp[2] : hp[3];
    second_atk_atk = (second_atk == 1) ? atk[0] : (second_atk == 2) ? atk[1] : (second_atk == 3) ? atk[2] : atk[3];
    second_atk_def = (second_atk == 1) ? def[0] : (second_atk == 2) ? def[1] : (second_atk == 3) ? def[2] : def[3];
    second_atk_type = (second_atk == 1) ? type[0] : (second_atk == 2) ? type[1] : (second_atk == 3) ? type[2] : type[3];

    Battling( first_atk, second_atk);

}
int Battling(int first_atk,int second_atk) {
    turn = 1; //��l�Ƨ�����
    first_atk_origin_hp = first_atk_hp;
    second_atk_origin_hp = second_atk_hp;

    printf("�԰��}�l\n\n");

    if((first_atk_type=='W')&&(second_atk_type=='F')) {
        first_restraintatk=1.2;
        second_restraintatk=0.8;

    }
    if((first_atk_type=='W')&&(second_atk_type=='A')) {
        first_restraintatk=1;
        second_restraintatk=1;

    }
    if((first_atk_type=='W')&&(second_atk_type=='G')) {
        first_restraintatk=0.8;
        second_restraintatk=1.2;
    }
    if((first_atk_type=='F')&&(second_atk_type=='A')) {
        first_restraintatk=1.2;
        second_restraintatk=0.8;
    }
    if((first_atk_type=='F')&&(second_atk_type=='G')) {
        first_restraintatk=1;
        second_restraintatk=1;
    }
    if((first_atk_type=='F')&&(second_atk_type=='W')) {
        first_restraintatk=0.8;
        second_restraintatk=1.2;
    }
    if((first_atk_type=='A')&&(second_atk_type=='G')) {
        first_restraintatk=1.2;
        second_restraintatk=0.8;
    }
    if((first_atk_type=='A')&&(second_atk_type=='W')) {
        first_restraintatk=1;
        second_restraintatk=1;
    }
    if((first_atk_type=='A')&&(second_atk_type=='F')) {
        first_restraintatk=0.8;
        second_restraintatk=1.2;
    }
    if((first_atk_type=='G')&&(second_atk_type=='W')) {
        first_restraintatk=1.2;
        second_restraintatk=0.8;
    }
    if((first_atk_type=='G')&&(second_atk_type=='F')) {
        first_restraintatk=1;
        second_restraintatk=1;
    }
    if((first_atk_type=='G')&&(second_atk_type=='A')) {
        first_restraintatk=0.8;
        second_restraintatk=1.2;
    }
    if((first_atk_type=='W')&&(second_atk_type=='W')) {
        first_restraintatk=1;
        second_restraintatk=1;
    }
    if((first_atk_type=='A')&&(second_atk_type=='A')) {
        first_restraintatk=1;
        second_restraintatk=1;
    }
    if((first_atk_type=='G')&&(second_atk_type=='G')) {
        first_restraintatk=1;
        second_restraintatk=1;
    }
    if((first_atk_type=='F')&&(second_atk_type=='F')) {
        first_restraintatk=1;
        second_restraintatk=1;
    }
    while(first_atk_hp >=0 && second_atk_hp >= 0) {
        int atk;
        if(turn == 1) {
            atk = first_atk_atk*first_restraintatk - second_atk_def;
            if(first_atk_hp <  first_atk_origin_hp/2) {
                atk= (first_atk_atk*bloodatk*first_restraintatk) - second_atk_def;
            }
            second_atk_hp -=atk;
            printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", first_atk, second_atk, atk);
            turn = 2; //�洫������
        }

        else {
            atk = second_atk_atk*second_restraintatk - first_atk_def;
            if(second_atk_hp <  second_atk_origin_hp/2) {
                atk= (second_atk_atk*bloodatk*second_restraintatk) - first_atk_def;
            }
            first_atk_hp -=atk;
            printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", second_atk, first_atk, atk);
            turn = 1; //�洫������
        }
        printf("����%d HP: %d  ����%d HP: %d\n\n", first_atk, first_atk_hp, second_atk, second_atk_hp);
    }
    printf("����%d ���h�԰���O\n", (first_atk_hp > 0) ? second_atk : first_atk);
    printf("�԰�����\n\n");
    printf("����%d ���\n", (first_atk_hp > 0) ? first_atk : second_atk);
}

int main() { //�D�禡
    while(choice!=0) {
        printf("1. �s�W�έק�s�W����\n"
               "2. ��ܩҦ�������\n"
               "3. �԰�\n"
               "0. �����C��\n"
               "�п��:");
        scanf("%d",&choice);
        printf("\n");
        if(choice<0||choice>3) {
            printf("��J���~!\n\n");
        }
        if(choice==1) {
            editnewchar(3);
        }
        if(choice==2) {
            int i;
            for(i=0; i<3+inputchar; i++) {
                printf("����%d\n",i+1);
                printf_player(i);
            }
        }
        if(choice==3) {
            SelectAndBattle(first_atk,second_atk);
        }
    }
    printf("\n");
    printf("�����C��\n");
    return 0;
}
