#include<stdio.h>
#include<stdlib.h>

int main()
{
    //����1
    char char1_type = 'F';
    int char1_hp  = 45;
    int char1_atk = 20;
    int char1_def = 5;
    float char1_combat = (char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5 - 50) * 6.5; //����j��
    //����2
    char char2_type = 'G';
    int char2_hp  = 50;
    int char2_atk = 15;
    int char2_def = 5;
    float char2_combat = (char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5 - 50) * 6.5; //����j��
    //����3
    char char3_type = 'W';
    int char3_hp  = 45;
    int char3_atk = 15;
    int char3_def = 10;
    float char3_combat = (char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5 - 50) * 6.5; //����j��

    printf("����1\n"
           "�W�١G����\n"
           "�ݩʡG%c      �����G%d\n"
           "��q�G%d     ���m�G%d\n"
           "\n", char1_type, char1_atk, char1_hp, char1_def);

    printf("����j�׹w���G%.2f\n\n", char1_combat);

    printf("����2\n"
           "�W�١G����\n"
           "�ݩʡG%c      �����G%d\n"
           "��q�G%d     ���m�G%d\n"
           "\n", char2_type, char2_atk, char2_hp, char2_def);

    printf("����j�׹w���G%.2f\n\n", char2_combat);

    printf("����3\n"
           "�W�١G�굲\n"
           "�ݩʡG%c      �����G%d\n"
           "��q�G%d     ���m�G%d\n"
           "\n", char3_type, char3_atk, char3_hp, char3_def);

    printf("����j�׹w���G%.2f\n\n", char3_combat);

    //�s�W����
    char charN_type;
    int charN_hp;
    int charN_atk;
    int charN_def;
    float charN_combat; //����j��

    printf("�s�W����\n"
           "�ݩʡG");

    scanf("%c", &charN_type);

    printf("��q�G");

    scanf("%d", &charN_hp);

    printf("�����G");

    scanf("%d", &charN_atk);

    printf("���m�G");

    scanf("%d", &charN_def);

    printf("\n"
           "����4\n"
           "�ۭq����\n"
           "�ݩʡG%c      �����G%d\n"
           "��q�G%d     ���m�G%d\n"
           "\n", charN_type, charN_atk, charN_hp, charN_def);

    charN_combat = (charN_hp * 1.0 + charN_atk * 0.8 + charN_def * 0.5 - 50) * 6.5;

    printf("����j�׹w���G%.2f\n\n", charN_combat);

    return 0;
}

