#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){//找出字串從哪一位變成'\0'
    int len = 0;
    while(1)
    {
        if(s[len] != '\0')
            len++;
        else//如果出現'\0'就終止迴圈
        {
            break;
        }
    }
    return len;//回傳結果

}

int my_strcmp(const char*s1,const char*s2){

    int val = 0;//兩字元相等為0
    for(int i = 0; i < 20; i++)
    {
        if(s1[i] - s2[i] > 0)//判斷兩字元大小
        {
            val = 1;
            break;
        }
        if(s1[i] - s2[i] < 0)//判斷兩字元大小
        {
            val = -1;
            break;
        }
        //如果沒觸發到以上兩個判斷式回傳值就會保持為0
    }
    return val;//回傳結果
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
        if(s2[i] != '\0')//將s2不屬於空字元的部分寫入s1
        {
            s1[i] = s2[i];
        }
        else
        {
            s1[i] = '\0';
        }
    }
    return s1;//回傳結果
}

char *my_strcat(char *s1, const char *s2){
    int bgn = my_strlen(s1);//設定串接起始點
    for(int i = 0; i < my_strlen(s2); i++)
    {
        s1[bgn] = s2[i];//開始串接
        bgn++;//覆蓋下一個點
    }
    return s1;//回傳結果

}

char *my_strstr(const char *s1, const char *s2){
    int counter = 0;//計數器
    int bgn = 0;//設定輸出起始點
    for(int i = 0; i < my_strlen(s1); i++)//逐個檢查s1
    {
        for(int j = 0; j < my_strlen(s2); j++)//逐個檢查s2
        {
            if(s1[i] != s2[j])//如出現不符項目
            {
                counter = 0;//計數器歸零
                i = i - j;//將s1檢查點退回上次檢查位置
                break;//跳出s2檢查階段
            }
            else//符合項目
            {
                i++;//檢查下個s1
                counter++;
                if(counter == my_strlen(s2))//當計數器等於字串長度時
                {
                    bgn = i - my_strlen(s2);//設定起始輸出位置
                    break;//跳出迴圈
                }

            }
        }
        if(counter == my_strlen(s2))//當計數器等於字串長度時
        {
            break;//跳出s1s2比對階段
        }
    }
    if(bgn == 0)//如無符合項目
        return NULL;//回傳NULL
    else
        return (char*)s1 + bgn;//回傳結果

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
