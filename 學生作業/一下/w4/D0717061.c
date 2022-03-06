/*  109年度  資訊二丁
        第四週作業       */
#include<stdio.h>//標頭檔
#include<stdlib.h>
int hcf(int n1,int n2)//找最大公因數
{
    return n2?hcf(n2,n1%n2):n1;
}
struct fraction//定義分數結構
{
    int numerator,denominator;//分子、分母
};
struct fraction reduce(struct fraction result)//約分
{
    int gcd = hcf(result.numerator, result.denominator);//找最大公因數
    result.numerator /= gcd;//除最大公因數
    result.denominator /= gcd;
    if(result.denominator<0)//如果分母小於0
    {
        result.numerator*=-1;//負號給分子
        result.denominator*=-1;
    }
    return result;//回傳結果
}
struct fraction add(struct fraction num1, struct fraction num2)//加法
{
    num1.numerator *= num2.denominator;
    num2.numerator *= num1.denominator;//通分
    struct fraction result = {num1.numerator + num2.numerator,num1.denominator * num2.denominator};//分數結果結構
    result = reduce(result);//結果約分
    return result;//回傳結果
}
struct fraction sub(struct fraction num1, struct fraction num2)//減法
{
    num1.numerator *= num2.denominator;
    num2.numerator *= num1.denominator;//通分
    struct fraction result = {num1.numerator - num2.numerator,num1.denominator * num2.denominator};//分數結果結構
    result = reduce(result);//結果約分
    return result;//回傳結果
}
struct fraction multi(struct fraction num1, struct fraction num2)//乘法
{
    struct fraction result = {num1.numerator*num2.numerator,num1.denominator*num2.denominator};//分數乘法結構
    result = reduce(result);//結果約分
    return result;//回傳結果
}
struct fraction divide(struct fraction num1, struct fraction num2)//除法
{
    struct fraction result = {num1.numerator * num2.denominator,num1.denominator * num2.numerator};//分數除法結構
    result = reduce(result);//結果約分
    return result;//回傳結果
}
int main()
{
    struct fraction num1;//宣告結構變數
    struct fraction num2;
    int n=0;
    while(1)
    {
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開)：");//顯示文字
        scanf("%d",&n);
        if(n==1)//選擇加法
        {
            printf("a/b + c/d，請輸入a b c d：");
            scanf("%d %d %d %d",&num1.numerator,&num1.denominator,&num2.numerator,&num2.denominator);//輸入分子分母
            if(num1.denominator==0||num2.denominator==0)//若分母為0
            {
                printf("分母不可為0\n");
            }
            else
            {
                struct fraction addition = add(num1, num2);//宣告加法結果結構
                if(addition.denominator==1)//如果分母為1
                {
                    printf("%d/%d + %d/%d = %d\n", num1.numerator,num1.denominator,num2.numerator,num2.denominator,addition.numerator);//只顯示分子
                }
                else
                    printf("%d/%d + %d/%d = %d/%d\n", num1.numerator,num1.denominator,num2.numerator,num2.denominator,addition.numerator,addition.denominator);//顯示結果分子分母
            }
        }
        if(n==2)//減法
        {
            printf("a/b - c/d，請輸入a b c d：");
            scanf("%d %d %d %d",&num1.numerator,&num1.denominator,&num2.numerator,&num2.denominator);//輸入分子分母
            if(num1.denominator==0||num2.denominator==0)//若分母為0
            {
                printf("分母不可為0\n");
            }
            else
            {
                struct fraction subtraction = sub(num1, num2);//宣告減法結果結構
                if(subtraction.denominator==1)//如果分母為1
                {
                    printf("%d/%d - %d/%d = %d\n", num1.numerator,num1.denominator,num2.numerator,num2.denominator,subtraction.numerator);//只顯示分子
                }
                else
                    printf("%d/%d - %d/%d = %d/%d\n", num1.numerator,num1.denominator,num2.numerator,num2.denominator,subtraction.numerator,subtraction.denominator);//顯示結果分子分母
            }
        }
        if(n==3)//選擇乘法
        {
            printf("a/b * c/d，請輸入a b c d：");
            scanf("%d %d %d %d",&num1.numerator,&num1.denominator,&num2.numerator,&num2.denominator);//輸入分子分母
            if(num1.denominator==0||num2.denominator==0)//若分母為0
            {
                printf("分母不可為0\n");
            }
            else
            {
                struct fraction multiplication = multi(num1, num2);//宣告乘法結果結構
                if(multiplication.denominator==1)//如果分母為1
                {
                    printf("%d/%d * %d/%d = %d\n", num1.numerator,num1.denominator,num2.numerator,num2.denominator,multiplication.numerator);//只顯示分子
                }
                else
                    printf("%d/%d * %d/%d = %d/%d\n",num1.numerator,num1.denominator,num2.numerator,num2.denominator,multiplication.numerator,multiplication.denominator);//顯示結果分子分母
            }
        }
        if(n==4)//選擇除法
        {
            printf("a/b / c/d，請輸入a b c d：");
            scanf("%d %d %d %d",&num1.numerator,&num1.denominator,&num2.numerator,&num2.denominator);//輸入分子分母
            if(num2.numerator==0)//若除數為0
            {
                printf("除數不可為0\n");
            }
            else if(num1.denominator==0||num2.denominator==0)//若分母為0
            {
                printf("分母不可為0\n");
            }
            else
            {
                struct fraction division = divide(num1, num2);//宣告除法結果結構
                if(division.denominator==1)//如果分母為1
                {
                    printf("%d/%d / %d/%d = %d\n", num1.numerator,num1.denominator,num2.numerator,num2.denominator,division.numerator);//只顯示分子
                }
                else
                    printf("%d/%d / %d/%d = %d/%d\n",num1.numerator,num1.denominator,num2.numerator,num2.denominator,division.numerator,division.denominator);//顯示結果分子分母
            }
        }
        if(n<0||n>4)//選擇超出範圍
        {
            printf("輸入錯誤\n");
        }
        if(n==0)//選擇離開
        {
            return 0;//回傳並結束程式
        }
        printf("\n");//空一行
    }
}



