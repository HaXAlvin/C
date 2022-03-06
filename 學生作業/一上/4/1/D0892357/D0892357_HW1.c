// 程式設計功課 9/23 HW1
#include <stdio.h>

// 將屬性、血量、攻擊、防禦、強度預測的資料串在一起成結構
struct Status
{
	char attribute;
	int health;
	int attack;
	int defence;
	double strength;
};

// 計算角色強度預測的函式
double predict(int hp, int atk, int def)
{
	double rsp;
	rsp = (hp*1.0 + atk * 0.8 + def * 0.5 - 50)*6.5;

	return rsp;
}

int main()
{
	// 宣告定義角色
	struct Status role1 = {'F',45,18,6};
	struct Status role2 = { .attribute = 'W',.health = 44,.attack = 16,.defence = 8 };
	struct Status role3 = { .attribute = 'A',.health = 42,.attack = 20,.defence = 5 };
	struct Status role4;

	// 角色1-3強度預測
	role1.strength = predict(role1.health, role1.attack, role1.defence);
	role2.strength = predict(role2.health, role2.attack, role2.defence);
	role3.strength = predict(role3.health, role3.attack, role3.defence);

	// 輸出角色1-3
	printf("角色1\n"
		   "名稱:五河\n"
		   "屬性:%c	    攻擊:%d\n"
		   "血量:%d	    防禦:%d\n"
		   "角色強度預測:%.2lf\n", role1.attribute, role1.attack, role1.health, role1.defence, role1.strength);
	printf("\n");

	printf("角色2\n"
		   "名稱:四糸\n"
		   "屬性:%c	    攻擊:%d\n"
		   "血量:%d	    防禦:%d\n"
		   "角色強度預測:%.2lf\n", role2.attribute, role2.attack, role2.health, role2.defence, role2.strength);
	printf("\n");

	printf("角色3\n"
		   "名稱:八舞\n"
		   "屬性:%c	    攻擊:%d\n"
		   "血量:%d	    防禦:%d\n"
		   "角色強度預測:%.2lf\n", role3.attribute, role3.attack, role3.health, role3.defence, role3.strength);
	printf("\n");

	// 輸入新增角色的數值
	printf("新增角色\n屬性:");
	scanf("%c", &role4.attribute);
	printf("血量:");
	scanf("%d", &role4.health);
	printf("攻擊:");
	scanf("%d", &role4.attack);
	printf("防禦:");
	scanf("%d", &role4.defence);
	printf("\n");

	// 角色4強度預測
	role4.strength = predict(role4.health, role4.attack, role4.defence);

	// 輸出角色4
	printf("角色4\n"
		   "名稱:自訂角色\n"
		   "屬性:%c	    攻擊:%d\n"
		   "血量:%d	    防禦:%d\n"
		   "角色強度預測:%.2lf\n", role4.attribute, role4.attack, role4.health, role4.defence, role4.strength);

	return 0;
}
