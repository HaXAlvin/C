#include <stdio.h>
#include <stdlib.h>
typedef struct node* NodePtr;
typedef struct node//�w�qstruct
{
    int type;//�x�s���A
    int value;//int���A
    float number;//float���A
    char text[16];//char���A
    NodePtr nextPtr;
} Node;
void addNote_i(NodePtr* ptr)//int���A��J��
{

    NodePtr newPtr = malloc(sizeof(Node));//
    newPtr->nextPtr= NULL;
    printf("Please input number:");
    scanf("%d", &newPtr->value);
    newPtr->type=1;//�w�q���A

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
void addNote_f(NodePtr* ptr)//float���A��J��
{

    NodePtr newPtr = malloc(sizeof(Node));//���@��
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
void addNote_s(NodePtr* ptr)//char���A��J��
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
void print(NodePtr ptr)//�C�L��
{
    while(ptr!=NULL)
    {
        if(ptr->type==1)//�������A
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
void freemem(NodePtr ptr)//����O����Ŷ�
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
        scanf("%d",&user_input);//�\����
        switch(user_input)
        {
            case 1:
            {
                printf("�������:(1:int/2:float/3:char[16]:");
                scanf("%d",&input_form);
                getchar();
                if(input_form==1)//int���A
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
                else//�����O
                {
                    printf("��J���~\n");
                    user_input=0;
                }
            }
            case 2:
            {
                print(headPtr);//�L�X
                break;
            }
            case 3:
            {
                freemem(headPtr);//����O����
                end=1;
                break;
            }

        }
    }while(!end);//�����{��

    return 0;

}
