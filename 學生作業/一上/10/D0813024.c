#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    while(1){
        srand(time(NULL));
        int a[4] = {0};//答案和輸入分作兩個陣列
        int b[4] = {0};
        int input,digit;//輸出和輸出的位數
        int count = 0 ;
        int A = 0;
        int B = 0;
        char end;
        for(int i = 0;i < 4;i++){ //四位不相同數字
            a[i] = rand() % 10;
            for(int j = 0;j < i;j++){
                if(a[j] == a[i])
                    i--;
            }
        }
            for(int i=0;i<4;i++){
            printf("%d",a[i]);
        }
        puts("");
        do{
            A = 0;
            B = 0;
            count = 0;
            printf(">> ");
            scanf("%d",&input);
            digit = input;
            while(digit != 0){ //計算位數
                digit /= 10;
                count++;
            }
            b[0] = input / 1000;
            b[1] = (input / 100) % 10;
            b[2] = (input / 10) % 10;
            b[3] = input % 10;
            if((count != 4  && b[0] != 0) || b[0] == b[1] || b[0] == b[2] || b[0] == b[3] //判斷是否輸入錯誤
               || b[1] == b[2] || b[1] == b[3] || b[2] == b[3]){
                printf("INPUT ERROR\n");
            }
            else{
                for(int i = 0; i < 4;i++){
                    if(a[i] == b[i])
                       A++;
                    else{
                        for(int j = 0;j < 4;j++)
                            if(a[i] == b[j])
                                B++;
                    }
                }
                printf("%dA%dB\n",A,B);
            }
        }while(A != 4);
        printf("YOU WIN\n");
        do{
            printf("Play Again?(Y/N)");
            scanf("%c",&end);
            if(end == 'N')
                return 0;
        }while(end != 'Y' && end != 'y');
    }
}
