#include<stdio.h>
#include<string.h>
#include<stdlib.h>

union dic{//整數、小數、字元陣列
    int num;
    float numwithdot;
    char word[16];
};

enum type{//整數、小數、字元陣列
    I,F,S,
};

struct array{//message、類別
    union dic kind;
    enum type t;
    struct array* next;
};

struct array add(struct array* Ptr){
    char wordtype;
    struct array* currentPtr = Ptr;
    while(currentPtr->next){//findEnd
        currentPtr=currentPtr->next;
    }
    struct array* tempPtr = calloc(1,sizeof(struct array));
    currentPtr->next=tempPtr;

    while(1){
        printf("選擇類型:(i:int/f:float/s:char[16]:");
        scanf("%c%*c",&wordtype);
        if(wordtype=='i'||wordtype=='f'||wordtype=='s')
            break;
        printf("輸入錯誤!\n");
    }
    if(wordtype=='i'){//輸入轉判別
        printf("輸入資料:");
        scanf("%d",&tempPtr->kind.num);
        tempPtr->t=I;
    }
    else if(wordtype=='f'){
        printf("輸入資料:");
        scanf("%f",&tempPtr->kind.numwithdot);
        tempPtr->t=F;
    }
    else if(wordtype=='s'){
        printf("輸入資料:");
        gets(tempPtr->kind.word);
        tempPtr->t=S;
    }
}

void freeArray(struct array* currentPtr){//遞迴
    if(currentPtr->next){
        freeArray(currentPtr->next);
    }
    free(currentPtr);
}

int main(){
    int times = 0;//起始零
    int option = 0;//選項
    struct array* headPtr = calloc(1,sizeof(struct array));//宣告第零個結構
    while(1){
        printf("選擇:(1.新增/2.印出/0.結束):");
        scanf("%d%*c",&option);
        if(option==0){//free(struct)
            printf("結束程式\n");
            freeArray(headPtr);
            return 0;
        }
        else if(option==1){//新增
            add(headPtr);
        }
        else if(option==2){//列印
            struct array* currentPtr = headPtr->next;//從第一個開始印
            while(currentPtr){
                if(currentPtr->t==I){//判別
                    printf("%d\n",currentPtr->kind.num);
                }
                else if(currentPtr->t==F){
                    printf("%f\n",currentPtr->kind.numwithdot);
                }
                else if(currentPtr->t==S){
                    puts(currentPtr->kind.word);
                }
                currentPtr=currentPtr->next;
            }
        }
        else//防呆
            printf("輸入錯誤!\n");
    }
}
