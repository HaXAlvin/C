#include<stdio.h>
int add(int a, int b) //a+b
{
	return a + b;
}
int sub(int a, int b)//a-b
{
	return a - b;
}
int multi(int a, int b)//a*b
{
	return a * b;
}
int divide(int a, int b)//a/b
{
	return a / b;
}
int mod(int a, int b)//a%b
{
	return a % b;
}
int main()
{
	int mode,num1,num2;
	int (*opt[])(int, int) = {add, sub, multi, divide, mod};
	char symbol[5] = {'+', '-', '*', '/', '%'};//宣告放運算符號的陣列
	while(1)
	{
		printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):");
		scanf("%d", &mode);//模式
		if(mode==0)
			return 0;
		printf("請輸入2個整數:");
		scanf("%d %d", &num1, &num2);//讀取2個整數
		printf("%d %c %d = %d\n", num1, symbol[mode - 1], num2, opt[mode - 1](num1, num2));//根據模式輸出對應的算式
	}
}
