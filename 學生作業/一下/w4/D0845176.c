#include <stdio.h>
#include<stdlib.h>
int _gcd(int num1,int num2)//找出最大公因數
{
    while(num2!=0)
    {
        int tmp =num1%num2;
        num1=num2;
        num2=tmp;
    }
    return num1;
}

typedef struct div{
    int m,n;//分數的分子跟分母
}fra;//另成一個形態
fra reduce(fra k,int gcd)//約分 且回傳型態為fra
{
    k.m = (k.m/gcd);
    k.n = (k.n/gcd);
    return k;
}
int main()
{
    int opt,gcd;//選項,最大公因數
    
    fra i,j,k;//ㄑ型態為裡面有兩個分數
    printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
    while(scanf("%d",&opt)!=EOF)
    {
        if(opt==1)//加法
        {
            printf("a/b + c/d 請輸入a b c d :");
            scanf("%d %d %d %d",&i.m,&i.n,&j.m,&j.n);
            if(i.n==0 || j.n==0)
            {
                printf("分母不可為0\n");
            }
            else
            {
                printf("%d/%d - %d/%d = ",i.m,i.n,j.m,j.n);
                k.m=(i.m * j.n)+(j.m * i.n);
                k.n=(i.n*j.n);
                gcd = _gcd(k.m,k.n);
                k=reduce(k,gcd);
                if(k.n<0)//分號放在分子
                {
                    k.m *=-1;
                    k.n *=-1;
                }
                if(k.m%k.n == 0)
                    printf("%d\n",k.m/k.n);
                else
                    printf("%d/%d\n",k.m,k.n);
            }        }
        else if(opt==2)//減法
        {
            printf("a/b - c/d 請輸入a b c d :");
            scanf("%d %d %d %d",&i.m,&i.n,&j.m,&j.n);
            if(i.n==0 || j.n==0)
            {
                printf("分母不可為0\n");
            }
            else
            {
                printf("%d/%d - %d/%d = ",i.m,i.n,j.m,j.n);
                k.m=(i.m*j.n)-(j.m*i.n);
                k.n=(i.n*j.n);
                gcd = _gcd(k.m,k.n);
                k=reduce(k,gcd);
                if(k.n<0)
                {
                    k.m *=-1;
                    k.n *=-1;
                }
                if(k.m%k.n == 0)
                    printf("%d\n",k.m/k.n);
                else
                    printf("%d/%d\n",k.m,k.n);
                
            }
        }
        else if(opt==3)//乘法
        {
            printf("a/b * c/d 請輸入a b c d :");
            scanf("%d %d %d %d",&i.m,&i.n,&j.m,&j.n);
            if(i.n==0 || j.n==0)
            {
                printf("分母不可為0\n");
            }
            
            else
            {
                printf("%d/%d - %d/%d = ",i.m,i.n,j.m,j.n);
                k.m=i.m*j.m;
                k.n=i.n*j.n;
                gcd = _gcd(k.m,k.n);
                k=reduce(k,gcd);
                if(k.n<0)
                {
                    k.m *=-1;
                    k.n *=-1;
                }
                if(k.m%k.n == 0)
                    printf("%d\n",k.m/k.n);
                else
                    printf("%d/%d\n",k.m,k.n);
            }
            
        }
        else if(opt==4)//除法
        {
            printf("a/b / c/d 請輸入a b c d :");
            scanf("%d %d %d %d",&i.m,&i.n,&j.m,&j.n);
            if(i.n==0 || j.n==0)
            {
                printf("分母不可為0\n");
            }
            else if(j.m==0)
            {
                printf("除數不可為0\n");
            }
            else
            {
                printf("%d/%d - %d/%d = ",i.m,i.n,j.m,j.n);
                k.m=i.m*j.n;
                k.n=i.n*j.m;
                gcd = _gcd(k.m,k.n);
                k=reduce(k,gcd);
                if(k.n<0)
                {
                    k.m *=-1;
                    k.n *=-1;
                }
                if(k.m%k.n == 0)
                    printf("%d\n",k.m/k.n);
                else
                    printf("%d/%d\n",k.m,k.n);
                
            }
            
        }
        else if(opt==0)//離開
        {
            printf("\n");
            return 0;
        }
        else
            printf("輸入錯誤\n");
        printf("\n");
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
    }
    return 0;
}
