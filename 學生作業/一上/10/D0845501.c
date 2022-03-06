#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Make_a_question(int ans[],int result)
{
    srand(time(NULL));
    for(int i=0; i<4; i++)
    {
        ans[i]=rand()%10;
    }
    while(ans[0]==ans[1]||ans[0]==ans[2]||ans[0]==ans[3]||ans[1]==ans[2]||ans[1]==ans[3]||ans[2]==ans[3])
    {
        for(int i=0; i<4; i++)
        {
            ans[i]=rand()%10;
        }
    }
    result=1000*ans[0]+100*ans[1]+10*ans[2]+1*ans[3];
    return;
}
void Enter_the_question(int input,int num[])
{
    printf(">> ");
    scanf("%d", &input);
    num[3]=input%10;//1234...4
    num[2]=input/10%10;//1234...123...3
    num[1]=input/100%10;//1234...12...2
    num[0]=input/1000;//1234...1
    if(input<100||input>9999)
    {
        printf("INPUT ERROR\n");
        Enter_the_question(input,num);
    }
    else if(num[0]==num[1]||num[0]==num[2]||num[0]==num[3]||num[1]==num[2]||num[1]==num[3]||num[2]==num[3])
    {
        printf("INPUT ERROR\n");
        Enter_the_question(input,num);
    }
    return;
}

void Checkanswer(int input,int result,int num[],int ans[],int a,int b)
{
    int i,j;
    printf("ii%d rr%d\n",input,result);
    while(input!=result)
    {
        a=0,b=0;
        for(i=0; i<4; i++)
        {
            if(num[i]==ans[i])
                a++;
            else
                for(j=0; j<4; j++)
                {
                    if(num[i]==ans[j])
                        b++;
                }
        }
        if(a==4)
        {
            printf("YOU WIN\n");
            break;
        }
        else
            printf("%dA%dB\n",a,b);

        Enter_the_question(input,num);
    }
    return;
}
void Ifplayagain(char cho,int input,int result,int num[],int ans[],int a,int b)
{
    printf("Play Again?(Y/N)");
    scanf("%c",&cho);
    if(cho=='Y')
    {
        Make_a_question(ans,result);

        Enter_the_question(input,num);

        Checkanswer(input,result,num,ans,a,b);
        Ifplayagain(cho,input,result,num,ans,a,b);
    }
    else if(cho=='N')
        return;
    else if(cho!='Y'&&cho!='N'){
        Ifplayagain(cho,input,result,num,ans,a,b);
    }

    return;
}
int main()
{
    int ans[4],num[4],input,result,guess,a,b;
    char cho;
    a=0,b=0;
    Make_a_question(ans,result);
    Enter_the_question(input,num);
    Checkanswer(input,result,num,ans,a,b);
    Ifplayagain(cho,input,result,num,ans,a,b);

    return 0;
}
