#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//角色一變數宣告
char char1_name[] = "瑞斯叔叔";
char char1_type[] = "F";
int char1_hp[] = {45};
int char1_atk[] = {20};
int char1_def[] = {5};
//角色二變數宣告
char char2_name[] = "幸福教主刮哥";
char char2_type[] = "W";
int char2_hp[] = {40};
int char2_atk[] = {15};
int char2_def[] = {10};
//角色三變數宣告
char char3_name[] = "垃圾車";
char char3_type[] = "A";
int char3_hp[] = {45};
int char3_atk[] = {15};
int char3_def[] = {10};
//角色四變數宣告
char char4_name[20];
char char4_type[10];
int char4_hp[5];
int char4_atk[5];
int char4_def[5];
//先攻 後攻 的相關屬性
int firstone_atk;
int firstone_hp;
int firstone_def;
int firstone_type;
int lastone_atk;
int lastone_hp;
int lastone_def;
int lastone_type;
//前四個的角色強度預測
int power1;
int power2;
int power3;
//新增的相關變數
int start;
//新增或修改新增角色的計數器
int count_character=0;
//新增屬性相剋相關變數
int happening_type = 0;
void EditNewChar() {
    //角色輸入屬性flag
    int attributes_true = 1;
    //血量、攻擊、防禦、綜合屬性輸入flag
    int mix_true = 1, hp_true = 1, atk_true = 1, def_true = 1, happening = 1;
    do {
        //輸出錯誤訊息 並要求重新輸入數值
        if(attributes_true == 0) {
            printf("錯誤 : 無此屬性\n");
        }
        if(mix_true + hp_true + atk_true + def_true!= 4) {
            printf("錯誤 : 能力數值在範圍之外\n");
        }
        //新增角色相關素質
        if(count_character != 0) {
            printf("\n修改新增角色\n\n角色4\n名稱:%s\n屬性:%s    攻擊:%d\n血量:%d   防禦:%d\n",char4_name,char4_type,char4_atk[0],char4_hp[0],char4_def[0]);
            printf("\n名稱:");
        } else if(count_character == 0) {
            printf("\n新增角色\n名稱:");
            count_character++;
        }
        scanf("%s",char4_name);
        printf("屬性:");
        scanf("%s",char4_type);
        printf("血量:");
        scanf("%d",&char4_hp[0]);
        printf("攻擊:");
        scanf("%d",&char4_atk[0]);
        printf("防禦:");
        scanf("%d",&char4_def[0]);
        //屬性大小寫問題 利用flag判斷是否重新輸入
        if(char4_type[0] == 'f') {
            char4_type[0] = 'F';
            attributes_true = 1;
        } else if(char4_type[0] == 'w') {
            char4_type[0] = 'W';
            attributes_true = 1;
        } else if(char4_type[0] == 'g') {
            char4_type[0] = 'G';
            attributes_true = 1;
        } else if(char4_type[0] == 'a') {
            char4_type[0] = 'A';
            attributes_true = 1;
        } else if(char4_type[0] == 'F') {
            attributes_true = 1;
        } else if(char4_type[0] == 'W') {
            attributes_true = 1;
        } else if(char4_type[0] == 'G') {
            attributes_true = 1;
        } else if(char4_type[0] == 'A') {
            attributes_true = 1;
        } else {
            attributes_true = 0;
        }
        //角色素質是否皆在值域內 利用flag判斷是否重新輸入
        if((char4_hp[0] < 40)||(char4_hp[0] > 50)) {
            hp_true = 0;
        } else if((char4_hp[0] >= 40)&&(char4_hp[0] <= 50)) {
            hp_true = 1;
        }
        if((char4_atk[0] < 15)||(char4_atk[0] > 20)) {
            atk_true = 0;
        } else if((char4_atk[0] >= 15)&&(char4_atk[0] <= 20)) {
            atk_true = 1;
        }
        if((char4_def[0] >= 5)&&(char4_def[0] <= 10)) {
            def_true = 1;
        } else if((char4_def[0] < 5)||(char4_def[0] > 10)) {
            def_true = 0;
        }
        if(((char4_hp[0] + char4_atk[0] + char4_def[0])>=65)||((char4_hp[0] + char4_atk[0] + char4_def[0])<=70)) {
            mix_true = 1;
        } else if(((char4_hp[0] + char4_atk[0] + char4_def[0])<65)||((char4_hp[0] + char4_atk[0] + char4_def[0])>70)) {
            mix_true = 0;
        }
    } while((attributes_true == 0)|(mix_true + hp_true + atk_true + def_true != 4));
    //角色四資訊
    int power4 = (char4_hp[0] * 1.0 + char4_atk[0] * 0.8 + char4_def[0] * 0.5 - 50 ) * 6.5;
    printf("\n角色4\n名稱:%s\n屬性:%s    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n\n",char4_name,char4_type,char4_atk[0],char4_hp[0],char4_def[0],power4);
    printf("\n");
}
//新增一個PrintCharData的函式(顯示所有角色的資料)
void PrintCharData() {
    power1 = (char1_hp[0] * 1.0 + char1_atk[0] * 0.8 + char1_def[0] * 0.5 - 50 ) * 6.5;
    power2 = (char2_hp[0] * 1.0 + char2_atk[0] * 0.8 + char2_def[0] * 0.5 - 50 ) * 6.5;
    power3 = (char3_hp[0] * 1.0 + char3_atk[0] * 0.8 + char3_def[0] * 0.5 - 50 ) * 6.5;
    printf("角色1\n名稱:%s\n屬性:%s    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char1_name,char1_type,char1_atk[0],char1_hp[0],char1_def[0],power1);
    printf("\n角色2\n名稱:%s\n屬性:%s    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char2_name,char2_type,char2_atk[0],char2_hp[0],char2_def[0],power2);
    printf("\n角色3\n名稱:%s\n屬性:%s    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char3_name,char3_type,char3_atk[0],char3_hp[0],char3_def[0],power3);
    if(count_character != 0) {
        int power4 = (char4_hp[0] * 1.0 + char4_atk[0] * 0.8 + char4_def[0] * 0.5 - 50 ) * 6.5;
        printf("\n角色4\n名稱:%s\n屬性:%s    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n\n",char4_name,char4_type,char4_atk[0],char4_hp[0],char4_def[0],power4);
    }
    if(count_character == 0) {
        printf("\n");
    }
}
//新增一個PrintCharData的函式，包含Battling副程式(選取先攻後攻分別為何者，接著戰鬥開始!!)
void SelectAndBattle() {
    //先攻，後攻
    int firstone,lastone;
    //存取資料用到的變數
    int sum1_hp,sum2_hp,data_hp,data_atk,data_def,data_line;
    printf("\n");
    if(count_character == 0) {
        //先攻角色錯誤時，回來的地方
first1_choose:
        //不可重複選取時，回來的地方
compare1_choose:
        printf("選擇先攻角色 : ");
        scanf("%d",&firstone);
        while((firstone>3)||(firstone<1)) {
            printf("錯誤 : 無此角色\n");
            goto first1_choose;
        }
        while((firstone<=3)&&(firstone>=1)) {
            //後攻角色錯誤時，回來的地方
last1_choose:
            printf("選擇後攻角色 : ");
            scanf("%d",&lastone);
            if((lastone>3)||(lastone<1)) {
                printf("錯誤 : 無此角色\n");
                goto last1_choose;
            } else if((lastone<=3)&&(lastone>=1)) {
                if(firstone == lastone) {
                    printf("錯誤 : 不可重複選取\n");
                    goto compare1_choose;
                }
                Battling(firstone,lastone,sum1_hp,sum2_hp);
            }
            break;
        }
    } else if(count_character != 0) {
first2_choose:
compare2_choose:
        printf("選擇先攻角色 : ");
        scanf("%d",&firstone);
        while((firstone>4)||(firstone<1)) {
            printf("錯誤 : 無此角色\n");
            goto first2_choose;
        }
        while((firstone<=4)&&(firstone>=1)) {
last2_choose:
            printf("選擇後攻角色 : ");
            scanf("%d",&lastone);
            if((lastone>4)||(lastone<1)) {
                printf("錯誤 : 無此角色\n");
                goto last2_choose;
            } else if((lastone<=4)&&(lastone>=1)) {
                if(firstone == lastone) {
                    printf("錯誤 : 不可重複選取\n");
                    goto compare2_choose;
                }
                Battling(firstone,lastone,sum1_hp,sum2_hp);
            }
            break;
        }
    }
}
//PrintCharData的副程式Battleing(戰鬥開始!!)
void Battling(int firstone,int lastone,int sum1_hp,int sum2_hp) {
    printf("\n先攻為角色%d、後攻為角色%d\n戰鬥開始\n\n", firstone, lastone);
    if(firstone==1) {
        firstone_type = char1_type[0];
        firstone_hp = char1_hp[0];
        firstone_atk = char1_atk[0];
        firstone_def = char1_def[0];
    } else if(firstone==2) {
        firstone_type = char2_type[0];
        firstone_hp = char2_hp[0];
        firstone_atk = char2_atk[0];
        firstone_def = char2_def[0];
    } else if(firstone==3) {
        firstone_type = char3_type[0];
        firstone_hp = char3_hp[0];
        firstone_atk = char3_atk[0];
        firstone_def = char3_def[0];
    } else if(firstone==4) {
        firstone_type = char4_type[0];
        firstone_hp = char4_hp[0];
        firstone_atk = char4_atk[0];
        firstone_def = char4_def[0];
    }
    if(lastone==1) {
        lastone_type = char1_type[0];
        lastone_hp = char1_hp[0];
        lastone_atk = char1_atk[0];
        lastone_def = char1_def[0];
    } else if(lastone==2) {
        lastone_type = char2_type[0];
        lastone_hp = char2_hp[0];
        lastone_atk = char2_atk[0];
        lastone_def = char2_def[0];
    } else if(lastone==3) {
        lastone_type = char3_type[0];
        lastone_hp = char3_hp[0];
        lastone_atk = char3_atk[0];
        lastone_def = char3_def[0];
    } else if(lastone==4) {
        lastone_type = char4_type[0];
        lastone_hp = char4_hp[0];
        lastone_atk = char4_atk[0];
        lastone_def = char4_def[0];
    }
    sum1_hp = firstone_hp;
    sum2_hp = lastone_hp;
    if((firstone_type == 'W' && lastone_type == 'F')||(firstone_type == 'F' && lastone_type == 'A')||(firstone_type == 'A' && lastone_type == 'G')||(firstone_type == 'G' && lastone_type == 'W')) {
        happening_type = 1;
    } else if((firstone_type == 'F' && lastone_type == 'W')||(firstone_type == 'A' && lastone_type == 'F')||(firstone_type == 'G' && lastone_type == 'A')||(firstone_type == 'W' && lastone_type == 'G')) {
        happening_type = 2;
    } else {
        happening_type = 0;
    }
    do {
        if(lastone_hp < sum2_hp/2.0) {
            if(happening_type == 1) {
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", firstone, lastone, (int)(firstone_atk*1.2*1.2 - lastone_def));
                lastone_hp = (int)(lastone_hp - (firstone_atk*1.2*1.2 - lastone_def));
            } else if(happening_type == 0) {
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", firstone, lastone, (int)(firstone_atk*1.2 - lastone_def));
                lastone_hp = (int)(lastone_hp - (firstone_atk*1.2 - lastone_def));
            } else if(happening_type == 2) {
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", firstone, lastone, (int)(firstone_atk*1.2*0.8 - lastone_def));
                lastone_hp = (int)(lastone_hp - (firstone_atk*1.2*0.8 - lastone_def));
            }
        } else if(lastone_hp >= sum2_hp/2.0) {
            if(happening_type == 1) {
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", firstone, lastone, (int)(firstone_atk*1.2 - lastone_def));
                lastone_hp = (int)(lastone_hp - (firstone_atk*1.2 - lastone_def));
            } else if(happening_type == 0) {
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", firstone, lastone, (int)(firstone_atk - lastone_def));
                lastone_hp = (int)(lastone_hp - (firstone_atk - lastone_def));
            } else if(happening_type == 2) {
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", firstone, lastone, (int)(firstone_atk*0.8 - lastone_def));
                lastone_hp = (int)(lastone_hp - (firstone_atk*0.8 - lastone_def));
            }
        }
        printf("角色%d HP: %d 角色%d HP:%d\n\n", firstone, firstone_hp, lastone, lastone_hp);
        if(firstone_hp <= 0) {
            printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n\n", firstone, lastone);
            break;
        }
        if(lastone_hp <= 0) {
            printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n\n", lastone, firstone);
            break;
        }
        if(lastone_hp < sum2_hp/2.0) {
            if(happening_type == 2) {
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", lastone, firstone, (int)(lastone_atk*1.2*1.2 - firstone_def));
                firstone_hp = (int)(firstone_hp - (lastone_atk*1.2*1.2 - firstone_def));
            } else if(happening_type == 0) {
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", lastone, firstone, (int)(lastone_atk*1.2 - firstone_def));
                firstone_hp = (int)(firstone_hp - (lastone_atk*1.2 - firstone_def));
            } else if(happening_type == 1) {
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", lastone, firstone, (int)(lastone_atk*1.2*0.8 - firstone_def));
                firstone_hp = (int)(firstone_hp - (lastone_atk*1.2*0.8 - firstone_def));
            }
        } else if(lastone_hp >= sum2_hp/2.0) {
            if(happening_type == 2) {
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", lastone, firstone, (int)(lastone_atk*1.2 - firstone_def));
                firstone_hp = (int)(firstone_hp - (lastone_atk*1.2 - firstone_def));
            } else if(happening_type == 0) {
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", lastone, firstone, (int)(lastone_atk - firstone_def));
                firstone_hp = (int)(firstone_hp - (lastone_atk - firstone_def));
            } else if(happening_type == 1) {
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", lastone, firstone, (int)(lastone_atk*0.8 - firstone_def));
                firstone_hp = (int)(firstone_hp - (lastone_atk*0.8 - firstone_def));
            }
        }
        printf("角色%d HP: %d 角色%d HP:%d\n\n", firstone, firstone_hp, lastone, lastone_hp);
        if(firstone_hp <= 0) {
            printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n\n", firstone, lastone);
            break;
        }
        if(lastone_hp <= 0) {
            printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n\n", lastone, firstone);
            break;
        }
    } while((firstone_hp>=0)&&(lastone_hp>=0));
}
int main(void) {
    power1 = (char1_hp[0] * 1.0 + char1_atk[0] * 0.8 + char1_def[0] * 0.5 - 50 ) * 6.5;
    power2 = (char2_hp[0] * 1.0 + char2_atk[0] * 0.8 + char2_def[0] * 0.5 - 50 ) * 6.5;
    power3 = (char3_hp[0] * 1.0 + char3_atk[0] * 0.8 + char3_def[0] * 0.5 - 50 ) * 6.5;
    //角色一資訊
    printf("角色1\n名稱:%s\n屬性:%s    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char1_name,char1_type,char1_atk[0],char1_hp[0],char1_def[0],power1);
    //角色二資訊
    printf("\n角色2\n名稱:%s\n屬性:%s    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n",char2_name,char2_type,char2_atk[0],char2_hp[0],char2_def[0],power2);
    //角色三資訊
    printf("\n角色3\n名稱:%s\n屬性:%s    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測：%d\n\n",char3_name,char3_type,char3_atk[0],char3_hp[0],char3_def[0],power3);
    while(1) {
        //結束戰鬥時，goto回來
start_battle:
        //判斷接下來的流程為何
        printf("1、新增或修改新增角色\n2、顯示所有角色資料\n3、戰鬥\n0、結束遊戲\n請選擇 : ");
        scanf("%d",&start);
        if(start == 1) {
            //EditNewChar的函式代入
            EditNewChar();
        } else if(start == 2) {
            //PrintCharData的函式代入
            PrintCharData();
        } else if(start == 3) {
            SelectAndBattle();
        } else if(start == 0) {
            //輸入0結束遊戲
            printf("\n結束遊戲\n");
            return 0;
        } else {
            //對，就是輸入錯誤
            printf("輸入錯誤\n");
        }
    }
    return 0;
}

