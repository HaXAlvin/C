#include<stdio.h>
#include<stdlib.h>

int main() {
    //角色1
    char char1_type = 'G';
    int char1_hp = 50;
    int char1_atk = 15;
    int char1_def = 5;

    //角色2
    char char2_type = 'F';
    int char2_hp = 42;
    int char2_atk = 19;
    int char2_def = 7;

    //角色3
    char char3_type = 'A';
    int char3_hp = 44;
    int char3_atk = 17;
    int char3_def = 8;

    //角色4(自行輸入)
    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;

    //強度預測公式
    float hp_pd = 1.0;
    float atk_pd = 0.8;
    float def_pd = 0.5;
    //使錯誤兩次直接結束
    int is_error=0;
    int is_error1=0;
    int is_error2=0;
    //角色1數值
    printf("角色1\n"
           "名稱:aibo \n"
           "屬性:%c   攻擊:%d\n"
           "血量:%d  防禦:%d\n"
           ,char1_type,char1_atk,char1_hp,char1_def);

    printf("角色強度預測:%.2f\n\n",(char1_hp*hp_pd)+(char1_atk*atk_pd)+(char1_def*def_pd)-50);
    //角色2數值
    printf("角色2\n"
           "名稱:公道伯  \n"
           "屬性:%c   攻擊:%d\n"
           "血量:%d  防禦:%d\n"
           ,char2_type,char2_atk,char2_hp,char2_def);

    printf("角色強度預測:%.2f\n\n",(char2_hp*hp_pd)+(char2_atk*atk_pd)+(char2_def*def_pd)-50);
    //角色3數值
    printf("角色3\n"
           "名稱:滅滅子  \n"
           "屬性:%c   攻擊:%d  \n"
           "血量:%d  防禦:%d  \n"
           ,char3_type,char3_atk,char3_hp,char3_def);

    printf("角色強度預測:%.2f\n\n",(char3_hp*hp_pd)+(char3_atk*atk_pd)+(char3_def*def_pd)-50);


    int quest;

    //是否新增角色
    while(1) { //輸入錯誤的迴圈
        is_error=0; //flag歸回0
        printf("是否新增角色(1.Yes/2.No)? ");
        scanf("%d",&quest);
        if(quest !=1 && quest !=2) {
            printf("輸入錯誤\n");
            is_error=1;
        } else if(is_error==0) {
            break;
        }
    }

    getchar();
    //若選項選1，選擇創立角色4
    if(quest == 1) {
        while(1) {          //設置輸入錯誤的迴圈
            is_error = 0;   //將flag歸回0
            is_error1 = 0;
            printf("新增角色\n"
                   "角色名稱:自訂角色\n");
            printf("屬性:");
            scanf("%c",&char4_type);

            printf("血量:");
            scanf("%d",&char4_hp);

            printf("攻擊:");
            scanf("%d",&char4_atk);

            printf("防禦:");
            scanf("%d",&char4_def);
            getchar();
            //數值限制
            if(char4_type != 'F' && char4_type != 'W' && char4_type != 'G' && char4_type != 'A' &&
                    char4_type != 'f' && char4_type != 'w' && char4_type != 'g' && char4_type != 'a') {
                printf("錯誤:無此屬性\n"),is_error=1;
            }
            //將屬性小寫轉成大寫
            else if(char4_type == 'f') {
                char4_type = 'F';
            } else if(char4_type == 'w') {
                char4_type = 'W';
            } else if(char4_type == 'g') {
                char4_type = 'G';
            } else if(char4_type == 'a') {
                char4_type = 'A';
            }

            if(char4_hp >50 || char4_hp <40 ||
                    char4_atk >20 || char4_atk <15 ||
                    char4_def >10 ||  char4_def <5 || (char4_hp + char4_atk  + char4_def) >70 || (char4_hp + char4_atk  + char4_def) <65) {
                printf("錯誤:能力數值在限制範圍之外\n");
                is_error1=1;
            }
            //輸入有誤重新輸入的flag
            if(is_error==0 && is_error1==0) {
                break;
            }
        }



        //印出角色4數據
        printf("\n");

        printf("角色4\n"
               "名稱:自訂角色  \n"
               "屬性:%c   攻擊:%d  \n"
               "血量:%d  防禦:%d   \n"
               ,char4_type,char4_atk,char4_hp,char4_def);
        printf("角色強度預測:%.2f\n\n",(char4_hp*hp_pd)+(char4_atk*atk_pd)+(char4_def*def_pd)-50);
    }

    //若選項選2，直接進入選角環節

    else if(quest == 2) {
        quest = 0;   //將回應設成flag當加減
    }





    int player1;
    int player2;
    while(1) {  //重複角色輸入的迴圈

        while(1) {
            is_error2=0;
            printf("選擇先攻角色:");
            scanf("%d",&player1);
            if(player1 < 1 || player1 > 3 + quest) { //quest為有無角色4時數值是否增加
                printf("錯誤:無此角色\n");
                is_error2=1;
            }
            if(is_error2==0) {
                break;
            }
        }
        while(1) {
            is_error2=0;
            printf("選擇後攻角色:");
            scanf("%d",&player2);
            if(player2 < 1 || player2 > 3 + quest) {
                printf("錯誤:無此角色\n");
                is_error2=1;
            }
            if(is_error2==0) {
                break;
            }
        }

        is_error2=0;
        if(player1 == player2) {
            printf("錯誤:角色重複輸入\n",is_error2=1);
        }
        if(is_error2 == 0) {
            break;
        }

    }
    printf("先攻為角色%d、後攻為角色%d\n",player1,player2);
    printf("戰鬥開始\n\n");

    //將被選取的資料取出
    int first_hp,first_atk,first_def;
    int later_hp,later_atk,later_def;
    //先攻
    if(player1==1) {
        first_hp=char1_hp;
        first_atk=char1_atk;
        first_def=char1_def;
    } else if(player1==2) {
        first_hp=char2_hp;
        first_atk=char2_atk;
        first_def=char2_def;
    } else if(player1==3) {
        first_hp=char3_hp;
        first_atk=char3_atk;
        first_def=char3_def;
    } else if(player1==4) {
        first_hp=char4_hp;
        first_atk=char4_atk;
        first_def=char4_def;
    }
    //後攻
    if(player2==1) {
        later_hp=char1_hp;
        later_atk=char1_atk;
        later_def=char1_def;
    } else if(player2==2) {
        later_hp=char2_hp;
        later_atk=char2_atk;
        later_def=char2_def;
    } else if(player2==3) {
        later_hp=char3_hp;
        later_atk=char3_atk;
        later_def=char3_def;
    } else if(player2==4) {
        later_hp=char4_hp;
        later_atk=char4_atk;
        later_def=char4_def;
    }

    int damage,damage2;

    //戰鬥程序
    while(1) {
        damage = first_atk - later_def;    //先攻造成傷害
        damage2 = later_atk - first_def;   //後攻造成傷害
        //先攻角色攻擊
        printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n"
               "角色%d HP: %d 角色%d HP: %d\n\n",player1,player2,damage,player1,first_hp,player2,later_hp-(first_atk - later_def));
        later_hp = later_hp -(first_atk - later_def);   //後攻角色損血

        if(first_hp <= 0) { //血量歸0的驗證
            printf("角色%d 失去戰鬥能力\n"
                   "戰鬥結束\n\n"
                   "角色%d 獲勝",player1,player2);
            break;
        } else if(later_hp <= 0) {
            printf("角色%d 失去戰鬥能力\n"
                   "戰鬥結束\n\n"
                   "角色%d 獲勝",player2,player1);
            break;
        }
        //後攻角色攻擊
        printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n"
               "角色%d HP: %d 角色%d HP: %d\n\n",player2,player1,damage2,player1,first_hp-(later_atk - first_def),player2,later_hp);
        first_hp = first_hp - (later_atk - first_def);    //先攻角色損血

        if(first_hp <= 0) { //血量歸0的驗證
            printf("角色%d 失去戰鬥能力\n"
                   "戰鬥結束\n\n"
                   "角色%d 獲勝",player1,player2);
            break;
        } else if(later_hp <= 0) {
            printf("角色%d 失去戰鬥能力\n"
                   "戰鬥結束\n\n"
                   "角色%d 獲勝",player2,player1);
            break;
        }

    }
    return 0;
}







