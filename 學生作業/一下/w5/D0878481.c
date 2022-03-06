#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int type;
    union{
        int a;
        float b;
        char c[16];

    }center;

}arr;
void change(arr *temp,char temp1){//call by reference
    char inputchar[16];//暫存字串空間的變數
    if (temp1=='i'){//型態為整數
        temp->type=1;//紀錄型態為整數
        scanf("%d",&(temp->center).a);//將輸入資料存進結構的a
        return;
    }
    else if(temp1=='f'){//型態為小數
        temp->type=2;//型態為小數
        scanf("%f",&(temp->center).b);//將輸入資料存進結構的b
        return;
    }
    else {
        temp->type=3;//型態為字串
        scanf("%s",&inputchar);//輸入
        strcpy((temp->center).c,inputchar);//copy進結構的c
    }

}

int main(){
    arr *data;//指標結構
    int i;
    int count=0;//紀錄第幾組資料
    int input;//選擇功能，輸入的資料
    char inputtype;//資料型態
    while(1){
        printf("選擇:(1.新增/2.印出/0.結束):");
        scanf("%d",&input);
        if(input>2){//防呆
            printf("輸入錯誤!");
            continue;
        }
        if (input==0){//為0結束程式
            for (i=0;i<count;i++){
                free(data);
            }
            break;
        }
        switch(input){
            case 1:
                if(count==0)//新增記憶體空間
                    data=malloc(1*sizeof(arr));

                else
                    data=realloc(data,(count+1)*sizeof(arr));//第二筆資料以後的空間創立

                printf("選擇類型:(i = int/f = float/s = char[16]):");
                getchar();
                scanf("%c",&inputtype);//輸入類型
                if ((inputtype!='i')&&(inputtype!='f')&&(inputtype!='s')){//防呆
                    printf("輸入錯誤!\n");
                    continue;
                }
                printf("輸入資料:");
                if (inputtype=='i'){//整數
                    change(data+count,inputtype);
                }
                else if (inputtype=='f'){//小數
                    change(data+count,inputtype);
                }
                else{//字串
                   change(data+count,inputtype);
                }

                count++;//計數加1
                break;
            case 2:

                for (i=0;i<count;i++){//印出所存的資料
                    if (data[i].type==1){//為整數的話
                        printf("%d\n",data[i].center.a);
                    }
                    else if (data[i].type==2){//為小數的話
                        printf("%f\n",data[i].center.b);
                    }
                    else{//為字串的話
                        printf("%s\n",data[i].center.c);
                    }

                }
                break;
        }

    }

}


