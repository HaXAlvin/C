#include<stdio.h>
#include<stdlib.h>

typedef union{
    int i;
    float f;
    char s[16];
}Value;
typedef struct node* NodePtr;
typedef struct node{
    char choice;
    Value val;
    NodePtr nextPtr;
}Node;

void addData(NodePtr* ptr){
    NodePtr newPtr = malloc(sizeof(Node));
    newPtr->nextPtr = NULL;

    printf("選擇類型:(i : int/f : float/s : char[16]):");
    scanf("%c%*c",&(newPtr->choice));
    if (newPtr->choice != 'i' && newPtr->choice != 'f' && newPtr->choice != 's'){
        printf("輸入錯誤!\n");
        return ;
    }
    printf("輸入資料:");
    if ((*newPtr).choice == 'i')
        scanf("%d",&(newPtr->val.i));
    else if ((*newPtr).choice == 'f')
        scanf("%f",&(newPtr->val.f));
    else if ((*newPtr).choice == 's')
        scanf("%s",newPtr->val.s);

    if (*ptr == NULL)
        *ptr = newPtr;
    else {
        NodePtr tempPtr = *ptr;
        while(tempPtr->nextPtr != NULL)
            tempPtr = tempPtr->nextPtr;
        tempPtr->nextPtr = newPtr;
    }
}

void print(Node* node){
    while(node){
        switch(node->choice){
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
        node = node->nextPtr;
    }
}

void freeList(NodePtr* ptr){
    while(*ptr != NULL){
        NodePtr temp = *ptr;
        *ptr = (*ptr)->nextPtr;
        free(temp);
    }
}

int main(){
    int len = 0;
    int opt;
    NodePtr head = NULL;
    do{
        printf("選擇:(1.新增/2.印出/0.結束):");
        scanf("%d%*c",&opt);
        if (opt < 0 || opt >= 3){//選項防呆
            printf("輸入錯誤!\n");
            continue;
        }
        if (opt==0) {
            freeList(&head);
            printf("結束程式\n");
            len = 1;
            break;
        }
        if (opt == 1){
            addData(&head);
        }
        else if (opt == 2){
//            for (int i = 0;i < len;i++){
            print(head);
//            }
        }
    }while(!len);
    return 0;
}
