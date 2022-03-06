#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char choose=' ';
    int i,n,guess[4];
    char num[5];
    srand(time(NULL));
    while(1) {
        int answer[100]= {0},count=0,a[10]= {0}; //隨機產生4個不同的數字
        for(i=0; i<4; i++) {
            n=rand()%10;
            if(answer[count]<n && a[n-1]==0) {
                answer[count]=n;
                //printf("%d",answer[count]);
                count++;
                a[n-1]++;
            } else
                i--;

        }
        for(int i=0;i<4;i++){
            printf("%d",answer[i]);
        }
        puts("");
        puts(" ");

        int count1=0,count2=0;
        while(count1!=4) {
            int count1=0,count2=0;
            do {
                printf(">> ");
                gets(num);


                guess[0] =   num[0]-48;
                guess[1] =   num[1]-48;
                guess[2] =   num[2]-48;
                guess[3] =   num[3]-48;

                if(strlen(num)!=4||guess[0]==guess[1]||guess[0]==guess[2]||guess[0]==guess[3]||guess[1]==guess[2]||guess[1]==guess[3]||guess[2]==guess[3]) {
                    printf("INPUT ERROR\n");//判斷是否輸入錯誤
                }
            } while(strlen(num)!=4 ||guess[0]==guess[1]||guess[0]==guess[2]||guess[0]==guess[3]||guess[1]==guess[2]||guess[1]==guess[3]||guess[2]==guess[3]);//判斷是否輸入錯誤

            for(i=0; i<4; i++) {
                for(n=0; n<4; n++) {
                    if(answer[i]==guess[n]) {
                        if(i==n)
                            count1++;//相同位置且相同數字
                        else
                            count2++;//不同位置且相同數字
                    }
                }
            }
            //printf("%d ",count1);
            //printf("%d\n",count2);
            if(count1==4) {
                break;
            } else
                printf("%dA%dB\n",count1,count2);

        }
        //    choose='a';
        printf("YOU WIN\n");
        int c=0;
        do {
            c=0;
            printf("Play Again?(Y/N)");//判斷是否重新玩一次
            scanf("%c",&choose);
            getchar();
            //	scanf("%c",&choose);
            //	printf("%c",choose);
            if(choose!='N' && choose!='Y')
                c=1;
            //    printf("%c",choose);

        } while(c==1);

        if(choose=='Y') {
            getchar();
            continue;
        }

        else if(choose=='N')
            return 0;
    }





}
