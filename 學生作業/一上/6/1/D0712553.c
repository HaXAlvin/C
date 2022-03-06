#include <stdio.h>
#include <stdlib.h>

int main()
{
	//角色1
	char charl_type = 'G'; //角色1的屬性
	int charl_hp = 40; //角色1的血量
	int charl_atk = 20; //角色1的攻擊量
	int charl_def = 5; //角色1的防禦量
	//角色2
    char char2_type = 'W'; //角色2的屬性
	int char2_hp = 50;  //角色2的血量
	int char2_atk = 15; //角色2的攻擊量
	int char2_def = 5; //角色2的防禦量
	//角色3
    char char3_type = 'F'; //角色3的屬性
	int char3_hp = 40; //角色3的血量
	int char3_atk = 15;  //角色3的攻擊量
	int char3_def = 10; //角色3的防禦量
	//強度預測
    double power;

	printf("角色1\n");
	printf("角色名稱：蘑菇\n");
	printf("屬性：%-6c血量：%d\n" ,charl_type ,charl_hp);
	printf("攻擊：%-6d防禦：%d\n" ,charl_atk ,charl_def);
	power = (charl_hp*1 + charl_atk*0.8 + charl_def*0.5 - 50)*6.5;
	printf("角色強度預測：%.2lf\n\n", power);

    printf("角色2\n");
	printf("角色名稱：香菇\n");
	printf("屬性：%-6c血量：%d\n" ,char2_type ,char2_hp);
	printf("攻擊：%-6d防禦：%d\n" ,char2_atk ,char2_def);
	power = (char2_hp*1 + char2_atk*0.8 + char2_def*0.5 - 50)*6.5;
	printf("角色強度預測：%.2lf\n\n", power);

    printf("角色3\n");
	printf("角色名稱：杏鮑菇\n");
	printf("屬性：%-6c血量：%d\n" ,char3_type ,char3_hp);
	printf("攻擊：%-6d防禦：%d\n" ,char3_atk ,char3_def);
	power = (char3_hp*1 + char3_atk*0.8 + char3_def*0.5 - 50)*6.5;
	printf("角色強度預測：%.2lf\n\n", power);

    //角色4
    char char4_type; //定義角色4屬性變數
	int char4_hp; //定義角色4血量變數
	int char4_atk; //定義角色4攻擊變數
	int char4_def; //定義角色4防禦變數

    int ans, order1, order2;
    int p = 1; //是否新增角色flag
    int q = 1; //進入新增角色flag
    int r = 0; //預設：新增角色，不直接進入攻擊順序迴圈
    while(p){
        printf("是否新增角色(1.YES/2.NO)?");
        scanf("%d", &ans);
        if(ans == 1){
            q = 1; //要創角flag
            p = 0; //離開此迴圈
        }else if(ans == 2){
            q = 0; //不創角flag
            p = 0; //離開此迴圈
            r = 1; //不新增角色，直接進入攻擊順序迴圈
        }else{
            printf("輸入錯誤\n");
        }
    }

    while(q){
        printf("屬性：");
        scanf("%*c%c" ,&char4_type); //使用者輸入屬性，存入角色4屬性變數 char4_type
        //scanf("%*[^\n]");
        if(char4_type>97){
        char4_type = char4_type - 32;
        }
        printf("血量：");
        scanf("%d" ,&char4_hp); //使用者輸入血量，存入角色4血量變數 char4_hp
        printf("攻擊：");
        scanf("%d" ,&char4_atk); //使用者輸入攻擊，存入角色4攻擊變數 char4_atk
        printf("防禦：");
        scanf("%d" ,&char4_def); //使用者輸入防禦，存入角色4防禦變數 char4_def

        if(char4_hp<51 && char4_hp>39 && char4_atk<21 && char4_atk>14 && char4_def<11 && char4_def>4){
            switch (char4_type){
                case 'F':
                case 'W':
                case 'A':
                case 'G': //以上皆符合則印出下列資訊
                    printf("\n");
                    printf("角色4\n");
                    printf("角色名稱：自訂角色\n");
                    printf("屬性：%-6c血量：%d\n" ,char4_type ,char4_hp);
                    printf("攻擊：%-6d防禦：%d\n" ,char4_atk ,char4_def);
                    power = (char4_hp*1 + char4_atk*0.8 + char4_def*0.5 - 50)*6.5;
                    printf("角色強度預測：%.2lf\n\n", power);
                    q = 0; //離開創角迴圈flag
                    p = 1;
                    break; //屬性判斷停止
                default: //輸入屬性，不在範圍屬性內
                    printf("錯誤：無此屬性\n\n");
            }
        }
        //如果能力數值其一不符合，則判斷屬性是否符合
        else {
            switch (char4_type){
                case 'F':
                case 'W':
                case 'A':
                case 'G': //以上皆符合則印出下列資訊
                    printf("錯誤：能力數值在限制範圍之外\n\n");
                    break;
                default: //不符合則印出下列資訊
                    printf("錯誤：無此屬性\n");
                    printf("錯誤：能力數值在限制範圍之外\n\n");
            }
        }
    }
    int stchar;
    int sthp;
    int statk;
    int stdef;
    int ndchar;
    int ndhp;
    int ndatk;
    int nddef;
    while(r){
        printf("\n");
        printf("請選擇先攻角色：");
        scanf("%d", &order1);
        switch (order1){
            case 1:
                stchar = order1;
                sthp = charl_hp;
                statk = charl_atk;
                stdef = charl_def;
                break;
            case 2:
                stchar = order1;
                sthp = char2_hp;
                statk = char2_atk;
                stdef = char2_def;
                break;
            case 3:
                stchar = order1;
                sthp = char3_hp;
                statk = char3_atk;
                stdef = char3_def;
        }
        switch (order1){
            case 1:
            case 2:
            case 3: //判斷輸入資訊是否有此角色
                printf("請選擇後攻角色：");
                scanf("%d", &order2);
                if (order2 == order1){ //不可重複判斷
                    printf("錯誤：不可重複選取\n");
                }
                else if (order2 > 3){
                    printf("錯誤：無此角色\n");
                }
                else { //以上皆正確，則印出以下資訊
                    printf("\n");
                    printf("先攻為角色%d、後攻為角色%d\n", order1, order2);
                    switch (order2){
                        case 1:
                            ndchar = order2;
                            ndhp = charl_hp;
                            ndatk = charl_atk;
                            nddef = charl_def;
                            break;
                        case 2:
                            ndchar = order2;
                            ndhp = char2_hp;
                            ndatk = char2_atk;
                            nddef = char2_def;
                            break;
                        case 3:
                            ndchar = order2;
                            ndhp = char3_hp;
                            ndatk = char3_atk;
                            nddef = char3_def;
                    }
                    r = 0; //離開攻擊順序迴圈
                }
                break;
            default: //輸入資訊不在角色數量範圍內
                printf("錯誤：無此角色\n");
        }
    }
    while(p) {
        printf("\n");
        printf("請選擇先攻角色：");
        scanf("%d", &order1);
        switch (order1){
            case 1:
                stchar = order1;
                sthp = charl_hp;
                statk = charl_atk;
                stdef = charl_def;
                break;
            case 2:
                stchar = order1;
                sthp = char2_hp;
                statk = char2_atk;
                stdef = char2_def;
                break;
            case 3:
                stchar = order1;
                sthp = char3_hp;
                statk = char3_atk;
                stdef = char3_def;
            case 4:
                stchar = order1;
                sthp = char4_hp;
                statk = char4_atk;
                stdef = char4_def;
        }
        switch (order1){
            case 1:
            case 2:
            case 3:
            case 4: //輸入條件須為1-4之角色
                printf("請選擇後攻角色：");
                scanf("%d", &order2);
                if (order2 == order1){ //先攻後攻不可是同一角色
                    printf("錯誤：不可重複選取\n");
                }
                else if (order2 > 4){
                    printf("錯誤：無此角色\n");
                }
                else { //以上判斷正確，印出以下訊息
                    printf("\n");
                    printf("先攻角色為%d、後攻角色為%d\n", order1, order2);
                    switch (order2){
                        case 1:
                            ndchar = order2;
                            ndhp = charl_hp;
                            ndatk = charl_atk;
                            nddef = charl_def;
                            break;
                        case 2:
                            ndchar = order2;
                            ndhp = char2_hp;
                            ndatk = char2_atk;
                            nddef = char2_def;
                            break;
                        case 3:
                            ndchar = order2;
                            ndhp = char3_hp;
                            ndatk = char3_atk;
                            nddef = char3_def;
                        case 4:
                            ndchar = order2;
                            ndhp = char4_hp;
                            ndatk = char4_atk;
                            nddef = char4_def;
                    }
                    p = 0;
                }
                break; //角色先攻後攻判斷停止
            default: //輸入資訊不在角色數量範圍內
                printf("錯誤：無此角色\n");
        }
    }
    printf("戰鬥開始\n");
    printf("\n");
    int firstatk = statk - nddef;
    int lastatk = ndatk - stdef;
    while(sthp>0 && ndhp>0){
        printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", order1, order2, firstatk);
        ndhp = ndhp -  firstatk;
        printf("角色%d HP：%d  角色%d HP：%d\n", order1, sthp, order2, ndhp);
        printf("\n");
        if (ndhp<=0 && sthp!=0){
            printf("角色%d 失去戰鬥能力\n", order2);
            printf("戰鬥結束\n");
            printf("\n");
            printf("角色%d 獲勝",order1);
            q = 0;
            return 0;
        }
        printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n", order2, order1, lastatk);
        sthp = sthp - lastatk;
        printf("角色%d HP：%d  角色%d HP：%d\n", order1, sthp, order2, ndhp);
        printf("\n");
        if(sthp<=0 && ndhp!=0){
            printf("角色%d 失去戰鬥能力\n", order1);
            printf("戰鬥結束\n");
            printf("\n");
            printf("角色%d 獲勝",order2);
            q = 0;
            return 0;
        }
    }
return 0;
}
