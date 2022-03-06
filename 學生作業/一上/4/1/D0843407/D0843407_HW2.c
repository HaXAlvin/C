#include<stdio.h>

int main(){
    char sem= 0B11111111;
//1. 在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了
    char event1 = 0B10111111;
    sem = sem & event1;
//2. 在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了
    char event2 = 0B11011111;
    sem = sem & event2;
//3. 在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分
    char event3 = 0B00100000;
    sem = sem ^ event3;
//4. 在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了
    char event4 = 0B11110111;
    sem = sem & event4;
//5. 在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了
    char event5 = 0B11111101;
    sem = sem & event5;

    char sem1up = sem,sem1down = sem;
    char sem2up = sem,sem2down = sem;
    char sem3up = sem,sem3down = sem;
    char sem4up = sem,sem4down = sem;
    char stan = 0B00000001;
    sem1up = sem1up >> 7;
    sem1up = sem1up & stan;
    printf("大一上:%d\n",sem1up);
    sem1down = sem1down >> 6;
    sem1down = sem1down & stan;
    printf("大一下:%d\n",sem1down);
    sem2up = sem2up >> 5;
    sem2up = sem2up & stan;
    printf("大二上:%d\n",sem2up);
    sem2down = sem2down >> 4;
    sem2down = sem2down & stan;
    printf("大二下:%d\n",sem2down);
    sem3up = sem3up >> 3;
    sem3up = sem3up & stan;
    printf("大三上:%d\n",sem3up);
    sem3down = sem3down >> 2;
    sem3down = sem3down & stan;
    printf("大三下:%d\n",sem3down);
    sem4up = sem4up >> 1;
    sem4up = sem4up & stan;
    printf("大四上:%d\n",sem4up);
    sem4down = sem4down & stan;
    printf("大四下:%d\n",sem4down & stan);
}
