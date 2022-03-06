#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int count = 0, max = 10;
    char **name;
    name = calloc(max, sizeof(char *));
    while (1) {  // 主選單
        printf("1. 新增\n");
        printf("2. 印出\n");
        printf("3. 排序\n");
        printf("4. 離開\n");
        int select;
        printf("輸入 : ");
        scanf("%d%*c", &select);
        printf("\n");
        if (select == 1) {
            if (count >= max) {  // 預設指標陣列為10，不夠時自動補5個
                max += 5;
                name = realloc(name, max * sizeof(char *));
            }
            char name1[100] = {0};
            gets(name1);
            printf("\n");
            name[count] = calloc(strlen(name1)+1, sizeof(char));
            strcpy(name[count], name1);  // 將輸入的字串複製到指標陣列
            count++;
            continue;
        }
        else if (select == 2) {  // 印出所有輸入
            for (int i = 0; i < count; i++) {
                printf("%s\n", name[i]);
            }
            printf("\n");
            continue;
        }
        else if (select == 3) {  // 排序(泡沫)
            for (int i = count - 1; i > 0; i--) {
                for (int j = 0; j < i; j++) {
                    if (strcmp(name[j], name[j + 1]) == 1) {
                        char *tmp = name[j];
                        name[j] = name[j + 1];
                        name[j + 1] = tmp;
                    }
                }
            }
            continue;
        }
        else if (select == 4) {  // 釋放記憶體 & 離開
            for (int i = 0; i < max; i++) {
                free(name[i]);
            }
            free(name);
            break;
        }
        else {  // 防止輸入規定以外的選項
            printf("ERROR\n\n");
            continue;
        }
    }
    return 0;
}
