#include <stdio.h>
#include <stdlib.h>

typedef struct node* NodePtr;

typedef union {
    int i;
    float f;
    char s[16];
} Value;

typedef struct node{
    char type;
    Value val;
    NodePtr next;
}Node;

void print(NodePtr node) {
    while (node) {
        switch (node->type) {
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
        node = node->next;
    }
}

void addNode(NodePtr* ptr) {
    NodePtr newPtr = malloc(sizeof(Node));
    newPtr->next = NULL;

    char temp;
    while (1) {
        printf("選擇類型：(i：int/f：float/s：char[16])：");
        scanf("%c%*c", &temp);
        if (temp != 'i' && temp != 'f' && temp != 's') {
            printf("輸入錯誤!\n");
            continue;
        }
        break;
    }

    newPtr->type = temp;
    printf("輸入資料：");
    switch (temp) {
    case 'i':
        scanf("%d", &(newPtr->val.i));
        break;
    case 'f':
        scanf("%f", &(newPtr->val.f));
        break;
    case 's':
        scanf("%s", newPtr->val.s);
        break;
    }

    if (*ptr == NULL) {
        *ptr = newPtr;
    }
    else {
        NodePtr tempPtr = *ptr;

        while (tempPtr->next != NULL)
            tempPtr = tempPtr->next;

        tempPtr->next = newPtr;
    }
}

void freeList(NodePtr* ptr) {
    while (*ptr != NULL) {
        NodePtr temp = *ptr;
        *ptr = (*ptr)->next;
        free(temp);
    }
}

int main() {
    NodePtr head = NULL;
    while (1) {
        int choose;
        printf("選擇：(1.新增/2.印出/0.結束)：");
        scanf("%d%*c", &choose);
        if (choose < 0 || choose / 3) {
            printf("輸入錯誤!\n");
            continue;
        }
        if (!choose) {
            freeList(&head);
            printf("結束程式\n");
            break;
        }
        switch (choose) {
            case 1: //1.新增
                addNode(&head);
                break;
            case 2: //2.印出
                print(head);
                break;
        }
    }
}
