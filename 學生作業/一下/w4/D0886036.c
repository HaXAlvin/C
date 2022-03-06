#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ip{// 分子分母
    int up, down;
};

int gcd(struct ip a){//最大公因數
    while(a.down != 0) {
        int temp = a.up % a.down;
        a.up = a.down;
        a.down = temp;
    }
    return a.up;
}

struct ip add(struct ip i, struct ip j){//加法
    int a, b;//通分
    a = i.up * j.down + j.up * i.down;
    b = i.down * j.down;

    struct ip c = {
        a, b
    };
    int count = gcd(c);//簡化分數
    int k;
    int h = c.up;//分子
    k = h/count;
    c.up = k;
    int p;
    int g = c.down;//分母
    p = g/count;
    c.down = p;
    return c;

};

struct ip sub(struct ip i, struct ip j){//減法
    int a, b;//通分
    a = i.up * j.down - j.up * i.down;
    b = i.down * j.down;

    struct ip c = {
        a, b
    };
    int count = gcd(c);//簡化分數
    int k;
    int h = c.up;//分子
    k = h/count;
    c.up = k;
    int p;
    int g = c.down;//分母
    p = g/count;
    c.down = p;
    return c;
};

struct ip multi(struct ip i, struct ip j){//乘法
    int a, b;//直接相乘
    a = i.up * j.up;
    b = i.down * j.down;
    struct ip c = {
        a, b
    };
    int count = gcd(c);//簡化分數
    int k;
    int h = c.up;//分子
    k = h/count;
    c.up = k;
    int p;
    int g = c.down;//分母
    p = g/count;
    c.down = p;
    return c;
};

struct ip divi(struct ip i, struct ip j){//除法
    int a, b;//直接相除
    a = i.up * j.down;
    b = i.down * j.up;
    struct ip c = {
        a, b
    };
    int count = gcd(c);//簡化分數
    int k;
    int h = c.up;//分子
    k = h/count;
    c.up = k;
    int p;
    int g = c.down;//分母
    p = g/count;
    c.down = p;
    return c;
};

int main(){
    int function;//功能
    while(1){
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開) : ");//輸入功能
        scanf("%d", &function);
        if(function == 1){
            printf("a/b + c/d，請輸入a b c d : ");
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);//輸入兩個分數
            if(b == 0 || d == 0){//防蠢
                printf("分母不可為0\n");
                continue;
            }
            struct ip first = {//第一個分數
                a, b
            };
            struct ip second = {//第二個分數
                c, d
            };
            struct ip op = add(first, second);
            if(op.down < 0){//移負號到分子
                op.up*= -1;
                op.down*= -1;
            }
            if(op.up % op.down != 0)//結果不是整數,輸出分數
                printf("%d/%d + %d/%d = %d/%d\n\n",a,b,c,d,op.up, op.down);
            else//若為整數,輸出整數
                printf("%d/%d + %d/%d = %d\n\n",a,b,c,d,op.up);
        }
        else if(function == 2){
            printf("a/b - c/d，請輸入a b c d : ");
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);//輸入兩個分數
            if(b == 0 || d == 0){//防蠢
                printf("分母不可為0\n");
                continue;
            }
            struct ip first = {//第一個分數
                a, b
            };
            struct ip second = {//第二個分數
                c, d
            };
            struct ip op = sub(first, second);
            if(op.down < 0){//移負號到分子
                op.down *= -1;
                op.up *= -1;
            }
            if(op.up % op.down != 0)//結果不是整數,輸出分數
                printf("%d/%d + %d/%d = %d/%d\n\n",a,b,c,d,op.up, op.down);
            else//若為整數,輸出整數
                printf("%d/%d + %d/%d = %d\n\n",a,b,c,d,op.up);
        }
        else if(function == 3){
            printf("a/b * c/d，請輸入a b c d : ");
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);//輸入兩個分數
            if(b == 0 || d == 0){//防呆
                printf("分母不可為0\n");
                continue;
            }
            struct ip first = {//第一個分數
                a, b
            };
            struct ip second = {//第二個分數
                c, d
            };
            struct ip op = multi(first, second);
            if(op.down < 0){//移負號到分子
                op.down *= -1;
                op.up *= -1;
            }
            if(op.up % op.down != 0)//結果不是整數,輸出分數
                printf("%d/%d + %d/%d = %d/%d\n\n",a,b,c,d,op.up, op.down);
            else//若為整數,輸出整數
                printf("%d/%d + %d/%d = %d\n\n",a,b,c,d,op.up);
        }
        else if(function == 4){
            printf("a/b / c/d，請輸入a b c d : ");
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);//輸入兩個分數
            if(b == 0 || d == 0){//防蠢
                printf("分母不可為0\n\n");
                continue;
            }
            else if(c == 0){//防蠢
                printf("除數不可為0\n\n");
                continue;
            }
            struct ip first = {//第一個分數
                a, b
            };
            struct ip second = {//第一個分數
                c, d
            };
            struct ip op = divi(first, second);
            if(op.down < 0){//移負號到分子
                op.down *= -1;
                op.up *= -1;
            }
            if(op.up % op.down != 0)//結果不是整數,輸出分數
                printf("%d/%d + %d/%d = %d/%d\n\n",a,b,c,d,op.up, op.down);
            else//若為整數,輸出整數
                printf("%d/%d + %d/%d = %d\n\n",a,b,c,d,op.up);
        }
        else if(function != 0 && function != 1 && function != 2 && function != 3 && function != 4)//輸入錯誤情況
            printf("輸入錯誤\n\n");
        else if(function == 0)//結束
            return 0;
    }
}
