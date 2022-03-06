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
    printf("是否新增角色(1.Yes/2.No)? ");

    scanf("%d",&quest);
    getchar();
    //若選項選1，選擇創立角色4
    if(quest == 1) {
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
                char4_def >10 ||  char4_def <5) {
            printf("錯誤:能力數值在限制範圍之外");
            return 0;
        }
        if((char4_hp + char4_atk  + char4_def) >70 || (char4_hp + char4_atk  + char4_def) <65 ) {
            printf("錯誤:能力數值在限制範圍之外");
            return 0;
        }
        if(is_error==1) {
            return 0;
        }

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
        int player1;
        int player2;

        printf("選擇先攻角色:");
        scanf("%d",&player1);
        if(player1 !=1 &&  player1 !=2 && player1 !=3) { //只可選擇角色1,2,3
            printf("此角色不存在");
            return 0;
        }

        printf("選擇後攻角色:");
        scanf("%d",&player2);
        if(player2 !=1 &&  player2 !=2 && player2 !=3) { //只可選擇角色1,2,3
            printf("此角色不存在");
            return 0;
        }

        if(player1 == player2) {                        //角色不可重複
            printf("不可重複選取");
            return 0;
        }

        printf("先攻為角色%d、後攻為角色為%d",player1,player2);
        return 0;
    }

    //輸入錯誤時

    else if(quest !=1 & quest !=2) {
        printf("輸入錯誤");
        return 0;
    }

    //角色4加入時選角環節

    int player1;
    int player2;

    printf("選擇先攻角色:");
    scanf("%d",&player1);
    if(player1 !=1 &&  player1 !=2 && player1 !=3 && player1 !=4) { //只可選擇角色1,2,3,4
        printf("此角色不存在");
        return 0;
    }

    printf("選擇後攻角色:");
    scanf("%d",&player2);
    if(player2 !=1 &&  player2 !=2 && player2 !=3&& player2 !=4) {  //只可選擇角色1,2,3,4
        printf("此角色不存在");
        return 0;
    }

    if(player1 == player2) {                                        //角色不可重複
        printf("不可重複選取");
        return 0;
    }

    printf("先攻為角色%d、後攻為角色為%d",player1,player2);
    return 0;



    return 0;

}
