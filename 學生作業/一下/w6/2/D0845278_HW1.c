#include <stdio.h>
#include <stdlib.h>

typedef union {
    int num;//計數字
    float f_num;//計小數
    char word[16];//計字串
} Save;

typedef struct data {
    Save save;//union
    char input;//類型輸入
    struct data *nextPtr;//鏈結串列
} Data;

void save_data(Data *ans) {
    while(1) {
        printf("選擇類型:(i:int/f:float/s:char[16]):");
        getchar();
        scanf("%c",&ans->input);//輸入指向Data類型輸入
        if(ans->input == 'i') {
            printf("輸入資料:");
            scanf("%d",&ans->save.num);//存入union
            //printf("%d\n",ans->save.num);
            break;
        } else if(ans->input == 'f') {
            printf("輸入資料:");
            scanf("%f",&ans->save.f_num);//存入union
            break;
        } else if(ans->input == 's') {
            printf("輸入資料:");
            scanf("%s",ans->save.word);//存入union
            break;
        } else {//防呆
            printf("輸入錯誤!請重新輸入\n");
            continue;
        }
    }
}

int main() {
    Data *ans = malloc(sizeof(Data));//建立動態陣列
    Data *currentPtr = ans;
    int choice;
    printf("選擇:(1.新增/2.印出/0.結束):");
    while(1) {
        scanf("%d",&choice);
        if(choice!=0&&choice!=1&&choice!=2) {//防呆
            printf("輸入錯誤!\n");
            printf("選擇:(1.新增/2.印出/0.結束):");
            continue;
        }
        if(choice==0) {//結束
            printf("結束程式\n");
            free(ans);//釋放記憶體
            return 0;
        } else if(choice==1) { //新增
            Data *newPtr = malloc(sizeof(Data));//建立動態陣列
            save_data(newPtr);//進入函式
            currentPtr->nextPtr = newPtr;//使newPtr指向下一個
            currentPtr = currentPtr->nextPtr;//使curr...指向下個node
            currentPtr->nextPtr = NULL;//預設下個node為NULL
            printf("選擇:(1.新增/2.印出/0.結束):");
        } else if(choice==2) { //印出
            Data* run = ans->nextPtr;
            while(run != NULL) {//到空字串停
                if(run->input == 'i') {//判斷類型後印出
                    printf("%d\n",run->save.num);
                } else if(run->input == 'f') {
                    printf("%f\n",run->save.f_num);
                } else if(run->input == 's') {
                    printf("%s\n",run->save.word);
                }
                run=run->nextPtr;//印完換下一個
            }
            printf("選擇:(1.新增/2.印出/0.結束):");
        }
    }
}

