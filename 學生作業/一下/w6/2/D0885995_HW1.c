#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定義union
typedef union _total{
    int Int;
    float Float;
    char member[16];
}total;

//定義struct
typedef struct _save{
    total con;
    char n;
    struct _save *nextPtr; //鏈結串鍊
}save;

//存的函式
void saver(save *a)
{
    while(1){
        printf("選擇類型:(i:int/f:float/s:char[16]):");
        scanf("%*c%c",&(a->n)); //存式哪個形式
        //如果式int
        if (a->n == 'i'){
            printf("輸入資料:");
            scanf("%d",&a->con.Int);
            break;
        }
        //如果是float
        else if (a->n == 'f'){
            printf("輸入資料:");
            scanf("%f",&a->con.Float);
            break;
        }
        //如果是string
        else if (a->n == 's'){
            printf("輸入資料:");
            scanf("%s",a->con.member);
            break;
        }
        else
            printf("輸入錯誤!\n");
    }
    a->nextPtr = NULL;
}

int main()
{
    int n,i=0;//n是存要做哪一個動作，i是陣列第幾個，count是有幾個陣列
    save *headPtr;
    headPtr = NULL;
    while(1){
        printf("選擇:(1.新增/2.印出/0.結束):");
        scanf("%d",&n); //存要做哪一個動作
        //判斷存取或印出
        switch(n){
            //存
            case 1:{
                save *currentPtr = malloc(sizeof(save));
                saver(currentPtr);
                i++;
                if (headPtr == NULL){
                    headPtr = currentPtr;
                }
                else{
                    save *temp = headPtr; //暫存指標結構
                    //指向下一個
                    while(temp->nextPtr!=NULL){
                        temp = temp->nextPtr;
                    }
                    temp->nextPtr = currentPtr;
                }
                break;
            }
            //印
            case 2:{//印出的迴圈
                save *ptr = headPtr;
                for (int j=0;j<i;j++){
                    //判斷是哪一個型態
                    if (ptr->n == 'i'){
                        printf("%d\n",ptr->con.Int);
                    }
                    else if (ptr->n == 'f'){
                        printf("%f\n",ptr->con.Float);
                    }
                    else if (ptr->n == 's'){
                        printf("%s\n",ptr->con.member);
                    }
                    ptr = ptr->nextPtr;
                }
                break;
            }
        }
        //結束並釋放
        if (n==0){
            while (headPtr != NULL){
                save *x = headPtr->nextPtr;
                free(headPtr);
                headPtr = x;
            }
            printf("結束程式");
            break;
        }
        //防呆
        else if (n!=0 && n!=1 && n!=2)
            printf("輸入錯誤!\n");
    }
}
