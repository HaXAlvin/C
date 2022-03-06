#include<stdio.h>
#include<string.h>
#include<stdlib.h>

size_t my_strlen(const char*s){
    int num=0;
    while(1){
        if(s[num]!='\0'){
            num++;
        }
        else{
            break;
        }
    }
    return num;

}

int my_strcmp(const char*s1,const char*s2){//«e¤j=1«e¤p=-1

    int lens1=my_strlen(s1);
    int lens2=my_strlen(s2);
    if(lens1>=lens2){
        for(int i=0 ; i<lens2 ; i++){
            if(s1[i]>s2[i]){
                return 1;
            }
            else if(s1[i]<s2[i]){
                return -1;
            }
            else{
                return 0;
            }
        }
    }
    else if(lens1<lens2){
        for(int j=0 ; j<lens1 ; j++){
            if(s1[j]>s2[j]){
                return 1 ;
            }
            else if(s1[j]<s2[j]){
                return -1;
            }
            else{
                return 0;
            }
        }
    }

}

char *my_strcpy(char *s1, const char *s2){
    int len=my_strlen(s2);

    for( int i = 0; i<=len ; i++){
        s1[i]=s2[i];
    }

    return s1;


}

char *my_strcat(char *s1, const char *s2){//d2 b2
    int len=my_strlen(s1);
    int len2=my_strlen(s2);
    int count=0;

    for(int j=len ; j<len+len2 ; j++){
        s1[j]=s2[count];
        count++;
    }
    return s1;

}

char *my_strstr(const char *s1, const char *s2){
    //char a[100],b[100];
    int count=0;
    int i,j;
    int word1_ln=my_strlen(s1);
    int word2_ln=my_strlen(s2);
    for( i =0 ; i < word1_ln; i++){
        if(s1[i]==s2[i]){
            while(s1[i]!='\0'&&s2[i]!='\0'){

            }
        }
    }
    if(word1_ln>word2_ln){
        while(s1[count]!='\0'){
            return (char*)&s1[i];
        }
    }
    else{
        while(s2[count]!='\0'){
            return (char*)&s2[i];
        }
    }


}

int main(){
    char a1[20]="I love dog ";
    char b1[20]="and cat.";
    char c1[20]="love";
    char d1[20];//i love dog and cat

    char a2[20]="I love dog ";
    char b2[20]="and cat.";
    char c2[20]="love";
    char d2[20];//i love dog and cat

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
