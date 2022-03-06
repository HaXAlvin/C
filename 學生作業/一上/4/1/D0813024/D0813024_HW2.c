#include<stdio.h>
#include<stdlib.h>


int main()
{
    char sem = 0b11111111;
    char event1 = 0b10111111;
    char event2 = 0b10011111;
    char event3 = 0b00100000;
    char event4 = 0b10110111;
    char event5 = 0b10110101;
    char val1 = 0b00000001;
    printf("大一上:%d\n",sem>>7 & val1);


    sem = sem & event1;//在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了
    printf("大一下:%d\n",sem>>6 & val1);


    sem = sem & event2;//在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了

    sem = sem ^ event3;//在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分
    printf("大二上:%d\n",sem>>5 & val1);

    printf("大二下:%d\n",sem>>4 & val1);


    sem = sem & event4;//在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了
    printf("大三上:%d\n",sem>>3 &val1);

    printf("大三下:%d\n",sem>>2 &val1);


    sem = sem & event5;//在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了
    printf("大四上:%d\n",sem>>1 &val1);
    printf("大四下:%d\n",sem & val1);

    return 0;



}
