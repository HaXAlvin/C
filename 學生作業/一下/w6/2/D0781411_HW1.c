#include <stdio.h>
#include <stdlib.h>
typedef struct tmp   //結構
{
	char type;       //類型
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
	TmpPtr newPtr = malloc(sizeof(Tmp));//開一個新的
	newPtr->nextPtr = NULL;//剛開始是空的
	TmpPtr Temp;//之後會用到的tmp
	printf("選擇類型(i:int/f:float/s:char[16]):");
	while(scanf("%c%*c",&newPtr->type)&&(newPtr->type!='i'&&newPtr->type!='f'&&newPtr->type!='s'))//輸入錯誤的迴圈~  這裡開始是輸入
	{
		printf("輸入錯誤!\n");
		printf("選擇類型(i:int/f:float/s:char[16]):");
	}
	printf("輸入資料:");
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
	}//輸入結束
	if(*head == NULL)
	{
        *head = newPtr;//如果是空的就接上去
    }
    else	//如果不是空的
	{
        TmpPtr Temp = *head;// 接上head
        while(Temp->nextPtr != NULL)//如果有接東西的話就往下找直到沒有東西
        {
            Temp = Temp->nextPtr;
        }
        Temp->nextPtr = newPtr;
    }
}
void print(TmpPtr head) //把它全部丟出來
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
		head = head->nextPtr;//往下找
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
	printf("選擇:(1.新增2.印出0.結束):");
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
			printf("輸入錯誤!\n");
		}
		printf("選擇:(1.新增2.印出0.結束):");
	}
	free_list(&head);
	printf("結束程式\n");
}
