#include<stdio.h>
#include<stdlib.h>
typedef union{
    int i;
    float f;
    char s[16];
} Value;
/*上為輸入資料的各種形式*/
typedef struct node* NodePtr;
typedef struct node{
    char type;
    Value num;
    NodePtr nextptr;
}Node;
/*上為每個結構內的變數*/
void add(NodePtr* ptr){
    NodePtr newptr = malloc(sizeof(Node));
    newptr->nextptr = NULL;

    printf("選擇類型：(i：int/f：float/s：char[16])：");
    getchar();
    scanf("%c", &newptr->type);

    if((newptr->type) != 'i' && (newptr->type)!= 'f' && (newptr->type)!= 's'){
        printf("輸入錯誤!\n");
        return ;
    }
    printf("輸入資料：");
    if((newptr->type)=='i'){
        scanf("%d", &(newptr->num.i));
    }
    else if((newptr->type)=='f'){
        scanf("%f", &(newptr->num.f));
    }
    else if((newptr->type)=='s'){
        scanf("%s", (newptr->num.s));
    }
    if(*ptr == NULL){
        *ptr = newptr;
    }
    else{
        NodePtr temp = *ptr;
        while(temp->nextptr != NULL)
            temp = temp->nextptr;
        temp->nextptr=newptr;
    }
}
/*上為add的副函式
  在最初時宣告一個名為newptr的結構指標且宣其大小
  印出選擇類型：(i：int/f：float/s：char[16])：，使用者輸入要什麼型態
  若不是i、f、s 則印出輸入錯誤!，結束此副函式
  印出輸入資料：，如果型態為i則用%d，如果型態為f則用%f，如果型態為s則用%s
  若傳入的ptr內是NULL則使ptr內為newptr(開頭)
  否則在令一個指標結構temp，使temp為ptr內的東西(中間鏈結接的東西)
  則temp裡的nextptr就會指向我們新增的指標結構newptr(新增值的結構)
  */
void show(NodePtr ptr){
    while(ptr!=NULL){
        if(ptr->type=='i'){
            printf("%d\n", (ptr->num.i));
        }
        else if(ptr->type=='f'){
            printf("%f\n", (ptr->num.f));
        }
        else if(ptr->type=='s'){
            printf("%s\n", (ptr->num.s));
        }
        ptr=ptr->nextptr;
    }
    printf("\n");
}
/*上為show的副函式
  使用while迴圈一直跑(條件是ptr不為NULL)
  如果ptr的型態為i，則用%d印出值
  如果ptr的型態為f，則用%f印出值
  如果ptr的型態為s，則用%s印出值
  再使ptr為ptr內的nextptr
  因為nextptr指向下一個值存的指標結構
  這樣就能印出下一個指標結構內的值
  直到ptr為NULL*/
void free_act(NodePtr ptr){
    while(ptr != NULL){
        NodePtr temp=ptr;
        ptr=ptr->nextptr;
        free(temp);
    }
}
/*上為free_act的副函式
  使用while迴圈一直跑(條件是ptr不為NULL)
  令一個指標結構temp，使temp為ptr，再使ptr為ptr內的nextptr(因為nextptr指向下一個指標結構)，再去free temp
  (如果沒有先用temp存取ptr，直接free的話，這樣nextptr就無法指向下一個指標結構，而使下一個之後的指標結構無法被free)*/
int main(){
    NodePtr head= NULL;
    int input;
    while(1){
        printf("1.新增, 2.印出, 0.結束: ");
        scanf("%d", &input);
        if(input==1){
            add(&head);
        }
        else if(input==2){
            show(head);
        }
        else if(input==0){
            free_act(head);
            break;
        }
        else {
            printf("輸入有錯誤!\n");
        }
    }
    return 0;
}
/*上為主函式
  宣告head的指標結構和input的變數
  使用while迴圈一直跑
  如果input為1時呼叫add的副函式
  否則如果input為2時呼叫show的副函式
  否則如果input為3時呼叫free_act的副函式，且停止此迴圈
  否則，印出輸入有錯誤!*/
