#include<stdio.h>
int main() {
    //角色1
    char char1_type = 'F';
    int char1_hp = 48;
    int char1_atk = 16;
    int char1_def = 6;
    //角色2
    char char2_type = 'G';
    int char2_hp = 41;
    int char2_atk = 19;
    int char2_def = 9;
    //角色3
    char char3_type = 'A';
    int char3_hp = 46;
    int char3_atk = 15;
    int char3_def = 7;
    //自訂角色
    char char4_type ;
    int char4_hp ;
    int char4_atk;
    int char4_def ;
    //強度預測算法
    float va1=((char1_hp*1.0)+(char1_atk*0.8)+(char1_def*0.5)-50)*6.5;
    float va2=((char2_hp*1.0)+(char2_atk*0.8)+(char2_def*0.5)-50)*6.5;
    float va3=((char3_hp*1.0)+(char3_atk*0.8)+(char3_def*0.5)-50)*6.5;
    //角色1 名稱:馬力歐 屬性:F 血量:48 攻擊力:16 防禦力:6 總和70
    //角色2 名稱:路易吉 屬性:G 血量:41攻擊力:19 防禦力:9 總和69
    //角色3 名稱:奇諾比奧 屬性:A 血量:46 攻擊力:15 防禦力:7 總和68
    printf("角色1\n名稱:馬力歐\n屬性:%c\t\t血量:%d\n攻擊力:%d\t防禦力:%d\n強度預測:%.2f\n\n",char1_type,char1_hp,char1_atk,char1_def,va1);
    printf("角色2\n名稱:路易吉\n屬性:%c\t\t血量:%d\n攻擊力:%d\t防禦力:%d\n強度預測:%.2f\n\n",char2_type,char2_hp,char2_atk,char2_def,va2);
    printf("角色3\n名稱:奇諾比奧\n屬性:%c\t\t血量:%d\n攻擊力:%d\t防禦力:%d\n強度預測:%.2f\n\n",char3_type,char3_hp,char3_atk,char3_def,va3);
    //選擇是否新增角色
    printf("是否新增角色(1.Yes/2.No)? ");
    //令一新整數num
    int num;
    //輸入選擇1或2或其他數字
    scanf("%d",&num);
    //是否新增角色選擇1.Yes
    if (num==1){
        printf("新增角色\n");
        printf("屬性:");
        scanf(" %c",&char4_type);
        printf("血量:");
        scanf("%d",&char4_hp);
        printf("攻擊力:");
        scanf("%d",&char4_atk);
        printf("防禦力:");
        scanf("%d",&char4_def);
        //屬性字元設定
        if (char4_type!='F'&&char4_type!='W'&&char4_type!='G'&&char4_type!='A'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a'){
            printf("錯誤:無此屬性\n");
        }
        //atk,def,hp三者總和
        int sum=char4_atk+char4_def+char4_hp;
        //能力值條件設定
        if (char4_atk<15||char4_atk>20||char4_def<5||char4_def>10||char4_hp<40||char4_hp>50||sum<65||sum>70){
            printf("錯誤:能力數值在限制範圍之外");
        }
        //如果屬性或能力值有一方錯或兩者錯就return 0
        if ((char4_type!='F'&&char4_type!='W'&&char4_type!='G'&&char4_type!='A'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a')||char4_atk<15||char4_atk>20||char4_def<5||char4_def>10||char4_hp<40||char4_hp>50||sum<65||sum>70)
            return 0;
        //屬性大小寫轉換
        if (islower(char4_type)){
           char4_type=toupper(char4_type);
        }
        //強度預測算法
        float va4=((char4_hp*1.0)+(char4_atk*0.8)+(char4_def*0.5)-50)*6.5;

        printf("\n角色4\n角色名稱:自訂角色\n屬性:%c\t\t血量:%d\n攻擊力:%d\t防禦力:%d\n強度預測:%.2f\n\n",char4_type,char4_hp,char4_atk,char4_def,va4);
        //選擇先後攻角色
        printf("選擇先攻角色:");
        int atk1;
        scanf("%d",&atk1);
        printf("選擇後攻角色:");
        int atk2;
        scanf("%d",&atk2);
        //先攻後攻的值不得超過4
        if (atk1>4||atk2>4){
            printf("錯誤:無此角色");
            return 0;
        }
        //先攻後攻不得相等
        if (atk1==atk2){
            printf("錯誤:不可重複選取");
            return 0;
        }
        printf("\n先攻為角色%d、後攻為角色%d",atk1,atk2);
    }
    //是否新增角色選擇2.No
    if (num==2){
        printf("選擇先攻角色:");
        int atk1;
        scanf("%d",&atk1);
        printf("選擇後攻角色:");
        int atk2;
        scanf("%d",&atk2);
        //先攻後攻的值不得超過4
        if (atk1>4||atk2>4){
            printf("錯誤:無此角色");
            return 0;
        }
        printf("先攻為角色%d、後攻為角色%d",atk1,atk2);
        //先攻後攻不得相等
        if (atk1==atk2){
            printf("錯誤:不可重複選取");
        }
    }
    //是否新增角色選擇不等於1.2.
    if (num!=1&&num!=2){
        printf("輸入錯誤");
    }
    return 0;
}
