/*  109�~��  ��T�G�B
        �ĤT�g�@�~       */
#include<stdio.h>//���Y��
#include<stdlib.h>
int add(int a, int b) //�[�k
{
    return a+b;//�^�ǭ�
}
int sub(int a, int b) //��k
{
    return a-b;
}
int multi(int a, int b) //���k
{
    return a*b;
}
int divide(int a, int b) //���k
{
    return a/b;
}
int mod(int a, int b) //���l��
{
    return a%b;
}
int main()
{
    int n=0,a=0,b=0;//�ŧi�ܼ�
    int (*opt[])(int,int)= {add,sub,multi,divide,mod};//�x�s�禡���а}�C

    while(1)
    {
        printf("�п��(1.�a�k/2.��k/3.���k/4.���k/5.���l��/0.���})�G");//��ܤ�r
        scanf("%d",&n);

        if(n==1)//��ܥ[�k
        {
            printf("�п�J��Ӿ�ơG");
            scanf("%d %d",&a,&b);
            printf("%d + %d = %d\n",a,b,opt[0](a,b));
        }
        if(n==2)//��ܴ�k
        {
            printf("�п�J��Ӿ�ơG");
            scanf("%d %d",&a,&b);
            printf("%d - %d = %d\n",a,b,opt[1](a,b));
        }
        if(n==3)//��ܭ��k
        {
            printf("�п�J��Ӿ�ơG");
            scanf("%d %d",&a,&b);
            printf("%d * %d = %d\n",a,b,opt[2](a,b));
        }
        if(n==4)//��ܰ��k
        {
            printf("�п�J��Ӿ�ơG");
            scanf("%d %d",&a,&b);
            printf("%d / %d = %d\n",a,b,opt[3](a,b));
        }
        if(n==5)//��ܨ��l��
        {
            printf("�п�J��Ӿ�ơG");
            scanf("%d %d",&a,&b);
            printf("%d %% %d = %d\n",a,b,opt[4](a,b));
        }
        if(n==0)//������}
        {
            return 0;
        }

    }
}
