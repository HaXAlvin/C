#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

char q[4]= {0};
char my[4]= {0};
void sn(void);
void check(void);
int i,j,ans;
int ag;
void sn() {    //出題函數
    int i,j;
    srand(time(0));
    for(i=0; i<4; i++) {
        q[i]=rand()%10;
        for(j=0; j<i; j++)
            if(q[j]==q[i])
                i--;
    }
}
void   check() {
    int boolin = 1; //用來表示使用者是否正常輸入
    printf(">> ");
    scanf("%d",&ans);
    my[0] = ans / 1000;  //轉換
    my[1] = ans / 100 % 10;
    my[2] = ans / 10 % 10;
    my[3] = ans % 10;
    if((strlen(my)!=4)) {
        //判斷使用者是否輸入了四個字元
        boolin *=0;
        printf("INPUT ERROR\n");
    }
    for( i=0; i<4; i++) {
        //判斷使用者是否輸入重複數字
        for(j=0; j<i; j++) {
            while( my[j]==my[i]) {
                printf("INPUT ERROR\n");
                boolin *= 0;
                break;
            }
            if(!boolin)
                break;
        }
        if(!boolin)
            break;
    }

}
int main() {
    do {
        srand(time(NULL));
        int a=0;
        int b=0;
        sn();
        do {
            check();
            int i,j;
            a=0;
            b=0;

            for( i = 0; i < 4; i++ ) {
                if( q[i] == my[i] ) /* 位置相同，A 加一 */
                    a++;
                else {
                    /* 位置不相同 */
                    for( j = 0; j < 4; j++ )
                        if( q[i] == my[j] ) /* 但是值相同，B 加一 */
                            b++;
                }
            }



            if(a!=4)
                printf("%dA%dB\n",a,b);  //沒過關，那就顯示幾A幾B
        } while(a!=4);  //如果有4A代表使用者過關了！
        printf("YOU WIN\n");
        printf("Play again？（Y/N）：");
        scanf("%d", &ag);
        if(ag=='n'||ag=='N')
            return 0;
    } while(ag=='y'||ag=='Y');

}
