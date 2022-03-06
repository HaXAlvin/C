#include <stdio.h>
#include <stdlib.h>

typedef union{
    int i;
    float f;
    char s[16];
}Value;

typedef struct node* NodePtr;

typedef struct node{
    char type;
    Value val;
    NodePtr nextPtr;
}Node;

int scanData(NodePtr* ptr){ //scan Data
    NodePtr newData = malloc(sizeof(Node));
    newData->nextPtr = NULL;
    while(1){//system to avoid error type input
        printf("Type:(i:int/f:float/s:char[16]):");
        scanf("%c%*c", &(newData->type));
        if(newData->type != 'i' && newData->type != 'f' && newData->type != 's'){
            printf("Input Error!\n");
        }
        else//if input type error
            break;
    }
    printf("Input Data:");
    switch(newData->type){
        case 'i':
            scanf("%d", &(newData->val.i));
            break;
        case 'f':
            scanf("%f", &(newData->val.f));
            break;
        case 's':
            scanf("%s", newData->val.s);
            break;
    }
    if(*ptr == NULL)//create head
        *ptr = newData;
    else{
        NodePtr tempPtr = *ptr;//if got head then create another node next to head

        while(tempPtr->nextPtr != NULL)
            tempPtr = tempPtr->nextPtr;

        tempPtr->nextPtr = newData;
    }
    return 1;
}

void printData(NodePtr data){ //print Data
    while(data!=NULL){//keep looping till the next data node is NULL
        switch(data->type){
            case 'i':
                printf("%d\n", data->val.i);
                break;
            case 'f':
                printf("%f\n", data->val.f);
                break;
            case 's':
                printf("%s\n", data->val.s);
                break;
        }
        data = data->nextPtr;//change node
    }
}

int main(){
    NodePtr list = NULL;//create 1st node
    while(1){
        int choose;
        printf("Choose:(1.Add/2.Print/0.End):");
        scanf("%d%*c", &choose);
        if(choose < 0 || choose / 3){//input error system
            printf("Input Error!\n");
            continue;
        }
        if(!choose){
            free(list);//free all data
            printf("End Of Program\n");
            break;
        }
        switch(choose){
            case 1: //1.add data
                scanData(&list);
                break;
            case 2: //2.print data
                printData(list);
                break;
        }
    }
}
