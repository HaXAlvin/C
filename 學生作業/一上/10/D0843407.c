#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//宣告
int answer[4]={-1,-1,-1,-1};//電腦生成答案
int output,player_input;//生成答案時的輸出,玩家輸入的數值
int input[4];//玩家輸入
int playerchoice;//玩家是否重玩的flag

//隨機產生0-9數字的函式
int random(){
    output=rand()%10;
    return output;
}

//生產出答案的函式
void count_answer(){
    for(int i=0;i<=3;i++){
        answer[i]=random();
        //防止重複
        for(int j=0;j<i;j++){
            if(answer[i]==answer[j]){
                i--;
            }
        }
    }
    for(int i=0;i<4;i++){
            printf("%d",answer[i]);
        }
        puts("");
}

//確認玩家輸入的數值是否正確的函式
void input_check(){
    while(1){
        int flag_allright=2;
        printf(">> ");
        scanf("%d",&player_input);
        //判斷玩家輸入值是否為四位數
        if(player_input>=10000||player_input<=999){
            printf("INPUT ERROR\n");
            continue;
        }
        else
            flag_allright--;
        //將數值拆為四個數字
        input[0]=player_input/1000;
        input[1]=(player_input%1000-player_input%100)/100;
        input[2]=(player_input%100-player_input%10)/10;
        input[3]=player_input%10;
        //判斷數字是否重複
        if(input[0]==input[1]||input[0]==input[2]||input[0]==input[3]||input[1]==input[2]||input[1]==input[3]||input[2]==input[3]){
            printf("INPUT ERROR\n");
            continue;
        }
        else
            flag_allright--;
        if(flag_allright==0){
            break;
        }
    }
}

//遊戲主要幾A幾B的運算函式
void game_operation(){
    while(1){
        input_check();//呼叫檢查玩家輸入的函式
        int A=0,B=0;
        //算出A
        for(int i=0;i<=3;i++){
            if(answer[i]==input[i]){
                A++;
            }
        }
        //答案正確
        if(A==4){
            printf("YOU WIN\n");
            return;
        }
        //算出B
        for(int i=0;i<=3;i++){
            for(int j=0;j<=3;j++){
                if(answer[i]==input[j]){
                B++;
                }
            }
        }
        B=B-A;
        printf("%dA%dB\n",A,B);
    }
}

//判斷玩家是否重玩的函式
int play_again(){
    char play_or_not;
    while(1){
        printf("Play Again?(Y/N)");
        getchar();
        scanf("%c",&play_or_not);
        if(play_or_not=='Y')
            return 1;
        else if(play_or_not=='N')
            return 0;
    }
}

//主函式
int main(){
    srand(time(NULL));//給予SEED
    while(1){
        count_answer();
        game_operation();
        playerchoice=play_again();
        if(playerchoice==0)
            return 0;
    }
}
