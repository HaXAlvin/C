/*  109�~��  ��T�G�B
        �ĥ|�g�@�~       */
#include<stdio.h>//���Y��
#include<stdlib.h>
int hcf(int n1,int n2)//��̤j���]��
{
    return n2?hcf(n2,n1%n2):n1;
}
struct fraction//�w�q���Ƶ��c
{
    int numerator,denominator;//���l�B����
};
struct fraction reduce(struct fraction result)//����
{
    int gcd = hcf(result.numerator, result.denominator);//��̤j���]��
    result.numerator /= gcd;//���̤j���]��
    result.denominator /= gcd;
    if(result.denominator<0)//�p�G�����p��0
    {
        result.numerator*=-1;//�t�������l
        result.denominator*=-1;
    }
    return result;//�^�ǵ��G
}
struct fraction add(struct fraction num1, struct fraction num2)//�[�k
{
    num1.numerator *= num2.denominator;
    num2.numerator *= num1.denominator;//�q��
    struct fraction result = {num1.numerator + num2.numerator,num1.denominator * num2.denominator};//���Ƶ��G���c
    result = reduce(result);//���G����
    return result;//�^�ǵ��G
}
struct fraction sub(struct fraction num1, struct fraction num2)//��k
{
    num1.numerator *= num2.denominator;
    num2.numerator *= num1.denominator;//�q��
    struct fraction result = {num1.numerator - num2.numerator,num1.denominator * num2.denominator};//���Ƶ��G���c
    result = reduce(result);//���G����
    return result;//�^�ǵ��G
}
struct fraction multi(struct fraction num1, struct fraction num2)//���k
{
    struct fraction result = {num1.numerator*num2.numerator,num1.denominator*num2.denominator};//���ƭ��k���c
    result = reduce(result);//���G����
    return result;//�^�ǵ��G
}
struct fraction divide(struct fraction num1, struct fraction num2)//���k
{
    struct fraction result = {num1.numerator * num2.denominator,num1.denominator * num2.numerator};//���ư��k���c
    result = reduce(result);//���G����
    return result;//�^�ǵ��G
}
int main()
{
    struct fraction num1;//�ŧi���c�ܼ�
    struct fraction num2;
    int n=0;
    while(1)
    {
        printf("���(1.�[/2.��/3.��/4.��/0.���})�G");//��ܤ�r
        scanf("%d",&n);
        if(n==1)//��ܥ[�k
        {
            printf("a/b + c/d�A�п�Ja b c d�G");
            scanf("%d %d %d %d",&num1.numerator,&num1.denominator,&num2.numerator,&num2.denominator);//��J���l����
            if(num1.denominator==0||num2.denominator==0)//�Y������0
            {
                printf("�������i��0\n");
            }
            else
            {
                struct fraction addition = add(num1, num2);//�ŧi�[�k���G���c
                if(addition.denominator==1)//�p�G������1
                {
                    printf("%d/%d + %d/%d = %d\n", num1.numerator,num1.denominator,num2.numerator,num2.denominator,addition.numerator);//�u��ܤ��l
                }
                else
                    printf("%d/%d + %d/%d = %d/%d\n", num1.numerator,num1.denominator,num2.numerator,num2.denominator,addition.numerator,addition.denominator);//��ܵ��G���l����
            }
        }
        if(n==2)//��k
        {
            printf("a/b - c/d�A�п�Ja b c d�G");
            scanf("%d %d %d %d",&num1.numerator,&num1.denominator,&num2.numerator,&num2.denominator);//��J���l����
            if(num1.denominator==0||num2.denominator==0)//�Y������0
            {
                printf("�������i��0\n");
            }
            else
            {
                struct fraction subtraction = sub(num1, num2);//�ŧi��k���G���c
                if(subtraction.denominator==1)//�p�G������1
                {
                    printf("%d/%d - %d/%d = %d\n", num1.numerator,num1.denominator,num2.numerator,num2.denominator,subtraction.numerator);//�u��ܤ��l
                }
                else
                    printf("%d/%d - %d/%d = %d/%d\n", num1.numerator,num1.denominator,num2.numerator,num2.denominator,subtraction.numerator,subtraction.denominator);//��ܵ��G���l����
            }
        }
        if(n==3)//��ܭ��k
        {
            printf("a/b * c/d�A�п�Ja b c d�G");
            scanf("%d %d %d %d",&num1.numerator,&num1.denominator,&num2.numerator,&num2.denominator);//��J���l����
            if(num1.denominator==0||num2.denominator==0)//�Y������0
            {
                printf("�������i��0\n");
            }
            else
            {
                struct fraction multiplication = multi(num1, num2);//�ŧi���k���G���c
                if(multiplication.denominator==1)//�p�G������1
                {
                    printf("%d/%d * %d/%d = %d\n", num1.numerator,num1.denominator,num2.numerator,num2.denominator,multiplication.numerator);//�u��ܤ��l
                }
                else
                    printf("%d/%d * %d/%d = %d/%d\n",num1.numerator,num1.denominator,num2.numerator,num2.denominator,multiplication.numerator,multiplication.denominator);//��ܵ��G���l����
            }
        }
        if(n==4)//��ܰ��k
        {
            printf("a/b / c/d�A�п�Ja b c d�G");
            scanf("%d %d %d %d",&num1.numerator,&num1.denominator,&num2.numerator,&num2.denominator);//��J���l����
            if(num2.numerator==0)//�Y���Ƭ�0
            {
                printf("���Ƥ��i��0\n");
            }
            else if(num1.denominator==0||num2.denominator==0)//�Y������0
            {
                printf("�������i��0\n");
            }
            else
            {
                struct fraction division = divide(num1, num2);//�ŧi���k���G���c
                if(division.denominator==1)//�p�G������1
                {
                    printf("%d/%d / %d/%d = %d\n", num1.numerator,num1.denominator,num2.numerator,num2.denominator,division.numerator);//�u��ܤ��l
                }
                else
                    printf("%d/%d / %d/%d = %d/%d\n",num1.numerator,num1.denominator,num2.numerator,num2.denominator,division.numerator,division.denominator);//��ܵ��G���l����
            }
        }
        if(n<0||n>4)//��ܶW�X�d��
        {
            printf("��J���~\n");
        }
        if(n==0)//������}
        {
            return 0;//�^�Ǩõ����{��
        }
        printf("\n");//�Ť@��
    }
}



