#include <stdio.h>
#include <stdlib.h>

typedef struct  list//結構
{
	char type;
	union store
	{
		int i;
		float f;
		char ch[16];
	};
}lis;

void set(struct list *a)//輸入
{
	printf("選擇類型(i:int/f:float/s:char[16]):");
	scanf("%c%*c",&a->type);
	if(a->type=='i')
	{
		printf("輸入資料:");
		scanf("%d",&a->i);
	}
	else if(a->type=='f')
	{
		printf("輸入資料:");
		scanf("%f",&a->f);
	}
	else if(a->type=='s')
	{
		printf("輸入資料:");
		scanf("%s",&a->ch);
	}
	else
	{
		printf("輸入錯誤!\n");
	}
}

void print(struct list *a)//輸出
{
	if(a->type=='i')
	{
		printf("%d\n",a->i);
	}
	if(a->type=='f')
	{
		printf("%f\n",a->f);
	}
	if(a->type=='s')
	{
		printf("%s\n",a->ch);
	}
}
int main()
{
	lis *li =malloc(0);
	int sum=0;
	int act;
	int i;
	while(1)
	{
		printf("選擇:(1.新增2.印出0.結束):");
		scanf("%d%*c",&act);
		if(act==0)
		{
			break;
		}
		else if(act==1)
		{
			sum++;

            li = realloc(li,sum * (sizeof(struct list)));

			set(&li[sum-1]);
		}
		else if(act==2)//印出
		{
			for(i=0;i<sum;i++)
			{
				print(&li[i]);
			}
		}
		else
		{
			printf("輸入錯誤!\n");
		}
	}
	free(li);
}
