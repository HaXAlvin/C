#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){
    int count=0;//宣告
    for(int i=0;;i++){//計算長度
        if(s[i]=='\0'){//當讀到\0停止
            break;
        }
        count++;
    }
    return count;//回傳
}

int my_strcmp(const char*s1,const char*s2){
    int count1 = 0,count2 = 0;//宣告
    for(int i=0;;i++){//將s1每一項相加迴圈
        if(s1[i]=='\0'){//當讀到\0停止
            break;
        }
        count1+=s1[i];
    }
    for(int i=0;;i++){//將s1每一項相加迴圈
        if(s2[i]=='\0'){//當讀到\0停止
            break;
        }
        count2+=s2[i];
    }
    //s1 s2比大小
    if(count1>count2){
        return -1;//回傳
    }
    else if(count1<count2){
        return 1;//回傳
    }
    else{
        return 0;//回傳
    }
}

char *my_strcpy(char *s1, const char *s2){
    for(int i=0;i<=19;i++){//歸0s1陣列
        s1[i]='\0';
    }
    for(int i=0;;i++){//將s2塞到s1裡
        if(s2[i]=='\0'){//當讀到\0停止
            break;
        }
        s1[i]=s2[i];
    }
    return s1;//回傳
}

char *my_strcat(char *s1, const char *s2){
    int count1 = 0,count2 = 0;
    for(int i=0;;i++){//計算s1長度
        if(s1[i]=='\0'){//當讀到\0停止
            break;
        }
        count1++;
    }
    for(int i=0;;i++){//計算s2長度
        if(s2[i]=='\0'){//當讀到\0停止
            break;
        }
        count2++;
    }
    for(int i=0;i<count2;i++){//將s2塞到s1後
        s1[i+count1]=s2[i];
    }
    return s1;
}

char *my_strstr(const char *s1, const char *s2){
    int is_s2=0,count;//宣告
    for(int i=0;;i++){
        if(s1[i]=='\0'){//當讀到\0停止
            break;
        }
        else if(s1[i]==s2[0]){
            for(int j=0;;j++){
                if(s2[j]=='\0'){
                    is_s2=1;//都相同 flag
                    count=i;//紀錄開始相同的位置
                    break;
                }
                else if(s1[i+j]!=s2[j]){//不相等
                    break;
                }
            }
        }
        else;
    }
    //
    if(is_s2==1){//如果flag有觸發
        for(int i=count;;i++){//從相同的位置 開始回傳
            if(s1[i]=='\0'){
                break;
            }
            return (char*)&s1[i];//回傳
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
