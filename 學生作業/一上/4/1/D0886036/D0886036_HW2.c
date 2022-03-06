#include <stdio.h>
#include <stdlib.h>

int main()
{
    char val00 =0b10000001;
    char val11 =0b10000000;
    char val12 =0b00000000;
    char val01 =0b00100001;
    char val21 =0b00100000;
    char val02 =0b00010001;
    char val22 =0b00010000;
    char val31 =0b00000000;
    char val03 =0b00000101;
    char val32 =0b00000100;
    char val41 =0b00000000;
    char val04 =0b00000000;
    char val42 =0b00000001;

    printf("大一上:%d\n" , ( val00 ^ val11) );
    printf("大一下:%d\n" , val12);//在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了
    printf("大二上:%d\n" , ( val01 ^ val21) );//在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了,在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分
    printf("大二下:%d\n" , ( val02 ^ val22) );
    printf("大三上:%d\n" , val31) ;//在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了
    printf("大三下:%d\n" , ( val03 ^ val32) );
    printf("大四上:%d\n" , val41);//在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了
    printf("大四下:%d\n" , ( val04 ^ val42) );

    return 0;
}
