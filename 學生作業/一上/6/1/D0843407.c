#include <stdio.h>

int main(){
//宣告變數
    char Char1_type='W',Char2_type='F',Char3_type='G';//宣告屬性
    int Char1_atk=15,Char2_atk=20,Char3_atk=15;//宣告攻擊
    int Char1_hp=50,Char2_hp=40,Char3_hp=45;//宣告血量
    int Char1_def=5,Char2_def=5,Char3_def=10;//宣告防禦
//角色四
    char Char4_type;//角色4的屬性,攻擊,血量,防禦,角色4數值總和
    int Char4_atk,Char4_hp,Char4_def,Char4_all;//角色4的攻擊,血量,防禦,角色4數值總和
//檢查變數
    int Add,Char_num=3,Char_frist,Char_last;//新增角色,角色總數,先攻,後攻
    int is_nf1=0,is_nf2=0,is_ntf=0,is_nf3=0,is_nf4=0,is_nf5=0;/*新增錯誤flag(1),角色輸入錯誤flag(2),角色輸入只錯屬性flag
                                                                                                    角色先攻錯誤flag(3),角色後攻錯誤flag(4),先後攻重複錯誤flag(5)*/
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
    printf("屬性:%c    攻擊:%d  \n",Char3_type,Char3_atk);
    printf("血量:%d   防禦:%d  \n",Char3_hp,Char3_def);
    printf("強度預測:%.2f\n",( Char3_hp * 1.0 + Char3_atk * 0.8 + Char3_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
//新增角色錯誤重來的迴圈(1){含迴圈2}
    while(is_nf1==0){
        printf("是否新增角色(1.Yes/2.No)?");
        scanf("%d",&Add);
        getchar();
        printf ("\n");
        if(Add==1){
            is_nf1=1;//不重複迴圈(1)
            Char_num++;
//角色輸入錯誤重來的迴圈(2)
            while(is_nf2==0){
                is_nf2=1;//不重複迴圈(2)
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
                if(Char4_type!='F'&&Char4_type!='f'&&Char4_type!='W'&&Char4_type!='w'&&
                   Char4_type!='G'&&Char4_type!='g'&&Char4_type!='A'&&Char4_type!='a'){
                    printf("錯誤:無此屬性\n");
                    //為啥事&&不是||
                    is_nf2=0;//重複迴圈(2)
                    is_ntf=1;//屬性有錯
                }
//小寫換大寫
                else if(Char4_type=='f'){
                    Char4_type='F';
                }
                else if(Char4_type=='w'){
                    Char4_type='W';
                }
                else if(Char4_type=='g'){
                    Char4_type='G';
                }
                else if(Char4_type=='a'){
                    Char4_type='A';
                }
//檢查數值
                Char4_all = Char4_hp+Char4_atk+Char4_def;
                if((Char4_hp<40||Char4_hp>50)||(Char4_atk<15||Char4_atk>20)||
                (Char4_def<5||Char4_def>10)||(Char4_all<65||Char4_all>70)){
                    printf("錯誤:能力數值在限制範圍之外\n\n");
                    is_nf2=0;//重複迴圈(2)
                    is_ntf=0;//連錯兩個,不用觸發角色輸入只錯屬性flag
                }
//角色輸入只錯屬性,補\n給他-flag
                if(is_ntf==1){
                    printf ("\n");
                }
            }
//顯示角色4
            printf ("\n");
            printf("角色4 \n");
            printf("名稱:自訂角色 \n");
            printf("屬性:%c    攻擊:%d  \n",Char4_type,Char4_atk);
            printf("血量:%d   防禦:%d  \n",Char4_hp,Char4_def);
            printf("強度預測:%.2f\n",( Char4_hp * 1.0 + Char4_atk * 0.8 + Char4_def * 0.5 - 50 ) * 6.5);
            printf ("\n");
        }
//讓只錯屬性有\n
        else if(Add==2){
            is_nf1=1;//不重複迴圈(1)
        }
        else{
            printf("輸入錯誤\n\n");
        }
    }
//角色重複選取重來的迴圈(5){含迴圈3.4}
    while(is_nf5==0){
        is_nf5=1;//不重複迴圈(5)
//角色先攻錯誤重來的迴圈(3)
        while(is_nf3==0){
            is_nf3=1;//不重複迴圈(3)
            printf("選擇先攻角色: ");
            scanf("%d",&Char_frist);
            if(Char_frist<=0||Char_frist>Char_num){
                printf("錯誤:無此角色\n");
                is_nf3=0;//重複迴圈(3)
            }
        }
//角色後攻錯誤重來的迴圈(4)
        while(is_nf4==0){
            is_nf4=1;//不重複迴圈(4)
            printf("選擇後攻角色: ");
            scanf("%d",&Char_last);
            if(Char_last<=0||Char_last>Char_num){
                printf("錯誤:無此角色\n");
                is_nf4=0;//重複迴圈(4)
            }
        }
        if(Char_last==Char_frist){
            printf("錯誤:不可重複選取\n\n");
            is_nf5=0;//重複迴圈(5)
            is_nf3=0;//重製迴圈(3)
            is_nf4=0;//重製迴圈(4)
        }
    }
    printf("\n先攻為角色%d、後攻為角色%d\n",Char_frist,Char_last);
//取出角色數值
    int FA_atk,FA_hp,FA_def;//宣告先攻數值
    int LA_atk,LA_hp,LA_def;//宣告後攻數值
//先攻角色數值取出
    if(Char_frist==1){
        FA_atk=Char1_atk;
        FA_hp=Char1_hp;
        FA_def=Char1_def;
    }
    else if(Char_frist==2){
        FA_atk=Char2_atk;
        FA_hp=Char2_hp;
        FA_def=Char2_def;
    }
    else if(Char_frist==3){
        FA_atk=Char3_atk;
        FA_hp=Char3_hp;
        FA_def=Char3_def;
    }
    else if(Char_frist==4){
        FA_atk=Char4_atk;
        FA_hp=Char4_hp;
        FA_def=Char4_def;
    }
//後攻角色數值取出
    if(Char_last==1){
        LA_atk=Char1_atk;
        LA_hp=Char1_hp;
        LA_def=Char1_def;
    }
    else if(Char_last==2){
        LA_atk=Char2_atk;
        LA_hp=Char2_hp;
        LA_def=Char2_def;
    }
    else if(Char_last==3){
        LA_atk=Char3_atk;
        LA_hp=Char3_hp;
        LA_def=Char3_def;
    }
    else if(Char_last==4){
        LA_atk=Char4_atk;
        LA_hp=Char4_hp;
        LA_def=Char4_def;
    }
//戰鬥開始
    int demage,is_whowin,winner,loser;//宣告傷害,誰勝flag,勝利者,失敗者
    printf("戰鬥開始\n\n");
//戰鬥迴圈(6)
    while(1){
        demage = FA_atk - LA_def;
        LA_hp -= demage;
        printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",Char_frist,Char_last,demage);
        printf("角色%d HP: %d\t角色%d HP:%d\n\n",Char_frist,FA_hp,Char_last,LA_hp);
        if(LA_hp<=0){
            is_whowin=1;//先攻勝
            break;//跳出迴圈(6)
        }
        demage = LA_atk - FA_def;
        FA_hp -= demage;
        printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",Char_last,Char_frist,demage);
        printf("角色%d HP: %d\t角色%d HP:%d\n\n",Char_frist,FA_hp,Char_last,LA_hp);
        if(FA_hp<=0){
            is_whowin=0;//後攻勝
            break;//跳出迴圈(6)
        }
    }
//勝敗判定
    if(is_whowin==1){
        winner=Char_frist;
        loser=Char_last;
    }
    else{
        winner=Char_last;
        loser=Char_frist;
    }
//顯示勝敗
    printf("角色%d 失去戰鬥能力\n",loser);
    printf("戰鬥結束\n\n");
    printf("角色%d 獲勝\n",winner);
    return 0;
}

