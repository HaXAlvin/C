// �{���]�p�\�� 7/10
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// ��O�ƭȪ�����d��
#define MAX_HP 50
#define MIN_HP 40
#define MAX_ATK 20
#define MIN_ATK 15
#define MAX_DEF 10
#define MIN_DEF 5
#define MAX_TOTAL 70
#define MIN_TOTAL 65

// �ŧi�۩w�q����Ƶ��c
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

// ��X�����O�ƭ�
void print_role(struct Status *role) {
	printf("����%d\n"
		   "�W��:%s\n"
		   "�ݩ�:%c	    ����:%d\n"
		   "��q:%d	    ���m:%d\n"
		   "����j�׹w��:%.2lf\n", role->id, role->name, role->attribute, role->attack, role->health, role->defence, role->strength);
	printf("\n");
}

// �p�⨤��j�׹w��
double predict(int hp, int atk, int def)
{
	double rsp;
	rsp = (hp*1.0 + atk * 0.8 + def * 0.5 - 50)*6.5;

	return rsp;
}

// �s�W����
void create_role(struct Status *role) {
	printf("\n");
	getchar();
	printf("�s�W����\n�ݩ�:");
	scanf("%c", &(role->attribute));
	role->attribute = toupper(role->attribute);
	printf("��q:");
	scanf("%d", &(role->health));
	printf("����:");
	scanf("%d", &(role->attack));
	printf("���m:");
	scanf("%d", &(role->defence));

	role->strength = predict(role->health, role->attack, role->defence);
}

// ��O�ƭȿ��~����
bool status_invalid(struct Status *role) {
	bool wrong = false;

	// �ݩʿ��~
	if (role->attribute != 'F' && role->attribute != 'W' && role->attribute != 'G' && role->attribute != 'A') {
		printf("���~:�L���ݩ�\n");
		wrong = true;
	}

	int total = role->health + role->attack + role->defence;

	// ��q���~
	if (role->health < MIN_HP || role->health > MAX_HP) {
		printf("���~:��O�ƭȦb����d�򤧥~\n");
		wrong = true;
	}

	// �������~
	else if (role->attack < MIN_ATK || role->attack > MAX_ATK) {
		printf("���~:��O�ƭȦb����d�򤧥~\n");
		wrong = true;
	}

	// ���m���~
	else if (role->defence < MIN_DEF || role->defence > MAX_DEF) {
		printf("���~:��O�ƭȦb����d�򤧥~\n");
		wrong = true;
	}

	// �`�X�ȿ��~
	else if (total < MIN_TOTAL || total > MAX_TOTAL) {
		printf("���~:��O�ƭȦb����d�򤧥~\n");
		wrong = true;
	}

	return wrong;
}

// �����ܿ��~����
bool role_invalid(int role_id, bool is_exist) {
	bool wrong = false;

	// ����1-4�H�~
	if (role_id < 1 || role_id > 4) {
		printf("���~:�L������\n");
		wrong = true;
	}

	// �S���Ыب���4
	else if (role_id == 4 && !is_exist) {
		printf("���~:�L������\n");
		wrong = true;
	}

	return wrong;
}

// ��l�ƪ��a����
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
	// �ŧi�w�q����
	struct Status role1 = { 1,{"���e"},'F',45,18,6 };	// ���c����: id, �W��, �ݩ�, ��q, ����, ���m
	struct Status role2 = { 2,{"�|��"},'W',44,16,8 };
	struct Status role3 = { 3,{"�K�R"},'A',42,20,5 };
	struct Status role4 = { 4,{"�ۭq����"} };

	// ����1-3�j�׹w��
	role1.strength = predict(role1.health, role1.attack, role1.defence);
	role2.strength = predict(role2.health, role2.attack, role2.defence);
	role3.strength = predict(role3.health, role3.attack, role3.defence);

	// ��X����1-3
	print_role(&role1);
	print_role(&role2);
	print_role(&role3);

	// �O�_�s�W����4
	int choice;
	bool role4_exist = false;
	while (true) {
		printf("�O�_�s�W����(1.Yes/2.No)? ");
		scanf("%d", &choice);

		// ��ܼW�]
		if (choice == 1) {
			do {
				create_role(&role4);
			} while (status_invalid(&role4));
			role4_exist = true;

			printf("\n");
			print_role(&role4);
		}

		// ���1�M2�H�~
		else if (choice != 2) {
			printf("��J���~\n");
			continue;
		}

		printf("\n");
		break;
	}

	// ���������ܳ���, ���𨤦���
	int first, after;
	do {
		printf("��ܥ��𨤦�:");
		scanf("%d", &first);
	} while (role_invalid(first, role4_exist));

	// ��𨤦���
	while (true) {
		printf("��ܫ�𨤦�:");
		scanf("%d", &after);

		if (role_invalid(after, role4_exist)) {
			continue;
		}

		// ���⤣�i���ƿ��
		else if (first == after) {
			printf("���~:���i���ƿ��\n");
			continue;
		}

		break;
	}

	printf("\n���𬰨���%d, ��𬰨���%d\n�԰��}�l\n\n", first, after);

	// �԰��e���]�m
	struct Status player1, player2;
	player_setup(first, &player1, role1, role2, role3, role4);
	player_setup(after, &player2, role1, role2, role3, role4);

	// �԰��}�l
	int damage;
	while (true) {
		// ����^�X
		damage = player1.attack - player2.defence;
		printf("����%d �� ����%d �o�ʧ���, �y�� %d �I�ˮ`\n", player1.id, player2.id, damage);
		player2.health -= damage;
		printf("����%d HP: %d  ����%d HP: %d\n\n", player1.id, player1.health, player2.id, player2.health);

		if (player2.health <= 0) {
			printf("����%d ���h�԰���O\n�԰�����\n\n", player2.id);
			printf("����%d ���\n", player1.id);
			break;
		}

		// ���^�X
		damage = player2.attack - player1.defence;
		printf("����%d �� ����%d �o�ʧ���, �y�� %d �I�ˮ`\n", player2.id, player1.id, damage);
		player1.health -= damage;
		printf("����%d HP: %d  ����%d HP: %d\n\n", player1.id, player1.health, player2.id, player2.health);

		if (player1.health <= 0) {
			printf("����%d ���h�԰���O\n�԰�����\n\n", player1.id);
			printf("����%d ���\n", player2.id);
			break;
		}
	}

	return 0;
}
