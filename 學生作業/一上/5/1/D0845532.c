#include<stdio.h>//標頭檔
int main() {
    //主函式
    char char1type='G',char2type='A',char3type='F',char4type;//type
    int  char1atk=20,char2atk=15,char3atk=16,char4atk;//atk
    int  char1hp=40,char2hp=35,char3hp=44,char4hp;//hp
    int  char1def=10,char2def=10,char3def=5,char4def;//def
    int  add;//yes or no
    int first,last,first1,last1;//先攻 後攻

    printf("角色1\n"//印出文字
           "名稱:毛毛\n");
    printf("屬性:G    攻擊:20\n",char1type,char1atk);
    printf("血量:40   防禦:10\n", char2type,char2atk);
    printf("角色預測強度:%.2f\n\n",((char1hp*1)+(char1atk*0.8)+(char1def*0.5)-50)*6.5);

    printf("角色2\n"
           "名稱:皮皮\n");
    printf("屬性:A    攻擊:15\n",char2type,char2atk);
    printf("血量:35   防禦:10\n",char2hp,char2def);
    printf("角色預測強度:%.2f\n\n",((char2hp*1)+(char2atk*0.8)+(char2def*0.5)-50)*6.5);

    printf("角色3\n"
           "名稱:瑞斯\n");
    printf("屬性:F    攻擊:16\n",char3type,char3atk);
    printf("血量:44   防禦:5\n",char3hp,char3def);
    printf("角色預測強度:%.2f\n\n",((char1hp*1)+(char1atk*0.8)+(char1def*0.5)-50)*6.5);
    printf("是否新增角色(1.yes 2.no)?");
    scanf("%d",&add);
    getchar();
    if (add==1) {

        printf("");
        printf("新增角色\n");//新增角色
        printf("屬性:");
        scanf("%c",&char4type);
        getchar();
        printf("攻擊:");
        scanf("%d",&char4atk);
        getchar();
        printf("血量:");
        scanf("%d",&char4hp);
        getchar();
        printf("防禦:");
        scanf("%d",&char4def);
        getchar();
        if (char4type =='F' || char4type =='f' || char4type =='W' || char4type =='w' ||//屬性以外
                char4type =='G' || char4type =='g' || char4type =='A' || char4type =='a') {
            if (char4hp<40 || char4hp>50||//數值限制
                    char4atk<15||char4atk>20||
                    char4def<5||char4def>10) {
                printf("錯誤:能力數值在限制之外\n");
                return 0;

            }
            if ((char4def+char4atk+char4hp)<65||(char4def+char4atk+char4hp)>70) {
                printf("錯誤:能力數值在限制之外\n");
                return 0;
            }
        } else {
            if (char4hp<40 || char4hp>50||//數值限制
                    char4atk<15||char4atk>20||
                    char4def<5||char4def>10) {
                if ((char4def+char4atk+char4hp)<65||(char4def+char4atk+char4hp)>70) {

                    printf("無此屬性\n");
                    printf("錯誤:能力數值在限制之外\n");
                    return 0;
                }
            }
        }
        if (char4type=='f') { //大小寫轉換
            char4type='F';
        } else if (char4type=='w') {
            char4type='W';
        } else if (char4type=='g') {
            char4type='G';
        } else if (char4type=='a') {
            char4type='A';
        }
        if (char4hp<40 || char4hp>50||//數值限制
                char4atk<15||char4atk>20||
                char4def<5||char4def>10) {
            printf("錯誤:能力數值在限制之外\n");
            return 0;
        }
        if ((char4def+char4atk+char4hp)<65||(char4def+char4atk+char4hp)>70) {
            printf("錯誤:能力數值在限制之外\n");
            return 0;
        }
        printf("\n");

        printf("角色4\n");
        printf("名稱:自訂角色\n");
        printf("屬性:%c 攻擊%d\n",char4type,char4atk);
        printf("血量:%d 防禦%d\n",char4hp,char4def);
        printf("角色預測強度:%.2f\n",((char4hp*1)+(char4atk*0.8)+(char4def*0.5)-50)*6.5);
        printf("\n");
        printf("輸入先攻角色:");
        scanf("%d",&first1);

        if (first1==1||first1==2||first1==3||first1==4) {
            printf("輸入後攻角色:");
        }

        else {
            printf("錯誤:無此角色");
            return 0;
        }
        scanf("%d",&last1);//後攻角色
        if (last1==1||last1==2||last1==3||last1==4) {
            printf("輸入後攻角色:");
        }

        else {
            printf("錯誤:無此角色");
            return 0;
        }
        if (first1==last1) { //重複選取
            printf("錯誤:不可重複選取\n");
            return 0;
        }
        printf("先攻角色:%d、後攻角色:%d",first1,last1);

    }

    else if (add==2) { //輸入2的路線
        printf("輸入先攻角色:\n");
        scanf("%d",&first);
        if (first!=1&&first!=2&&first!=3) {
            printf("錯誤:角色不存在");
            return 0;
        }
        printf("輸入後攻角色:\n");
        scanf("%d",&last);
        if (last!=1&&last!=2&&last!=3) {
            printf("錯誤:角色不存在");
            return 0;
        }
        if (first==last) {
            printf("錯誤:不可重複選取");
            return 0;
        }
        printf("先攻為角色%d、後攻為角色%d",first,last);

    }


    return 0;//結束

}
