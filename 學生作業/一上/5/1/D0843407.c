#include <stdio.h>

int main() {
//宣告變數
    char Char1_type='W',Char2_type='F',Char3_type='G',Char4_type;//屬性
    int Char1_atk=15,Char2_atk=20,Char3_atk=15,Char4_atk;//攻擊
    int Char1_hp=50,Char2_hp=40,Char3_hp=45,Char4_hp;//血量
    int Char1_def=5,Char2_def=5,Char3_def=10,Char4_def;//防禦
    int Add,Char4_all,Char_num=3,Char_frist,Char_last,is_tf=0;//新增角色,角色4數值總和,角色總數,先攻,後攻,錯兩個的flag
//內建角色
    printf("角色1 \n");
    printf("名稱:傑尼龜 \n");
    printf("屬性:%c    攻擊:%d  \n",Char1_type,Char1_atk);
    printf("血量:%d   防禦:%d  \n",Char1_hp,Char1_def);
    printf("強度預測:%.2f\n",( Char1_hp * 1.0 + Char1_atk * 0.8 + Char1_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
    printf("角色2 \n");
    printf("名稱:小火龍 \n");
    printf("屬性:%c    攻擊:%d  \n",Char2_type,Char2_atk);
    printf("血量:%d   防禦:%d  \n",Char2_hp,Char2_def);
    printf("強度預測:%.2f\n",( Char2_hp * 1.0 + Char2_atk * 0.8 + Char2_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
    printf("角色3 \n");
    printf("名稱:小拳石 \n");
    printf("屬性:%c    攻擊:%d  \n",Char2_type,Char2_atk);
    printf("血量:%d   防禦:%d  \n",Char2_hp,Char2_def);
    printf("強度預測:%.2f\n",( Char3_hp * 1.0 + Char3_atk * 0.8 + Char3_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
//新增角色
    printf("是否新增角色(1.Yes/2.No)?");
    scanf("%d",&Add);
    getchar();
    printf ("\n");
    if(Add==1) {
        Char_num++;
        printf("新增角色\n");
        printf("屬性:");
        scanf("%c",&Char4_type);
        getchar();
        printf("血量:");
        scanf("%d",&Char4_hp);
        getchar();
        printf("攻擊:");
        scanf("%d",&Char4_atk);
        getchar();
        printf("防禦:");
        scanf("%d",&Char4_def);
        getchar();
//檢查屬性
        if(Char4_type!='F'&&Char4_type!='f'&&Char4_type!='W'&&Char4_type!='w'&&
                Char4_type!='G'&&Char4_type!='g'&&Char4_type!='A'&&Char4_type!='a') {
            printf("錯誤:無此屬性\n");
            //為啥事&&不是||
            is_tf = 1;
        }
//小寫換大寫
        else if(Char4_type=='f') {
            Char4_type='F';
        } else if(Char4_type=='w') {
            Char4_type='W';
        } else if(Char4_type=='g') {
            Char4_type='G';
        } else if(Char4_type=='a') {
            Char4_type='A';
        }
//檢查數值
        Char4_all = Char4_hp+Char4_atk+Char4_def;
        if((Char4_hp<40||Char4_hp>50)||(Char4_atk<15||Char4_atk>20)||(Char4_def<5||
                Char4_def>10)||(Char4_all<65||Char4_all>70)) {
            printf("錯誤:能力數值在限制範圍之外\n");
            return 0;
        }
//屬性錯時
        if(is_tf==1) {
            return 0;
        }
//顯示角色4
        printf ("\n");
        printf("角色4 \n");
        printf("名稱:自訂角色 \n");
        printf("屬性:%c    攻擊:%d  \n",Char4_type,Char4_atk);
        printf("血量:%d   防禦:%d  \n",Char4_hp,Char4_def);
        printf("強度預測:%.2f\n",( Char4_hp * 1.0 + Char4_atk * 0.8 + Char4_def * 0.5 - 50 ) * 6.5);
        printf ("\n");
    } else if(Add==2) {
    } else {
        printf("輸入錯誤\n");
        return 0;
    }
//選擇先後攻
    printf("選擇先攻角色: ");
    scanf("%d",&Char_frist);
    if(Char_frist<=0||Char_frist>Char_num) {
        printf("錯誤:無此角色\n");
        return 0;
    }
    printf("選擇後攻角色: ");
    scanf("%d",&Char_last);
    if(Char_last<=0||Char_last>Char_num) {
        printf("錯誤:無此角色\n");
        return 0;
    }
    printf("\n先攻為角色%d、後攻為角色%d\n",Char_frist,Char_last);
}

