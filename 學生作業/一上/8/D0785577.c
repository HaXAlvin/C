#include<stdio.h>
#include<string.h>
#include<ctype.h>

int chosen(int a);                           //確認功能選擇是否在範圍內;
int create_type(char t);                     //確認新增/修改角色的屬性是否符合規定;
int create_ability(int x, int y, int z);     //確認新增/修改角色的能力值是否符合規定;
int member_range(int m, int n);              //確認選角是否存在;
int type_weakness(char f, char l);           //屬性相剋判斷;
void battle(int first[], int last[], int weakness_result);         //戰鬥

int main()
{
    char name[5][21] = { " ","RTRT","DK","Hue"," " };    //角色名稱，name[1]、name[2]...分別對應到角色1、2、3、4的名稱;
    char type[5] = { ' ','F','G','W',' ' };              //角色屬性，排序同上;
    int  hp[5]   = { 3,45,40,45,0 };                     //角色生命值，第一個hp[0]用來存取目前角色數量，其他排序同上;
    int  atk[5]  = { 3,20,20,15,0 };                     //角色攻擊力，排序同上;
    int  def[5]  = { 3,5,10,10,0 };                      //角色防禦力，排序同上;
    float  combat[5] = { 3,0,0,0,0 };                    //角色強度預測，排序同上;

    for (int i = 1; i < 4; i++)    //計算角色1~3的強度預測;
    {
        combat[i] = (hp[i] * 1.0 + atk[i] * 0.8 + def[i] * 0.5 - 50) * 6.5;
    }

    while (1)
    {
        int choose = 0;        //判斷功能選擇的變數;
        printf("1. 新增或修改新增角色\n"
               "2. 顯示所有角色資料\n"
               "3. 戰鬥\n"
               "0. 結束遊戲\n");
        printf("請選擇：");
        scanf("%d", &choose);
        getchar();
        printf("\n");

        if (chosen(choose))      //若輸入值不符合規定，函式會回傳1，並重置迴圈;
        {
            printf("輸入錯誤!\n\n");
            continue;
        }
        else if (choose == 0)    //輸入0，結束遊戲;
        {
            printf("結束遊戲\n\n");
            break;
        }
        while (choose == 1)      //輸入1，進入新增/修改角色迴圈;
        {
            int ability_range = 1;    //判斷能力值是否在範圍內的變數;
            int type_check = 1;       //判斷屬性是否正確的變數;

            if (hp[0] == 4)           //若角色已有4名，則修改新增角色，否則新增角色;
                printf("修改新增角色\n");
            else if (hp[0] == 3)
                printf("新增角色\n");
            printf("名稱：");         //將各項數值存入Array中;
            gets(name[4]);
            printf("屬性：");
            scanf("%c", &type[4]);
            printf("血量：");
            scanf("%d", &hp[4]);
            printf("攻擊：");
            scanf("%d", &atk[4]);
            printf("防禦：");
            scanf("%d", &def[4]);
            getchar();

            if (islower(type[4]))    //小寫轉大寫;
                type[4] = toupper(type[4]);

            type_check = create_type(type[4]);                         //若屬性不合規範，回傳1;
            ability_range = create_ability(hp[4], atk[4], def[4]);     //若能力值不合規範，回傳1;

            if (type_check || ability_range)        //其中一項不合規範，重置創角迴圈;
            {
                if (type_check)                  //並顯示各種錯誤原因;
                {
                    printf("錯誤：無此屬性\n");   
                    if (!ability_range)
                    {
                        printf("\n");
                    }
                }
                if (ability_range)
                    printf("錯誤：能力數值在限制範圍之外\n\n");
                
                continue;
            }   
            else        //輸入正確，印出角色四的數值，並將強度預測存入Array;
            {
                printf("\n角色4\n"
                       "名稱：%s\n"
                       "屬性：%c     攻擊：%d\n"
                       "血量：%d    防禦：%d\n", name[4], type[4], atk[4], hp[4], def[4]);
                combat[4] =(hp[4] * 1.0 + atk[4] * 0.8 + def[4] * 0.5 - 50) * 6.5;
                printf("角色強度預測：%.2f\n\n", combat[4]);

                if (hp[0] == 3)        //若目前只有三位角色，將紀錄角色數量的值改成四位;
                {
                    hp[0] = 4;
                    atk[0] = 4;
                    def[0] = 4;
                    combat[0] = 4;
                }
                break;        //順利完成工作，離開迴圈;
            }
        }
        if (choose == 2)        //輸入2，顯示所有角色資料;
        {
            for (int i = 1; i <= hp[0]; i++)        //hp[0]代表目前角色的數量;
            {
                printf("角色%d\n"
                       "名稱：%s\n"
                       "屬性：%c     攻擊：%d\n"
                       "血量：%d    防禦：%d\n"
                       "角色強度預測：%.2f\n\n", i, name[i], type[i], atk[i], hp[i], def[i], combat[i]);
            }
        }
        while (choose == 3)        //輸入3，進入戰鬥迴圈;
        {
            int first = 0;         //first存取先攻角色，last存取後攻角色，member_check判定選取角色是否存在;
            int last = 0;
            int member_check = 0;

            printf("選擇先攻角色：");
            scanf("%d", &first);
            member_check = member_range(first, hp[0]);        //若選取角色不存在，回傳1;

            if (member_check)        //選取角色不存在，重置戰鬥迴圈;
            {
                printf("錯誤：無此角色\n");
                continue;
            }

            int first_member[4] = { first,hp[first],atk[first],def[first] };        //角色存在，將角色的各項數據存入先攻成員的Array，以便戰鬥函式取用;
            char first_type = type[first];    //存取屬性;

            while (1)    //後攻選角迴圈;
            {
                member_check = 0;
                printf("選擇後攻角色：");
                scanf("%d", &last);
                member_check = member_range(last, hp[0]);     //同上，若選取角色不存在，回傳1;

                if (member_check)        //選取角色不存在，重置後攻選角迴圈;
                {
                    printf("錯誤：無此角色\n");
                    continue;
                }

                break;
            }

            if (last == first)            //重複選角的情況，重置整個戰鬥迴圈;
            {
                printf("錯誤：不可重複選取\n");
                continue;
            }

            int last_member[4] = { last,hp[last],atk[last],def[last] };        //角色存在，將角色的各項數據存入後攻成員的Array，以便戰鬥函式取用;
            char last_type = type[last];    //存取屬性;

            printf("\n先攻為角色%d，後攻為角色%d\n", first, last);

            int weakness = type_weakness(first_type, last_type);      //判定屬性剋制情況，根據情況不同會回傳1(先攻方克制後攻方)，2(後攻方克制先攻方)，0(並無相剋);
            battle(first_member, last_member, weakness);    //進行戰鬥，傳送先後攻方的數值以及屬性相剋的情形;
            break;      //完成戰鬥，離開戰鬥迴圈;
        }
    }
    return 0;
}

