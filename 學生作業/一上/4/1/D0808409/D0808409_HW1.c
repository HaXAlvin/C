#include<stdio.h>
#include<stdlib.h>
#include <wchar.h>
int main(){
    //����1
    char char1_name[] = "Momi";
    char char1_type = 'W';
    int char1_hp = 50;
    int char1_atk = 15;
    int char1_def = 7;
    //����2
    char char2_name[] = "Kirito";
    char char2_type = 'F';
    int char2_hp = 48;
    int char2_atk = 16;
    int char2_def = 8;
    //����3
    char char3_name[] = "Miku";
    char char3_type = 'G';
    int char3_hp = 46;
    int char3_atk = 17;
    int char3_def = 9;
    //����4
    char char4_name[] = "Chaos";
    char char4_type = 'G';
    int char4_hp = 46;
    int char4_atk = 17;
    int char4_def = 9;
    //��J��X
    Print(1,char1_name,char1_type,char1_hp,char1_atk,char1_def);
    Print(2,char2_name,char2_type,char2_hp,char2_atk,char2_def);
    Print(3,char3_name,char3_type,char3_hp,char3_atk,char3_def);
    printf("�s�W����\n");
    printf("�ݩʡG");
    scanf("%c",&char4_type);
    printf("��q�G");
    scanf("%d",&char4_hp);
    printf("�����G");
    scanf("%d",&char4_atk);
    printf("���m�G");
    scanf("%d",&char4_def);
    printf("\n");
    Print(4,char4_name,char4_type,char4_hp,char4_atk,char4_def);
    return 0;
}
//�ۻs�U�ο�X���P
int Print(int Count,char name[] ,int type,int hp,int atk,int def)
{   printf("����%d\n�W�١G",Count);
    for(int x=0;x<strlen(name);x++)
    {
    printf("%c",name[x]);
    }
    printf("\n�ݩʡG%c     �����G%d\n��q�G%d    ���m�G%d\n",type,atk,hp,def);

    float Power  = ( hp * 1.0 + atk * 0.8 + def * 0.5 - 50 ) * 6.5;
    printf("����j�׹w���G%.2f\n\n",Power);
    return 0;
}

