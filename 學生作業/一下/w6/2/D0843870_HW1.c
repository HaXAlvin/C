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
void enterdata(struct stru **datainfo,struct stru **current)//��J��ƨ禡 
{
	char mode;//�s������� 
	//�ЫؤU�@�ӵ��c���쵲�W�@�� 
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
		break;//�B�榨�\���X�j�� 
	}
	(*current)->data1 = NULL;//��e���c�����̪���m�]��NULL 
}
void printdata(struct stru *datainfo)//�L�X��� 
{
	struct stru *tmp;
	tmp = datainfo;
	//�L�X��C���U����� 
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
	int mode;//�Ҧ�,��Ƽƶq 
	while(1)
	{
		printf("���:(1.�s�W/2.�L�X/0.����):");
		scanf("%d", &mode);
		if(mode==1)//�s�W 
			enterdata(&datainfo,&current);
		else if(mode==2)//�L�X 
			printdata(datainfo);
		else if(mode==0)//���� 
		{
			printf("�����{��\n"); 
			return 0;
		}
		else//���b 
			printf("��J���~!\n");
	}
}
