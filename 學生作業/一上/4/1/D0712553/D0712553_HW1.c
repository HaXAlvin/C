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
	printf("角色強度預測 : %.2lf\n\n", power);

    printf("角色2\n");
	printf("角色名稱：香菇\n");
	printf("屬性：%-6c血量：%d\n" ,char2_type ,char2_hp);
	printf("攻擊：%-6d防禦：%d\n" ,char2_atk ,char2_def);
	power = (char2_hp*1 + char2_atk*0.8 + char2_def*0.5 - 50)*6.5;
	printf("角色強度預測 : %.2lf\n\n", power);

    printf("角色3\n");
	printf("角色名稱：杏鮑菇\n");
	printf("屬性：%-6c血量：%d\n" ,char3_type ,char3_hp);
	printf("攻擊：%-6d防禦：%d\n" ,char3_atk ,char3_def);
	power = (char3_hp*1 + char3_atk*0.8 + char3_def*0.5 - 50)*6.5;
	printf("角色強度預測 : %.2lf\n\n", power);

    //角色4
    char char4_type; //定義角色4屬性變數
	int char4_hp; //定義角色4血量變數
	int char4_atk; //定義角色4攻擊變數
	int char4_def; //定義角色4防禦變數

    printf("新增角色\n");
    printf("屬性：");
    scanf("%c" ,&char4_type); //使用者輸入屬性，存入角色4屬性變數 char4_type
    printf("血量：");
    scanf("%d" ,&char4_hp); //使用者輸入血量，存入角色4血量變數 char4_hp
    printf("攻擊：");
    scanf("%d" ,&char4_atk); //使用者輸入攻擊，存入角色4攻擊變數 char4_atk
    printf("防禦：");
    scanf("%d" ,&char4_def); //使用者輸入防禦，存入角色4防禦變數 char4_def
    printf("\n");

    printf("角色4\n");
    printf("角色名稱：自訂角色\n");
    printf("屬性：%-6c血量：%d\n" ,char4_type ,char4_hp);
    printf("攻擊：%-6d防禦：%d\n" ,char4_atk ,char4_def);
    power = (char4_hp*1 + char4_atk*0.8 + char4_def*0.5 - 50)*6.5;
    printf("角色強度預測 : %.2lf\n", power);

    return 0;
}
