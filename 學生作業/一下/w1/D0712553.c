#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){
    size_t len = 0;
    while (*s++ != '\0'){  //Ū�쵲���r��Y����
        len++;  //�O�ƨ쵲���ꬰ��
    }
    return len;
}

int my_strcmp(const char*s1,const char*s2){
    int cmp = 0;
    while (*s1 != '\0' && *s2 != '\0'){
        *s1++;
        *s2++;
        if (*s1 != '\0' && *s2 == '\0'){  //�p�Gs2������
            cmp = -1;  //�hs1>s2
        }else if (*s1 == '\0' && *s2 != '\0'){  //�p�Gs1������
            cmp = 1;  //�hs1<s2
        }else{
            cmp = 0;  //�_�h�۵�
        }
    }
    return cmp;
}

char *my_strcpy(char *s1, const char *s2){

    int len = my_strlen(s2);  //�n�ƻs���r�����
    int i;
    for (i=0; i<=len; i++){  //�@�@���Ȩ�r�����
        *s1 = *s2;
        s1++;
        s2++;
    }
    return s1 ;
}

char *my_strcat(char *s1, const char *s2){
    char *cat = s1;
    while (*cat != '\0'){  //�]��Ĥ@�r�ꪺ����
        cat++;
    }
    while (*cat++ = *s2++);  //�q�Ĥ@�r�ꪺ�������W�ĤG�r��
    return s1;
}

char *my_strstr(const char *s1, const char *s2){

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
