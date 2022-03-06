#include<stdio.h>
#include<stdlib.h>
#include<string.h>

size_t my_strlen(const char*s){
    int count=0; //�p�����
    int i=0; //�]�}�̪��ܼ�
    while (s[i]!='\0'){ //�]�}�C���j��
        count++;
        i++;
    }
    return count;
}

int my_strcmp(const char*s1,const char*s2){
    int count=0; //
    int len; //�}�C����
    if (my_strlen(s1)>my_strlen(s2)) //���s1 s2�֪�
        len=my_strlen(s1);
    else
        len=my_strlen(s2);

    for (int i=0;i<len;i++){ //�P�_�֪�acsii code�֤j
        if (s1[i]>s2[i]){
            return 1;
            break;
        }
        else if (s1[i]<s2[i]){
            return -1;
            break;
        }
        else if (s1[i]==s2[i]){
            count++;
        }
    }
    if (count==len) //�p�G�@��return 0
        return 0;
}

char *my_strcpy(char *s1, const char *s2){
    int len=0; //s2�����ܼ�
    int i=0; //�j���ܼ�
    len=my_strlen(s2);
    for (i=0;i<len+1;i++){ //�Ns2 ������ s1
        s1[i]=s2[i];
    }
    return s1;
}

char *my_strcat(char *s1, const char *s2){
    int i=0;// �j���ܼ�
    int j=0;// �j���ܼ�
    int len1=my_strlen(s1);//s1�}�C����
    int len2=my_strlen(s2);//s2�}�C����
    for (i=len1,j=0;j<len2+1;i++,j++){ //�Ns2�Ҧbs1�᭱
        s1[i]=s2[j];
    }
    return s1;
}

char *my_strstr(const char *s1, const char *s2){
    int i=0,j=0; //�j���ܼ�
    int num=0; //�P�_�O�_���ư��椧�ܼ�
    int k; //�s�����פ��ܼ�
    int len1=my_strlen(s1); //s1�}�C���פ��ܼ�
    int len2=my_strlen(s2); //s2�}�C���פ��ܼ�

    for (i=0;i<len2;i++){ //�P�_���̬ۦP���_���j��
        for (j=0;j<len1;j++){
            if (s2[i]==s1[j] && num==0){ //�P�_�O�_�@�˨åB�i�J�U�@���q
                num=1;
                k=j;
                i++;
            }
            else if (num==1){ //�P�_����O�_�ҬۦP
                if (s2[i]==s1[j]){
                    i++;
                }
                else{ //���@�˼QNULL
                    return '\0';
                }
            }
                if (i==len2){ //�Q�X����
                    return (char*)s1+k;
            }
        }
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
