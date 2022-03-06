#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char **name;//存名字
    char temp[50];//暫存姓名
    char *name_temp;
    int choice,i,j,k;
    int length=0;//字串長度
    int num=0;//記錄幾筆資料
    int a=2;
    name=malloc(10*sizeof(char*));//另一維大小為10個char
    while(1){
        scanf("%d",&choice);//選擇功能
        getchar();
        switch(choice){
            case 1:
                gets(temp);//新增名字
                length=strlen(temp);//偵測字串大小
                if (num>5*a){//當一維空間大於10，則分配多五個空間
                    name=realloc(name,(5*(a+1))*sizeof(char*));
                    a++;
                }

                name[num]=calloc((length+1),sizeof(char));//設二維空間為字串大小加一，因為有'\0'
                for (i=0;i<=length;i++){
                    name[num][i]=temp[i];//讓值輸入進動態二維陣列裡
                }
                num++;

                break;
            case 2:
                for(i=0;i<num;i++)//印出名字
                    printf("%s\n",name[i]);

                break;
            case 3:

                for(i=0;i<num;i++){//氣泡排序
                    for (j=i;j<num;j++){
                        k=strcmp(name[j],name[i]);//是否相等，不相等則交換
                        if (k==0){
                            continue;
                        }
                        else if (k==-1){

                            name_temp=name[j];//用址交換
                            name[j]=name[i];
                            name[i]=name_temp;

                        }
                    }
                }
                break;


        }
        if (choice==4){
            for (i=0;i<num;i++){//釋放二維
                free(name[num]);
            }
            free(name);//釋放一維
            break;
        }
    }





}
