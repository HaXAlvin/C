#include<stdio.h>

int main()
{
    int c; //��           Column
    int r; //�C           Row
    int l; //�﨤�u����  length
    int j;
    int k;
    int i;
    int z;
    printf("��J�٧ι﨤�u����(3�B5�B7�B9):");
    scanf ("%d%*c",&l);
    while(l!=3&&l!=5&&l!=7&&l!=9)
    {
        printf("��J���~!\n");
        printf("��J�٧ι﨤�u����(3�B5�B7�B9):");
        scanf ("%d%*c",&l);
    }
    printf("��J���(2~10):");
    scanf ("%d%*c",&c);
    while(c<2||c>10)
    {
        printf("��J���~!\n");
        printf("��J���(2~10):");
        scanf ("%d%*c",&c);
    }
    printf("��J�C��(2~10):");
    scanf ("%d%*c",&r);
    while(r<2||r>10)
    {
        printf("��J���~!\n");
        printf("��J���(2~10):");
        scanf ("%d%*c",&r);
    }
    printf("\n"); //�C�Ƹ�٧Ϊ��Ů� 
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
