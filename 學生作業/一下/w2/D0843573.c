#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char **dynaArr1;
    char dynaArr2[100];
    int select;
    int space=0,namecalculate=10,compare,length=0;
    int i=0,m=0,n=0;
    dynaArr1 = malloc(10*sizeof(char*));

    while(1)
    {
        printf("選擇:(1.新增2.印出3.排序4.離開)\n");
        scanf("%d",&select);
        //選擇1 讓使用者新增名字
        if(select==1)
        {
            //空間不足則每次增加5個char 大小的空間
            if(namecalculate==0)
            {
                dynaArr1 = realloc(dynaArr1,namecalculate+5*sizeof(char));
                namecalculate = namecalculate+5;
                namecalculate = 5;
            }
            getchar();
            gets(dynaArr2);
            //紀錄字串長度
            //length = strlen(dynaArr1);
            for(int j=0;j<100;j++)
            {
                if(dynaArr2[j]!='\0')
                    m++;
            }
            //配置的空間須剛好為輸入的字元數加上’\0’所佔的空間大小
            dynaArr1[space] = malloc(m+1*sizeof(char));
            //把第二個複製到第一個
            strcpy(dynaArr1[space],dynaArr2);
            space++;
        }
        // 選擇2 印出使用者輸入的名字
        if(select==2)
        {
            for(n=0;n<space;n++)
            {
                puts(dynaArr1[n]);
                printf("\n");
            }
        }
        //選擇3 使用泡沫排序法排序
        if(select==3)
        {
            for(int i=space-1;i>0;i--)
            {
                for(int c=0;c<i;c++)
                {
                    compare=strcmp(dynaArr1[c],dynaArr1[c+1]);
                    if(compare>0)
                    {
                        char* tmp=dynaArr1[c];
                        dynaArr1[c]=dynaArr1[c+1];
                        dynaArr1[c+1]=tmp;
                    }
                }
            }
            printf("排序完成!\n");
        }
        //選擇4 釋放記憶體 結束程式
        if(select==4)
        {
            for(int l=0;l<space;l++)
            {
                free(dynaArr1[i]);
            }
            free(dynaArr1);
            return 0;
        }
    }
}
