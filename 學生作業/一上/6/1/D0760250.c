#include <stdio.h>
#include <stdlib.h>

int main()
{
    //由左至右分別為:"是否要新增角色"之輸入、是否繼續迴圈判斷值、先攻角色、後攻角色、贏家、輸家
    int user_input=0,repeat_value=1,select_char1,select_char2,win,lose;
    //先攻後攻的數據資料
    int select_char1_hp,select_char1_atk,select_char1_def;
    int select_char2_hp,select_char2_atk,select_char2_def;

    char char1_type = 'F';
    int char1_hp = 50;
    int char1_atk = 15;
    int char1_def = 5;
    char char2_type = 'W';
    int char2_hp = 45;
    int char2_atk = 20;
    int char2_def = 5;
    char char3_type = 'A';
    int char3_hp = 40;
    int char3_atk = 20;
    int char3_def = 10;
    char char4_type;
    int char4_hp,char4_atk,char4_def ;

    printf("角色1\n名稱：SKY\n屬性\：%c     攻擊\：%d\n血量\：%d    防禦\：%d\n角色強度預測：%.2f\n\n"
           ,char1_type,char1_atk,char1_hp,char1_def,(char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5);
    printf("角色2\n名稱：SUN\n屬性\：%c     攻擊\：%d\n血量\：%d    防禦\：%d\n角色強度預測：%.2f\n\n"
           ,char2_type,char2_atk,char2_hp,char2_def,(char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5);
    printf("角色3\n名稱：DUST\n屬性\：%c     攻擊\：%d\n血量\：%d    防禦\：%d\n角色強度預測：%.2f\n\n"
           ,char3_type,char3_atk,char3_hp,char3_def,(char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5);

    //如果user_input不等於1or2，則再次詢問"是否要新增角色"
    while(user_input!=1&&user_input!=2){
        printf("是否要新增角色(1.YES/2.NO)? ");
        scanf("%d%*c",&user_input);
        if(user_input==1){
            while(repeat_value==1){
                repeat_value=0;
                printf("\n新增角色(屬性總和=65~70)\n屬性(F/W/G/A):");
                scanf("%c",&char4_type);
                //如果是小寫，則轉換成大寫
                if((char4_type=='f')||(char4_type=='w')||(char4_type=='g')||(char4_type=='a')){
                    char4_type=char4_type-32;
                }
                printf("輸入血量(40~50):");
                scanf("%d",&char4_hp);
                printf("輸入攻擊(15~20):");
                scanf("%d",&char4_atk);
                printf("輸入防禦(5~10):");
                scanf("%d%*c",&char4_def);
                //如果屬性不等於FWGA，則repeat_value=1，繼續重複輸入角色資料
                if((char4_type!='F')&&(char4_type!='W')&&(char4_type!='G')&&(char4_type!='A')){
                    printf("錯誤:無此屬性\n");
                    repeat_value=1;
                }
                //判斷能力數值是否在限制範圍內，如果為否，則repeat_value=1，繼續重複輸入角色資料
                if(!(char4_atk>=15&&char4_atk<=20)||!(char4_hp>=40&&char4_hp<=50)||!(char4_def>=5&&char4_def<=10)||
                   !(char4_atk+char4_hp+char4_def>=65&&char4_atk+char4_hp+char4_def<=70)){
                    printf("錯誤:能力數值在限制範圍之外\n");
                    repeat_value=1;
                }
                //如果前兩項if條件都為假，則印出自訂角色
                if(repeat_value==0){
                    printf("\n");
                    printf("角色4\n名稱：自訂角色\n屬性\：%c     攻擊\：%d\n血量\：%d    防禦\：%d\n角色強度預測：%.2f\n\n"
                           ,char4_type,char4_atk,char4_hp,char4_def,(char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5);
                }
            }
        }

        //如果"是否要新增角色"之輸入不等於1 or 2，則印出"輸入錯誤"
        else if(user_input!=1&&user_input!=2){
            printf("輸入錯誤\n");
        }
    }

    repeat_value=1;
    while(repeat_value==1){
        repeat_value=0;
        printf("選擇先攻角色:");
        scanf("%d",&select_char1);
        //判斷角色是否存在(由於"是否要新增角色"=1時，會新增角色4，所以條件會有3個)
        //如果輸入錯誤，則repeat_value=1，重複輸入先攻角色
        if(select_char1<1||(select_char1>3&&user_input!=1)||(select_char1>4&&user_input==1)){
            printf("錯誤:無此角色\n");
            repeat_value=1;
        }
    }
    repeat_value=1;
    //如果"錯誤:無此角色"或"錯誤:不可重複選取"，則repeat_value=1，重複輸入後攻角色
    while(repeat_value==1){
        printf("選擇後攻角色:");
        scanf("%d",&select_char2);
        //判斷角色是否存在
        if(select_char2<1||(select_char2>3&&user_input!=1)||(select_char2>4&&user_input==1)){
            printf("錯誤:無此角色\n");
            repeat_value=1;
        }
        else if(select_char1==select_char2){
            printf("錯誤:不可重複選取\n");
            repeat_value=1;
        }
        //如果輸入正確，則將先攻後攻角色數值取出
        else{
            printf("\n先攻角色為%d、後攻角色為%d\n",select_char1,select_char2);
            switch(select_char1){
                case 1:
                    select_char1_hp=char1_hp;
                    select_char1_atk=char1_atk;
                    select_char1_def=char1_def;
                    break;
                case 2:
                    select_char1_hp=char2_hp;
                    select_char1_atk=char2_atk;
                    select_char1_def=char2_def;
                    break;
                case 3:
                    select_char1_hp=char3_hp;
                    select_char1_atk=char3_atk;
                    select_char1_def=char3_def;
                    break;
                case 4:
                    select_char1_hp=char4_hp;
                    select_char1_atk=char4_atk;
                    select_char1_def=char4_def;

            }
            switch(select_char2){
                case 1:
                    select_char2_hp=char1_hp;
                    select_char2_atk=char1_atk;
                    select_char2_def=char1_def;
                    break;
                case 2:
                    select_char2_hp=char2_hp;
                    select_char2_atk=char2_atk;
                    select_char2_def=char2_def;
                    break;
                case 3:
                    select_char2_hp=char3_hp;
                    select_char2_atk=char3_atk;
                    select_char2_def=char3_def;
                    break;
                case 4:
                    select_char2_hp=char4_hp;
                    select_char2_atk=char4_atk;
                    select_char2_def=char4_def;

            }
            repeat_value=0;//跳出迴圈
        }
    }
    printf("戰鬥開始\n\n");
    //如果雙方血量都沒小於0，則繼續戰鬥
    while(select_char1_hp>0&&select_char2_hp>0){
        //先攻的攻擊
        select_char2_hp=select_char2_hp-(select_char1_atk-select_char2_def);
        printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n角色%d HP: %d 角色%d HP: %d\n\n"
               ,select_char1,select_char2,select_char1_atk-select_char2_def,select_char1,select_char1_hp,select_char2,select_char2_hp);
        //判斷雙方血量，來決定是否跳出迴圈
        if(select_char1_hp<=0||select_char2_hp<=0){
            break;
        }
        //後攻的攻擊
        select_char1_hp=select_char1_hp-(select_char2_atk-select_char1_def);
        printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n角色%d HP: %d 角色%d HP: %d\n\n"
               ,select_char2,select_char1,select_char2_atk-select_char1_def,select_char1,select_char1_hp,select_char2,select_char2_hp);
    }
    //判斷輸贏家
    if(select_char1_hp<=0){
        win=select_char2;
        lose=select_char1;
    }
    else{
        win=select_char1;
        lose=select_char2;
    }
    printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝",lose,win);

    return 0;
}


