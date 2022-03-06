#include <stdio.h>
#include <stdlib.h>

/*
數據限制：
屬性：F=火、W=水、G=土、A=風。不可輸入F、W、G、A、f、w、g、a以外的英文字母。
血量 40~50的整數
攻擊 15~20的整數
防禦 5~10的整數
3者總和在65~70之間
攻擊傷害公式為：(int)(攻擊方攻擊力 * 相剋倍率 * 殘血倍率 - 被攻擊方防禦力)
    屬性相剋倍率：
        屬性關係W>F>A>G>W
        若為相剋關係：優勢者1.2倍，劣勢者0.8倍
        若雙方無相剋則攻擊力各為1.0倍
    殘血倍率：
        攻擊方血量小於原本的50%時殘血倍率為1.2倍
*/
/*
參考https://hackmd.io/@K-54OPo-RMyCWp-fBFE48Q/SkTwAtktB#%E7%AC%AC5%E9%80%B1
新增角色：屬性判斷方式、correct_flag
*/

void EditNewChar(); //函式：新增角色
void PrintCharData(); //函式：顯示角色資訊
void SelectAndBattle(); //函式：擇先攻後，接著進Battling戰鬥函式
void Battling(); //函式：戰鬥

int n = 3; //用於switch(star_ans)case2顯示角色資料。如有新增角色，case1結尾n改為4
int *n_Addr = &n; //角色數量(n)指標，確保在各函示間正確傳遞
int correct; //flag

char char_name[4][21] = {"蘑菇", "香菇", "杏鮑菇"}; //角色1：蘑菇。角色2：香菇。角色3：杏鮑菇。如果有，角色4

char type[4] = {'G', 'W', 'F'}; //依序角色1~3屬性，預留可新增角色4屬性
int hp[4] = {40, 50, 40}; //依序角色1~3血量，預留可新增角色4血量
int atk[4] = {20, 15, 15}; //依序角色1~3攻擊，預留可新增角色4攻擊
int def[4] = {5, 5, 10}; //依序角色1~3防禦，預留可新增角色4防禦
int char4_sum; //角色4能力數值總和
double power; //角色強度預測

//先攻角色st
int st_char; //先攻角色號
int st_type; //屬性
int st_hp; //血量
int st_half_hp; //半血
int st_atk; //攻擊
int st_def; //防禦
//後攻角色nd
int nd_char; //後攻角色號
int nd_type; //屬性
int nd_hp; //血量
int nd_half_hp; //半血
int nd_atk; //攻擊
int nd_def; //防禦

int first_sum_atk; //先攻方對後攻方之攻擊量
int second_sum_atk; //後攻方對先攻方之攻擊量
double first_type_atk; //先攻方對後攻方之屬性相剋倍率
double second_type_atk; //後攻方對先攻方之屬性相剋倍率

int star_game = 1; //遊戲開始flag

int main(){
    while (star_game != 0){
        int star_ans; //選取初始選項變數
        printf("1.新增或修改新增角色\n"); //case新增或修改角色4
        printf("2.顯示所有角色資料\n"); //case2顯示角色資料
        printf("3.戰鬥\n"); //case3進入戰鬥
        printf("0.結束遊戲\n"); //case0遊戲結束flag=0
        printf("請選擇:");
        scanf("%d", &star_ans);
        printf("\n");

        switch (star_ans){
            case 1:
                EditNewChar();
                break;
            case 2:
                PrintCharData();
                break;
            case 3:
                SelectAndBattle();
                break;
            case 0:
                printf("結束遊戲");
                star_game = 0;
        }
    }
    return 0;
}

void EditNewChar(){  //函式：新增角色 
    do {
        correct = 1; //初始化flag
        printf("新增角色\n");
        printf("角色名稱：");
        scanf("%*c%s", char_name[3]); //輸入角色名稱
        printf("屬性：");
        scanf("%*c%c", &type[3]); //輸入屬性
        printf("血量：");
        scanf("%d", &hp[3]); //輸入血量
        printf("攻擊：");
        scanf("%d", &atk[3]); //輸入攻擊
        printf("防禦：");
        scanf("%d", &def[3]); //輸入防禦
    if (type[3]!='F' && type[3]!='W' && type[3]!='A' && type[3]!= 'G' && type[3]!= 'f' && type[3]!= 'w' && type[3]!= 'a'  && type[3]!= 'g'){
        printf("錯誤：無此屬性\n");
        correct = 0;
    }
    else if (type[3] >= 'a'){  //如果輸入是小寫，轉存成大寫
        type[3] = type[3] - 32;
    }
    char4_sum = hp[3] + atk[3] + def[3]; //角色4能力數值總和
    if (hp[3]<40 || hp[3]>50 || atk[3]<15 || atk[3]>20 || def[3]<5 || def[3]>10 || char4_sum<65 || char4_sum>70){
        printf("錯誤：能力數值在限制範圍之外\n");
        correct = 0;
                    }
    printf("\n");
    }while (!correct);
        *n_Addr = 4; //顯示角色資訊時，多顯示角色4資訊
}

