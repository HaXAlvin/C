#include<stdio.h>

int main()
{
    char char1_name[21] = "阿吉";
    char char2_name[21] = "卡維";
    char char3_name[21] = "小樹";
    char char4_name[21];

    char type[4] = {'F', 'W', 'W'};//屬性
    int hp[4] = {43, 46, 45, 0};//血量
    int atk[4] = {19, 15, 17, 0};//攻擊
    int def[4] = {7, 8, 6, 0};//防禦


    int choice;//選擇(0~3)
    int NewChar = 0;//判斷是否已新增角色0為否，1為是
    //用while迴圈先印出選擇菜單，然後輸入，輸入 < 0 或 > 3 則輸出"輸入錯誤"
    while (printf("1. 新增或修改新增角色\n2. 顯示所有角色資料\n3. 戰鬥\n0. 結束遊戲\n請選擇: ")&&scanf("%d", &choice))
    {
        if (choice < 0 || choice > 3)
        {
            printf("\n輸入錯誤!\n\n");
            continue;
        }
        if (choice == 0)//結束遊戲
        {
            printf("\n結束遊戲\n");
            break;
        }
        else if (choice == 1)
        {
            int error_type = 0, error_val = 0;//error_type 紀錄屬性是否錯誤, error_val 紀錄能力數值是否錯誤 0-> 正確, 1-> 錯誤

            do { //用do while迴圈 先輸入角色資訊後判斷是否輸入錯誤
                if (NewChar == 0)
                    printf("\n新增角色\n");
                else if (NewChar == 1)
                    printf("\n修改新增角色\n");
                getchar();
                printf("名稱 : ");
                gets(char4_name);
                printf("屬性 : ");
                scanf("%c", &type[3]);
                printf("血量 : ");
                scanf("%d", &hp[3]);
                printf("攻擊 : ");
                scanf("%d", &atk[3]);
                printf("防禦 : ");
                scanf("%d", &def[3]);
                int sum = atk[3] + hp[3] + def[3];
                if (type[3] == 102 || type[3] == 119 || type[3] == 103 || type[3] == 97)//用ASCII code 將小寫轉成大寫
                    type[3] = type[3] - 32;
                //先判斷屬性
                if (type[3] != 'F' && type[3] != 'W' && type[3] != 'G' && type[3] != 'A')
                {
                    printf("錯誤:無此屬性\n");
                    error_type = 1;
                    //判斷屬性錯誤後接著判斷能力數值與其總和
                    if (atk[3] < 15 || atk[3] > 20 || hp[3] < 40 || hp[3] > 50 || def[3] < 5 || def[3] > 10)
                    {
                        printf("錯誤:能力數值在限制範圍之外\n");
                        error_val = 1;
                    }
                    else if (sum < 65 || sum > 70)
                    {
                        printf("錯誤:能力數值在限制範圍之外\n");
                        error_val = 1;
                    }
                    continue;
                }
                //屬性無誤接著判斷能力數值與其總和
                if (atk[3] < 15 || atk[3] > 20 || hp[3] < 40 || hp[3] > 50 || def[3] < 5 || def[3] > 10)
                {
                    printf("錯誤:能力數值在限制範圍之外\n");
                    error_val = 1;
                }
                else if (sum < 65 || sum > 70)
                {
                    printf("錯誤:能力數值在限制範圍之外\n");
                    error_val = 1;
                }
                else
                {
                    error_type = 0, error_val = 0;//輸入皆正確將error歸零
                    float predict = (hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5 - 50) * 6.5;
                    printf("\n角色4\n名稱: %s\n屬性: %c      攻擊: %d\n", char4_name, type[3], atk[3]);
                    printf("血量: %d     防禦: %d\n", hp[3], def[3]);
                    printf("強度預測: %.2f\n\n", predict);
                    NewChar = 1;
                }
            }while (error_type == 1 || error_val == 1);
        }
        else if (choice == 2)
        {
            //角色1
            float predict_char1 = (hp[0] * 1.0 + atk[0] * 0.8 + def[0] * 0.5 - 50) * 6.5;
            printf("\n角色1\n名稱: %s\n屬性: %c      攻擊: %d\n", char1_name, type[0], atk[0]);
            printf("血量: %d     防禦: %d\n", hp[0], def[0]);
            printf("強度預測: %.2f\n", predict_char1);
            //角色2
            float predict_char2 = (hp[1] * 1.0 + atk[1] * 0.8 + def[1] * 0.5 - 50) * 6.5;
            printf("\n角色2\n名稱: %s\n屬性: %c      攻擊: %d\n", char2_name, type[1], atk[1]);
            printf("血量: %d     防禦: %d\n", hp[1], def[1]);
            printf("強度預測: %.2f\n", predict_char2);
            //角色3
            float predict_char3 = (hp[2] * 1.0 + atk[2] * 0.8 + def[2] * 0.5 - 50) * 6.5;
            printf("\n角色3\n名稱: %s\n屬性: %c      攻擊: %d\n", char3_name, type[2], atk[2]);
            printf("血量: %d     防禦: %d\n", hp[2], def[2]);
            printf("強度預測: %.2f\n\n", predict_char3);
            //角色4(若NewChar為1則輸出)
            if (NewChar == 1)
            {
                float predict_char4 = (hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5 - 50) * 6.5;
                printf("\n角色4\n名稱: %s\n屬性: %c      攻擊: %d\n", char4_name, type[3], atk[3]);
                printf("血量: %d     防禦: %d\n", hp[3], def[3]);
                printf("強度預測: %.2f\n\n", predict_char4);
            }
        }
        else if (choice == 3)
        {
            int FirstAtk, SecondAtk;//先攻,後攻
            int error_first, error_second, error;//先攻角色錯誤,後攻角色錯誤,重複選取
            do{
                printf("選擇先攻角色:");//決定先攻角色
                scanf(" %d", &FirstAtk);
                if (NewChar == 0)//沒有角色4
                {
                    if (FirstAtk != 1 && FirstAtk != 2 && FirstAtk != 3)
                    {
                        printf("錯誤:無此角色\n");
                        error_first = 1;//先攻角色錯誤
                    }
                    else
                        error_first = 0;
                }
                else if (NewChar == 1)//有角色4
                {
                    if (FirstAtk != 1 && FirstAtk != 2 && FirstAtk != 3 && FirstAtk != 4)
                    {
                        printf("錯誤:無此角色\n");
                        error_first = 1;//先攻角色錯誤
                    }
                    else
                        error_first = 0;//輸入無誤將error_first歸零
                }
                else
                    error_first = 0;//輸入無誤將error_first歸零
            }while(error_first == 1);
            do{
                printf("選擇後攻角色:");//決定後攻角色
                scanf(" %d", &SecondAtk);
                if (NewChar == 0)//沒有角色4
                {
                    if (SecondAtk != 1 && SecondAtk != 2 && SecondAtk != 3)
                    {
                        printf("錯誤:無此角色\n");
                        error_second = 1;//後攻角色錯誤
                    }
                    else
                        error_second = 0;
                }
                else if (NewChar == 1)//有角色4
                {
                    if (SecondAtk != 1 && SecondAtk != 2 && SecondAtk != 3 && SecondAtk != 4)
                    {
                        printf("錯誤:無此角色\n");
                        error_second = 1;//後攻角色錯誤
                    }
                    else
                        error_second = 0;
                }
                else if (FirstAtk == SecondAtk)//重複選取同一個角色
                {
                    printf("錯誤:不可重複選取\n");
                    error = 1;//角色重複選取
                }
                else
                {
                    error_second = 0;//輸入無誤將error_second歸零
                    error = 0;//沒有重複將error歸零
                }
            }while(error_second == 1 || error == 1);
            printf("\n先攻為角色%d、後攻為角色%d\n", FirstAtk, SecondAtk);
            printf("戰鬥開始\n");
            //先攻角色資料
            char FirstAtk_type;
            int FirstAtk_hp, FirstAtk_atk, FirstAtk_def;
            //後攻角色資料
            char SecondAtk_type;
            int SecondAtk_hp, SecondAtk_atk, SecondAtk_def;
            //將先攻角色資料取出
            if (FirstAtk == 1)
                FirstAtk_type = type[0], FirstAtk_hp = hp[0], FirstAtk_atk = atk[0], FirstAtk_def = def[0];
            else if (FirstAtk == 2)
                FirstAtk_type = type[1], FirstAtk_hp = hp[1], FirstAtk_atk = atk[1], FirstAtk_def = def[1];
            else if (FirstAtk == 3)
                FirstAtk_type = type[2], FirstAtk_hp = hp[2], FirstAtk_atk = atk[2], FirstAtk_def = def[2];
            else if (FirstAtk == 4)
                FirstAtk_type = type[3], FirstAtk_hp = hp[3], FirstAtk_atk = atk[3], FirstAtk_def = def[3];
            //將後攻角色資料取出
            if (SecondAtk == 1)
                SecondAtk_type = type[0], SecondAtk_hp = hp[0], SecondAtk_atk = atk[0], SecondAtk_def = def[0];
            else if (SecondAtk == 2)
                SecondAtk_type = type[1], SecondAtk_hp = hp[1], SecondAtk_atk = atk[1], SecondAtk_def = def[1];
            else if (SecondAtk == 3)
                SecondAtk_type = type[2], SecondAtk_hp = hp[2], SecondAtk_atk = atk[2], SecondAtk_def = def[2];
            else if (SecondAtk == 4)
                SecondAtk_type = type[3], SecondAtk_hp = hp[3], SecondAtk_atk = atk[3], SecondAtk_def = def[3];
            ("%d %d\n", FirstAtk_hp, SecondAtk_hp);
            float FirstAtk_type_val, SecondAtk_type_val;//屬性相剋倍率
            float first_low_hp = 1.0, second_low_hp = 1.0;//殘血倍率
            //屬性相剋倍率
            if (FirstAtk_type == 'W' && SecondAtk_type == 'F')//W > F
                FirstAtk_type_val = 1.2, SecondAtk_type_val = 0.8;
            else if (FirstAtk_type == 'F' && SecondAtk_type == 'A')// F > A
                FirstAtk_type_val = 1.2, SecondAtk_type_val = 0.8;
            else if (FirstAtk_type == 'A' && SecondAtk_type == 'G')// A > G
                FirstAtk_type_val = 1.2, SecondAtk_type_val = 0.8;
            else if (FirstAtk_type == 'G' && SecondAtk_type == 'W')// G > W
                FirstAtk_type_val = 1.2, SecondAtk_type_val = 0.8;
            else
                FirstAtk_type_val = 1.0, SecondAtk_type_val = 1.0;
            //printf("%d\n", FirstAtk_hp);
            int FirstAtk_dam, SecondAtk_dam;
                int first_initial_hp = FirstAtk_hp;
                int second_initial_hp = SecondAtk_hp;
            for (int i = 1; i != 0; i++)//利用for迴圈執行戰鬥
            {
                //先攻回合
                FirstAtk_dam = (int)(FirstAtk_atk * FirstAtk_type_val * first_low_hp - SecondAtk_def);
                printf("\n角色%d 對角色%d 發動攻擊，造成 %d 點傷害\n", FirstAtk, SecondAtk, FirstAtk_dam);
                SecondAtk_hp -= FirstAtk_dam;//被攻擊方剩餘血量
                printf("角色%d HP: %d  角色%d HP: %d\n", FirstAtk, FirstAtk_hp, SecondAtk, SecondAtk_hp);
                if (FirstAtk_hp <= 0 || SecondAtk_hp <= 0)//判斷先攻與後攻是否有一方血量低於0
                {
                    i = -1;//有中一方血量低於0則將i變成-1 經過i++變為0 跳出迴圈
                    continue;//若if判斷式成立則不執行下面的敘述句
                }

                if (SecondAtk_hp < second_initial_hp / 2)
                    second_low_hp = 1.2;
                //後攻回合
                SecondAtk_dam = (int)(SecondAtk_atk * SecondAtk_type_val * second_low_hp - FirstAtk_def);
                printf("\n角色%d 對角色%d 發動攻擊，造成 %d 點傷害\n", SecondAtk, FirstAtk, SecondAtk_dam);
                FirstAtk_hp -= SecondAtk_dam;//被攻擊方剩餘血量
                printf("角色%d HP: %d  角色%d HP: %d\n", FirstAtk, FirstAtk_hp, SecondAtk, SecondAtk_hp);
                if (FirstAtk_hp <= 0 || SecondAtk_hp <= 0)//判斷先攻與後攻是否有一方血量低於0
                {
                    i = -1;//有中一方血量低於0則將i變成-1 經過i++變為0 跳出迴圈
                }
                if (FirstAtk_hp < first_initial_hp / 2)
                    first_low_hp = 1.2;
            }
            if (FirstAtk_hp <= 0)
                printf("\n角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n\n", FirstAtk, SecondAtk);
            else if (SecondAtk_hp <= 0)
                printf("\n角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n\n", SecondAtk, FirstAtk);
        }
    }
    return 0;
}
