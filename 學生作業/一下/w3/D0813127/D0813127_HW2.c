#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp1(char *a, char *b) // �Q��ASCII�X���Ƨ�
{
    if (strcmp(a, b) > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int cmp2(char *a, char *b)  // �Q�Φr��ǰ��Ƨ�
{
    char table[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";  // �r���
    int max = strlen(a);
    if (strlen(b) > max) {
        max = strlen(b);
    }
    for (int i = 0; i < max; i++) {  // ����U�r���b�r�媺����
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
    for (int i = n - 1; i > 0; i--) {  // �w�j�Ƨ�
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
        printf("�п�J�r���(��J0����): ");
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
            printf("��ܱƧǤ覡(1. �HASCII / 2. �H�r���): ");
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
