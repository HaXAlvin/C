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
    int  atk1_hp;
    int  atk1_atk;
    int  atk1_def;
    int  atk2_hp;
    int  atk2_atk;
    int  atk2_def;

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

            while((char4_type!='F'&&char4_type!='G'&&char4_type!='A'&&char4_type!='W'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a')||(15>char4_atk||char4_atk>20|40>char4_hp|char4_hp>50|5>char4_def|char4_def>10|65>(char4_hp+char4_atk+char4_def)|(char4_hp+char4_atk+char4_def)>70)){//輸入錯誤重新輸入
            	if(char4_type!='F'&&char4_type!='G'&&char4_type!='A'&&char4_type!='W'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a')//角色屬性不符合條件
					printf("錯誤:無此屬性\n");
				if(15>char4_atk||char4_atk>20|40>char4_hp|char4_hp>50|5>char4_def|char4_def>10|65>(char4_hp+char4_atk+char4_def)|(char4_hp+char4_atk+char4_def)>70)//角色能力範圍不符合條件
				printf("錯誤:能力範圍在限制範圍之外\n");
		   		printf("\n新增角色\n");
            	printf("屬性:");
            	scanf(" %c",&char4_type);
            	printf("血量:");
            	scanf("%d",&char4_hp);
            	printf("攻擊:");
            	scanf("%d",&char4_atk);
            	printf("防禦:");
            	scanf("%d",&char4_def);
			}

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
            while(fir>4){//先攻角色要小於4
                printf("錯誤:無此角色\n");
                printf("\n選擇先攻角色:");
                scanf("%d",&fir);
            }
            printf("選擇後攻角色:");
            scanf("%d",&sec);
            while(sec>4){//後攻角色要小於4
                printf("錯誤:無此角色\n");
                printf("\n選擇後攻角色:");
                scanf("%d",&sec);
            }
            while(fir==sec){//先攻角色不等於後攻角色
                printf("錯誤:不可重複選取\n");
                printf("\n選擇先攻角色:");
            	scanf("%d",&fir);
                while(fir>4){//先攻角色要小於4
                    printf("錯誤:無此角色\n");
                    printf("\n選擇先攻角色:");
                    scanf("%d",&fir);
                }
                printf("選擇後攻角色:");
                scanf("%d",&sec);
                while(sec>4){//後攻角色要小於4
                    printf("錯誤:無此角色\n");
                    printf("\n選擇後攻角色:");
                    scanf("%d",&sec);
                }
            }

            printf("先攻為角色%d、後攻為角色%d\n",fir,sec);
            printf("戰鬥開始\n\n");
            if(fir==1){//建立暫存
                atk1_hp = char1_hp;
                atk1_def = char1_def;
                atk1_atk = char1_atk;
            }else if(fir==2){
                atk1_hp = char2_hp;
                atk1_def = char2_def;
                atk1_atk = char2_atk;
            }else if(fir==3){
                atk1_hp = char3_hp;
                atk1_def = char3_def;
                atk1_atk = char3_atk;
            }else if(fir==4){
                atk1_hp = char4_hp;
                atk1_def = char4_def;
                atk1_atk = char4_atk;
            }
            if(sec==1){
                atk2_hp = char1_hp;
                atk2_def = char1_def;
                atk2_atk = char1_atk;
            }else if(sec==2){
                atk2_hp = char2_hp;
                atk2_def = char2_def;
                atk2_atk = char2_atk;
            }else if(sec==3){
                atk2_hp = char3_hp;
                atk2_def = char3_def;
                atk2_atk = char3_atk;
            }else if(sec==4){
                atk2_hp = char4_hp;
                atk2_def = char4_def;
                atk2_atk = char4_atk;
            }
            int hur1 = atk1_atk - atk2_def;
            int hur2 = atk2_atk - atk1_def;
            do{
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n",fir,sec,hur1);
                printf("角色%d HP:%d 角色%d HP:%d\n\n",fir,atk1_hp,sec,atk2_hp-=hur1);
                if(atk2_hp<=0){
                    printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",sec,fir);
                    break;}
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n",sec,fir,hur2);
                printf("角色%d HP:%d 角色%d HP:%d\n\n",fir,atk1_hp-=hur2,sec,atk2_hp);

            }while(0<atk1_hp&&0<atk2_hp);
            if(atk1_hp<=0){
                printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",fir,sec);
                break;
            }
            break;




        case(2):
            printf("\n選擇先攻角色:");
            scanf("%d",&fir);
    		while(fir>4){//先攻角色要小於4
                printf("錯誤:無此角色\n");
                printf("\n選擇先攻角色:");
                scanf("%d",&fir);
            }
            printf("選擇後攻角色:");
            scanf("%d",&sec);
            while(sec>4){//後攻角色要小於4
                printf("錯誤:無此角色\n");
                printf("\n選擇後攻角色:");
                scanf("%d",&sec);
            }
            while(fir==sec){//先攻角色不等於後攻角色
                    printf("錯誤:不可重複選取\n");
                    printf("\n選擇先攻角色:");
                    scanf("%d",&fir);
                while(fir>4){//先攻角色要小於4
                    printf("錯誤:無此角色\n");
                    printf("\n選擇先攻角色:");
                    scanf("%d",&fir);
                }
                printf("選擇後攻角色:");
                scanf("%d",&sec);
                while(sec>4){//後攻角色要小於4
                    printf("錯誤:無此角色\n");
                    printf("\n選擇後攻角色:");
                    scanf("%d",&sec);
                }
            }

            printf("先攻為角色%d、後攻為角色%d\n",fir,sec);
            printf("戰鬥開始\n\n");
            if(fir==1){//建立暫存
                atk1_hp = char1_hp;
                atk1_def = char1_def;
                atk1_atk = char1_atk;
            }else if(fir==2){
                atk1_hp = char2_hp;
                atk1_def = char2_def;
                atk1_atk = char2_atk;
            }else if(fir==3){
                atk1_hp = char3_hp;
                atk1_def = char3_def;
                atk1_atk = char3_atk;
            }else if(fir==4){
                atk1_hp = char4_hp;
                atk1_def = char4_def;
                atk1_atk = char4_atk;
            }
            if(sec==1){
                atk2_hp = char1_hp;
                atk2_def = char1_def;
                atk2_atk = char1_atk;
            }else if(sec==2){
                atk2_hp = char2_hp;
                atk2_def = char2_def;
                atk2_atk = char2_atk;
            }else if(sec==3){
                atk2_hp = char3_hp;
                atk2_def = char3_def;
                atk2_atk = char3_atk;
            }else if(sec==4){
                atk2_hp = char4_hp;
                atk2_def = char4_def;
                atk2_atk = char4_atk;
            }
            do{
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n",fir,sec,hur1);
                printf("角色%d HP:%d 角色%d HP:%d\n\n",fir,atk1_hp,sec,atk2_hp-=hur1);
                if(atk2_hp<=0){
                    printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",sec,fir);
                    break;}
                printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n",sec,fir,hur2);
                printf("角色%d HP:%d 角色%d HP:%d\n\n",fir,atk1_hp-=hur2,sec,atk2_hp);
            }while(0<atk1_hp&&0<atk2_hp);
            if(atk1_hp<=0){
                printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",fir,sec);
                break;
            }
            break;

        default:
            while(choose>2){//輸入錯誤重新輸入
            	printf("輸入錯誤\n");
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

                    while((char4_type!='F'&&char4_type!='G'&&char4_type!='A'&&char4_type!='W'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a')||(15>char4_atk||char4_atk>20|40>char4_hp|char4_hp>50|5>char4_def|char4_def>10|65>(char4_hp+char4_atk+char4_def)|(char4_hp+char4_atk+char4_def)>70)){
                        if(char4_type!='F'&&char4_type!='G'&&char4_type!='A'&&char4_type!='W'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a')
                            printf("錯誤:無此屬性\n");
                        if(15>char4_atk||char4_atk>20|40>char4_hp|char4_hp>50|5>char4_def|char4_def>10|65>(char4_hp+char4_atk+char4_def)|(char4_hp+char4_atk+char4_def)>70)
                        printf("錯誤:能力範圍在限制範圍之外\n");
                        printf("\n新增角色\n");
                        printf("屬性:");
                        scanf(" %c",&char4_type);
                        printf("血量:");
                        scanf("%d",&char4_hp);
                        printf("攻擊:");
                        scanf("%d",&char4_atk);
                        printf("防禦:");
                        scanf("%d",&char4_def);
                    }

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
                    while(fir>4){//先攻角色要小於4
                        printf("錯誤:無此角色\n");
                        printf("\n選擇先攻角色:");
                        scanf("%d",&fir);
                    }
                    printf("選擇後攻角色:");
                    scanf("%d",&sec);
                    while(sec>4){//後攻角色要小於4
                        printf("錯誤:無此角色\n");
                        printf("\n選擇後攻角色:");
                        scanf("%d",&sec);
                    }
                    while(fir==sec){//先攻角色不等於後攻角色
                        printf("錯誤:不可重複選取\n");
                        printf("\n選擇先攻角色:");
                        scanf("%d",&fir);
                        while(fir>4){//先攻角色要小於4
                            printf("錯誤:無此角色\n");
                            printf("\n選擇先攻角色:");
                            scanf("%d",&fir);
                        }
                        printf("選擇後攻角色:");
                        scanf("%d",&sec);
                        while(sec>4){//後攻角色要小於4
                            printf("錯誤:無此角色\n");
                            printf("\n選擇後攻角色:");
                            scanf("%d",&sec);
                        }
                    }
                    printf("先攻為角色%d、後攻為角色%d\n",fir,sec);
                    printf("戰鬥開始\n\n");
                    if(fir==1){
                        atk1_hp = char1_hp;
                        atk1_def = char1_def;
                        atk1_atk = char1_atk;
                    }else if(fir==2){
                        atk1_hp = char2_hp;
                        atk1_def = char2_def;
                        atk1_atk = char2_atk;
                    }else if(fir==3){
                        atk1_hp = char3_hp;
                        atk1_def = char3_def;
                        atk1_atk = char3_atk;
                    }else if(fir==4){
                        atk1_hp = char4_hp;
                        atk1_def = char4_def;
                        atk1_atk = char4_atk;
                    }
                    if(sec==1){
                        atk2_hp = char1_hp;
                        atk2_def = char1_def;
                        atk2_atk = char1_atk;
                    }else if(sec==2){
                        atk2_hp = char2_hp;
                        atk2_def = char2_def;
                        atk2_atk = char2_atk;
                    }else if(sec==3){
                        atk2_hp = char3_hp;
                        atk2_def = char3_def;
                        atk2_atk = char3_atk;
                    }else if(sec==4){
                        atk2_hp = char4_hp;
                        atk2_def = char4_def;
                        atk2_atk = char4_atk;
                    }
                    int hur1 = atk1_atk - atk2_def;
                    int hur2 = atk2_atk - atk1_def;
                    do{
                        printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n",fir,sec,hur1);
                        printf("角色%d HP:%d 角色%d HP:%d\n\n",fir,atk1_hp,sec,atk2_hp-=hur1);
                        if(atk2_hp<=0){
                            printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",sec,fir);
                            break;}
                        printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n",sec,fir,hur2);
                        printf("角色%d HP:%d 角色%d HP:%d\n\n",fir,atk1_hp-=hur2,sec,atk2_hp);

                    }while(0<atk1_hp&&0<atk2_hp);
                    if(atk1_hp<=0){
                        printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",fir,sec);
                        break;
                    }
                    break;




                case(2):
                    printf("\n選擇先攻角色:");
                    scanf("%d",&fir);
                    while(fir>4){//先攻角色要小於4
                        printf("錯誤:無此角色\n");
                        printf("\n選擇先攻角色:");
                        scanf("%d",&fir);
                    }
                    printf("選擇後攻角色:");
                    scanf("%d",&sec);
                    while(sec>4){//後攻角色要小於4
                        printf("錯誤:無此角色\n");
                        printf("\n選擇後攻角色:");
                        scanf("%d",&sec);
                    }
                    while(fir==sec){//先攻角色不等於後攻角色
                        printf("錯誤:不可重複選取\n");
                        printf("\n選擇先攻角色:");
                        scanf("%d",&fir);
                        while(fir>4){//先攻角色要小於4
                            printf("錯誤:無此角色\n");
                            printf("\n選擇先攻角色:");
                            scanf("%d",&fir);
                        }
                        printf("選擇後攻角色:");
                        scanf("%d",&sec);
                        while(sec>4){//後攻角色要小於4
                            printf("錯誤:無此角色\n");
                            printf("\n選擇後攻角色:");
                            scanf("%d",&sec);
                        }
                    }

                    printf("先攻為角色%d、後攻為角色%d\n",fir,sec);
                    printf("戰鬥開始\n\n");
                    if(fir==1){
                        atk1_hp = char1_hp;
                        atk1_def = char1_def;
                        atk1_atk = char1_atk;
                    }else if(fir==2){
                        atk1_hp = char2_hp;
                        atk1_def = char2_def;
                        atk1_atk = char2_atk;
                    }else if(fir==3){
                        atk1_hp = char3_hp;
                        atk1_def = char3_def;
                        atk1_atk = char3_atk;
                    }else if(fir==4){
                        atk1_hp = char4_hp;
                        atk1_def = char4_def;
                        atk1_atk = char4_atk;
                    }
                    if(sec==1){
                        atk2_hp = char1_hp;
                        atk2_def = char1_def;
                        atk2_atk = char1_atk;
                    }else if(sec==2){
                        atk2_hp = char2_hp;
                        atk2_def = char2_def;
                        atk2_atk = char2_atk;
                    }else if(sec==3){
                        atk2_hp = char3_hp;
                        atk2_def = char3_def;
                        atk2_atk = char3_atk;
                    }else if(sec==4){
                        atk2_hp = char4_hp;
                        atk2_def = char4_def;
                        atk2_atk = char4_atk;
                    }
                    do{
                        printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n",fir,sec,hur1);
                        printf("角色%d HP:%d 角色%d HP:%d\n\n",fir,atk1_hp,sec,atk2_hp-=hur1);
                        if(atk2_hp<=0){
                            printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",sec,fir);
                            break;}
                        printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n",sec,fir,hur2);
                        printf("角色%d HP:%d 角色%d HP:%d\n\n",fir,atk1_hp-=hur2,sec,atk2_hp);

                    }while(0<atk1_hp&&0<atk2_hp);
                    if(atk1_hp<=0){
                        printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",fir,sec);
                        break;
                    }
                    break;
                }

            }
    }


    return 0;
 }

