#include <stdbool.h>
#include <stdio.h>
int main()
{   int Length,Rows,Column;
    do{//��dowhile�P�_�O�_���~�٦����ƿ�J
    printf("��J�٧ι﨤�u���ס]3�B5�B7�B9�^�G");
    scanf("%d",&Length);
    if(Length!=3&&Length!=5&&Length!=7&&Length!=9)
    {
        printf("��J���~!\n");
    }
    }while(Length!=3&&Length!=5&&Length!=7&&Length!=9) ;
    do{//��dowhile�P�_�O�_���~�٦����ƿ�J
    printf("��J��ơ]2 ~ 10�^�G");
    scanf("%d",&Rows);
    if(Rows<2||Rows>10)
    {
        printf("��J���~!\n");
    }
    }while(Rows<2||Rows>10) ;
    do{//��dowhile�P�_�O�_���~�٦����ƿ�J
    printf("��J�C�ơ]2 ~ 10�^�G");
    scanf("%d",&Column);
    if(Column<2||Column>10)
    {
        printf("��J���~!\n");
    }
    }while(Column<2||Column>10) ;
    int Space=Length-2;
    int whiK=1;
    bool MaxLen=false;
    for(int i=0;i<Rows;i++)//��X��
    {   whiK=1;
        MaxLen=false;
        while(whiK>0)
        {
            for(int j=1;j<=Column;j++)//��X�C
            {
                Space=(Length-whiK)/2;//��Ů��
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
                    MaxLen=true;//��bool�s�O�_�[��W�L�٧Ϊ���
                }
            }
            else if(MaxLen)//���U�Ӵ�^��
            {
                whiK-=2;
                if(whiK<=0)
                    break;
            }
        }
        puts("");
    }
}
