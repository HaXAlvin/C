#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int opt,a=10,b=0,len;//a為一開始設定第一維空間,len為輸入名字的長度
    char **name,nam[100],*tmp;//name為二維空間,nam為輸入的名字
    name = malloc(a * sizeof(char *));
    printf("1.新增　2.印出　3.排序　4.離開\n");
    while(scanf("%d",&opt)!=EOF)
    {
        if(b>a)//若空間不足再多配置五個
        {
            a+=5;
            name = realloc(name,a * sizeof(char *));

        }

        if(opt==1)
        {
            for(int i=b;i<a;i++)
            {
                printf("輸入名字：");
                getchar();//讀'\n'
                gets(nam);//輸入名字

                len = strlen(nam);//計算輸入名字的長度
                name[i] = calloc(len+1,sizeof(char));//配置第二維空間
                for(int j=0;j<=len;j++)
                {
                    name[i][j]=nam[j];//將輸入的名字存進第二維
                }
                b++;//計算輸入幾個名字
                break;
            }
        }
        else if(opt==2)
        {
            for(int i=0;i<b;i++)
            {
                printf("%s\n",name[i]);//輸出名字
            }
        }
        else if(opt==3)
        {
            for(int i=b-1;i>0;i--)
            {
                for(int j=0;j<i;j++)
                {
                    if(strcmp(name[j],name[j+1])>0)//當此式為true則運作以下 直接交換位址
                    {
                        tmp=name[j];
                        name[j]=name[j+1];
                        name[j+1]=tmp;

                    }
                }
            }
        }
        else if(opt==4)//釋放
        {
            for(int i=0;i<b;i++)
                free(name[i]);//第二維
            free(name);//第一維
            return 0;
        }
        else
        {
            printf("輸入錯誤\n");
        }
        printf("1.新增　2.印出　3.排序　4.離開\n");

    }

    return 0;
}
