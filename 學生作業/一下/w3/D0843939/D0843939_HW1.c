#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int multi(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    return a / b;
}
int mod(int a, int b)
{
    return a % b;
}
int main()
{
    int (*opt[])(int, int) = {add, sub, multi, divide, mod};
    int n,a,b;
    while(1)
    {
        printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):");
        scanf("%d", &n);
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
            printf("請輸入2個整數:");
            scanf("%d %d", &a, &b);
            printf("%d + %d = %d\n", a, b, opt[0](a, b));
        }
        if(n == 2)
        {
            printf("請輸入2個整數:");
            scanf("%d %d", &a, &b);
            printf("%d - %d = %d\n", a, b, opt[1](a, b));
        }
        if(n == 3)
        {
            printf("請輸入2個整數:");
            scanf("%d %d", &a, &b);
            printf("%d * %d = %d\n", a, b, opt[2](a, b));
        }
        if(n == 4)
        {
            printf("請輸入2個整數:");
            scanf("%d %d", &a, &b);
            printf("%d / %d = %d\n", a, b, opt[3](a, b));
        }
        if(n == 5)
        {
            printf("請輸入2個整數:");
            scanf("%d %d", &a, &b);
            printf("%d %% %d = %d\n", a, b, opt[4](a, b));
        }
    }
}
