#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch1_type= 'F';
    int ch1_hp=46;
    int ch1_attack=17;
    int ch1_defense=7;

    printf("����@\n");
    printf("����W��:����\n");
    printf("�ݩ�:%c    ",ch1_type);
    printf("����:%d\n",ch1_attack);
    printf("��q:%d   ",ch1_hp);
    printf("���m:%d\n",ch1_defense);
    printf("����w���j��:%.2f\n\n",((ch1_hp*1)+(ch1_attack*0.8)+(ch1_defense*0.5)-50)*6.5);
    printf("\n");

    char ch2_type= 'W';
    int ch2_hp=45;
    int ch2_attack=16;
    int ch2_defense=8;

    printf("����G\n");
    printf("����W��:����\n");
    printf("�ݩ�:%c    ",ch2_type);
    printf("����:%d\n",ch2_attack);
    printf("��q:%d   ",ch2_hp);
    printf("���m:%d\n",ch2_defense);
    printf("����w���j��:%.2f\n\n",((ch2_hp*1)+(ch2_attack*0.8)+(ch2_defense*0.5)-50)*6.5);
    printf("\n");

    char ch3_type= 'G';
    int ch3_hp=43;
    int ch3_attack=19;
    int ch3_defense=6;

    printf("����T\n");
    printf("����W��:���A\n");
    printf("�ݩ�:%c    ",ch3_type);
    printf("����:%d\n",ch3_attack);
    printf("��q:%d   ",ch3_hp);
    printf("���m:%d\n",ch3_defense);
    printf("����w���j��:%.2f\n\n",((ch3_hp*1)+(ch3_attack*0.8)+(ch3_defense*0.5)-50)*6.5);
    printf("\n");

    char ch4_type;
    printf("�s�W����\n");
    printf("�ݩ�:");
    scanf("%c", &ch4_type);
    int ch4_hp, ch4_attack, ch4_defense;
    printf("����:");
    scanf("%d", &ch4_attack);
    printf("��q:");
    scanf("%d", &ch4_hp);
    printf("���m:");
    scanf("%d", &ch4_defense);
    printf("\n");
    printf("����|\n");
    printf("�W��:����\n");
    printf("�ݩ�:%c    ",ch4_type);
    printf("����:%d\n", ch4_attack);
    printf("��q:%d    ", ch4_hp);
    printf("���m:%d\n", ch4_defense);
    printf("����w���j��:%.2f\n\n",((ch4_hp*1)+(ch4_attack*0.8)+(ch4_defense*0.5)-50)*6.5);


    return 0;
}
