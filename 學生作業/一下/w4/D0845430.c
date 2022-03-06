#include <stdio.h>
#include <stdlib.h>
typedef struct number{//建立分數結構number
    int div, den;//div: 分子, den: 分母
}frac;//取名為frac

frac add(frac a, frac b){//兩數相加函式
    struct number c;//新增一個存答案的結構
    c.den=a.den*b.den;//分母相乘
    c.div=(a.div*b.den)+(a.den*b.div);//分子交叉相乘後相加
    return c;//回傳經過計算的結構
}

frac sub(frac a, frac b){//兩數相減函式
    struct number c;//新增一個存答案的結構
    c.den=a.den*b.den;//分母相乘
    c.div=(a.div*b.den)-(a.den*b.div);//分子交叉相乘後相減
    return c;//回傳經過計算的結構
}

frac multi(frac a, frac b){//兩數相乘函式
    struct number c;//新增一個存答案的結構
    c.div=a.div*b.div;//分子相乘
    c.den=a.den*b.den;//分母相乘
    return c;//回傳經過計算的結構
}

frac divide(frac a, frac b){//兩數相除函式
    struct number c;//新增一個存答案的結構
    c.div=a.div*b.den;//a分子與b分母相乘
    c.den=a.den*b.div;//b分子與a分母相乘
    return c;//回傳經過計算的結構
}

int gcd(int a, int b){//找最大公因數函式
    int tmp;
    while(a%b!=0){//輾轉相除法
        tmp=b;
        b=a%b;
        a=tmp;
    }
    return b;//回傳最大公因數
}

