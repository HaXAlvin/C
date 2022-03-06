#include<stdio.h>
#include<stdlib.h>
typedef struct node* NodePtr;

typedef union{
    int i;
    float f;
    char s[16];
}Value;

typedef struct node{
    char type;
    Value value;
    NodePtr nextPtr;
}Node;

void print(NodePtr node){//印出鏈結串列
    while(node){
        switch(node->type){
            case'i':
                printf("%d\n", node->value.i);
                break;
            case'f':
                printf("%f\n", node->value.f);
                break;
            case's':
                printf("%s\n", node->value.s);
                break;
        }
        node = node->nextPtr;
    }
}

int addNode(NodePtr* ptr){
    //建立一個新的鏈結串列 並配置一個node的空間
    NodePtr newPtr = malloc(sizeof(Node));
    newPtr->nextPtr = NULL;

    //輸入資料
    while(1){
        printf("選擇類型：(i：int/f：float/s：char[16])：");
        scanf("%c%*c", &newPtr->type);
        if(newPtr->type != 'i' && newPtr->type != 'f' && newPtr->type != 's'){
            printf("輸入錯誤!\n");
            continue;
        }
        break;
    }
    printf("輸入資料：");
    switch(newPtr->type){
        case 'i':
            scanf("%d", &(newPtr->value.i));
            break;
        case 'f':
            scanf("%f", &(newPtr->value.f));
            break;
        case 's':
            scanf("%s", newPtr->value.s);
            break;
    }
    //輸入完畢

    //串列
    if(*ptr == NULL)
        *ptr = newPtr;
    else{
        NodePtr tempPtr = *ptr;

        while(tempPtr->nextPtr != NULL)
            tempPtr = tempPtr->nextPtr;

        tempPtr->nextPtr = newPtr;
    }
    return 1;
}
void freeList(NodePtr* ptr){ //釋放空間
    while(*ptr != NULL){
        NodePtr temp = *ptr;
        *ptr = (*ptr)->nextPtr;
        free(temp);
    }
}
int main(){
    NodePtr head = NULL;
    int user_input = 0;
    while(1){
        printf("選擇：(1.新增/2.印出/0.結束)：");
        scanf("%d", &user_input);
        fflush(stdin);
        if(user_input!=1 && user_input!=2 && user_input!=0){
            printf("輸入錯誤\n");
            continue;
        }
        switch(user_input){
            case 1:
                addNode(&head);
                break;
            case 2:
                print(head);
                break;
            case 0:
                freeList(&head);
                return 0;
        }
    }

    return 0;
}
