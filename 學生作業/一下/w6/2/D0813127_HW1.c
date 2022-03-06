#include<stdio.h>
#include<stdlib.h>

typedef union
{
    int i;
    float f;
    char s[16];
}Data;

typedef struct node *NodePtr;

typedef struct node
{
    char type;
    Data value;
    NodePtr nextPtr;
}Node;

void addNode(NodePtr *ptr)  // 新增結構
{
    NodePtr newPtr = malloc(sizeof(Node));
    newPtr->nextPtr = NULL;
    while (1) {
        printf("選擇類型：(i：int/f：float/s：char[16])：");
        scanf("%c", &newPtr->type);  // 記錄型態
        getchar();
        if (newPtr->type == 'i' || newPtr->type == 'f' || newPtr->type == 's') {
            break;
        }
        printf("輸入錯誤!\n");  // 防呆
    }
    printf("輸入資料：");  // 將資料根據類型存入結構
    if (newPtr->type == 'i') {
        scanf("%d", &newPtr->value.i);
    }
    else if (newPtr->type == 'f') {
        scanf("%f", &newPtr->value.f);
    }
    else if (newPtr->type == 's') {
        gets(newPtr->value.s);
    }
    if (*ptr == NULL) {
        *ptr = newPtr;  // 如果一開始沒東西把剛新增的結構當頭
    }
    else {  // 將剛新增的連接到最尾端
        NodePtr tempPtr = *ptr;
        while (tempPtr->nextPtr != NULL) {
            tempPtr = tempPtr->nextPtr;
        }
        tempPtr->nextPtr = newPtr;
    }
}

void freeList(NodePtr *ptr)  // 釋放記憶體
{
    while (*ptr != NULL) {
        NodePtr temp = *ptr;
        *ptr = (*ptr)->nextPtr;
        if (temp->type == 'i') {
            printf("Delete %d\n", temp->value.i);
        }
        else if (temp->type == 'f') {
            printf("Delete %f\n", temp->value.f);
        }
        else if (temp->type == 's') {
            printf("Delete %s\n", temp->value.s);
        }
        free(temp);
    }
}

void print(NodePtr node)  // 將串聯起來的結構印出
{
    while (node != NULL) {
        if (node->type == 'i') {
            printf("%d\n", node->value.i);
        }
        else if (node->type == 'f') {
            printf("%f\n", node->value.f);
        }
        else if (node->type == 's') {
            printf("%s\n", node->value.s);
        }
        node = node->nextPtr;
    }
}

int main()
{
    NodePtr head = NULL;
    int input1;
    while (1) {
        printf("選擇：(1.新增/2.印出/0.結束)：");
        scanf("%d", &input1);
        getchar();
        if (input1 == 1) {
            addNode(&head);
        }
        else if (input1 == 2) {
            print(head);
        }
        else if (input1 == 0) {
            freeList(&head);
            printf("結束程式\n");
            break;
        }
        else {  // 防呆
            printf("輸入錯誤!\n");
        }
    }
    return 0;
}
