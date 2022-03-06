#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *nextPtr;
} Node;
//���Jval���쵲��C*headPtrPtr����index�ӡA���\�^��1�A���Ѧ^��0
int insert(Node **headPtrPtr, int index, int newVal){
    int i;
    Node *newPtr;      //�ninsert��node
    Node *previousPtr; //�ninsert����m���W�@��node
    Node *laterPtr;    //�ninsert����m���U�@��node
    //���ninsert���e�@��node
    previousPtr = *headPtrPtr;
    for(i = 0; i < index - 1 && previousPtr->nextPtr!= NULL; i++){
        previousPtr = previousPtr->nextPtr;
    }
    if(i != index - 1 && index != 0){ //�����index����m
        return 0;
    }
    //�t�m�ninsert��node
    newPtr = malloc(sizeof(Node));
    if(index == 0){ //insert��̫e���A�쥻��index 0�|��index 1
        laterPtr = *headPtrPtr; //�쥻��index 0������
        *headPtrPtr = newPtr; //headPtrPtr���V�s�t�m��node
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
    Node *headPtr = NULL; //headptr�|���V�Ĥ@��node
    Node *currentPtr = NULL; /*�إߦ�C��current�|���V
                               �w�g�إߪ��̫�@��node*/
    int inputTmp; //�ϥΪ̿�J���Ȧs
    while(scanf("%d", &inputTmp) && inputTmp != 0){
        //�ʺA�t�m�s��node
        if(headPtr == NULL){ //�إ߲Ĥ@��node
            headPtr = malloc(sizeof(Node));
            currentPtr = headPtr;
        }
        else{ //�إ߲�2�ӥH�᪺node
            currentPtr->nextPtr = malloc(sizeof(Node));
            currentPtr = currentPtr->nextPtr; //����!
        }
        //�����Ȩ�s��node
        currentPtr->value = inputTmp;
        currentPtr->nextPtr = NULL;
    }
    printf("%d\n\n",insert(&headPtr,5,55));
    currentPtr = headPtr;
	while(currentPtr != NULL){
		printf("%d ", currentPtr->value);
		currentPtr = currentPtr->nextPtr; //����!
    }
}
