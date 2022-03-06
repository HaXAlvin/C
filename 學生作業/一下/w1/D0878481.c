#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){
    int count=0;
    while(s[count]!='\0'){//�p�G�Ȥ�����\0�Acount+1
        count++;
    }
    return count;//�^��count

}

int my_strcmp(const char*s1,const char*s2){
    int count=0;
    while(s1[count]==s2[count]){//��ȬۦP��
        if ((s1[count]=='\0')&&(s2[count]=='\0')){//�p�G���ȳ���n��\0
            return 0;
        }

        count++;//���U�@�Ӭ��Ȥ��

    }
    if (s1[count]>s2[count]){//���ۦP�ɡA����k��
        return 1;
    }
    else//����k�p
        return -1;

}

char *my_strcpy(char *s1, const char *s2){
    int count=0;
    while(s2[count]!='\0'){//��Ȥ���\0��
        s1[count]=s2[count];//�N�n�ƻs�r��v�@��J
        count++;
    }
    if (s2[count]=='\0'){//��s2���Ȭ�\0
        s1[count]='\0';//�N\0��Js1������
    }
    return s1;






}

char *my_strcat(char *s1, const char *s2){
    int count=0;
    int count1=0;
    while(s1[count]!='\0'){//����J�ۤv����
        s1[count]=s1[count];
        count++;//�p��X����
    }
    while(s2[count1]!='\0'){
        s1[count]=s2[count1];//�q�̥��ݶ�Js2���Y
        count++;
        count1++;
    }


    return s1;
}

char *my_strstr(const char *s1, const char *s2){

    int count=0;
    int count1=0;
    while(1){

        char *s3=(char*)&s1[count];//�]�ܼƦs����m
        while (s1[count]==s2[count1]){//��}�C���r���@�ˮɩ��U���
            count1++;
            count++;
        }
        if (s2[count1]=='\0'){//���X�j��ɡA�p�Gs2�̫᪺��m�O\0,�h�^�Ǥ@�_��ۦP����m
            return s3;

        }
        if(s1[count]=='\0'){//�p�Gs1�̫ᬰ\0�h�S���ۦP�r��
            return NULL;
        }
        count++;//�W�z�������ߡA�h�Ncount+1�A�h��X�ŦX�r�ꪺ��m
        count1=0;//�����s2��count�k0

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
