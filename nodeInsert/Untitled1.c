#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *nextPtr;
} Node;
//插入val到鏈結串列*headPtrPtr的第index個，成功回傳1，失敗回傳0
int insert(Node **headPtrPtr, int index, int newVal){
    int i;
    Node *newPtr;      //要insert的node
    Node *previousPtr; //要insert的位置的上一個node
    Node *laterPtr;    //要insert的位置的下一個node
    //找到要insert的前一個node
    previousPtr = *headPtrPtr;
    for(i = 0; i < index - 1 && previousPtr->nextPtr!= NULL; i++){
        previousPtr = previousPtr->nextPtr;
    }
    if(i != index - 1 && index != 0){ //未找到index的位置
        return 0;
    }
    //配置要insert的node
    newPtr = malloc(sizeof(Node));
    if(index == 0){ //insert到最前面，原本的index 0會變index 1
        laterPtr = *headPtrPtr; //原本的index 0的指標
        *headPtrPtr = newPtr; //headPtrPtr指向新配置的node
    }
    else{
        laterPtr = previousPtr->nextPtr;
        previousPtr->nextPtr = newPtr;
    }
    newPtr->value = newVal;
    newPtr->nextPtr = laterPtr;
    return 1;
}
int main(){
    Node *headPtr = NULL; //headptr會指向第一個node
    Node *currentPtr = NULL; /*建立串列時current會指向
                               已經建立的最後一個node*/
    int inputTmp; //使用者輸入的暫存
    while(scanf("%d", &inputTmp) && inputTmp != 0){
        //動態配置新的node
        if(headPtr == NULL){ //建立第一個node
            headPtr = malloc(sizeof(Node));
            currentPtr = headPtr;
        }
        else{ //建立第2個以後的node
            currentPtr->nextPtr = malloc(sizeof(Node));
            currentPtr = currentPtr->nextPtr; //遞移!
        }
        //指派值到新的node
        currentPtr->value = inputTmp;
        currentPtr->nextPtr = NULL;
    }
    printf("%d\n\n",insert(&headPtr,5,55));
    currentPtr = headPtr;
	while(currentPtr != NULL){
		printf("%d ", currentPtr->value);
		currentPtr = currentPtr->nextPtr; //遞移!
    }
}
