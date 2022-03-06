#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp1(char *a, char *b) // 利用ASCII碼做排序
{
    if (strcmp(a, b) > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int cmp2(char *a, char *b)  // 利用字典序做排序
{
    char table[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";  // 字典序
    int max = strlen(a);
    if (strlen(b) > max) {
        max = strlen(b);
    }
    for (int i = 0; i < max; i++) {  // 比較各字母在字典的順序
        int locate_a = 0, locate_b = 0;
        for (int j = 0; j < 52; j++) {
            if (table[j] == a[i]) {
                locate_a = j;
            }
            if (table[j] == b[i]) {
                locate_b = j;
            }
            if (locate_a != 0 && locate_b != 0) {
                break;
            }
        }
        if (locate_a == locate_b) {
            continue;
        }
        else if (locate_a > locate_b) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

void sort(char **str, int n, int (*cmp)(char *, char *))
{
    for (int i = n - 1; i > 0; i--) {  // 泡沫排序
        for (int j = 0; j < i; j++) {
            if (cmp(str[j], str[j + 1])) {
                char *tmp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    while (1) {
        printf("請輸入字串數(輸入0結束): ");
        int num;
        scanf("%d", &num);
        getchar();
        if (num == 0) {
            break;
        }
        char **str;
        char s[100];
        str = calloc(num, sizeof(char *));
        for (int i = 0; i < num; i++) {
            gets(s);
            str[i] = calloc(strlen(s), sizeof(char));
            strcpy(str[i], s);
        }
        int select;
        while (1) {
            printf("選擇排序方式(1. 以ASCII / 2. 以字典序): ");
            scanf("%d", &select);
            if (select == 1 || select == 2) {
                break;
            }
            else {
                printf("ERROR\n\n");
            }
        }
        if (select == 1) {
            sort(str, num, cmp1);
        }
        else {
            sort(str, num, cmp2);
        }
        for (int i = 0; i < num; i++) {
            printf("%s\n", str[i]);
        }
    }
    return 0;
}
