#include <stdio.h>
#include <stdlib.h>
//�䤽�]�ƻ��j��
int devide(int n,int m)
{
    if(!m)
    {
        return n;
    }
    return devide(m,n%m);
}
//���l/����
    struct fraction
    {
        int frac;
        int deno;
    };
    //�[�k��
    struct fraction add_fraction(struct fraction e1,struct fraction e2)
    {
        struct fraction result;
        result.frac= e1.frac* e2.deno+ e2.frac* e1.deno;
        result.deno= e1.deno* e2.deno;
        //��X���]��
        int factor=devide(result.frac,result.deno);
        //���H���]�ƨӬ���
        result.frac=result.frac/factor;
        result.deno=result.deno/factor;
        return result;

    };
    //��k��,�P�[�k���j�P�p�P
    struct fraction min_fraction(struct fraction e1,struct fraction e2)
    {
        struct fraction result;
        result.frac= e1.frac* e2.deno- e2.frac* e1.deno;
        result.deno= e1.deno* e2.deno;
        int factor=devide(result.frac,result.deno);
        result.frac=result.frac/factor;
        result.deno=result.deno/factor;
        return result;
    };
    //���k��,�P�[�k���j�P�p�P
    struct fraction multi_fraction(struct fraction e1,struct fraction e2)
    {
        struct fraction result;
        result.frac= e1.frac* e2.frac;
        result.deno= e1.deno* e2.deno;
        int factor=devide(result.frac,result.deno);
        result.frac=result.frac/factor;
        result.deno=result.deno/factor;
        return result;
    };
    //���k��,�P�[�k���j�P�p�P
    struct fraction dvid_fraction(struct fraction e1,struct fraction e2)
    {
        struct fraction result;
        result.frac= e1.deno* e2.frac;
        result.deno= e1.frac* e2.deno;
        int factor=devide(result.frac,result.deno);
        result.frac=result.frac/factor;
        result.deno=result.deno/factor;
        return result;
    };
    //�L�X���ת��Ƶ{��
    void print(int num_1,int num_2,int num_3,int num_4,int a, int b,char temp)//a�O���l,b�O����
    {
        if((((a)*(b)<0)||(b<0))&&(temp!='-'))//�Y���l*�����p��s�Τ����p��s, �᭱�Ode�t����bug
        {
            a*=-1;
            b*=-1;
        }
        if(temp=='-')//�Y���l�M�������O�t��
        {
            if(b<a)
                a*=-1;
            b*=-1;

        }
        if((a>0)&&(b<0))//����l�O�������O�t
        {
            a*=-1;
            b*=-1;
        }
        if((a<0)&&(b<0))
            b*=-1;
        if(b==1)//�p�G���׬O���
        {
            printf("%d/%d %c %d/%d=%d\n\n",num_1,num_2,temp,num_3,num_4,a);
        }
        else//�p�G���׬O����
        {
            printf("%d/%d %c %d/%d= %d/%d\n\n",num_1,num_2,temp,num_3,num_4,a,b);
        }
    }
    int main()
    {
        struct fraction fraction_1,fraction_2,fraction_final;
        int num_1,num_2,num_3,num_4;
        char temp;
        while(1)
        {
            int option=-1;
            printf("���(1.�[/2.��/3.��/4.��/0.���}:");
            scanf("%d",&option);
            if(option==1)
            {
                printf("a/b + c/d�A�п�Ja b c d: ");
                scanf("%d %d %d %d",&num_1,&num_2,&num_3,&num_4);
                getchar();
                if((num_2==0)||(num_4==0))//�������i��0
                {
                    printf("�������i��0\n");
                }
                else
                {
                    //�a�J�Ʀr
                    fraction_1.frac=num_1;
                    fraction_1.deno=num_2;
                    fraction_2.frac=num_3;
                    fraction_2.deno=num_4;
                    fraction_final=add_fraction(fraction_1,fraction_2);
                    temp='+';//�̫�n�L�X�[��
                    print(num_1,num_2,num_3,num_4,fraction_final.frac,fraction_final.deno,temp);
                }
            }
            else if(option==2)
            {
                printf("a/b - c/d�A�п�Ja b c d: ");
                scanf("%d %d %d %d",&num_1,&num_2,&num_3,&num_4);
                getchar();
                if((num_2==0)||(num_4==0))
                {
                    printf("�������i��0\n");
                }
                else
                {
                    fraction_1.frac=num_1;
                    fraction_1.deno=num_2;
                    fraction_2.frac=num_3;
                    fraction_2.deno=num_4;
                    fraction_final=min_fraction(fraction_1,fraction_2);
                    temp='-';//�̫�n�L�X�t��
                    print(num_1,num_2,num_3,num_4,fraction_final.frac,fraction_final.deno,temp);
                }
            }
            else if(option==3)
            {
                printf("a/b * c/d�A�п�Ja b c d: ");
                scanf("%d %d %d %d",&num_1,&num_2,&num_3,&num_4);
                getchar();
                if((num_2==0)||(num_4==0))
                {
                    printf("�������i��0\n");
                }
                else
                {
                    fraction_1.frac=num_1;
                    fraction_1.deno=num_2;
                    fraction_2.frac=num_3;
                    fraction_2.deno=num_4;
                    fraction_final=multi_fraction(fraction_1,fraction_2);
                    temp='*';//�̫�n�L�X����
                     print(num_1,num_2,num_3,num_4,fraction_final.frac,fraction_final.deno,temp);
                }
            }
            else if(option==4)
            {
                printf("a/b / c/d�A�п�Ja b c d: ");
                scanf("%d %d %d %d",&num_1,&num_2,&num_3,&num_4);
                getchar();
                if((num_2==0)||(num_4==0))
                {
                    printf("�������i��0\n\n");
                }
                else if(num_3==0)
                    printf("���Ƥ��i��0\n\n");
                else
                {
                    fraction_1.frac=num_1;
                    fraction_1.deno=num_2;
                    fraction_2.frac=num_3;
                    fraction_2.deno=num_4;
                    fraction_final=dvid_fraction(fraction_1,fraction_2);
                    temp='/';//�̫�n�L�X����
                    print(num_1,num_2,num_3,num_4,fraction_final.deno,fraction_final.frac,temp);
                }
            }
            else if(option==0)
            {
                return 0;
            }
            else
            {
                printf("��J���~\n");
            }
        }
    }
