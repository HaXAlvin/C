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
        // s1 比 s2 早出現空字元
        if(*(s1 + num)=='\0' && *(s2 + num)!='\0'){
            return 1;
        }
        // s2 比 s1 早出現空字元
        if(*(s1 + num)!='\0' && *(s2 + num)=='\0'){
            return -1;
        }
        // 同時出現空字元
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
    //s1 的長度
    int num = 0;
    //計算 s1 的長度
    while(*(s1 + num)!='\0'){
        num++;
    }
    int count = 0;
    //從 s1 的末位置開始接上 s2 直到 s2 為空字元
    while(*(s2 + count)!='\0'){
        *(s1 + num) = *(s2 + count);
        num++;
        count++;
    }
    return s1;
}

char *my_strstr(const char *s1, const char *s2){
    //控制 s1 的第 num 項
    int num = 0;
    //用於回傳 若 num1 為 2147483647 為 NULL
    int num1 = 2147483647;
    //計算符合的字數
    int YN = 0;
    //最外層while控制 s1 的第 num 項
    while(*(s1 + num)!='\0'){
        //控制 s2 的第 count 項
        int count = 0;
        //若 s1 的第 num 項和 s2 的第 count 項相等
        if(*(s1 + num) == *(s2 + count)){
            YN = 0;
            //s2 在 s1 的第 num1 項開始出現
            num1 = num;
            //當 s2 的文字出現在 s1 檢查 s2 後的每個字元是否都和 s1 相等
            while((*(s2 + count) == *(s1 + num)) && (*(s2 + count)!='\0')){
                if(*(s2 + count) == *(s1 + num)){
                    count++;
                    num++;
                    YN++;
                    //若下一項不相等則先判定為 NULL
                    if(*(s2 + count) != *(s1 + num) && (*(s2 + count)!='\0')){
                        num1 = 2147483647;
                    }
                }else{
                    num1 = 2147483647;
                    break;
                }
            }
        }
        //確定 s2 已在 s1 出現就中止迴圈
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
