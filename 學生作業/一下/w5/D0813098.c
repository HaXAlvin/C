#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct array
{
    union function
    {
        int i;
        float f;
        char c[16];
    };
    int i1;
    char c1;
};//宣告 array的結構函式，其中包含整數變數、字串和一個union(用來儲存資料)
int main()
{
    struct array *arr=malloc(sizeof(struct array));;//宣告結構名
    int count=0;//宣告變數
    while(1){
        printf("選擇(1.新增/2.印出/0.結束):");//印出選擇(1.新增/2.印出/0.結束):
        scanf("%d", &arr[count].i1);
        if(arr[count].i1==0){
            free(arr);
            break;
        }//如果輸入的為0，則停止此迴圈
        else if(arr[count].i1==1){
            while(1){
                printf("選擇類型(i.int/f.float/c.char[16]):");
                getchar();
                scanf("%c", &arr[count].c1);

                if (arr[count].c1=='i'){
                    printf("輸入資料:");
                    scanf("%d", &arr[count].i);
                    break;
                }
                else if(arr[count].c1=='f'){
                    printf("輸入資料:");
                    scanf("%f", &arr[count].f);
                    break;
                }
                else if(arr[count].c1=='c'){
                    printf("輸入資料:");
                    scanf("%s", &arr[count].c);
                    break;
                }
                else {
                    printf("輸入錯誤，請重新輸入\n");
                }
            }
        }//如果輸入的為1，則印出選擇類型(i.int/f.float/c.char[16]):，且讓使用者輸入
        else if(arr[count].i1==2){
            for(int countdown=0;countdown<count;countdown++){
                if(arr[countdown].c1=='i'){
                    printf("%d\n", arr[countdown].i);
                }
                else if(arr[countdown].c1=='f'){
                    printf("%f\n", arr[countdown].f);
                }
                else if(arr[countdown].c1=='c'){
                    printf("%s\n", arr[countdown].c);
                }
            }
        }//如果輸入的為2，則印出所有新增值
        else {
            printf("輸入錯誤，請重新輸入\n");
        }//否則印出輸入錯誤，請重新輸入
        count++;
    }
    return 0;
}
