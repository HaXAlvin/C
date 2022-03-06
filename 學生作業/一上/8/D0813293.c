#include<stdio.h>
#include<stdlib.h>

int main() {
    //char1=小狗育軒
    char char1_name[24] = "小狗育軒";
    char char1_type[7] = {"W"};
    int char1_atk[7] = {15};
    int char1_hp[7] = {50};
    int char1_def[7] = {5};
    //角色強度預測
    float char1_predict[7]= {(char1_hp[0] * 1 + char1_atk[0] * 0.8 + char1_def[0] * 0.5 - 50) * 6.5};
    //char2=小豬哲瑋
    char char2_name[24] = {"小豬哲瑋"};
    char char2_type[7] = {"F"};
    int char2_atk[7] = {18};
    int char2_hp[7] = {47};
    int char2_def[7] = {5};
    //角色強度預測
    float char2_predict[7] = {(char2_hp[0] * 1 + char2_atk[0] * 0.8 + char2_def[0] * 0.5 - 50) * 6.5};
    //char3=韓家軍劭詳
    char chae3_name[24] = {"韓家軍劭詳"};
    char char3_type[7] = {"A"};
    int char3_atk[7] = {15};
    int char3_hp[7] = {45};
    int char3_def[7] = {7};
    //角色強度預測
    float char3_predict[7] = {(char3_hp[0] * 1 + char3_atk[0] * 0.8 + char3_def[0] * 0.5 - 50) * 6.5};
    //新增角色1=newchar1
    char newchar1_name[24];
    char newchar1_type[7];
    int newchar1_atk[7] = {0};
    int newchar1_hp[7] = {0};
    int newchar1_def[7] = {0};
    //新增角色強度預測
    float newchar1_predict;
    int cho;//選擇戰鬥前選項
    //屬性克制
    float addchar1_ret=1;
    float addchar2_ret=1;
    //殘血倍率
    float addchar1_jca=1;
    float addchar2_jca=1;
    int addchar1=0;//先攻
    int addchar2=0;//後攻
    //新增暫存角色儲存對戰資料
    int addchar1_type[7];
    int addchar1_atk[7] = {0};
    int addchar1_hp[7] = {0};
    int addchar1_def[7] = {0};
    int addchar2_type[7];
    int addchar2_atk[7] = {0};
    int addchar2_hp[7] = {0};
    int addchar2_def[7] = {0};
    //判斷半血
    int char1hp_helf;
    int char2hp_helf;
    int val=0;//判斷有無新增過角色
    int count=3;//計算目前幾個角色
    //選擇遊戲開始前選項
    while(1) {
        printf("\n1. 新增或修改新增角色\n");
        printf("2. 顯示所有角色資料\n");
        printf("3. 戰鬥\n");
        printf("0. 結束遊戲\n\n");
        printf("請選擇 : ");
        scanf("%d",&cho);
        if(cho == 2) { //顯示目前資訊
            printf("\n角色1\n名稱:小狗育軒\n");
            printf("屬性:%c\t攻擊:%d\n",char1_type[0],char1_atk[0]);
            printf("血量:%d\t防禦:%d\n",char1_hp[0],char1_def[0]);
            printf("角色強度預測:%.2f\n\n",char1_predict[0]);
            printf("角色2\n名稱:小豬哲瑋\n");
            printf("屬性:%c\t攻擊:%d\n",char2_type[0],char2_atk[0]);
            printf("血量:%d\t防禦:%d\n",char2_hp[0],char2_def[0]);
            printf("角色強度預測:%.2f\n\n",char2_predict[0]);
            printf("角色3\n名稱:韓家軍劭詳\n");
            printf("屬性:%c\t攻擊:%d\n",char3_type[0],char3_atk[0]);
            printf("血量:%d\t防禦:%d\n",char3_hp[0],char3_def[0]);
            printf("角色強度預測:%.2f\n\n",char3_predict[0]);
        } else if(cho == 1) { //若選擇新增角色，則顯示新增輸入資訊
            while(1) {
                if(val==0) {
                    count = 4;//計算目前角色
                    printf("\n新增角色\n名稱:");
                    scanf("%s",&newchar1_name);
                    printf("屬性:");
                    scanf(" %c", &newchar1_type[0]);
                    printf("攻擊:");
                    scanf("%d",&newchar1_atk[0]);
                    printf("血量:");
                    scanf("%d", &newchar1_hp[0]);
                    printf("防禦:");
                    scanf("%d",&newchar1_def[0]);
                } else if(val>0) {
                    printf("\n修改新增角色\n名稱:");
                    scanf("%s",&newchar1_name);
                    printf("屬性:");
                    scanf(" %c", &newchar1_type[0]);
                    printf("攻擊:");
                    scanf("%d",&newchar1_atk[0]);
                    printf("血量:");
                    scanf("%d", &newchar1_hp[0]);
                    printf("防禦:");
                    scanf("%d",&newchar1_def[0]);
                }
                //轉換大小寫
                if (newchar1_type[0]== 'f' ) {
                    newchar1_type[0]= 'F';
                } else if(newchar1_type[0]== 'w' ) {
                    newchar1_type[0]= 'W';
                } else if(newchar1_type[0]== 'g' ) {
                    newchar1_type[0]= 'G';
                } else if(newchar1_type[0]== 'a' ) {
                    newchar1_type[0]= 'A';
                } else if(newchar1_type[0]== 'F' ) {
                    newchar1_type[0]= 'F';
                } else if(newchar1_type[0]== 'W' ) {
                    newchar1_type[0]= 'W';
                } else if(newchar1_type[0]== 'G' ) {
                    newchar1_type[0]= 'G';
                } else if(newchar1_type[0]== 'A' ) {
                    newchar1_type[0]= 'A';
                } else {
                    printf("錯誤: 無此屬性\n");
                }
                //判斷角色數值
                if((newchar1_atk[0] < 15)|(newchar1_atk[0] > 20)) {
                    printf("錯誤 : 能力數值在範圍之外\n");
                } else if((newchar1_hp[0] < 40)|(newchar1_hp[0] > 50)) {
                    printf("錯誤 : 能力數值在範圍之外\n");
                } else if((newchar1_def[0] < 5)|(newchar1_def[0] > 10)) {
                    printf("錯誤 : 能力數值在範圍之外\n");
                } else if(((newchar1_hp[0] + newchar1_atk[0] + newchar1_def[0])< 65 )|((newchar1_hp[0] + newchar1_atk[0] + newchar1_def[0])> 70 )) {
                    printf("錯誤 : 能力數值在範圍之外\n");
                } else {
                    val = val +1;
                    break;
                }
            }

            //新增角色預測強度
            float newchar1_predict[7] = {(newchar1_hp[0] * 1 + newchar1_atk[0] * 0.8 + newchar1_def[0] * 0.5 - 50) * 6.5};
            //新增角色資訊
            printf("\n角色4\n名稱:%s\n屬性:%c\n攻擊:%d\n血量:%d\n防禦:%d\n角色強度預測:%.2f\n\n"
                   ,newchar1_name,newchar1_type[0],newchar1_atk[0],newchar1_hp[0],newchar1_def[0],newchar1_predict[0]);
        }
        //選擇攻擊順序
        else if(cho == 3) {
            while(1) {
                printf("\n選擇先攻角色: ");
                scanf("%d",&addchar1);
                if((addchar1>count)|(addchar1<1)) {
                    printf("錯誤: 無此角色\n");
                } else {
                    break;
                }
            }
            while(1) { //重新輸入迴圈
                printf("選擇後攻角色: ");
                scanf("%d",&addchar2);
                if((addchar2>count)|(addchar2<1)) {
                    printf("錯誤: 無此角色\n");
                } else if((addchar2<=count)&(addchar2>=1)) {
                    if(addchar2 == addchar1) {
                        printf("錯誤: 不可重複選取\n");
                    } else {
                        printf("\n先攻為角色%d、後攻為角色%d\n",addchar1,addchar2);
                        printf("戰鬥開始\n");
                        break;
                    }
                }
            }
            //設定暫存角色的角色資料
            if(addchar1==1) {
                addchar1_atk[0]=char1_atk[0],addchar1_hp[0]=char1_hp[0],addchar1_def[0]=char1_def[0],addchar1_type[0]=char1_type[0];
            } else if(addchar1==2) {
                addchar1_atk[0]=char2_atk[0],addchar1_hp[0]=char2_hp[0],addchar1_def[0]=char2_def[0],addchar1_type[0]=char2_type[0];
            } else if(addchar1==3) {
                addchar1_atk[0]=char3_atk[0],addchar1_hp[0]=char3_hp[0],addchar1_def[0]=char3_def[0],addchar1_type[0]=char3_type[0];
            } else if(addchar1==4) {
                addchar1_atk[0]=newchar1_atk[0],addchar1_hp[0]=newchar1_hp[0],addchar1_def[0]=newchar1_def[0],addchar1_type[0]=newchar1_type[0];
            }
            if(addchar2==1) {
                addchar2_atk[0]=char1_atk[0],addchar2_hp[0]=char1_hp[0],addchar2_def[0]=char1_def[0],addchar2_type[0]=char1_type[0];
            } else if(addchar2==2) {
                addchar2_atk[0]=char2_atk[0],addchar2_hp[0]=char2_hp[0],addchar2_def[0]=char2_def[0],addchar2_type[0]=char2_type[0];
            } else if(addchar2==3) {
                addchar2_atk[0]=char3_atk[0],addchar2_hp[0]=char3_hp[0],addchar2_def[0]=char3_def[0],addchar2_type[0]=char3_type[0];
            } else if(addchar2==4) {
                addchar2_atk[0]=newchar1_atk[0],addchar2_hp[0]=newchar1_hp[0],addchar2_def[0]=newchar1_def[0],addchar2_type[0]=newchar1_type[0];
            }
            if((addchar1_type[0]=='W')&&(addchar2_type[0]=='F')) {
                addchar1_ret = 1.2;
                addchar2_ret = 0.8;
            } else if((addchar1_type[0]=='F')&&(addchar2_type[0]=='A')) {
                addchar1_ret = 1.2;
                addchar2_ret = 0.8;
            } else if((addchar1_type[0]=='A')&&(addchar2_type[0]=='G')) {
                addchar1_ret = 1.2;
                addchar2_ret = 0.8;
            } else if((addchar1_type[0]=='G')&&(addchar2_type[0]=='W')) {
                addchar1_ret = 1.2;
                addchar2_ret = 0.8;
            } else if((addchar1_type[0]=='F')&&(addchar2_type[0]=='W')) {
                addchar1_ret = 0.8;
                addchar2_ret = 1.2;
            } else if((addchar1_type[0]=='A')&&(addchar2_type[0]=='F')) {
                addchar1_ret = 0.8;
                addchar2_ret = 1.2;
            } else if((addchar1_type[0]=='G')&&(addchar2_type[0]=='A')) {
                addchar1_ret = 0.8;
                addchar2_ret = 1.2;
            } else if((addchar1_type[0]=='W')&&(addchar2_type[0]=='G')) {
                addchar1_ret = 0.8;
                addchar2_ret = 1.2;
            }
            if(addchar1_hp[0]<char1hp_helf/2) {
                addchar1_jca = 1.2;
            }
            if(addchar2_hp[0]<char2hp_helf/2) {
                addchar2_jca = 1.2;
            }
            char2hp_helf=addchar2_hp[0];
            char1hp_helf=addchar1_hp[0];
            //戰鬥迴圈
            while(1) {
                printf("\n角色%d 對 角色%d 發動攻擊，造成%.llf點傷害\n",addchar1,addchar2,(addchar1_atk[0]*addchar1_ret*addchar1_jca-addchar2_def[0]));
                addchar2_hp[0]=addchar2_hp[0]-(addchar1_atk[0]*addchar1_ret*addchar1_jca-addchar2_def[0]);
                printf("角色%d HP: %d 角色%d HP: %d\n\n",addchar1,addchar1_hp[0],addchar2,addchar2_hp[0]);
                if(addchar2_hp[0]<=0) {
                    printf("\n角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n",addchar2,addchar1);
                    break;
                }
                printf("角色%d 對 角色%d 發動攻擊，造成%.llf點傷害\n",addchar2,addchar1,(addchar2_atk[0]*addchar2_ret*addchar2_jca-addchar1_def[0]));
                addchar1_hp[0]=addchar1_hp[0]-(addchar2_atk[0]*addchar2_ret*addchar2_jca-addchar1_def[0]);
                printf("角色%d HP: %d 角色%d HP: %d\n",addchar1,addchar1_hp[0],addchar2,addchar2_hp[0]);
                if(addchar1_hp[0]<=0) {
                    printf("\n角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n",addchar1,addchar2);
                    break;
                }
            }
        } else if(cho == 0) {
            printf("\n結束遊戲\n");
            return 0;
        } else {
            printf("\n輸入錯誤!\n\n");
        }
    }
}

