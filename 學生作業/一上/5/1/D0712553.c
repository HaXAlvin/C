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
	printf("是否新增角色(1.YES/2.NO)?");
	scanf("%d%*c", &ans);
	if (ans == 1){ //選擇新增角色，印出以下資訊，請使用者輸入訊息
        printf("屬性：");
        scanf("%c" ,&char4_type); //使用者輸入屬性，存入角色4屬性變數 char4_type
        if(char4_type>97){
            char4_type = char4_type - 32;
        }
        printf("血量：");
        scanf("%d" ,&char4_hp); //使用者輸入血量，存入角色4血量變數 char4_hp
        printf("攻擊：");
        scanf("%d" ,&char4_atk); //使用者輸入攻擊，存入角色4攻擊變數 char4_atk
        printf("防禦：");
        scanf("%d" ,&char4_def); //使用者輸入防禦，存入角色4防禦變數 char4_def

        //如果能力數值皆符合，則判斷屬性是否符合
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

                    //角色新增完成，選擇先攻後攻角色
                    printf("請選擇先攻角色：");
                    scanf("%d", &order1);
                    switch (order1){
                        case 1 ... 4: //輸入條件須為1-4之角色
                            printf("請選擇後攻角色：");
                            scanf("%d", &order2);
                            if (order2 == order1){ //先攻後攻不可是同一角色
                                printf("錯誤：不可重複選取\n");
                            }
                            else { //以上判斷正確，印出以下訊息
                                printf("\n");
                                printf("先攻角色為%d、後攻角色為%d\n", order1, order2);
                            }
                            break; //角色先攻後攻判斷停止
                        default: //輸入資訊不在角色數量範圍內
                            printf("錯誤：無此角色\n");
                    }
                    break; //屬性判斷停止
                default: //輸入屬性，不在範圍屬性內
                    printf("錯誤：無此屬性\n");
            }
        }
        //如果能力數值其一不符合，則判斷屬性是否符合
        else {
            switch (char4_type){
                case 'F':
                case 'W':
                case 'A':
                case 'G': //以上皆符合則印出下列資訊
                    printf("錯誤：能力數值在限制範圍之外\n");
                    break;
                default: //不符合則印出下列資訊
                    printf("錯誤：無此屬性\n");
                    printf("錯誤：能力數值在限制範圍之外\n");
            }
        }
	}
    else if (ans == 2){ //選擇不新增角色，跳過新增角色，選擇先攻後攻角色
            printf("\n");
            printf("請選擇先攻角色：");
            scanf("%d", &order1);
            switch (order1){
                case 1:
                case 2:
                case 3: //判斷輸入資訊是否有此角色
                    printf("請選擇後攻角色：");
                    scanf("%d", &order2);
                    if (order2 == order1){ //不可重複判斷
                        printf("錯誤：不可重複選取\n");
                    }
                    else { //以上皆正確，則印出以下資訊
                        printf("\n");
                        printf("先攻為角色%d、後攻為角色%d\n", order1, order2);
                    }
                    break;
                default: //輸入資訊不在角色數量範圍內
                    printf("錯誤：無此角色\n");
            }
    }
    else { //使用者輸入1.yes/2.no以外之資訊
        printf("輸入錯誤\n");
    }
return 0;
}
