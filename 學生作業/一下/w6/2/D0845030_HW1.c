#include <stdio.h>
#include <stdlib.h>

typedef struct node *NodePtr;//�ۧڰѦҵ��c

typedef union{
    int i;
    float f;
    char s[16];
}Value;

typedef struct node{
    char type;
    Value val;
    NodePtr nextPtr;
}Data;

int scanData(Data *newData){ //�������
    printf("��������G(i�Gint/f�Gfloat/s�Gchar[16])�G");
    scanf("%c%*c", &(newData->type));
    if(newData->type != 'i' && newData->type != 'f' && newData->type != 's'){
        printf("��J���~!\n");
        return 0;
    }
    printf("��J��ơG");
    return 1;
}

void addNode(NodePtr *ptr, Data *data){//��J���
    NodePtr newPtr = malloc(sizeof(Data));//�쵲��C
    newPtr->nextPtr = NULL;
    switch(data->type){
        case 'i':
            scanf("%d", &newPtr->val.i);
            newPtr->type='i';//�x�s���A
            break;
        case 'f':
            scanf("%f", &newPtr->val.f);
            newPtr->type='f';//�x�s���A
            break;
        case 's':
            scanf("%s", newPtr->val.s);
            newPtr->type='s';//�x�s���A
            break;
    }
    if(*ptr == NULL)
        *ptr = newPtr;
    else{
        NodePtr tempPtr = *ptr;
        while(tempPtr->nextPtr != NULL)
            tempPtr = tempPtr->nextPtr;
        tempPtr->nextPtr = newPtr;
    }
}

void printData(NodePtr node){ //�L�XData
    while(node){
        switch(node->type){
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
          node = node->nextPtr;//����
    }
}

void freeList(NodePtr* ptr){//����
    while(*ptr != NULL){
        NodePtr temp = *ptr;
        *ptr = (*ptr)->nextPtr;
        free(temp);
    }
}

int main(){
    NodePtr head = NULL;
    Data *list;
    int len = 0;
    while(1){
        int choose;
        printf("��ܡG(1.�s�W/2.�L�X/0.����)�G");
        scanf("%d%*c", &choose);
        if(choose < 0 || choose / 3){
            printf("��J���~!\n");
            continue;
        }
        if(choose == 0){
            freeList(&head);//����
            printf("�����{��\n");
            break;
        }
        switch(choose){
            case 1: //1.�s�W
                if(!len) //�Y�}�C���׬�0
                    list = malloc(sizeof(Data));
                else //�W���ʺA�t�m�Ŷ�
                    list = realloc(list, sizeof(Data) * (len + 1));
                while(!scanData(&list[len]));
                addNode(&head, &list[len]);
                len++;
                break;
            case 2: //2.�L�X
                printData(head);
                break;
        }
    }
}
