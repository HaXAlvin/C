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
    char alpha;
}array;

//輸入整數函式
void in1(array *a, int b)
{
    scanf("%d", &a[b].base.i);
}

//輸入浮點數函式
void in2(array *a, int b)
{
    scanf("%f", &a[b].base.f);
}

//輸入字串函式
void in3(array *a, int b)
{
    scanf("%s", &a[b].base.s);
}

//輸出整數函式
void out1(array *a, int b)
{
   printf("%d\n", a[b].base.i);
}

//輸出浮點數數函式
void out2(array *a, int b)
{
   printf("%f\n", a[b].base.f);
}

//輸出字串函式
void out3(array *a, int b)
{
   printf("%s\n", a[b].base.s);
}

int main()
{
    //設定變數
    int n;
    char a;
    int time = 0;
    data base;
    //建立動態記憶體空間
    array *mall = malloc(sizeof(array));
    while(1)
    {
        printf("選擇：(1.新增/2.印出/0.結束)：");
        scanf("%d", &n);
        //選擇新增
        if(n == 1)
        {
            while(1)
            {
                printf("選擇類型：(i：int/f：float/s：char[16])：");
                getchar();
                scanf("%c", &a);
                //重新分配動態記憶體空間
                mall = realloc(mall,sizeof(array));
                //輸入整數
                if(a == 'i')
                {
                    printf("輸入資料：");
                    in1(mall, time);
                    mall[time].alpha = a;
                    time++;
                    break;
                }
                //輸入浮點數
                else if(a == 'f')
                {
                    printf("輸入資料：");
                    in2(mall, time);
                    mall[time].alpha = a;
                    time++;
                    break;
                }
                //輸入字串
                else if(a == 's')
                {
                    printf("輸入資料：");
                    in3(mall, time);
                    mall[time].alpha = a;
                    time++;
                    break;
                }
                //防呆
                else
                {
                    printf("輸入錯誤!\n");
                }
            }
        }
        //選擇印出
        if(n == 2)
        {
            //判斷動態陣列中每項形式
            for(int i = 0; i < time; i++)
            {
                if(mall[i].alpha == 'i')
                {
                    out1(mall, i);
                }
                if(mall[i].alpha == 'f')
                {
                    out2(mall, i);
                }
                if(mall[i].alpha == 's')
                {
                    out3(mall, i);
                }
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
            printf("結束程式");
            free(mall);
            return 0;
        }
    }
}
