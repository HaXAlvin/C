// 程式設計作業 14/10
#include <stdio.h>
int main()
{
	int diagonal, columns, rows;
	// 對角線長,度輸入
	while (1) {
		printf("輸入菱形對角線長度(3,5,7,9): ");
		scanf("%d", &diagonal);

		// 除錯
		if (diagonal != 3 && diagonal != 5 && diagonal != 7 && diagonal != 9) {
			printf("輸入錯誤!\n");
			continue;
		}
		else break;
	}

	// 行數輸入
	while (1) {
		printf("輸入行數(2~10): ");
		scanf("%d", &columns);

		// 除錯
		if (columns < 2 || columns > 10) {
			printf("輸入錯誤!\n");
			continue;
		}
		else break;
	}

	// 列數輸入
	while (1) {
		printf("輸入列數(2~10): ");
		scanf("%d", &rows);

		// 除錯
		if (rows < 2 || rows > 10) {
			printf("輸入錯誤!\n");
			continue;
		}
		else break;
	}

	printf("\n");
	// 總列數
	for (int r = rows; r > 0; r--) {
		// 單個菱形的列數
		for (int i = 0; i < diagonal; i++) {
			// 總行數
			for (int c = columns; c > 0; c--) {
				// 單個菱形的行數
				for (int j = 0; j < diagonal; j++) {
					// 判斷菱形上半的空白鍵
					if (i < (-j + diagonal / 2) || i < (j - diagonal / 2)) {
						printf(" ");
					}
					// 判斷菱形下半的空白鍵
					else if (i > (j + diagonal / 2) || i > (-j + diagonal / 2 * 3)) {
						printf(" ");
					}
					// 輸出 * 號
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
