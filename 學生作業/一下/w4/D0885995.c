#include<stdio.h>
#include<stdlib.h>

struct _fraction{
        //分子//分母
    int mol,den;
}; //分數的結構
typedef struct _fraction  fraction; //將struct _fraction 取名為 fraction

int contract(int a, int b) //約分
{
    if (a<0)
        a=a*(-1);
    if (b<0)
        b=b*(-1);
    while (a>0 && b>0){
        if (a>b)
            a=a%b;
        else
            b=b%a;
    }
    if (a==0)
        return b;
    else
        return a;
}
fraction sign(int a,int b)
{
    fraction ans;
    if (a>0 && b<0){
        ans.mol = a*(-1);
        ans.den = b*(-1);
        return ans;
    }
    else if (a<0 && b<0){
        ans.mol = a*(-1);
        ans.den = b*(-1);
        return ans;
    }
}

fraction add(fraction a, fraction b)//加法
{
    fraction ans; //答案的結構
    ans.den=a.den * b.den; //分母相乘
    ans.mol=(a.mol * b.den) + (a.den * b.mol); //通分後相加
    ans=sign(ans.mol,ans.den); //負號放分子
    int count = contract(ans.mol,ans.den); //約分
    ans.den=ans.den/count; //約分
    ans.mol=ans.mol/count; //約分
    return ans;

}

fraction sub(fraction a, fraction b)//減法
{
    fraction ans; //答案的結構
    ans.den=a.den * b.den; //分母相乘
    ans.mol=(a.mol * b.den) - (a.den * b.mol); //通分後相減
    ans=sign(ans.mol,ans.den); //負號放分子
    int count = contract(ans.mol,ans.den); //約分
    ans.den=ans.den/count; //約分
    ans.mol=ans.mol/count; //約分
    return ans;
}

fraction multi(fraction a, fraction b)//乘法
{
    fraction ans; //答案的結構
    ans.den=a.den * b.den; //分母相乘
    ans.mol=a.mol * b.mol; //分子相乘
    ans=sign(ans.mol,ans.den); //負號放分子
    int count = contract(ans.mol,ans.den); //約分
    ans.den=ans.den/count; //約分
    ans.mol=ans.mol/count; //約分
    return ans;
}

fraction divide(fraction a, fraction b)//除法
{
    fraction ans; //答案的結構
    int temp=b.mol;
    b.mol=b.den;
    b.den=temp;
    ans.den=a.den * b.den; //分母相乘
    ans.mol=a.mol * b.mol; //分子相乘
    ans=sign(ans.mol,ans.den); //負號放分子
    int count = contract(ans.mol,ans.den); //約分
    ans.den=ans.den/count; //約分
    ans.mol=ans.mol/count; //約分
    return ans;
}
int def(int a,int b,int c,int d)
{
    if (b==0 || d==0)
        return 0;
    else if (c==0)
        return 1;
}
int main()
{
    int input;//輸入要做哪個運算
    int num1,num2,num3,num4;//輸入哪兩個數運算
    while (1){
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
        scanf("%d",&input);
        if (input==0)//判斷是否離開
            break;
        else if (input!=1 && input!=2 && input!=3 && input!=4)
            printf("輸入錯誤\n\n");
        fraction first_num;
        fraction second_num;
        fraction ans;
        switch (input)
        {
            case 1://加法
                printf("a/b + c/d，請輸入a b c d:");
                scanf("%d %d %d %d",&num1,&num2,&num3,&num4);
                def(num1,num2,num3,num4);
                if (def(num1,num2,num3,num4)==0){
                    printf("分母不可為0\n\n");
                    break;
                }
                first_num.mol = num1;
                first_num.den = num2;
                second_num.mol = num3;
                second_num.den = num4;
                ans=add(first_num,second_num);
                if (ans.den!=1)
                    printf("%d/%d + %d/%d = %d/%d\n\n",num1,num2,num3,num4,ans.mol,ans.den);
                else
                    printf("%d/%d + %d/%d = %d\n\n",num1,num2,num3,num4,ans.mol);
                break;
            case 2://減法
                printf("a/b - c/d，請輸入a b c d:");
                scanf("%d %d %d %d",&num1,&num2,&num3,&num4);
                if (def(num1,num2,num3,num4)==0){
                    printf("分母不可為0\n\n");
                    break;
                }
                first_num.mol = num1;
                first_num.den = num2;
                second_num.mol = num3;
                second_num.den = num4;
                ans=sub(first_num,second_num);
                if (ans.den!=1)
                  printf("%d/%d - %d/%d = %d/%d\n\n",num1,num2,num3,num4,ans.mol,ans.den);
                else
                    printf("%d/%d - %d/%d = %d\n\n",num1,num2,num3,num4,ans.mol);
                break;
            case 3://乘法
                printf("a/b * c/d，請輸入a b c d:");
                scanf("%d %d %d %d",&num1,&num2,&num3,&num4);
                def(num1,num2,num3,num4);
                if (def(num1,num2,num3,num4)==0){
                    printf("分母不可為0\n\n");
                    break;
                }
                first_num.mol = num1;
                first_num.den = num2;
                second_num.mol = num3;
                second_num.den = num4;
                ans=multi(first_num,second_num);
                if (ans.den!=1)
                    printf("%d/%d * %d/%d = %d/%d\n\n",num1,num2,num3,num4,ans.mol,ans.den);
                else
                    printf("%d/%d * %d/%d = %d\n\n",num1,num2,num3,num4,ans.mol);
                break;
            case 4://除法
                printf("a/b / c/d，請輸入a b c d:");
                scanf("%d %d %d %d",&num1,&num2,&num3,&num4);
                def(num1,num2,num3,num4);
                if (def(num1,num2,num3,num4)==0){
                    printf("分母不可為0\n\n");
                    break;
                }
                else if (def(num1,num2,num3,num4)==1){
                    printf("除數不可為0\n\n");
                    break;
                }
                first_num.mol = num1;
                first_num.den = num2;
                second_num.mol = num3;
                second_num.den = num4;
                ans=divide(first_num,second_num);
                if (ans.den!=1)
                    printf("%d/%d / %d/%d = %d/%d\n\n",num1,num2,num3,num4,ans.mol,ans.den);
                else
                    printf("%d/%d / %d/%d = %d\n\n",num1,num2,num3,num4,ans.mol);
                break;
        }
    }
}
