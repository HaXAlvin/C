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
        printf("��������G(i�Gint/f�Gfloat/s�Gchar[16])�G");
        scanf("%c%*c", &temp);
        if (temp != 'i' && temp != 'f' && temp != 's') {
            printf("��J���~!\n");
            continue;
        }
        break;
    }

    newPtr->type = temp;
    printf("��J��ơG");
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
        printf("��ܡG(1.�s�W/2.�L�X/0.����)�G");
        scanf("%d%*c", &choose);
        if (choose < 0 || choose / 3) {
            printf("��J���~!\n");
            continue;
        }
        if (!choose) {
            freeList(&head);
            printf("�����{��\n");
            break;
        }
        switch (choose) {
            case 1: //1.�s�W
                addNode(&head);
                break;
            case 2: //2.�L�X
                print(head);
                break;
        }
    }
}
