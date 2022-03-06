#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

int main()
{
    //變數依序為：1.屬性 2.血量 3.攻擊 4.防禦 5.角色強度    
    //角色強度使用float來紀錄小數點
    //角色強度公式：( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5

    //角色1 
    char char1_type = 'F';
    int char1_hp  = 45;
    int char1_atk = 20;
    int char1_def = 5;
    float char1_combat = (char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5 - 50) * 6.5; 

    //角色2 
    char char2_type = 'G';
    int char2_hp  = 50;
    int char2_atk = 15;
    int char2_def = 5;
    float char2_combat = (char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5 - 50) * 6.5;

    //角色3
    char char3_type = 'W';
    int char3_hp  = 45;
    int char3_atk = 15;
    int char3_def = 10;
    float char3_combat = (char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5 - 50) * 6.5;

    //注意不要搞混血量和攻擊的變數順序

    printf("角色1\n"
           "名稱：離散\n"
           "屬性：%c     攻擊：%d\n"
           "血量：%d    防禦：%d\n", char1_type, char1_atk, char1_hp, char1_def);

    printf("角色強度預測：%.2f\n\n", char1_combat);

    printf("角色2\n"
           "名稱：離散\n"
           "屬性：%c     攻擊：%d\n"
           "血量：%d    防禦：%d\n", char2_type, char2_atk, char2_hp, char2_def);

    printf("角色強度預測：%.2f\n\n", char2_combat);

    printf("角色3\n"
           "名稱：資結\n"
           "屬性：%c     攻擊：%d\n"
           "血量：%d    防禦：%d\n", char3_type, char3_atk, char3_hp, char3_def);

    printf("角色強度預測：%.2f\n\n", char3_combat);

    //新增角色
    //變數依序為：1.角色強度 2.屬性 3.血量 4.攻擊 5.防禦 6.先攻角色 7.後攻角色 8.確認是否新增角色

    float charN_combat; 
    char charN_type;
    int charN_hp;
    int charN_atk;
    int charN_def;
    int firstattack;
    int nextattack;
    int check;

    printf("是否新增角色(1.Yes/2.No)？");
    scanf("%d", &check);

  
    //數據限制：
    //屬性：F = 火、W = 水、G = 土、A = 風。不可輸入F、W、G、A、f、w、g、a以外的英文字母。
    //血量：40~50的整數
    //攻擊：15~20的整數
    //防禦：5~10的整數
    //三者總和在65~70之間

    //選擇新增角色
    if(check==1)
    {
        //輸入角色數值
        printf("\n新增角色\n"
               "屬性：");
        getchar();                  //使用 getchar 吃掉剛剛Enter下來的字元
        scanf("%c", &charN_type);
        printf("血量：");
        scanf("%d", &charN_hp);
        printf("攻擊：");
        scanf("%d", &charN_atk);
        printf("防禦：");
        scanf("%d", &charN_def);
        
        //小寫轉大寫
        if (islower(charN_type))
            charN_type = toupper(charN_type);

        //屬性不存在
        if (!(charN_type == 'F' || charN_type == 'W' || charN_type == 'G' || charN_type == 'A'))
        {
            printf("錯誤：無此屬性\n");
        }

        //數據範圍錯誤
        if (!(charN_hp >= 40 && charN_hp <= 50 && charN_atk >= 15 && charN_atk <= 20 && charN_def >= 5 &&
            charN_def <= 10 && charN_hp + charN_atk + charN_def >= 65 && charN_hp + charN_atk + charN_def <= 70))
        {
            printf("錯誤：能力數值在限制範圍之外\n");
        }

        //符合設定的範圍
        if ((charN_type == 'F' || charN_type == 'W' || charN_type == 'G' || charN_type == 'A') &&
            charN_hp >= 40 && charN_hp <= 50 && charN_atk >= 15 && charN_atk <= 20 && charN_def >= 5 &&
            charN_def <= 10 && charN_hp + charN_atk + charN_def >= 65 && charN_hp + charN_atk + charN_def <= 70)
        {
            printf("\n角色4\n"
                   "名稱：自訂角色\n"
                   "屬性：%c     攻擊：%d\n"
                   "血量：%d    防禦：%d\n", charN_type, charN_atk, charN_hp, charN_def);

            charN_combat = (charN_hp * 1.0 + charN_atk * 0.8 + charN_def * 0.5 - 50) * 6.5;

            printf("角色強度預測：%.2f\n", charN_combat);

            printf("\n選擇先攻角色：");
            scanf("%d", &firstattack);

            //確認角色是否存在
            if (firstattack > 4)
            {
                printf("無此角色\n");
                return 0;
            }

            printf("選擇後攻角色：");
            scanf("%d", &nextattack);

            if (nextattack > 4)
            {
                printf("無此角色\n");
                return 0;
            }

            //確認是否重複選取
            if (nextattack == firstattack)
            {
                printf("錯誤：不可重複選取\n");
                return 0;
            }

            printf("\n先攻角色為%d，後攻角色為%d\n", firstattack, nextattack);

        }

        //不符合新增角色條件 結束程式

        else 
            return 0;

    }

    //選擇不新增角色
    else if (check == 2)

    {

        printf("\n選擇先攻角色：");
        scanf("%d", &firstattack);

        //確認角色是否存在
        if (firstattack > 3)
        {
            printf("無此角色\n");
            return 0;
        }

        printf("選擇後攻角色：");
        scanf("%d", &nextattack);

        if (nextattack > 3)
        {
            printf("無此角色\n");
            return 0;
        }

        //確認是否重複選取
        if (nextattack == firstattack)
        {
            printf("錯誤：不可重複選取\n");
            return 0;
        }

        printf("\n先攻角色為%d，後攻角色為%d\n", firstattack, nextattack);

    }

    //新增角色欄位輸入錯誤
    else
        printf("輸入錯誤\n");

    return 0;
}

