#include <stdio.h>

int main()
{
    //����1
    char char1_type = 'F';
    int char1_atk = 19;
    int char1_hp = 43;
    int char1_def = 7;
    float char1_str = (char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;
    printf("����1\n�W��:���N\n�ݩ�:%c      ����:%d\n", char1_type, char1_atk);
    printf("��q:%d     ���m:%d\n", char1_hp, char1_def);
    printf("�j�׹w��:%.2f\n\n", char1_str);
    //����2
    char char2_type = 'W';
    int char2_atk = 15;
    int char2_hp = 46;
    int char2_def = 8;
    float char2_str = (char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
    printf("����2\n�W��:�d��\n�ݩ�:%c      ����:%d\n", char2_type, char2_atk);
    printf("��q:%d     ���m:%d\n", char2_hp, char2_def);
    printf("�j�׹w��:%.2f\n\n", char2_str);
    //����3
    char char3_type = 'W';
    int char3_atk = 17;
    int char3_hp = 45;
    int char3_def = 6;
    float char3_str = (char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
    printf("����3\n�W��:�p��\n�ݩ�:%c      ����:%d\n", char3_type, char3_atk);
    printf("��q:%d     ���m:%d\n", char3_hp, char3_def);
    printf("�j�׹w��:%.2f\n\n", char3_str);
    //����4
    char char4_type;
    int char4_atk;
    int char4_hp;
    int char4_def;
    printf("�s�W����\n�ݩ�:");
    scanf("%c", &char4_type);
    printf("����:");
    scanf("%d", &char4_atk);
    printf("��q:");
    scanf("%d", &char4_hp);
    printf("���m:");
    scanf("%d", &char4_def);
    float char4_str = (char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;
    //����4
    printf("\n����4\n�W��:�۸�\n�ݩ�:%c      ����:%d\n", char4_type, char4_atk);
    printf("��q:%d     ���m:%d\n", char4_hp, char4_def);
    printf("�j�׹w��:%.2f\n\n", char4_str);
    /*printf("����1\n�W��:���N\n�ݩ�:F      ����:19\n��q:43     ���m:7\n\n"
           "����2\n�W��:�d��\n�ݩ�:W      ����:15\n��q:46     ���m:8\n\n"
           "����3\n�W��:�p��\n�ݩ�:A      ����:17\n��q:45     ���m:6\n");*/
    return 0;
}
