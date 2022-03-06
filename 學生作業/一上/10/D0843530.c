#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void NUM(int num[4]){  //隨機變數
    int i,j;

    srand(time(NULL));
    for(i = 0; i < 4; i++){
        num[i] = rand()%10;
        for(j = 0;j < i;j++){
            if (num[i] == num[j]){
                i = i-1;
            }
        }
    }
}


void AB(int num[],int ans[]){
    int i,A = 0,B = 0,j,fail = 1;
    char input[5];
    NUM(num);
    /*for(i = 0;i <4; i++){
        printf("%d",num[i]);
    }*/
    while(A != 4){
        fail =  1;
        while(fail == 1){
            fail = 0;
            printf(">> ");
            gets(input);
            if(strlen(input) < 4 || strlen(input) > 4){
                printf("INPUT ERROR\n");
                fail = 1;
                break;
            }

            fail = 0;
            for(i = 0;i < 4;i++){
                ans[i] = (int)(input[i] - 48);
            }
            for(i = 1;i < 4;i++){
                for(j = 1;j <= i;j++){
                    if(ans[i] == ans[i-j]){
                        fail = 1;
                        break;
                    }
                }
                if(fail == 1){
                    printf("INPUT ERROR\n");
                    break;
                }
            }
        }

        while(fail == 0){
            A = 0;
            B = 0;
            for(i = 0;i < 4;i++){
                for(j = 0;j < 4;j++){
                    if(ans[i] == num[j]){
                        if(i == j){
                            A++;
                        }
                        else{
                            B++;
                        }
                    }
                }
            }
            if(A != 4){
                printf("%dA%dB\n",A,B);
            }
            fail = 1;
        }

    }
}

int main(){
    int num[4]; //隨機
    int i,j;
    char again;
    int ans[4];//輸入
    int fail = 0,failed = 0;
    /*srand(time(NULL));
    for(i = 0; i < 4; i++){
        num[i] = rand()%10;
        for(j = 0;j < i;j++){
            if (num[i] == num[j]){
                i = i-1;
            }
        }
    }*/
    do{
        fail = 0;
        AB(num,ans);
        /*for(i = 0;i < 4; i++){
            printf("%d",num[i]);
        }*/
        printf("YOU WIN\n");
        while(failed = 1){
            failed = 0;
            printf("Play Again?(Y/N)");
            scanf("%c",&again);
            getchar();
            if(again == 'Y'){
                fail = 1;
                break;
            }

            else if(again == 'N')
                break;
            else
                failed = 1;
        }

    }while(fail == 1);



}
