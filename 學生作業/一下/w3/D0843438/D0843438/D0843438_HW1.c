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
        printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}):");
        scanf("%d",&system);
        if (system==0)
            return 0;
        printf("�п�J2�Ӿ��:");
        scanf("%d %d",&a,&b);
        printf("%d %c %d = %d\n",a,sign[system-1],b,function[system-1](a,b));
    }
}
