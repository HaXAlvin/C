#include <stdio.h>
#include <stdlib.h>

int main()
{
    int diagonal,row1,row2;//對角線/行/列
    int i,j,n,a,m,k,l;//for裡面的變數

    while(1)//對角線長度的迴圈
    {
        printf("輸入菱形對角線長度:(3、5、7、9): ");
        scanf("%d",&diagonal);
        if(diagonal!=3&&diagonal!=5&&diagonal!=7&&diagonal!=9)//錯誤
        {
            printf("輸入錯誤\n");
        }
        if(diagonal==3||diagonal==5||diagonal==7||diagonal==9)//正確
        {
            break;
        }
    }
    while(1)//行數的迴圈
    {
        printf("輸入行數(2~10): ");
        scanf("%d",&row1);
        if(row1!=2&&row1!=3&&row1!=4&&row1!=5&&row1!=6&&row1!=7&&row1!=8&&row1!=9&&row1!=10)//錯誤
        {
            printf("輸入錯誤\n");
        }
        if(row1==2||row1==3||row1==4||row1==5||row1==6||row1==7||row1==8||row1==9||row1==10)//正確
        {
            break;
        }
    }
    while(1)//列數的迴圈
    {
        printf("輸入列數(2~10): ");
        scanf("%d",&row2);
        if(row2!=2&&row2!=3&&row2!=4&&row2!=5&&row2!=6&&row2!=7&&row2!=8&&row2!=9&&row2!=10)//錯誤
        {
            printf("輸入錯誤\n");
        }
        if(row2==2||row2==3||row2==4||row2==5||row2==6||row2==7||row2==8||row2==9||row2==10)//正確
        {
            goto A;//跳入菱形
        }
    }

A://菱形程式碼
    for(l=1; l<=row2; l++)//列數
    {
        for(i=1,m=(diagonal-1)/2; i<=(diagonal+1)/2; i++,m--)//菱形上半部
        {
            for(n=1; n<=row1; n++)
            {
                for(a=1; a<=m; a++)
                {
                    printf(" ");
                }
                for(a=0; a<i*2-1; a++)
                {
                    printf("*");
                }
                for(a=1; a<=m; a++)
                {
                    printf(" ");
                }
                printf(" ");

            }

            printf("\n");
        }
        for(i=1,k=diagonal-2; i<(diagonal+1)/2; i++,k-=2)//菱形下半部
        {
            for(n=1; n<=row1; n++)
            {
                for(a=1; a<=i; a++)
                {
                    printf(" ");
                }
                for(a=1; a<=k; a++)
                {
                    printf("*");
                }
                for(a=1; a<=i; a++)
                {
                    printf(" ");
                }
                printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }




    return 0;
}
