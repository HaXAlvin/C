#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){
	int i,count_len=0; //�p�����
	for(i=0;*(s+i) != '\0';i++)
		count_len += 1;
	return count_len;
}

int my_strcmp(const char*s1,const char*s2){
	int i,val=0; //�^�ǭ�
	for(i=0;*(s1+i) != '\0' && *(s2+i) != '\0';i++){ //�q��0�Ӧr���}�l���
		if(*(s1+i) > *(s2+i)){ //�Y�j��^��1
			val = 1;
			break;
		}
		else if(*(s1+i) == *(s2+i)) //�Y����^��0
			val = 0;
		else if(*(s1+i) < *(s2+i)){ //�Y�p��^��-1
			val = -1;
			break;
		}
	}
	return val;
}

char *my_strcpy(char *s1, const char *s2){
	int i;
	for(i=0;i<20;i++)
		*(s1+i) = *(s2+i); //�Ns1�ܦ�s2
	return s1;
}

char *my_strcat(char *s1, const char *s2){
    int i,j,k=0;
	for(i=0;i<20;i++){
        if(*(s1+i) == '\0'){ //�p��s1������
            j = i;
            break;
        }
	}
	for(i=j;i<20;i++){
        *(s1+i) = *(s2+k); //�Ns2���Ws1
        k += 1;
	}
    return s1;
}

char *my_strstr(const char *s1, const char *s2){
    int i=0,j,flag_pre=0,ans=0,len_s2=0;
    for(i=0;*(s2+i) != '\0';i++){
        len_s2 = i; //�p��s2����
        for(j=flag_pre;j<20;j++){
            if(*(s2+i) == *(s1+j)){ //�ˬds1���ĴX���X�{s2
                if(flag_pre == 0){
                    flag_pre = j;
                    ans = j;
                    break;
                }
                else if(j-1 == flag_pre){ //�T�Os2�bs1���O�@�ӧ����r
                    flag_pre = j;
                    break;
                }

            }
        }
    }
    if((flag_pre-ans) == len_s2)
        return s1+ans;
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
