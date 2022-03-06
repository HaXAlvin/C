#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int cmp1(char *strA, char *strB) {
	for (; *strA == *strB; ++strA, ++strB)
		if (*strA == '\0')
			return 0;
	return *strA > *strB;
}

int cmp2(char *strA, char *strB) {
	for (; *strA == *strB; ++strA, ++strB)
		if (*strA == '\0')
			return 0;
	return tolower(*strA) > tolower(*strB) ? 1 : *strA > *strB;
}

void movListPointer(char **arr, int start, int end) {
	for (int i = end; i > start; --i)
		arr[i] = arr[i - 1];
}
void sort(char **sArr, int n, int (*cmp)(char*, char*)) {
	char *tmpptr;
	for (int end = 1; end < n; ++end) {
		for (int start = 0; start < end; ++start) {
			if (!cmp(sArr[end], sArr[start])) {
				tmpptr = sArr[end];
				movListPointer(sArr, start, end);
				sArr[start] = tmpptr;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int line = 0;
	int choice = 0;
	char **sArr;
	sArr = malloc(100 * sizeof(char));
	for (int i = 0; i < 100; ++i)
		*(sArr + i) = malloc(100 * sizeof(char));
	while (1) {
		// Input 1
		fputs("請輸入測資行數(輸入0結束)：", stdout);
		scanf("%i", &line);
		getchar();
		if (line == 0)
			break;
		// Input 2
		for (int i = 0; i < line; ++i)
			gets(sArr[i]);
		// Input 3
		fputs("請選擇排序方式(1. ASCII/2. 字典序)：", stdout);
		scanf("%i", &choice);
		getchar();
		// Process
		if (choice == 1)
			sort(sArr, line, cmp1);
		else if (choice == 2)
			sort(sArr, line, cmp2);
		else
			continue;
		// Output 1
		for (int i = 0; i < line; ++i)
			puts(sArr[i]);
	}
	return 0;
}