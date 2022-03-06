#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    int flag,flag2,ans[10]={0};//由左至右依序為:判斷值1,判斷值2,電腦生成四個數的陣列
    char input[10],in[10];//由左至右依序為:使用者輸入四個數字之陣列,Play Again?(Y/N)之輸入

    do{
        srand(time(NULL));
        for(int n1=0;n1<4;n1++){//生成四個隨機整數
            do{
                ans[n1]=rand()%10;
                flag=0;
                for(int n2=0;n2<n1;n2++){//判斷生成的整數是否有跟前面生成的重複
                    if(ans[n1]==ans[n2])
                        flag++;
                }
            }while(flag>0);//重複則重新生成
            //printf("%d ",ans[n1]);//檢查用>印出生成的四個數
        }
        //puts(" ");//檢查用>印出生成的四個數之換行
        for(int i=0;i<4;i++){
            printf("%d",ans[i]);
        }
        puts("");
        do{
            do{
                flag=0;
                printf(">> ");
                scanf("%s",input);//使用者輸入四個數字

                if(strlen(input)!=4)//檢查是否為四個數
                    flag++;
                else{//否則檢查有無重複數字
                    for(int n1=0;n1<4;n1++){
                        flag2=0;
                        for(int n2=0;n2<4;n2++){
                            if(input[n1]==input[n2])
                                flag2++;
                        }
                        if(flag2>1){//如果有重複則跳出迴圈
                            flag++;
                            break;
                        }
                    }
                }
                if(flag>0)//如果輸入不為四個數或有重複則flag>0
                    puts("INPUT ERROR");
            }while(flag>0);//輸入錯誤，重複輸入

            flag=0;
            flag2=0;

            for(int n1=0;n1<4;n1++){//判斷nAmB
                for(int n2=0;n2<4;n2++){
                    if(input[n1]-48==ans[n2])//判斷輸入與答案有相同數字的數量=n+m=flag
                        flag++;
                }
                if(input[n1]-48==ans[n1])//判斷輸入與答案有相同數字且為正確位置的數量=n=flag2
                    flag2++;
            }

            if(flag2!=4)//如果答案沒有完全正確
                printf("%dA%dB\n",flag2,flag-flag2);//flag2=n,flag=n+m
        }while(flag2!=4);//如果答案沒有完全正確，則讓玩家再次輸入

        printf("YOU WIN\nPlay Again?(Y/N)");//詢問是否在玩一次
        while(scanf("%s",in)&&(strcmp(in,"Y")!=0&&strcmp(in,"N")!=0)){//如果玩家輸入不是Y or N，則重複輸入
            printf("Play Again?(Y/N)");
        }

    }while(strcmp(in,"Y")==0);//輸入為Y則在玩一次，否則跳出迴圈，結束遊戲
}

