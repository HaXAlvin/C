#include <stdio.h>
int char1_atk;
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

    //printf("是否新增角色(1.Yes/2.No)? ");
    //scanf(" %d", &reply);
    while (printf("是否新增角色(1.Yes/2.No)? "), scanf("%d", &reply) && (reply != 1 && reply != 2))
    {
        printf("輸入錯誤!\n");//若非輸入1 or 2 則顯示輸入錯誤且重新輸入
    }
    if (reply == 2)
    {
        int error1, error2, error3;
        do{
            printf("\n選擇先攻角色:");//決定先攻角色
            scanf(" %d", &fir);
            if (fir != 1 && fir != 2 && fir != 3)
            {
                printf("錯誤:無此角色");//非角色1~3
                error1 = 1;//先攻角色錯誤
            }
            else
                error1 = 0;//輸入無誤將error1歸0
        }while (error1 == 1);
        do{
            printf("選擇後攻角色:");//決定後攻角色
            scanf(" %d", &sec);
            if (sec != 1 && sec != 2 && sec != 3)//非角色1~3
            {
                printf("錯誤:無此角色\n");
                error2 = 1;//後攻角色錯誤
            }
            else if (fir == sec)//重複選取同一個角色
            {
                printf("錯誤:不可重複選取\n");
                error3 = 1;//角色重複選取
            }
            else
            {
                error2 = 0;//輸入無誤將error2歸0
                error3 = 0;//沒有重複將error3歸0
            }
        }while (error2 == 1 || error3 == 1);
        printf("\n先攻為角色%d、後攻為角色%d\n", fir, sec);
        printf("戰鬥開始\n");
        int fir_atk, fir_hp, fir_def;//宣告先攻角色的資料
        switch (fir){//先攻角色
            case 1://將角色1的資料取出
                fir_atk = char1_atk;
                fir_hp = char1_hp;
                fir_def = char1_def;
                break;
            case 2://將角色2的資料取出
                fir_atk = char2_atk;
                fir_hp = char2_hp;
                fir_def = char2_def;
                break;
            case 3://將角色3的資料取出
                fir_atk = char3_atk;
                fir_hp = char3_hp;
                fir_def = char3_def;
                break;
        }
        int sec_atk, sec_hp, sec_def;//宣告後攻角色的資料
        switch (sec){//後攻角色
            case 1://將角色1的資料取出
                sec_atk = char1_atk;
                sec_hp = char1_hp;
                sec_def = char1_def;
                break;
            case 2://將角色2的資料取出
                sec_atk = char2_atk;
                sec_hp = char2_hp;
                sec_def = char2_def;
                break;
            case 3://將角色3的資料取出
                sec_atk = char3_atk;
                sec_hp = char3_hp;
                sec_def = char3_def;
                break;
        }
        for (int i = 1; i != 0; i++)//利用for迴圈執行戰鬥
        {
            //先攻回合
            printf("\n角色%d 對角色%d 發動攻擊，造成 %d 點傷害\n", fir, sec, fir_atk - sec_def);
            sec_hp = sec_hp - (fir_atk - sec_def);//被攻擊方剩餘血量
            printf("角色%d HP: %d  角色%d HP: %d\n", fir, fir_hp, sec, sec_hp);
            if (fir_hp <= 0 || sec_hp <= 0)//判斷先攻與後攻是否有一方血量低於0
            {
                i = -1;//有中一方血量低於0則將i變成-1 經過i++變為0 跳出迴圈
                continue;//若if判斷式成立則不執行下面的敘述句
            }
            printf("角色%d 對角色%d 發動攻擊，造成 %d 點傷害\n", sec, fir, sec_atk - fir_def);
            fir_hp = fir_hp - (sec_atk - fir_def);
            printf("角色%d HP: %d  角色%d HP: %d\n", fir, fir_hp, sec, sec_hp);
            if (fir_hp <= 0 || sec_hp <= 0)//判斷先攻與後攻是否有一方血量低於0
            {
                i = -1;//有中一方血量低於0則將i變成-1 經過i++變為0 跳出迴圈
            }
        }
        if (fir_hp <= 0)
            printf("\n角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n", fir, sec);
        else if (sec_hp <= 0)
            printf("\n角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n", sec, fir);
    }
    else if (reply == 1)//輸入新增角色數值
    {
        int error1, error2;//error1為屬性輸入錯誤, error2為能力超出範圍
        do {    //利用do while迴圈 先輸入角色資訊後判斷是否輸入錯誤
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
                error1 = 1;//屬性輸入錯誤
                if (char4_atk < 15 || char4_atk > 20 || char4_hp < 40 || char4_hp > 50 || char4_def < 5 || char4_def > 10)//判斷屬性錯誤後再判斷能力數值限制
                {
                    printf("錯誤:能力數值在限制範圍之外\n");
                    error2 = 1;//能力超出範圍
                }
                else if (char4_sum < 65 || char4_sum > 70)//判斷屬性錯誤後再判斷三者總和是否超出範圍
                {
                    printf("錯誤:能力數值在限制範圍之外\n");
                    error2 = 1;//能力超出範圍
                }
                continue;
            }
            if (char4_atk < 15 || char4_atk > 20 || char4_hp < 40 || char4_hp > 50 || char4_def < 5 || char4_def > 10)//屬性無誤之後判斷能力數值限制
            {
                printf("錯誤:能力數值在限制範圍之外\n");
                error2 = 1;//能力超出範圍
            }
            else if (char4_sum < 65 || char4_sum > 70)//屬性無誤之後判斷三者總和超出範圍
            {
                printf("錯誤:能力數值在限制範圍之外\n");
                error2 = 1;//能力超出範圍
            }
            else //若屬性無誤且能力數值皆在範圍內則顯示角色4
            {
                error1 = 0, error2 = 0;//若輸入皆正確則將error歸0
                float char4_str = (char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5; //角色4的強度預測值
                printf("\n角色4\n名稱: 誠誠\n屬性: %c      攻擊: %d\n", char4_type, char4_atk);
                printf("血量: %d     防禦: %d\n", char4_hp, char4_def);
                printf("強度預測: %.2f\n\n", char4_str);
            }
        }while (error1 == 1 || error2 == 1);
        int error3, error4, error5;
        do{
            printf("選擇先攻角色:");
            scanf(" %d", &fir);//決定先攻角色
            if (fir != 1 && fir != 2 && fir != 3 && fir != 4)//非角色1~4
            {
                printf("錯誤:無此角色\n");
                error3 = 1;//先攻角色錯誤
            }
            else
                error3 = 0;//先攻角色無誤將error3歸0
        }while (error3 == 1);
        do{
            printf("選擇後攻角色:");//決定後攻角色
            scanf(" %d", &sec);
            if (sec != 1 && sec != 2 && sec != 3 && sec != 4)//非角色1~4
            {
                printf("錯誤:無此角色\n");
                error4 = 1;//後攻角色錯誤
            }
            else if (fir == sec)//重複選取同一個角色
            {
                printf("錯誤:不可重複選取\n");
                error5 = 1;//重複選取
            }
            else
            {
                 error4 = 0;//後攻角色無誤將error4歸0
                 error5 = 0;//沒有重複選取將error5歸0
            }
        }while (error4 == 1 || error5 == 1);

        printf("\n先攻為角色%d、後攻為角色%d\n", fir, sec);//顯示先攻與後攻角色
        printf("戰鬥開始\n");
        int fir_atk, fir_hp, fir_def;//宣告先攻角色的資料
        switch (fir){//先攻角色
            case 1:
                fir_atk = char1_atk;
                fir_hp = char1_hp;
                fir_def = char1_def;
                break;
            case 2:
                fir_atk = char2_atk;
                fir_hp = char2_hp;
                fir_def = char2_def;
                break;
            case 3:
                fir_atk = char3_atk;
                fir_hp = char3_hp;
                fir_def = char3_def;
                break;
            case 4:
                fir_atk = char4_atk;
                fir_hp = char4_hp;
                fir_def = char4_def;
                break;
        }
        int sec_atk, sec_hp, sec_def;//宣告後攻角色的資料
        switch (sec){
            case 1:
                sec_atk = char1_atk;
                sec_hp = char1_hp;
                sec_def = char1_def;
                break;
            case 2:
                sec_atk = char2_atk;
                sec_hp = char2_hp;
                sec_def = char2_def;
                break;
            case 3:
                sec_atk = char3_atk;
                sec_hp = char3_hp;
                sec_def = char3_def;
                break;
            case 4:
                sec_atk = char4_atk;
                sec_hp = char4_hp;
                sec_def = char4_def;
                break;
        }
        for (int i = 1; i != 0; i++)//利用for迴圈執行戰鬥
        {
            //先攻回合
            printf("\n角色%d 對角色%d 發動攻擊，造成 %d 點傷害\n", fir, sec, fir_atk - sec_def);
            sec_hp = sec_hp - (fir_atk - sec_def);//被攻擊方剩餘血量
            printf("角色%d HP: %d  角色%d HP: %d\n", fir, fir_hp, sec, sec_hp);
            if (fir_hp <= 0 || sec_hp <= 0)//判斷先攻與後攻是否有一方血量低於0
            {
                i = -1;//有中一方血量低於0則將i變成-1 經過i++變為0 跳出迴圈
                continue;//若if判斷式成立則不執行下面的敘述句
            }
            printf("角色%d 對角色%d 發動攻擊，造成 %d 點傷害\n", sec, fir, sec_atk - fir_def);
            fir_hp = fir_hp - (sec_atk - fir_def);
            printf("角色%d HP: %d  角色%d HP: %d\n", fir, fir_hp, sec, sec_hp);
            if (fir_hp <= 0 || sec_hp <= 0)//判斷先攻與後攻是否有一方血量低於0
            {
                i = -1;//有中一方血量低於0則將i變成-1 經過i++變為0 跳出迴圈
            }
        }
        if (fir_hp <= 0)
            printf("\n角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n", fir, sec);
        else if (sec_hp <= 0)
            printf("\n角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n", sec, fir);
    }
    return 0;
}
