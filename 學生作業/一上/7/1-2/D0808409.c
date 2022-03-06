#include <stdbool.h>
#include <stdio.h>
int main()
{   int Length,Rows,Column;
    do{//用dowhile判斷是否錯誤還有重複輸入
    printf("輸入菱形對角線長度（3、5、7、9）：");
    scanf("%d",&Length);
    if(Length!=3&&Length!=5&&Length!=7&&Length!=9)
    {
        printf("輸入錯誤!\n");
    }
    }while(Length!=3&&Length!=5&&Length!=7&&Length!=9) ;
    do{//用dowhile判斷是否錯誤還有重複輸入
    printf("輸入行數（2 ~ 10）：");
    scanf("%d",&Rows);
    if(Rows<2||Rows>10)
    {
        printf("輸入錯誤!\n");
    }
    }while(Rows<2||Rows>10) ;
    do{//用dowhile判斷是否錯誤還有重複輸入
    printf("輸入列數（2 ~ 10）：");
    scanf("%d",&Column);
    if(Column<2||Column>10)
    {
        printf("輸入錯誤!\n");
    }
    }while(Column<2||Column>10) ;
    int Space=Length-2;
    int whiK=1;
    bool MaxLen=false;
    for(int i=0;i<Rows;i++)//輸出行
    {   whiK=1;
        MaxLen=false;
        while(whiK>0)
        {
            for(int j=1;j<=Column;j++)//輸出列
            {
                Space=(Length-whiK)/2;//算空格數
                for(int m = 1 ;m <= Space ;m++)
                {
                    printf(" ");
                }
                for(int n = 1 ;n <= whiK ;n++)
                {
                    printf("*");
                }
                Space=(Length-whiK)/2 +1;
                if(Space==0)
                    Space++;
                for(int o = 1 ;o <= Space ;o++)
                {
                    printf(" ");
                }
            }
            puts("");
            if(whiK<Length&&!MaxLen)
            {
                whiK+=2;
                if(whiK==Length)
                {
                    MaxLen=true;//用bool存是否加到超過菱形長度
                }
            }
            else if(MaxLen)//接下來減回來
            {
                whiK-=2;
                if(whiK<=0)
                    break;
            }
        }
        puts("");
    }
}
