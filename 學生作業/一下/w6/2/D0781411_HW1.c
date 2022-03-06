#include <stdio.h>
#include <stdlib.h>
typedef struct tmp   //���c
{
	char type;       //����
	union
	{
		int i;
		double f;
		char s[16];
	};
	struct tmp* nextPtr;
}Tmp;

typedef struct tmp* TmpPtr;

void add(TmpPtr *head)
{
	TmpPtr newPtr = malloc(sizeof(Tmp));//�}�@�ӷs��
	newPtr->nextPtr = NULL;//��}�l�O�Ū�
	TmpPtr Temp;//����|�Ψ쪺tmp
	printf("�������(i:int/f:float/s:char[16]):");
	while(scanf("%c%*c",&newPtr->type)&&(newPtr->type!='i'&&newPtr->type!='f'&&newPtr->type!='s'))//��J���~���j��~  �o�̶}�l�O��J
	{
		printf("��J���~!\n");
		printf("�������(i:int/f:float/s:char[16]):");
	}
	printf("��J���:");
	if(newPtr->type=='i')
	{
		scanf("%d",&newPtr->i);
	}
	else if(newPtr->type=='f')
	{
		scanf("%lf",&newPtr->f);
	}
	else if(newPtr->type=='s')
	{
		scanf("%s",newPtr->s);
	}//��J����
	if(*head == NULL)
	{
        *head = newPtr;//�p�G�O�Ū��N���W�h
    }
    else	//�p�G���O�Ū�
	{
        TmpPtr Temp = *head;// ���Whead
        while(Temp->nextPtr != NULL)//�p�G�����F�誺�ܴN���U�䪽��S���F��
        {
            Temp = Temp->nextPtr;
        }
        Temp->nextPtr = newPtr;
    }
}
void print(TmpPtr head) //�⥦������X��
{
	while(head!=NULL)
	{
		if(head->type=='i')
		{
			printf("%d\n",head->i);
		}
		else if(head->type=='f')
		{
			printf("%lf\n",head->f);
		}
		else if(head->type=='s')
		{
			printf("%s\n",head->s);
		}
		head = head->nextPtr;//���U��
	}
}
void free_list(TmpPtr *head)
{
	TmpPtr Temp;
	while(*head != NULL)
	{
        Temp = *head;
        *head = (*head)->nextPtr;
        free(Temp);
    }
}
int main()
{
	TmpPtr head=NULL;
	int type;
	printf("���:(1.�s�W2.�L�X0.����):");
	while(scanf("%d%*c",&type)&&type!=0)
	{
		if(type==1)
		{
			add(&head);
		}
		else if(type==2)
		{
			print(head);
		}
		else
		{
			printf("��J���~!\n");
		}
		printf("���:(1.�s�W2.�L�X0.����):");
	}
	free_list(&head);
	printf("�����{��\n");
}
