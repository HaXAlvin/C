#include<stdio.h>
#include<stdlib.h>

typedef union
{
    int i;
    float f;
    char s[16];
}B;

typedef struct
{
    B b;
    char c;
}A;

void input(A *a, char c)
{
    if (c == 'i') {
        scanf("%d", &(*a).b.i);
    }
    else if (c == 'f') {
        scanf("%f", &(*a).b.f);
    }
    else if (c == 's') {
        scanf("%s", &(*a).b.s);
    }
}

void printall(A *a, char *c, int max)
{
    for (int i = 0; i < max; i++) {
        if (c[i] == 'i') {
            printf("%d\n", (a[i].b.i));
        }
        else if (c[i] == 'f') {
            printf("%f\n", (a[i].b.f));
        }
        else if (c[i] == 's') {
            printf("%s\n", (a[i].b.s));
        }
    }
}

int main()
{
    int max = 1, count = 0;
    A *st = malloc(sizeof(A));
    while (1) {
        int sle;
        while (1) {
            printf("選擇：(1.新增/2.印出/0.結束)：");
            scanf("%d", &sle);
            getchar();
            if (sle == 1 || sle == 2 || sle == 0) {
                break;
            }
            else {
                printf("輸入錯誤！\n\n");
            }
        }
        char c[100];
        if (sle == 1) {
            while (1) {
                printf("選擇類型：(i：int/f：float/s：char[16])：");
                scanf("%c%*c", &c[count]);
                if (c[count] == 'i' || c[count] == 'f' || c[count] == 's') {
                    break;
                }
                else {
                    printf("輸入錯誤！\n\n");
                }
            }
            printf("輸入資料：");
            input(&st[count], c[count]);
        }
        else if (sle == 2) {
            printall(st, c, max);
            continue;
        }
        else if (sle == 0) {
            printf("結束程式\n");
            free(st);
            break;
        }
        max++;
        count++;
        st = realloc(st, max * sizeof(A));
    }
    return 0;
}
