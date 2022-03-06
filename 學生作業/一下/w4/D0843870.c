#include<stdio.h>
//���Ƶ��c
typedef struct Div
{
	int fraction;
	int denominator;
}div;
//�Y�������t�ƫh�q��-1�Ϩ��ܬ���
div isnegative(div output)
{
	if(output.denominator<0)
	{
		output.denominator *= -1;
		output.fraction *= -1;
	}
	return output;
}
//�Ƭ���²����
div simplest(div output)
{
	int tmp1 = output.fraction;
	int tmp2 = output.denominator;
	int tmp;
	//����۰��k
	while(1)
	{
		tmp = tmp1 % tmp2;
		if(tmp==0)
			break;
		tmp1 = tmp2;
		tmp2 = tmp;
	}
	output.fraction /= tmp2;
	output.denominator /= tmp2;
	return output;
}
//�[�k x/y+z/w= (x*w+z*y)/y*w
div sum(div a, div b)
{
	div out;
	a.fraction *= b.denominator;
	b.fraction *= a.denominator;
	out.denominator = a.denominator * b.denominator;//��������a��b��������
	out.fraction = a.fraction + b.fraction;
	return isnegative(simplest(out));
}
//��k x/y-z/w= (x*w-z*y)/y*w
div sub(div a, div b)
{
	div out;
	a.fraction *= b.denominator;
	b.fraction *= a.denominator;
	out.denominator = a.denominator * b.denominator;//��������a��b��������
	out.fraction = a.fraction - b.fraction;
	return isnegative(simplest(out));
}
//���k (x/y)*(z/w)=(x*z)/(y*w)
div mult(div a, div b)
{
	div out;
	out.denominator = a.denominator * b.denominator;
	out.fraction = a.fraction * b.fraction;
	return isnegative(simplest(out));
}
//���k (x/y)/(z/w)=(x*w)/(y*z)
div divis(div a, div b)
{
	div out;
	//�Nb���˼ƦA�ۭ�
	out.denominator = a.denominator * b.fraction;
	out.fraction = a.fraction * b.denominator;
	return isnegative(simplest(out));
}
int main()
{
	int mode;//�s��ܼҦ�
	div input1, input2, result;//�s�ݭp�⪺��
	div (*method[])(div, div) = {sum, sub, mult, divis};
	char symbol[4] = {'+', '-', '*', '/'};
	while(1)
	{
		printf("���(1.�[/2.��/3.��/4.��/0.���}):");
		scanf("%d", &mode);
		if(mode==0)
			return 0;//end main
		//���b
		if(mode!=1&&mode!=2&&mode!=3&&mode!=4&&mode!=0)
		{
			printf("��J���~\n\n");
			continue;
		}
		printf("a/b %c c/d�A�п�Ja b c d:", symbol[mode - 1]);
		scanf("%d %d %d %d", &input1.fraction, &input1.denominator,&input2.fraction,&input2.denominator);
		//���b
		if(input2.denominator==0||input1.denominator==0)
		{
			printf("�������i��0\n\n");
			continue;
		}
		else if(input2.fraction*input2.denominator==0&&mode==4)
		{
			printf("���Ƥ��i��0\n\n");
			continue;
		}
		//���G�Ǧ^result
		result = method[mode - 1](input1, input2);
		if(result.denominator==1)//������1�u�L�X���l ex:5/1 >> 5
			printf("%d/%d %c %d/%d = %d\n\n",input1.fraction,input1.denominator,symbol[mode-1],input2.fraction,input2.denominator, result.fraction);
		else
			printf("%d/%d %c %d/%d = %d/%d\n\n",input1.fraction,input1.denominator,symbol[mode-1],input2.fraction,input2.denominator, result.fraction, result.denominator);
	}
}
