/*  109�~��  ��T�G�B
        �Ĥ@�g�@�~       */
#include<stdio.h>//���Y��
#include<string.h>

size_t my_strlen(const char*s)//�p��r�����
{
    for(int i=0;; i++)//�p��r�����
    {
        if(s[i]=='\0')//��'\0'����
        {
            return i;//�^�Ǫ���
        }
    }
}

int my_strcmp(const char*s1,const char*s2)//���s1�Ps2��Ӧr��
{
    for(int i=0;; i++)//����r��C�@�Ӧr
    {
        if(s1[i]==s2[i])//��Ӧr��@��
        {
            return 0;//�^��0;
        }
        if(s1[i]<s2[i])//s1��s2�p
        {
            return -1;//�^��-1
        }
        if(s1[i]>s2[i])//s1��s2�j
        {
            return 1;//�^��1
        }


    }

}

char *my_strcpy(char *s1, const char *s2)//�N�r��s2������s1
{
    for(int i=0;; i++)//�d��s2���C�@�Ӧr
    {
        if(s2[i]!='\0')//�p�Gs2���O'\0'
        {
            s1[i]=s2[i];//�Ns2���ȵ�s1
        }

        else//�p�Gs2�O'\0'
        {
            s1[i]='\0';//s1��'\0'
            return s1;//�^��s1
        }
    }

}

char *my_strcat(char *s1, const char *s2)//�N�r��s2����s1����
{
    int a=0,b=0;//�ŧi�ܼ�
    for(int i=0;; i++)//�p��s1�r�����
    {
        if(s1[i]!='\0')//����̫᪺\0
        {
            a++;//a�W�[1
        }
        else
            break;//���X�j��

    }

    for(int i=0;; i++)//�p��s2�r�����
    {
        if(s2[i]!='\0')//����̫᪺\0
        {
            b++;//b�W�[1
        }
        else
            break;//���X�j��

    }
    b++;//�[\0
    for(int j=0; j<b; j++)//�`��b��
    {
        s1[a]=s2[j];//�qs1[a]�}�l���
        a++;//a�W�[1
    }
    return s1;//�^��s1

}

char *my_strstr(const char *s1, const char *s2)//�^�Ǧb�r��s2�bs1�Ĥ@���X�{��m������
{
    int a=0,b=0;//�ŧi�ܼ�
    for(int i=0;; i++)//�p��s1�r�����
    {
        if(s1[i]!='\0')//����̫᪺\0
        {
            a++;//a�W�[1
        }
        else
            break;//���X�j��
    }
    a++;//�[\0
    for(int i=0;; i++)//�p��s2�r�����
    {
        if(s2[i]!='\0')//����̫᪺\0
        {
            b++;//b�W�[1
        }
        else
            break;//���X�j��
    }
    int n=0,tmp=0,sum=0;//�ŧi�j��
    for(int i=0;i<a;i++)//����a��
    {
        if(s1[i]==s2[n])//��Xs1�Ps2���ۦP�r
        {
            n++;//s2�W�[
            if(n==1)//�ۦP���Ĥ@��
                tmp=i-1;//�����Ĥ@����m
            if(n==b){//�s��ۦP�����ƻPs2�ۦP
                sum=b;//����s2����
                break;
            }
        }
        else
            n=0;//���ۦPn�M�s
            continue;//�~��
    }
    char *ptr=(char*)&s1[tmp];//�ŧi����
    if(n==sum)//�T�{���ۦP���r
    {
        return (char*)ptr;//�^�ǬۦP�r���Ĥ@�Ӧr������
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
