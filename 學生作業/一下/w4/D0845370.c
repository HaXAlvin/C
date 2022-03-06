#include <stdio.h>
#include <math.h>

typedef struct{
    int n,d; //分母(numerator),分子(denominator)
}fractions; //分數結構

fractions reduction_f(fractions f){ //約分
    int is_neg = 0, min = 0, Max_factor = 0,i; //判斷分子是否負數,判斷分子分母大小,最大公因數
    if(f.d < 0){ //先將有負號的都取絕對值
        f.d= fabs(f.d);
        is_neg += 1;
    }
    if(f.d >= f.n) //分母小
        min = f.n;
    else           //分子小
        min = f.d;
    for(i=2;i<=min;i++){ //求最大公因數
        if(f.d % i == 0 && f.n % i == 0)
            Max_factor = i;
    }
    if(Max_factor > 0){ //約分
        f.d = f.d / Max_factor;
        f.n = f.n / Max_factor;
    }
    if(is_neg > 0) //將負號加回來
        f.d = 0 - f.d;
    return f;
}

fractions add_ope(fractions f1, fractions f2){ //加的運算
    fractions add;
    add.d = (f1.d * f2.n) + (f2.d * f1.n); //兩個分數相加
    add.n = f1.n * f2.n;
    if(add.n < 0){ //將負號移至分子
        add.n = fabs(add.n);
        add.d = 0 - add.d;
    }
    add = reduction_f(add); //約分
    return add;
}

fractions sub_ope(fractions f1, fractions f2){ //減的運算
    fractions sub;
    sub.d = (f1.d * f2.n) - (f2.d * f1.n); //兩個分數相減
    sub.n = f1.n * f2.n;
    if(sub.n < 0){ //將負號移至分子
        sub.n = fabs(sub.n);
        sub.d = 0 - sub.d;
    }
    sub = reduction_f(sub); //約分
    return sub;
}

fractions multi_ope(fractions f1, fractions f2){ //乘的運算
    fractions multi;
    multi.d = f1.d * f2.d; //兩個分數相乘
    multi.n = f1.n * f2.n;
    if(multi.n < 0){ //將負號移至分子
        multi.n = fabs(multi.n);
        multi.d = 0 - multi.d;
    }
    multi = reduction_f(multi); //約分
    return multi;
};

fractions div_ope(fractions f1, fractions f2){ //除的運算
    fractions div;
    div.d = f1.d * f2.n; //兩個分數相除
    div.n = f1.n * f2.d;
    if(div.n < 0){ //將負號移至分子
        div.n = fabs(div.n);
        div.d = 0 - div.d;
    }
    div = reduction_f(div); //約分
    return div;
}

int main(){
    while(1){
        int choose = 0;
        fractions f1,f2,ans; //運算式的第一個分數,第二個分數,結果
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開)：");
        scanf("%d", &choose);
        if(choose == 0)
            return 0;
        else if(choose == 1){ //加法
            printf("a/b + c/d，請輸入a b c d：");
            scanf("%d %d %d %d", &f1.d, &f1.n, &f2.d, &f2.n);
            if(f1.n == 0 || f2.n == 0) //分母輸入為0
                printf("分母不可為0\n\n");
            else{
                ans = add_ope(f1, f2); //加法運算
                if(ans.n == 1 || ans.d == 0) //整數
                    printf("%d/%d + %d/%d = %d\n\n", f1.d, f1.n, f2.d, f2.n, ans.d);
                else
                    printf("%d/%d + %d/%d = %d/%d\n\n", f1.d, f1.n, f2.d, f2.n, ans.d, ans.n);
            }
        }
        else if(choose == 2){ //減法
            printf("a/b - c/d，請輸入a b c d：");
            scanf("%d %d %d %d", &f1.d, &f1.n, &f2.d, &f2.n);
            if(f1.n == 0 || f2.n == 0) //分母輸入為0
                printf("分母不可為0\n\n");
            else{
                ans = sub_ope(f1, f2); //減法運算
                if(ans.n == 1 || ans.d == 0) //整數
                    printf("%d/%d - %d/%d = %d\n\n", f1.d, f1.n, f2.d, f2.n, ans.d);
                else
                    printf("%d/%d - %d/%d = %d/%d\n\n", f1.d, f1.n, f2.d, f2.n, ans.d, ans.n);
            }
        }
        else if(choose == 3){ //乘法
            printf("a/b * c/d，請輸入a b c d：");
            scanf("%d %d %d %d", &f1.d, &f1.n, &f2.d, &f2.n);
            if(f1.n == 0 || f2.n == 0) //分母輸入為0
                printf("分母不可為0\n\n");
            else{
                ans = multi_ope(f1, f2); //乘法運算
                if(ans.n == 1 || ans.d == 0) //整數
                    printf("%d/%d * %d/%d = %d\n\n", f1.d, f1.n, f2.d, f2.n, ans.d);
                else
                    printf("%d/%d * %d/%d = %d/%d\n\n", f1.d, f1.n, f2.d, f2.n, ans.d, ans.n);
            }
        }
        else if(choose == 4){ //除法
            printf("a/b / c/d，請輸入a b c d：");
            scanf("%d %d %d %d", &f1.d, &f1.n, &f2.d, &f2.n);
            if(f2.d == 0){ //輸入使除數為0
                printf("除數不可為0\n\n");
            }
            else{
                if(f1.n == 0 || f2.n == 0) //分母輸入為0
                    printf("分母不可為0\n\n");
                else{
                    ans = div_ope(f1, f2); //除法運算
                    if(ans.n == 1 || ans.d == 0) //整數
                        printf("%d/%d / %d/%d = %d\n\n", f1.d, f1.n, f2.d, f2.n, ans.d);
                    else
                        printf("%d/%d / %d/%d = %d/%d\n\n", f1.d, f1.n, f2.d, f2.n, ans.d, ans.n);
                }
            }
        }
        else if(choose > 4 || choose < 0) //輸入指令錯誤
            printf("輸入錯誤\n\n");
    }
}
