#include <stdio.h>

int add(int a, int b){ //加法
    return a + b;
}

int sub(int a, int b){ //減法
    return a - b;
}

int multi(int a, int b){ //乘法
    return a * b;
}

int divide(int a, int b){ //除法
    return a / b;
}

int mod(int a, int b){ //取餘數
    return a % b;
}

int main(){
    int (* opt[])(int, int) = {add,sub,multi,divide,mod}; //函示指標
    while(1){
        int a = 0,b = 0,choose = 0;
        printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開)：");
        scanf("%d", &choose);
        if(choose == 0)
            return 0;
        printf("請輸入2個整數；");
        scanf("%d %d", &a, &b);
        if(choose == 1)
            printf("%d + %d = %d\n", a, b, opt[0](a, b));
        else if(choose == 2)
            printf("%d - %d = %d\n", a, b, opt[1](a, b));
        else if(choose == 3)
            printf("%d * %d = %d\n", a, b, opt[2](a, b));
        else if(choose == 4)
            printf("%d / %d = %d\n", a, b, opt[3](a, b));
        else if(choose == 5)
            printf("%d %% %d = %d\n", a, b, opt[4](a, b));
    }
}
