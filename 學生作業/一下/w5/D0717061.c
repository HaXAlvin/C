/*  109年度  資訊二丁
        第五週作業    */
#include<stdio.h>//標頭檔
#include<stdlib.h>
struct array//定義陣列結構
{
    union arr//定義聯合結構
    {
        int num;//整數
        float Num;//單精度浮點數
        char word[16];//字元陣列
    } Arr;
    char t;//用來儲存資料型態
};
void store(struct array *a)//儲存資料之副程式
{
    char ty;//宣告變數
    while(1)
    {
        printf("選擇類型：(i：int/f：float/s：char[16])：");
        scanf("%c",&ty);//選擇型態
        getchar();
        if(ty=='i')//選擇int
        {
            printf("輸入資料：");
            scanf("%d",&(a->Arr).num);//輸入資料
            a->t=ty;//儲存型態
            break;//跳出迴圈
        }
        if(ty=='f')//選擇float
        {
            printf("輸入資料：");
            scanf("%f",&(a->Arr).Num);//輸入資料
            a->t=ty;//儲存型態
            break;//跳出迴圈
        }

        if(ty=='s')//選擇char
        {
            printf("輸入資料：");
            gets((a->Arr).word);//輸入資料
            a->t=ty;//儲存型態
            break;//跳出迴圈
        }
        if(!(ty=='i'||ty=='s'||ty=='f'))//輸入i、f、s以外
            printf("輸入錯誤！\n");
    }
}
int main()//主程式
{
    int n=0,sum=0;//選告變數
    struct array *mov=malloc(sum*sizeof(struct array));//宣告mov陣列為struct array結構的動態陣列
    while(1)
    {
        printf("選擇：(1.新增/2.印出/0.結束)：");
        scanf("%d",&n);
        if(n==1)//選擇新增
        {
            getchar();
            sum++;//陣列+1
            mov = realloc(mov,sum*sizeof(struct array));
            store(&mov[sum-1]);//call副程式

        }
        if(n==2)//選擇印出
        {
            for(int i=0; i<sum; i++) //迴圈印出
            {
                if(mov[i].t=='i')//如果型態為int
                    printf("%d\n",mov[i].Arr.num);
                else if(mov[i].t=='f')//如果型態為floar
                    printf("%f\n",mov[i].Arr.Num);
                else if(mov[i].t=='s')//如果型態為char
                    puts(mov[i].Arr.word);
            }
        }
        if(n<0||n>2)//輸入0、1、2以外
            printf("輸入錯誤！\n");
        if(n==0)//選擇結束
        {
            printf("結束程式");
            return 0;//回傳，並結束程式
        }

    }

}
