#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));
    int i,j,num[4];
    int ans[4];
    int scan;
    int TRUE=1,FALSE=0;
    int o;
    int A,B;

    for(i=0; i<4; i++) // �H���X4��ƪ��ü�
    {
        do
        {
            num[i]= rand()%10;
            for(j=0; j<i; j++)
            {
                if(num[i]==num[j])
                {
                    break;
                }
            }
        }
        while(j!=i);
    }
    for(int i=0;i<4;i++){
            printf("%d",num[i]);
        }
        puts("");
    do   // �}�l�C��
    {
        printf(">>");
        scanf("%d",&scan);
        ans[0]=scan/1000;  //�Ĥ@���
        ans[1]=scan/100%10;//�ĤG���
        ans[2]=scan/10%10; //�ĤT���
        ans[3]=scan%10;     //�ĥ|���

        for(i=0; o=FALSE; i++)
        {
            for(j=0; j<i; j++)
            {
                if(i!=j && ans[i]==ans[j])// �˴����S������
                {
                    printf("INPUT ERROR");
                    o=TRUE;
                    break;
                }

            }
            if(o=TRUE)
            {
                break;
            }
        }
        if(o)
        {
            continue;
        }
        A=B=0;
        for(i=0; i<4; i++)
        {
            if(num[i]==ans[i])
            {
                A++;
            }
            else
            {
                for(j=0; j<4; j++)
                {
                    if(num[i]==ans[j])
                    {
                        B++;
                    }
                }

            }
        }
        printf("%dA%dB",A,B);
    }while(1);
    if(A==4);
    {
        printf("YOU WIN");
    }
}
