#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//設定結構
typedef union _data
{
    int i;
    float f;
    char s[16];
}data;

typedef struct _array
{
    data base;
    int num;
    struct _array* nextptr;
    struct _array* lastptr;
}array;

//輸入整數函式
void in1(array *a)
{
    scanf("%d", &a -> base);
}

//輸入浮點數函式
void in2(array *a)
{
    scanf("%f", &a -> base);
}

//輸入字串函式
void in3(array *a)
{
    scanf("%s", &a -> base);
}

//輸出整數函式
void out1(array *a)
{
   printf("%d\n", a -> base.i);
}

//輸出浮點數數函式
void out2(array *a)
{
   printf("%f\n", a -> base.f);
}

//輸出字串函式
void out3(array *a)
{
   printf("%s\n", a -> base.s);
}

int main()
{
    //設定變數
    int n = 0;
    int a;
    int time = 0;
    array *headptr = NULL;
    array *currentptr = NULL;
    array scanptr;
    array *printptr;
    while(1)
    {
        printf("選擇：(1.新增/2.印出/0.結束)：");
        scanf("%d", &n);
        //選擇新增
        if(n == 1)
        {
            time++;
            while(1)
            {
                printf("選擇類型:(1：int/2：float/3：char[16])：");
                scanf("%d", &a);
                //輸入int
                if(a == 1)
                {
                    printf("輸入資料:");
                    scanf("\n");
                    in1(&scanptr);
                    if(headptr == NULL)
                    {
                        headptr = malloc(sizeof(array));
                        currentptr = headptr;
                        headptr -> lastptr = NULL;
                    }
                    else
                    {
                        currentptr -> nextptr = malloc(sizeof(array));
                        currentptr -> nextptr -> lastptr=currentptr;
                        currentptr = currentptr -> nextptr;
                    }
                    currentptr -> base = scanptr.base;
                    currentptr -> num = a;
                    currentptr -> nextptr = NULL;
                    break;
                }
                //輸入float
                if(a == 2)
                {
                    printf("輸入資料:");
                    scanf("\n");
                    in2(&scanptr);
                    if(headptr == NULL)
                    {
                        headptr = malloc(sizeof(array));
                        currentptr = headptr;
                        headptr -> lastptr = NULL;
                    }
                    else
                    {
                        currentptr -> nextptr = malloc(sizeof(array));
                        currentptr -> nextptr -> lastptr=currentptr;
                        currentptr = currentptr -> nextptr;
                    }
                    currentptr -> base = scanptr.base;
                    currentptr -> num = a;
                    currentptr -> nextptr = NULL;
                    break;
                }
                //輸入字串
                if(a == 3)
                {
                    printf("輸入資料:");
                    scanf("\n");
                    in3(&scanptr);
                    if(headptr == NULL)
                    {
                        headptr = malloc(sizeof(array));
                        currentptr = headptr;
                        headptr -> lastptr = NULL;
                    }
                    else
                    {
                        currentptr -> nextptr = malloc(sizeof(array));
                        currentptr -> nextptr -> lastptr=currentptr;
                        currentptr = currentptr -> nextptr;
                    }
                    currentptr -> base = scanptr.base;
                    currentptr -> num = a;
                    currentptr -> nextptr = NULL;
                    break;
                }
                //防呆
                if(a != 1 && a != 2 && a != 3)
                {
                    printf("輸入錯誤!\n");
                }
            }

        }
        //選擇印出
        if(n == 2)
        {
            printptr = headptr;
            while(printptr != NULL)
            {
                //輸出int
                if(printptr -> num == 1)
                {
                    out1(printptr);
                }
                //輸出float
                if(printptr -> num == 2)
                {
                    out2(printptr);
                }
                //輸出字串
                if(printptr -> num == 3)
                {
                    out3(printptr);
                }
                printptr = printptr -> nextptr;
            }

        }
        //防呆
        if(n != 0 && n != 1 && n != 2)
        {
            printf("輸入錯誤!\n");
        }
        //結束程式
        if(n == 0)
        {
            printf("結束程式\n");
            while(currentptr -> lastptr != NULL)
            {
                free(currentptr -> nextptr);
                currentptr = currentptr -> lastptr;
            }
            free(headptr);
            return 0;
        }
    }
}
