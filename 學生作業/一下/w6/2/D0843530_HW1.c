#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef union _information{ //用不同型態的變數去存輸入的資料
    int i;
    float f;
    char s[16];
}information;


typedef struct _array{  //拿來存資料
    information infor;
    char type;
    struct _array *nextptr; //下一個資料的位置
}array;

void scan(array *arr){  //選擇資料型態及輸入資料
    while(1){
        printf("選擇類型：(i：int/f：float/s：char[16])：");
        getchar();
        scanf("%c",&arr->type);
        printf("輸入資料：");
        if(arr->type == 's'){
            scanf("%s",&arr->infor.s);
            break;
        }
        else if(arr->type == 'i'){
            scanf("%d",&arr->infor.i);
            break;
        }
        else if(arr->type == 'f'){
            scanf("%f",&arr->infor.f);
            break;
        }
        else{
            printf("輸入錯誤！\n");
            continue;
        }
    }

}

int main(){
    int now = 0,chose,i;
    array *head = NULL,*currentarr = NULL,*tmp,*current;
    while(1){
        printf("選擇：(1.新增/2.印出/0.結束)：");
        scanf("%d",&chose);  //選擇新增印出結束
        if(chose == 1){  //新增資料
            if(head == NULL){  //若沒有資料 讓他當開頭
            	head = malloc(sizeof(array));
            	currentarr = head;
			}
            else {  //如果前面有了 就讓nextptr = 下一個資料存的地方
            	currentarr->nextptr = malloc(sizeof(array));
            	currentarr = currentarr->nextptr;
			}
			currentarr->nextptr = NULL;
            scan(currentarr); //輸入啦
        }
        else if(chose == 2){  //印出
            current = head;
            while(current != NULL){
                if(current->type == 'i') { //記得判斷型態 再決定怎麼印出
                    printf("%d\n",current->infor.i);
                }
                else if(current->type == 'f'){
                    printf("%f\n",current->infor.f);
                }
                else{
                    printf("%s\n",current->infor.s);
                }
                current = current->nextptr;
            }
        }
        else if(chose == 0){  //把空間free掉
            printf("結束程式\n");
            currentarr = head;
            while(currentarr != NULL){
                tmp = currentarr->nextptr;
                free(currentarr);
                currentarr = tmp;
            }
            head = NULL;
            break;
        }
        else {  //就012你還會輸錯!
            printf("輸入錯誤！\n");
            continue;
        }
    }

}

