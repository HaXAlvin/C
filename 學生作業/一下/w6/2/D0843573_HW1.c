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
    //紀錄in類型的資料
    if((*Function).Num=='i')
    {
        int Number;
        printf("輸入資料:");
        scanf("%d",&(*Function).Type.Int);
    }
    //紀錄float類型的資料
    else if((*Function).Num=='f')
    {
        int Number;
        printf("輸入資料:");
        scanf("%f",&(*Function).Type.Float);
    }
    //紀錄char類型的資料
    else if((*Function).Num=='s')
    {
        int Number;
        printf("輸入資料:");
        scanf("%s",&(*Function).Type.Char);
    }
    //防呆
    else
    {
        printf("輸入錯誤!\n");
    }
    //將此node的下個node的位址(nextPtr)預設為NULL
    (*Function).nextPtr=NULL;
}

void Output(Form *Function)
{
    //輸出int類型的資料
    if((*Function).Num=='i')
    {
        printf("%d\n",(*Function).Type.Int);
    }
    //輸出float類型的資料
    else if((*Function).Num=='f')
    {
        printf("%f\n",(*Function).Type.Float);
    }
    //輸出char類型的資料
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
        printf("選擇:(1.新增/2.印出/0.結束):");
        scanf("%d",&Choose1);
        getchar();
        //防呆
        if((Choose1<0)||(Choose1>2))
        {
            printf("輸入錯誤!\n");
        }
        //釋放動態陣列，結束程式
        if(Choose1==0)
        {
            printf("結束程式\n");
            free(currentPtr);
            break;
        }
        //選擇1，就輸入
        if(Choose1==1)
        {
            //動態配置1個Form，並使currentPtr與headPtr指向這個Form
            if(headPtr == NULL)
            {
                headPtr = malloc(sizeof(Form));
                currentPtr = headPtr;
            }
            //動態配置1個Form，並使currentPtr->nextPtr指向這個Form
            else
            {
                (*currentPtr).nextPtr = malloc(sizeof(Form));
                //將currentPtr指向新的Form，也就是原本的currentPtr->nextPtr
                currentPtr = currentPtr->nextPtr;
            }
            printf("選擇類型:(i:int/f:float/s:char[16]):");
            scanf("%c",&(*currentPtr).Num);
            getchar();
            //防呆
            while((*currentPtr).Num != 'i' && (*currentPtr).Num != 's' && (*currentPtr).Num != 'f')
            {
                printf("輸入錯誤!\n");
                printf("選擇類型:(i:int/f:float/s:char[16]):");
                scanf("%c",&(*currentPtr).Num);
                getchar();
            }
            //呼叫輸入的副函式
            Input(currentPtr);

        }
        //選擇2，就輸出
        if(Choose1==2)
        {
            currentPtr = headPtr;

            while(currentPtr!=NULL)
            {
                //呼叫輸出的副函式
                Output(currentPtr);
                recordPtr = currentPtr;
                currentPtr = (*currentPtr).nextPtr;
            }
            currentPtr = recordPtr;
        }
    }
    return 0;
}
