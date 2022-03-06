#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{//結構陣列
    union{
        int score1;
        float score2;
        char name[16];
    }union1;
    int count;
}array;
int main()
{
    int i=0;
    array num[100];//叫出結構
    int n;
    int m;
    while(1){//一直做下去直到輸入0
        printf("選擇：(1.新增/2.印出/0.結束)：");
        scanf("%d",&n);
        if(n==0)//結束
            break;
        else if(n==1){//新增
            printf("選擇類型：(1：int/2：float/3：char[16])：");//選擇輸入類型
            scanf("%d",&num[i].count);
            if(num[i].count==1){
                printf("輸入資料：");
                scanf("%d",&num[i].union1.score1);
            }
            if(num[i].count==2){
                printf("輸入資料：");
                scanf("%f",&num[i].union1.score2);
            }
            if(num[i].count==3){
                printf("輸入資料：");
                scanf("%s",&num[i].union1.name);
            }
            i++;
        }
        else if(n==2){//印出
            m=i;
            for(i=0;i<m;i++){//由最前輸入印到最後輸入
                if(num[i].count==1)
                    printf("%d\n",num[i].union1.score1);
                if(num[i].count==2)
                    printf("%f\n",num[i].union1.score2);
                if(num[i].count==3)
                    printf("%s\n",num[i].union1.name);
            }
        }
        else{//輸入錯誤就重來
            printf("輸入錯誤!\n");
            continue;
        }
    }
}
