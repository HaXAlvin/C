// 30/09 程式設計功課
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

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

// 新增角色的函式
void add_role(struct Status *role) {
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

bool check_role(struct Status *role, bool *error) {
	if (role->attribute != 'F' && role->attribute != 'W' && role->attribute != 'G' && role->attribute != 'A') {
		printf("錯誤:無此屬性\n");
		*error = true;
	}

	int total = role->health + role->attack + role->defence;

	if (role->health < 40 || role->health > 50 || role->attack < 15 || role->attack > 20 || role->defence < 5 || role->defence > 10 || total < 65 || total > 70) {
		printf("錯誤:能力數值在限制範圍之外\n");
		*error = true;
	}
	return *error;
}

int main()
{
	// 宣告定義角色
	struct Status role1 = { role1.attribute = 'F',role1.health = 45,role1.attack = 18,role1.defence = 6 };
	struct Status role2 = { role2.attribute = 'W',role2.health = 44,role2.attack = 16,role2.defence = 8 };
	struct Status role3 = { role3.attribute = 'A',role3.health = 42,role3.attack = 20,role3.defence = 5 };
	struct Status role4 = {};

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

	// 角色4
	int is_add;
	bool is_wrong = false;

	printf("是否新增角色(1.Yes/2.No)? ");
	scanf("%d", &is_add);
	getchar();

	// 選擇增設
	if (is_add == 1) {
		add_role(&role4);

		// 角色4出現錯誤, 就自動結束
		if(check_role(&role4, &is_wrong)){
            return 0;
		}

		// 輸出角色4
		else{
		    printf("\n");
            printf("角色4\n"
			       "名稱:自訂角色\n"
			       "屬性:%c	    攻擊:%d\n"
			       "血量:%d	    防禦:%d\n"
			       "角色強度預測:%.2lf\n", role4.attribute, role4.attack, role4.health, role4.defence, role4.strength);
		}
    }

    // 選擇1和2以外
	else if (is_add != 2) {
		printf("輸入錯誤\n");
		return 0;
	}

	printf("\n");

	// 先攻後攻選擇
	int first_atk, after_atk;
	printf("選擇先攻角色:");
	scanf("%d", &first_atk);

	if (first_atk == 4 && role4.attribute == NULL || first_atk > 4) {
		printf("錯誤:無此角色\n");
		return 0;
	}

    printf("選擇後攻角色:");
    scanf("%d", &after_atk);

    if (after_atk == 4 && role4.attribute == NULL || after_atk > 4) {
        printf("錯誤:無此角色\n");
        return 0;
    }

    if (first_atk == after_atk) {
        printf("錯誤:不可重複選取\n");
        return 0;
	}

	printf("\n先攻為角色%d, 後攻為角色%d\n", first_atk, after_atk);


	return 0;
}
