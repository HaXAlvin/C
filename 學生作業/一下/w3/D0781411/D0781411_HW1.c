#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) //加法
{
	return a+b;
}
int sub(int a, int b) //減法
{
	return a-b;
}
int mult(int a, int b) //乘法
{
	return a*b;
}
int divide(int a, int b) //除法
{
	return a/b;
}
int mod(int a, int b) //取餘數 
{
	return a%b;
}
int main()
{
	int (*func[5])(int,int)={add,sub,mult,divide,mod};
	char symbol[6]={'+','-','*','/','%'};
	int sym=1;
	int a;
	int b;
	printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):");
	while(scanf("%d",&sym)&&sym!=0)
	{
		printf("請輸入兩個整數:");
		scanf("%d %d",&a,&b);
		printf("%d %c %d = %d\n",a,symbol[sym-1],b,func[sym-1](a,b));
		printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):");
	}
	
}














