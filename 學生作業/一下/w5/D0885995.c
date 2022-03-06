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
}

int main()
{
    int n,i=0,count=1;//n是存要做哪一個動作，i是陣列第幾個，count是有幾個陣列
    save *input = malloc(1*sizeof(save));
    while(1){
        printf("選擇:(1.新增/2.印出/0.結束):");
        scanf("%d",&n); //存要做哪一個動作
        //判斷存取或印出
        switch(n){
            //存
            case 1:
                //更改陣列大小
                input = realloc(input,count*sizeof(save));
                saver(&input[i]);
                i++;
                count++;
                break;
            //印
            case 2:
                //印出的迴圈
                for (int j=0;j<i;j++){
                    //判斷是哪一個型態
                    if (input[j].n == 'i'){
                        printf("%d\n",input[j].con.Int);
                    }
                    else if (input[j].n == 'f'){
                        printf("%f\n",input[j].con.Float);
                    }
                    else if (input[j].n == 's'){
                        printf("%s\n",input[j].con.member);
                    }
                }
                break;
        }
        //結束並釋放
        if (n==0){
            free(input);
            printf("結束程式");
            break;
        }
        //防呆
        else if (n!=0 && n!=1 && n!=2)
            printf("輸入錯誤!\n");
    }
}
