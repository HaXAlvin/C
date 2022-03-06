#include<stdio.h>
#include<stdlib.h>

typedef union _content
{
    int i;
    float f;
    char s[16];
} content;

typedef struct _data
{
    content stuff;
    int sort;
    struct _data* nextptr;
    struct _data* lastptr;
} data;
//輸入用副程式
void input1(data *a)
{
    scanf("%d",&a->stuff);
}

void input2(data *a)
{
    scanf("%f",&a->stuff);
}

void input3(data *a)
{
    scanf("%s",&a->stuff);
}
//輸出用副程式
void output1(data *a)
{
    printf("%d\n",a->stuff.i);
}

void output2(data *a)
{
    printf("%f\n",a->stuff.f);
}

void output3(data *a)
{
    printf("%s\n",a->stuff.s);
}
//錯誤
void wrong(void)
{
    printf("輸入錯誤!\n");
}
//主程式
int main()
{
    int system=0;
    int insort=0;
    void (*input[])(data *)={input1,input2,input3};
    void (*output[])(data *)={output1,output2,output3};
    data *headptr=NULL;
    data *currentptr=NULL;
    data scanptr;
    data *printptr;
    while(1)//系統迴圈
    {
        printf("選擇:(1.新增/2.印出/0.結束):");
        scanf("%d",&system);
        if(system==0)//結束
        {
            while(currentptr->lastptr!=NULL)
            {
                free(currentptr->nextptr);
                currentptr=currentptr->lastptr;
            }
            free(headptr);
            return 0;
        }
        else if(system==1)//輸入
        {
            while(1)//防呆迴圈
            {
                printf("選擇類型:(1.int/2.float/3.char[16]):");
                scanf("%d",&insort);
                if(insort==1||insort==2||insort==3)//輸入正確
                {
                    break;
                }
                else//輸入錯誤
                {
                    wrong;
                }
            }
            printf("輸入資料:");
            scanf("\n");
            input[insort-1](&scanptr);
            if(headptr==NULL)
            {
                headptr=malloc(sizeof(data));
                currentptr=headptr;
                headptr->lastptr=NULL;
            }
            else
            {
                currentptr->nextptr=malloc(sizeof(data));
                currentptr->nextptr->lastptr=currentptr;
                currentptr=currentptr->nextptr;
            }
            currentptr->stuff=scanptr.stuff;
            currentptr->sort=insort;
            currentptr->nextptr=NULL;
        }
        else if(system==2)//印出
        {
            printptr=headptr;
            while(printptr!=NULL)
            {
                output[(printptr->sort)-1](printptr);
                printptr=printptr->nextptr;
            }
        }
        else//輸入錯誤
        {
            wrong();
        }
    }
}
