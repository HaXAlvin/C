#include <stdio.h>
#include <stdlib.h>

int main()
{
    int diagonal,row1,row2;//�﨤�u/��/�C
    int i,j,n,a,m,k,l;//for�̭����ܼ�

    while(1)//�﨤�u���ת��j��
    {
        printf("��J�٧ι﨤�u����:(3�B5�B7�B9): ");
        scanf("%d",&diagonal);
        if(diagonal!=3&&diagonal!=5&&diagonal!=7&&diagonal!=9)//���~
        {
            printf("��J���~\n");
        }
        if(diagonal==3||diagonal==5||diagonal==7||diagonal==9)//���T
        {
            break;
        }
    }
    while(1)//��ƪ��j��
    {
        printf("��J���(2~10): ");
        scanf("%d",&row1);
        if(row1!=2&&row1!=3&&row1!=4&&row1!=5&&row1!=6&&row1!=7&&row1!=8&&row1!=9&&row1!=10)//���~
        {
            printf("��J���~\n");
        }
        if(row1==2||row1==3||row1==4||row1==5||row1==6||row1==7||row1==8||row1==9||row1==10)//���T
        {
            break;
        }
    }
    while(1)//�C�ƪ��j��
    {
        printf("��J�C��(2~10): ");
        scanf("%d",&row2);
        if(row2!=2&&row2!=3&&row2!=4&&row2!=5&&row2!=6&&row2!=7&&row2!=8&&row2!=9&&row2!=10)//���~
        {
            printf("��J���~\n");
        }
        if(row2==2||row2==3||row2==4||row2==5||row2==6||row2==7||row2==8||row2==9||row2==10)//���T
        {
            goto A;//���J�٧�
        }
    }

A://�٧ε{���X
    for(l=1; l<=row2; l++)//�C��
    {
        for(i=1,m=(diagonal-1)/2; i<=(diagonal+1)/2; i++,m--)//�٧ΤW�b��
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
        for(i=1,k=diagonal-2; i<(diagonal+1)/2; i++,k-=2)//�٧ΤU�b��
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
