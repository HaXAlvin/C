// 30/09 �{���]�p�\��
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// �N�ݩʡB��q�B�����B���m�B�j�׹w������Ʀ�b�@�_�����c
struct Status
{
	char attribute;
	int health;
	int attack;
	int defence;
	double strength;
};

// �p�⨤��j�׹w�����禡
double predict(int hp, int atk, int def)
{
	double rsp;
	rsp = (hp*1.0 + atk * 0.8 + def * 0.5 - 50)*6.5;

	return rsp;
}

// �s�W���⪺�禡
void add_role(struct Status *role) {
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

bool check_role(struct Status *role, bool *error) {
	if (role->attribute != 'F' && role->attribute != 'W' && role->attribute != 'G' && role->attribute != 'A') {
		printf("���~:�L���ݩ�\n");
		*error = true;
	}

	int total = role->health + role->attack + role->defence;

	if (role->health < 40 || role->health > 50 || role->attack < 15 || role->attack > 20 || role->defence < 5 || role->defence > 10 || total < 65 || total > 70) {
		printf("���~:��O�ƭȦb����d�򤧥~\n");
		*error = true;
	}
	return *error;
}

int main()
{
	// �ŧi�w�q����
	struct Status role1 = { role1.attribute = 'F',role1.health = 45,role1.attack = 18,role1.defence = 6 };
	struct Status role2 = { role2.attribute = 'W',role2.health = 44,role2.attack = 16,role2.defence = 8 };
	struct Status role3 = { role3.attribute = 'A',role3.health = 42,role3.attack = 20,role3.defence = 5 };
	struct Status role4 = {};

	// ����1-3�j�׹w��
	role1.strength = predict(role1.health, role1.attack, role1.defence);
	role2.strength = predict(role2.health, role2.attack, role2.defence);
	role3.strength = predict(role3.health, role3.attack, role3.defence);

	// ��X����1-3
	printf("����1\n"
		   "�W��:���e\n"
		   "�ݩ�:%c	    ����:%d\n"
		   "��q:%d	    ���m:%d\n"
		   "����j�׹w��:%.2lf\n", role1.attribute, role1.attack, role1.health, role1.defence, role1.strength);
	printf("\n");

	printf("����2\n"
		   "�W��:�|��\n"
		   "�ݩ�:%c	    ����:%d\n"
		   "��q:%d	    ���m:%d\n"
		   "����j�׹w��:%.2lf\n", role2.attribute, role2.attack, role2.health, role2.defence, role2.strength);
	printf("\n");

	printf("����3\n"
		   "�W��:�K�R\n"
		   "�ݩ�:%c	    ����:%d\n"
		   "��q:%d	    ���m:%d\n"
		   "����j�׹w��:%.2lf\n", role3.attribute, role3.attack, role3.health, role3.defence, role3.strength);
	printf("\n");

	// ����4
	int is_add;
	bool is_wrong = false;

	printf("�O�_�s�W����(1.Yes/2.No)? ");
	scanf("%d", &is_add);
	getchar();

	// ��ܼW�]
	if (is_add == 1) {
		add_role(&role4);

		// ����4�X�{���~, �N�۰ʵ���
		if(check_role(&role4, &is_wrong)){
            return 0;
		}

		// ��X����4
		else{
		    printf("\n");
            printf("����4\n"
			       "�W��:�ۭq����\n"
			       "�ݩ�:%c	    ����:%d\n"
			       "��q:%d	    ���m:%d\n"
			       "����j�׹w��:%.2lf\n", role4.attribute, role4.attack, role4.health, role4.defence, role4.strength);
		}
    }

    // ���1�M2�H�~
	else if (is_add != 2) {
		printf("��J���~\n");
		return 0;
	}

	printf("\n");

	// ��������
	int first_atk, after_atk;
	printf("��ܥ��𨤦�:");
	scanf("%d", &first_atk);

	if (first_atk == 4 && role4.attribute == NULL || first_atk > 4) {
		printf("���~:�L������\n");
		return 0;
	}

    printf("��ܫ�𨤦�:");
    scanf("%d", &after_atk);

    if (after_atk == 4 && role4.attribute == NULL || after_atk > 4) {
        printf("���~:�L������\n");
        return 0;
    }

    if (first_atk == after_atk) {
        printf("���~:���i���ƿ��\n");
        return 0;
	}

	printf("\n���𬰨���%d, ��𬰨���%d\n", first_atk, after_atk);


	return 0;
}
