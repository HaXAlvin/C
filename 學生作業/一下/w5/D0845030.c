#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Origin{
    char ityp;
    union tagB{//用來儲存資料
        int i;
        float f;
        char s[16];
    }Save;
};
void setO(struct Origin *input){
    int type;//輸入類型
    do{
        printf("選擇類型 : (1 : int/2 : float/3 : char[16]) : ");
        scanf("%d", &type);
        if(type < 1 || type > 3)
            printf("輸入錯誤!\n");
    }while(type < 1 || type > 3);
    printf("輸入資料 : ");
    if(type == 1){//int
        scanf("%d", &(input -> Save).i);
        (*input).ityp = 'I';//讓主程式判斷輸入型態
    }
    else if(type == 2){//float
        scanf("%f", &(input -> Save).f);
        (*input).ityp = 'F';//讓主程式判斷輸入型態
    }
    else if(type == 3){//char[16]
        scanf("%s", (input -> Save).s);
        (*input).ityp = 'S';//讓主程式判斷輸入型態
    }
}
int main(){
    int choice;//選擇
    int i;
    struct Origin sArray[100];
    struct Origin *sa = malloc(sizeof(struct Origin));//使用動態陣列配置將動態陣列增加1個struct大小的記憶體空間
    int count = 0;
    while(1){
        printf("選擇 : (1.新增/2.印出/0.結束) : ");
        scanf("%d", &choice);
        if(choice < 0 || choice > 2)
            printf("輸入錯誤!\n");
        if(choice == 1){
            setO(sa);//call by reference
            sArray[count] = *sa;
            sa = realloc(sa, sizeof(struct Origin));//增加記憶體空間
            count++;
        }
        else if(choice == 2){
           for(i = 0; i < count; i++){//印出以輸入的資料
                if(sArray[i].ityp == 'I'){//判斷輸入型態
                    printf("%d\n", sArray[i].Save.i);
                }
                else if(sArray[i].ityp == 'F'){//判斷輸入型態
                    printf("%.6f\n", sArray[i].Save.f);
                }
                else if(sArray[i].ityp == 'S'){//判斷輸入型態
                    printf("%s\n", sArray[i].Save.s);
                }
           }
        }
        else if(choice == 0){
            printf("結束程式");
            free(sa);//釋放動態配置記憶體
            break;
        }
    }
    return 0;
}
