#include<stdio.h>
#include<stdlib.h>

typedef struct _Form
{
    char Num;
    union
    {
        int Int;
        char Char[16];
        float Float;
    }Type;
}Form;
//輸入的副函式
void Input(Form *Function,int i)
{
    //紀錄int類型的資料
    if(Function[i].Num=='i')
    {
        int Number;
        printf("輸入資料:");
        scanf("%d",&Function[i].Type.Int);
    }
    //紀錄float類型的資料
    else if(Function[i].Num=='f')
    {
        int Number;
        printf("輸入資料:");
        scanf("%f",&Function[i].Type.Float);
    }
    //紀錄char類型的資料
    else if(Function[i].Num=='s')
    {
        int Number;
        printf("輸入資料:");
        scanf("%s",&Function[i].Type.Char);
    }
    //防呆
    else
    {
        printf("輸入錯誤!\n");
    }
}
//輸出的副函式
void Output(Form *Function,int a)
{
    //輸出int類型的資料
    if(Function[a].Num=='i')
    {
        printf("%d",Function[a].Type.Int);
    }
    //輸出float類型的資料
    else if(Function[a].Num=='f')
    {
        printf("%f",Function[a].Type.Float);
    }
    //輸出char類型的資料
    else if(Function[a].Num=='s')
    {
        printf("%s",Function[a].Type.Char);
    }
}

int main()
{
    int Choose1;
            int i=0;
    //建立動態陣列
    Form *dynArr=malloc(sizeof(Form));
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
            free(dynArr);
            break;
        }
        //選擇1，就輸入
        if(Choose1==1)
        {
            printf("選擇類型:(i:int/f:float/s:char[16]):");
            scanf("%c",&dynArr[i].Num);
            getchar();
            while(dynArr[i].Num != 'i' && dynArr[i].Num != 's' && dynArr[i].Num != 'f')
            {
                printf("輸入錯誤!\n");
                printf("選擇類型:(i:int/f:float/s:char[16]):");
                scanf("%c",&dynArr[i].Num);
                getchar();
            }
            //新增動態陣列大小
            dynArr=realloc(dynArr,(i+2)*sizeof(Form));
            //呼叫輸入的副函式
            Input(dynArr,i);
            //紀數
            i++;
        }
        //選擇2，就輸出
        if(Choose1==2)
        {
            int j;
            for(j=0;j<=i;j++)
            {
                if(dynArr[j].Num == 'i')
                    printf("%d\n",dynArr[j].Type.Int);
                if(dynArr[j].Num == 'f')
                    printf("%f\n",dynArr[j].Type.Float);
                if(dynArr[j].Num == 's')
                    printf("%s\n",dynArr[j].Type.Char);
            }
        }
    }
    return 0;
}
