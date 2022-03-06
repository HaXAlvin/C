/*  109年度  資訊二丁
        第一週作業       */
#include<stdio.h>//標頭檔
#include<string.h>

size_t my_strlen(const char*s)//計算字串長度
{
    for(int i=0;; i++)//計算字串長度
    {
        if(s[i]=='\0')//到'\0'停止
        {
            return i;//回傳長度
        }
    }
}

int my_strcmp(const char*s1,const char*s2)//比較s1與s2兩個字串
{
    for(int i=0;; i++)//比較字串每一個字
    {
        if(s1[i]==s2[i])//兩個字串一樣
        {
            return 0;//回傳0;
        }
        if(s1[i]<s2[i])//s1比s2小
        {
            return -1;//回傳-1
        }
        if(s1[i]>s2[i])//s1比s2大
        {
            return 1;//回傳1
        }


    }

}

char *my_strcpy(char *s1, const char *s2)//將字串s2拷貝到s1
{
    for(int i=0;; i++)//查看s2的每一個字
    {
        if(s2[i]!='\0')//如果s2不是'\0'
        {
            s1[i]=s2[i];//將s2的值給s1
        }

        else//如果s2是'\0'
        {
            s1[i]='\0';//s1為'\0'
            return s1;//回傳s1
        }
    }

}

char *my_strcat(char *s1, const char *s2)//將字串s2接到s1尾端
{
    int a=0,b=0;//宣告變數
    for(int i=0;; i++)//計算s1字串長度
    {
        if(s1[i]!='\0')//不算最後的\0
        {
            a++;//a增加1
        }
        else
            break;//跳出迴圈

    }

    for(int i=0;; i++)//計算s2字串長度
    {
        if(s2[i]!='\0')//不算最後的\0
        {
            b++;//b增加1
        }
        else
            break;//跳出迴圈

    }
    b++;//加\0
    for(int j=0; j<b; j++)//循環b次
    {
        s1[a]=s2[j];//從s1[a]開始賦值
        a++;//a增加1
    }
    return s1;//回傳s1

}

char *my_strstr(const char *s1, const char *s2)//回傳在字串s2在s1第一次出現位置的指標
{
    int a=0,b=0;//宣告變數
    for(int i=0;; i++)//計算s1字串長度
    {
        if(s1[i]!='\0')//不算最後的\0
        {
            a++;//a增加1
        }
        else
            break;//跳出迴圈
    }
    a++;//加\0
    for(int i=0;; i++)//計算s2字串長度
    {
        if(s2[i]!='\0')//不算最後的\0
        {
            b++;//b增加1
        }
        else
            break;//跳出迴圈
    }
    int n=0,tmp=0,sum=0;//宣告迴圈
    for(int i=0;i<a;i++)//重複a次
    {
        if(s1[i]==s2[n])//找出s1與s2的相同字
        {
            n++;//s2增加
            if(n==1)//相同的第一次
                tmp=i-1;//紀錄第一次位置
            if(n==b){//連續相同的次數與s2相同
                sum=b;//紀錄s2長度
                break;
            }
        }
        else
            n=0;//不相同n清零
            continue;//繼續
    }
    char *ptr=(char*)&s1[tmp];//宣告指標
    if(n==sum)//確認有相同的字
    {
        return (char*)ptr;//回傳相同字的第一個字的指標
    }


}

int main()
{
    char a1[20]="I love dog ";
    char b1[20]="and cat.";
    char c1[20]="love";
    char d1[20];

    char a2[20]="I love dog ";
    char b2[20]="and cat.";
    char c2[20]="love";
    char d2[20];

    printf("Length of a1:%d\n",strlen(a1));
    printf("My_Length of a1:%d\n",my_strlen(a1));
    printf("\n");

    printf("Strcmp of a1 and a2:%d\n",strcmp(a1,a2));
    printf("My_Strcmp of a1 and a2:%d\n",my_strcmp(a1,a2));
    printf("\n");

    printf("Strcmp of a1 and b1:%d\n",strcmp(a1,b1));
    printf("My_Strcmp of a1 and b1:%d\n",my_strcmp(a1,b1));
    printf("\n");

    printf("Strcmp of c1 and a1:%d\n",strcmp(c1,a1));
    printf("My_Strcmp of c1 and a1:%d\n",my_strcmp(c1,a1));
    printf("\n");

    printf("Strcpy of d1 and a1:%s\n",strcpy(d1,a1));
    printf("My_Strcpy of d2 and a2:%s\n",my_strcpy(d2,a2));
    printf("\n");

    printf("Strcat of d1 and b1:%s\n",strcat(d1,b1));
    printf("My_Strcat of d2 and b2:%s\n",my_strcat(d2,b2));
    printf("\n");


    printf("Strstr of d1 and c1:%s\n",strstr(d1,c1));
    printf("My_Strstr of d2 and c2:%s\n",my_strstr(d2,c2));
    printf("\n");

    return 0;
}