int main(){
    int cho;//功能選擇變數
    int ggcd;//最大公因數
    struct number n1;//第一個分數
    struct number n2;//第二個分數
    struct number n3;//答案的分數
    printf("1.Add/2.Subtract/3.Multiply/4.Divide/0.Leave:");//提示輸入
    scanf("%d", &cho);//使用者輸入選擇
    while(cho>=0){
        if(cho<0||cho>4)//輸入非0~4
            printf("Input error.\n\n");//顯示錯誤
        else if(cho==1){//選擇1(加法)
            printf("a/b + c/d, please input a b c d: ");//提示輸入
            scanf("%d %d %d %d", &n1.div, &n1.den, &n2.div, &n2.den);//輸入4個數字
            if(n1.den==0||n2.den==0)//若有分母輸入為0
                printf("Denominator can't be 0.\n\n");//顯示分母不可為0
            else{
                n3=add(n1, n2);//呼叫函式add進行加法計算
                ggcd=gcd(n3.div, n3.den);//呼叫函式gcd找最大公因數
                if(n3.div%n3.den==0)//若答案為整數
                    printf("%d/%d + %d/%d = %d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div/n3.den);//分子除以分母後印出整數
                else if(gcd(n3.div, n3.den)!=1){//若兩數無互質
                    n3.div/=ggcd;//分子除以最大公因數
                    n3.den/=ggcd;//分母除以最大公因數
                    if(n3.den<0)//若分母為負數
                        printf("%d/%d + %d/%d = %d/%d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div*(-1), n3.den*(-1));//分子分母各*(-1)後印出結果
                    else
                        printf("%d/%d + %d/%d = %d/%d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div, n3.den);//分子分母各除以最大公因數後印出結果
                }
                else
                    printf("%d/%d + %d/%d = %d/%d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div, n3.den);//印出結果
            }
        }
        else if(cho==2){//選擇2(減法)
            printf("a/b - c/d, please input a b c d: ");//提示輸入
            scanf("%d %d %d %d", &n1.div, &n1.den, &n2.div, &n2.den);//輸入4個數字
            if(n1.den==0||n2.den==0)//若有分母輸入為0
                printf("Denominator can't be 0.\n\n");//顯示分母不可為0
            else{
                n3=sub(n1, n2);//呼叫函式sub進行減法計算
                ggcd=gcd(n3.div, n3.den);//呼叫函式gcd找最大公因數
                if(n3.div%n3.den==0)//若答案為整數
                    printf("%d/%d - %d/%d = %d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div/n3.den);//分子除以分母後印出整數
                else if(gcd(n3.div, n3.den)!=1){//若兩數無互質
                    n3.div/=ggcd;//分子除以最大公因數
                    n3.den/=ggcd;//分母除以最大公因數
                    if(n3.den<0)//若分母為負數
                        printf("%d/%d - %d/%d = %d/%d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div*(-1), n3.den*(-1));//分子分母各*(-1)後印出結果
                    else
                        printf("%d/%d - %d/%d = %d/%d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div, n3.den);//分子分母各除以最大公因數後印出結果
                }
                else
                    printf("%d/%d - %d/%d = %d/%d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div, n3.den);//印出結果
            }
        }
        else if(cho==3){//選擇3(乘法)
            printf("a/b * c/d, please input a b c d: ");//提示輸入
            scanf("%d %d %d %d", &n1.div, &n1.den, &n2.div, &n2.den);//輸入4個數字
            if(n1.div==0||n2.div==0)//若有分子輸入為0
                printf("Divisor can't be 0.\n\n");//顯示分子不可為0
            else if(n1.den==0||n2.den==0)//若有分母輸入為0
                printf("Denominator can't be 0.\n\n");//顯示分母不可為0
            else{
                n3=multi(n1, n2);//呼叫函式multi進行乘法計算
                ggcd=gcd(n3.div, n3.den);//呼叫函式gcd找最大公因數
                if(n3.div%n3.den==0)//若答案為整數
                    printf("%d/%d * %d/%d = %d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div/n3.den);//分子除以分母後印出整數
                else if(gcd(n3.div, n3.den)!=1){//若兩數無互質
                    n3.div/=ggcd;//分子除以最大公因數
                    n3.den/=ggcd;//分母除以最大公因數
                    if(n3.den<0)//若分母為負數
                        printf("%d/%d * %d/%d = %d/%d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div*(-1), n3.den*(-1));//分子分母各*(-1)後印出結果
                    else
                        printf("%d/%d * %d/%d = %d/%d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div, n3.den);//分子分母各除以最大公因數後印出結果
                }
                else
                    printf("%d/%d * %d/%d = %d/%d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div, n3.den);//印出結果
            }
        }
        else if(cho==4){//選擇4(除法)
            printf("a/b / c/d, please input a b c d: ");//提示輸入
            scanf("%d %d %d %d", &n1.div, &n1.den, &n2.div, &n2.den);//輸入4個數字
            if(n1.div==0||n2.div==0)//若有分子輸入為0
                printf("Divisor can't be 0.\n\n");//顯示分子不可為0
            else if(n1.den==0||n2.den==0)//若有分母輸入為0
                printf("Denominator can't be 0.\n\n");//顯示分母不可為0
            else{
                n3=divide(n1, n2);//呼叫函式divide進行除法計算
                ggcd=gcd(n3.div, n3.den);//呼叫函式gcd找最大公因數
                if(n3.div%n3.den==0)//若答案為整數
                    printf("%d/%d / %d/%d = %d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div/n3.den);//分子除以分母後印出整數
                else if(gcd(n3.div, n3.den)!=1){//若兩數無互質
                    n3.div/=ggcd;//分子除以最大公因數
                    n3.den/=ggcd;//分母除以最大公因數
                    if(n3.den<0)//若分母為負數
                        printf("%d/%d / %d/%d = %d/%d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div*(-1), n3.den*(-1));//分子分母各*(-1)後印出結果
                    else
                        printf("%d/%d / %d/%d = %d/%d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div, n3.den);//分子分母各除以最大公因數後印出結果
                }
                else
                    printf("%d/%d / %d/%d = %d/%d\n\n", n1.div, n1.den, n2.div, n2.den, n3.div, n3.den);//印出結果
            }
        }
        else if(cho==0)//選擇0(離開)
            return 0;
        printf("1.Add/2.Subtract/3.Multiply/4.Divide/0.Leave:");//提示輸入
        scanf("%d", &cho);//使用者輸入選擇
    }
}
