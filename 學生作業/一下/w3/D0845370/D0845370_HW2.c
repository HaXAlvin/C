#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp1(char *s1, char *s2){ //ASCII排序
    if(strcmp(s1,s2) == 1) //前面比較大,需交換
        return 1;
    else if(strcmp(s1,s2) == -1 || strcmp(s1,s2) == 0)
        return 0;
}

int cmp2(char *s1, char *s2){ //字典排序
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int range = 0;
    if(len1 >= len2) //for迴圈需要跑的次數
        range = len1;
    else
        range = len2;
    for(int i=0;i<range;i++){
        if((s1[i]>64 && s1[i]<91) && (s2[i]>96 && s2[i]<123)){ //前面大寫,後面小寫
            if(s1[i]+32 > s2[i]) //前面較大需交換
                return 1;
            else
                return 0;
        }
        else if((s1[i]>96 && s1[i]<123) && (s2[i]>64 && s2[i]<91)){ //前面小寫,後面大寫
            if(s1[i] >= s2[i]+32) //前面較大需交換
                return 1;
            else
                return 0;
        }
        else if(((s1[i]>64 && s1[i]<91) &&(s2[i]>64 && s2[i]<91)) || ((s1[i]>96 && s1[i]<123) && (s2[i]>96 && s2[i]<123))){ //前後都大寫 或 前後都小寫
            if(s1[i] > s2[i]) //前面較大需交換
                return 1;
            else //繼續比較下一個字元
                continue;
        }
        return 0; //若是前後完全一樣則不須交換
    }
}

void sort(char **sArr,int n,int (*cmp)(char *, char *)){ //交換
    for(int i=(n-1);i>0;i--){
        for(int j=0;j<i;j++){
            if(cmp(sArr[j],sArr[j+1]) == 1){ //若是比較須前後交換
                char *temp = sArr[j];
                sArr[j] = sArr[j+1];
                sArr[j+1] = temp;
            }
        }
    }
}

int main(){
    while(1){
        int strnum = 0,count_num = 0,choose = 0;
        printf("請輸入字串數(輸入0結束)：");
        scanf("%d", &strnum); //字串數
        if(strnum == 0)
            return 0;
        char **sArr = malloc(strnum * sizeof(char *)); //第一維大小
        getchar();
        while(count_num < strnum){ //輸入所有字串
            char tmp[500] = {0};
            gets(tmp);
            int len = strlen(tmp);
            sArr[count_num] = malloc(len * sizeof(char)); //第二維大小
            strcpy(sArr[count_num],tmp);
            count_num += 1;
        }
        printf("請選擇排序方式(1. 以ASCII/2. 以字典序)：");
        scanf("%d", &choose);
        if(choose == 1)
            sort(sArr,strnum,cmp1);
        else if(choose == 2)
            sort(sArr,strnum,cmp2);
        for(int i=0;i<strnum;i++) //印出排序後結果
            printf("%s\n",sArr[i]);
        for(int i=0;i<strnum;i++) //釋放所有空間
            free(sArr[i]);
        free(sArr);
    }
}
