#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num,A,B;
    char Y;
    do{
        srand(time(NULL));
        int a[4]={0};
        int b[4]={0};
        for(int i=0;i<4;i++){   //取得題目
            a[i]=rand()%10;
            for(int j=0;j<i;j++){
                if(a[j]==a[i]){ //檢查題目數字是否重複
                    i--;
                }
            }
        }
        for(int i=0;i<4;i++){
            printf("%d",a[i]);
        }
        puts("");
        while(A!=4){
            printf(">>");
            scanf("%d",&num);   //輸入自己的答案
            b[0]=num/1000;      //分別取數
            b[1]=(num/100)%10;
            b[2]=(num/10)%10;
            b[3]=num%10;
            A=0;
            B=0;
            if(num/1000==0||num/10000!=0){    //答案不得小於4位數或大於4位數
                printf("INPUT ERROR\n");

            }
            for(int i=0;i<4;i++){  //答案中不得有重複數字
                for(int j=0;j<i;j++){
                    if(i!=j&&b[i]==b[j])
                        printf("INPUT ERROR\n");
                }
            }

            for(int i=0;i<4;i++){  //判斷答案與題目的AB
                for(int j=0;j<4;j++){
                    if(b[i]==a[j]){
                        if(i==j)
                            A++;
                        else
                            B++;
                    }
                }
            }

            printf("%dA%dB\n",A,B);
            if(A==4){
                printf("YOU WIN\n");
                printf("Play Again?(Y/N)");
                scanf("%d",&Y);
            }
        }
    }while(Y=='Y');  //如果輸入Y再玩一次


}



