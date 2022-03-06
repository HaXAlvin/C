#include<stdio.h>
#include<stdlib.h>
int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int multi(int a,int b)
{
	return a*b;
}
int divide(int a,int b)
{
	return a/b;
}
int mod(int a,int b)
{
	return a%b;
}
int main ()
{
    while(1)
    {
        int system,a,b;
        int (*function[])(int,int)={add,sub,multi,divide,mod};
        char sign[]={'+','-','*','/','%'};
        printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):");
        scanf("%d",&system);
        if (system==0)
            return 0;
        printf("請輸入2個整數:");
        scanf("%d %d",&a,&b);
        printf("%d %c %d = %d\n",a,sign[system-1],b,function[system-1](a,b));
    }
}
