#include<stdio.h>
#include<stdlib.h>

int main() {

    int char1_hp=40;
    int char1_atk=15;
    int char1_def=5;
    int char2_hp=41;
    int char2_atk=16;
    int char2_def=6;
    int char3_hp=42;
    int char3_atk=17;
    int char3_def=7;
    char char4_type ;
    int char4_hp;
    int char4_atk;
    int char4_def;
    int ans;
    int ans1;
    int ans2;
    int test=0;
    int err_type = 0;
    int hp1;
    int hp2;
    int atk1;
    int atk2;
    int def1;
    int def2;
    char dam1;
    char dam2;

    printf("角色1\n"
           "名稱:老噴\n"
           "屬性:F     攻擊:15\n"
           "血量:40    防禦:5\n"
           "角色強度預測:29.25\n\n");
    printf("角色2\n"
           "名稱:老龜\n"
           "屬性:W    攻擊:16\n"
           "血量:41   防禦:6\n"
           "角色強度預測:44.20\n\n");
    printf("角色3\n"
           "名稱:老皮\n"
           "屬性G    攻擊:17\n"
           "血量:42   防禦:7\n"
           "角色強度預測:59.15\n\n");

    printf("是否新增角色(1.Yes/2.No)?");
    scanf("%d",&ans);
    while(ans>2) {
        printf("輸入錯誤\n");
        printf("是否新增角色(1.Yes/2.No)?");
        scanf("%d",&ans);
    }
    printf("\n");
    if (ans ==1)
        //當%d=1時
    {
        printf("新增角色\n");
        printf("屬性:");
        scanf("%*c%c",&char4_type);
        printf("血量:");
        scanf("%d",&char4_hp);
        printf("攻擊:");
        scanf("%d",&char4_atk);
        printf("防禦:");
        scanf("%d",&char4_def);
        switch(char4_type)
            //判斷角色屬性
        {
        case'f':
            break;
        case'g':
            break;
        case'a':
            break;
        case'w':
            break;
        case'F':
            break;
        case'G':
            break;
        case'A':
            break;
        case'W':
            break;
        default:
            test = test +1; //計算錯誤次數
            err_type = 1; //標示錯誤種類
        }
        if (char4_hp<40||char4_hp>50||char4_atk<15||char4_atk>20||char4_def<5||char4_def>10) {
            test = test +1;
            err_type = 2;
        }//判斷能力值範圍
        switch(test) { //判斷顯示的東西
        case 0:
            break;
        case 1:
            if(err_type == 1) {
                printf("無此屬性");
                return 0;
            } else if(err_type == 2) {
                printf("錯誤:能力數值在範圍之外");
                return 0;
            } else {
                break;
            }

        case 2:
            printf("無此屬性\n錯誤:能力數值在範圍之外");
            return 0;
        }

        float a = (char1_hp*1.0+char1_atk*0.8+char1_def*0.5);
        float b = (a-50)*6.5;
        printf("\n");
        printf("角色4\n");
        printf("名稱:自訂角色\n");

        switch(char4_type) {
        case'f':
            printf("屬性:F  ");
            break;
        case'g':
            printf("屬性:G  ");
            break;
        case'a':
            printf("屬性:A  ");
            break;
        case'w':
            printf("屬性:W  ");
            break;
        default:
            printf("屬性:%c   ",char4_type);
            break;
        }
        printf("攻擊:%d\n",char4_atk);
        printf("血量:%d   ",char4_hp);
        printf("防禦:%d\n",char4_def);
        printf("角色強度預測:%.2lf",b);
        printf("\n");
        printf("      ");
        printf("\n");
        printf("選擇先攻角色:");
        scanf("%d",&ans1);
        while(ans1>4) {
            printf("錯誤:無此角色\n");
            printf("選擇先攻角色:");
            scanf("%d",&ans1);
        }
        printf("選擇後攻角色:");
        scanf("%d",&ans2);
        while(ans2>4) {
            printf("錯誤:無此角色\n");
            printf("選擇後攻角色:");
            scanf("%d",&ans2);
        }
        printf("先攻角色為%d",ans1);
        printf("後攻角色為%d",ans2);
    } else if(ans==2)
        //當%d=2時
    {
        printf("選擇先攻角色:");
        scanf("%d",&ans1);
        if(ans1==ans2) {
            printf("錯誤:不可重複選取\n");
            return 0;
        } else if(ans1>3) {
            printf("錯誤:無此角色");
            return 0;
        }
        printf("選擇後攻角色:");
        scanf("%d",&ans2);
        if (ans1==ans2) {
            printf("錯誤:不可重複選取");
            return 0;
        } else if (ans2>3) {
            printf("錯誤:無此角色");
            return 0;
        }
        printf("\n");
        printf("先攻角色為%d、",ans1);
        printf("後攻角色為%d",ans2);
    }
    printf("\n");
    printf("戰鬥開始");
    printf("\n");
    printf("     ");
    printf("\n");
    switch(ans1) {
    case 1:
        hp1=40;
        atk1=15;
        def1=5;
        break;
    case 2:
        hp1=41;
        atk1=16;
        def1=6;
        break;
    case 3:
        hp1=42;
        atk1=17;
        def1=7;
        break;
    case 4:
        hp1=char4_hp;
        atk1=char4_atk;
        def1=char4_def;
        break;
    default:
        hp1=0;
        break;
    }
    switch(ans2) {
    case 1:
        hp2=40;
        atk2=15;
        def2=5;
        break;
    case 2:
        hp2=41;
        atk2=16;
        def2=6;
        break;
    case 3:
        hp2=42;
        atk2=17;
        def2=7;
        break;
    case 4:
        hp2=char4_hp;
        atk2=char4_atk;
        def2=char4_def;
        break;
    default:
        hp2=0;
        break;
    }
    dam1=atk1-def2;
    dam2=atk2-def1;

    while(hp1>0&hp2>0) {

        hp2=hp2-dam1;
        printf("角色%d 對角色%d 發動攻擊，造成%d傷害\n角色%d HP %d  角色%d  HP %d\n",ans1,ans2,dam1,ans1,hp1,ans2,hp2);
        printf("\n");
        if(hp2>0) {
            hp1=hp1-dam2;
            printf("角色%d 對角色%d 發動攻擊，造成%d傷害\n角色%d HP %d  角色%d  HP %d\n",ans2,ans1,dam2,ans1,hp1,ans2,hp2);
            printf("\n");
        }

    }
    if(hp1<=0|hp2<=0) {
        if(hp1<=0) {
            printf("角色%d  失去戰鬥能力\n戰鬥結束\n",ans1);
            printf("\n");
            printf("角色%d 獲勝",ans2);
        } else {
            printf("角色%d  失去戰鬥能力\n戰鬥結束\n",ans2);
            printf("\n");
            printf("角色%d 獲勝",ans1);
        }

    }
    return 0;
}
