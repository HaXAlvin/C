#include<stdio.h>

int main()
{
    int dia, col, rows;//對角線(diagonal), 行數(columns), 列數(rows)
    int i, j, k, m;
    while (printf("輸入菱形對角線長度(3、5、7、9):"), scanf("%d", &dia) && (dia != 3 && dia != 5 && dia != 7 && dia != 9))
    {
        printf("輸入錯誤!\n");//對角線輸入錯誤
    }
    while (printf("輸入行數(2~10):"), scanf("%d", &col) && (col < 2 || col > 10))
    {
        printf("輸入錯誤!\n");//行數輸入錯誤
    }
    while (printf("輸入列數(2~10):"), scanf("%d", &rows) && (rows < 2 || rows > 10))
    {
        printf("輸入錯誤!\n");//列數輸入錯誤
    }
    printf("\n");
    for (i = 0; i < rows; i++)//共有n列
    {
        for (j = 0; j < dia / 2 + 1; j++)//菱形的上半部共有(對角線 / 2 + 1)列
        {
            for (k = 0; k < col; k++)//菱形的上半部需要多少個
            {
                for (m = dia / 2; m > j; m--)//上半部 前面空白的部分
                    printf(" ");
                for (m = 0; m < 1 + j * 2; m++)//上半部的 *
                    printf("*");
                for (m = dia / 2; m > j; m--)//上半部 後面空白的部分
                    printf(" ");
                if (k < col)//每個菱形之間空一格
                    printf(" ");
            }
            printf("\n");
        }
        for (j = 0; j < dia / 2; j++)//菱形的下半部共有(對角線 / 2)列
        {
            for (k = 0; k < col; k++)//菱形的下半部需要多少個
            {
                for (m = 0; m <= j; m++)//下半部 前面空白的部分
                    printf(" ");
                for (m = dia; m > j * 2 + 2 ; m--)//下半部的*
                    printf("*");
                for (m = 0; m <= j; m++)//下半部 後面空白的部分
                    printf(" ");
                if (k < col)
                    printf(" ");//每個菱形之間空一格
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
