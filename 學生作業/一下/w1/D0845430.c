#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){
    int c=0;//c:字串長度
    while(s[c]!='\0')//當字串還沒遇到終止符號
        c++;//字串長度c+1
    return c;//回傳字串長度c
}

int my_strcmp(const char*s1,const char*s2){
    int i;
    for(i=0;i<20;i++){
        if(s1[i]==s2[i])//若s1與s2同一位置的字元相同
            continue;//繼續檢查
        else//若s1與s2同一位置的字元不相同
            return s1[i]-s2[i];//回傳s1與s2同一位置字元的ASCII相減值
    }
    return 0;//檢查完發現都一樣，回傳0
}

char *my_strcpy(char *s1, const char *s2){
    int i;
    for(i=0;i<20;i++)
        s1[i]=s2[i];//將s2該位置的字元指派給s1的同一位置上
    return s1;//回傳新的s1
}

char *my_strcat(char *s1, const char *s2){
    int i;
    int c=0, d=0;//c:s1字串長度, d:s2字串長度
    while(s1[c]!='\0')//當字串還沒遇到終止符號
        c++;//字串長度c+1
    while(s2[d]!='\0')//當字串還沒遇到終止符號
        d++;//字串長度d+1
    for(i=c;i<=c+d;i++)
        s1[i]=s2[i-c];//將s1的大小擴充到字串長度c與字串長度d相加的值, 並把s2裡的字元接到s1後
    return s1;//回傳新的s1
}

char *my_strstr(const char *s1, const char *s2){
    int c=0, d=0, loc=0;//c:s1字串長度, d:s2字串長度
    int i, j;
    while(s2[c]!='\0')//當字串還沒遇到終止符號//love
        c++;//字串長度c+1
    while(s1[d]!='\0')//當字串還沒遇到終止符號//i love dog and cat
        d++;//字串長度d+1
    char str[d];//將字元陣列大小預設為d的字串長度
    for(i=0;i<d;i++){
        if(s1[i]==s2[0]){//若s1檢查到的字元等於s2的第一個字元
            for(j=1;j<c;j++){
                if(s1[i+j]!=s2[j])//若s1的下一個字元不等於s2的下一個字元
                    break;//跳出迴圈, 再從s1的下一個字元重新檢查
                if(j==c-1)//如果檢查到s1的最後一個字元了還是等於s2的最後一個字元
                    loc=i;//把正在檢查的i值指派給代表位置的變數loc
            }
        }
    }
    for(i=0;i<d;i++)
        str[i]=s1[i+loc];//從得到的位置開始將字元指派給新的陣列
    return str;//回傳新陣列str
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
    puts(d2);

    printf("Strstr of d1 and c1:%s\n",strstr(d1,c1));
    printf("My_Strstr of d2 and c2:%s\n",my_strstr(d2,c2));
    printf("\n");

    return 0;
}
