#include <stdio.h>

int main(){
    char Char1_type='W',Char2_type='F',Char3_type='G',Char4_type;//�ݩ�
    int Char1_atk=15,Char2_atk=20,Char3_atk=15,Char4_atk;//����
    int Char1_hp=50,Char2_hp=40,Char3_hp=45,Char4_hp;//��q
    int Char1_def=5,Char2_def=5,Char3_def=10,Char4_def;//���m
    printf("����1 \n");
    printf("�W��:�ǥ��t \n");
    printf("�ݩ�:%c    ����:%d  \n",Char1_type,Char1_atk);
    printf("��q:%d   ���m:%d  \n",Char1_hp,Char1_def);
    printf("�j�׹w��:%.2f\n",( Char1_hp * 1.0 + Char1_atk * 0.8 + Char1_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
    printf("����2 \n");
    printf("�W��:�p���s \n");
    printf("�ݩ�:%c    ����:%d  \n",Char2_type,Char2_atk);
    printf("��q:%d   ���m:%d  \n",Char2_hp,Char2_def);
    printf("�j�׹w��:%.2f\n",( Char2_hp * 1.0 + Char2_atk * 0.8 + Char2_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
    printf("����3 \n");
    printf("�W��:�p���� \n");
    printf("�ݩ�:%c    ����:%d  \n",Char2_type,Char2_atk);
    printf("��q:%d   ���m:%d  \n",Char2_hp,Char2_def);
    printf("�j�׹w��:%.2f\n",( Char3_hp * 1.0 + Char3_atk * 0.8 + Char3_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
    printf("�s�W���� \n");
    printf("�ݩ�:");
    scanf("%c",&Char4_type);
    printf("��q:");
    scanf("%d",&Char4_hp);
    printf("����:");
    scanf("%d",&Char4_atk);
    printf("���m:");
    scanf("%d",&Char4_def);
    printf ("\n");
    printf("����4 \n");
    printf("�W��:�ۭq���� \n");
    printf("�ݩ�:%c    ����:%d  \n",Char4_type,Char4_atk);
    printf("��q:%d   ���m:%d  \n",Char4_hp,Char4_def);
    printf("�j�׹w��:%.2f\n",( Char4_hp * 1.0 + Char4_atk * 0.8 + Char4_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
    return 0;
}
