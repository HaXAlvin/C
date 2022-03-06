#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void add(char **name,int space,int all_space)
{
	char in[200]={0};
	gets(in);
	if(all_space==space)
	{
		name=realloc(name,(all_space)*sizeof(char));  //擴大
	}

	name[space]=calloc(strlen(in)+1,sizeof(char));//根據大小
	strcpy(name[space],in);
}

void print(char **name,int space) //丟出來
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
	for(i=0;i<space;i++)//泡沫排序
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
	printf("你要做甚麼?(1.新增 2.印出 3.排序 4.離開):");
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
		printf("你要做甚麼?(1.新增 2.印出 3.排序 4.離開):");
	}
	for(i=0;i<space;i++) //跳出就釋放記憶體
	{
		free(name[i]);
	}
	free(name);
}
