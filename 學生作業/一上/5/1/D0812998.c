 #include<stdio.h>
 int main()
 {
    char char1_type = 'F';
    int  char1_hp= 45;
    int  char1_atk= 16;
    int  char1_def= 5;
    float  char1_power=(char1_hp*1.0+char1_atk*0.8+char1_def*0.5 -50)*6.5;
    char char2_type = 'A';
    int  char2_hp= 40;
    int  char2_atk= 20;
    int  char2_def= 8;
    float  char2_power=(char2_hp*1.0+char2_atk*0.8+char2_def*0.5 -50)*6.5;
    char char3_type = 'G';
    int  char3_hp = 50;
    int  char3_atk = 16;
    int  char3_def = 5;
    float  char3_power=(char3_hp*1.0+char3_atk*0.8+char3_def*0.5 -50)*6.5;
    char char4_type;
    int  char4_hp;
    int  char4_atk;
    int  char4_def;

    printf("角色1\n"
            "名稱：王銘宏\n"
            "屬性：%-6c    攻擊：%-6d\n"
            "血量：%-6d    防禦：%-6d\n"
            "角色強度預測:%.2f\n",char1_type,char1_atk,char1_hp,char1_def,char1_power);
    printf("角色2\n"
            "名稱:宏銘王\n"
            "屬性：%-6c    攻擊：%-6d\n"
            "血量：%-6d    防禦：%-6d\n"
            "角色強度預測:%.2f\n",char2_type,char2_atk,char2_hp,char2_def,char2_power);
    printf("角色3\n"
            "名稱：老師對不起我不該玩你的名子\n"
            "屬性：%-6c    攻擊：%-6d\n"
            "血量：%-6d    防禦：%-6d\n"
            "角色強度預測:%.2f\n",char3_type,char3_atk,char3_hp,char3_def,char3_power);

    int choose,fir,sec;
        printf("\n是否新增角色(1.Yes/2.No)? ");
        scanf("%d",&choose);
    switch(choose){
        case(1):
            printf("\n新增角色\n");
            printf("屬性:");
            scanf(" %c",&char4_type);
            printf("血量:");
            scanf("%d",&char4_hp);
            printf("攻擊:");
            scanf("%d",&char4_atk);
            printf("防禦:");
            scanf("%d",&char4_def);
            if(char4_type!='F'&&char4_type!='G'&&char4_type!='A'&&char4_type!='W'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a'){//角色4屬性不符合條件
                printf("錯誤:無此屬性\n");
                if(15>char4_atk||char4_atk>20|40>char4_hp|char4_hp>50|5>char4_def|char4_def>10|65>(char4_hp+char4_atk+char4_def)|(char4_hp+char4_atk+char4_def)>70){//角色4數值不符合條件
                    printf("錯誤:能力範圍在限制範圍之外\n");}
                    break;}
            if(15>char4_atk||char4_atk>20|40>char4_hp|char4_hp>50|5>char4_def|char4_def>10|65>(char4_hp+char4_atk+char4_def)|(char4_hp+char4_atk+char4_def)>70){//角色4數值不符合條件
                printf("錯誤:能力範圍在限制範圍之外\n");
                break;}
            float  char4_power=(char4_hp*1.0+char4_atk*0.8+char4_def*0.5 -50)*6.5;
            if(isupper(char4_type)==0){//是否為大寫字母
                char4_type=toupper(char4_type);//轉換成大寫字母
            }
            printf("\n角色4\n名稱:自訂角色\n"
            "屬性:%-6c    攻擊:%-6d\n"
            "血量:%-6d    防禦:%-6d\n\n"
            "角色強度預測:%.2f\n",char4_type,char4_atk,char4_hp,char4_def,char4_power);

            printf("\n選擇先攻角色:");
            scanf("%d",&fir);
            if(fir>4){//先攻角色要小於4
                printf("錯誤:無此角色\n");
                break;}
            printf("選擇後攻角色:\n");
            scanf("%d",&sec);
            if(sec>4){//後攻角色要小於4
                printf("錯誤:無此角色\n");
                break;}
            if(fir==sec){//先攻角色不等於後攻角色
                printf("錯誤:不可重複選取\n");
                break;}
            printf("先攻為角色%d、後攻為角色%d\n",fir,sec);
                break;
        case(2):
            printf("\n選擇先攻角色:");
            scanf("%d",&fir);
            if(fir>3){//先攻角色要小於3
                printf("錯誤:無此角色\n");
                break;}
            printf("選擇後攻角色:");
            scanf("%d",&sec);
            if(sec>3){//後攻角色要小於3
                printf("錯誤:無此角色\n");
                break;}
            if(fir==sec){//先攻角色不等於後攻角色
                printf("錯誤:不可重複選取\n");
                break;}
            printf("\n先攻為角色%d、後攻為角色%d\n",fir,sec);
            break;
        default:
            printf("輸入錯誤\n");
            break;
    }


     return 0;
 }
