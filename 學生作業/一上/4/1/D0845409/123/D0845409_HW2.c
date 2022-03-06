#include<stdio.h>
#include<stdlib.h>

int main()
{
    char sem1 = 0b11111111;
    char val = 0b00010000;
    char bite = 0b00000001;

    //事件一:在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了
    char sem2 = (val << 2)^sem1;//1011 1111

    //事件二:在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了
    char ori_sem3 = sem2 ^ (val << 1);//1001 1111

    //事件三:在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分
    char sem3 = ori_sem3 ^ (val >> 1);//1011 1111
    char sem4 = sem3;

    //事件四:在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了
    char sem5 = sem4 ^ (val >> 1);//1011 0111
    char sem6 = sem5;

    //事件五:在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了
    char sem7 = sem6 ^ (val >> 3);//10110101
    char sem8 = sem7;

    printf("大一上:%d\n"
           "大一下:%d\n"
           "大二上:%d\n"
           "大二下:%d\n"
           "大三上:%d\n"
           "大三下:%d\n"
           "大四上:%d\n"
           "大四下:%d\n"
           ,(sem1 & bite)
           ,(sem2 & bite) >> 1
           ,(sem3 & bite)
           ,(sem4 & bite)
           ,(sem5 & bite) >> 1
           ,(sem6 & bite)
           ,(sem7 & bite) >> 1
           ,(sem8 & bite));

           return 0;
}
