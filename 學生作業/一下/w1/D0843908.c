#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){
    int num = 0;
    while(*(s + num)!='\0'){
        num++;
    }
    return num;
}

int my_strcmp(const char*s1,const char*s2){
    int num = 0;
    while(1){
        // s1 �� s2 ���X�{�Ŧr��
        if(*(s1 + num)=='\0' && *(s2 + num)!='\0'){
            return 1;
        }
        // s2 �� s1 ���X�{�Ŧr��
        if(*(s1 + num)!='\0' && *(s2 + num)=='\0'){
            return -1;
        }
        // �P�ɥX�{�Ŧr��
        if(*(s1 + num)=='\0' && *(s2 + num)=='\0'){
            return 0;
        }
        num++;
    }
}

char *my_strcpy(char *s1, const char *s2){
    int num = 0;
    while(*(s2 + num)!='\0'){
        *(s1 + num) = *(s2 + num);
        num++;
    }
    return s1;
}

char *my_strcat(char *s1, const char *s2){
    //s1 ������
    int num = 0;
    //�p�� s1 ������
    while(*(s1 + num)!='\0'){
        num++;
    }
    int count = 0;
    //�q s1 ������m�}�l���W s2 ���� s2 ���Ŧr��
    while(*(s2 + count)!='\0'){
        *(s1 + num) = *(s2 + count);
        num++;
        count++;
    }
    return s1;
}

char *my_strstr(const char *s1, const char *s2){
    //���� s1 ���� num ��
    int num = 0;
    //�Ω�^�� �Y num1 �� 2147483647 �� NULL
    int num1 = 2147483647;
    //�p��ŦX���r��
    int YN = 0;
    //�̥~�hwhile���� s1 ���� num ��
    while(*(s1 + num)!='\0'){
        //���� s2 ���� count ��
        int count = 0;
        //�Y s1 ���� num ���M s2 ���� count ���۵�
        if(*(s1 + num) == *(s2 + count)){
            YN = 0;
            //s2 �b s1 ���� num1 ���}�l�X�{
            num1 = num;
            //�� s2 ����r�X�{�b s1 �ˬd s2 �᪺�C�Ӧr���O�_���M s1 �۵�
            while((*(s2 + count) == *(s1 + num)) && (*(s2 + count)!='\0')){
                if(*(s2 + count) == *(s1 + num)){
                    count++;
                    num++;
                    YN++;
                    //�Y�U�@�����۵��h���P�w�� NULL
                    if(*(s2 + count) != *(s1 + num) && (*(s2 + count)!='\0')){
                        num1 = 2147483647;
                    }
                }else{
                    num1 = 2147483647;
                    break;
                }
            }
        }
        //�T�w s2 �w�b s1 �X�{�N����j��
        if(num - num1 == YN){
            break;
        }
        num++;
    }
    if(num1==2147483647){
        return NULL;
    }else{
        return (char*)(s1+num1);
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
