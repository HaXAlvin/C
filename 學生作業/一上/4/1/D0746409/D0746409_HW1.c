#include<stdio.h>
int main()
{
	char char1_type = 'A';
	int char1_atk = 18;
	int char1_hp = 42;
	int char1_def = 6;
	float char1_pred;
	char char2_type = 'F';
	int char2_atk = 20;
	int char2_hp = 40;
	int char2_def = 10;
	float char2_pred;
	char char3_type = 'G';
	int char3_atk = 15;
	int char3_hp = 49;
	int char3_def = 5;
	float char3_pred;
	char char4_type;
	int char4_atk;
	int char4_hp;
	int char4_def;
	float char4_pred;
	printf("角色１\n");
	printf("名稱：史蒂諾夫\n");
	printf("屬性：%c   攻擊%d\n", char1_type, char1_atk);
	printf("血量：%d  防禦%d\n", char1_hp, char1_def);
	printf("角色強度預測：%.2f\n\n", char1_pred = (char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5 - 50) * 6.5);
	printf("角色２\n");
	printf("名稱：赫爾基心\n");
	printf("屬性：%c   攻擊%d\n", char2_type, char2_atk);
	printf("血量：%d  防禦%d\n", char2_hp, char2_def);
	printf("角色強度預測：%.2f\n\n", char2_pred = (char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5 - 50) * 6.5);
	printf("角色３\n");
	printf("名稱：SorryZ\n");
	printf("屬性：%c   攻擊%d\n", char3_type, char3_atk);
	printf("血量：%d  防禦%d\n", char3_hp, char3_def);
	printf("角色強度預測：%.2f\n\n", char3_pred = (char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5 - 50) * 6.5);
	printf("新增角色\n");
	printf("屬性：");
	scanf("%c", &char4_type);
	printf("攻擊：");
	scanf("%d", &char4_atk);
	printf("血量：");
	scanf("%d", &char4_hp);
	printf("防禦：");
	scanf("%d", &char4_def);
	printf("\n角色4\n");
	printf("名稱：自訂角色\n");
	printf("屬性：%c   攻擊%d\n", char4_type, char4_atk);
	printf("血量：%d  防禦%d\n", char4_hp, char4_def);
	printf("角色強度預測：%.2f\n", char4_pred = (char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5 - 50) * 6.5);
	printf("%.2f",char4_pred);
	return 0;
}
