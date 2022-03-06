#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int multi(int a, int b)
{
    return a*b;
}

int divide(int a, int b)
{
    return a/b;
}

int mod(int a, int b)
{
    return a%b;
}

int main()
{
    int (*opt[5])(int,int)={add,sub,multi,divide,mod};
    int a,b,choose;
    while(1)
    {
        printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}):");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                scanf("%d %d",&a,&b);
                printf("%d + %d = %d\n",a,b,opt[0](a,b));
                break;
            case 2:
                scanf("%d %d",&a,&b);
                printf("%d - %d = %d\n",a,b,opt[1](a,b));
                break;
            case 3:
                scanf("%d %d",&a,&b);
                printf("%d * %d = %d\n",a,b,opt[2](a,b));
                break;
            case 4:
                scanf("%d %d",&a,&b);
                printf("%d / %d = %d\n",a,b,opt[3](a,b));
                break;
            case 5:
                scanf("%d %d",&a,&b);
                printf("%d %% %d = %d\n",a,b,opt[4](a,b));
                break;
            case 0:
                return 0;
        }
    }

}
