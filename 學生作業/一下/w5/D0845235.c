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
    int choose_data;//1.int/2.float/3.char[16]
};

void add(struct Data *data,int count){//設一個call by reference函式
    printf("選擇類型：（1.int / 2.float / 3.char[16]）：");
    scanf("%d",&data[count].choose_data);
    while((data[count].choose_data!=1)&&(data[count].choose_data!=2)&&(data[count].choose_data!=3)){
        printf("輸入錯誤，請重新輸入\n");
        printf("選擇：（1.新增 / 2.印出 / 0.結束）：");
        scanf("%d",&data[count].choose_data);
    }
    if(data[count].choose_data==1){ //1.int
        printf("輸入資料（int）：");
        scanf("%d",&data[count].type.data_i);
    }
    else if(data[count].choose_data==2){ //2.float
        printf("輸入資料（float）：");
        scanf("%f",&data[count].type.data_f);
    }
    else if(data[count].choose_data==3){ //3.char[16]
        printf("輸入資料（char[16]）：");
        getchar();
        gets(data[count].type.data_s);
    }
}

int main(){
    struct Data* data = malloc(1*sizeof(struct Data));//struct宣告
    int choice;//1.新增/2.印出/0.結束
    int count=0;//計算幾筆資料
    while(1235){
        printf("選擇：（1.新增 / 2.印出 / 0.結束）：");
        scanf("%d",&choice);
        while((choice!=1)&&(choice!=2)&&(choice!=0)){
            printf("輸入錯誤，請重新輸入\n");
            printf("選擇：（1.新增 / 2.印出 / 0.結束）：");
            scanf("%d",&choice);
        }
        if(choice==1){//新增
            if(count>0){//第一筆資料後，每次增加一個struct大小的記憶體空間
                data = realloc(data,(count+1)*sizeof(struct Data));
            }
            add(data,count);//呼叫函式
            count+=1;
        }
        else if(choice==2){//印出
            for(int i=0 ;i<count ;i++){
                if(data[i].choose_data==1){
                    printf("%d\n",data[i].type.data_i);
                }
                else if(data[i].choose_data==2){
                    printf("%f\n",data[i].type.data_f);
                }
                else if(data[i].choose_data==3){
                    printf("%s\n",data[i].type.data_s);
                }
            }
        }
        else if(choice==0){//結束程式
            printf("離開此程式");
            free(data);
            return 0;
        }
    }
}
