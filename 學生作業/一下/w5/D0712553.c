#include<stdio.h>
#include<stdlib.h>

typedef struct _List {
	enum {
		Int, Float, Str,
	}type;
	union Data{
		int i;
		float f;
		char s[16];
	}data;
}List;

void app(List* list, int time) {
	char ifs;
	while (1) {
		printf("選擇型態:(i:int/f:float/s:char[16]):");
		scanf("%c", &ifs);
		getchar();
		if (ifs == 'i') {
			list[time].type = Int;
			break;
		}
		else if (ifs == 'f') {
			list[time].type = Float;
			break;
		}
		else if (ifs == 's') {
			list[time].type = Str;
			break;
		}
		else {
			printf("輸入錯誤\n");
		}
	}
	printf("輸入資料:");
	if (ifs == 'i') {
		scanf("%d", &list[time].data.i);
	}
	else if (ifs == 'f') {
		scanf("%f", &list[time].data.f);
	}
	else if (ifs == 's') {
		scanf("%s", list[time].data.s);
	}
}

int main() {
	List* list = malloc(sizeof(List));
	int time = 0;

	while (1) {
		int choose;
		printf("選擇:(1.新增/2.印出/0.結束)：");
		scanf("%d", &choose);
		getchar();

		if (choose == 1) {
			if (time != 0) {
				list = realloc(list, (time + 1) * sizeof(List));
			}
			app(list, time);
			time++;
		}
		else if (choose == 2) {
			int i;
			for (i = 0; i < time; i++) {
				if (list[i].type == 0) {
					printf("%d\n", list[i].data.i);
				}
				else if (list[i].type == 1) {
					printf("%f\n", list[i].data.f);
				}
				else if (list[i].type == 2) {
					printf("%s\n", list[i].data.s);
				}
			}
		}
		else if (choose == 0) {
			free(list);
			break;
		}
		else {
			printf("輸入錯誤\n");
		}
	}
	return 0;
}