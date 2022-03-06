#include<stdio.h>
#include<stdlib.h>
#include<string.h>

union Type{ //定義
    int data_i;//整數型
    float data_f;//小數型
    char data_s[16];//字串
};

struct Data{//struct的定義
    union Type type;//union變數的宣告
    int choose;//1.int/2.float/3.char[16]
    struct Data *nextPtr;//自我參考指標成員
};

void add(struct Data *data){//設一個call by reference函式
    printf("選擇類型：（1.int / 2.float / 3.char[16]）：");
    scanf("%d",&data->choose);
    getchar();
    while((data->choose!=1)&&(data->choose!=2)&&(data->choose!=3)){
            printf("輸入錯誤，請重新輸入\n");
            printf("選擇類型：（1.int / 2.float / 3.char[16]）：");
            scanf("%d",&data->choose);
    }
    if(data->choose==1){ //1.int
        printf("輸入資料（int）：");
        scanf("%d",&data->type.data_i);
    }
    else if(data->choose==2){ //2.float
        printf("輸入資料（float）：");
        scanf("%f",&data->type.data_f);
    }
    else if(data->choose==3){ //3.char[16]
        printf("輸入資料（char[16]）：");
        gets(data->type.data_s);
    }
}

int main(){
    struct Data *data = malloc(sizeof(struct Data));//struct宣告
    struct Data *currentPtr = data;//設一個暫存存頭
    int choice;//1.新增/2.印出/0.結束
    while(1235){
        printf("選擇：（1.新增 / 2.印出 / 0.結束）：");
        scanf("%d",&choice);
        while((choice!=1)&&(choice!=2)&&(choice!=0)){
            printf("輸入錯誤，請重新輸入\n");
            printf("選擇：（1.新增 / 2.印出 / 0.結束）：");
            scanf("%d",&choice);
        }
        if(choice==1){//新增
            struct Data *newPtr = malloc(sizeof(struct Data));//新增一個結構
            add(newPtr);//呼叫函式
            currentPtr->nextPtr=newPtr;//新的指標為目前指標的下一個
            currentPtr=currentPtr->nextPtr;//目前指標指向下一個指標
            currentPtr->nextPtr= NULL;//目前指標的是空字串
        }
        else if(choice==2){//印出
            struct Data* lemon = data;//設一個暫存lemon
            while(lemon!=NULL){
                if(lemon->choose==1){
                    printf("%d\n",lemon->type.data_i);
                }
                else if(lemon->choose==2){
                    printf("%f\n",lemon->type.data_f);
                }
                else if(lemon->choose==3){
                    printf("%s\n",lemon->type.data_s);
                }
                lemon = lemon->nextPtr;
            }
        }
        else if(choice==0){//結束程式
            printf("離開此程式");
            free(data);
            return 0;
        }
    }
}
