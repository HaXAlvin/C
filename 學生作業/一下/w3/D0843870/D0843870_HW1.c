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
	char symbol[5] = {'+', '-', '*', '/', '%'};//�ŧi��B��Ÿ����}�C
	while(1)
	{
		printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}):");
		scanf("%d", &mode);//�Ҧ�
		if(mode==0)
			return 0;
		printf("�п�J2�Ӿ��:");
		scanf("%d %d", &num1, &num2);//Ū��2�Ӿ��
		printf("%d %c %d = %d\n", num1, symbol[mode - 1], num2, opt[mode - 1](num1, num2));//�ھڼҦ���X�������⦡
	}
}
