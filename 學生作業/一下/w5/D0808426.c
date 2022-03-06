#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// list���c, ������ҤƤ覡: listNode a = {.i = 5, TInt};
typedef struct {
	// Fields
	union {
		int i;
		float f;
		char s[16];
	};

	// Types
	enum {
		TInt,
		TFloat,
		TStr
	} type;
} listNode;

// �s�Wlist�`�I, �ǤJ��list & ���� (both by ref), ��^�slist (by ref)
listNode *addNode(listNode *list, int *list_N) {
	char choice_type; // �Τ��ܪ����� (char)
	int choice_T; // �ഫ��Τ��ܪ����� (enum.type / int)

	// ���ܥΤ��ܱ��x�s���������
	do {
		printf("��ܸ������ (i = int; f = float; s = char[16]): ");
		scanf(" %c", &choice_type);

		// ��p�g��, �����ഫ��enum.type�æs�Jchoice_T, ���ѫh�����ܿ�J
		choice_type = tolower(choice_type);
		choice_T = (choice_type == 'i') ? TInt : (choice_type == 'f') ? TFloat : (choice_type == 's') ? TStr : -1;
		if (choice_T == -1)
			printf("���w�q������!\n");
		fflush(stdin); // �M��stdin buffer
	} while (choice_T < 0);

	// �s�ة��X�Rlist
	if (*list_N == 0) { //����l��, �}�P�s�Ŷ� (node * 1)
		list = malloc(sizeof(listNode));
		++(*list_N);
	} else if (*list_N > 0) { //�w��l��, �X�R��Ŷ� (node * list_N), list_N���W
		list = realloc(list, sizeof(listNode) * ++(*list_N));
	}

	// ���ܥΤ��J���, �ھ�choice_T�s�J������� (�]��}�ۦP, �]�i�ϥαj���૬�B�z)
	printf("�п�J���: ");
	switch (choice_T) {
		case TInt:
			scanf(" %i", &list[*list_N - 1].i);
		break;
		case TFloat:
			scanf(" %f", &list[*list_N - 1].f);
		break;
		case TStr:
			scanf(" %15[^\n]", list[*list_N - 1].s); // ������� & �����ťհ���
		break;
	}
	fflush(stdin); // �M��stdin buffer

	// �O�s��ƫ�, �A�O�schoice_T (�]�̶��Ǫ��ߺD)
	list[*list_N - 1].type = choice_T;
	return list;
}

// �M��list, �̾�������X�C��node�����e
void displayList(listNode *list, int list_N) {
	// �̾�list_N�j��
	for (int i = 0; i < list_N; ++i) {
		// ��������, ��X
		switch (list[i].type) {
        case TInt:
            printf("%i", list[i].i);
        break;

        case TFloat:
            printf("%f", list[i].f);
        break;

        case TStr:
            printf("%s", list[i].s);
        break;
		}
		putchar('\n');
	}
}

// �D���
int main(int argc, char *argv[]) {
	listNode *list; // ��node��_�����C��
	int list_N = 0; // �C����
	int choice; // �ʧ@���

	while (1) {
		// ���ܥΤ��ܰʧ@
		printf(
			"1 = �s�W\n"
			"2 = �L�X\n"
			"0 = ���}\n"
			"���: "
		);
		scanf(" %i", &choice);

		// 0 = ���}
		if (choice == 0)
			break;

		// �̿�ܰ���ʧ@
		switch (choice) {
			case 1:
				list = addNode(list, &list_N);
			break;
			case 2:
				displayList(list, list_N);
			break;
			default:
				printf("���~���ﶵ!\n");
			continue;
		}
		// ���_�����j�u
		printf("-------------------------------\n");
	}
	return 0;
}
