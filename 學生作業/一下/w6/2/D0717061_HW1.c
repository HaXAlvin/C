/*  109年度  資訊二丁
        第一週作業    */
#include<stdio.h>//標頭檔
#include<stdlib.h>
typedef struct node* NodePtr;//定義Node是struct node
typedef struct node//定義node結構
{
    union arr//定義聯合結構
    {
        int num;//整數
        float Num;//單精度浮點數
        char word[16];//字元陣列
    } Arr;
    char t;//用來儲存資料型態
    NodePtr nextPtr;
} Node;

void addNode(NodePtr* ptr)//鏈結串列之副程式
{
    char ty;
    NodePtr newPtr = malloc(sizeof(Node));//動態配置Node
    newPtr->nextPtr = NULL;//預設為NULL
    while(1)
    {
        printf("選擇類型：(i：int/f：float/s：char[16])：");
        scanf("%c",&ty);//選擇型態
        getchar();
        if(ty=='i')//選擇int
        {
            printf("輸入資料：");
            scanf("%d", &(newPtr->Arr).num);//輸入資料
            newPtr->t=ty;//儲存型態
            break;//跳出迴圈
        }
        if(ty=='f')//選擇float
        {
            printf("輸入資料：");
            scanf("%f", &(newPtr->Arr).Num);//輸入資料
            newPtr->t=ty;//儲存型態
            break;//跳出迴圈
        }

        if(ty=='s')//選擇char
        {
            printf("輸入資料：");
            gets((newPtr->Arr).word);//輸入資料
            newPtr->t=ty;//儲存型態
            break;//跳出迴圈
        }
        if(!(ty=='i'||ty=='s'||ty=='f'))//輸入i、f、s以外
            printf("輸入錯誤！\n");
    }
    if(*ptr == NULL)//如果為NULL
        *ptr = newPtr;
    else
    {
        NodePtr tempPtr = *ptr;
        while(tempPtr->nextPtr != NULL)//不為NULL迴圈
            tempPtr = tempPtr->nextPtr;//遞移
        tempPtr->nextPtr = newPtr;//指派到新的node
    }
}

void print(NodePtr node)//印出之副程式
{
    while(node)
    {
        if(node->t=='i')//如果型態為int
        {
            printf("%d ", (node->Arr).num);//印出(node->Arr).num
            node = node->nextPtr;//將node指向原本的node->nextPtr
            printf("\n");
        }

        else if(node->t=='f')//如果型態為floar
        {
            printf("%f", (node->Arr).Num);//印出(node->Arr).Num
            node = node->nextPtr;//將node指向原本的node->nextPtr
            printf("\n");
        }
        else if(node->t=='s')//如果型態為char
        {
            puts((node->Arr).word);//印出(node->Arr).word
            node = node->nextPtr;//將node指向原本的node->nextPtr
        }

    }
}
void freeList(NodePtr* ptr) //釋放記憶體
{
    while(*ptr != NULL)
    {
        NodePtr temp = *ptr;//將*ptr記錄到temp
        *ptr = (*ptr)->nextPtr;//*ptr為資料
        free(temp);//釋放記憶體
    }
}
int main()//主程式
{
    NodePtr head = NULL;
    int n=0,sum=0;//選告變數
    while(1)
    {
        printf("選擇：(1.新增/2.印出/0.結束)：");
        scanf("%d",&n);
        if(n==1)//選擇新增
        {
            getchar();
            addNode(&head);
        }
        if(n==2)//選擇印出
        {
            print(head);
        }
        if(n<0||n>2)//輸入0、1、2以外
            printf("輸入錯誤！\n");
        if(n==0)//選擇結束
        {
            freeList(&head);
            printf("結束程式");
            return 0;//回傳，並結束程式
        }

    }

}
