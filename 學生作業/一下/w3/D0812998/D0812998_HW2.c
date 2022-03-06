#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int sort(char sArr[][100],int n,int (*arr)(char *, char *))
{
   // sArr=malloc(n*sizeof(char *));
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n-1;i++)
        {
        //    sArr[i]=calloc(100,sizeof(char));
            if(arr(sArr[i],sArr[i+1])==1)
            {
                char tmp[100];
                strcpy(tmp,sArr[i]);
                strcpy(sArr[i],sArr[i+1]);
                strcpy(sArr[i+1],tmp);
            }
        }

    }


}

int cmp1(char *sArr1,char *sArr2)
{
    int n1=strlen(sArr1);
    int n2=strlen(sArr2);
    for(int i=0;i<n1 && i<n2;i++)
    {

        if(sArr1[i]>sArr2[i])
        {
            return 1;
        }
        if(sArr1[i]<sArr2[i])
        {
            return 0;
        }
    }
    if(n1>n2)
        return 1;
    else
        return 0;
}

int cmp2(char *sArr1,char *sArr2,int n)
{
    int n1=strlen(sArr1);
    int n2=strlen(sArr2);
    for(int i=0;i<n1 && i<n2;i++)
    {
        float f1,f2;

        if(sArr1[i]>=97)
        {
            f1=toupper(sArr1[i])+0.5;
        }
        else
            f1=sArr1[i];
        if(sArr2[i]>=97)
        {
            f2=toupper(sArr2[i])+0.5;
        }
        else
            f2=sArr2[i];
        if(f1>f2)
        {
            return 1;
        }
        if(f1<f2)
        {
            return 0;
        }
    }
    if(n1>n2)
        return 1;
    else
        return 0;
}

int main()
{   int n,m;
    while(1)
    {
        printf("請輸入字串數(輸入0結束):");

        char name[100][100];
        scanf("%d",&n);
        if(n==0)
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",&name[i]);
        }
        printf("請選擇排序方式(1.以ASCII/2.以字典序):");
        scanf("%d",&m);
        if(m==1)
        {
            sort(name,n,cmp1);
        }
        else
        {
            sort(name,n,cmp2);
        }
        for(int i=0;i<n;i++)
        {
            printf("%s\n",name[i]);
        }
    }

}
