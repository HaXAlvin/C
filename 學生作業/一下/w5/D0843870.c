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
void enterdata(stru *datainfo, int num)//��J��ƨ禡 
{
	char mode;//�s������� 
	while(1)
	{
		printf("�������:(i:int/f:float/s:char[16]):");
		getchar();
		scanf("%c", &mode);
		if(mode!='i'&&mode!='f'&&mode!='s')//���b 
		{
			printf("��J���~!\n");
			continue;
		}
		printf("��J���:");
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
		break;//�B�榨�\���X�j�� 
	}
}
void printdata(stru *datainfo,int num)//�L�X��� 
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
	int mode,num=0;//�Ҧ�,��Ƽƶq 
	while(1)
	{
		printf("���:(1.�s�W/2.�L�X/0.����):");
		scanf("%d", &mode);
		if(mode==1)//�s�W 
		{
			if(num==0)//��Ƽƶq��0��malloc�t�m��l�Ŷ� 
				datainfo = (stru *)malloc(sizeof(stru));
			else//�_�h��realloc���s�t�m 
				datainfo=(stru*)realloc(datainfo, (num + 1) * sizeof(stru));
			enterdata(datainfo+num, num);
		}
		else if(mode==2)//�L�X 
			printdata(datainfo, num);
		else if(mode==0)//���� 
		{
			printf("�����{��\n"); 
			return 0;
		}
			
		else//���b 
			printf("��J���~!\n");
		++num;//��Ƽƶq+1 
	}
}
