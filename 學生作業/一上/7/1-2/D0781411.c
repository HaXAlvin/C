#include<stdio.h>

int main()
{
    int c; //行           Column
    int r; //列           Row
    int l; //對角線長度  length
    int j;
    int k;
    int i;
    int z;
    printf("輸入菱形對角線長度(3、5、7、9):");
    scanf ("%d%*c",&l);
    while(l!=3&&l!=5&&l!=7&&l!=9)
    {
        printf("輸入錯誤!\n");
        printf("輸入菱形對角線長度(3、5、7、9):");
        scanf ("%d%*c",&l);
    }
    printf("輸入行數(2~10):");
    scanf ("%d%*c",&c);
    while(c<2||c>10)
    {
        printf("輸入錯誤!\n");
        printf("輸入行數(2~10):");
        scanf ("%d%*c",&c);
    }
    printf("輸入列數(2~10):");
    scanf ("%d%*c",&r);
    while(r<2||r>10)
    {
        printf("輸入錯誤!\n");
        printf("輸入行數(2~10):");
        scanf ("%d%*c",&r);
    }
    printf("\n"); //列數跟菱形的空格 
    for(z=0; z<r;z++)
    {
        for(i=0; i<l-i; i++)
        {
            for(k=0; k<c; k++)
            {
                for(j=0; j<((l+1)/2)-i-1; j++)
                {
                    printf(" ");
                }
                for(j=0; j<(2*i+1); j++)
                {
                    printf("*");
                }
                for(j=0; j<((l+1)/2)-i-1; j++)
                {
                    printf(" ");
                }
                printf(" ");
            }
            printf("\n");
        }
        for(i=0; i<l-i; i++)
        {
            for(k=0; k<c; k++)
            {
                for(j=0; j<i+1; j++)
                {
                    printf(" ");
                }
                for(j=0; j<l-2*i-2; j++)
                {
                    printf("*");
                }
                for(j=0; j<i+1; j++)
                {
                    printf(" ");
                }
                printf(" ");
            }
            printf("\n");
        }
    }
}
