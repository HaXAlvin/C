#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){
    int count=0;
    while(s[count]!='\0'){//如果值不等於\0，count+1
        count++;
    }
    return count;//回傳count

}

int my_strcmp(const char*s1,const char*s2){
    int count=0;
    while(s1[count]==s2[count]){//當值相同時
        if ((s1[count]=='\0')&&(s2[count]=='\0')){//如果末值都剛好為\0
            return 0;
        }

        count++;//往下一個為值比對

    }
    if (s1[count]>s2[count]){//不相同時，左比右打
        return 1;
    }
    else//左比右小
        return -1;

}

char *my_strcpy(char *s1, const char *s2){
    int count=0;
    while(s2[count]!='\0'){//當值不為\0時
        s1[count]=s2[count];//將要複製字串逐一塞入
        count++;
    }
    if (s2[count]=='\0'){//當s2末值為\0
        s1[count]='\0';//將\0塞入s1的末值
    }
    return s1;






}

char *my_strcat(char *s1, const char *s2){
    int count=0;
    int count1=0;
    while(s1[count]!='\0'){//先塞入自己的值
        s1[count]=s1[count];
        count++;//計算出長度
    }
    while(s2[count1]!='\0'){
        s1[count]=s2[count1];//從最末端塞入s2的頭
        count++;
        count1++;
    }


    return s1;
}

char *my_strstr(const char *s1, const char *s2){

    int count=0;
    int count1=0;
    while(1){

        char *s3=(char*)&s1[count];//設變數存取位置
        while (s1[count]==s2[count1]){//當陣列中字元一樣時往下比對
            count1++;
            count++;
        }
        if (s2[count1]=='\0'){//跳出迴圈時，如果s2最後的位置是\0,則回傳一起初相同的位置
            return s3;

        }
        if(s1[count]=='\0'){//如果s1最後為\0則沒有相同字串
            return NULL;
        }
        count++;//上述都不成立，則將count+1，去找出符合字串的位置
        count1=0;//把紀錄s2的count歸0

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
