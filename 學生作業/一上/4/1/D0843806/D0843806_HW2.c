#include<stdio.h>

int main()
{
    char init = 0b11111111;
    char val1 = 0b01000000;
    unsigned char Fre2 = init ^ val1;//1.在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了
    //1011 1111
    char val2 = 0b00100000;
    unsigned char Sop1 = Fre2 ^ val2;//2.在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了
    //1001 1111
    char val3 = 0b10111111;
    unsigned char Sop1_2 = Sop1 | val3;//3.在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分
    //1011 1111
    char val4 = 0b00001000;
    unsigned char Jun1 = Sop1_2 ^ val4;//4.在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了
    //1011 0111
    char val5 = 0b00000010;
    unsigned char Sen1 = Jun1 ^ val5;//5.在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了
    //1011 0101
    printf("大一上:%d\n", Sen1 & 0b00000001);
    printf("大一下:%d\n", Sen1 & 0b00000000);
    printf("大二上:%d\n", Sen1 & 0b00000001);
    printf("大二下:%d\n", Sen1 & 0b00000001);
    printf("大三上:%d\n", Sen1 & 0b00000000);
    printf("大三下:%d\n", Sen1 & 0b00000001);
    printf("大四上:%d\n", Sen1 & 0b00000000);
    printf("大四下:%d\n", Sen1 & 0b00000001);
    return 0;
}
