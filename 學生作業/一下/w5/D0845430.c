#include <stdio.h>
#include <stdlib.h>
typedef struct Data{//建立名叫data的結構
    union D{//成員1：union
        int i;//類型：整數
        float f;//類型：浮點數
        char s[16];//類型：字串
    }d;
    char type;//成員2：儲存使用者選擇的類型的變數
}data;

int main(){
    int cho;//選擇
    int t=0, count=0;
    int i;
    data *a=malloc(sizeof(data));//給空間（一個)
    printf("Choose the function(1.Add/2.Print/0.Terminate):");//提示輸入
    scanf("%d", &cho);//輸入選擇
    while(1){
        getchar();
        if(cho==1){//選擇1
            a=realloc(a, (t++)*sizeof(data));//重置空間(多給一個)
            printf("Choose the type(i: int/f: float/s: char[16]):");//提示輸入
            scanf("%c", &a[t].type);//輸入類型
            printf("Input data:");//提示輸入
            if(a[t].type=='i')//選擇i
                scanf("%d", &a[t].d.i);//輸入整數類型資料
            else if(a[t].type=='f')//選擇f
                scanf("%f", &a[t].d.f);//輸入整數類型資料
            else if(a[t].type=='s')//選擇s
                gets(a[t].d.s);//輸入整數類型資料
            count++;
        }
        else if(cho==2){//選擇2
            for(i=0;i<count;i++){
                puts(a[i]);//印出資料
                printf("\n");//換行
            }
        }
        else if(cho!=1&&cho!=2&&cho!=0)//選擇非0或1或2
            printf("Input error!\n");//顯示輸入錯誤
        else if(cho==0){//選擇0
            for(i=0;i<count;i++)
                free(a[i]);//釋放第二維
            free(a);//釋放第一維
            return 0;
        }
    }
}
