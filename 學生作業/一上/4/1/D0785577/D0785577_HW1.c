#include<stdio.h>
#include<stdlib.h>

int main()
{
    //角色1
    char char1_type = 'F';
    int char1_hp  = 45;
    int char1_atk = 20;
    int char1_def = 5;
    float char1_combat = (char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5 - 50) * 6.5; //角色強度
    //角色2
    char char2_type = 'G';
    int char2_hp  = 50;
    int char2_atk = 15;
    int char2_def = 5;
    float char2_combat = (char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5 - 50) * 6.5; //角色強度
    //角色3
    char char3_type = 'W';
    int char3_hp  = 45;
    int char3_atk = 15;
    int char3_def = 10;
    float char3_combat = (char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5 - 50) * 6.5; //角色強度

    printf("角色1\n"
           "名稱：離散\n"
           "屬性：%c      攻擊：%d\n"
           "血量：%d     防禦：%d\n"
           "\n", char1_type, char1_atk, char1_hp, char1_def);

    printf("角色強度預測：%.2f\n\n", char1_combat);

    printf("角色2\n"
           "名稱：離散\n"
           "屬性：%c      攻擊：%d\n"
           "血量：%d     防禦：%d\n"
           "\n", char2_type, char2_atk, char2_hp, char2_def);

    printf("角色強度預測：%.2f\n\n", char2_combat);

    printf("角色3\n"
           "名稱：資結\n"
           "屬性：%c      攻擊：%d\n"
           "血量：%d     防禦：%d\n"
           "\n", char3_type, char3_atk, char3_hp, char3_def);

    printf("角色強度預測：%.2f\n\n", char3_combat);

    //新增角色
    char charN_type;
    int charN_hp;
    int charN_atk;
    int charN_def;
    float charN_combat; //角色強度

    printf("新增角色\n"
           "屬性：");

    scanf("%c", &charN_type);

    printf("血量：");

    scanf("%d", &charN_hp);

    printf("攻擊：");

    scanf("%d", &charN_atk);

    printf("防禦：");

    scanf("%d", &charN_def);

    printf("\n"
           "角色4\n"
           "自訂角色\n"
           "屬性：%c      攻擊：%d\n"
           "血量：%d     防禦：%d\n"
           "\n", charN_type, charN_atk, charN_hp, charN_def);

    charN_combat = (charN_hp * 1.0 + charN_atk * 0.8 + charN_def * 0.5 - 50) * 6.5;

    printf("角色強度預測：%.2f\n\n", charN_combat);

    return 0;
}

