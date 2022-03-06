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
} A;

void inputi(A *a,int b)
{
    scanf("%d",&a[b].typ);
}

void inputf(A *a,int b)
{
    scanf("%f",&a[b].typ);
}

void inputs(A *a,int b)
{
    scanf("%s",&a[b].typ);
}

void outputi(A *a,int b)
{
    printf("%d",a[b].typ.i);
}

void outputf(A *a,int b)
{
    printf("%f",a[b].typ.f);
}

void outputs(A *a,int b)
{
    printf("%s",a[b].typ.s);
}

int main()
{
    int choose;
    char type;
    int b=0;
    A *array=malloc(b*sizeof(A));

    while(1)
    {
        printf("選擇:(1.新增/2.印出/0.結束):");//選擇功能
        scanf("%d",&choose);
        if(choose == 1)//新增
        {
            printf("選擇類型:(i:int/f:float/s:char[16]):");
            getchar();
            scanf("%c",&type);
            if(type =='i')//若要輸入整數
            {
                printf("輸入資料:");
                inputi(array,b);
                array[b].num='i';
                b++;
            }
            else if(type =='f')//若要輸入浮點數
            {
                printf("輸入資料:");
                inputf(array,b);
                array[b].num='f';
                b++;
            }
            else if(type == 's')//若要輸入字串
            {
                printf("輸入資料:");
                inputs(array,b);
                array[b].num='s';
                b++;
            }
            else
            {
                printf("輸入錯誤!\n");
            }
            
        }
        else if(choose == 2)//印出
        {
            for(int i=0;i<b;i++)
            {
                if(array[i].num =='i')
                {
                    outputi(array,i);
                    printf("\n");
                }
                else if(array[i].num =='f')
                {
                    outputf(array,i);
                    printf("\n");
                }
                else if(array[i].num == 's')
                {
                    outputs(array,i);
                    printf("\n");
                }
            }
        }
        else if(choose == 0)//離開
        {
            printf("結束程式\n");
            free(array);
            break;
        }
        else//輸入錯誤
        {
            printf("輸入錯誤!\n");
            continue;
        }
    }
}
