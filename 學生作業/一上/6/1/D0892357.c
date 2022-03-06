// 程式設計功課 7/10
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// 能力數值的限制範圍
#define MAX_HP 50
#define MIN_HP 40
#define MAX_ATK 20
#define MIN_ATK 15
#define MAX_DEF 10
#define MIN_DEF 5
#define MAX_TOTAL 70
#define MIN_TOTAL 65

// 宣告自定義的資料結構
struct Status
{
	int id;
	char name[32];
	char attribute;
	int health;
	int attack;
	int defence;
	double strength;
};

// 輸出角色能力數值
void print_role(struct Status *role) {
	printf("角色%d\n"
		   "名稱:%s\n"
		   "屬性:%c	    攻擊:%d\n"
		   "血量:%d	    防禦:%d\n"
		   "角色強度預測:%.2lf\n", role->id, role->name, role->attribute, role->attack, role->health, role->defence, role->strength);
	printf("\n");
}

// 計算角色強度預測
double predict(int hp, int atk, int def)
{
	double rsp;
	rsp = (hp*1.0 + atk * 0.8 + def * 0.5 - 50)*6.5;

	return rsp;
}

// 新增角色
void create_role(struct Status *role) {
	printf("\n");
	getchar();
	printf("新增角色\n屬性:");
	scanf("%c", &(role->attribute));
	role->attribute = toupper(role->attribute);
	printf("血量:");
	scanf("%d", &(role->health));
	printf("攻擊:");
	scanf("%d", &(role->attack));
	printf("防禦:");
	scanf("%d", &(role->defence));

	role->strength = predict(role->health, role->attack, role->defence);
}

// 能力數值錯誤偵測
bool status_invalid(struct Status *role) {
	bool wrong = false;

	// 屬性錯誤
	if (role->attribute != 'F' && role->attribute != 'W' && role->attribute != 'G' && role->attribute != 'A') {
		printf("錯誤:無此屬性\n");
		wrong = true;
	}

	int total = role->health + role->attack + role->defence;

	// 血量錯誤
	if (role->health < MIN_HP || role->health > MAX_HP) {
		printf("錯誤:能力數值在限制範圍之外\n");
		wrong = true;
	}

	// 攻擊錯誤
	else if (role->attack < MIN_ATK || role->attack > MAX_ATK) {
		printf("錯誤:能力數值在限制範圍之外\n");
		wrong = true;
	}

	// 防禦錯誤
	else if (role->defence < MIN_DEF || role->defence > MAX_DEF) {
		printf("錯誤:能力數值在限制範圍之外\n");
		wrong = true;
	}

	// 總合值錯誤
	else if (total < MIN_TOTAL || total > MAX_TOTAL) {
		printf("錯誤:能力數值在限制範圍之外\n");
		wrong = true;
	}

	return wrong;
}

// 角色選擇錯誤偵測
bool role_invalid(int role_id, bool is_exist) {
	bool wrong = false;

	// 角色1-4以外
	if (role_id < 1 || role_id > 4) {
		printf("錯誤:無此角色\n");
		wrong = true;
	}

	// 沒有創建角色4
	else if (role_id == 4 && !is_exist) {
		printf("錯誤:無此角色\n");
		wrong = true;
	}

	return wrong;
}

// 初始化玩家角色
void player_setup(int select, struct Status *player, struct Status role1, struct Status role2, struct Status role3, struct Status role4) {
	switch (select)
	{
	case 1:
		*player = role1;
		break;
	case 2:
		*player = role2;
		break;
	case 3:
		*player = role3;
		break;
	case 4:
		*player = role4;
		break;
	}
}

int main()
{
	// 宣告定義角色
	struct Status role1 = { 1,{"五河"},'F',45,18,6 };	// 結構順序: id, 名稱, 屬性, 血量, 攻擊, 防禦
	struct Status role2 = { 2,{"四糸"},'W',44,16,8 };
	struct Status role3 = { 3,{"八舞"},'A',42,20,5 };
	struct Status role4 = { 4,{"自訂角色"} };

	// 角色1-3強度預測
	role1.strength = predict(role1.health, role1.attack, role1.defence);
	role2.strength = predict(role2.health, role2.attack, role2.defence);
	role3.strength = predict(role3.health, role3.attack, role3.defence);

	// 輸出角色1-3
	print_role(&role1);
	print_role(&role2);
	print_role(&role3);

	// 是否新增角色4
	int choice;
	bool role4_exist = false;
	while (true) {
		printf("是否新增角色(1.Yes/2.No)? ");
		scanf("%d", &choice);

		// 選擇增設
		if (choice == 1) {
			do {
				create_role(&role4);
			} while (status_invalid(&role4));
			role4_exist = true;

			printf("\n");
			print_role(&role4);
		}

		// 選擇1和2以外
		else if (choice != 2) {
			printf("輸入錯誤\n");
			continue;
		}

		printf("\n");
		break;
	}

	// 攻擊先後選擇部分, 先攻角色選擇
	int first, after;
	do {
		printf("選擇先攻角色:");
		scanf("%d", &first);
	} while (role_invalid(first, role4_exist));

	// 後攻角色選擇
	while (true) {
		printf("選擇後攻角色:");
		scanf("%d", &after);

		if (role_invalid(after, role4_exist)) {
			continue;
		}

		// 角色不可重複選取
		else if (first == after) {
			printf("錯誤:不可重複選取\n");
			continue;
		}

		break;
	}

	printf("\n先攻為角色%d, 後攻為角色%d\n戰鬥開始\n\n", first, after);

	// 戰鬥前的設置
	struct Status player1, player2;
	player_setup(first, &player1, role1, role2, role3, role4);
	player_setup(after, &player2, role1, role2, role3, role4);

	// 戰鬥開始
	int damage;
	while (true) {
		// 先攻回合
		damage = player1.attack - player2.defence;
		printf("角色%d 對 角色%d 發動攻擊, 造成 %d 點傷害\n", player1.id, player2.id, damage);
		player2.health -= damage;
		printf("角色%d HP: %d  角色%d HP: %d\n\n", player1.id, player1.health, player2.id, player2.health);

		if (player2.health <= 0) {
			printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n", player2.id);
			printf("角色%d 獲勝\n", player1.id);
			break;
		}

		// 後攻回合
		damage = player2.attack - player1.defence;
		printf("角色%d 對 角色%d 發動攻擊, 造成 %d 點傷害\n", player2.id, player1.id, damage);
		player1.health -= damage;
		printf("角色%d HP: %d  角色%d HP: %d\n\n", player1.id, player1.health, player2.id, player2.health);

		if (player1.health <= 0) {
			printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n", player1.id);
			printf("角色%d 獲勝\n", player2.id);
			break;
		}
	}

	return 0;
}