int chosen(int a)    //判斷功能選擇，若輸入值不在0~3則回傳1;
{
    if (a == 0 || a == 1 || a == 2 || a == 3)
        return 0;
    else
        return 1;
}

int create_type(char t)    //屬性不正確則回傳1;
{
    if (t == 'F' || t == 'W' || t == 'G' || t == 'A')
        return 0;
    else
        return 1;
}

int create_ability(int x, int y, int z)    //能力值範圍不正確則回傳1;
{
    if (x >= 40 && x <= 50 && y >= 15 && y <= 20 && z >= 5 && z <= 10 && x + y + z >= 65 && x + y + z <= 70)
        return 0;
    else
        return 1;
}

int member_range(int m,int n)    //若選角不存在，則回傳1;
{
    if (m > 0 && m <= n)
        return 0;
    else
        return 1;
}

int type_weakness(char f, char l)    //判斷屬性剋制情形，先建立一個屬性表，用一個迴圈找到先攻方的屬性，再列舉與其有相剋關係的其他屬性，並比對後攻方屬性是否為其一; 
{
    char arr[5] = { 'W','F','A','G','W' };    //在屬性表中，相連的兩個數字所存入的屬性，必定為前者剋制後者;
    int find = 0;
    while(arr[find] != f)
    {
        find++;
    }
    if (l == arr[find + 1])                  //因此若後攻方屬性，在表中的順序，是先攻方的後面(find+1)，則先攻方剋制後攻方，回傳1，反之則回傳2;
        return 1;
    else if (l == arr[find - 1] || (f == 'W'&&l == 'G'))    //但要注意，順序在第0的值'W'並沒有前一位，因此只能獨立在條件中;
        return 2;
    else
        return 0;
}

