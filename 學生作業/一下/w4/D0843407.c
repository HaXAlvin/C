#include<stdio.h>

typedef struct fraction{//宣告結構
    int numerator,denominator;
}BOX;

//加
BOX addition(BOX A,BOX B){
    int temp_numerator,temp_denominator;
    temp_numerator=A.numerator * B.denominator+B.numerator * A.denominator;
    temp_denominator=B.denominator * A.denominator;
    A.numerator=temp_numerator;
    A.denominator=temp_denominator;
    return A;
}
//減
BOX subtraction(BOX A,BOX B){
    int temp_numerator,temp_denominator;
    temp_numerator=A.numerator * B.denominator-B.numerator * A.denominator;
    temp_denominator=B.denominator * A.denominator;
    A.numerator=temp_numerator;
    A.denominator=temp_denominator;
    return A;
}
//乘
BOX multiplication(BOX A,BOX B){
    int temp_numerator,temp_denominator;
    temp_numerator=A.numerator * B.numerator;
    temp_denominator=B.denominator * A.denominator;
    A.numerator=temp_numerator;
    A.denominator=temp_denominator;
    return A;
}
//除
BOX division(BOX A,BOX B){
    int temp_numerator,temp_denominator;
    temp_numerator=A.numerator * B.denominator;
    temp_denominator=B.numerator * A.denominator;
    if(temp_denominator<0){//防分母<0
            temp_denominator*=-1;
            temp_numerator*=-1;
        }
    A.numerator=temp_numerator;
    A.denominator=temp_denominator;
    return A;
}

//求最大公因數
int GCD(BOX A){
    int temp;
    if(A.denominator>A.numerator){
        temp=A.denominator;
        A.denominator=A.numerator;
        A.numerator=temp;
    }
    while ( A.numerator % A.denominator != 0 ){
        temp = A.numerator % A.denominator;
        A.numerator = A.denominator;
        A.denominator = temp;
     }
    return A.denominator;
}

int main(){
    //宣告
    int input,a,b,c,d;
    char symbol[4]={'+','-','*','/'};
    while(1){
        //讀取
        printf("選擇（1.加/2.減/3.乘/4.除/0.離開）：");
        scanf("%d",&input);
        //讀取
        if(input==0){//離開
            return 0;
        }

        //防呆
        else if(input<0||input>4){
            printf("輸入錯誤\n");
            continue;
        }
        //防呆
        //讀取
        printf("a/b %c c/d，請輸入a b c d：",symbol[input-1]);
        scanf("%d %d %d %d",&a,&b,&c,&d);
        //讀取
        //防呆
        if(input==4&&c==0&&(b==0||d==0)){
            printf("分母不能為0\n");
            printf("除數不能為0\n");
            continue;
        }
        else if(b==0||d==0){
            printf("分母不能為0\n");
            continue;
        }
        else if(input==4&&c==0){
            printf("除數不能為0\n");
            continue;
        }
        //防呆
        //讓分母無-號
        if(b<0){
            b*=-1;
            a*=-1;
        }
        if(d<0){
            d*=-1;
            c*=-1;
        }
        //讓分母無-號
        //輸入結構
        BOX frist= {
            a,b
        };
        BOX last= {
            c,d
        };
        //運算
        if(input==1){
            frist = addition(frist,last);
        }
        else if(input==2){
            frist = subtraction(frist,last);
        }
        else if(input==3){
            frist = multiplication(frist,last);
        }
        else if(input==4){
            frist = division(frist,last);
        }
        //化簡
        if(frist.numerator!=0){
            int gcd = GCD (frist);
            frist.numerator/=gcd;
            frist.denominator/=gcd;
        }
        // 防止分母為-
        if(frist.denominator<0){
            frist.numerator*=-1;
            frist.denominator*=-1;
        }
        printf("%d/%d %c %d/%d = %d/%d\n",a,b,symbol[input-1],c,d,frist.numerator,frist.denominator);
    }

}
