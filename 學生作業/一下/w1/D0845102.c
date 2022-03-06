#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s)
{
    int count=0;
    while(s[count]!='\0')//��r�꦳�X��
        count++;
    return count;
}

int my_strcmp(const char*s1,const char*s2)
{
    int countS1=0,countS2=0;
    while(s1[countS1]!='\0')//��r�꦳�X��
        countS1++;
    while(s2[countS2]!='\0')//��r�꦳�X��
        countS2++;
    if(countS1>countS2)
    {
        return -1;
    }
    else if(countS1==countS2)
    {
        return 0;
    }
    else if(countS1<countS2)
    {
        return 1;
    }
}

char *my_strcpy(char *s1, const char *s2)
{
    int countS2=0;
    while(s2[countS2]!='\0')//��r�꦳�X��
    {
        s1[countS2]=s2[countS2];//�ƻs�r��
        countS2++;
    }
    s1[countS2]=' ';
    return s1;
}

char *my_strcat(char *s1, const char *s2)
{
    int countS1=0,countS2=0;
    while(s1[countS1]!='\0')//��r�꦳�X��
        countS1++;
    while(s2[countS2]!='\0')//��r�꦳�X��
        countS2++;
    countS2++;
    int i=0,j=0;
    while(countS2>0)
    {
        s1[countS1+j-2]=s2[i];//�N�r��α�
        countS2--;
        i++;
        j++;
    }
    return s1;
}

char *my_strstr( const char *s1, const char *s2)
{
    char *str1 = (char*)s1;
	char *str2 = (char*)s2;
	char *s3 = (char*)s1;
    str1=s3;
    str2=(char*)s2;
    int countS1=0,countS2=0,count=0;
    while(s1[countS1]!='\0')//��r�꦳�X��
        countS1++;
    while(s2[countS2]!='\0')//��r�꦳�X��
        countS2++;
    int i=0,len=0;
    for(int j=0;;)
    {
        if(s2[i]==s1[j])//�p�G������@���@�˴N�i�J�j��
        {
            i++;
            j++;
            count++;
            if(count==countS2)//������|���@�˷ǳƸ��X
            {
                for(int i=0;i<countS1;i++)
                {
                    s3[i]=s1[i+(len/20)];//��r��h�l���r�Ů���
                }
                return s3;
            }
        }
        else
        {
            i++;//�o���������r��
            count=0;//�S���@�˴N�k�s���M�s���|���]�|�Q�P�w���T
            len++;//��r��n�R���X��/20�]���r�꦳20�ӷ|�h�]20��
        }
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
