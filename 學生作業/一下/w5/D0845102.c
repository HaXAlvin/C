#include <stdio.h>
#include <stdlib.h>
typedef enum//印出時的選項
{
    I,F,S
} type;
typedef union//設一個包含要求格式的union
{
    int i_;
    char s_[16];
    float f_;
} input;
struct array//設一個記錄檔
{
    input transform;
    type what_type;
};
void call_in(struct array *in_type,int n)//選擇類型的函式
{
    for(char choose=0;;)
    {

        printf("選擇類型:(i:int/f:float/s:char[16]:");

        scanf("%c",&choose);
        getchar();
        if(choose=='i')
        {printf("輸入資料:");
            scanf("%d",&in_type[n].transform.i_);
            in_type[n].what_type=I;
            break;
        }
        else if(choose=='f')
        {printf("輸入資料:");
            scanf("%f",&in_type[n].transform.f_);
            in_type[n].what_type=F;
            break;
        }
        else if(choose=='s')
        {printf("輸入資料:");
            scanf("%s",in_type[n].transform.s_);
            in_type[n].what_type=S;
            break;
        }
        else
        {
            printf("輸入錯誤!\n");
            choose='\0';
        }
    }
}
int main()
{
    struct array *arr = malloc(0);//設一個struct類型的動態陣列
    int count=0;
    for(int option;;)
    {
        printf("選擇:(1.新增)/2.印出/0.結束):");
        scanf("%d",&option);
        getchar();
        if(option==1)
        {
            arr = realloc(arr, (count+1) * sizeof(struct array));
            call_in(arr,count);//呼叫函式
            count++;
            option=-1;//重置選項參數
        }
        else if(option==2)
        {
            for(int j=0; j<count; j++)
            {

                if(arr[j].what_type==I)//先判斷類型,再輸出
                {
                    printf("%d\n",arr[j].transform.i_);

                }
                else if(arr[j].what_type==F)
                {
                    printf("%f\n",arr[j].transform.f_);
                }
                else if(arr[j].what_type==S)
                {
                    printf("%s\n",arr[j].transform.s_);
                }
            }
            option=-1;//重置選項參數

        }
        else if(option==0)
        {
            printf("結束程式\n");
            free(arr);
            return 0;
        }
        else if(option>2)//debug,選項過大會導致bug
        {
             printf("輸入錯誤!\n");
            option=-1;//重置選項參數
        }
        else
        {
            printf("輸入錯誤!\n");
            option=-1;//重置選項參數
        }
    }

}
