// �{���]�p�\�� 9/23 HW1
#include <stdio.h>

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

int main()
{
	// �ŧi�w�q����
	struct Status role1 = {'F',45,18,6};
	struct Status role2 = { .attribute = 'W',.health = 44,.attack = 16,.defence = 8 };
	struct Status role3 = { .attribute = 'A',.health = 42,.attack = 20,.defence = 5 };
	struct Status role4;

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

	// ��J�s�W���⪺�ƭ�
	printf("�s�W����\n�ݩ�:");
	scanf("%c", &role4.attribute);
	printf("��q:");
	scanf("%d", &role4.health);
	printf("����:");
	scanf("%d", &role4.attack);
	printf("���m:");
	scanf("%d", &role4.defence);
	printf("\n");

	// ����4�j�׹w��
	role4.strength = predict(role4.health, role4.attack, role4.defence);

	// ��X����4
	printf("����4\n"
		   "�W��:�ۭq����\n"
		   "�ݩ�:%c	    ����:%d\n"
		   "��q:%d	    ���m:%d\n"
		   "����j�׹w��:%.2lf\n", role4.attribute, role4.attack, role4.health, role4.defence, role4.strength);

	return 0;
}
