#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef union _list
{
    int i;
    float f;
    char s[16];
} list;

typedef struct _A
{
    char num;
    list typ;
    struct _A *lastPtr;
    struct _A *nextPtr;
} A;

void inputi(A *a)
{
    scanf("%d",&a->typ.i);
}

void inputf(A *a)
{
    scanf("%f",&a->typ);
}

void inputs(A *a)
{
    scanf("%s",&a->typ);
}

void outputi(A *a)
{
    printf("%d",a->typ.i);
}

void outputf(A *a)
{
    printf("%f",a->typ.f);
}

void outputs(A *a)
{
    printf("%s",a->typ.s);
}


int main()
{
    int choose;
    char type;
    A *headPtr = NULL, *currentPtr = NULL, *priPtr;
    A scanPtr;

    while(1)
    {
        printf("選擇:(1.新增/2.印出/0.結束):");//選擇功能
        scanf("%d",&choose);


        if(choose == 1)//新增
        {
            while (1) {
                printf("選擇類型:(i:int/f:float/s:char[16]):");
                scanf("\n");
                scanf("%c%*c",&type);
                if(type =='i')//若要輸入整數
                {
                    printf("輸入資料:");
                    inputi(&scanPtr);
                    currentPtr->num='i';
                    break;
                }
                else if(type =='f')//若要輸入浮點數
                {
                    printf("輸入資料:");
                    inputf(&scanPtr);
                    currentPtr->num='f';
                    break;
                }
                else if(type == 's')//若要輸入字串
                {
                    printf("輸入資料:");
                    inputs(&scanPtr);
                    currentPtr->num='s';
                    break;
                }
                else
                {
                    printf("輸入錯誤!\n");
                }
            }


                if(headPtr == NULL){
                    headPtr = malloc(sizeof(A));
                    currentPtr = headPtr;
                }
                else{
                    currentPtr->nextPtr = malloc(sizeof(A));
                    currentPtr = currentPtr->nextPtr;
                }
                currentPtr->nextPtr = NULL;




        }
        else if(choose == 2)//印出
        {
            priPtr = headPtr;
            while(priPtr->nextPtr!=NULL)
            {
                if(priPtr->num =='i')
                {
                    outputi(currentPtr);
                    printf("\n");
                }
                else if(priPtr->num =='f')
                {
                    outputf(currentPtr);
                    printf("\n");
                }
                else if(priPtr->num == 's')
                {
                    outputs(currentPtr);
                    printf("\n");
                }
                priPtr=priPtr->nextPtr;
            }
        }
        else if(choose == 0)//離開
        {
            printf("結束程式\n");
            free(currentPtr);
            break;
        }
        else//輸入錯誤
        {
            printf("輸入錯誤!\n");
            continue;
        }
    }
}

