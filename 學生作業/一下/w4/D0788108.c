#include <stdio.h>

typedef struct fraction{
    int nume;
    int deno;
}fra;

int gcd (int a, int b){
    if (b != 0)
        return gcd(b, a % b);
    else
        return a;
}

fra add (fra num_1, fra num_2){
    fra temp;
    temp.nume = (num_1.nume * num_2.deno) + (num_2.nume * num_1.deno);
    temp.deno = num_1.deno * num_2.deno;
    return temp;
}

fra sub(fra num_1, fra num_2){
    fra temp;
    temp.nume = (num_1.nume * num_2.deno) - (num_2.nume * num_1.deno);
    temp.deno = num_1.deno * num_2.deno;
    return temp;
}

fra pro(fra num_1, fra num_2){
    fra temp;
    temp.nume = num_1.nume * num_2.nume;
    temp.deno = num_1.deno * num_2.deno;
    return temp;
}

fra div(fra num_1, fra num_2){
    fra temp;
    temp.nume = num_1.nume * num_2.deno;
    temp.deno = num_1.deno * num_2.nume;
    return temp;
}

int main(){
    fra (*fptr[])(fra, fra) = {add, sub, pro, div}, temp_1, temp_2, ans;
    char ope[4] = {'+', '-', '*', '/'};
    int choose, factor;
    while (printf("選擇(1.加/2.減/3.乘/4.除/0.離開) : "), scanf("%d", &choose) && choose){
        if (choose >= 5 || choose < 0){
            printf("輸入錯誤\n\n");
            continue;
        }
        printf("a/b %c c/d, 請輸入a, b, c, d: ",ope[choose-1]);
        scanf("%d %d %d %d", &temp_1.nume, &temp_1.deno, &temp_2.nume, &temp_2.deno);
        if (temp_1.deno == 0 || temp_2.deno == 0){
            printf("分母不可為0\n\n");
            continue;
        }
        if (choose == 4 && temp_2.nume == 0){
            printf("除數不可為0\n\n");
            continue;
        }
        ans = fptr[choose-1](temp_1, temp_2);
        factor = gcd(ans.nume, ans.deno);
        if (ans.deno < 0 && ans.nume > 0)
            ans.nume*= -1, ans.deno *= -1;
        if (ans.deno/factor != 1)
            printf("%d/%d %c %d/%d = %d/%d\n\n", temp_1.nume, temp_1.deno, ope[choose-1], temp_2.nume, temp_2.deno, ans.nume/factor, ans.deno/factor);
        else
            printf("%d/%d %c %d/%d = %d\n\n", temp_1.nume, temp_1.deno, ope[choose-1], temp_2.nume, temp_2.deno, ans.nume/factor);
    }
    return 0;
}
