#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int gcd(int m,int n)//最大公因數
{
    while(n != 0)
    {
        int r = m%n;
        m = n;
        n = r;
    }
    return m;
}
struct formula
{
    int numer;//分子
    int deno;//分母
};

struct formula multi(struct formula number1,struct formula number2)//乘
{
    int factor;
    struct formula answer;
    answer.numer = number1.numer * number2.numer;
    answer.deno = number1.deno * number2.deno;
    factor=gcd(answer.numer,answer.deno);//約分
    answer.numer = answer.numer/factor;
    answer.deno = answer.deno/factor;
    return answer;
};
struct formula divide(struct formula number1,struct formula number2)//除
{
    int factor;
    struct formula answer;
    answer.numer = number1.numer * number2.deno;
    answer.deno = number1.deno * number2.numer;
    factor=gcd(answer.numer,answer.deno);
    answer.numer = answer.numer/factor;
    answer.deno = answer.deno/factor;
    return answer;
};
struct formula add(struct formula number1,struct formula number2)//加
{
    int factor;
    struct formula answer;
    answer.numer = number1.numer*number2.deno+number2.numer*number1.deno;
    answer.deno = number1.deno * number2.deno;
    factor=gcd(answer.numer,answer.deno);
    answer.numer = answer.numer/factor;
    answer.deno = answer.deno/factor;

    return answer;
};
struct formula sub(struct formula number1,struct formula number2)//減
{
    int factor;
    struct formula answer;
    answer.numer = number1.numer*number2.deno-number2.numer*number1.deno;
    answer.deno = number1.deno * number2.deno;
    factor=gcd(answer.numer,answer.deno);
    answer.numer = answer.numer/factor;
    answer.deno = answer.deno/factor;
    return answer;
};







int main()
{
    struct formula input1;
    struct formula input2;
    struct formula output;
    int choose;
    while(1)
    {
        printf("請選擇（1.加/2.減/3./乘/4.除/0.離開):");
        scanf("%d",&choose);

        if(choose > 4)//輸入錯誤
        {
            printf("輸入錯誤\n\n");
            continue;
        }
        if(choose == 3 )//若選擇乘法
        {
            printf("a/b * c/d，請輸入a b c d:");
            scanf("%d %d %d %d",&input1.numer,&input1.deno,&input2.numer,&input2.deno);
            if(input1.deno == 0 || input2.deno == 0)
            {
                printf("分母不可為0\n");
            }
            else
            {
                output = multi(input1,input2);
                if(output.deno<0)//負負得正或負號移到分子
                {
                output.numer=output.numer*(-1);
                output.deno=output.deno*(-1);
                }
                if(output.deno == 1)//若為整數寫成整數
                {
                    printf("%d/%d * %d/%d = %d\n",input1.numer,input1.deno,input2.numer,input2.deno,output.numer);
                }
                else
                {
                    printf("%d/%d * %d/%d = %d/%d\n",input1.numer,input1.deno,input2.numer,input2.deno,output.numer,output.deno);
                }
            }
        }
        if(choose == 4 )//若選擇除法
        {
            printf("a/b / c/d，請輸入a b c d:");
            scanf("%d %d %d %d",&input1.numer,&input1.deno,&input2.numer,&input2.deno);
            if(input1.deno == 0 || input2.deno == 0)
            {
                printf("分母不可為0\n");
                continue;
            }
            if(input1.numer == 0 || input2.numer == 0)
            {
                printf("除數不可為0\n");
            }
            else
            {
                output = divide(input1,input2);
                if(output.deno<0)
                {
                output.numer=output.numer*(-1);
                output.deno=output.deno*(-1);
                }
                if(output.deno == 1)
                {
                    printf("%d/%d / %d/%d = %d\n",input1.numer,input1.deno,input2.numer,input2.deno,output.numer);
                }
                else
                {
                    printf("%d/%d / %d/%d = %d/%d\n",input1.numer,input1.deno,input2.numer,input2.deno,output.numer,output.deno);
                }
            }


        }
        if(choose == 1)//若選擇加法
        {
            printf("a/b + c/d，請輸入a b c d:");
            scanf("%d %d %d %d",&input1.numer,&input1.deno,&input2.numer,&input2.deno);
            if(input1.deno == 0 || input2.deno == 0)
            {
                printf("分母不可為0\n");
            }
            else
            {
                output = add(input1,input2);
                if(output.deno<0)
                {
                output.numer=output.numer*(-1);
                output.deno=output.deno*(-1);
                }
                if(output.deno == 1)
                {
                    printf("%d/%d + %d/%d = %d\n",input1.numer,input1.deno,input2.numer,input2.deno,output.numer);
                }
                else
                {
                    printf("%d/%d + %d/%d = %d/%d\n",input1.numer,input1.deno,input2.numer,input2.deno,output.numer,output.deno);
                }
            }
        }
        if(choose == 2)//若選擇減法
        {
            printf("a/b - c/d，請輸入a b c d:");
            scanf("%d %d %d %d",&input1.numer,&input1.deno,&input2.numer,&input2.deno);
            if(input1.deno == 0 || input2.deno == 0)
            {
                printf("分母不可為0\n");
            }
            else
            {
                output = sub(input1,input2);
                if(output.deno<0)
                {
                output.numer=output.numer*(-1);
                output.deno=output.deno*(-1);
                }
                if(output.deno == 1)
                {
                    printf("%d/%d - %d/%d = %d\n",input1.numer,input1.deno,input2.numer,input2.deno,output.numer);
                }
                else
                {
                    printf("%d/%d - %d/%d = %d/%d\n",input1.numer,input1.deno,input2.numer,input2.deno,output.numer,output.deno);
                }
            }
        }
        if(choose == 0)//離開
            break;

    }
}


