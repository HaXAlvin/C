#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// list結構, 直接實例化方式: listNode a = {.i = 5, TInt};
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

// 新增list節點, 傳入原list & 項數 (both by ref), 返回新list (by ref)
listNode *addNode(listNode *list, int *list_N) {
	char choice_type; // 用戶選擇的類型 (char)
	int choice_T; // 轉換後用戶選擇的類型 (enum.type / int)

	// 提示用戶選擇欲儲存之資料類型
	do {
		printf("選擇資料類型 (i = int; f = float; s = char[16]): ");
		scanf(" %c", &choice_type);

		// 轉小寫後, 嘗試轉換成enum.type並存入choice_T, 失敗則重提示輸入
		choice_type = tolower(choice_type);
		choice_T = (choice_type == 'i') ? TInt : (choice_type == 'f') ? TFloat : (choice_type == 's') ? TStr : -1;
		if (choice_T == -1)
			printf("未定義的類型!\n");
		fflush(stdin); // 清除stdin buffer
	} while (choice_T < 0);

	// 新建或擴充list
	if (*list_N == 0) { //未初始化, 開闢新空間 (node * 1)
		list = malloc(sizeof(listNode));
		++(*list_N);
	} else if (*list_N > 0) { //已初始化, 擴充原空間 (node * list_N), list_N遞增
		list = realloc(list, sizeof(listNode) * ++(*list_N));
	}

	// 提示用戶輸入資料, 根據choice_T存入對應欄位 (因位址相同, 也可使用強制轉型處理)
	printf("請輸入資料: ");
	switch (choice_T) {
		case TInt:
			scanf(" %i", &list[*list_N - 1].i);
		break;
		case TFloat:
			scanf(" %f", &list[*list_N - 1].f);
		break;
		case TStr:
			scanf(" %15[^\n]", list[*list_N - 1].s); // 限制長度 & 忽略空白停止
		break;
	}
	fflush(stdin); // 清除stdin buffer

	// 保存資料後, 再保存choice_T (因依順序的習慣)
	list[*list_N - 1].type = choice_T;
	return list;
}

// 遍歷list, 依據類型輸出每個node的內容
void displayList(listNode *list, int list_N) {
	// 依據list_N迴圈
	for (int i = 0; i < list_N; ++i) {
		// 辨識類型, 輸出
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

// 主函數
int main(int argc, char *argv[]) {
	listNode *list; // 由node串起的的列表
	int list_N = 0; // 列表項數
	int choice; // 動作選擇

	while (1) {
		// 提示用戶選擇動作
		printf(
			"1 = 新增\n"
			"2 = 印出\n"
			"0 = 離開\n"
			"選擇: "
		);
		scanf(" %i", &choice);

		// 0 = 離開
		if (choice == 0)
			break;

		// 依選擇執行動作
		switch (choice) {
			case 1:
				list = addNode(list, &list_N);
			break;
			case 2:
				displayList(list, list_N);
			break;
			default:
				printf("錯誤的選項!\n");
			continue;
		}
		// 神奇的分隔線
		printf("-------------------------------\n");
	}
	return 0;
}
