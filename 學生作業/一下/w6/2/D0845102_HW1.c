#include <stdio.h>
#include <stdlib.h>
typedef struct node* NodePtr;
typedef struct node//定義struct
{
    int type;//儲存型態
    int value;//int型態
    float number;//float型態
    char text[16];//char型態
    NodePtr nextPtr;
} Node;
void addNote_i(NodePtr* ptr)//int型態輸入器
{

    NodePtr newPtr = malloc(sizeof(Node));//
    newPtr->nextPtr= NULL;
    printf("Please input number:");
    scanf("%d", &newPtr->value);
    newPtr->type=1;//定義型態

    if(*ptr==NULL)
    {
        *ptr=newPtr;
    }
    else
    {

        NodePtr tempPtr=*ptr;

        while(tempPtr->nextPtr!=NULL)
        {
            tempPtr=tempPtr->nextPtr;
        }
        tempPtr->nextPtr= newPtr;
    }
}
void addNote_f(NodePtr* ptr)//float型態輸入器
{

    NodePtr newPtr = malloc(sizeof(Node));//都一樣
    newPtr->nextPtr= NULL;
    printf("Please input float:");
    scanf("%f", &newPtr->number);
    getchar();
    newPtr->type=2;

    if(*ptr==NULL)
    {
        *ptr=newPtr;
    }
    else
    {

        NodePtr tempPtr=*ptr;

        while(tempPtr->nextPtr!=NULL)
        {
            tempPtr=tempPtr->nextPtr;
        }
        tempPtr->nextPtr= newPtr;
    }
}
void addNote_s(NodePtr* ptr)//char型態輸入器
{

    NodePtr newPtr = malloc(sizeof(Node));
    newPtr->nextPtr= NULL;
    printf("Please input char:");
    scanf("%s",newPtr->text);
    newPtr->type=3;
    if(*ptr==NULL)
    {
        *ptr=newPtr;
    }
    else
    {

        NodePtr tempPtr=*ptr;

        while(tempPtr->nextPtr!=NULL)
        {
            tempPtr=tempPtr->nextPtr;
        }
        tempPtr->nextPtr= newPtr;
    }
}
void print(NodePtr ptr)//列印器
{
    while(ptr!=NULL)
    {
        if(ptr->type==1)//偵測型態
        {
            printf("%d\n",ptr->value);
        }
        else if(ptr->type==2)
        {
            printf("%f\n",ptr->number);
        }
        else if(ptr->type==3)
        {
            printf("%s",ptr->text);
        }
        ptr=ptr->nextPtr;
    }
    printf("\n");
}
void freemem(NodePtr ptr)//釋放記憶體空間
{
    while(ptr!=NULL)
    {
        NodePtr temp=ptr;
        if(ptr->type==1)
        {
            printf("Delete %d\n",temp->value);
           free(temp);
        }
        else if(ptr->type==2)
        {
            printf("Delete %f\n",temp->number);
            free(temp);
        }
        else if(ptr->type==3)
        {
            printf("Delete %s\n",temp->value);
            free(temp);
        }
        ptr=ptr->nextPtr;
    }
}
int main()
{
    NodePtr headPtr=NULL;
    int user_input, end=0;
    int input_form;
    do
    {
        printf("1. new 2.print 3.end:");
        scanf("%d",&user_input);//功能選擇
        switch(user_input)
        {
            case 1:
            {
                printf("選擇類型:(1:int/2:float/3:char[16]:");
                scanf("%d",&input_form);
                getchar();
                if(input_form==1)//int型態
                {
                    addNote_i(&headPtr);
                    user_input=0;
                    break;
                }
                else if(input_form==2)//float
                {
                    addNote_f(&headPtr);
                    user_input=0;
                    break;
                }
                else if(input_form==3)//char
                {
                    addNote_s(&headPtr);
                    user_input=0;

                    break;
                }
                else//都不是
                {
                    printf("輸入錯誤\n");
                    user_input=0;
                }
            }
            case 2:
            {
                print(headPtr);//印出
                break;
            }
            case 3:
            {
                freemem(headPtr);//釋放記憶體
                end=1;
                break;
            }

        }
    }while(!end);//結束程式

    return 0;

}
