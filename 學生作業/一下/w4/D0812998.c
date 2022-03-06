#include<stdio.h>
#include<stdlib.h>

struct frac
{
    int son;
    int mom;

};//�]�m�@�ӵ��c�s�J����C�@�Ӥ��Ʃһݭn�������P���l

struct frac neg(struct frac fracAns)
{
    if(fracAns.mom<0)
    {
        fracAns.son*=-1;
        fracAns.mom*=-1;
    }//��ӭt������
     return fracAns;
}//�B�z�t��

struct frac gcd(struct frac fracAns)
{
    int a=fracAns.son;
    int b=fracAns.mom;
    int t;
    while(b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }//��̤j���]�Ƭ���
    fracAns.son/=a;
    fracAns.mom/=a;

    return fracAns;
};

struct frac add(struct frac a,struct frac b)
{
    return neg(gcd( (struct frac){b.mom*a.son+a.mom*b.son ,a.mom*b.mom} ));
}

struct frac sub(struct frac a , struct frac b)
{
    int subson = a.son*b.mom-a.mom*b.son;
    int submom = a.mom*b.mom;//���ƴ�k����
    struct frac ans;
    ans.son = subson;
    ans.mom = submom;
    ans = gcd(ans);
    ans = neg(ans);
    return ans;
}

struct frac mul(struct frac a , struct frac b)
{
    int mulson = a.son*b.son;
    int mulmom = a.mom*b.mom;//���ƭ��k����
    struct frac ans;
    ans.son = mulson;
    ans.mom = mulmom;
    ans = gcd(ans);
    ans = neg(ans);
    return ans;
}



struct frac divi(struct frac a , struct frac b)
{
    int divison = a.son*b.mom;
    int divimom = a.mom*b.son;//���ư��k����
    struct frac ans;
    ans.son = divison;
    ans.mom = divimom;
    ans = gcd(ans);
    ans = neg(ans);
    return ans;
}

int main()
{
    int choose,a,b,c,d;
    char op;
    while(1)
    {
        char ops[] = {'+','-','*','/'};
        printf("���(1.�[/2.��/3.��/4.��/0.���}):");
        scanf("%d",&choose);

        if(choose==0)
        {
            return 0;
        }
        else if (choose<0||choose>4)
        {
            printf("��J���~\n");
            continue;
        }//��J�ƻ���ܬƻ�Ÿ�
        op = ops[choose-1];

        while(1)
        {
            printf("a/b %c c/d , �п�Ja b c d :",op);
            scanf("%d %d %d %d",&a,&b,&c,&d);
            if(choose==4&&(c==0||d==0))
            {
                printf("���Ƥ��i��0\n");
            }
            else if(b==0||d==0)
            {
                printf("�������i��0\n");
            }
            else
            {
                break;
            }//���b
        }

        struct frac frac1 =
        {
            a,b
        };//�]�m�@�ӵ��c�s�J�Ĥ@�Ӥ��ƪ������P���l
        struct frac frac2 =
        {
            c,d
        };//�]�m�@�ӵ��c�s�J�ĤG�Ӥ��ƪ������P���l
        struct frac fracAns;//�]�m�@�ӵ��c�s�J�ĤT�Ӥ��ƪ������P���l
        if(choose==1)
        {
            fracAns = add(frac1 , frac2);
        }
        else if(choose==2)
        {
            fracAns = sub(frac1 , frac2);
        }
        else if(choose==3)
        {
            fracAns = mul(frac1 , frac2);
        }
        else if(choose==4)
        {
            fracAns = divi(frac1 , frac2);
        }//��J�ƻ�]���Ө禡
         printf("%d/%d %c %d/%d ",a,b,op,c,d);
         if(fracAns.mom==1)
         {
             printf("=%d\n",fracAns.son);
         }//�Y�������@,��J���
         else
         {
             printf("=%d / %d\n",fracAns.son,fracAns.mom);
         }

    }
}
