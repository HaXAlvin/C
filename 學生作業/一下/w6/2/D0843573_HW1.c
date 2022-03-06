#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Form
{
    char Num;
    struct Form *nextPtr;
    union
    {
        int Int;
        char Char[16];
        float Float;
    }Type;
}Form;

void Input(Form *Function)
{
    //����in���������
    if((*Function).Num=='i')
    {
        int Number;
        printf("��J���:");
        scanf("%d",&(*Function).Type.Int);
    }
    //����float���������
    else if((*Function).Num=='f')
    {
        int Number;
        printf("��J���:");
        scanf("%f",&(*Function).Type.Float);
    }
    //����char���������
    else if((*Function).Num=='s')
    {
        int Number;
        printf("��J���:");
        scanf("%s",&(*Function).Type.Char);
    }
    //���b
    else
    {
        printf("��J���~!\n");
    }
    //�N��node���U��node����}(nextPtr)�w�]��NULL
    (*Function).nextPtr=NULL;
}

void Output(Form *Function)
{
    //��Xint���������
    if((*Function).Num=='i')
    {
        printf("%d\n",(*Function).Type.Int);
    }
    //��Xfloat���������
    else if((*Function).Num=='f')
    {
        printf("%f\n",(*Function).Type.Float);
    }
    //��Xchar���������
    else if((*Function).Num=='s')
    {
        printf("%s\n",(*Function).Type.Char);
    }
}

int main()
{
    int Choose1;
    Form *headPtr=NULL, *currentPtr=NULL, *recordPtr=NULL;
    while(1)
    {
        printf("���:(1.�s�W/2.�L�X/0.����):");
        scanf("%d",&Choose1);
        getchar();
        //���b
        if((Choose1<0)||(Choose1>2))
        {
            printf("��J���~!\n");
        }
        //����ʺA�}�C�A�����{��
        if(Choose1==0)
        {
            printf("�����{��\n");
            free(currentPtr);
            break;
        }
        //���1�A�N��J
        if(Choose1==1)
        {
            //�ʺA�t�m1��Form�A�è�currentPtr�PheadPtr���V�o��Form
            if(headPtr == NULL)
            {
                headPtr = malloc(sizeof(Form));
                currentPtr = headPtr;
            }
            //�ʺA�t�m1��Form�A�è�currentPtr->nextPtr���V�o��Form
            else
            {
                (*currentPtr).nextPtr = malloc(sizeof(Form));
                //�NcurrentPtr���V�s��Form�A�]�N�O�쥻��currentPtr->nextPtr
                currentPtr = currentPtr->nextPtr;
            }
            printf("�������:(i:int/f:float/s:char[16]):");
            scanf("%c",&(*currentPtr).Num);
            getchar();
            //���b
            while((*currentPtr).Num != 'i' && (*currentPtr).Num != 's' && (*currentPtr).Num != 'f')
            {
                printf("��J���~!\n");
                printf("�������:(i:int/f:float/s:char[16]):");
                scanf("%c",&(*currentPtr).Num);
                getchar();
            }
            //�I�s��J���ƨ禡
            Input(currentPtr);

        }
        //���2�A�N��X
        if(Choose1==2)
        {
            currentPtr = headPtr;

            while(currentPtr!=NULL)
            {
                //�I�s��X���ƨ禡
                Output(currentPtr);
                recordPtr = currentPtr;
                currentPtr = (*currentPtr).nextPtr;
            }
            currentPtr = recordPtr;
        }
    }
    return 0;
}
