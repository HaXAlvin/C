#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//為了約分，需要使用最大公因數
int GCF/*最大公因數*/(int integer1/*整數1*/, int integer2/*整數2*/)
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
    int molecule/*分子*/,denominator/*分母*/;
};

//寫出乘法的副函式
struct function times/*乘法*/(struct function input1/*結構1*/,struct function input2/*結構2*/)
{
    struct function answer;
    //運算答案分子=結構1分子*結構2分子
    answer.molecule=input1.molecule*input2.molecule;
    //運算答案分母=結構1分母*結構2分母
    answer.denominator=input1.denominator*input2.denominator;
    //int一個變數去紀錄最大公因數的值
    int solution=GCF(answer.molecule,answer.denominator);
    //讓答案分子/最大公因數，藉此約分
    answer.molecule=answer.molecule/solution;
    //讓答案分母/最大公因數，藉此約分
    answer.denominator=answer.denominator/solution;
    //回傳
    return answer;
};

//寫出除法的副函式
struct function divided(struct function input1,struct function input2)
{
    struct function answer;
    //運算答案分子=結構1分子*結構2分母
    answer.molecule=input1.molecule*input2.denominator;
    //運算答案分母=結構1分母*結構2分子
    answer.denominator=input1.denominator*input2.molecule;
    //int一個變數去紀錄最大公因數的值
    int solution=GCF(answer.molecule,answer.denominator);
    //讓答案分子/最大公因數，藉此約分
    answer.molecule=answer.molecule/solution;
    //讓答案分母/最大公因數，藉此約分
    answer.denominator=answer.denominator/solution;
    //回傳
    return answer;
};

//寫出加法的副函式
struct function plus(struct function input1,struct function input2)
{
    struct function answer;
    //運算答案分子=(結構1分子*結構2分母)+(結構1分母*結構2分子)，藉此通分
    answer.molecule=input1.molecule*input2.denominator+input1.denominator*input2.molecule;
    //運算答案分母=(結構1分母*結構2分母)，藉此通分
    answer.denominator=input1.denominator*input2.denominator;
    //int一個變數去紀錄最大公因數的值
    int solution=GCF(answer.molecule,answer.denominator);
    //讓答案分子/最大公因數，藉此約分
    answer.molecule=answer.molecule/solution;
     //讓答案分母/最大公因數，藉此約分
    answer.denominator=answer.denominator/solution;
    //回傳
    return answer;
};

//寫出減法的副函式
struct function minus(struct function input1,struct function input2)
{
    struct function answer;
    //運算答案分子=(結構1分子*結構2分母)-(結構1分母*結構2分子)，藉此通分
    answer.molecule=input1.molecule*input2.denominator-input1.denominator*input2.molecule;
    //運算答案分母=(結構1分母*結構2分母)，藉此通分
    answer.denominator=input1.denominator*input2.denominator;
    //int一個變數去紀錄最大公因數的值
    int solution=GCF(answer.molecule,answer.denominator);
    //讓答案分子/最大公因數，藉此約分
    answer.molecule=answer.molecule/solution;
    //讓答案分母/最大公因數，藉此約分
    answer.denominator=answer.denominator/solution;
    //回傳
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
        /*還沒考慮整數的狀況*/
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
        scanf("%d",&choose);
        //防呆
        if((choose<0)||(choose>4))
        {
            printf("輸入錯誤\n\n");
        }
        //結束程式
        if(choose==0)
        {
            return 0;
        }
        //加法
        if(choose==1)
        {
            printf("a/b + c/d，請輸入a b c d : ");
            scanf("%d %d %d %d",&fraction1.molecule,&fraction1.denominator,&fraction2.molecule,&fraction2.denominator);
            //讓solution紀錄加法副函式的值
            solution=plus(fraction1,fraction2);
            printf("%d/%d + %d/%d = %d/%d\n\n",fraction1.molecule,fraction1.denominator,fraction2.molecule,fraction2.denominator,solution.molecule,solution.denominator);
        }
        //減法
        if(choose==2)
        {
            printf("a/b - c/d，請輸入a b c d : ");
            scanf("%d %d %d %d",&fraction1.molecule,&fraction1.denominator,&fraction2.molecule,&fraction2.denominator);
            //讓solution紀錄減法副函式的值
            solution=minus(fraction1,fraction2);
            //若答案能整除，顯示整數
            if(solution.molecule%solution.denominator==0)
            {
                printf("%d/%d / %d/%d = %d\n\n",fraction1.molecule,fraction1.denominator,fraction2.molecule,fraction2.denominator,solution.molecule/solution.denominator);
            }
            //答案不能整除，以分數形式呈現
            else
            {
                printf("%d/%d / %d/%d = %d/%d\n\n",fraction1.molecule,fraction1.denominator,fraction2.molecule,fraction2.denominator,solution.molecule,solution.denominator);
            }
        }
        //乘法
        if(choose==3)
        {
            printf("a/b * c/d，請輸入a b c d : ");
            scanf("%d %d %d %d",&fraction1.molecule,&fraction1.denominator,&fraction2.molecule,&fraction2.denominator);
            //讓solution紀錄乘法副函式的值
            solution=times(fraction1,fraction2);
            //若答案之分母為負數，讓負號顯示在分子位置
            if(solution.denominator<0)
            {
                printf("%d/%d * %d/%d = %d/%d\n\n",fraction1.molecule,fraction1.denominator,fraction2.molecule,fraction2.denominator,solution.molecule/-1,solution.denominator/-1);
            }
            else
            {
                printf("%d/%d * %d/%d = %d/%d\n\n",fraction1.molecule,fraction1.denominator,fraction2.molecule,fraction2.denominator,solution.molecule,solution.denominator);
            }
        }
        //除法
        if(choose==4)
        {
            printf("a/b / c/d，請輸入a b c d : ");
            scanf("%d %d %d %d",&fraction1.molecule,&fraction1.denominator,&fraction2.molecule,&fraction2.denominator);
            //防呆
            if(fraction2.molecule==0)
            {
                printf("除數不可為0\n\n");
            }
            //防呆
            else if((fraction1.denominator==0)||(fraction2.denominator==0))
            {
                printf("分母不可為0\n\n");
            }
            else
            {
                ////讓solution紀錄除法副函式的值
                solution=divided(fraction1,fraction2);
                //若答案能整除，顯示整數
                if(solution.molecule%solution.denominator==0)
                {
                    printf("%d/%d / %d/%d = %d\n\n",fraction1.molecule,fraction1.denominator,fraction2.molecule,fraction2.denominator,solution.molecule/solution.denominator);
                }
                //答案不能整除，以分數形式呈現
                else
                {
                    //若答案之分母為負數，讓負號顯示在分子位置
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