void battle(int first[], int last[], int weakness_result)    //戰鬥迴圈;
{
    printf("戰鬥開始\n\n");
    int first_atk;             //變數分別代表1.先攻方攻擊力，2.後攻方攻擊力，3.先攻方血量，4.後攻方血量，5.造成傷害量，以及6.先後攻方是否觸發殘血倍率;
    int last_atk;              //盡量不變動原本傳進來的值，所以宣告了戰鬥專用攻擊力的變數，用來直接乘上倍率;
    int first_hp = first[1];
    int last_hp = last[1];
    int damage=0;
    int flag_f = 0;
    int flag_l = 0;
    if (weakness_result == 1)    //依照傳入的先後攻方相剋情形 「weakness_result」 ，來決定攻擊力的相剋倍率;
    {
        first_atk = first[2] * 1.2;
        last_atk = last[2] * 0.8;
    }
    else if (weakness_result == 2)
    {
        first_atk = first[2] * 0.8;
        last_atk = last[2] * 1.2;
    }
    else
    {
        first_atk = first[2];
        last_atk = last[2];
    }
    while (first_hp > 0 && last_hp > 0)    //計算造成傷害的迴圈，若有一方血量低於零則判定勝負;
    {
        if (first_hp < first[1] * 0.5 && flag_f == 0)    //判定是否乘上殘血倍率，只會乘一次;
        {
            first_atk = first_atk * 1.2;
            flag_f = 1;
        }

        damage = first_atk - last[3];    //倍率已經乘入攻擊力裡面，剩下只有扣除防禦力;
        last_hp = last_hp - damage;

        printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n", first[0], last[0], damage);
        printf("角色%d HP: %d  角色%d HP: %d\n\n", first[0], first_hp, last[0], last_hp);

        if (last_hp <= 0)    //若後攻方血量歸零，直接結束迴圈;
        {
            break;
        }

        if (last_hp < last[1] * 0.5 && flag_l == 0)
        {
            last_atk = last_atk * 1.2;
            flag_l = 1;
        }

        damage = last_atk - first[3];
        first_hp = first_hp - damage;
        printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n", last[0], first[0], damage);
        printf("角色%d HP: %d  角色%d HP: %d\n\n", first[0], first_hp, last[0], last_hp);
    }

    if (first_hp <= 0)    //判定勝負
    {
        printf("角色%d 失去戰鬥能力\n", first[0]);
        printf("戰鬥結束\n\n");
        printf("角色%d 獲勝\n\n", last[0]);
    }
    else if (last_hp <= 0)
    {
        printf("角色%d 失去戰鬥能力\n", last[0]);
        printf("戰鬥結束\n\n");
        printf("角色%d 獲勝\n\n", first[0]);
    }
}

//數據限制：
//屬性：F = 火、W = 水、G = 土、A = 風。不可輸入F、W、G、A、f、w、g、a以外的英文字母。
//血量：40~50的整數
//攻擊：15~20的整數
//防禦：5~10的整數
//三者總和在65~70之間

//角色強度公式：( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5

//攻擊傷害 = (int)(攻擊方攻擊力 * 相剋倍率 * 殘血倍率 - 被攻擊方防禦力)
//屬性相剋倍率：
//屬性關係W > F > A > G > W
//若為相剋關係：優勢者1.2倍，劣勢者0.8倍
//若雙方無相剋則攻擊力各為1.0倍
//殘血倍率：攻擊方血量小於原本的50%時殘血倍率為1.2倍