void PrintCharData(){ //函式：顯示角色資訊 
    int i; //for迴圈變數
    for (i=0; i<n; i++){ //印出角色1~3所有數值，角色1(i=0)，角色2(i=1)，角色3(i=2)
        printf("角色%d\n", i+1);
        printf("角色名稱：%s\n", char_name[i]);
        printf("屬性：%-6c血量：%d\n" ,type[i] ,hp[i]); //屬性、血量
        printf("攻擊：%-6d防禦：%d\n" ,atk[i] ,def[i]); //攻擊、防禦
        power = (hp[i]*1 + atk[i]*0.8 + def[i]*0.5 - 50)*6.5; //強度預測：[(血量*1+攻擊*0.8+防禦*0.5)-50]*6.5
        printf("角色強度預測：%.2lf\n\n", power); //強度預測
    }
}

void SelectAndBattle(){ //函式：擇先攻後，接著進Battling戰鬥函式
    do {
        correct = 1; //初始化flag
        printf("選擇先攻角色：");
        scanf("%d", &st_char);
        if (st_char<1 || st_char>n){ //如果先攻角色號小於1，或大於n=3(未新增角色)/n=4(有新增角色)
            printf("錯誤：無此角色\n");
            correct = 0;
        }
    }while (!correct);
    do {
        correct = 1; //初始化flag
        printf("選擇後攻角色：");
        scanf("%d", &nd_char);
        if (nd_char<1 || nd_char>n){ //如果後攻角色號小於1，或大於n=3(未新增角色)/n=4(有新增角色)
            printf("錯誤：無此角色\n");
            correct = 0;
        }else if (nd_char == st_char){
            printf("錯誤：不可重複選取\n");
            correct = 0;
        }
    }while (!correct);
    //先攻角色資料取出
    st_type = type[st_char-1];
    st_hp = hp[st_char-1];
    st_half_hp = st_hp / 2; //先攻角色，半血數值
    st_atk = atk[st_char-1];
    st_def = def[st_char-1];
    //後攻角色資料取出
    nd_type = type[nd_char-1];
    nd_hp = hp[nd_char-1];
    nd_half_hp = nd_hp / 2; //後攻角色，半血數值
    nd_atk = atk[nd_char-1];
    nd_def =  def[nd_char-1];

    if (st_type == 'A'){ //屬性相剋判斷，先攻屬性A
        if (nd_type == 'F'){
            first_type_atk = 0.8;
            second_type_atk = 1.2;
        }else if (nd_type == 'G'){
            first_type_atk = 1.2;
            second_type_atk = 0.8;
        }else {
            first_type_atk = 1;
            second_type_atk = 1;
        }
    }
    if (st_type == 'G'){ //屬性相剋判斷，先攻屬性G
        if (nd_type == 'A'){
            first_type_atk = 0.8;
            second_type_atk = 1.2;
        }else if (nd_type == 'W'){
            first_type_atk = 1.2;
            second_type_atk = 0.8;
        }else {
            first_type_atk = 1;
            second_type_atk = 1;
        }
    }
    if (st_type == 'F'){ //屬性相剋判斷，先攻屬性F
        if (nd_type == 'W'){
            first_type_atk = 0.8;
            second_type_atk = 1.2;
        }else if (nd_type == 'A'){
            first_type_atk = 1.2;
            second_type_atk = 0.8;
        }else {
            first_type_atk = 1;
            second_type_atk = 1;
        }
    }
    if (st_type == 'W'){ //屬性相剋判斷，先攻屬性W
        if (nd_type == 'G'){
            first_type_atk = 0.8;
            second_type_atk = 1.2;
        }else if (nd_type == 'F'){
            first_type_atk = 1.2;
            second_type_atk = 0.8;
        }else {
            first_type_atk = 1;
            second_type_atk = 1;
        }
    }
    first_sum_atk = st_atk * first_type_atk - nd_def; //先攻方攻擊計算
    second_sum_atk = nd_atk * second_type_atk - st_def; //後攻方攻擊計算
    Battling();
}

void Battling(){ //函式：戰鬥
    while(st_hp>0 && nd_hp>0){
        printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", st_char, nd_char, first_sum_atk);
        nd_hp = nd_hp - first_sum_atk;
        printf("角色%d HP：%d  角色%d HP：%d\n", st_char, st_hp, nd_char, nd_hp);
        printf("\n");
        if (nd_hp < nd_half_hp){ //後攻血量低於50%，加上殘寫倍率
            second_sum_atk = (nd_atk * second_type_atk * 1.2 - st_def);
        }
        if (nd_hp<=0 && st_hp!=0){
            printf("角色%d 失去戰鬥能力\n", nd_char);
            printf("戰鬥結束\n");
            printf("\n");
            printf("角色%d 獲勝",st_char);
            printf("\n\n");
            break;
        }
        printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", nd_char, st_char, second_sum_atk);
        st_hp = st_hp - second_sum_atk;
        printf("角色%d HP：%d  角色%d HP：%d\n", st_char, st_hp, nd_char, nd_hp);
        printf("\n");
        if (st_hp < st_half_hp){ //先攻血量低於50%，加上殘寫倍率
            first_sum_atk = (st_atk * first_type_atk * 1.2 - nd_def);
        }
        if (st_hp<=0 && nd_hp!=0){
            printf("角色%d 失去戰鬥能力\n", st_char);
            printf("戰鬥結束\n");
            printf("\n");
            printf("角色%d 獲勝", nd_char);
            printf("\n\n");
            break;
        }
    }
}
