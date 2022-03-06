#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp1(char *a,char *b) { //ASCII排序
    if(strcmp(a,b)>0)//比大小
        return 1;
    else
        return 0;
}

int cmp2(char *a,char *b) { //字典排序
    int i,j;
    int len_a = strlen(a);
    int len_b = strlen(b);
    char temp_a[1000] ;//提供更改的暫存
    char temp_b[1000] ;
    strcpy(temp_a,a);
    strcpy(temp_b,b);
    for(i=0; i<len_a; i++) {//把小寫轉大寫
        if(a[i]>'Z')
            temp_a[i]-=32;
    }
    for(i=0; i<len_b; i++) {
        if(b[i]>'Z')
            temp_b[i]-=32;
    }
    //a>b傳1
    if(len_a>=len_b) {
        for(i=0; i<len_a; i++) {
            if(temp_b=='\0')//先結束在前面
                return 0;
            if(temp_a[i]>temp_b[i])
                return 1;
             else if(temp_a[i]==temp_b[i]) {//相同的話比較原本的字串
                if(a[i]<b[i])
                    return 0;
                else if(a[i]>b[i])
                    return 1;
                else if(a[i]==b[i])
                    continue;
            } else if(temp_a[i]<temp_b[i])
                return 0;
        }
    } else if(len_a<len_b) {//同上
        for(i=0; i<len_a; i++) {
            if(temp_a=='\0')
                return 1;
            if(temp_a[i]>temp_b[i])
                return 1;
            else if(temp_a[i]==temp_b[i]) {
                if(a[i]<b[i])
                    return 0;
                else if(a[i]>b[i])
                    return 1;
                else if(a[i]==b[i])
                    continue;
            } else if(temp_a[i]<temp_b[i])
                return 0;
        }
    }
}

void sort(char sArr[][100],int n,int(*cmp)(char *,char *)) {
    int i,j;
    char tmp[1000];
    for(i=0; i<n; i++) {
        for(j=0; j<n-1-i; j++) {
            if(cmp(sArr[j],sArr[j+1])==1) {//排序
                strcpy(tmp,sArr[j]);
                strcpy(sArr[j],sArr[j+1]);
                strcpy(sArr[j+1],tmp);
            }
        }
    }
}

int main() {
    int num;
    int choise;
    int i;
    char sArr[1000][100];
    printf("請輸入字串數(輸入0結束) : ");
    while(scanf("%d",&num)!=EOF) {
        if(num==0)
            return 0;
        else if(num<0) {//防呆
            printf("輸入錯誤!\n");
            printf("請輸入字串數(輸入0結束) : ");
            continue;
        } else {
            for(i=0; i<num; i++) {
                scanf("%s",sArr[i]);
            }
            printf("選擇排序方式(1. 以ASCII/2. 以字典序) : ");
            scanf("%d",&choise);
            if(choise==1) {//選擇進入哪個函式
                sort(sArr,num,cmp1);
                for(i=0; i<num; i++) {
                    printf("%s",sArr[i]);
                    printf("\n");
                }
            } else if(choise==2) {
                sort(sArr,num,cmp2);
                for(i=0; i<num; i++) {
                    printf("%s",sArr[i]);
                    printf("\n");
                }
            }
        }
        printf("請輸入字串數(輸入0結束) : ");
    }
}
