#include <stdio.h>
#include <stdlib.h>

int main()
{
    char char1_type = 'F';
    int char1_hp = 40;
    int char1_atk = 15;
    int char1_def = 10;
    char char2_type = 'W';
    int char2_hp = 45;
    int char2_atk = 20;
    int char2_def = 5;
    char char3_type = 'A';
    int char3_hp = 40;
    int char3_atk = 20;
    int char3_def = 10;
    char char0_type;
    int char0_hp,char0_atk,char0_def ;

    printf("����1\n�W�١GSKY\n�ݩ�\�G%c     ����\�G%d\n��q\�G%d    ���m\�G%d\n����j�׹w���G%.2f\n\n"
           ,char1_type,char1_atk,char1_hp,char1_def,(char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5);
    printf("����2\n�W�١GSUN\n�ݩ�\�G%c     ����\�G%d\n��q\�G%d    ���m\�G%d\n����j�׹w���G%.2f\n\n"
           ,char2_type,char2_atk,char2_hp,char2_def,(char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5);
    printf("����3\n�W�١GDUST\n�ݩ�\�G%c     ����\�G%d\n��q\�G%d    ���m\�G%d\n����j�׹w���G%.2f\n\n"
           ,char3_type,char3_atk,char3_hp,char3_def,(char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5);

    printf("��J�ݩ�:");
    scanf("%c",&char0_type);
    printf("��J����:");
    scanf("%d",&char0_atk);
    printf("��J��q:");
    scanf("%d",&char0_hp);
    printf("��J���m:");
    scanf("%d",&char0_def);
    printf("\n");
    printf("����4\n�W�١G�ۭq����\n�ݩ�\�G%c     ����\�G%d\n��q\�G%d    ���m\�G%d\n����j�׹w���G%.2f\n\n"
           ,char0_type,char0_atk,char0_hp,char0_def,(char0_hp*1.0+char0_atk*0.8+char0_def*0.5-50)*6.5);


    return 0;
}

