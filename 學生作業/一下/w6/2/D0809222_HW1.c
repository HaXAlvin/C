#include<stdio.h>
#include<stdlib.h>

typedef union {
    int intValue;
    float floatValue;
    char stringValue[16];
} Value;

typedef struct node *NodePtr;
typedef struct node {
    char type;
    Value value;
    struct node *nextNode;
} Node;

void addNode(NodePtr *ptr);
void print(NodePtr node);
void freeList(NodePtr *ptr);

int main() {
    NodePtr headPtr = NULL;
    int user_input, end = 0;

    while (1) {
        int actionCode;
        printf("選擇：(1.新增/2.印出/0.結束)：");
        scanf("%d%*c", &actionCode);

        // Guard statement
        if(actionCode < 0 || actionCode / 3) {
            printf("輸入錯誤!\n");
            continue;
        }
        if (!actionCode) {
            freeList(&headPtr);
            printf("結束程式\n");
            break;
        }

        switch(actionCode) {
            case 1:
                addNode(&headPtr);
                break;
            case 2:
                print(headPtr);
                break;
            case 0:
                freeList(&headPtr);
            default:
                break;
        }
    }
    return 0;
}

void addNode(NodePtr *ptr){
    NodePtr newPtr = malloc(sizeof(Node));
    newPtr->nextNode = NULL;
    
    printf("選擇類型：(i：int/f：float/s：char[16])：");
    scanf("%c%*c", &(*newPtr).type);

    // Guard statement
    if ((*newPtr).type != 'i' && (*newPtr).type != 'f' && (*newPtr).type != 's'){
        printf("輸入錯誤!\n");
        return;
    }

    printf("輸入資料：");
    switch((*newPtr).type) {
        case 'i':
            scanf("%d", &(*newPtr).value.intValue);
            break;
        case 'f':
            scanf("%f", &(*newPtr).value.floatValue);
            break;
        case 's':
            scanf("%s", (*newPtr).value.stringValue);
            break;
    }
    
    if (*ptr == NULL) {
        *ptr = newPtr;
    } else {
        NodePtr tempPtr = *ptr;
        while (tempPtr->nextNode != NULL) {
            tempPtr = tempPtr->nextNode;
        }
        tempPtr->nextNode = newPtr;
    }
}

void print(NodePtr node) {
    while (node) {
        switch(node->type) {
        case 'i':
            printf("%d\n", node->value.intValue);
            break;
        case 'f':
            printf("%f\n", node->value.floatValue);
            break;
        case 's':
            printf("%s\n", node->value.stringValue);
            break;
        }
        node = node->nextNode;
    }
}

void freeList(NodePtr *ptr) {
    while (*ptr != NULL){
        NodePtr temp = *ptr;
        *ptr = (*ptr)->nextNode;
        free(temp);
    }
}