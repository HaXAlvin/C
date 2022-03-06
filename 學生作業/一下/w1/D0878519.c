#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){//計算字串長度
    int length=0;
    while(s[length]!='\0')//如果不到最後的\0就length++
        length++;
    return length;
}

int my_strcmp(const char*s1,const char*s2){//比較字串長度
    if(*s1==*s2)
        return 0;//s1=s2回傳0
    if(*s1>*s2)
        return 1;//s1>s2回傳1
    if(*s1<*s2)
        return -1;//s1<s2回傳-1
}

char *my_strcpy(char *s1, const char *s2){//把s1變成s2的數據
    int i=0;
    while(s2[i]!='\0')//s2[i]如果不等於\0就i++
    {
        s1[i]=s2[i];
        i++;
    }
    s1[i]='\0';
    return s1;
}

char *my_strcat(char *s1, const char *s2){//s2接到s1
    int length=0;
    while(s1[length]!='\0')//如果不到最後的\0就length++
        length++;
    int i=0;
    while(s2[i]!='\0')
    {
        s1[length+i]=s2[i];//原本的s1長度+i長度=s2的i長度
        i++;
    }
    s1[length+i]='\0';
    return s1;
}

char *my_strstr(const char *s1, const char *s2){//找到s2在s1第一次出現的地方
    int i=0,j,k=0;
    while(s1[i]!='\0')//做迴圈直到\0
    {
        i++;
        j=i;
        while(s2[k]!='\0'&&s1[j]==s2[k])
        {
            j++;
            k++;
        }
        if(s2[k]=='\0'&&k>0)//讀到s2的最後面
            return &s1[i];
    }
}
int main(){
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
