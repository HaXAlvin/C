#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){//��X�r��q���@���ܦ�'\0'
    int len = 0;
    while(1)
    {
        if(s[len] != '\0')
            len++;
        else//�p�G�X�{'\0'�N�פ�j��
        {
            break;
        }
    }
    return len;//�^�ǵ��G

}

int my_strcmp(const char*s1,const char*s2){

    int val = 0;//��r���۵���0
    for(int i = 0; i < 20; i++)
    {
        if(s1[i] - s2[i] > 0)//�P�_��r���j�p
        {
            val = 1;
            break;
        }
        if(s1[i] - s2[i] < 0)//�P�_��r���j�p
        {
            val = -1;
            break;
        }
        //�p�G�SĲ�o��H�W��ӧP�_���^�ǭȴN�|�O����0
    }
    return val;//�^�ǵ��G
    /*for(int i = 0; i < my_strlen(s2); i++)
    {
        v2 += s2[i];
    }
    return v1 - v2;*/
    //memset(s1, '\0', 20);
    //memset(s2, '\0', 20);

}

char *my_strcpy(char *s1, const char *s2){
    for(int i = 0; i < 20; i++)
    {
        if(s2[i] != '\0')//�Ns2���ݩ�Ŧr���������g�Js1
        {
            s1[i] = s2[i];
        }
        else
        {
            s1[i] = '\0';
        }
    }
    return s1;//�^�ǵ��G
}

char *my_strcat(char *s1, const char *s2){
    int bgn = my_strlen(s1);//�]�w�걵�_�l�I
    for(int i = 0; i < my_strlen(s2); i++)
    {
        s1[bgn] = s2[i];//�}�l�걵
        bgn++;//�л\�U�@���I
    }
    return s1;//�^�ǵ��G

}

char *my_strstr(const char *s1, const char *s2){
    int counter = 0;//�p�ƾ�
    int bgn = 0;//�]�w��X�_�l�I
    for(int i = 0; i < my_strlen(s1); i++)//�v���ˬds1
    {
        for(int j = 0; j < my_strlen(s2); j++)//�v���ˬds2
        {
            if(s1[i] != s2[j])//�p�X�{���Ŷ���
            {
                counter = 0;//�p�ƾ��k�s
                i = i - j;//�Ns1�ˬd�I�h�^�W���ˬd��m
                break;//���Xs2�ˬd���q
            }
            else//�ŦX����
            {
                i++;//�ˬd�U��s1
                counter++;
                if(counter == my_strlen(s2))//��p�ƾ�����r����׮�
                {
                    bgn = i - my_strlen(s2);//�]�w�_�l��X��m
                    break;//���X�j��
                }

            }
        }
        if(counter == my_strlen(s2))//��p�ƾ�����r����׮�
        {
            break;//���Xs1s2��ﶥ�q
        }
    }
    if(bgn == 0)//�p�L�ŦX����
        return NULL;//�^��NULL
    else
        return (char*)s1 + bgn;//�^�ǵ��G

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
