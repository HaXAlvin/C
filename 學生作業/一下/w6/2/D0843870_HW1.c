#include<stdio.h>
#include<stdlib.h>
struct stru//datastruct 
{
	union _data 
	{
		int num;
		float flo;
		char str[16];
	}data;
	int type;
	struct stru *data1;
};
void enterdata(struct stru **datainfo,struct stru **current)//輸入資料函式 
{
	char mode;//存資料類型 
	//創建下一個結構並鏈結上一個 
	if(*datainfo == NULL)
	{
		*datainfo = malloc(sizeof(struct stru));
		*current = *datainfo;
	}
	else
	{
		(*current)->data1 = malloc(sizeof(struct stru));
		*current = (*current)->data1;
	}
	while(1)
	{
		printf("選擇類型:(i:int/f:float/s:char[16]):");
		getchar();
		scanf("%c", &mode);
		if(mode!='i'&&mode!='f'&&mode!='s')//防呆 
		{
			printf("輸入錯誤!\n");
			continue;
		}
		printf("輸入資料:");
		if(mode=='i')
		{
			scanf("%d", &((*current)->data.num));
			(*current)->type = 0;
		}
		if(mode=='f')
		{
			scanf("%f", &((*current)->data.flo));
			(*current)->type = 1;
		}
		if(mode=='s')
		{
			scanf("%s", (*current)->data.str);
			(*current)->type = 2;
		}
		break;//運行成功跳出迴圈 
	}
	(*current)->data1 = NULL;//當前結構元素裡的位置設為NULL 
}
void printdata(struct stru *datainfo)//印出資料 
{
	struct stru *tmp;
	tmp = datainfo;
	//印出串列的各筆資料 
	while(tmp!=NULL)
	{
		if(tmp->type == 0)
			printf("%d\n",tmp->data.num);
		if(tmp->type == 1)
			printf("%f\n",tmp->data.flo);
		if(tmp->type == 2)
			printf("%s\n",tmp->data.str);
		tmp = tmp->data1;
	}
}
int main()
{
	struct stru *datainfo = NULL;
	struct stru *current = NULL;
	int mode;//模式,資料數量 
	while(1)
	{
		printf("選擇:(1.新增/2.印出/0.結束):");
		scanf("%d", &mode);
		if(mode==1)//新增 
			enterdata(&datainfo,&current);
		else if(mode==2)//印出 
			printdata(datainfo);
		else if(mode==0)//結束 
		{
			printf("結束程式\n"); 
			return 0;
		}
		else//防呆 
			printf("輸入錯誤!\n");
	}
}
