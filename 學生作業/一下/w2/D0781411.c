#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void add(char **name,int space,int all_space)
{
	char in[200]={0};
	gets(in);
	if(all_space==space)
	{
		name=realloc(name,(all_space)*sizeof(char));  //�X�j
	}

	name[space]=calloc(strlen(in)+1,sizeof(char));//�ھڤj�p
	strcpy(name[space],in);
}

void print(char **name,int space) //��X��
{
	int i;
	for(i=0;i<space;i++)
	{
		printf("%s\n",name[i]);
	}
}

void sort(char **name,int space)
{
	int i;
	int j;
	char *tmp;
	for(i=0;i<space;i++)//�w�j�Ƨ�
	{
		for(j=0;j<space-i-1;j++)
		{
			if(strcmp(name[j],name[j+1])>0)
			{
				tmp= name[j];
				name[j]= name[j+1];
				name[j+1]= tmp;
			}
		}
	}
}

int main()
{
	int i;
	int j;
	char **name;
	int space=0;
	name=malloc(10*sizeof(char));
	int type=0;
	int all_space=10;
	printf("�A�n���ƻ�?(1.�s�W 2.�L�X 3.�Ƨ� 4.���}):");
	while(scanf("%d%*c",&type)&&type!=4)
	{
		if(type==1)
		{
			add(name,space,all_space);
			space++;
			if(all_space<=space)
			{
			    printf("kk\n");
				all_space+=5;
			}
		}
		if(type==2)
		{
			print(name,space);
		}
		if(type==3)
		{
			sort(name,space);
		}
		printf("�A�n���ƻ�?(1.�s�W 2.�L�X 3.�Ƨ� 4.���}):");
	}
	for(i=0;i<space;i++) //���X�N����O����
	{
		free(name[i]);
	}
	free(name);
}
