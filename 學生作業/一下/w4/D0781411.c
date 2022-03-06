#include <stdio.h>
struct num
{
	int son;//分子
	int mom;//分母
};
struct num reduction(struct num a)
{
	if((a.son<0&&a.mom<0)||(a.son>0&&a.mom<0)) //處理負號
	{
		a.son*=-1;
		a.mom*=-1;
	}
	return a;
}
int gcd_func(int a,int b)	//最大公因數
{
    if(b==0)
    {
        return a;
    }
    return gcd_func(b,a%b);
}
struct num add(struct num a,struct num b)
{
	struct num ans;
	int lcm=a.mom*b.mom;//最小公倍數
	a.son*=b.mom;
	b.son*=a.mom;
	a.son+=b.son;
	int gcd=gcd_func(a.son,lcm);
	a.son/=gcd;
	lcm/=gcd;
	a.mom=lcm;
	return reduction(a);
}
struct num sub(struct num a,struct num b)
{
	b.son*=-1;
	return reduction(add(a,b));
}
struct num mult(struct num a,struct num b)
{
	int gcd; //最大公因數
	a.son=a.son*b.son;
	a.mom=a.mom*b.mom;	//相乘結束
	gcd=gcd_func(a.son,a.mom);
	a.son/=gcd;
	a.mom/=gcd; //約分
	return reduction(a);
}
struct num divide(struct num a,struct num b)
{
	int tmp;
	tmp=b.son;
	b.son=b.mom;
	b.mom=tmp;
	return reduction(mult(a,b));
}
int main()
{
	struct num (*func[5]) (struct num,struct num)={add,sub,mult,divide};
	struct num left;
	struct num right;
	struct num ans;
	char symbol[5]={'+','-','*','/'};
	int sym;
	int i;
	while(1)
	{
		printf("選擇(1.加/2.減/3.乘/4.除/0離開):");
		if(scanf("%d",&sym)&&sym==0)
		{
			break;
		}
		if(sym>4||sym<0)
		{
			printf("輸入錯誤\n\n");
			continue;
		}
		printf("a/b %c c/d，請輸入a b c d:",symbol[sym-1]);
		scanf("%d %d",&left.son,&left.mom);
		scanf("%d %d",&right.son,&right.mom);
		if(left.mom==0||right.mom==0)
		{
			printf("分母不可為0\n\n");
		}
		else if(sym==4&&right.son==0)
		{
			printf("除數不可為0\n\n");
		}
		else if(right.mom!=0&&left.mom!=0)
		{
			ans = func[sym-1](left,right);
			printf("%d/%d %c %d/%d = ",left.son,left.mom,symbol[sym-1],right.son,right.mom);
			if(ans.mom!=1)   //分母是不是1
			{
				printf("%d/%d\n\n",ans.son,ans.mom);
			}
			else
			{
				printf("%d\n\n",ans.son);
			}
		}
	}
}
