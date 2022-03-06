#include <stdio.h>
// colom hapus eror
int main ()
{
    int leng,row,col;
    int i,ltop,lbot,s,y,r,cbot,m;
    int n = 1, x = 1, c = 1, z = 0, ctop = 1;
    printf("Input length (3, 5, 7, 9): ");
    scanf("%d",&leng);
    printf("Row (2~10) : " );
    scanf("%d",&row);
    printf("Column (2~10) : ");
    scanf("%d",&col);

    while (leng>10 || leng%2==0) //check length input
    {
        printf("Length input error, please re-input(3, 5, 7, 9): ");
        scanf("%d",&leng);
    }

    while (row>10 || row<2) //check row input
    {
        printf("Row input error, please re-input(2~10): ");
        scanf("%d",&row);
    }

    while (col>10 || col<2) // check column input
    {
        printf("Column input error, please re-input(2~10): ");
        scanf("%d",&col);
    }


    for (r=1;r<=row;r++) // row
    {
        y = leng/2;
        m = leng;
        for (ltop=1;ltop<=leng/2+1;ltop++) // diamond
        {
            for (i=0;i<y;i++)
            {
                printf(" ");
            }
            y--;

            for (s=0;s<2*n-1;s++)
            {
                printf("*");
            }

            while (c<col)
            {
                for (ctop=1;ctop<=m;ctop++)//
                {//

                    printf(" ");//
                }//

                for(s=0;s<2*n-1;s++)
                {
                     printf("*");
                }
                c++;
            }
            n++;
            m = m-2;
            c = 1;
            printf("\n");
        }



            y = leng;
            m = 3;
            for (lbot=1;lbot<=leng/2;lbot++)
            {
                for (i=1;i<=x;i++)
                {
                    printf(" ");
                }
                x++;

                for (s=0;s<y-2;s++)
                {
                    printf("*");
                }
                 while (c<col)
                {
                    for (ctop=1;ctop<=m;ctop++)//
                    {//

                            printf(" ");//
                    }//

                    for(s=0;s<y-2;s++)
                    {
                         printf("*");
                    }
                    c++;
                }
                m = m+2;
                c = 1;
                y = y-2;
                printf("\n");
            }
        x=1;
        n=1;
        printf("\n");
    }

    return 0;
}
