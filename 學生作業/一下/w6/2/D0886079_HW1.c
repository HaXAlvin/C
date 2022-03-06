#include<stdio.h>
#include<stdlib.h>
typedef struct node* NodePtr;
typedef struct node{
    int value;
    NodePtr nextPtr;
}Node;

void print(NodePtr node){
    while(node){
        printf("%d ", node->value);
        node = node->nextPtr;
    }
    printf("\n");
}

void addNode(NodePtr* ptr){
    NodePtr newPtr = malloc(sizeof(Node));
    newPtr->nextPtr = NULL;

    printf("�п�J�Ʀr: ");
    scanf("%d", &newPtr->value);

    if(*ptr == NULL)
        *ptr = newPtr;
    else{
        NodePtr tempPtr = *ptr;

        while(tempPtr->nextPtr != NULL)
            tempPtr = tempPtr->nextPtr;

        tempPtr->nextPtr = newPtr;
    }

}
void freeList(NodePtr* ptr){
    while(*ptr != NULL){
        NodePtr temp = *ptr;
        *ptr = (*ptr)->nextPtr;
        printf("delete %d\n", temp->value);
        free(temp);
    }
}
int main(){
    NodePtr head = NULL;
    int user_input, end = 0;
    do{
        printf("1.�s�W�`�I, 2.�L�X�쵲��C, 3.����: ");
        scanf("%d", &user_input);
        fflush(stdin);
        switch(user_input){
            case 1:
                addNode(&head);
                break;
            case 2:
                print(head);
                break;
            case 3:
                freeList(&head);
                end = 1;
            default:
                break;
        }

    }while(!end);

    return 0;
}
