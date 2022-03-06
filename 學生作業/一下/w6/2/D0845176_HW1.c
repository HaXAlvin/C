#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef union
{
    int in;
    float fl;
    char ch[16];
}B;
typedef struct node* NodePtr;
typedef struct node{
    B c;
    //int opt2;
    NodePtr nextPtr;
}Node;
void print(NodePtr node,int arr[])
{
    int i=0;
    while(node)
    {
        if(arr[i]==1)
            printf("%d\n",node->c.in);
        else if(arr[i]==2)
            printf("%f\n",node->c.fl);
        else if(arr[i]==3)
            printf("%s\n",node->c.ch);
        i++;
        node = node->nextPtr;
    }
}
int add(NodePtr* ptr,int arr[])//新增資料
{
    int i=0;
    NodePtr newPtr = malloc(sizeof(Node));
    newPtr->nextPtr = NULL;
    int opt2;
    printf("選擇類型：(1.int/2.float/3.char[16]):");
    scanf("%d",&opt2);
    getchar();
    if(opt2!=1 && opt2!=2 && opt2!=3)
    {
        printf("輸入錯誤！\n");
        return 0;
    }
    printf("輸入資料：");
    switch(opt2)
    {
        case 1:
            scanf("%d",&(newPtr->c.in));
            arr[i]=1;
            i++;
            if(*ptr == NULL)
                *ptr = newPtr;
            break;
        case 2:
            scanf("%f",&(newPtr->c.fl));
            arr[i]=2;
            i++;
            break;
        case 3:
            scanf("%s",&(newPtr->c.ch));
            arr[i]=3;
            i++;
            break;
    }
    return 1;
}

void fre(NodePtr* ptr)
{
    while(*ptr != NULL)
    {
        NodePtr temp = *ptr;
        *ptr = (*ptr)->nextPtr;
        free(temp);
    }
    printf("結束程式\n");
}
int main()
{
    NodePtr head = NULL;
    int arr[100];
    while(1)
    {
        int opt1;//選擇功能
        printf("選擇:(1.新增/2.印出/0.結束):");
        scanf("%d",&opt1);
        getchar();
        if(opt1<0||opt1/3)
        {
            printf("輸入錯誤!\n");
            continue;
        }
        if(opt1==0)
        {
            if(head!=NULL)
                fre(&head);
            printf("結束程式\n");
            break;
        }
        switch(opt1)
        {
            case 1: //新增
                add(&head,arr);
                break;
            case 2: //印出
                print(head,arr);
                break;
        }
    }
    return 0;
}
