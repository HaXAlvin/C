/*  109�~��  ��T�G�B
        �ĤG�g�@�~       */
#include<stdio.h>//���Y��
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[100];//�ŧi�ܼ�
    int n=0,lon=0,sum=0;
    int num=10;
    char **ptr;//�ʺA�}�C
    ptr=malloc(num*sizeof(char*));//�إ߲Ĥ@���}�C�A�j�p��10


    printf("1.�s�W"
           "2.�L�X"
           "3.�Ƨ�"
           "4.���}\n");//�L�X��r

    while(scanf("%d",&n))
    {
        getchar();
        if(n==1)//�s�W
        {
            gets(str);//��J�r��
            lon=strlen(str);//�p��r�����
            lon++;//�[�W'\0'
            if(sum>=num)//�p�G�ݭn�s�W�}�C
            {
                printf("dddddd");
                ptr=realloc(ptr,(num+5)*sizeof(char*));//�s�W�}�C�A�C���s�W5��
                num=num+5;
            }
            ptr[sum]=calloc(lon,sizeof(char));//�ھڦr����׷s�W�ĤG���}�C

            for(int i=0; i<lon; i++)//����lon��
            {
                ptr[sum][i]=str[i];//��ȵ��}�C
            }
            for(int i=0; i<100; i++)//�N��J���}�C�M��
            {
                str[i]=0;
            }
            sum++;//�ܼ�+1
        }
        if(n==2)//�L�X
        {
            for(int i=0; i<sum; i++)
            {
                puts(ptr[i]);//�̷Ӷ��ǦL�X
            }

        }
        if(n==3)//�Ƨ�
        {
            for(int i=sum;i>0;i--)//�w�j�ƧǪk
            {
                for(int j=0;j<i-1;j++)

                {
                    if(strcmp(ptr[j],ptr[j+1])>0)//strcmp�����Ӱ}�C
                    {
                        char *temp=ptr[j];
                        ptr[j]=ptr[j+1];
                        ptr[j+1]=temp;
                    }
                }
            }

        }
        if(n==4)//���}
        {
            for(int i=0;i<sum;i++)
            {
                free(ptr[i]);//����ĤG���}�C
            }
            free(ptr);//����Ĥ@���}�C
            return 0;//�����æ^��

        }
    }
}
