#include<stdio.h>
#include<stdlib.h>
#include <wchar.h>
int main() {
    int chara_Total=3;
    //����1
    char char1_name[] = "Momi";
    char char1_type = 'W';
    int char1_hp = 45;
    int char1_atk = 15;
    int char1_def = 7;
    //����2
    char char2_name[] = "Kirito";
    char char2_type = 'F';
    int char2_hp = 44;
    int char2_atk = 16;
    int char2_def = 8;
    //����3
    char char3_name[] = "Miku";
    char char3_type = 'G';
    int char3_hp = 43;
    int char3_atk = 17;
    int char3_def = 9;
    //����4
    char char4_name[] = "�ۭq����";
    char char4_type = 'G';
    int char4_hp = 46;
    int char4_atk = 17;
    int char4_def = 9;
    //��J��X
    Print(1,char1_name,char1_type,char1_hp,char1_atk,char1_def);
    puts("");//����
    Print(2,char2_name,char2_type,char2_hp,char2_atk,char2_def);
    puts("");
    Print(3,char3_name,char3_type,char3_hp,char3_atk,char3_def);
    puts("");
    printf("�O�_�s�W����(1.Yes/2.No)?");
    int YN;//�s�xyes or no
    scanf("%d",&YN);
    if(RanInt(YN,1,2)==1) { //�ۻsfunction�P�_�d��O�_�W�X
        printf("��J���~");
        return 0;
    }
    if(YN==1) {
        chara_Total++;
        getchar();
        printf("\n�s�W����\n");
        printf("�ݩʡG");
        scanf("%c",&char4_type);
        printf("��q�G");
        scanf("%d",&char4_hp);
        printf("�����G");
        scanf("%d",&char4_atk);
        printf("���m�G");
        scanf("%d",&char4_def);
        int Total  = char4_hp + char4_atk + char4_def;
        switch(char4_type) { //�ݩʦr���P�_
        case 'F':
            break;
        case 'W':
            break;
        case 'G':
            break;
        case 'A':
            break;
        case 'f':
            break;
        case 'w':
            break;
        case 'g':
            break;
        case 'a':
            break;
        default:
            printf("���~�G�L���ݩ�\n");
            if(RanInt(char4_hp,40,50)==1)
                printf("���~�G��O�ƭȦb����d�򤧥~\n");
            else if(RanInt(char4_atk,15,20)==1)
                printf("���~�G��O�ƭȦb����d�򤧥~\n");
            else if(RanInt(char4_def,5,10)==1)
                printf("���~�G��O�ƭȦb����d�򤧥~\n");
            else if(RanInt(Total,65,70)==1)
                printf("���~�G��O�ƭȦb����d�򤧥~\n");
            return 0;
            break;
        }
        if(RanInt(char4_hp,40,50)==1) {
            printf("���~�G��O�ƭȦb����d�򤧥~\n");
            return 0;
        } else if(RanInt(char4_atk,15,20)==1) {
            printf("���~�G��O�ƭȦb����d�򤧥~\n");
            return 0;
        } else if(RanInt(char4_def,5,10)==1) {
            printf("���~�G��O�ƭȦb����d�򤧥~\n");
            return 0;
        } else if(RanInt(Total,65,70)==1) {
            printf("���~�G��O�ƭȦb����d�򤧥~\n");
            return 0;
        }
        puts("");
        Print(4,char4_name,char4_type,char4_hp,char4_atk,char4_def);
    }
    int AtkChara1;//�s�ϥΪ̿�J����𨤦��
    int AtkChara2;
    printf("\n��ܥ��𨤦�G");
    scanf("%d",&AtkChara1);
    if(RanInt(AtkChara1,1,chara_Total)==1) {
        printf("���~�G�L������\n");
        return 0;
    }
    printf("��ܫ�𨤦�G");
    scanf("%d",&AtkChara2);
    if(RanInt(AtkChara2,1,chara_Total)==1) {
        printf("�L������\n");
        return 0;
    }
    if(AtkChara1 == AtkChara2) {
        printf("���~�G���i���ƿ��\n");
        return 0;
    }
    printf("\n���𬰨���%d�B��𬰨���%d",AtkChara1,AtkChara2);
}
//�ۻs�U�ο�X���P
int Print(int Count,char name[],int type,int hp,int atk,int def) {
    printf("����%d\n�W�١G%s\n�ݩʡG%c     �����G%d\n��q�G%d    ���m�G%d\n",Count,name,type,atk,hp,def);
    float Power  = ( hp * 1.0 + atk * 0.8 + def * 0.5 - 50 ) * 6.5;
    printf("����j�׹w���G%.2f\n",Power);
    return 0;
}
int RanInt(int num,int min,int max) { //����Ʀr�b���w�d��
    if(num < min || num > max)
        return 1;
    else
        return 0;
}

