#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){
    int count=0;//�ŧi
    for(int i=0;;i++){//�p�����
        if(s[i]=='\0'){//��Ū��\0����
            break;
        }
        count++;
    }
    return count;//�^��
}

int my_strcmp(const char*s1,const char*s2){
    int count1 = 0,count2 = 0;//�ŧi
    for(int i=0;;i++){//�Ns1�C�@���ۥ[�j��
        if(s1[i]=='\0'){//��Ū��\0����
            break;
        }
        count1+=s1[i];
    }
    for(int i=0;;i++){//�Ns1�C�@���ۥ[�j��
        if(s2[i]=='\0'){//��Ū��\0����
            break;
        }
        count2+=s2[i];
    }
    //s1 s2��j�p
    if(count1>count2){
        return -1;//�^��
    }
    else if(count1<count2){
        return 1;//�^��
    }
    else{
        return 0;//�^��
    }
}

char *my_strcpy(char *s1, const char *s2){
    for(int i=0;i<=19;i++){//�k0s1�}�C
        s1[i]='\0';
    }
    for(int i=0;;i++){//�Ns2���s1��
        if(s2[i]=='\0'){//��Ū��\0����
            break;
        }
        s1[i]=s2[i];
    }
    return s1;//�^��
}

char *my_strcat(char *s1, const char *s2){
    int count1 = 0,count2 = 0;
    for(int i=0;;i++){//�p��s1����
        if(s1[i]=='\0'){//��Ū��\0����
            break;
        }
        count1++;
    }
    for(int i=0;;i++){//�p��s2����
        if(s2[i]=='\0'){//��Ū��\0����
            break;
        }
        count2++;
    }
    for(int i=0;i<count2;i++){//�Ns2���s1��
        s1[i+count1]=s2[i];
    }
    return s1;
}

char *my_strstr(const char *s1, const char *s2){
    int is_s2=0,count;//�ŧi
    for(int i=0;;i++){
        if(s1[i]=='\0'){//��Ū��\0����
            break;
        }
        else if(s1[i]==s2[0]){
            for(int j=0;;j++){
                if(s2[j]=='\0'){
                    is_s2=1;//���ۦP flag
                    count=i;//�����}�l�ۦP����m
                    break;
                }
                else if(s1[i+j]!=s2[j]){//���۵�
                    break;
                }
            }
        }
        else;
    }
    //
    if(is_s2==1){//�p�Gflag��Ĳ�o
        for(int i=count;;i++){//�q�ۦP����m �}�l�^��
            if(s1[i]=='\0'){
                break;
            }
            return (char*)&s1[i];//�^��
        }
    }
    //
    //


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
