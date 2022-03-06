#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void add(char **a,int b) //存入的函式
{
    char temp[500]; //暫存空間
    gets(temp);
    int len=strlen(temp); //存入的字串長度
    a[b-1]=malloc((len+1)*sizeof(char)); //建立一個空間在二維陣列的第二維
    strcpy(a[b-1],temp); //複製進去
    return;

}
void sort(char **a,int b) //排序的函示
{
    //泡沫排序
    for (int i=0;i<b;i++){
        for (int j=0;j<i;j++){
            if (strcmp(*(a+i),*(a+j))==-1){
                char temp[500]; //暫存的字串
                char *ptr1=a[i];
                char *ptr2=a[j];
                char *ptr; //暫存的指標
                strcpy(temp,a[i]);
                //指標互換位置
                ptr=ptr1;
                ptr1=ptr2;
                strcpy(a[i],a[j]);
                ptr2=ptr1;
                strcpy(a[j],temp);
            }
        }
    }
}


int main()
{
    int n,count=0,num1=10;
    char **nameArr;
    nameArr=malloc(10*sizeof(char*));//建立第一維
    printf("學生姓名登記系統\n");
    while (1){
        printf("1.新增2.印出3.排序4.離開:");
        scanf("%d%*c",&n); //判斷做哪一個動作

        if (n==1){ //新增
            count++;
            if (count>num1){
                nameArr=realloc(nameArr,(count+5)*sizeof(char*)); //位置不足時增加5個空間
                num1+=5;
            }
            add(nameArr,count);
        }
        else if (n==2){ //動作
            for (int i=0;i<=count-1;i++){
                printf("%s\n",nameArr[i]);
            }
        }
        else if (n==3){ //排序
            sort(nameArr,count);
            printf("排序完成\n");
        }
        else if (n==4){ //離開並釋放
            for (int j=0;j<count;j++){
                free(nameArr[j]);
            }
            free(nameArr);
            break;
        }

        else
            printf("\n輸入錯誤\n\n");
    }
}
