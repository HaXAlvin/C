#include<stdio.h>
#include<stdlib.h>
union data
{
    int Int;
    float Float;
    char Char[16];
};//設置1個union來儲存資料
struct array
{
    union data data2;
    char Char2;
};//存進struct裡在包含一個char當作紀錄方法
int main()
{
    int choose,count=0,n=1;
    struct array *array2;
    array2 = malloc (0*sizeof(struct array));//設置一個為0的動態陣列
    while(1)
    {
        printf("(1.新增/2.印出/0.結束):");
        scanf("%d",&choose);
        if(choose!=1&&choose!=2&&choose!=0)
        {
            printf("輸入錯誤!\n");
            continue;
        }//防呆
        else if(choose == 1)
        {
            while(1)
            {
                array2 = realloc(array2,n*sizeof(struct array));//每次新增多給他一個n個大小的記憶體空間,n每一次新增多+1
                printf("選擇類型:(i : int/f : float/s:char[16]):");
                getchar();
                scanf("%c",&array2[count].Char2);
                if(array2[count].Char2 == 'i')
                {
                    printf("輸入資料:");
                    scanf("%d",&array2[count].data2.Int);
                    break;
                }//輸入i存在union的int裡
                else if(array2[count].Char2 == 'f')
                {
                    printf("輸入資料:");
                    scanf("%f",&array2[count].data2.Float);
                    break;
                }//輸入f存在union的flaot裡
                else if(array2[count].Char2 == 's')
                {
                    printf("輸入資料:");
                    scanf("%s",&array2[count].data2.Char);
                    break;
                }//輸入s存在union的char裡
                else
                {
                    printf("輸入錯誤!\n");
                    continue;
                }//防呆
            }
        }
        if(choose == 2)
        {
            for(int j=0;j<count;j++)
            {
                if(array2[j].Char2=='i')
                {
                    printf("%d\n",array2[j].data2.Int);
                }//如果陣列為i則輸出union裡的int
                else if(array2[j].Char2=='f')
                {
                    printf("%f\n",array2[j].data2.Float);
                }//如果陣列為f則輸出union裡的float
                else if(array2[j].Char2=='s')
                {
                    printf("%s\n",array2[j].data2.Char);
                }//如果陣列為s則輸出union裡的char
            }
        }
        if(choose == 0)
        {
            free(array2);
            return 0;
        }//釋放動態配置記憶體
        n++;
        count++;
    }
}
