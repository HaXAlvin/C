#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int cho, count=0;//cho: 選擇, count: 用來計算名字的數量
    int i, j;
    printf("1.新增/2.印出/3.排序/4.離開: ");//提示輸入
    scanf("%d", &cho);//輸入選擇
    char **name=malloc(10*sizeof(char*));
    while(cho==1||cho==2||cho==3||cho==4){//若輸入為1或2或3或4，進入迴圈
        getchar();
        if(cho==1){//選擇1
            char temp[100]={0};//建立暫存姓名的陣列
            gets(temp);//輸入姓名
            name[count]=malloc((strlen(temp)+1)*sizeof(char));//配置字串長度+1('\0')的大小給name
            for(i=0;i<strlen(temp);i++)
                name[count][i]=temp[i];//將temp裡的字元逐一指派給配置好的name
            name[count][strlen(temp)]='\0';//陣列最後一個字元為'\0'
            count++;//名字的數量+1
            if(count>=10){//預設的10個空間用完了
                name=realloc(name, (count+5)*sizeof(char));//先增加5個空間
                if(count%5==1)//之後每用完5個空間(count是從0開始)
                    name=realloc(name, (count+5)*sizeof(char));//增加5個空間
            }
        }
        else if(cho==2){//選擇2
            for(i=0;i<count;i++)
                printf("%s\n", name[i]);//印出姓名
        }
        else if(cho==3){//選擇3
            char *tmp=NULL;
            for(i=0;i<count;i++){//泡沫排序begins
                for(j=0;j<i;j++){
                    if(strcmp(name[j], name[i])>0){
                        tmp=name[j];
                        name[j]=name[i];
                        name[i]=tmp;
                    }
                }
            }//泡沫排序ends
        }
        else if(cho==4){//選擇4
            for(i=0;i<count;i++)
                free(name[i]);//釋放第二維
            free(name);//釋放第一維
            return 0;
        }
        printf("1.新增/2.印出/3.排序/4.離開: ");//提示輸入
        scanf("%d", &cho);//輸入選擇
    }
}
