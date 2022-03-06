#include <stdio.h>
#include <stdlib.h>

char type[4]="WAF";
int hp[4]= {50,40,45};
int atk[4]= {15,20,17};
int def[4]= {5,8,7};

char char1_name[21]="楊安安";
char char2_name[21]="小可愛";
char char3_name[21]="柏豪胖胖";
char char4_name[21];


int main() {
    float type1,type2;
    float blood1,blood2;

    int char4_is_create=0;
    int is_correct,choose;
    while(1) {
        printf("1. 新增或修改新增角色\n");
        printf("2. 顯示所有角色資料\n");
        printf("3. 戰鬥\n");
        printf("0. 結束遊戲\n");
        printf("請選擇：");
        scanf("%d",&choose);
        switch(choose) {
        case 1:
            EditNewChar(char4_is_create);
            char4_is_create = 1;
            break;
        case 2:
            PrintCharData(char4_is_create);
            break;
        case 3:
            SelectAndBattle(char4_is_create);
            break;
        case 0:
            printf("結束遊戲\n");
            return 0;

        default :
            printf("輸入錯誤！\n\n");

        }



        puts("");
    }
}

int EditNewChar(int char4_is_create) {
    int is_correct;

    do {
        is_correct = 1; //初始化flag
        if(char4_is_create == 0) {
            printf("\n新增角色\n");
        } else {
            printf("\n修改新增角色\n");
        }

        printf("名稱：");
        scanf("%s",char4_name);
        printf("屬性：");
        scanf("%*c%c", &type[3]);
        printf("血量：");
        scanf("%d", &hp[3]);
        printf("攻擊：");
        scanf("%d", &atk[3]);
        printf("防禦：");
        scanf("%d", &def[3]);
        //檢察屬性
        if(type[3] != 'F' && type[3] != 'W' && type[3] != 'G' && type[3] != 'A' &&
                type[3] != 'f' && type[3] != 'w' && type[3] != 'g' && type[3] != 'a') {
            printf("錯誤：無此屬性\n");
            is_correct = 0;
        } else if(type[3] >= 'a')
            type[3] -= 32;
        //檢查能力數值
        int char4_sum = hp[3] + atk[3] + def[3];
        if(hp[3] < 40 || hp[3] > 50 || atk[3] < 15 || atk[3] > 20 ||
                def[3] < 5 || def[3] > 10 || char4_sum < 65 || char4_sum > 70) {
            printf("錯誤：能力數值在限制範圍之外\n");
            is_correct = 0;
        }
    } while(!is_correct);

    printf("\n角色4\n名稱：%s\n",char4_name);
    printf("屬性：%c     攻擊：%d\n", type[3], atk[3]);
    printf("血量：%d    防禦：%d\n", hp[3], def[3]);
    printf("角色強度預測：%.2f\n", (hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5 - 50.0) * 6.5 );

    printf("\n");
    //return choose;
}

