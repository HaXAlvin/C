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
        printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}):");
        scanf("%d", &n);
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
            printf("�п�J2�Ӿ��:");
            scanf("%d %d", &a, &b);
            printf("%d + %d = %d\n", a, b, opt[0](a, b));
        }
        if(n == 2)
        {
            printf("�п�J2�Ӿ��:");
            scanf("%d %d", &a, &b);
            printf("%d - %d = %d\n", a, b, opt[1](a, b));
        }
        if(n == 3)
        {
            printf("�п�J2�Ӿ��:");
            scanf("%d %d", &a, &b);
            printf("%d * %d = %d\n", a, b, opt[2](a, b));
        }
        if(n == 4)
        {
            printf("�п�J2�Ӿ��:");
            scanf("%d %d", &a, &b);
            printf("%d / %d = %d\n", a, b, opt[3](a, b));
        }
        if(n == 5)
        {
            printf("�п�J2�Ӿ��:");
            scanf("%d %d", &a, &b);
            printf("%d %% %d = %d\n", a, b, opt[4](a, b));
        }
    }
}
