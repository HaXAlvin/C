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

    if (want==1) { //Yesssss的結果

        char ch4_type;
        printf("新增角色\n");//新增角色
        printf("屬性:");
        scanf("%c", &ch4_type);
        int ch4_hp, ch4_attack, ch4_defense;
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
                ch4_type=='W'||ch4_type=='w') { //屬性內跟屬性外
            if (ch4_attack<15||ch4_attack>20||
                    ch4_hp<40    ||ch4_hp>50||
                    ch4_defense<5||ch4_defense>10) { //限制數值範圍
                printf("錯誤:能力數值在限制範圍之外\n");
                return 0;
            }
            if ((ch4_attack+ch4_hp+ch4_defense)<65||(ch4_attack+ch4_hp+ch4_defense)>70) {
                printf("錯誤:能力數值在限制範圍之外\n");
                return 0;
            }
        }

        else {
            if (ch4_attack<15||ch4_attack>20||
                    ch4_hp<40    ||ch4_hp>50||
                    ch4_defense<5||ch4_defense>10) {
                if ((ch4_attack+ch4_hp+ch4_defense)<65||(ch4_attack+ch4_hp+ch4_defense)>70) {
                    printf("錯誤:無此屬性\n");
                    printf("錯誤:能力數值在限制範圍之外\n");
                    return 0;
                }
            }
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
        int one1,two1;
        printf("選擇先攻角色:");
        scanf("%d",&one1);
        if (4>=one1>=1) {
            printf("選擇後攻角色:");
        }
        if (one1<1,one1>4) {
            printf("錯誤:無此角色");//輸入超過範圍數字的情況
            return 0;
        }
        scanf("%d",&two1);
        if (two1<1,two1>4) {
            printf("錯誤:無此角色");
            return 0;
        }
        if (one1==two1) {
            printf("錯誤:不可重複選取");//輸入同樣數字的情況
            return 0;
        }
        printf("先攻為角色:%d、",one1);
        printf("後攻為角色:%d",two1);

    }

    int one2,two2;
    if (want==2) { //Nooooo的結果
        printf("選擇先攻角色:");
        scanf("%d",&one2);
        if(3>=one2>=1) {
            printf("選擇後攻角色:");
        }
        if(one2<1,one2>3) {
            printf("錯誤:無此角色");//輸入超過範圍數字的情況
            return 0;
        }
        scanf("%d",&two2);
        if(two2<1,two2>3) {
            printf("錯誤:無此角色");//輸入超過範圍數字的情況
            return 0;
        }
        if(one2==two2) {
            printf("錯誤:不可重複選取");//輸入同樣數字的情況
            return 0;
        }
        printf("先攻為角色:%d、",one2);
        printf("後攻為角色:%d",two2);
    }
    if (want!=1&&want!=2) { //創造角色輸入其他不是1或2的情況
        printf("輸入錯誤");
    }



    return 0;
}
