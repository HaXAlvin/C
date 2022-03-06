// 程式設計作業 12/2
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
		// 隨機生成一組四個數字
		for (int i = 0; i < 4; i++) {
			guess_num[i] = rand() % 10;
			while (i > 0) {
				bool repeat = false;
				for (int j = 0; j < i; j++) {	// 檢測重複數字
					if (guess_num[j] == guess_num[i])
						repeat = true;
				}
				if (repeat) {	// 重複就再生成
					guess_num[i] = rand() % 10;
					continue;
				}
				else	// 沒有重複就下一位數字
					break;
			}
		}
		// 使用者輸入四個數字
		while (1) {
			printf(">> ");
			char num_string[10];
			gets(num_string);
			if (strlen(num_string) != 4) {	// 限制為四位數
				printf("ooINPUT ERROR\n");
				continue;
			}
			tmp = atoi(num_string);	// string轉換為int
			bool repeat = false;
			for (int i = 0; i < 4; i++) {
				input_num[i] = (tmp / (int)pow(10, 3 - i)) % 10;	// 把數字按位分解
				printf("[%d]:%d %d\n",i,input_num[i],(int)pow(10, 3 - i));
				if (i > 0) {
					for (int j = 0; j < i; j++) {	// 檢測重複數字
						if (input_num[j] == input_num[i])
							repeat = true;
					}
				}
			}
			if (repeat) {	// 輸入數字有重複的情況
				printf("kkINPUT ERROR\n");
				continue;
			}
			// 與正確答案比較
			int nA = 0, mB = 0;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (input_num[j] == guess_num[i] && j == i)	// 有出現, 位置正確
						nA += 1;
					else if (input_num[j] == guess_num[i])	// 有出現, 位置錯誤
						mB += 1;
				}
			}
			// 答案完全正解
			if (nA == 4) {
				printf("YOU WIN\n");
				// 詢問是否在玩一次
				while (1) {
					printf("Play Again?(Y/N)");
					scanf("%c", &play_again);
					getchar();	// 清除輸入緩衝區
					play_again = toupper(play_again);
					if (play_again == 'Y' || play_again == 'N')
						break;
				}
				if (play_again == 'Y')
					break;
				else if (play_again == 'N')
					return 0;
			}
			else	// 印出提示
				printf("%dA%dB\n", nA, mB);
		}
	}

	return 0;
}
