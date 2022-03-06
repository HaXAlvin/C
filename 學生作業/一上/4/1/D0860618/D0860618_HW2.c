#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char word= 0b11111111;
    //1. 在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了
    word=word^0b00000010;
    //2. 在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了
    word=word^0b00000100;
    //3. 在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分
    word=word^0b00000100;
    //4. 在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了
    word=word^0b00010000;
    //5. 在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了
    word=word^0b01000000;

    //10110101;
    printf("大一上:%hhd\n",word&0b00000001);
    printf("大一下:%hhd\n",word&0b00000001>>1);
    printf("大二上:%hhd\n",word&0b00000001);
    printf("大二下:%hhd\n",word&0b00000001);
    printf("大三上:%hhd\n",word&0b00000001>>4);
    printf("大三下:%hhd\n",word&0b00000001);
    printf("大四上:%hhd\n",word&0b00000001>>6);
    printf("大四下:%hhd\n",word&0b00000001);
}


