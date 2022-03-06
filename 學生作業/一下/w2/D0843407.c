#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    //變數
    int input1=0;
    int arrlong=10,arr_full=0,strlong;
    char input_name[100];
    int bigsmall;
    char* temp;
    char **name;//宣告
    name = malloc ( arrlong * sizeof(char*) );//一維長度
    do{
        printf("\n學生姓名登記系統\n輸入以繼續\n 1.新增\n 2.印出\n 3.排序\n 4.離開\n\n");
        scanf("%d",&input1);
        if(input1==1){
            if(arr_full==10||(arr_full-10)%5==0&&arr_full!=0&&arr_full!=5){
                printf("hihi\n");
                arrlong+=5;
                name = realloc ( name , arrlong * sizeof(char*) );//一維10 15 20時加5
            }
            printf("\n新增姓名:");
            getchar();
            gets(input_name);//scanf含空白
            strlong=strlen(input_name)+1;
            name[arr_full] = calloc (strlong , sizeof(char));//第二維
            strcpy(name[arr_full],input_name);//複製進陣列
            arr_full++;//計算長度++
        }
        else if(input1==2){
            printf("\n姓名列表:\n");
            for(int i=0;i<arr_full;i++){
                printf("%s\n",name[i]);
            }
        }
        else if(input1==3){
                //泡沫排序法
            for(int i=0;i<arr_full-2;i++){
                for(int j=i+1;j<arr_full;j++){
                    bigsmall=strcmp(name[i],name[j]);
                    if(bigsmall==1){
                        //交換
                        temp=name[i];
                        name[i]=name[j];
                        name[j]=temp;
                    }
                }
            }
            printf("\n排序完成\n");
        }
    }while(input1!=4);
    //釋放記憶體
    for(int i=0;i<arrlong;i++){
        free(name[i]);
    }
    free(name);
}
