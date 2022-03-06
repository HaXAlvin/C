#include <stdio.h>

int main()
{
    int height=0,row=0,columns=0;
    int loopc,loopr,blank;
    int b,a=1;


    while(height !=3 && height !=5 && height !=7 && height !=9)
    {
        printf("Enter Rhombus Range(3,5,7,9):");
        scanf("%d",&height);
        if(height !=3 && height !=5 && height !=7 && height !=9)
        {
            printf("Error:Enter Again\n");
        }

    }
    while(!(row >=2 && row <=10))
    {
        printf("Enter Row(2~10):");
        scanf("%d",&row);
        if(!(row >=2 && row <=10))
        {
            printf("Error:Enter Again\n");
        }
    }
    while(!(columns >=2 && columns <=10))
    {
        printf("Enter Columns(2~10):");
        scanf("%d",&columns);
        if(!(columns >=2 && columns <=10))
        {
            printf("Error:Enter Again\n");
        }
    }
    printf("\n");
    for(loopc=1 ; loopc<=columns ; loopc++)
    {
        while(height >= a)//top to center
        {
            for(loopr=1 ; loopr<=row ; loopr++)
            {
                blank=(height - a)/2;
                for(b=1 ; b<=blank ; b++)
                {
                    printf(" ");
                }
                for(b=1 ; b<=a ; b++)
                {
                    printf("*");
                }
                for(b=1 ; b<=blank ; b++)
                {
                    printf(" ");
                }
                printf(" ");
            } // for loop end
            printf("\n");
            a += 2;
        }// while end
        a -= 4;
        printf("%d\n",a);
        while(a >= 1)
        {
            for(loopr=1 ; loopr<=row ; loopr++)
            {
                blank=(height - a)/2;
                for(b=1 ; b<=blank ; b++)
                {
                    printf(" ");
                }
                for(b=1 ; b<=a ; b++)
                {
                    printf("*");
                }
                for(b=1 ; b<=blank ; b++)
                {
                    printf(" ");
                }
                printf(" ");
            }// bottom loop end
            printf("\n");
            a -= 2;
        }//while
        printf("\n");
    }//first for end
} //main
