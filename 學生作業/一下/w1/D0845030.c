#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){
    int count = 0;
    while(s[count] != '\0')
        count ++;
    return count;
}

int my_strcmp(const char*s1,const char*s2){
    int count = 0, num = 0;
    while(s1[count] != '\0')
        count ++;
    while(s2[num] != '\0')
        num ++;
    if(count == num)
        return 0;
    if(count > num)
        return -1;
    if(count < num)
        return 1;
}

char *my_strcpy(char *s1, const char *s2){
    int count = 0;
    while(s2[count] != '\0'){
        s1[count] = s2[count];
        count ++;
    }
    s1[count] = '\0';
    return s1;
}

char *my_strcat(char *s1, const char *s2){
    int count = 0, num = 0;
    while(s1[count] != '\0')
        count ++;//紀錄s1的長度
    while(s2[num] != '\0'){
        s1[count] = s2[num];
        num ++;
        count ++;
    }
    s1[count] = '\0';
    return s1;
}

char *my_strstr(const char *s1, const char *s2){
    int count = 0, num;
    int temp = 0;
    while(s1[count] != '\0'){
        temp = count;//紀錄count的值
        num = 0;
        while(s1[count] != '\0' && s2[num] != '\0'){
            if(s1[count] == s2[num]){//如果相同繼續比
                count ++;
                num ++;
            }
            else//如果不同換下個字元
                break;
        }
        if(s2[num] == '\0')
            return (char*)&s1[temp];
        count = temp;
        count++;
    }
    return NULL;
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
