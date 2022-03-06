#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    //角色強度公式：( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5
    //變數依序為：1.屬性 2.血量 3.攻擊 4.防禦 5.角色強度
    //角色強度使用float來紀錄小數點

    //角色1
    char char1_type = 'F';
    int  char1_hp = 45;
    int  char1_atk = 20;
    int  char1_def = 5;
    float char1_combat = (char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5 - 50) * 6.5;

    //角色2
    char char2_type = 'G';
    int  char2_hp = 50;
    int  char2_atk = 15;
    int  char2_def = 5;
    float char2_combat = (char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5 - 50) * 6.5;

    //角色3
    char char3_type = 'W';
    int  char3_hp = 45;
    int  char3_atk = 15;
    int  char3_def = 10;
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
    //變數依序為：1.角色強度 2.屬性 3.血量 4.攻擊 5.防禦 6.先攻角色 7.後攻角色 8.迴圈控制 9.確認是否新增角色

    float charN_combat;
    char charN_type;
    int charN_hp;
    int charN_atk;
    int charN_def;
    int firstattack;
    int lastattack;
    int check;
    int create = 0;

    //確認是否新增角色
    while (create == 0)
    {
        create = 1;
        printf("是否新增角色(1.Yes/2.No)？");
        scanf("%d", &check);

        //新增角色欄位輸入錯誤 返回迴圈起點
        if (!(check == 1 || check == 2))
        {
            printf("輸入錯誤\n");
            create = 0;
        }
    }

    //數據限制：
    //屬性：F = 火、W = 水、G = 土、A = 風。不可輸入F、W、G、A、f、w、g、a以外的英文字母。
    //血量：40~50的整數
    //攻擊：15~20的整數
    //防禦：5~10的整數
    //三者總和在65~70之間

    //選擇新增角色 進入輸入數值迴圈
    while (check == 1)
    {
        check = 0;

        //輸入角色數值
        printf("\n新增角色\n"
               "屬性：");
        //getchar();                  //使用 getchar 吃掉剛剛Enter下來的字元
        scanf(" %c", &charN_type);
        printf("血量：");
        scanf("%d", &charN_hp);
        printf("攻擊：");
        scanf("%d", &charN_atk);
        printf("防禦：");
        scanf("%d", &charN_def);

        //小寫轉大寫
        if (islower(charN_type))
            charN_type = toupper(charN_type);

        //屬性不存在 返回輸入數值迴圈
        if (!(charN_type == 'F' || charN_type == 'W' || charN_type == 'G' || charN_type == 'A'))
        {
            printf("錯誤：無此屬性\n");
            check = 1;
        }

        //數據範圍錯誤 返回輸入數值迴圈
        if (!(charN_hp >= 40 && charN_hp <= 50 && charN_atk >= 15 && charN_atk <= 20 && charN_def >= 5 &&
            charN_def <= 10 && charN_hp + charN_atk + charN_def >= 65 && charN_hp + charN_atk + charN_def <= 70))
        {
            printf("錯誤：能力數值在限制範圍之外\n");
            check = 1;
        }
    }

    //符合設定的範圍
    if (check == 0 && (charN_type == 'F' || charN_type == 'W' || charN_type == 'G' || charN_type == 'A') &&
        charN_hp >= 40 && charN_hp <= 50 && charN_atk >= 15 && charN_atk <= 20 && charN_def >= 5 &&
        charN_def <= 10 && charN_hp + charN_atk + charN_def >= 65 && charN_hp + charN_atk + charN_def <= 70)
    {
        //印出新增角色的數值
        printf("\n角色4\n"
               "名稱：自訂角色\n"
               "屬性：%c     攻擊：%d\n"
               "血量：%d    防禦：%d\n", charN_type, charN_atk, charN_hp, charN_def);

        charN_combat = (charN_hp * 1.0 + charN_atk * 0.8 + charN_def * 0.5 - 50) * 6.5;

        printf("角色強度預測：%.2f\n\n", charN_combat);

        //選角迴圈
        while (check == 0)
        {
            check = 1;

            //選取先攻角色迴圈 若選取正確則check = 3
            while (check == 1)
            {
                check = 3;
                printf("選擇先攻角色：");
                scanf("%d", &firstattack);

                //若角色不存在 則返回選取先攻角色的迴圈
                if (firstattack > 4 || firstattack < 1)
                {
                    printf("無此角色\n");
                    check = 1;
                }
            }

            //選取後攻角色迴圈 check==3才會進入
            while (check == 3)
            {
                check = 1;
                printf("選擇後攻角色：");
                scanf("%d", &lastattack);

                //若角色不存在 則返回選取後攻角色的迴圈
                if (lastattack > 4 || lastattack < 1)
                {
                    printf("無此角色\n");
                    check = 3;
                }
            }

            //若重複選取 則返回選角迴圈
            if (lastattack == firstattack)
            {
                printf("錯誤：不可重複選取\n");
                check = 0;
            }
        }

        printf("\n先攻為角色%d，後攻為角色%d\n", firstattack, lastattack);
        check = 4;    //準備進入戰鬥
    }


    //選擇不新增角色
    if (check == 2)
    {
        printf("\n");  //排版用

        //選角迴圈
        while (check == 2)
        {
            check = 0;

            //選取先攻角色迴圈 若選取正確則check = 3
            while (check == 0)
            {
                check = 3;
                printf("選擇先攻角色：");
                scanf("%d", &firstattack);

                //若角色不存在 則返回選取先攻角色的迴圈
                if (firstattack > 3 || firstattack < 1)
                {
                    printf("無此角色\n");
                    check = 0;
                }
            }

            //選取後攻角色迴圈 check==3才會進入
            while (check == 3)
            {
                check = 0;
                printf("選擇後攻角色：");
                scanf("%d", &lastattack);

                //若角色不存在 則返回選取後攻角色的迴圈
                if (lastattack > 3 || lastattack < 1)
                {
                    printf("無此角色\n");
                    check = 3;
                }
            }

            //若重複選取 則返回選角迴圈
            if (lastattack == firstattack)
            {
                printf("錯誤：不可重複選取\n");
                check = 2;
            }
        }

        printf("\n先攻為角色%d，後攻為角色%d\n", firstattack, lastattack);
        check = 4;    //準備進入戰鬥
    }

    //宣告變數 先攻角色的數值 以及 後攻角色的數值
    char first_type;
    int  first_hp;
    int  first_atk;
    int  first_def;
    char last_type;
    int  last_hp;
    int  last_atk;
    int  last_def;

    //將剛剛選取的角色數值個別導入
    if (check == 4)
    {
        printf("戰鬥開始\n\n");

        if (firstattack == 1)
        {
            first_type = char1_type;
            first_hp   = char1_hp;
            first_atk  = char1_atk;
            first_def  = char1_def;
        }
        if (firstattack == 2)
        {
            first_type = char2_type;
            first_hp   = char2_hp;
            first_atk  = char2_atk;
            first_def  = char2_def;
        }
        if (firstattack == 3)
        {
            first_type = char3_type;
            first_hp   = char3_hp;
            first_atk  = char3_atk;
            first_def  = char3_def;
        }
        if (firstattack == 4)
        {
            first_type = charN_type;
            first_hp   = charN_hp;
            first_atk  = charN_atk;
            first_def  = charN_def;
        }
        if (lastattack == 1)
        {
            last_type = char1_type;
            last_hp   = char1_hp;
            last_atk  = char1_atk;
            last_def  = char1_def;
        }
        if (lastattack == 2)
        {
            last_type = char2_type;
            last_hp   = char2_hp;
            last_atk  = char2_atk;
            last_def  = char2_def;
        }
        if (lastattack == 3)
        {
            last_type = char3_type;
            last_hp   = char3_hp;
            last_atk  = char3_atk;
            last_def  = char3_def;
        }
        if (lastattack == 4)
        {
            last_type = charN_type;
            last_hp   = charN_hp;
            last_atk  = charN_atk;
            last_def  = charN_def;
        }

        check = 5; //進入戰鬥

    }

    if (check == 5)
    {
        //戰鬥迴圈 一回合各自攻擊一次 若先攻角色結束攻擊時 後攻角色血量低於0 則直接break出來
        while (first_hp > 0 && last_hp > 0)
        {
            last_hp = last_hp - (first_atk - last_def);
            printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n", firstattack, lastattack, first_atk - last_def);
            printf("角色%d HP: %d  角色%d HP: %d\n\n", firstattack, first_hp, lastattack, last_hp);

            if (last_hp <= 0)
            {
                break;
            }

            first_hp = first_hp - (last_atk - first_def);
            printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n", lastattack, firstattack, last_atk - first_def);
            printf("角色%d HP: %d  角色%d HP: %d\n\n", firstattack, first_hp, lastattack, last_hp);
        }
        //判定勝負
        if (first_hp <= 0)
        {
            printf("%d 失去戰鬥能力\n", firstattack);
            printf("戰鬥結束\n\n");
            printf("角色%d 勝利\n", lastattack);
        }
        //判定勝負
        if (last_hp <= 0)
        {
            printf("角色%d 失去戰鬥能力\n", lastattack);
            printf("戰鬥結束\n\n");
            printf("角色%d 勝利\n", firstattack);
        }
    }
    return 0;
}

