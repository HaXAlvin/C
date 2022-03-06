#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���F�����A�ݭn�ϥγ̤j���]��
int GCF/*�̤j���]��*/(int integer1/*���1*/, int integer2/*���2*/)
{
    int i;
    while(integer1%integer2!=0)
    {
        i=integer2;
        integer2=integer1%integer2;
        integer1=i;
    }
    return integer2;
}

struct function
{
    int molecule/*���l*/,denominator/*����*/;
};

//�g�X���k���ƨ禡
struct function times/*���k*/(struct function input1/*���c1*/,struct function input2/*���c2*/)
{
    struct function answer;
    //�B�⵪�פ��l=���c1���l*���c2���l
    answer.molecule=input1.molecule*input2.molecule;
    //�B�⵪�פ���=���c1����*���c2����
    answer.denominator=input1.denominator*input2.denominator;
    //int�@���ܼƥh�����̤j���]�ƪ���
    int solution=GCF(answer.molecule,answer.denominator);
    //�����פ��l/�̤j���]�ơA�Ǧ�����
    answer.molecule=answer.molecule/solution;
    //�����פ���/�̤j���]�ơA�Ǧ�����
    answer.denominator=answer.denominator/solution;
    //�^��
    return answer;
};

//�g�X���k���ƨ禡
struct function divided(struct function input1,struct function input2)
{
    struct function answer;
    //�B�⵪�פ��l=���c1���l*���c2����
    answer.molecule=input1.molecule*input2.denominator;
    //�B�⵪�פ���=���c1����*���c2���l
    answer.denominator=input1.denominator*input2.molecule;
    //int�@���ܼƥh�����̤j���]�ƪ���
    int solution=GCF(answer.molecule,answer.denominator);
    //�����פ��l/�̤j���]�ơA�Ǧ�����
    answer.molecule=answer.molecule/solution;
    //�����פ���/�̤j���]�ơA�Ǧ�����
    answer.denominator=answer.denominator/solution;
    //�^��
    return answer;
};

//�g�X�[�k���ƨ禡
struct function plus(struct function input1,struct function input2)
{
    struct function answer;
    //�B�⵪�פ��l=(���c1���l*���c2����)+(���c1����*���c2���l)�A�Ǧ��q��
    answer.molecule=input1.molecule*input2.denominator+input1.denominator*input2.molecule;
    //�B�⵪�פ���=(���c1����*���c2����)�A�Ǧ��q��
    answer.denominator=input1.denominator*input2.denominator;
    //int�@���ܼƥh�����̤j���]�ƪ���
    int solution=GCF(answer.molecule,answer.denominator);
    //�����פ��l/�̤j���]�ơA�Ǧ�����
    answer.molecule=answer.molecule/solution;
     //�����פ���/�̤j���]�ơA�Ǧ�����
    answer.denominator=answer.denominator/solution;
    //�^��
    return answer;
};

//�g�X��k���ƨ禡
struct function minus(struct function input1,struct function input2)
{
    struct function answer;
    //�B�⵪�פ��l=(���c1���l*���c2����)-(���c1����*���c2���l)�A�Ǧ��q��
    answer.molecule=input1.molecule*input2.denominator-input1.denominator*input2.molecule;
    //�B�⵪�פ���=(���c1����*���c2����)�A�Ǧ��q��
    answer.denominator=input1.denominator*input2.denominator;
    //int�@���ܼƥh�����̤j���]�ƪ���
    int solution=GCF(answer.molecule,answer.denominator);
    //�����פ��l/�̤j���]�ơA�Ǧ�����
    answer.molecule=answer.molecule/solution;
    //�����פ���/�̤j���]�ơA�Ǧ�����
    answer.denominator=answer.denominator/solution;
    //�^��
    return answer;
};

