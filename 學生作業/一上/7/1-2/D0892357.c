// �{���]�p�@�~ 14/10
#include <stdio.h>
int main()
{
	int diagonal, columns, rows;
	// �﨤�u��,�׿�J
	while (1) {
		printf("��J�٧ι﨤�u����(3,5,7,9): ");
		scanf("%d", &diagonal);

		// ����
		if (diagonal != 3 && diagonal != 5 && diagonal != 7 && diagonal != 9) {
			printf("��J���~!\n");
			continue;
		}
		else break;
	}

	// ��ƿ�J
	while (1) {
		printf("��J���(2~10): ");
		scanf("%d", &columns);

		// ����
		if (columns < 2 || columns > 10) {
			printf("��J���~!\n");
			continue;
		}
		else break;
	}

	// �C�ƿ�J
	while (1) {
		printf("��J�C��(2~10): ");
		scanf("%d", &rows);

		// ����
		if (rows < 2 || rows > 10) {
			printf("��J���~!\n");
			continue;
		}
		else break;
	}

	printf("\n");
	// �`�C��
	for (int r = rows; r > 0; r--) {
		// ��ӵ٧Ϊ��C��
		for (int i = 0; i < diagonal; i++) {
			// �`���
			for (int c = columns; c > 0; c--) {
				// ��ӵ٧Ϊ����
				for (int j = 0; j < diagonal; j++) {
					// �P�_�٧ΤW�b���ť���
					if (i < (-j + diagonal / 2) || i < (j - diagonal / 2)) {
						printf(" ");
					}
					// �P�_�٧ΤU�b���ť���
					else if (i > (j + diagonal / 2) || i > (-j + diagonal / 2 * 3)) {
						printf(" ");
					}
					// ��X * ��
					else {
						printf("*");
					}
				}
				printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}
