#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR 128

int option = 4; // User selcted menu option
int line = 0; // Current already used line count
int lines = 10; // Total lines that free to use
char **name; //  A table to record strings
char tmpname[MAX_STR]; // A buffer to store name inputs for preprocessing
int tmpname_len; // Length of *tmpname

// Free dynamic memory used by **name
void freeName(void) {
	// Free second layer (char *)
	for (int i = 0; i < lines; ++i)
		free(*(name + i));
	// Free first layer (char **)
	free(name);
}

// Allocate and fill value to **name
void addName(void) {
	fputs("> 請輸入姓名：", stdout);
	scanf("%128s", tmpname);
	tmpname_len = strlen(tmpname) + 1;

	// Extend the space when the usage exceeds the limits
	if (line >= lines)
		name = realloc(name, (lines += 5) * sizeof(char *));

	// Allocate specified spaces for a string, and fill it with the buffer
	*(name + line) = malloc(tmpname_len * sizeof(char));
	strncpy(*(name + line++), tmpname, tmpname_len);
}

// Show **name content
void listName(void) {
	for (int i = 0; i < line; ++i) {
		fputs(*(name + i), stdout);
		if (i < line - 1)
			putchar('\n');
	}
	// Pause for the user
	getchar();
}

// Sort the pointers of **name using insertion sort, and call listName() to preview the results
void movListPointer(char **arr, int start, int end) {
	for (int i = end; i > start; --i)
		arr[i] = arr[i - 1];
}
void sortName(void) {
	char *tmpptr;
	for (int i = 1; i < line; ++i) {
		for (int j = 0; j < i; ++j) {
			if (strcmp(name[i], name[j]) < 0) { // A->Z
				tmpptr = name[i];
				movListPointer(name, j, i);
				name[j] = tmpptr;
			}
		}
	}
	listName();
}

// Provide a menu for interection
int start_menu(void) {
	while (1) {
		// Clean the page
		system("cls");
		printf(
			"1. 新增\n"
			"2. 印出\n"
			"3. 排序\n"
			"4. 離開\n\n"
			"> 請輸入選擇："
		);
		scanf("%i", &option);
		getchar(); //Capture the newline left by scanf
		switch (option) {
			case 1:
				addName();
			break;
			case 2:
				listName();
			break;
			case 3:
				sortName();
			break;
			case 4:
				freeName();
			return 0;
		}
	}
	return -1;
}

// Entry Point
int main(void) {
	// Init **name with 10 lines
	name = malloc(lines * sizeof(char *));
	return start_menu();
}