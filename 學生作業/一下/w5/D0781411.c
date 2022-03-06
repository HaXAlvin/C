#include <stdio.h>
#include <stdlib.h>

typedef struct  list//���c
{
	char type;
	union store
	{
		int i;
		float f;
		char ch[16];
	};
}lis;

void set(struct list *a)//��J
{
	printf("�������(i:int/f:float/s:char[16]):");
	scanf("%c%*c",&a->type);
	if(a->type=='i')
	{
		printf("��J���:");
		scanf("%d",&a->i);
	}
	else if(a->type=='f')
	{
		printf("��J���:");
		scanf("%f",&a->f);
	}
	else if(a->type=='s')
	{
		printf("��J���:");
		scanf("%s",&a->ch);
	}
	else
	{
		printf("��J���~!\n");
	}
}

void print(struct list *a)//��X
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
		printf("���:(1.�s�W2.�L�X0.����):");
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
		else if(act==2)//�L�X
		{
			for(i=0;i<sum;i++)
			{
				print(&li[i]);
			}
		}
		else
		{
			printf("��J���~!\n");
		}
	}
	free(li);
}
