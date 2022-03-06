#include<stdio.h>
#include<stdlib.h>

struct cal
{
    int n1, n2;
};

struct cal add(struct cal num1, struct cal num2)
{
    struct cal sum = {num1.n1 * num2.n2 + num2.n1 * num1.n2, num1.n2 * num2.n2};
    return sum;
};

struct cal sub(struct cal num1, struct cal num2)
{
    struct cal sum = {num1.n1 * num2.n2 - num2.n1 * num1.n2, num1.n2 * num2.n2};
    return sum;
};

struct cal multi(struct cal num1, struct cal num2)
{
    struct cal sum = {num1.n1 * num2.n1, num1.n2 * num2.n2};
    return sum;
};

struct cal divide(struct cal num1, struct cal num2)
{
    struct cal sum = {num1.n1 * num2.n2, num1.n2 * num2.n1};
    return sum;
};

int main()
{
    int count = 0;
    char x[] = "+-*/";
    int sle;
    while (1) {
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開)：");
        scanf("%d", &sle);
        if (sle == 0) {
            return 0;
        }
        else if (sle == 1 || sle == 2 || sle == 3 || sle == 4) {

        }
        else {
            printf("輸入錯誤\n\n");
            continue;
        }
        printf("a/b %c c/d，請輸入a b c d：", x[sle - 1]);
        struct cal num1;
        struct cal num2;
        scanf("%d %d %d %d", &num1.n1, &num1.n2, &num2.n1, &num2.n2);
        if (num1.n2 == 0 || num2.n2 == 0) {
            printf("分母不可為0\n\n");
            continue;
        }
        else if (sle == 4 && num2.n1 == 0) {
            printf("除數不可為0\n\n");
            continue;
        }
        printf("%d/%d %c %d/%d = ", num1.n1, num1.n2, x[sle - 1], num2.n1, num2.n2);
        struct cal sum[100];
        if (sle == 1) {
            sum[count] = add(num1, num2);
        }
        else if (sle == 2) {
            sum[count] = sub(num1, num2);
        }
        else if (sle == 3) {
            sum[count] = multi(num1, num2);
        }
        else if (sle == 4) {
            sum[count] = divide(num1, num2);
        }
        int min = abs(sum[count].n1), max = abs(sum[count].n2);
        if (max < min) {
            int tmp = min;
            min = max;
            max = tmp;
        }
        printf("%d %d\n",min,max);
        for (int i = min; i > 1; i--) {
            if (min % i == 0 && max % i == 0) {
                sum[count].n1 /= i;
                sum[count].n2 /= i;
                break;
            }
        }
        if (sum[count].n2 < 0 && sum[count].n1 >= 0) {
            printf("-");
            sum[count].n2 = abs(sum[count].n2);
        }
        else if (sum[count].n2 < 0 && sum[count].n1 < 0) {
            sum[count].n2 = abs(sum[count].n2);
            sum[count].n1 = abs(sum[count].n1);
        }
        printf("%d", sum[count].n1);
        if (sum[count].n2 == 1) {
            printf("\n\n");
        }
        else {
            printf("/%d\n\n", sum[count].n2);
        }
        count++;
    }
    return 0;
}
