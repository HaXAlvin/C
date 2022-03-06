#include<stdio.h>
#include<stdlib.h>
typedef struct _struct//datastruct 
{
	union _data 
	{
		int num;
		float flo;
		char str[16];
	}data;
	int type;
}stru;
void enterdata(stru *datainfo, int num)//輸入資料函式 
{
	char mode;//存資料類型 
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
			scanf("%d", &datainfo->data.num);
			datainfo->type = 0;
		}
		if(mode=='f')
		{
			scanf("%f", &datainfo->data.flo);
			datainfo->type = 1;
		}
		if(mode=='s')
		{
			scanf("%s", datainfo->data.str);
			datainfo->type = 2;
		}
		break;//運行成功跳出迴圈 
	}
}
void printdata(stru *datainfo,int num)//印出資料 
{
	int i;
	for (i = 0; i < num;i++)
	{
		if(datainfo[i].type==0)
			printf("%d\n", datainfo[i].data.num);
		else if(datainfo[i].type==1)
			printf("%f\n", datainfo[i].data.flo);
		else if(datainfo[i].type==2)
			printf("%s\n", datainfo[i].data.str);
	}
}
int main()
{
	stru *datainfo;
	int mode,num=0;//模式,資料數量 
	while(1)
	{
		printf("選擇:(1.新增/2.印出/0.結束):");
		scanf("%d", &mode);
		if(mode==1)//新增 
		{
			if(num==0)//資料數量為0用malloc配置初始空間 
				datainfo = (stru *)malloc(sizeof(stru));
			else//否則用realloc重新配置 
				datainfo=(stru*)realloc(datainfo, (num + 1) * sizeof(stru));
			enterdata(datainfo+num, num);
		}
		else if(mode==2)//印出 
			printdata(datainfo, num);
		else if(mode==0)//結束 
		{
			printf("結束程式\n"); 
			return 0;
		}
			
		else//防呆 
			printf("輸入錯誤!\n");
		++num;//資料數量+1 
	}
}
