#include <stdio.h>

int main()
{
    //角色1
    char char1_type = 'F';
    int char1_atk = 19;
    int char1_hp = 43;
    int char1_def = 7;
    float char1_str = (char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;
    printf("角色1\n名稱: 阿吉\n屬性: %c      攻擊: %d\n", char1_type, char1_atk);
    printf("血量: %d     防禦: %d\n", char1_hp, char1_def);
    printf("強度預測: %.2f\n\n", char1_str);
    //角色2
    char char2_type = 'W';
    int char2_atk = 15;
    int char2_hp = 46;
    int char2_def = 8;
    float char2_str = (char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
    printf("角色2\n名稱: 卡維\n屬性: %c      攻擊: %d\n", char2_type, char2_atk);
    printf("血量: %d     防禦: %d\n", char2_hp, char2_def);
    printf("強度預測: %.2f\n\n", char2_str);
    //角色3
    char char3_type = 'W';
    int char3_atk = 17;
    int char3_hp = 45;
    int char3_def = 6;
    float char3_str = (char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
    printf("角色3\n名稱: 小樹\n屬性: %c      攻擊: %d\n", char3_type, char3_atk);
    printf("血量: %d     防禦: %d\n", char3_hp, char3_def);
    printf("強度預測: %.2f\n\n", char3_str);

    int reply;
    char char4_type;//屬性
    int char4_atk;//攻擊
    int char4_hp;//血量
    int char4_def;//防禦
    int fir, sec;//先攻,後攻
    printf("是否新增角色(1.Yes/2.No)? ");
    scanf(" %d", &reply);
    if (reply == 2)
    {
        printf("\n選擇先攻角色:");//決定先攻角色
        scanf(" %d", &fir);
        if (fir != 1 && fir != 2 && fir != 3)
        {
            printf("錯誤:無此角色");//非角色1~3
            return 0;
        }
        printf("選擇後攻角色:");//決定後攻角色
        scanf(" %d", &sec);
        if (sec != 1 && sec != 2 && sec != 3)//非角色1~3
        {
             printf("錯誤:無此角色");
            return 0;
        }
        if (fir == sec)//重複選取同一個角色
            printf("錯誤:不可重複選取");
        printf("\n先攻為角色%d、後攻為角色%d\n", fir, sec);
        return 0;
    }
    else if (reply == 1)//輸入新增角色數值
    {
        printf("\n新增角色\n屬性:");
        scanf(" %c", &char4_type);
        printf("攻擊:");
        scanf(" %d", &char4_atk);
        printf("血量:");
        scanf(" %d", &char4_hp);
        printf("防禦:");
        scanf(" %d", &char4_def);
        int char4_sum = char4_atk + char4_hp + char4_def;//攻擊,血量,防禦的總和
        if (char4_type == 'f')//f變成F
        {
            char4_type = 'F';
        }
        else if (char4_type == 'w')//w變成W
        {
            char4_type = 'W';
        }
        else if (char4_type == 'g')//g變成G
        {
            char4_type = 'G';
        }
        else if (char4_type == 'a')//a變成A
        {
            char4_type = 'A';
        }
        if (char4_type != 'F' && char4_type != 'W' && char4_type != 'G' && char4_type != 'A')//判斷屬性限制
        {
            printf("錯誤:無此屬性\n");
            if (char4_atk < 15 || char4_atk > 20 || char4_hp < 40 || char4_hp > 50 || char4_def < 5 || char4_def > 10)//判斷屬性錯誤後再判斷能力數值限制
            {
                printf("錯誤:能力數值在限制範圍之外\n");
            }
            else if (char4_sum < 65 || char4_sum > 70)//判斷屬性錯誤後再判斷三者總和是否超出範圍
            {
                printf("錯誤:能力數值在限制範圍之外\n");
            }
            return 0;
        }
        if (char4_atk < 15 || char4_atk > 20 || char4_hp < 40 || char4_hp > 50 || char4_def < 5 || char4_def > 10)//屬性無誤之後判斷能力數值限制
        {
            printf("錯誤:能力數值在限制範圍之外\n");
            return 0;
        }
        else if (char4_sum < 65 || char4_sum > 70)//屬性無誤之後判斷三者總和超出範圍
        {
            printf("錯誤:能力數值在限制範圍之外\n");
            return 0;
        }
        else //若屬性無誤且能力數值皆在範圍內則顯示角色4
        {
            float char4_str = (char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5; //角色4的強度預測值
            printf("\n角色4\n名稱: 誠誠\n屬性: %c      攻擊: %d\n", char4_type, char4_atk);
            printf("血量: %d     防禦: %d\n", char4_hp, char4_def);
            printf("強度預測: %.2f\n\n", char4_str);
        }
        printf("選擇先攻角色:");
        scanf(" %d", &fir);//決定先攻角色
        if (fir != 1 && fir != 2 && fir != 3 && fir != 4)//非角色1~4
        {
            printf("錯誤:無此角色\n");
            return 0;
        }
        printf("選擇後攻角色:");//決定後攻角色
        scanf(" %d", &sec);
        if (sec != 1 && sec != 2 && sec != 3 && sec != 4)//非角色1~4
        {
            printf("錯誤:無此角色\n");
            return 0;
        }
        if (fir == sec)//重複選取同一個角色
        {
            printf("錯誤:不可重複選取\n");
            return 0;
        }
        printf("\n先攻為角色%d、後攻為角色%d\n", fir, sec);//顯示先攻與後攻角色
    }
    else
    {
        printf("輸入錯誤!\n");//reply 非1&2
        return 0;
    }
    return 0;
}
