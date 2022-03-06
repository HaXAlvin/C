#include <stdio.h>
#include <stdlib.h>

typedef union{//建立union
    int i;//類型：整數
    float f;//類型：浮點數
    char s[16];//類型：字串
}data;

typedef struct Data{//建立名叫Data的結構
    char type;//使用者選擇的類型
    data value;//使用者要輸入的資料
    struct Data *next;//自我參考指標
}Data;

int main(){
    int cho;//選擇
    int flag=0;//用來提示是否print過
    Data *head=NULL, *current=NULL, *tmp=NULL;//head:串列的頭, current:會跑來跑去, tmp:用來存print過的串列尾
    while(1){
        printf("Choose the function(1.Add/2.Print/0.Terminate):");//提示輸入
        scanf("%d", &cho);//輸入選擇
        getchar();
        if(cho==1){//選擇1
            if(head==NULL){//建立第一個node
                head=malloc(sizeof(Data));//分配空間給current的next
                current=head;//將current指向head
            }
            else if(flag==1){//flag=1代表print過
                tmp->next=malloc(sizeof(Data));//直接從current開始給空間
                current=tmp->next;//將current指向next
            }
            else{//建立第二個以後的node
                current->next=malloc(sizeof(Data));//分配空間給current的next，因為print完後已把current指向next
                current=current->next;//將current指向next
            }
            printf("Choose the type(i: int/f: float/s: char[16]):");//提示輸入
            scanf("%c", &(current->type));//輸入類型
            getchar();
            if(current->type!='i'&&current->type!='f'&&current->type!='s'){//若輸入非i, f, s
                printf("Input error!\n");//顯示錯誤
                continue;
            }
            printf("Input data:");//提示輸入
            if(current->type=='i')//選擇i
                scanf("%d", &current->value.i);//輸入整數
            else if(current->type=='f')//選擇f
                scanf("%f", &current->value.f);//輸入浮點數
            else if(current->type=='s')//選擇s
                scanf("%s", current->value.s);//輸入字串
            current->next=NULL;//讓next先NULL
        }
        else if(cho==2){//選擇2
            tmp=current;//將tmp指向current
            current=head;//將current指向head
            while(current!=NULL){//若current不是NULL
                if(current->type=='i')//若current的type是i
                    printf("%d\n", current->value.i);//印出current裡value結構的i
                else if(current->type=='f')//若目前指標結構裡的type是f
                    printf("%f\n", current->value.f);//印出current裡value結構的f
                else if(current->type=='s')//若目前指標結構裡的type是s
                    printf("%s\n", current->value.s);//印出current裡value結構的s
                current=current->next;//將current指向next
            }
            flag=1;//令flag=1代表print過
        }
        else if(cho!=0&&cho!=1&&cho!=2){//選擇非0或1或2
            printf("Input error!\n");//顯示輸入錯誤
            continue;
        }
        else if(cho==0){//選擇0
            current=head;//將current指向head
            while(current->next!=0){
                free(current);//釋放current
                current=current->next;//將current指向next
            }
            printf("Terminate.\n");//顯示終止
            break;
        }
    }
    return 0;
}
