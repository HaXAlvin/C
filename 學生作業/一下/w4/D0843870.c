#include<stdio.h>
//分數結構
typedef struct Div
{
	int fraction;
	int denominator;
}div;
//若分母為負數則通乘-1使其變為正
div isnegative(div output)
{
	if(output.denominator<0)
	{
		output.denominator *= -1;
		output.fraction *= -1;
	}
	return output;
}
//化為最簡分數
div simplest(div output)
{
	int tmp1 = output.fraction;
	int tmp2 = output.denominator;
	int tmp;
	//輾轉相除法
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
//加法 x/y+z/w= (x*w+z*y)/y*w
div sum(div a, div b)
{
	div out;
	a.fraction *= b.denominator;
	b.fraction *= a.denominator;
	out.denominator = a.denominator * b.denominator;//讓分母為a跟b的公倍數
	out.fraction = a.fraction + b.fraction;
	return isnegative(simplest(out));
}
//減法 x/y-z/w= (x*w-z*y)/y*w
div sub(div a, div b)
{
	div out;
	a.fraction *= b.denominator;
	b.fraction *= a.denominator;
	out.denominator = a.denominator * b.denominator;//讓分母為a跟b的公倍數
	out.fraction = a.fraction - b.fraction;
	return isnegative(simplest(out));
}
//乘法 (x/y)*(z/w)=(x*z)/(y*w)
div mult(div a, div b)
{
	div out;
	out.denominator = a.denominator * b.denominator;
	out.fraction = a.fraction * b.fraction;
	return isnegative(simplest(out));
}
//除法 (x/y)/(z/w)=(x*w)/(y*z)
div divis(div a, div b)
{
	div out;
	//將b做倒數再相乘
	out.denominator = a.denominator * b.fraction;
	out.fraction = a.fraction * b.denominator;
	return isnegative(simplest(out));
}
int main()
{
	int mode;//存選擇模式
	div input1, input2, result;//存需計算的值
	div (*method[])(div, div) = {sum, sub, mult, divis};
	char symbol[4] = {'+', '-', '*', '/'};
	while(1)
	{
		printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
		scanf("%d", &mode);
		if(mode==0)
			return 0;//end main
		//防呆
		if(mode!=1&&mode!=2&&mode!=3&&mode!=4&&mode!=0)
		{
			printf("輸入錯誤\n\n");
			continue;
		}
		printf("a/b %c c/d，請輸入a b c d:", symbol[mode - 1]);
		scanf("%d %d %d %d", &input1.fraction, &input1.denominator,&input2.fraction,&input2.denominator);
		//防呆
		if(input2.denominator==0||input1.denominator==0)
		{
			printf("分母不可為0\n\n");
			continue;
		}
		else if(input2.fraction*input2.denominator==0&&mode==4)
		{
			printf("除數不可為0\n\n");
			continue;
		}
		//結果傳回result
		result = method[mode - 1](input1, input2);
		if(result.denominator==1)//分母為1只印出分子 ex:5/1 >> 5
			printf("%d/%d %c %d/%d = %d\n\n",input1.fraction,input1.denominator,symbol[mode-1],input2.fraction,input2.denominator, result.fraction);
		else
			printf("%d/%d %c %d/%d = %d/%d\n\n",input1.fraction,input1.denominator,symbol[mode-1],input2.fraction,input2.denominator, result.fraction, result.denominator);
	}
}
