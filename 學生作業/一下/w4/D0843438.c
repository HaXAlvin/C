#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct _fraction//�w�q���ƫ��A
{
    int numerator,denominator;
};
typedef struct _fraction fraction;

fraction contract(fraction a)//����
{
    if(a.numerator%a.denominator==0)//�㰣
    {
        a.numerator=a.numerator/a.denominator;
        a.denominator=1;
    }
    else//����
    {
        int i=2;
        while(i<=fabs(a.numerator)&&i<=fabs(a.denominator))
        {
            while(a.numerator%i==0&&a.denominator%i==0)
            {
                a.numerator=a.numerator/i;
                a.denominator=a.denominator/i;
            }
            i++;
        }
    }
    if(a.denominator<0)//�����Ƭ���
    {
        a.numerator=-a.numerator;
        a.denominator=-a.denominator;
    }
    return a;
}
fraction add(fraction a,fraction b)//�[�k
{
    fraction c={a.numerator*b.denominator+b.numerator*a.denominator,a.denominator*b.denominator};
    return contract(c);
}
fraction sub(fraction a,fraction b)//��k
{
    fraction c={a.numerator*b.denominator-b.numerator*a.denominator,a.denominator*b.denominator};
    return contract(c);
}
fraction multi(fraction a,fraction b)//���k
{
    fraction c={a.numerator*b.numerator,a.denominator*b.denominator};
    return contract(c);
}
fraction divide(fraction a,fraction b)//���k
{
    fraction c={a.numerator*b.denominator,a.denominator*b.numerator};
    return contract(c);
}
int main()//�D�{��
{
    int system,a,b,c,d;
    char sign[4]={'+','-','*','/'};
    fraction (*function[4])(fraction,fraction)={add,sub,multi,divide};
    while(1)//�t��
    {
        printf("���(1.�[/2.��/3.��/4.��/0.���}):");
        scanf("%d",&system);
        if(system==0)//���}
        {
            return 0;
        }
        else if(system==1||system==2||system==3||system==4)//�p��
        {
            printf("a/b %c c/d�A�п�Ja b c d:",sign[system-1]);
            scanf("%d %d %d %d",&a,&b,&c,&d);
            if(system==4&&c==0)//���b(���Ƭ�0)
            {
                printf("���Ƥ��i��0\n\n");
            }
            else if(b==0||d==0)//���b(������0)
            {
                printf("�������i��0\n\n");
            }
            else
            {
                fraction input1={a,b};
                fraction input2={c,d};
                fraction output=function[system-1](input1,input2);
                printf("%d/%d %c %d/%d = ",a,b,sign[system-1],c,d);
                if(output.denominator==1)//�㰣
                {
                    printf("%d\n\n",output.numerator);
                }
                else//�D�㰣
                {
                    printf("%d/%d\n\n",output.numerator,output.denominator);
                }
            }
        }
        else//���b
        {
            printf("��J���~\n\n");
        }
    }
}
