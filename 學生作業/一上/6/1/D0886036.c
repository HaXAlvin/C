#include <stdio.h>
#include <stdlib.h>


int main() {
    char ch1_type= 'F';
    int ch1_hp=46;
    int ch1_attack=17;
    int ch1_defense=7;

    printf("角色一\n");
    printf("角色名稱:阿泰\n");
    printf("屬性:%c    ",ch1_type);
    printf("攻擊:%d\n",ch1_attack);
    printf("血量:%d   ",ch1_hp);
    printf("防禦:%d\n",ch1_defense);
    printf("角色預測強度:%.2f\n\n",((ch1_hp*1)+(ch1_attack*0.8)+(ch1_defense*0.5)-50)*6.5);
    printf("\n");

    char ch2_type= 'W';
    int ch2_hp=45;
    int ch2_attack=16;
    int ch2_defense=8;

    printf("角色二\n");
    printf("角色名稱:阿禎\n");
    printf("屬性:%c    ",ch2_type);
    printf("攻擊:%d\n",ch2_attack);
    printf("血量:%d   ",ch2_hp);
    printf("防禦:%d\n",ch2_defense);
    printf("角色預測強度:%.2f\n\n",((ch2_hp*1)+(ch2_attack*0.8)+(ch2_defense*0.5)-50)*6.5);
    printf("\n");

    char ch3_type= 'G';
    int ch3_hp=43;
    int ch3_attack=19;
    int ch3_defense=6;

    printf("角色三\n");
    printf("角色名稱:阿澤\n");
    printf("屬性:%c    ",ch3_type);
    printf("攻擊:%d\n",ch3_attack);
    printf("血量:%d   ",ch3_hp);
    printf("防禦:%d\n",ch3_defense);
    printf("角色預測強度:%.2f\n\n",((ch3_hp*1)+(ch3_attack*0.8)+(ch3_defense*0.5)-50)*6.5);
    printf("\n");
    int want;
    printf("是否新增角色(Yesssss=1),(Nooooo=2) : ");
    scanf("%d", & want);
    getchar();
    char ch4_type;
    int ch4_hp, ch4_attack, ch4_defense;
    if (want==1) { //Yesssss的結果

        for(; ;) {


            printf("新增角色\n");//新增角色
            printf("屬性:");
            scanf("%c", &ch4_type);
            printf("攻擊:");
            scanf("%d", &ch4_attack);
            printf("血量:");
            scanf("%d", &ch4_hp);
            printf("防禦:");
            scanf("%d", &ch4_defense);
            getchar();
            if (ch4_type=='f') { //轉換大小寫
                ch4_type='F';
            }
            if (ch4_type=='g') {
                ch4_type='G';
            }
            if (ch4_type=='a') {
                ch4_type='A';
            }
            if (ch4_type=='w') {
                ch4_type='W';
            }
            if (ch4_type=='F'||ch4_type=='f'||
                    ch4_type=='G'||ch4_type=='g'||
                    ch4_type=='A'||ch4_type=='a'||
                    ch4_type=='W'||ch4_type=='w') { //屬性內
                if (ch4_attack<15||ch4_attack>20||
                        ch4_hp<40    ||ch4_hp>50||
                        ch4_defense<5||ch4_defense>10) { //限制數值範圍
                    printf("錯誤:能力數值在限制範圍之外\n");
                    continue;
                }
                if ((ch4_attack+ch4_hp+ch4_defense)<65||(ch4_attack+ch4_hp+ch4_defense)>70) {
                    printf("錯誤:能力數值在限制範圍之外\n");
                    continue;
                }
            }

            if (ch4_type!='F'&&ch4_type!='f'&&
                    ch4_type!='G'&&ch4_type!='g'&&
                    ch4_type!='A'&&ch4_type!='a'&&
                    ch4_type!='W'&&ch4_type!='w') { //屬性外
                if (ch4_attack<15||ch4_attack>20||
                        ch4_hp<40    ||ch4_hp>50||
                        ch4_defense<5||ch4_defense>10) { //限制數值範圍
                    printf("錯誤：無此屬性\n");
                    printf("錯誤:能力數值在限制範圍之外\n");
                    continue;
                }
                if ((ch4_attack+ch4_hp+ch4_defense)<65||(ch4_attack+ch4_hp+ch4_defense)>70) {
                    printf("錯誤：無此屬性\n");
                    printf("錯誤:能力數值在限制範圍之外\n");
                    continue;
                }
            }
            break;
        }




        printf("\n");
        printf("角色四\n");
        printf("名稱:阿芹\n");
        printf("屬性:%c    ",ch4_type);
        printf("攻擊:%d\n", ch4_attack);
        printf("血量:%d    ", ch4_hp);
        printf("防禦:%d\n", ch4_defense);
        printf("角色預測強度:%.2f\n\n",((ch4_hp*1)+(ch4_attack*0.8)+(ch4_defense*0.5)-50)*6.5);
        printf("\n");
        int one1,two1,f_attack,f_defense,f_hp,l_attack,l_defense,l_hp;
        for(; ;) {
            printf("選擇先攻角色:");
            scanf("%d",&one1);



            if (one1<1||one1>4) {
                printf("錯誤:無此角色\n");//輸入超過範圍數字的情況
                continue;
            }
            for(; ;) {
                if (4>=one1>=1) {
                    printf("選擇後攻角色:");
                }
                scanf("%d",&two1);
                if (two1<1||two1>4) {
                    printf("錯誤:無此角色\n");
                    continue;
                }
                if (one1==two1) {
                    printf("錯誤:不可重複選取\n");//輸入同樣數字的情況
                    continue;
                }
                break;
            }
            break;
        }
        printf("先攻為角色:%d、",one1);
        printf("後攻為角色:%d\n",two1);
        printf("戰鬥開始\n\n");
        if(one1==1&&two1==2) { //角色1對戰角色2
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 46 角色2 HP: 36\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 37 角色2 HP: 36\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 37 角色2 HP: 27\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 28 角色2 HP: 27\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 28 角色2 HP: 18\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 19 角色2 HP: 18\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 19 角色2 HP: 9\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 10 角色2 HP: 9\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 10 角色2 HP: 0\n\n");
            printf("角色2 失去戰鬥能力\n");
            printf("戰鬥結束\n\n");
            printf("角色1獲勝\n");

        }
        if(one1==1&&two1==3) { //角色1對戰角色3
            printf("角色1 對 角色3 發動攻擊,造成11點傷害\n");
            printf("角色1 HP: 46 角色3 HP: 32\n\n");
            printf("角色2 對 角色3 發動攻擊,造成12點傷害\n");
            printf("角色1 HP: 34 角色3 HP: 32\n\n");
            printf("角色1 對 角色3 發動攻擊,造成11點傷害\n");
            printf("角色1 HP: 34 角色3 HP: 21\n\n");
            printf("角色2 對 角色3 發動攻擊,造成12點傷害\n");
            printf("角色1 HP: 22 角色3 HP: 21\n\n");
            printf("角色1 對 角色3 發動攻擊,造成11點傷害\n");
            printf("角色1 HP: 22 角色3 HP: 10\n\n");
            printf("角色2 對 角色3 發動攻擊,造成12點傷害\n");
            printf("角色1 HP: 10 角色3 HP: 10\n\n");
            printf("角色1 對 角色3 發動攻擊,造成11點傷害\n");
            printf("角色1 HP: 10 角色3 HP: -1\n\n");
            printf("角色3 失去戰鬥能力\n");
            printf("戰鬥結束\n\n");
            printf("角色1獲勝\n");

        }
        if(one1==2&&two1==1) { //角色2對戰角色1
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 45 角色1 HP: 37\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 36 角色1 HP: 37\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 36 角色1 HP: 28\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 27 角色1 HP: 28\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 27 角色1 HP: 19\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 18 角色1 HP: 19\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 18 角色1 HP: 10\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 9  角色1 HP: 10\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 9  角色1 HP: 1\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 0  角色1 HP: 1\n\n");
            printf("角色2 失去戰鬥能力\n");
            printf("戰鬥結束\n\n");
            printf("角色1獲勝\n");

        }
        if(one1==2&&two1==3) { //角色2對戰角色3
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色2 HP: 45 角色3 HP: 33\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色2 HP: 34 角色3 HP: 33\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色2 HP: 34 角色3 HP: 23\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色2 HP: 23 角色3 HP: 23\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色2 HP: 23 角色3 HP: 13\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色2 HP: 12 角色3 HP: 13\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色2 HP: 12 角色3 HP: 3\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色2 HP: 1  角色3 HP: 3\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色2 HP: 1  角色3 HP: -7\n\n");
            printf("角色3 失去戰鬥能力\n");
            printf("戰鬥結束\n\n");
            printf("角色2獲勝\n");

        }
        if(one1==3&&two1==1) { //角色3對戰角色1
            printf("角色3 對 角色1 發動攻擊,造成12點傷害\n");
            printf("角色3 HP: 43 角色1 HP: 34\n\n");
            printf("角色1 對 角色3 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 32 角色1 HP: 34\n\n");
            printf("角色3 對 角色1 發動攻擊,造成12點傷害\n");
            printf("角色3 HP: 32 角色1 HP: 22\n\n");
            printf("角色1 對 角色3 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 21 角色1 HP: 22\n\n");
            printf("角色3 對 角色1 發動攻擊,造成12點傷害\n");
            printf("角色3 HP: 21 角色1 HP: 10\n\n");
            printf("角色1 對 角色3 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 10 角色1 HP: 10\n\n");
            printf("角色3 對 角色1 發動攻擊,造成12點傷害\n");
            printf("角色3 HP: 10 角色1 HP: -2\n\n");
            printf("角色1 失去戰鬥能力\n");
            printf("戰鬥結束\n\n");
            printf("角色3獲勝\n");

        }
        if(one1==3&&two1==2) { //角色3對戰角色2
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 43 角色2 HP: 34\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色3 HP: 33 角色2 HP: 34\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 33 角色2 HP: 23\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色3 HP: 23 角色2 HP: 23\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 23 角色2 HP: 12\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色3 HP: 13 角色2 HP: 12\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 13 角色2 HP: 1\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色3 HP: 3  角色2 HP: 1\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 3  角色2 HP: -10\n\n");
            printf("角色2 失去戰鬥能力\n");
            printf("戰鬥結束\n\n");
            printf("角色3獲勝\n");

        }
        if(one1==1&&two1==4) { //角色1對戰角色4
            f_attack=ch1_attack,f_defense=ch1_defense,f_hp=ch1_hp;
            l_attack=ch4_attack,l_defense=ch4_defense,l_hp=ch4_hp;

            while(f_hp>0&&l_hp>0) {
                printf("角色%d 對 角色%d 發動攻擊造成%d傷害\n",one1,two1,f_attack-l_defense);
                l_hp-=f_attack-l_defense;
                printf("角色%d HP:%d 角色%d HP:%d\n",one1,f_hp,two1,l_hp);

                printf("\n");
                if(l_hp<=0) {
                    printf("角色%d失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",two1,one1);
                    return 0;
                }
                printf("角色%d 對 角色%d 發動攻擊造成%d傷害\n",two1,one1,l_attack-f_defense);
                f_hp-=l_attack-f_defense;
                printf("角色%d HP:%d 角色%d HP:%d\n",one1,f_hp,two1,l_hp);
                printf("\n");
                if(f_hp<=0) {
                    printf("角色%d失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",one1,two1);
                    return 0;
                }
            }
        }
        if(one1==4&&two1==1) { //角色4對戰角色1
            f_attack=ch4_attack,f_defense=ch4_defense,f_hp=ch4_hp;
            l_attack=ch1_attack,l_defense=ch1_defense,l_hp=ch1_hp;

            while(f_hp>0&&l_hp>0) {
                printf("角色%d 對 角色%d 發動攻擊造成%d傷害\n",one1,two1,f_attack-l_defense);
                l_hp-=f_attack-l_defense;
                printf("角色%d HP:%d 角色%d HP:%d\n",one1,f_hp,two1,l_hp);

                printf("\n");
                if(l_hp<=0) {
                    printf("角色%d失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",two1,one1);
                    return 0;
                }
                printf("角色%d 對 角色%d 發動攻擊造成%d傷害\n",two1,one1,l_attack-f_defense);
                f_hp-=l_attack-f_defense;
                printf("角色%d HP:%d 角色%d HP:%d\n",one1,f_hp,two1,l_hp);
                printf("\n");
                if(f_hp<=0) {
                    printf("角色%d失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",one1,two1);
                    return 0;
                }
            }
        }
        if(one1==2&&two1==4) { //角色2對戰角色4
            f_attack=ch2_attack,f_defense=ch2_defense,f_hp=ch2_hp;
            l_attack=ch4_attack,l_defense=ch4_defense,l_hp=ch4_hp;

            while(f_hp>0&&l_hp>0) {
                printf("角色%d 對 角色%d 發動攻擊造成%d傷害\n",one1,two1,f_attack-l_defense);
                l_hp-=f_attack-l_defense;
                printf("角色%d HP:%d 角色%d HP:%d\n",one1,f_hp,two1,l_hp);

                printf("\n");
                if(l_hp<=0) {
                    printf("角色%d失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",two1,one1);
                    return 0;
                }
                printf("角色%d 對 角色%d 發動攻擊造成%d傷害\n",two1,one1,l_attack-f_defense);
                f_hp-=l_attack-f_defense;
                printf("角色%d HP:%d 角色%d HP:%d\n",one1,f_hp,two1,l_hp);
                printf("\n");
                if(f_hp<=0) {
                    printf("角色%d失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",one1,two1);
                    return 0;
                }
            }
        }
        if(one1==4&&two1==2) { //角色4對戰角色2
            f_attack=ch4_attack,f_defense=ch4_defense,f_hp=ch4_hp;
            l_attack=ch2_attack,l_defense=ch2_defense,l_hp=ch2_hp;

            while(f_hp>0&&l_hp>0) {
                printf("角色%d 對 角色%d 發動攻擊造成%d傷害\n",one1,two1,f_attack-l_defense);
                l_hp-=f_attack-l_defense;
                printf("角色%d HP:%d 角色%d HP:%d\n",one1,f_hp,two1,l_hp);

                printf("\n");
                if(l_hp<=0) {
                    printf("角色%d失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",two1,one1);
                    return 0;
                }
                printf("角色%d 對 角色%d 發動攻擊造成%d傷害\n",two1,one1,l_attack-f_defense);
                f_hp-=l_attack-f_defense;
                printf("角色%d HP:%d 角色%d HP:%d\n",one1,f_hp,two1,l_hp);
                printf("\n");
                if(f_hp<=0) {
                    printf("角色%d失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",one1,two1);
                    return 0;
                }
            }
        }
        if(one1==3&&two1==4) { //角色3對戰角色4
            f_attack=ch3_attack,f_defense=ch3_defense,f_hp=ch3_hp;
            l_attack=ch4_attack,l_defense=ch4_defense,l_hp=ch4_hp;

            while(f_hp>0&&l_hp>0) {
                printf("角色%d 對 角色%d 發動攻擊造成%d傷害\n",one1,two1,f_attack-l_defense);
                l_hp-=f_attack-l_defense;
                printf("角色%d HP:%d 角色%d HP:%d\n",one1,f_hp,two1,l_hp);

                printf("\n");
                if(l_hp<=0) {
                    printf("角色%d失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",two1,one1);
                    return 0;
                }
                printf("角色%d 對 角色%d 發動攻擊造成%d傷害\n",two1,one1,l_attack-f_defense);
                f_hp-=l_attack-f_defense;
                printf("角色%d HP:%d 角色%d HP:%d\n",one1,f_hp,two1,l_hp);
                printf("\n");
                if(f_hp<=0) {
                    printf("角色%d失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",one1,two1);
                    return 0;
                }
            }
        }
        if(one1==4&&two1==3) { //角色4對戰角色3
            f_attack=ch4_attack,f_defense=ch4_defense,f_hp=ch4_hp;
            l_attack=ch3_attack,l_defense=ch3_defense,l_hp=ch3_hp;

            while(f_hp>0&&l_hp>0) {
                printf("角色%d 對 角色%d 發動攻擊造成%d傷害\n",one1,two1,f_attack-l_defense);
                l_hp-=f_attack-l_defense;
                printf("角色%d HP:%d 角色%d HP:%d\n",one1,f_hp,two1,l_hp);

                printf("\n");
                if(l_hp<=0) {
                    printf("角色%d失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",two1,one1);
                    return 0;
                }
                printf("角色%d 對 角色%d 發動攻擊造成%d傷害\n",two1,one1,l_attack-f_defense);
                f_hp-=l_attack-f_defense;
                printf("角色%d HP:%d 角色%d HP:%d\n",one1,f_hp,two1,l_hp);
                printf("\n");
                if(f_hp<=0) {
                    printf("角色%d失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",one1,two1);
                    return 0;
                }
            }
        }

    }

    int one2,two2;
    if (want==2) { //Nooooo的結果
        for(; ;) {
            printf("選擇先攻角色:");
            scanf("%d",&one2);

            if(one2<1||one2>3) {
                printf("錯誤:無此角色\n");//輸入超過範圍數字的情況
                continue;
            }
            for(; ;) {
                if(3>=one2>=1) {
                    printf("選擇後攻角色:");
                }
                scanf("%d",&two2);
                if(two2<1||two2>3) {
                    printf("錯誤:無此角色\n");//輸入超過範圍數字的情況
                    continue;
                }
                if(one2==two2) {
                    printf("錯誤:不可重複選取\n");//輸入同樣數字的情況
                    continue;
                }
                break;
            }
            break;
        }
        printf("先攻為角色:%d、",one2);
        printf("後攻為角色:%d\n",two2);
        printf("戰鬥開始\n\n");
        if(one2==1&&two2==2) { //角色1對戰角色2
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 46 角色2 HP: 36\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 37 角色2 HP: 36\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 37 角色2 HP: 27\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 28 角色2 HP: 27\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 28 角色2 HP: 18\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 19 角色2 HP: 18\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 19 角色2 HP: 9\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 10 角色2 HP: 9\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色1 HP: 10 角色2 HP: 0\n\n");
            printf("角色2 失去戰鬥能力\n");
            printf("戰鬥結束\n\n");
            printf("角色1獲勝\n");

        }
        if(one2==1&&two2==3) { //角色1對戰角色3
            printf("角色1 對 角色3 發動攻擊,造成11點傷害\n");
            printf("角色1 HP: 46 角色3 HP: 32\n\n");
            printf("角色2 對 角色3 發動攻擊,造成12點傷害\n");
            printf("角色1 HP: 34 角色3 HP: 32\n\n");
            printf("角色1 對 角色3 發動攻擊,造成11點傷害\n");
            printf("角色1 HP: 34 角色3 HP: 21\n\n");
            printf("角色2 對 角色3 發動攻擊,造成12點傷害\n");
            printf("角色1 HP: 22 角色3 HP: 21\n\n");
            printf("角色1 對 角色3 發動攻擊,造成11點傷害\n");
            printf("角色1 HP: 22 角色3 HP: 10\n\n");
            printf("角色2 對 角色3 發動攻擊,造成12點傷害\n");
            printf("角色1 HP: 10 角色3 HP: 10\n\n");
            printf("角色1 對 角色3 發動攻擊,造成11點傷害\n");
            printf("角色1 HP: 10 角色3 HP: -1\n\n");
            printf("角色3 失去戰鬥能力\n");
            printf("戰鬥結束\n\n");
            printf("角色1獲勝\n");

        }
        if(one2==2&&two2==1) { //角色2對戰角色1
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 45 角色1 HP: 37\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 36 角色1 HP: 37\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 36 角色1 HP: 28\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 27 角色1 HP: 28\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 27 角色1 HP: 19\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 18 角色1 HP: 19\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 18 角色1 HP: 10\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 9  角色1 HP: 10\n\n");
            printf("角色2 對 角色1 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 9  角色1 HP: 1\n\n");
            printf("角色1 對 角色2 發動攻擊,造成9點傷害\n");
            printf("角色2 HP: 0  角色1 HP: 1\n\n");
            printf("角色2 失去戰鬥能力\n");
            printf("戰鬥結束\n\n");
            printf("角色1獲勝\n");

        }
        if(one2==2&&two2==3) { //角色2對戰角色3
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色2 HP: 45 角色3 HP: 33\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色2 HP: 34 角色3 HP: 33\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色2 HP: 34 角色3 HP: 23\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色2 HP: 23 角色3 HP: 23\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色2 HP: 23 角色3 HP: 13\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色2 HP: 12 角色3 HP: 13\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色2 HP: 12 角色3 HP: 3\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色2 HP: 1  角色3 HP: 3\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色2 HP: 1  角色3 HP: -7\n\n");
            printf("角色3 失去戰鬥能力\n");
            printf("戰鬥結束\n\n");
            printf("角色2獲勝\n");

        }
        if(one2==3&&two2==1) { //角色3對戰角色1
            printf("角色3 對 角色1 發動攻擊,造成12點傷害\n");
            printf("角色3 HP: 43 角色1 HP: 34\n\n");
            printf("角色1 對 角色3 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 32 角色1 HP: 34\n\n");
            printf("角色3 對 角色1 發動攻擊,造成12點傷害\n");
            printf("角色3 HP: 32 角色1 HP: 22\n\n");
            printf("角色1 對 角色3 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 21 角色1 HP: 22\n\n");
            printf("角色3 對 角色1 發動攻擊,造成12點傷害\n");
            printf("角色3 HP: 21 角色1 HP: 10\n\n");
            printf("角色1 對 角色3 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 10 角色1 HP: 10\n\n");
            printf("角色3 對 角色1 發動攻擊,造成12點傷害\n");
            printf("角色3 HP: 10 角色1 HP: -2\n\n");
            printf("角色1 失去戰鬥能力\n");
            printf("戰鬥結束\n\n");
            printf("角色3獲勝\n");

        }
        if(one2==3&&two2==2) { //角色3對戰角色2
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 43 角色2 HP: 34\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色3 HP: 33 角色2 HP: 34\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 33 角色2 HP: 23\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色3 HP: 23 角色2 HP: 23\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 23 角色2 HP: 12\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色3 HP: 13 角色2 HP: 12\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 13 角色2 HP: 1\n\n");
            printf("角色2 對 角色3 發動攻擊,造成10點傷害\n");
            printf("角色3 HP: 3  角色2 HP: 1\n\n");
            printf("角色3 對 角色2 發動攻擊,造成11點傷害\n");
            printf("角色3 HP: 3  角色2 HP: -10\n\n");
            printf("角色2 失去戰鬥能力\n");
            printf("戰鬥結束\n\n");
            printf("角色3獲勝\n");

        }
    }

    if (want!=1&&want!=2) { //創造角色輸入其他不是1或2的情況
        printf("輸入錯誤");
    }



    return 0;
}
