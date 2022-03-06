#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef union
{
    int in;
    float fl;
    char ch[16];
}B;
typedef struct
{
    B c;
    int opt2;
}A;

int main()
{
    int a=0,opt1,num=0;
    //char charch[16];
    
    A *s = malloc(a * sizeof(A));
    s = realloc(s,a * sizeof(A));
    printf("選擇:(1.新增/2.印出/0.結束):");
    while(scanf("%d",&opt1)!=EOF)
    {
        if(opt1 == 1)
        {
            a+=1;
            s = realloc(s,a * sizeof(A));
            printf("選擇類型(1.int/2.float/3.char):");
            scanf("%d",&s[num].opt2);
            if(s[num].opt2==1||s[num].opt2==2||s[num].opt2==3)
                printf("輸入資料:");
            if(s[num].opt2 == 1)
            {
                scanf("%d",&(s[num].c).in);
            }
            else if(s[num].opt2 == 2)
            {
                scanf("%f",&(s[num].c).fl);
            }
            else if(s[num].opt2 == 3)
            {
                getchar();
                scanf("%s",(s[num].c).ch);
               // strcpy((s[i].c).ch,charch);
                
            }
            else
            {
                while(s[num].opt2!=1&&s[num].opt2!=2&&s[num].opt2!=3)
                {
                    printf("輸入錯誤!\n");
                    printf("選擇類型(1.int/2.float/3.char):");
                    scanf("%d",&s[num].opt2);
                    if(s[num].opt2==1||s[num].opt2==2||s[num].opt2==3)
                        printf("輸入資料:");
                    if(s[num].opt2 == 1)
                    {
                        scanf("%d",&(s[num].c).in);
                    }
                    else if(s[num].opt2 == 2)
                    {
                        scanf("%f",&(s[num].c).fl);
                    }
                    else if(s[num].opt2 == 3)
                    {
                        getchar();
                        scanf("%s",(s[num].c).ch);
                        //strcpy((s[i].c).ch,charch);
                        
                    }
                }
            }
            num++;
        }
        else if(opt1 == 2)
        {
            for(int m=0;m<num;m++)
            {
                if(s[m].opt2==1)
                {
                    printf("%d\n",(s[m].c).in);
                }
                else if(s[m].opt2==2)
                {
                    printf("%f\n",(s[m].c).fl);
                }
                else if(s[m].opt2==3)
                {
                    printf("%s\n",(s[m].c).ch);
                }
            }
        }
        else if(opt1 == 0)
        {
            free(s);
            printf("結束程式\n");
            return 0;
        }
        else
            printf("輸入錯誤!\n");
        printf("選擇:(1.新增/2.印出/0.結束):");

    }
    return 0;
}
