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

void print(NodePtr node){//�L�X�쵲��C
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
    //�إߤ@�ӷs���쵲��C �ðt�m�@��node���Ŷ�
    NodePtr newPtr = malloc(sizeof(Node));
    newPtr->nextPtr = NULL;

    //��J���
    while(1){
        printf("��������G(i�Gint/f�Gfloat/s�Gchar[16])�G");
        scanf("%c%*c", &newPtr->type);
        if(newPtr->type != 'i' && newPtr->type != 'f' && newPtr->type != 's'){
            printf("��J���~!\n");
            continue;
        }
        break;
    }
    printf("��J��ơG");
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
    //��J����

    //��C
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
void freeList(NodePtr* ptr){ //����Ŷ�
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
        printf("��ܡG(1.�s�W/2.�L�X/0.����)�G");
        scanf("%d", &user_input);
        fflush(stdin);
        if(user_input!=1 && user_input!=2 && user_input!=0){
            printf("��J���~\n");
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
