#include <stdio.h>
#include <stdlib.h>

// data, type, *next_node
typedef struct node {
	union {
		int I;
		float F;
		char S[16];
	};
	int type;
	struct node *Next;
} Node;

/*
   Info: 插入新節點於指定串列的最後面
   Parameters: 舊串列最後一個節點的位址，新節點將被插入至該節點的下一個位址，傳入NULL代表創建一新串列
   Return value: 新串列的新節點的位址
*/
Node* newNode(Node* startNode) {
	Node *currentNode = (Node*) malloc(sizeof(Node));          // 創建一新節點，之後再移動到目標位置
	if (startNode != NULL)                                     // 傳入值若為NULL，創建新串列，指派為操作對象
		startNode->Next = currentNode;
	do {
		printf("請選擇類型 (1: int, 2: float, 3: char[16])："); // 選資料類型
		scanf("%i", &currentNode->type);
		setbuf(stdin, NULL);                                   // 移除緩衝區內容
		switch (currentNode->type) {
			case 1: //int
				printf("請輸入整數：");
				scanf("%i", &currentNode->I);      // 輸入資料 (Int) 
			break;
			case 2: //float
				printf("請輸入小數：");
				scanf("%f", &currentNode->F);      // 輸入資料 (Float)
			break;
			case 3: //string[16]
				printf("請輸入字串：");
				scanf("%16[^\n]", currentNode->S); // 輸入資料 (String)
			break;
			default:
				puts("Wrong Type!\n");
				currentNode->type = -1;
			break;
		}
		setbuf(stdin, NULL);           // 移除緩衝區內容
	} while (currentNode->type == -1); // 類型錯誤，重來
	currentNode->Next = NULL;          // 插入的節點指向NULL終止
	return currentNode;                // 返回新節點位址
}

/*
   Info: 依序換行輸出串列內容，以傳入節點為起始點
*/
void printNode(Node *currentNode) {
	while (currentNode != NULL) {
		switch (currentNode->type) {
			case 1:
				printf("%i\n", currentNode->I);
			break;
			case 2:
				printf("%f\n", currentNode->F);
			break;
			case 3:
				printf("%s\n", currentNode->S);
			break;
		}
		currentNode = currentNode->Next; // 切換至下一節點
	}
}

/*
   Info: 依序釋放串列記憶體，以傳入節點為起始點
*/
void freeNode(Node *currentNode) {
	void *nextPtr;
	while (currentNode != NULL) {
		nextPtr = currentNode->Next; // 下一節點之位址的Buffer
		free(currentNode);           // 釋放當前節點
		currentNode = nextPtr;       // 依據緩衝的nextPtr切換至下一節點
	}
}

int main(void) {
	int choice = 0;
	Node* startNode = NULL;
	Node* currentNode = NULL;

	while (1) {
		setbuf(stdin, NULL);  // 移除緩衝區內容
		printf("請選擇動作 (1. 新增, 2. 印出, 0. 結束)：");
		scanf("%i", &choice); // 選擇動作
		switch (choice) {
			case 1:  // 新增節點
				if (currentNode == NULL) {              // 無串列
					startNode = newNode(NULL);          // 新增一個節點
					currentNode = startNode;
				} else {                                // 有串列
					currentNode = newNode(currentNode); // 新增節點並切換至下一個節點
				}
			break;
			case 2:  // 印出串列
				printNode(startNode);
			break;
			case 0:  // 釋放串列並離開
				freeNode(startNode);
			return 0;
			default: // 錯誤選擇
				puts("Wrong Choice!\n");
			break;
		}
	}
	return 1;
}