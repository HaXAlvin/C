#include <stdio.h>

int main()
{
    //角色1
    char char1_type = 'F';
    int char1_atk = 19;
    int char1_hp = 43;
    int char1_def = 7;
    float char1_str = (char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;
    printf("角色1\n名稱:阿吉\n屬性:%c      攻擊:%d\n", char1_type, char1_atk);
    printf("血量:%d     防禦:%d\n", char1_hp, char1_def);
    printf("強度預測:%.2f\n\n", char1_str);
    //角色2
    char char2_type = 'W';
    int char2_atk = 15;
    int char2_hp = 46;
    int char2_def = 8;
    float char2_str = (char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
    printf("角色2\n名稱:卡維\n屬性:%c      攻擊:%d\n", char2_type, char2_atk);
    printf("血量:%d     防禦:%d\n", char2_hp, char2_def);
    printf("強度預測:%.2f\n\n", char2_str);
    //角色3
    char char3_type = 'W';
    int char3_atk = 17;
    int char3_hp = 45;
    int char3_def = 6;
    float char3_str = (char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
    printf("角色3\n名稱:小樹\n屬性:%c      攻擊:%d\n", char3_type, char3_atk);
    printf("血量:%d     防禦:%d\n", char3_hp, char3_def);
    printf("強度預測:%.2f\n\n", char3_str);
    //角色4
    char char4_type;
    int char4_atk;
    int char4_hp;
    int char4_def;
    printf("新增角色\n屬性:");
    scanf("%c", &char4_type);
    printf("攻擊:");
    scanf("%d", &char4_atk);
    printf("血量:");
    scanf("%d", &char4_hp);
    printf("防禦:");
    scanf("%d", &char4_def);
    float char4_str = (char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;
    //角色4
    printf("\n角色4\n名稱:誠誠\n屬性:%c      攻擊:%d\n", char4_type, char4_atk);
    printf("血量:%d     防禦:%d\n", char4_hp, char4_def);
    printf("強度預測:%.2f\n\n", char4_str);
    /*printf("角色1\n名稱:阿吉\n屬性:F      攻擊:19\n血量:43     防禦:7\n\n"
           "角色2\n名稱:卡維\n屬性:W      攻擊:15\n血量:46     防禦:8\n\n"
           "角色3\n名稱:小樹\n屬性:A      攻擊:17\n血量:45     防禦:6\n");*/
    return 0;
}
