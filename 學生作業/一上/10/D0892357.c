// �{���]�p�@�~ 12/2
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
int main()
{
	int guess_num[4], input_num[4], tmp;
	char play_again;
	srand(time(NULL));

	while (1) {
		// �H���ͦ��@�ե|�ӼƦr
		for (int i = 0; i < 4; i++) {
			guess_num[i] = rand() % 10;
			while (i > 0) {
				bool repeat = false;
				for (int j = 0; j < i; j++) {	// �˴����ƼƦr
					if (guess_num[j] == guess_num[i])
						repeat = true;
				}
				if (repeat) {	// ���ƴN�A�ͦ�
					guess_num[i] = rand() % 10;
					continue;
				}
				else	// �S�����ƴN�U�@��Ʀr
					break;
			}
		}
		// �ϥΪ̿�J�|�ӼƦr
		while (1) {
			printf(">> ");
			char num_string[10];
			gets(num_string);
			if (strlen(num_string) != 4) {	// ����|���
				printf("ooINPUT ERROR\n");
				continue;
			}
			tmp = atoi(num_string);	// string�ഫ��int
			bool repeat = false;
			for (int i = 0; i < 4; i++) {
				input_num[i] = (tmp / (int)pow(10, 3 - i)) % 10;	// ��Ʀr�������
				printf("[%d]:%d %d\n",i,input_num[i],(int)pow(10, 3 - i));
				if (i > 0) {
					for (int j = 0; j < i; j++) {	// �˴����ƼƦr
						if (input_num[j] == input_num[i])
							repeat = true;
					}
				}
			}
			if (repeat) {	// ��J�Ʀr�����ƪ����p
				printf("kkINPUT ERROR\n");
				continue;
			}
			// �P���T���פ��
			int nA = 0, mB = 0;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (input_num[j] == guess_num[i] && j == i)	// ���X�{, ��m���T
						nA += 1;
					else if (input_num[j] == guess_num[i])	// ���X�{, ��m���~
						mB += 1;
				}
			}
			// ���ק�������
			if (nA == 4) {
				printf("YOU WIN\n");
				// �߰ݬO�_�b���@��
				while (1) {
					printf("Play Again?(Y/N)");
					scanf("%c", &play_again);
					getchar();	// �M����J�w�İ�
					play_again = toupper(play_again);
					if (play_again == 'Y' || play_again == 'N')
						break;
				}
				if (play_again == 'Y')
					break;
				else if (play_again == 'N')
					return 0;
			}
			else	// �L�X����
				printf("%dA%dB\n", nA, mB);
		}
	}

	return 0;
}
