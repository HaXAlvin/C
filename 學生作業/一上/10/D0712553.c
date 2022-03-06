#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    srand(time(0));
    int read[4]={0}; //使用者輸入存取變數陣列
    int ans[4]={0}; //電腦預設答案
    int write_read; //使用者輸入存取變數
    int i, j;
    int A=0, B=0; //數字正確。A=位置正確。B=位置錯誤。
    int count = 0;
    char play_again;
    do { //生成亂數答案
        for (i=0; i<4; i++){
            ans[i] = (rand() % 10); //%10在0~9之間
            for (j=0; j<i; j++){
                if (ans[i] == ans[j]){
                    i--;  //數字相同，再做一次亂數生成
                }
            }
        }
        for(i=0;i<4;i++){
            printf("%d",ans[i]);
        }
        puts("");
        do {
            do {
                A = 0; //重置
                B = 0;  //重置
                count = 0; //重置
                printf(">> ");
                scanf("%d", &write_read);
                if (write_read<1000 || write_read>9999){ //使用者只能輸入4位數字
                    count++;
                }
                read[0] = write_read / 1000; //儲存第一位數
                read[1] = (write_read/100) % 10; //儲存第二位數
                read[2] = (write_read/10) % 10; //儲存第三位數
                read[3] = write_read % 10; //儲存第四位數
                for (i=0; i<4; i++){
                    for (j=0; j<i; j++){
                        if (read[j]==read[i]){ //輸入數字重複
                            count++;
                        }
                    }
                }
                if (count != 0){
                    printf("INPUT ERROR\n");
                }
            }while (count != 0);
            for (i=0; i<4; i++){ //有數字正確的情況下
                if (ans[i] == read[i]){ //位置正確
                    A++;
                } else {
                    for (j=0; j<4; j++){
                        if (ans[i] == read[j]){ //位置錯誤
                            B++;
                        }
                    }
                }
            }
            if (A != 4){
                printf("%dA%dB\n", A, B);
            }else {
                printf("YOU WIN\n");
            }
        }while (A != 4);
        do { //是否再玩一次
            count = 0;
            printf("Play again?(Y/N)");
            scanf("%*c%c", &play_again);
            if (play_again != 'Y' && play_again != 'y' && play_again != 'N' && play_again != 'n'){
                count ++;
            }
        }while (count != 0);
    }while (play_again == 'y' || play_again=='Y');
    return 0;
}