int main()
{
    int choose;
    struct function solution;
    struct function fraction1;
    struct function fraction2;
    while(1)
    {
        /*�٨S�Ҽ{��ƪ����p*/
        printf("���(1.�[/2.��/3.��/4.��/0.���}):");
        scanf("%d",&choose);
        //���b
        if((choose<0)||(choose>4))
        {
            printf("��J���~\n\n");
        }
        //�����{��
        if(choose==0)
        {
            return 0;
        }
        //�[�k
        if(choose==1)
        {
            printf("a/b + c/d�A�п�Ja b c d : ");
            scanf("%d %d %d %d",&fraction1.molecule,&fraction1.denominator,&fraction2.molecule,&fraction2.denominator);
            //��solution�����[�k�ƨ禡����
            solution=plus(fraction1,fraction2);
            printf("%d/%d + %d/%d = %d/%d\n\n",fraction1.molecule,fraction1.denominator,fraction2.molecule,fraction2.denominator,solution.molecule,solution.denominator);
        }
        //��k
        if(choose==2)
        {
            printf("a/b - c/d�A�п�Ja b c d : ");
            scanf("%d %d %d %d",&fraction1.molecule,&fraction1.denominator,&fraction2.molecule,&fraction2.denominator);
            //��solution������k�ƨ禡����
            solution=minus(fraction1,fraction2);
            //�Y���ׯ�㰣�A��ܾ��
            if(solution.molecule%solution.denominator==0)
            {
                printf("%d/%d / %d/%d = %d\n\n",fraction1.molecule,fraction1.denominator,fraction2.molecule,fraction2.denominator,solution.molecule/solution.denominator);
            }
            //���פ���㰣�A�H���ƧΦ��e�{
            else
            {
                printf("%d/%d / %d/%d = %d/%d\n\n",fraction1.molecule,fraction1.denominator,fraction2.molecule,fraction2.denominator,solution.molecule,solution.denominator);
            }
        }
        //���k
        if(choose==3)
        {
            printf("a/b * c/d�A�п�Ja b c d : ");
            scanf("%d %d %d %d",&fraction1.molecule,&fraction1.denominator,&fraction2.molecule,&fraction2.denominator);
            //��solution�������k�ƨ禡����
            solution=times(fraction1,fraction2);
            //�Y���פ��������t�ơA���t����ܦb���l��m
            if(solution.denominator<0)
            {
                printf("%d/%d * %d/%d = %d/%d\n\n",fraction1.molecule,fraction1.denominator,fraction2.molecule,fraction2.denominator,solution.molecule/-1,solution.denominator/-1);
            }
            else
            {
                printf("%d/%d * %d/%d = %d/%d\n\n",fraction1.molecule,fraction1.denominator,fraction2.molecule,fraction2.denominator,solution.molecule,solution.denominator);
            }
        }
        //���k
        if(choose==4)
        {
            printf("a/b / c/d�A�п�Ja b c d : ");
            scanf("%d %d %d %d",&fraction1.molecule,&fraction1.denominator,&fraction2.molecule,&fraction2.denominator);
            //���b
            if(fraction2.molecule==0)
            {
                printf("���Ƥ��i��0\n\n");
            }
            //���b
            else if((fraction1.denominator==0)||(fraction2.denominator==0))
            {
                printf("�������i��0\n\n");
            }
            else
            {
                ////��solution�������k�ƨ禡����
                solution=divided(fraction1,fraction2);
                //�Y���ׯ�㰣�A��ܾ��
                if(solution.molecule%solution.denominator==0)
                {
                    printf("%d/%d / %d/%d = %d\n\n",fraction1.molecule,fraction1.denominator,fraction2.molecule,fraction2.denominator,solution.molecule/solution.denominator);
                }
                //���פ���㰣�A�H���ƧΦ��e�{
                else
                {
                    //�Y���פ��������t�ơA���t����ܦb���l��m
                    if(solution.denominator<0)
                    {
                        printf("%d/%d * %d/%d = %d/%d\n\n",fraction1.molecule,fraction1.denominator,fraction2.molecule,fraction2.denominator,solution.molecule/-1,solution.denominator/-1);
                    }
                    else
                    {
                        printf("%d/%d * %d/%d = %d/%d\n\n",fraction1.molecule,fraction1.denominator,fraction2.molecule,fraction2.denominator,solution.molecule,solution.denominator);
                    }
                }
            }
        }
    }
    return 0;
}