int PrintCharData(int char4_is_create) {

    printf("角色1\n名稱：%s\n",char1_name);
    printf("屬性：%c     攻擊：%d\n", type[0], atk[0]);
    printf("血量：%d    防禦：%d\n", hp[0], def[0]);
    printf("角色強度預測：%.2f\n\n",
           (hp[0] * 1.0 + atk[0] * 0.8 + def[0] * 0.5 - 50.0) * 6.5 );
    printf("角色2\n名稱：%s\n",char2_name);
    printf("屬性：%c     攻擊：%d\n", type[1], atk[1]);
    printf("血量：%d    防禦：%d\n", hp[1], def[1]);
    printf("角色強度預測：%.2f\n\n",
           (hp[1] * 1.0 + atk[1] * 0.8 + def[1] * 0.5 - 50.0) * 6.5 );
    printf("角色3\n名稱：%s\n",char3_name);
    printf("屬性：%c     攻擊：%d\n", type[2], atk[2]);
    printf("血量：%d    防禦：%d\n", hp[2], def[2]);
    printf("角色強度預測：%.2f\n\n",
           (hp[2] * 1.0 + atk[2] * 0.8 + def[2] * 0.5 - 50.0) * 6.5 );
    if(char4_is_create == 1) {
        printf("\n角色4\n名稱：%s\n",char4_name);
        printf("屬性：%c     攻擊：%d\n", type[3], atk[3]);
        printf("血量：%d    防禦：%d\n", hp[3], def[3]);
        printf("角色強度預測：%.2f\n", (hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5 - 50.0) * 6.5 );
    }

    return ;
}
int SelectAndBattle(int char4_is_create) {
    int is_correct;
    int first_atk;


    int second_atk;

    do {
        is_correct = 1; //初始化flag
        printf("選擇先攻角色：");
        scanf("%d", &first_atk);
        if(first_atk < 1 || first_atk > 3 + char4_is_create) {
            printf("錯誤：無此角色\n");
            is_correct = 0;
        }
    } while(!is_correct);
    do {
        is_correct = 1; //初始化flag
        printf("選擇後攻角色：");
        scanf("%d", &second_atk);
        if(second_atk < 1 || second_atk > 3 + char4_is_create) {
            printf("錯誤：無此角色\n");
            is_correct = 0;
        } else if(second_atk == first_atk) {
            printf("錯誤：不可重複選取\n");
            is_correct = 0;
        }
    } while(!is_correct);
    printf("\n先攻為角色%d、後攻為角色%d\n", first_atk, second_atk);

    battle(first_atk, second_atk);

}
int battle(int first_atk,int second_atk) {
    char first_atk_type;
    int first_atk_origin_hp;
    int first_atk_hp;
    int first_atk_atk;
    int first_atk_def;

    char second_atk_type;
    int second_atk_origin_hp;
    int second_atk_hp;
    int second_atk_atk;
    int second_atk_def;

    int turn;
    float type1,type2;
    float blood1,blood2;

    //將先攻的能力資料取出
    first_atk_type =  (first_atk == 1) ? type[0] : (first_atk == 2) ? type[1] : (first_atk == 3) ? type[2] : type[3];
    first_atk_hp = (first_atk == 1) ? hp[0] : (first_atk == 2) ? hp[1] : (first_atk == 3) ? hp[2] : hp[3];
    first_atk_atk = (first_atk == 1) ? atk[0] : (first_atk == 2) ? atk[1] : (first_atk == 3) ? atk[2] : atk[3];
    first_atk_def = (first_atk == 1) ? def[0] : (first_atk == 2) ? def[1] : (first_atk == 3) ? def[2] : def[3];
    //將後攻的能力資料取出
    second_atk_type =  (second_atk == 1) ? type[0] : (second_atk == 2) ? type[1] : (second_atk == 3) ? type[2] : type[3];
    second_atk_hp = (second_atk == 1) ? hp[0] : (second_atk == 2) ? hp[1] : (second_atk == 3) ? hp[2] : hp[3];
    second_atk_atk = (second_atk == 1) ? atk[0] : (second_atk == 2) ? atk[1] : (second_atk == 3) ? atk[2] : atk[3];
    second_atk_def = (second_atk == 1) ? def[0] : (second_atk == 2) ? def[1] : (second_atk == 3) ? def[2] : def[3];

    turn = 1; //初始化攻擊方
    first_atk_origin_hp = first_atk_hp;
    second_atk_origin_hp = second_atk_hp;

    if( (first_atk_type == 'W' && second_atk_type == 'F') || (first_atk_type == 'F' && second_atk_type == 'A') ||(first_atk_type == 'A' && second_atk_type == 'G') ||(first_atk_type == 'G' && second_atk_type == 'W') ) {
        type1=1.2;
        type2=0.8;
    } else if( (first_atk_type == 'F' && second_atk_type == 'W') || (first_atk_type == 'A' && second_atk_type == 'F') ||(first_atk_type == 'G' && second_atk_type == 'A') ||(first_atk_type == 'W' && second_atk_type == 'G') ) {
        type1=0.8;
        type2=1.2;
    } else {
        type1=1;
        type2=1;
    }
    blood1=1;
    blood2=1;
    printf("戰鬥開始\n\n");
    while(first_atk_hp > 0 && second_atk_hp > 0) {
        int atk;
        if(turn == 1) {
            atk =(int) (first_atk_atk * type1 * blood1 - second_atk_def);
            second_atk_hp -= atk;
            if(second_atk_hp < second_atk_origin_hp/2) {
                blood2=1.2;
            }
            printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n", first_atk, second_atk, atk);
            turn = 2; //交換攻擊方
        } else {
            atk =(int) (second_atk_atk * type2 * blood2 - first_atk_def);
            first_atk_hp -= atk;
            if(first_atk_hp < first_atk_origin_hp/2) {
                blood1=1.2;
            }
            printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n", second_atk, first_atk, atk);
            turn = 1; //交換攻擊方
        }
        printf("角色%d HP: %d  角色%d HP: %d\n\n", first_atk, first_atk_hp, second_atk, second_atk_hp);
    }
    printf("角色%d 失去戰鬥能力\n", (first_atk_hp > 0) ? second_atk : first_atk);
    printf("戰鬥結束\n\n");
    printf("角色%d 獲勝\n\n", (first_atk_hp > 0) ? first_atk : second_atk);


}







