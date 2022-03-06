#include <stdio.h>
#include <stdlib.h>

typedef struct node *NodePtr;//自我參考結構

typedef union{
    int i;
    float f;
    char s[16];
}Value;

typedef struct node{
    char type;
    Value val;
    NodePtr nextPtr;
}Data;

int scanData(Data *newData){ //選擇類型
    printf("選擇類型：(i：int/f：float/s：char[16])：");
    scanf("%c%*c", &(newData->type));
    if(newData->type != 'i' && newData->type != 'f' && newData->type != 's'){
        printf("輸入錯誤!\n");
        return 0;
    }
    printf("輸入資料：");
    return 1;
}

void addNode(NodePtr *ptr, Data *data){//輸入資料
    NodePtr newPtr = malloc(sizeof(Data));//鏈結串列
    newPtr->nextPtr = NULL;
    switch(data->type){
        case 'i':
            scanf("%d", &newPtr->val.i);
            newPtr->type='i';//儲存型態
            break;
        case 'f':
            scanf("%f", &newPtr->val.f);
            newPtr->type='f';//儲存型態
            break;
        case 's':
            scanf("%s", newPtr->val.s);
            newPtr->type='s';//儲存型態
            break;
    }
    if(*ptr == NULL)
        *ptr = newPtr;
    else{
        NodePtr tempPtr = *ptr;
        while(tempPtr->nextPtr != NULL)
            tempPtr = tempPtr->nextPtr;
        tempPtr->nextPtr = newPtr;
    }
}

void printData(NodePtr node){ //印出Data
    while(node){
        switch(node->type){
            case 'i':
                printf("%d\n", node->val.i);
                break;
            case 'f':
                printf("%f\n", node->val.f);
                break;
            case 's':
                printf("%s\n", node->val.s);
                break;
            }
          node = node->nextPtr;//遞移
    }
}

void freeList(NodePtr* ptr){//釋放
    while(*ptr != NULL){
        NodePtr temp = *ptr;
        *ptr = (*ptr)->nextPtr;
        free(temp);
    }
}

int main(){
    NodePtr head = NULL;
    Data *list;
    int len = 0;
    while(1){
        int choose;
        printf("選擇：(1.新增/2.印出/0.結束)：");
        scanf("%d%*c", &choose);
        if(choose < 0 || choose / 3){
            printf("輸入錯誤!\n");
            continue;
        }
        if(choose == 0){
            freeList(&head);//釋放
            printf("結束程式\n");
            break;
        }
        switch(choose){
            case 1: //1.新增
                if(!len) //若陣列長度為0
                    list = malloc(sizeof(Data));
                else //增長動態配置空間
                    list = realloc(list, sizeof(Data) * (len + 1));
                while(!scanData(&list[len]));
                addNode(&head, &list[len]);
                len++;
                break;
            case 2: //2.印出
                printData(head);
                break;
        }
    }
}
