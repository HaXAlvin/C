#include<stdio.h>
int main() {
    //角色1 強度70
    char char1_type = 'F';
    int char1_hp = 48;
    int char1_atk = 16;
    int char1_def = 6;
    //角色2 強度69
    char char2_type = 'G';
    int char2_hp = 41;
    int char2_atk = 19;
    int char2_def = 9;
    //角色3 強度68
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

    printf("角色1\n名稱:馬力歐\n屬性:%c\t\t血量:%d\n攻擊力:%d\t防禦力:%d\n強度預測:%.2f\n\n",char1_type,char1_hp,char1_atk,char1_def,va1);
    printf("角色2\n名稱:路易吉\n屬性:%c\t\t血量:%d\n攻擊力:%d\t防禦力:%d\n強度預測:%.2f\n\n",char2_type,char2_hp,char2_atk,char2_def,va2);
    printf("角色3\n名稱:奇諾比奧\n屬性:%c\t\t血量:%d\n攻擊力:%d\t防禦力:%d\n強度預測:%.2f\n\n",char3_type,char3_hp,char3_atk,char3_def,va3);

    int num;
    int n=0;
    int first_atk,second_atk;

    printf("是否新增角色(1.Yes/2.No)? ");
    scanf("%d",&num);
    //是否新增角色選擇不等於1.2.則重新輸入
    if (num!=1&&num!=2)
        do {
            n=0;
            printf("輸入錯誤\n");
            printf("是否新增角色(1.Yes/2.No)? ");
            scanf("%d",&num);
        }while(n==1);
    //是否新增角色選擇1.Yes
    if (num==1){
        do {
            n=0;
            printf("\n新增角色\n");
            printf("屬性:");
            scanf(" %c",&char4_type);
            printf("血量:");
            scanf("%d",&char4_hp);
            printf("攻擊力:");
            scanf("%d",&char4_atk);
            printf("防禦力:");
            scanf("%d",&char4_def);
            //屬性錯誤重新輸入
            int sum=char4_atk+char4_def+char4_hp;
            if (char4_type!='F'&&char4_type!='W'&&char4_type!='G'&&char4_type!='A'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a'){
                printf("錯誤:無此屬性\n");
                n=1;
            }
            //能力值錯誤重新輸入
            if (char4_atk<15||char4_atk>20||char4_def<5||char4_def>10||char4_hp<40||char4_hp>50||sum<65||sum>70){
                printf("錯誤:能力數值在限制範圍之外\n");
                n=1;
            }
        }while(n==1);
        //屬性大小寫轉換
        if (islower(char4_type)){
           char4_type=toupper(char4_type);
        }
        //強度預測算法
        float va4=((char4_hp*1.0)+(char4_atk*0.8)+(char4_def*0.5)-50)*6.5;

        printf("\n角色4\n角色名稱:自訂角色\n屬性:%c\t\t血量:%d\n攻擊力:%d\t防禦力:%d\n強度預測:%.2f\n\n",char4_type,char4_hp,char4_atk,char4_def,va4);
        //選擇先後攻角色
        do{
            n=0;
            printf("選擇先攻角色:");
            scanf("%d",&first_atk);
            if (first_atk>4){
                printf("錯誤:無此角色\n");
                n=1;
            }
        }while(n==1);
        do{
            n=0;
            printf("選擇後攻角色:");
            scanf("%d",&second_atk);
            if (second_atk>4){
                printf("錯誤:無此角色\n");
                n=1;
            }
        }while(n==1);
        if (first_atk==second_atk){
            printf("錯誤:不可重複選取\n");
            n=1;
        }
    }
    //是否新增角色選擇2.No、選擇先後攻角色
    if (num==2){
        do{
            n=0;
            printf("選擇先攻角色:");
            scanf("%d",&first_atk);
            if (first_atk>4){
                printf("錯誤:無此角色\n");
                n=1;
            }
        }while(n==1);
        do{
            n=0;
            printf("選擇後攻角色:");
            scanf("%d",&second_atk);
            if (second_atk>4){
                printf("錯誤:無此角色\n");
                n=1;
            }
        }while(n==1);
        if (first_atk==second_atk){
            printf("錯誤:不可重複選取\n");
            n=1;
        }
    }
    printf("\n先攻為角色%d、後攻為角色%d",first_atk,second_atk);
    printf("\n戰鬥開始");
    //取出角色數據
    int atk1_hp,atk2_hp,atk1_atk,atk2_atk,atk1_def,atk2_def;
    switch (first_atk){
        case 1:
            atk1_hp=char1_hp;
            atk1_atk=char1_atk;
            atk1_def=char1_def;
            break;
        case 2:
            atk1_hp=char2_hp;
            atk1_atk=char2_atk;
            atk1_def=char2_def;
            break;
        case 3:
            atk1_hp=char3_hp;
            atk1_atk=char3_atk;
            atk1_def=char3_def;
            break;
        case 4:
            atk1_hp=char4_hp;
            atk1_atk=char4_atk;
            atk1_def=char4_def;
            break;
    }
    switch (second_atk){
        case 1:
            atk2_hp=char1_hp;
            atk2_atk=char1_atk;
            atk2_def=char1_def;
            break;
        case 2:
            atk2_hp=char2_hp;
            atk2_atk=char2_atk;
            atk2_def=char2_def;
            break;
        case 3:
            atk2_hp=char3_hp;
            atk2_atk=char3_atk;
            atk2_def=char3_def;
            break;
        case 4:
            atk2_hp=char4_hp;
            atk2_atk=char4_atk;
            atk2_def=char4_def;
            break;
    }
    int atk1_hurt,atk2_hurt;
    atk1_hurt=atk1_atk-atk2_def;//角色1攻擊力-角色2防禦力
    atk2_hurt=atk2_atk-atk1_def;//角色2攻擊力-角色1防禦力
    //先後攻回合對戰
    while (atk1_hp>0||atk2_hp>0){
        atk2_hp-=atk1_hurt;//互相攻擊後之血量
        printf("\n\n角色%d 對 角色%d 發動攻擊，造成%d點傷害\n角色%d HP:%d 角色%d HP:%d\n",first_atk,second_atk,atk1_hurt,first_atk,atk1_hp,second_atk,atk2_hp);
        if (atk2_hp<=0){
            printf("\n角色%d 失去戰鬥能力\n戰鬥結束\n\n",second_atk);
            printf("角色%d 獲勝",first_atk);
            return 0;
        }
        atk1_hp-=atk2_hurt;//互相攻擊後之血量
        printf("\n\n角色%d 對 角色%d 發動攻擊，造成%d點傷害\n角色%d HP:%d 角色%d HP:%d\n",second_atk,first_atk,atk2_hurt,first_atk,atk1_hp,second_atk,atk2_hp);
        if (atk1_hp<=0){
            printf("\n角色%d 失去戰鬥能力\n戰鬥結束\n\n",first_atk);
            printf("角色%d 獲勝",second_atk);
            return 0;
        }
    }
    return 0;
}







