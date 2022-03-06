#include <stdio.h>
#include<string.h>

int main(){
//宣告變數
    char Char1_name[21]="傑尼龜",Char2_name[21]="小火龍",Char3_name[21]="小拳石",Char4_name[21];
    char type[4]={'W','A','G'};
    int atk[4]={15,20,15,-1};
    int hp[4]={50,40,45,-1};
    int def[4]={5,8,10,-1};

//檢查變數
    int Add,Char_num=3,Char_frist,Char_last;
    int case_num=5,is_Char4_exist=0;
    int is_nf1=0,is_nf2=0,is_ntf=0,is_nf3=0,is_nf4=0,is_nf5=0;
    while(1){
        printf("1.新增或修改角色\n");
        printf("2.顯示所有角色資料\n");
        printf("3.戰鬥\n");
        printf("0.結束遊戲\n");
        printf("請選擇:");
        scanf("%d",&case_num);
        printf("\n");
        switch(case_num){
            case 1:
                while(is_nf2==0){
                    is_nf2=1;
                    if(is_Char4_exist==0){
                        printf("新增角色\n");
                    }
                    else
                        printf("修改新增角色\n");
                    printf("名稱:");
                    scanf("%s",&Char4_name);
                    getchar();
                    printf("屬性:");
                    scanf("%c",&type[3]);
                    getchar();
                    printf("血量:");
                    scanf("%d",&hp[3]);
                    getchar();
                    printf("攻擊:");
                    scanf("%d",&atk[3]);
                    getchar();
                    printf("防禦:");
                    scanf("%d",&def[3]);
                    getchar();
                    if(type[3]!='F'&&type[3]!='f'&&type[3]!='W'&&type[3]!='w'&&
                        type[3]!='G'&&type[3]!='g'&&type[3]!='A'&&type[3]!='a'){
                        printf("錯誤:無此屬性\n");
                        is_nf2=0;//重複迴圈(2)
                        is_ntf=1;//屬性有錯
                        }
                    //小寫換大寫
                    else if(type[3]=='f'){
                        type[3]='F';
                    }
                    else if(type[3]=='w'){
                        type[3]='W';
                    }
                    else if(type[3]=='g'){
                        type[3]='G';
                    }
                    else if(type[3]=='a'){
                        type[3]='A';
                    }
                    //檢查數值
                    int Char4_all = hp[3]+atk[3]+def[3];
                    if((hp[3]<40||hp[3]>50)||(atk[3]<15||atk[3]>20)||
                    (def[3]<5||def[3]>10)||(Char4_all<65||Char4_all>70)){
                        printf("錯誤:能力數值在限制範圍之外\n\n");
                        is_nf2=0;//重複迴圈(2)
                        is_ntf=0;//連錯兩個,不用觸發角色輸入只錯屬性flag
                    }
                    //角色輸入只錯屬性,補\n給他-flag
                    if(is_ntf==1){
                        printf ("\n");
                    }
                }
                is_nf2=0;
                printf ("\n");
                printf("角色4 \n");
                printf("名稱:%s \n",Char4_name);
                printf("屬性:%c    攻擊:%d  \n",type[3],atk[3]);
                printf("血量:%d   防禦:%d  \n",hp[3],def[3]);
                printf("強度預測:%.2f\n",( hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5 - 50 ) * 6.5);
                printf ("\n");
                is_Char4_exist=1;
                Char_num=4;
                break;
            case 2:
                printf("角色1 \n");
                printf("名稱:%s \n",Char1_name);
                printf("屬性:%c    攻擊:%d  \n",type[0],atk[0]);
                printf("血量:%d   防禦:%d  \n",hp[0],def[0]);
                printf("強度預測:%.2f\n",( hp[0] * 1.0 + atk[0] * 0.8 + def[0] * 0.5 - 50 ) * 6.5);
                printf ("\n");
                printf("角色2 \n");
                printf("名稱:%s \n",Char2_name);
                printf("屬性:%c    攻擊:%d  \n",type[1],atk[1]);
                printf("血量:%d   防禦:%d  \n",hp[1],def[1]);
                printf("強度預測:%.2f\n",( hp[1] * 1.0 + atk[1] * 0.8 + def[1] * 0.5 - 50 ) * 6.5);
                printf ("\n");
                printf("角色3 \n");
                printf("名稱:%s \n",Char3_name);
                printf("屬性:%c    攻擊:%d  \n",type[2],atk[2]);
                printf("血量:%d   防禦:%d  \n",hp[2],def[2]);
                printf("強度預測:%.2f\n",( hp[2] * 1.0 + atk[2] * 0.8 + def[2] * 0.5 - 50 ) * 6.5);
                printf ("\n");
                if(is_Char4_exist==1){
                    printf ("\n");
                    printf("角色4 \n");
                    printf("名稱:%s \n",Char4_name);
                    printf("屬性:%c    攻擊:%d  \n",type[3],atk[3]);
                    printf("血量:%d   防禦:%d  \n",hp[3],def[3]);
                    printf("強度預測:%.2f\n",( hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5 - 50 ) * 6.5);
                    printf ("\n");
                }
                break;
            case 3:
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
                //
                int FA_atk,FA_hp,FA_def;//宣告先攻數值
                int LA_atk,LA_hp,LA_def;//宣告後攻數值
                FA_atk=atk[Char_frist-1];
                FA_hp=hp[Char_frist-1];
                FA_def=def[Char_frist-1];
                LA_atk=atk[Char_last-1];
                LA_hp=hp[Char_last-1];
                LA_def=def[Char_last-1];
                //屬性倍率
                double FA_attX=1,LA_attX=1,FAblood=1,LAblood=1;
                if(type[Char_frist-1]=='W'||type[Char_last-1]=='F'){
                    FA_attX=1.2;
                    LA_attX=0.8;
                }
                if(type[Char_frist-1]=='F'||type[Char_last-1]=='A'){
                    FA_attX=1.2;
                    LA_attX=0.8;
                }
                if(type[Char_frist-1]=='A'||type[Char_last-1]=='G'){
                    FA_attX=1.2;
                    LA_attX=0.8;
                }
                if(type[Char_frist-1]=='G'||type[Char_last-1]=='W'){
                    FA_attX=1.2;
                    LA_attX=0.8;
                }
                //
                if(type[Char_frist-1]=='F'&&type[Char_last-1]=='W'){
                    FA_attX=0.8;
                    LA_attX=1.2;
                }
                if(type[Char_frist-1]=='A'&&type[Char_last-1]=='F'){
                    FA_attX=0.8;
                    LA_attX=1.2;
                }
                if(type[Char_frist-1]=='G'&&type[Char_last-1]=='A'){
                    FA_attX=0.8;
                    LA_attX=1.2;
                }
                if(type[Char_frist-1]=='W'&&type[Char_last-1]=='G'){
                    FA_attX=0.8;
                    LA_attX=1.2;
                }
                int FAfull=hp[Char_frist-1];
                int LAfull=hp[Char_last-1];
                //
                double demage;
                int is_whowin,winner,loser,demage1;//宣告傷害,誰勝flag,勝利者,失敗者
                printf("戰鬥開始\n\n");
                while(1){
                    if(FA_hp<FAfull/2){
                        FAblood=1.2;
                    }
                    demage = FA_atk*FA_attX*FAblood - LA_def;
                    demage1=demage;
                    LA_hp -= demage;
                    printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",Char_frist,Char_last,demage1);
                    printf("角色%d HP: %d\t角色%d HP:%d\n\n",Char_frist,FA_hp,Char_last,LA_hp);
                    if(LA_hp<=0){
                        is_whowin=1;//先攻勝
                        break;//跳出迴圈(6)
                    }
                    if(LA_hp<LAfull/2){
                        LAblood=1.2;
                    }
                    demage = LA_atk*LA_attX*LAblood - FA_def;
                    demage1=demage;
                    FA_hp -= demage;
                    printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",Char_last,Char_frist,demage1);
                    printf("角色%d HP: %d\t角色%d HP:%d\n\n",Char_frist,FA_hp,Char_last,LA_hp);
                    if(FA_hp<=0){
                        is_whowin=0;//後攻勝
                        break;//跳出迴圈(6)
                    }
                }
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
                printf("角色%d 獲勝\n\n",winner);
                break;
            case 0:
                return 0;
                break;
            default:
                printf("輸入錯誤\n\n");
                break;
        }
    }
}

