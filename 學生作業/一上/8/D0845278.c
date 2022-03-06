#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
int main() {
    int playerchose;
    char char1_name [21]= "劍指蒼穹";
    char char2_name [21]= "敲血為凝";
    char char3_name [21]= "超鬼特工";
    char char4_name [21];
    char type[5]= {'0','W','A','F'};
    int hp[5];
    int atk[5];
    int def[5];
    float strongpre[4];
    int i,j,k;
    hp[1]= 50;
    hp[2]= 40;
    hp[3]= 45;
    atk[1]=15;
    atk[2]=20;
    atk[3]=17;
    def[1]=5;
    def[2]=8;
    def[3]=7;
    //強度預測 = ( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5
    strongpre[1]= (hp[1] * 1.0 + atk[1] * 0.8 + def[1] * 0.5-50) * 6.5 ;
    strongpre[2]= (hp[2] * 1.0 + atk[2] * 0.8 + def[2] * 0.5-50) * 6.5 ;
    strongpre[3] = (hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5-50) * 6.5 ;
    int addchar,first_atk_char,last_atk_char,addchar_flag=0,correctflag = 1;
    while(5) { //一直循環問題直到結束
        printf("1.新增或修改新增角色\n");
        printf("2.顯示所有角色資料\n");
        printf("3.戰鬥\n");
        printf("0.結束遊戲\n");
        printf("請選擇：");
        scanf("%d",&playerchose);
        printf("\n");
        if(playerchose==1) {
            if (addchar_flag==0) {
                do {
                    correctflag = 1; //初始flag
                    printf("新增角色\n");
                    printf("名稱:");
                    scanf("%s",&char4_name);
                    type[4]=getchar();
                    printf("類型(F=火、W=水、G=土、A=風):");
                    scanf("%c", &type[4]);
                    printf("血量(40~50):");
                    scanf("%d", &hp[4]);
                    printf("攻擊(15~20):");
                    scanf("%d", &atk[4]);
                    printf("防禦(5~10):");
                    scanf("%d", &def[4]);
                    if(type[4] != 'F' && type[4] != 'W' && type[4] != 'G' && type[4] != 'A' && type[4] != 'f' && type[4] != 'w' && type[4] != 'g' && type[4] != 'a') {
                        printf("錯誤：無此屬性\n");
                        correctflag = 0;
                    } else if(type[4] >= 'a')
                        type[4] -= 32;
                    int char4_total = hp[4] + atk[4] + def[4];
                    if(hp[4] < 40 || hp[4] > 50 || atk[4] < 15 || atk[4] > 20 || def[4] < 5 || def[4] > 10 || char4_total < 65 || char4_total > 70) {
                        printf("錯誤：能力數值在限制範圍之外\n\n");
                        correctflag = 0;
                    }
                } while(!correctflag);
                //計算新增角色的強度，並印出角色4的最終資訊
                strongpre[4] = (hp[4] * 1.0 + atk[4] * 0.8 + def[4] * 0.5-50) * 6.5;
                printf("\n角色4\n名稱:%s\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測:%.2f\n\n",char4_name,type[4],atk[4],hp[4],def[4],strongpre[4]);
                addchar_flag=1;
            } else if(addchar_flag==1) {
                do {
                    correctflag = 1; //初始flag
                    printf("修改新增角色\n");
                    printf("名稱:");
                    scanf("%s",&char4_name);
                    type[4] = getchar();
                    printf("類型(F=火、W=水、G=土、A=風):");
                    scanf("%c", &type[4]);
                    printf("血量(40~50):");
                    scanf("%d", &hp[4]);
                    printf("攻擊(15~20):");
                    scanf("%d", &atk[4]);
                    printf("防禦(5~10):");
                    scanf("%d", &def[4]);
                    if(type[4] != 'F' && type[4] != 'W' && type[4] != 'G' && type[4] != 'A' && type[4] != 'f' && type[4] != 'w' && type[4] != 'g' && type[4] != 'a') {
                        printf("錯誤：無此屬性\n");
                        correctflag = 0;
                    } else if(type[4] >= 'a')
                        type[4] -= 32;
                    int char4_total = hp[4] + atk[4] + def[4];
                    if(hp[4] < 40 || hp[4] > 50 || atk[4] < 15 || atk[4] > 20 || def[4] < 5 || def[4] > 10 || char4_total < 65 || char4_total > 70) {
                        printf("\n錯誤：能力數值在限制範圍之外\n\n");
                        correctflag = 0;
                    }
                } while(!correctflag);
                //計算新增角色的強度，並印出角色4的最終資訊
                strongpre[4] = (hp[4] * 1.0 + atk[4] * 0.8 + def[4] * 0.5-50) * 6.5;
                printf("\n角色4\n名稱:%s\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測:%.2f\n\n",char4_name,type[4],atk[4],hp[4],def[4],strongpre[4]);
                addchar_flag=1;//紀錄是否有角色4
            }
        } else if(playerchose==2) {
            if(addchar_flag==0) { //沒有角色4
                printf("角色1\n名稱:%s\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測:%.2f\n\n",char1_name,type[1],atk[1],hp[1],def[1],strongpre[1]);
                printf("角色2\n名稱:%s\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測:%.2f\n\n",char2_name,type[2],atk[2],hp[2],def[2],strongpre[2]);
                printf("角色3\n名稱:%s\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測:%.2f\n\n",char3_name,type[3],atk[3],hp[3],def[3],strongpre[3]);
            } else if (addchar_flag==1) { //有角色4
                printf("角色1\n名稱:%s\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測:%.2f\n\n",char1_name,type[1],atk[1],hp[1],def[1],strongpre[1]);
                printf("角色2\n名稱:%s\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測:%.2f\n\n",char2_name,type[2],atk[2],hp[2],def[2],strongpre[2]);
                printf("角色3\n名稱:%s\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測:%.2f\n\n",char3_name,type[3],atk[3],hp[3],def[3],strongpre[3]);
                printf("角色4\n名稱:%s\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測:%.2f\n\n",char4_name,type[4],atk[4],hp[4],def[4],strongpre[4]);
            }
        } else if(playerchose==3) {
            do {
                do {
                    printf("選擇先攻角色:");
                    first_atk_char = getchar();
                    scanf("%d",&first_atk_char);
                    if(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3&&first_atk_char!=4)  //一旦輸入並非已定義角色，輸出錯誤
                        printf("錯誤:無此角色\n");
                } while(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3&&first_atk_char!=4);
                do {
                    printf("選擇後攻角色:");
                    last_atk_char = getchar();
                    scanf("%d",&last_atk_char);
                    if(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3&&last_atk_char!=4)  //一旦輸入並非已定義角色，輸出錯誤
                        printf("錯誤:無此角色\n");
                } while(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3&&last_atk_char!=4);
                if(first_atk_char==last_atk_char)   //一旦先攻角色等於後攻角色，輸出錯誤
                    printf("錯誤:不可重複選取\n");
            } while(first_atk_char==last_atk_char);
            printf("\n先攻角色為%d ，後攻角色為%d\n",first_atk_char,last_atk_char);  //印出最終輸入
            printf("開始戰鬥\n\n");
            //新增儲存資訊的變數
            int first_atk_hp=0,first_atk_atk=0,first_atk_def=0,last_atk_hp=0,last_atk_atk=0,last_atk_def=0,round = 0;//設定最初回合為0
            char first_atk_type,last_atk_type;
            //判斷輸入的角色，把資料輸入暫存裡
            if(first_atk_char == 1) {
                first_atk_type = type[1];
                first_atk_hp = hp[1];
                first_atk_atk = atk[1];
                first_atk_def = def[1];
            } else if (first_atk_char == 2) {
                first_atk_type = type[2];
                first_atk_hp = hp[2];
                first_atk_atk = atk[2];
                first_atk_def = def[2];
            } else if (first_atk_char ==3) {
                first_atk_type = type[3];
                first_atk_hp = hp[3];
                first_atk_atk = atk[3];
                first_atk_def = def[3];
            } else if (first_atk_char ==4) {
                first_atk_type = type[4];
                first_atk_hp = hp[4];
                first_atk_atk = atk[4];
                first_atk_def = def[4];
            }
            if(last_atk_char == 1) {
                last_atk_type = type[1];
                last_atk_hp = hp[1];
                last_atk_atk = atk[1];
                last_atk_def = def[1];
            } else if (last_atk_char == 2) {
                last_atk_type = type[2];
                last_atk_hp = hp[2];
                last_atk_atk = atk[2];
                last_atk_def = def[2];
            } else if (last_atk_char == 3) {
                last_atk_type = type[3];
                last_atk_hp = hp[3];
                last_atk_atk = atk[3];
                last_atk_def = def[3];
            } else if (last_atk_char == 4) {
                last_atk_type = type[4];
                last_atk_hp = hp[4];
                last_atk_atk = atk[4];
                last_atk_def = def[4];
            }
            //攻擊傷害 = (int)(攻擊方攻擊力 * 相剋倍率 * 殘血倍率 - 被攻擊方防禦力)
            //屬性相剋倍率：屬性關係W>F>A>G>W
            //若為相剋關係：優勢者1.2倍，劣勢者0.8倍,若雙方無相剋則攻擊力各為1.0倍
            //殘血倍率：攻擊方血量小於原本的50%時殘血倍率為1.2倍
            float firstatkhurt=first_atk_atk;//先攻攻擊力
            float lastatkhurt=last_atk_atk;//後攻攻擊力
            int max_first_atk_hp = first_atk_hp;
            int max_last_atk_hp = last_atk_hp;
            while(first_atk_char> 0||last_atk_char> 0) {
                //攻擊傷害 = 攻擊方攻擊力*相剋倍率*殘血倍率 - 被攻擊方防禦力
                if((first_atk_type=='W'&&last_atk_type=='F')||(first_atk_type=='F'&&last_atk_type=='A')||
                        (first_atk_type=='A'&&last_atk_type=='G')||(first_atk_type=='G'&&last_atk_type=='W'))
                    firstatkhurt = first_atk_atk*1.2;
                else if((last_atk_type=='W'&&first_atk_type=='F')||(last_atk_type=='F'&&first_atk_type=='A')||
                        (last_atk_type=='A'&&first_atk_type=='G')||(last_atk_type=='G'&&first_atk_type=='W'))
                    lastatkhurt = last_atk_atk*1.2;
                else if((first_atk_type=='F'&&last_atk_type=='W')||(first_atk_type=='A'&&last_atk_type=='F')||
                        (first_atk_type=='G'&&last_atk_type=='A')||(first_atk_type=='W'&&last_atk_type=='G'))
                    firstatkhurt = first_atk_atk*0.8;
                else if((last_atk_type=='F'&&first_atk_type=='W')||(last_atk_type=='A'&&first_atk_type=='F')||
                        (last_atk_type=='G'&&first_atk_type=='A')||(last_atk_type=='W'&&first_atk_type=='G'))
                    lastatkhurt = last_atk_atk*0.8;
                //判斷第幾回合以讓先後攻順序交換
                if(round%2==0) {
                    if(first_atk_hp<(0.5 * max_first_atk_hp))//判斷殘寫倍率
                        firstatkhurt = firstatkhurt*1.2;
                    int finalfirstatkhurt = firstatkhurt-last_atk_def;//減掉防禦力
                    printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",first_atk_char,last_atk_char,finalfirstatkhurt);
                    last_atk_hp = last_atk_hp - finalfirstatkhurt;
                    printf("角色%d HP: %d 角色%d HP: %d\n\n",first_atk_char,first_atk_hp,last_atk_char,last_atk_hp);
                } else if(round%2==1) {
                    if(last_atk_hp<(0.5 * max_last_atk_hp))
                        lastatkhurt=lastatkhurt*1.2;
                    int finallastatkhurt = lastatkhurt-first_atk_def;
                    printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",last_atk_char,first_atk_char,finallastatkhurt);
                    first_atk_hp = first_atk_hp - finallastatkhurt;
                    printf("角色%d HP: %d 角色%d HP: %d\n\n",first_atk_char,first_atk_hp,last_atk_char,last_atk_hp);
                }
                round++;//執行一次迴圈多一回合
                if(first_atk_hp<=0) {
                    printf("角色%d 失去戰鬥能力\n",first_atk_char);
                    printf("戰鬥結束\n");
                    printf("\n角色%d 獲勝\n\n",last_atk_char);
                    break;//一旦角色沒血顯示訊息後結束迴圈
                } else if(last_atk_hp<=0) {
                    printf("角色%d 失去戰鬥能力\n",last_atk_char);
                    printf("戰鬥結束\n");
                    printf("\n角色%d 獲勝\n\n",first_atk_char);
                    break;//一旦角色沒血顯示訊息後結束迴圈
                }
            }
        } else if(playerchose==0) {
            printf("結束遊戲\n");
            return 0;
        } else
            printf("輸入錯誤！\n\n");
    }
    return 0;
}
