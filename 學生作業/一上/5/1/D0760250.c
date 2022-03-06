#include <stdio.h>
#include <stdlib.h>

int main()
{
    //由左至右分別為:"是否要新增角色"之輸入、終止程式判斷值、先攻角色、後攻角色
    int user_input,end_value=0,select_char1,select_char2;

    char char1_type = 'F';
    int char1_hp = 40;
    int char1_atk = 15;
    int char1_def = 10;
    char char2_type = 'W';
    int char2_hp = 45;
    int char2_atk = 20;
    int char2_def = 5;
    char char3_type = 'A';
    int char3_hp = 40;
    int char3_atk = 20;
    int char3_def = 10;
    char char0_type;
    int char0_hp,char0_atk,char0_def ;

    printf("角色1\n名稱：SKY\n屬性\：%c     攻擊\：%d\n血量\：%d    防禦\：%d\n角色強度預測：%.2f\n\n"
           ,char1_type,char1_atk,char1_hp,char1_def,(char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5);
    printf("角色2\n名稱：SUN\n屬性\：%c     攻擊\：%d\n血量\：%d    防禦\：%d\n角色強度預測：%.2f\n\n"
           ,char2_type,char2_atk,char2_hp,char2_def,(char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5);
    printf("角色3\n名稱：DUST\n屬性\：%c     攻擊\：%d\n血量\：%d    防禦\：%d\n角色強度預測：%.2f\n\n"
           ,char3_type,char3_atk,char3_hp,char3_def,(char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5);

    printf("是否要新增角色(1.YES/2.NO)? ");
    scanf("%d%*c",&user_input);
    if(user_input==1){
        printf("\n新增角色(屬性總和=65~70)\n屬性(F/W/G/A):");
        scanf("%c",&char0_type);
        //如果是小寫，則轉換成大寫
        if((char0_type=='f')||(char0_type=='w')||(char0_type=='g')||(char0_type=='a')){
            char0_type=char0_type-32;
        }
        printf("輸入攻擊(15~20):");
        scanf("%d",&char0_atk);
        printf("輸入血量(40~50):");
        scanf("%d%*c",&char0_hp);
        printf("輸入防禦(5~10):");
        scanf("%d",&char0_def);
        //如我屬性不等於FWGA，則end_value+1
        if((char0_type!='F')&&(char0_type!='W')&&(char0_type!='G')&&(char0_type!='A')){
            printf("錯誤:無此屬性\n");
            end_value++;
        }
        //判斷能力數值是否在限制範圍內，如果為否，則end_value+1
        if(!(char0_atk>=15&&char0_atk<=20)||!(char0_hp>=40&&char0_hp<=50)||!(char0_def>=5&&char0_def<=10)||
           !(char0_atk+char0_hp+char0_def>=65&&char0_atk+char0_hp+char0_def<=70)){
            printf("錯誤:能力數值在限制範圍之外\n");
            end_value++;
        }
        //如果前兩項if條件都為假，則印出自訂角色
        if(end_value==0){
            printf("\n");
            printf("角色4\n名稱：自訂角色\n屬性\：%c     攻擊\：%d\n血量\：%d    防禦\：%d\n角色強度預測：%.2f\n\n"
                   ,char0_type,char0_atk,char0_hp,char0_def,(char0_hp*1.0+char0_atk*0.8+char0_def*0.5-50)*6.5);
        }
        //如果最前面兩項if條件有一個為真，則終止程式
        else{
            return 0;
        }
    }
    //如果"是否要新增角色"之輸入不等於1 or 2，則終止程式
    else if(user_input!=1&&user_input!=2){
        printf("輸入錯誤");
        return 0;
    }
    if(user_input==1||user_input==2){
        printf("選擇先攻角色:");
        scanf("%d",&select_char1);
        //判斷角色是否存在(由於"是否要新增角色"=1時，會新增角色4，所以條件會有3個)
        if(select_char1<1||(select_char1>3&&user_input!=1)||(select_char1>4&&user_input==1)){
            printf("錯誤:無此角色");
            return 0;
        }
        printf("選擇後攻角色:");
        scanf("%d",&select_char2);
        //判斷角色是否存在
        if(select_char2<1||(select_char2>3&&user_input!=1)||(select_char2>4&&user_input==1)){
            printf("錯誤:無此角色");
            return 0;
        }
        else if(select_char1==select_char2){
            printf("錯誤:不可重複選取");
            return 0;
        }
        else{
            printf("\n");
            printf("先攻角色為%d、後攻角色為%d",select_char1,select_char2);
        }
    }
    return 0;
}


