#include <stdio.h>
#include <stdlib.h>

int main()
{
    int diagonal;  //對角線長度
    int columns;   //行數
    int rows;      //列數
    int check = 1; //迴圈控制

    while (check == 1)  //輸入對角線長度的迴圈
    {
        check = 0;

        printf("輸入菱形對角線長度(3、5、7、9)：");
        scanf("%d", &diagonal);

        if (!(diagonal == 3 || diagonal == 5 || diagonal == 7 || diagonal == 9))    //若輸入值不在範圍，則回到迴圈起點
        {
            printf("輸入錯誤!\n");
            check = 1;
        }
    }

    while (check == 0)  //輸入行數的迴圈
    {
        check = 1;

        printf("輸入行數(2~10)：");
        scanf("%d", &columns);


        if (columns < 2 || columns > 10)    //若輸入值不在範圍，則回到迴圈起點
        {
            printf("輸入錯誤!\n");
            check = 0;
        }

    }

    while (check == 1)  //輸入列數的迴圈
    {
        check = 0;

        printf("輸入列數(2~10)：");
        scanf("%d", &rows);

        if (rows < 2 || rows > 10)    //若輸入值不在範圍，則回到迴圈起點
        {
            printf("輸入錯誤!\n");
            check = 1;
        }
    }

    int mid = (diagonal + 1) / 2;                //mid = 菱形正中間的列
    int i, j, k, m, n;

    for (i = 0; i < rows; i++)                   //印出rows(2~10)列完整菱形的迴圈
    {

        for (j = 1; j <= mid; j++)               //印出每一個菱形有多少行的迴圈 (只印上半部，j總共會有mid行)
        {
            for (k = 0; k < columns; k++)        //印出columns(2~10)行完整菱形的迴圈
            {
                for (m = 0; m < mid - j; m++)    //mid列沒有空格，而每接近mid一列，空格減少1，j也增加1
                {
                    printf(" ");
                }
                for (n = 0; n < 2 * j - 1; n++)  //每列增加2顆星星，2乘以J
                {
                    printf("*");
                }
                for (m = 0; m < mid - j; m++)    //印出與前面相同數量的空白，以免影響到第二行的菱形
                {
                    printf(" ");
                }
                printf(" ");
            }
            printf("\n");
        }

        for (j = mid - 1; j > 0; j--)           //印出每一個菱形有多少行的迴圈 (只印下半部，j會有mid-1行。空白和星星的數量與上半部相反，因此j採用遞減)
        {
            for (k = 0; k < columns; k++)       //其他與上面相同
            {
                for (m = 0; m < mid - j; m++)   
                {
                    printf(" ");
                }
                for (n = 0; n < 2 * j - 1; n++)
                {
                    printf("*");
                }
                for (m = 0;  m < mid - j; m++)
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
