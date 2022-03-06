#include<stdio.h>
#include<stdlib.h>
int main() {
    //角色1
    char char1_type = 'W';
    int char1_hp = 45;
    int char1_atk = 18;
    int char1_def = 6;
    float char1=(char1_hp* 1.0 + char1_atk* 0.8 + char1_def* 0.5 - 50 ) * 6.5;
    //角色2
    char char2_type = 'G';
    int char2_hp = 43;
    int char2_atk = 17;
    int char2_def = 5;
    float char2=(char2_hp* 1.0 + char2_atk* 0.8 + char2_def* 0.5 - 50 ) * 6.5;
    //角色3
    char char3_type = 'A';
    int char3_hp = 48;
    int char3_atk = 15;
    int char3_def = 7;
    float char3=(char3_hp* 1.0 + char3_atk* 0.8 + char3_def* 0.5 - 50 ) * 6.5;


    printf("角色1\n名稱:雷利\n屬性:W    攻擊:18\n血量:45   防禦:6\n角色強度預測:%.2f\n"
           "角色2\n名稱:阿呼\n屬性:G    攻擊:17\n血量:43   防禦:5\n角色強度預測:%.2f\n"
           "角色3\n名稱:布榖\n屬性:A    攻擊:15\n血量:48   防禦:7\n角色強度預測:%.2f\n",char1,char2,char3
          );
    //自訂角色
    char char4_type ;
    int char4_hp ;
    int char4_atk ;
    int char4_def ;
    int hurt1; //先攻擊方造成的傷害
    int hurt2; //後攻擊方造成的傷害
    int char5; //先攻角色的變數
    int char5_hp ;
    int char5_atk ;
    int char5_def ;
    int char6;   //後攻角色的變數
    int char6_hp  ;
    int char6_atk ;
    int char6_def ;
    int fall; //條件輸入錯誤
    int ans; //回答是否新增角色

    do {
        printf("是否新增新角色(1.yes/2.no)?");
        scanf("%d",&ans);
        if(ans==1) {
            do {
                printf("新增角色\n");
                printf("請輸入屬性(F=火、W=水、G=土、A=風):");
                scanf(" %c",&char4_type);
                printf("請輸入攻擊力:");
                scanf("%d",&char4_atk);
                printf("請輸入血量:");
                scanf("%d",&char4_hp);
                printf("請輸入防禦力:");
                scanf("%d",&char4_def);
                int sum=char4_hp+char4_atk+char4_def; //角色數值總和
                if((char4_type=='F'||char4_type=='W'||char4_type=='G'||char4_type=='A')&&(char4_atk>15&&char4_atk<20)&&(char4_hp<50&&char4_hp>40)&&(char4_def>5&&char4_def<10)&&(sum<70&&sum>65)) { //若屬性為大寫 且能力數值皆和能力範圍皆正確
                    printf("自訂角色\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測:%.2f\n",char4_type,char4_atk,char4_hp,char4_def, (char4_hp* 1.0 + char4_atk* 0.8 + char4_def* 0.5 - 50 ) * 6.5);
                    fall=1;
                    break;
                } else if((char4_type==102||char4_type==119||char4_type==103||char4_type==97)&&(char4_atk>15&&char4_atk<20)&&(char4_hp<50&&char4_hp>40)&&(char4_def>5&&char4_def<10)&&(sum<70&&sum>65)) { //若屬性為小寫 且能力數值皆和能力範圍皆正確
                    printf("自訂角色\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測:%.2f\n",char4_type-32,char4_atk,char4_hp,char4_def, (char4_hp* 1.0 + char4_atk* 0.8 + char4_def* 0.5 - 50 ) * 6.5);
                    fall=1;
                    break;
                } else if((char4_type=='f'||char4_type=='w'||char4_type=='g'||char4_type=='a'||char4_type=='F'||char4_type=='W'||char4_type=='G'||char4_type=='A')&&((char4_atk<15||char4_atk>20)||(char4_hp>50||char4_hp<40)||(char4_def<5||char4_def>10)||(sum>=70||sum<=65))) {
                    printf("錯誤:能力數值在限制範圍之外\n"); //若屬性輸入正確 但能力數值或能力範圍有錯
                    fall=0;
                } else if((char4_type!='f'||char4_type!='w'||char4_type!='g'||char4_type!='a'||char4_type!='F'||char4_type!='W'||char4_type!='G'||char4_type!='A')&&((char4_atk<15||char4_atk>20)||(char4_hp>50||char4_hp<40)||(char4_def<5||char4_def>10)||(sum>=70||sum<=65))) {
                    printf("錯誤:無此屬性\n錯誤:能力數值在限制範圍之外\n"); // //若屬性輸入不正確 且能力數值或能力範圍有錯
                    fall=0;
                } else if((char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a'&&char4_type!='F'&&char4_type!='W'&&char4_type!='G'&&char4_type!='A')&&((char4_atk>15||char4_atk<20)||(char4_hp<50||char4_hp>40)||(char4_def>5||char4_def<10)||(sum<70||sum>65))) {
                    printf("錯誤:無此屬性\n"); // //若屬性輸入不正確 但能力數值和能力範圍正確
                    fall=0;
                }
            } while(fall==0);
        }
        if(ans==2) {
            do {
                fall=1;
                printf("選擇先攻角色:");
                scanf("%d",&char5);
                if (1<=char5&&char5<=3) { //若角色數字輸入正確
                    do {
                        printf("選擇後攻角色:");
                        scanf("%d",&char6);
                        if(char5==char6) { //若角色相同
                            printf("不可重複選取\n");
                            fall=0;
                        } else if (1<=char6&&char6<=3) { // 若角色數字輸入正確 且角色不相同
                            printf("先攻為角色%d、後攻角色為%d\n",char5,char6);
                            switch(char5) {
                            case 1: //若輸入為1
                                char5_hp= char1_hp;
                                char5_atk= char1_atk;
                                char5_def= char1_def;
                                break;
                            case 2: //若輸入為2
                                char5_hp= char2_hp;
                                char5_atk= char2_atk;
                                char5_def= char2_def;
                                break;
                            case 3: //若輸入為3
                                char5_hp= char3_hp;
                                char5_atk= char3_atk;
                                char5_def= char3_def;
                                break;
                            case 4: //若輸入為4
                                char5_hp= char4_hp;
                                char5_atk= char4_atk;
                                char5_def= char4_def;
                                break;
                            }
                            switch(char6) {
                            case 1: //若輸入為1
                                char6_hp= char1_hp;
                                char6_atk= char1_atk;
                                char6_def= char1_def;
                                break;
                            case 2: //若輸入為2
                                char6_hp= char2_hp;
                                char6_atk= char2_atk;
                                char6_def= char2_def;
                                break;
                            case 3: //若輸入為3
                                char6_hp= char3_hp;
                                char6_atk= char3_atk;
                                char6_def= char3_def;
                                break;
                            case 4: //若輸入為4
                                char6_hp= char4_hp;
                                char6_atk= char4_atk;
                                char6_def= char4_def;
                                break;
                            }
                            printf("戰鬥開始\n");
                            while(char5_hp>0) {
                                hurt1=char5_atk-char6_def; //先攻的攻擊傷害數值
                                char6_hp=char6_hp-hurt1;//後攻被攻擊後的血量
                                printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",char5,char6,hurt1);
                                printf("角色 %d HP:%d 角色 %d HP:%d\n",char5,char5_hp,char6,char6_hp);
                                if(char6_hp>0) {
                                    hurt2=char6_atk-char5_def; //後攻的攻擊傷害數值
                                    char5_hp=char5_hp-hurt2;//先攻被攻擊後的血量
                                    printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",char6,char5,hurt2);
                                    printf("角色 %d HP:%d 角色 %d HP:%d\n",char6,char6_hp,char5,char5_hp);
                                    continue;
                                } else
                                    printf("角色 %d 失去戰鬥力\n戰鬥結束\n\n角色 %d 獲勝\n",char6,char5);
                                return 0;
                            }
                        } else //輸入無關的符號
                            printf("錯誤:無此角色\n");
                        fall=0;
                    } while(fall==0);
                }

                else //輸入無關的符號
                    printf("錯誤:無此角色\n");
                fall=0;
            } while(fall==0);
        } else if(ans>2) { //輸入錯誤指示
            printf("輸入錯誤\n");
            fall=0;
        }
    } while(fall==0);


    do {
        printf("選擇先攻角色:");
        scanf("%d",&char5);
        if (1<=char5&&char5<=4) { //若角色數字輸入正確
            do {
                printf("選擇後攻角色:");
                scanf("%d",&char6);
                if(char5==char6) { //若角色相同
                    printf("不可重複選取\n");
                    fall=0;
                } else if (1<=char6&&char6<=4) { // 若角色數字輸入正確 且角色不相同
                    printf("先攻為角色%d、後攻角色為%d\n",char5,char6);
                    switch(char5) {
                    case 1: //若輸入為1
                        char5_hp= char1_hp;
                        char5_atk= char1_atk;
                        char5_def= char1_def;
                        break;
                    case 2: //若輸入為2
                        char5_hp= char2_hp;
                        char5_atk= char2_atk;
                        char5_def= char2_def;
                        break;
                    case 3: //若輸入為3
                        char5_hp= char3_hp;
                        char5_atk= char3_atk;
                        char5_def= char3_def;
                        break;
                    case 4: //若輸入為4
                        char5_hp= char4_hp;
                        char5_atk= char4_atk;
                        char5_def= char4_def;
                        break;
                    }
                    switch(char6) {
                    case 1: //若輸入為1
                        char6_hp= char1_hp;
                        char6_atk= char1_atk;
                        char6_def= char1_def;
                        break;
                    case 2: //若輸入為2
                        char6_hp= char2_hp;
                        char6_atk= char2_atk;
                        char6_def= char2_def;
                        break;
                    case 3: //若輸入為3
                        char6_hp= char3_hp;
                        char6_atk= char3_atk;
                        char6_def= char3_def;
                        break;
                    case 4: //若輸入為4
                        char6_hp= char4_hp;
                        char6_atk= char4_atk;
                        char6_def= char4_def;
                        break;
                    }
                    printf("戰鬥開始\n");
                    while(char5_hp>0) { //當先攻血量大於0
                        hurt1=char5_atk-char6_def; //先攻的攻擊傷害數值
                        char6_hp=char6_hp-hurt1;//後攻被攻擊後的血量
                        printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",char5,char6,hurt1);
                        printf("角色 %d HP:%d 角色 %d HP:%d\n",char5,char5_hp,char6,char6_hp);
                        if(char6_hp>0) { //如果後攻血量大於0
                            hurt2=char6_atk-char5_def; //後攻的攻擊傷害數值
                            char5_hp=char5_hp-hurt2;//先攻被攻擊後的血量
                            printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",char6,char5,hurt2);
                            printf("角色 %d HP:%d 角色 %d HP:%d\n",char6,char6_hp,char5,char5_hp);
                            continue;
                        } else
                            printf("角色 %d 失去戰鬥力\n戰鬥結束\n\n角色 %d 獲勝\n",char6,char5);
                        return 0;
                    }
                } else //輸入無關的符號
                    printf("錯誤:無此角色\n");
                fall=0;
            } while(fall==0);
        }

        else //輸入無關的符號
            printf("錯誤:無此角色\n");
        fall=0;
    } while(fall==0);

    return 0;
}

