#include<stdio.h>
int main() {
    //����1
    char char1_type = 'F';
    int char1_hp = 48;
    int char1_atk = 16;
    int char1_def = 6;
    //����2
    char char2_type = 'G';
    int char2_hp = 41;
    int char2_atk = 19;
    int char2_def = 9;
    //����3
    char char3_type = 'A';
    int char3_hp = 50;
    int char3_atk = 14;
    int char3_def = 4;
    //�ۭq����
    char char4_type ;
    int char4_hp ;
    int char4_atk;
    int char4_def ;

    float va1=((char1_hp*1.0)+(char1_atk*0.8)+(char1_def*0.5)-50)*6.5;//�j�׹w����k
    float va2=((char2_hp*1.0)+(char2_atk*0.8)+(char2_def*0.5)-50)*6.5;//�j�׹w����k
    float va3=((char3_hp*1.0)+(char3_atk*0.8)+(char3_def*0.5)-50)*6.5;//�j�׹w����k

    printf("����1\n�W��:���O��\n�ݩ�:%c\t\t��q:%d\n�����O:%d\t���m�O%d\n�j�׹w��:%.2f\n\n",char1_type,char1_hp,char1_atk,char1_def,va1);
    printf("����2\n�W��:�����N\n�ݩ�:%c\t\t��q:%d\n�����O:%d\t���m�O%d\n�j�׹w��:%.2f\n\n",char2_type,char2_hp,char2_atk,char2_def,va2);
    printf("����3\n�W��:�_�դ��\n�ݩ�:%c\t\t��q:%d\n�����O:%d\t���m�O%d\n�j�׹w��:%.2f\n\n",char3_type,char3_hp,char3_atk,char3_def,va3);
    //printf("����1\n�W��:���O��\n�ݩ�:F\t\t��q:48\n�����O:16\t���m�O6\n\n");//�`�M70
    //printf("����2\n�W��:�����N\n�ݩ�:G\t\t��q:41\n�����O:19\t���m�O9\n\n");//�`�M69
    //printf("����3\n�W��:�_�դ��\n�ݩ�:A\t\t��q:50\n�����O:14\t���m�O4\n\n");//�`�M68

    printf("�s�W����\n");
    printf("�ݩ�:");
    scanf("%c",&char4_type);
    printf("��q:");
    scanf("%d",&char4_hp);
    printf("�����O:");
    scanf("%d",&char4_atk);
    printf("���m�O:");
    scanf("%d",&char4_def);

    float va4=((char4_hp*1.0)+(char4_atk*0.8)+(char4_def*0.5)-50)*6.5;//�j�׹w����k
    printf("\n����4\n����W��:�ۭq����\n�ݩ�:%c\t\t��q:%d\n�����O:%d\t���m�O:%d\n�j�׹w��:%.2f\n\n",char4_type,char4_hp,char4_atk,char4_def,va4);

    return 0;
}
