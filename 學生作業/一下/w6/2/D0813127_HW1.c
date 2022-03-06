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

void addNode(NodePtr *ptr)  // �s�W���c
{
    NodePtr newPtr = malloc(sizeof(Node));
    newPtr->nextPtr = NULL;
    while (1) {
        printf("��������G(i�Gint/f�Gfloat/s�Gchar[16])�G");
        scanf("%c", &newPtr->type);  // �O�����A
        getchar();
        if (newPtr->type == 'i' || newPtr->type == 'f' || newPtr->type == 's') {
            break;
        }
        printf("��J���~!\n");  // ���b
    }
    printf("��J��ơG");  // �N��Ʈھ������s�J���c
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
        *ptr = newPtr;  // �p�G�@�}�l�S�F����s�W�����c���Y
    }
    else {  // �N��s�W���s����̧���
        NodePtr tempPtr = *ptr;
        while (tempPtr->nextPtr != NULL) {
            tempPtr = tempPtr->nextPtr;
        }
        tempPtr->nextPtr = newPtr;
    }
}

void freeList(NodePtr *ptr)  // ����O����
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

void print(NodePtr node)  // �N���p�_�Ӫ����c�L�X
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
        printf("��ܡG(1.�s�W/2.�L�X/0.����)�G");
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
            printf("�����{��\n");
            break;
        }
        else {  // ���b
            printf("��J���~!\n");
        }
    }
    return 0;
}
