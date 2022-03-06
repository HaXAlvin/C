#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s)
{
    int i=0,answer=0;
    while(s[i]!='\0')//計算字串長度，\0為結尾
    {
        answer++;//跑迴圈計算
        i++;
    }
    return answer;
}

int my_strcmp(const char*s1,const char*s2)
{
    if(s1[0]>s2[0])//比較第一個字元大小
        return 1;//較大回傳1
    else if(s1[0]==s2[0])//比較第一個字元大小
        return 0;//相等回傳0
    else//比較第一個字元大小
        return -1;//較小回傳-1
}

char *my_strcpy(char *s1, const char *s2)
{
    int i=0,len=0;
    while(s2[i]!='\0')//計算後者字串的長度
    {
        len++;
        i++;
    }
    for(int j=0;j<=len;j++)//將後者每一個字元取代前者
    {
        s1[j]=s2[j];
    }
    return s1;
}

char *my_strcat(char *s1, const char *s2)
{
    int i=0,j=0,len1=0,len2=0,n=0;
    while(s1[i]!='\0')//計算字串長度
    {
        len1++;
        i++;
    }

    while(s2[j]!='\0')//計算字串長度
    {
        len2++;
        j++;
    }
    for(int k=len1;k<len1+len2;k++)//從前者字串的下一個位置開始填入後者字串
    {
        for(int m=n;m<len2;m++)//每填完一個字元此迴圈就結束
        {
            s1[k]=s2[m];
            n++;//以n為位置代表，由0開始，每填完一個位置，n+1
            break;
        }
    }
    return s1;
}

char *my_strstr(const char *s1, const char *s2)
{
    const char *str1=s1,*str2=s2,*str0=s1;//將兩個字串分別存到另外的位置以便計算比較
    while(*str0)//當位置還有在字元則繼續運算
    {
        str1=str0;//初始位置為要開始比較的位置
        str2=s2;//副字串存入
        while(*str1==*str2)//當有相等時，再比較下一個字元
        {
            str1++;
            str2++;
        }
        if(*str2=='\0')//代表副字串比較完了，返回到找到的初始位置
            return (char*)str0;
        if(*str1=='\0')//代表主字串比較完了，未找到相同的
            return NULL;
        str0++;//初始位置更新
    }
    return NULL;
}
int main()
{
    char a1[20]="I love dog ";
    char b1[20]="and cat.";
    char c1[20]="love";
    char d1[20];//"I love dog "

    char a2[20]="I love dog ";
    char b2[20]="and cat.";
    char c2[20]="love";
    char d2[20];//"I love dog "

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
