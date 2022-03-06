#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort(char **a,char **b)
{
	char *tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

int my_strcmp(const char*s1,const char*s2) // A=>65 a=>97    B=>66 b=>98 
{							//大於'Z'-31.5 => A=>65 a=>65.5  B=>66 b=>66.5 用這個方法泡沫排序 
	int i;
	float tmp1;
	float tmp2;
	int s1_len=strlen(s1);
	int re=0;
	for(i=0;i<s1_len;i++)
	{
		tmp1=*(s1+i);
		tmp2=*(s2+i);
		if(tmp1>'Z')
		{
			tmp1-=31.5;
		}
		if(tmp2>'Z')
		{
			tmp2-=31.5;
		}
		if(tmp1>tmp2)
		{
			//printf("%f>%f 要re1\n",tmp1,tmp2);
			re=1;
			break;
		}
		if(tmp1<tmp2)
		{
			//printf("%f<%f 要re-1\n",tmp1,tmp2);
			re=-1;
			break;
		}
	}
	return re;
}

void cmp1(char *item[],int n)
{
	int i;
	int j;
	for(i=0;i<n-1;i++)
	{
		for(j=1;j<n-i-1;j++)
		{
			if(strcmp(item[j],item[j+1])>0)
			{
				sort(&item[j],&item[j+1]);
			}
		}
	}
}

void cmp2(char *item[],int n)
{
	int i;
	int j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(my_strcmp(item[j],item[j+1])>0)
			{
				//printf("%s跟%s互換\n",item[j],item[j+1]);
				sort(&item[j],&item[j+1]);
			}
		}
	}
}

void print(char *item[],int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		printf("%s\n",item[i]);
	}
}

int main()
{
	int i;
	int th;
	char **item;
	int num;
	printf("請輸入字串數(輸入0結束):");
	while(scanf("%d",&num)&&num!=0)
	{
		item=malloc(num*sizeof(int));
		for(i=0;i<num;i++)
		{
			item[i]=calloc(100,sizeof(int));
			scanf("%s",item[i]);
		}
		printf("選擇排序方式(1.以ASCII/2.以字典序)");
		scanf("%d",&th);
		if(th==1)
		{
			cmp1(item,num);
			print(item,num);
		}
		if(th==2)
		{
			cmp2(item,num);
			print(item,num);
		}
		printf("請輸入字串數(輸入0結束):");
	}
} 
