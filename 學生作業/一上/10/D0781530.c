#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){
    int ans[4];
    int i,j;
    char chos;
    srand(time(NULL));//產生隨機4碼
    for(i=0; i<4; i++){
        ans[i]=rand()%10;
        for(j=0; j<i; j++){
            if(ans[i]==ans[j])
                i--;
        }
    }
    for(i=0;i<4;i++){
            printf("%d",ans[i]);
        }
        puts("");
    do{
        int i,j,a;
        int A=0,B=0;
        int gus[4]={0};
        int count=0;
        char inp[4]="";
        char chos;
        printf(">> ");
        scanf("%s",&inp);

        if(strlen(inp)!=4){//不是輸入4個數字
            printf("INPUT ERROR\n");
            continue;
        }

        a = atoi(inp);//將字串轉成數字
        gus[0]=a/1000;
        gus[1]=a/100%10;
        gus[2]=a%100/10;
        gus[3]=a%10;

        for(i=0; i<4; i++){//輸入的數字重複
            for(j=0; j<i; j++){
                if(gus[i]==gus[j] &&   i!=j){
                    count++;
                    continue;
                }
            }
        }

        for(i=0; i<4; i++){//計算幾A幾B
            if(ans[i]==gus[i])
                A++;
            for(j=0; j<4; j++){
                if(ans[i]!=gus[i] && ans[i]==gus[j])
                    B++;
            }
        }

        if(A==4){//猜出答案
            printf("YOU WIN\n");
            do{
                printf("Play Again?(Y/N) ");
                scanf("%*c%c",&chos);
                if(chos=='y'||chos=='Y'){//繼續玩
                    srand(time(NULL));//重新產生4碼
                    for(i=0; i<4; i++){
                        ans[i]=rand()%10;
                        for(j=0; j<i; j++){
                            if(ans[i]==ans[j])
                                i--;
                        }
                    }
                    break;
                }
                else if(chos=='N'||chos=='n')//不玩了
                    return 0;
                else//輸入錯誤
                    continue;
            }while(1);
        }
        else if(count==0)
            printf("%dA%dB\n",A,B);
        else//輸入重複數字印出錯誤提示
        	printf("INPUT ERROR\n");
    }while(1);
    return 0;
}
