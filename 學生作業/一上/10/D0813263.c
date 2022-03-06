#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int n = 1;//flag
    int a = 0;
    int b = 0;
    int value,Gnum,i,j;
    char choice;
    int Ans[4] = {0};
    int Guess[4] = {0};
    srand(time(NULL));
    //run random number
    while (n == 1){
        do{
            n = 0;
            value = rand() % 10000;
            Ans[3] = (value % 10);//千位數
            Ans[2] = (value % 100) / 10;//百位數
            Ans[1] = (value % 1000) / 100;//十位數
            Ans[0] = value / 1000;//個位數
            if (Ans[0] == Ans[1] || Ans[0] == Ans[2] || Ans[0] == Ans[3] || Ans[1] == Ans[2] || Ans[1] == Ans[3] || Ans[2] == Ans[3]){
                n = 1;
            }
        }while(n == 1);
        for(int i=0;i<4;i++){
            printf("%d",Ans[i]);
        }
        puts("");
        //1A2B實作
        do{
            n = 1;
            a = 0;
            b = 0;
            printf(">> ");
            scanf("%d",&Gnum);
            Guess[3] = (Gnum % 10);//千位數
            Guess[2] = (Gnum % 100) / 10;//百位數
            Guess[1] = (Gnum % 1000) / 100;//十位數
            Guess[0] = Gnum / 1000;//個位數
            //重複數字
            if (Guess[0] == Guess[1] || Guess[0] == Guess[2] || Guess[0] == Guess[3] || Guess[1] == Guess[2] || Guess[1] == Guess[3] || Guess[2] == Guess[3]){
                printf("INPUT ERROR\n");
                n = 1;
            }
            //位數不符合要求
            else if (Gnum >= 10000 || Gnum < 1000){
                printf("INPUT ERROR\n");
                n = 1;
            }
            else{
                for (i = 0;i <= 3;i++){
                    for (j = 0;j <= 3;j++){
                        if (Guess[i] == Ans[j]){
                            if (i == j){
                                a++;
                            }
                            else {
                                b++;
                            }
                        }
                    }
                }
                if (a != 4)
                    printf("%dA%dB\n",a,b);
            }
            if (a == 4){
                printf("YOU WIN\n");
                n = 0;
                break;
            }

        }while (n == 1);
        //是否繼續
        do{
            n = 1;
            printf("Play Again?(Y/N)");
            scanf(" %c",&choice);
            if (choice == 'Y'){
                n = 1;
                break;
            }
            else if (choice == 'N'){
                n = 0;

            }
            else {
                n = 1;
            }
        }while (n == 1);
    }
}
