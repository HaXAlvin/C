#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) //�[�k
{
	return a+b;
}
int sub(int a, int b) //��k
{
	return a-b;
}
int mult(int a, int b) //���k
{
	return a*b;
}
int divide(int a, int b) //���k
{
	return a/b;
}
int mod(int a, int b) //���l�� 
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
	printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}):");
	while(scanf("%d",&sym)&&sym!=0)
	{
		printf("�п�J��Ӿ��:");
		scanf("%d %d",&a,&b);
		printf("%d %c %d = %d\n",a,symbol[sym-1],b,func[sym-1](a,b));
		printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}):");
	}
	
}














