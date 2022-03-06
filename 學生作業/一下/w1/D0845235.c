#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s) {
    int i=0;
    for(i=0; s[i]!='\0'; i++);//s1[i]!='\0'，不是结束符號就循環繼續查找
    return i;
}

int my_strcmp(const char*s1,const char*s2) {
    int i=0;
    for(i=0; (s1[i]!='\0')&&(s2[i]!='\0'); i++) { //s1[i]!= '\0'，s2[i]!='\0'，不是结束符號就循環繼續查找
        if(s1[i]<s2[i]) {//如果s1[i]<s2[i]就回傳-1
            return -1;
        }
        if(s1[i]!=s2[i]) {//如果s1[i]不等於s2[i]就回傳1
            return 1;
        }
    }//如果兩個字串長度不一樣，則此迴圈只會判斷到短的那個迴圈，因此要再迴圈外判斷一次長的迴圈剩下沒判斷到的部分
    if(s1[i]<s2[i]) {//如果s1[i]<s2[i]就回傳-1
        return -1;
    }
    if(s1[i]!=s2[i]) {//如果s1[i]不等於s2[i]就回傳1
        return 1;
    }
    return 0;//兩字串相等就回傳0
}

char *my_strcpy(char *s1, const char *s2) {
    int i=0;
    while(s1[i]!='\0'||s2[i]!='\0') {//如果s2中有小於s1長度的會被覆盖，而大于s1長度的將保留
        s1[i] = s2[i];
        i++;
    }
    return s1;

}

char *my_strcat(char *s1, const char *s2) {//先計算s1長度再根據s2的長度來找最後的指標
    int i=0,j=0;
    for(i=0; s1[i]!='\0'; i++);//s1[i]!= '\0'
    for(j=0; (s1[j]!='\0')&&(s2[j]!='\0'); j++) {//計算到最後一個指標
        s1[i+j]=s2[j];
    }
    return s1;
}

char *my_strstr(const char *s1, const char *s2) {
    int i=0,j=0,k=0;
    for (i=0; s1[i]!='\0'; i++) {//先計算s1長度
        for (j=0,k=i; s1[j]!='\0'&&s1[k]==s2[j]; j++, k++);//比對出s2的位址
        if (s2[j] == '\0')//計算s2
            return (char*)&s1[i];
    }
    return NULL;
}

int main() {
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
