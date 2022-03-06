/*  109年度  資訊二丁
        第二週作業       */
#include<stdio.h>//標頭檔
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[100];//宣告變數
    int n=0,lon=0,sum=0;
    int num=10;
    char **ptr;//動態陣列
    ptr=malloc(num*sizeof(char*));//建立第一維陣列，大小為10


    printf("1.新增"
           "2.印出"
           "3.排序"
           "4.離開\n");//印出文字

    while(scanf("%d",&n))
    {
        getchar();
        if(n==1)//新增
        {
            gets(str);//輸入字串
            lon=strlen(str);//計算字串長度
            lon++;//加上'\0'
            if(sum>=num)//如果需要新增陣列
            {
                printf("dddddd");
                ptr=realloc(ptr,(num+5)*sizeof(char*));//新增陣列，每次新增5個
                num=num+5;
            }
            ptr[sum]=calloc(lon,sizeof(char));//根據字串長度新增第二維陣列

            for(int i=0; i<lon; i++)//重複lon次
            {
                ptr[sum][i]=str[i];//賦值給陣列
            }
            for(int i=0; i<100; i++)//將輸入的陣列清空
            {
                str[i]=0;
            }
            sum++;//變數+1
        }
        if(n==2)//印出
        {
            for(int i=0; i<sum; i++)
            {
                puts(ptr[i]);//依照順序印出
            }

        }
        if(n==3)//排序
        {
            for(int i=sum;i>0;i--)//泡沫排序法
            {
                for(int j=0;j<i-1;j++)

                {
                    if(strcmp(ptr[j],ptr[j+1])>0)//strcmp比較兩個陣列
                    {
                        char *temp=ptr[j];
                        ptr[j]=ptr[j+1];
                        ptr[j+1]=temp;
                    }
                }
            }

        }
        if(n==4)//離開
        {
            for(int i=0;i<sum;i++)
            {
                free(ptr[i]);//釋放第二維陣列
            }
            free(ptr);//釋放第一維陣列
            return 0;//結束並回傳

        }
    }
}
