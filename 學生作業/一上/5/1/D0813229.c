#include<stdio.h>
#include<stdlib.h>

int main() {
    char char1_type ;
    int char1_hp;
    int char1_atk;
    int char1_def;
    int ans;
    int ans1;
    int ans2;
    int test=0;
    int err_type = 0;
    int ans3;
    int ans4;

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
    //輸入數字
    if (ans ==1)
        //當%d=1時
    {
        printf("新增角色\n");
        printf("屬性:");
        scanf("%*c%c",&char1_type);
        printf("血量:");
        scanf("%d",&char1_hp);
        printf("攻擊:");
        scanf("%d",&char1_atk);
        printf("防禦:");
        scanf("%d",&char1_def);
        switch(char1_type)
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
        if (char1_hp<40||char1_hp>50||char1_atk<15||char1_atk>20||char1_def<5||char1_def>10) {
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
        printf("屬性:%c   ",char1_type);
        printf("攻擊:%d\n",char1_atk);
        printf("血量:%d   ",char1_hp);
        printf("防禦:%d\n",char1_def);
        printf("角色強度預測:%.2lf",b);

        printf("\n");
        printf("選擇先攻角色:");
        scanf("%d",&ans3);
        if (ans3>4) {
            printf("錯誤:無此角色");
            return 0;
        }
        printf("選擇後攻角色:");
        scanf("%d",&ans4);
        if (ans4>4) {
            printf("錯誤:無此角色");
            return 0;
        }
        printf("先攻角色為:%d",ans3);
        printf("後攻角色為:%d",ans4);
        return 0;
    }



    else if(ans==2)
        //當%d=2時
    {
        printf("選擇先攻角色:");
        scanf("%d",&ans1);
        if (ans1==ans2) {
            printf("錯誤:不可重複選取");
            return 0;
        }

        else if (ans1>3) {
            printf("錯誤:無此角色");
            return 0;
        }
        printf("選擇後攻角色:");
        scanf("%d",&ans2);

        if (ans1==ans2) {
            printf("錯誤:不可重複選取");
            return 0;
        }

        else if (ans2>3) {
            printf("錯誤:無此角色");
            return 0;
        }
        printf("先攻角色為:%d",ans1);
        printf("後攻角色為:%d",ans2);
    }
    if (ans>2)
        printf("輸入錯誤");

    return 0;

}
