#include<stdio.h>
#include<string.h>
#include<stdlib.h>

size_t my_strlen(const char*s){
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
//    for(i = 0;i < 20;i++){ //讀取字串結尾
//        if(s[i] == '\0'){
//            tmp = i;
//            break;
//        }
//    }     //這裡會局限字串大小
    //printf("%p %p %s %d",sptr1,sptr1 + tmp,s,tmp);
    return i;
}

int my_strcmp(const char*s1,const char*s2){
    if (s1[0] > s2[0]) return 1;
    else if(s1[0] == s2[0]) return 0;
    else return -1;
}

char *my_strcpy(char *s1, const char *s2){
    int i;
    for(i = 0;i <= my_strlen(s2);i++){ //要多給一個 把'\0'算進去 完整複製字串
        s1[i] = s2[i];
    }
    return s1;
}

char *my_strcat(char *s1, const char *s2){
    int i,tmp;
    tmp = my_strlen(s1); //計算s1結尾
    for(i = 0;i < my_strlen(s2);i++){ //接起來
        s1[tmp+i] = s2[i];
        //printf("%c",s1[tmp + i]);
    }
    //printf("%s",s1);
    return s1;
}

char *my_strstr(const char *s1, const char *s2){
    int i,j,fail = 0;
    char *tmp;
    for(i = 0;i < my_strlen(s1)&&fail == 0;i++){
        if(s1[i] == s2[0]){
            tmp = (char*)(s1 + i);
            //s1是常數型態 要先轉為非常數型態 回傳的是非常數型態的位址
            for(j = 1;j < my_strlen(s2);j++){
                if(s1[i+j] != s2[j]){
                    fail = 0;
                    break;
                }
                else{
                    fail = 1;
                }
            }
        }
    }
    //printf("%d %p %p %d",fail,tmp,s1,i);
    if(fail == 1){
        return tmp;
    }
    else return NULL;
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
