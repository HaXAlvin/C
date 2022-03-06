#include <stdio.h>
#include <stdlib.h>

typedef union{ //儲存資料的型態
    int i_data; //整數
    float f_data; //浮點數
    char s_data[16]; //字串
}Type;

typedef struct{ //存放資料的結構
    Type type; //資料
    char choosetype; //資料型態
}Data;

void inputnewdata(int num, Data *arr){ //新增資料
    while(1){ //選擇的資料型態超出限制
        printf("選擇類型：(i：int/f：float/s：char[16])：");
        getchar();
        scanf("%c", &arr[num].choosetype);
        if(arr[num].choosetype == 'i' || arr[num].choosetype == 'f' || arr[num].choosetype == 's')
            break;
        printf("輸入錯誤!\n");
    }
    printf("輸入資料：");
    if(arr[num].choosetype == 'i') //整數型態資料
        scanf("%d", &arr[num].type.i_data);
    else if(arr[num].choosetype == 'f') //浮點數型態資料
        scanf("%f", &arr[num].type.f_data);
    else if(arr[num].choosetype == 's'){ //字串型態資料
        getchar();
        gets(arr[num].type.s_data);
    }
}

void printdata(int num, Data *ans){ //印出新增的所有資料
    int i;
    for(i=0;i<num;i++){
        if(ans[i].choosetype == 'i') //印出整數
            printf("%d\n", ans[i].type.i_data);
        else if(ans[i].choosetype == 'f') //印出浮點數
            printf("%f\n", ans[i].type.f_data);
        else if(ans[i].choosetype == 's') //印出字串
            printf("%s\n", ans[i].type.s_data);
    }
}

int main(){
    int choose = 0,datanum = 0;
    Data *data;
    while(1){
        printf("選擇：(1.新增/2.印出/0.結束)；");
        scanf("%d", &choose);
        if(choose == 0){
            printf("結束程式");
            free(data); //釋放記憶體
            return 0;
        }
        else if(choose == 1){
            if(datanum == 0) //原陣列長度為0
                data = malloc(1 * sizeof(Data)); //增加1個struct大小的記憶體空間
            else
                data = realloc(data, (datanum+1) * sizeof(Data)); //增加1個struct大小的記憶體空間
            inputnewdata(datanum, data); //新增資料
            datanum += 1; //資料數+1
        }
        else if(choose == 2){ //印出所有新增資料
            printdata(datanum, data);
        }
        else if(choose < 0 || choose > 2) //輸入超出限制
            printf("輸入錯誤!\n");
    }
}
