#include<stdio.h>
#include<stdlib.h>

struct frac
{
    int son;
    int mom;

};//設置一個結構存入之後每一個分數所需要的分母與分子

struct frac neg(struct frac fracAns)
{
    if(fracAns.mom<0)
    {
        fracAns.son*=-1;
        fracAns.mom*=-1;
    }//兩個負號約掉
     return fracAns;
}//處理負號

struct frac gcd(struct frac fracAns)
{
    int a=fracAns.son;
    int b=fracAns.mom;
    int t;
    while(b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }//找最大公因數約分
    fracAns.son/=a;
    fracAns.mom/=a;

    return fracAns;
};

struct frac add(struct frac a,struct frac b)
{
    return neg(gcd( (struct frac){b.mom*a.son+a.mom*b.son ,a.mom*b.mom} ));
}

struct frac sub(struct frac a , struct frac b)
{
    int subson = a.son*b.mom-a.mom*b.son;
    int submom = a.mom*b.mom;//分數減法公式
    struct frac ans;
    ans.son = subson;
    ans.mom = submom;
    ans = gcd(ans);
    ans = neg(ans);
    return ans;
}

struct frac mul(struct frac a , struct frac b)
{
    int mulson = a.son*b.son;
    int mulmom = a.mom*b.mom;//分數乘法公式
    struct frac ans;
    ans.son = mulson;
    ans.mom = mulmom;
    ans = gcd(ans);
    ans = neg(ans);
    return ans;
}



struct frac divi(struct frac a , struct frac b)
{
    int divison = a.son*b.mom;
    int divimom = a.mom*b.son;//分數除法公式
    struct frac ans;
    ans.son = divison;
    ans.mom = divimom;
    ans = gcd(ans);
    ans = neg(ans);
    return ans;
}

int main()
{
    int choose,a,b,c,d;
    char op;
    while(1)
    {
        char ops[] = {'+','-','*','/'};
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
        scanf("%d",&choose);

        if(choose==0)
        {
            return 0;
        }
        else if (choose<0||choose>4)
        {
            printf("輸入錯誤\n");
            continue;
        }//輸入甚麼顯示甚麼符號
        op = ops[choose-1];

        while(1)
        {
            printf("a/b %c c/d , 請輸入a b c d :",op);
            scanf("%d %d %d %d",&a,&b,&c,&d);
            if(choose==4&&(c==0||d==0))
            {
                printf("除數不可為0\n");
            }
            else if(b==0||d==0)
            {
                printf("分母不可為0\n");
            }
            else
            {
                break;
            }//防呆
        }

        struct frac frac1 =
        {
            a,b
        };//設置一個結構存入第一個分數的分母與分子
        struct frac frac2 =
        {
            c,d
        };//設置一個結構存入第二個分數的分母與分子
        struct frac fracAns;//設置一個結構存入第三個分數的分母與分子
        if(choose==1)
        {
            fracAns = add(frac1 , frac2);
        }
        else if(choose==2)
        {
            fracAns = sub(frac1 , frac2);
        }
        else if(choose==3)
        {
            fracAns = mul(frac1 , frac2);
        }
        else if(choose==4)
        {
            fracAns = divi(frac1 , frac2);
        }//輸入甚麼跑哪個函式
         printf("%d/%d %c %d/%d ",a,b,op,c,d);
         if(fracAns.mom==1)
         {
             printf("=%d\n",fracAns.son);
         }//若分母為一,輸入整數
         else
         {
             printf("=%d / %d\n",fracAns.son,fracAns.mom);
         }

    }
}
