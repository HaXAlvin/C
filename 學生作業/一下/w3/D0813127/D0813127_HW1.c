#include<stdio.h>

int add(int a, int b)
{
    int c = a + b;
    return c;
}

int sub(int a, int b)
{
    int c = a - b;
    return c;
}

int multi(int a, int b)
{
    int c = a * b;
    return c;
}

int divide(int a, int b)
{
    int c = a / b;
    return c;
}

int mod(int a, int b)
{
    int c = a % b;
    return c;
}

int main()
{
    char cal[] = "+-*/%";
    int s;
    while (1) {
        while (1) {
            printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):");
            scanf("%d", &s);
            if (s == 0) {
                return 0;
            }
            else if (s == 1 || s == 2 || s == 3 || s == 4 || s == 5) {
                break;
            }
            else {
                printf("ERROR\n\n");
            }
        }
        printf("請輸入2個整數:");
        int a, b;
        scanf("%d %d", &a, &b);
        int (*opt[])(int, int) = {add, sub, multi, divide, mod};
        printf("%d %c %d = %d\n\n", a, cal[s - 1], b, opt[s - 1](a, b));
    }
    return 0;
}
