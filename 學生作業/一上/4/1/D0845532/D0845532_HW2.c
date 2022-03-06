#include<stdio.h>//11111111

int main()
{/* 1111 1111
    1011 1111
    1001 1111
    1011 1111
    1011 0111
    1011 0101*/
    char val1 =0b11111111,val2;
    char val3 =0b10000000;
    char val4 =0b00000000;
    char val5 =0b00100000;
    char val6 =0b00010000;
    char val7 =0b00000000;
    char val8 =0b00000100;
    char val9 =0b00000000;
    char val10 =0b00000001;
    val2 =0b01000000;
    val1^=val2;     //在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了
                    // 在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了
                    // 在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分
    val2=0b00001000;
    val1^=val2;     //在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了
    val2 =0b10110101;
    val1&=val2;     //在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了
    printf("大一上:%d\n",(val1&val3)>>7);
    printf("大一下:%d\n",(val1&val4)>>6);
    printf("大二上:%d\n",(val1&val5)>>5);
    printf("大二下:%d\n",(val1&val6)>>4);
    printf("大三上:%d\n",(val1&val7)>>3);
    printf("大三下:%d\n",(val1&val8)>>2);
    printf("大四上:%d\n",(val1&val9)>>1);
    printf("大四下:%d\n",val1&val10);





    return 0;
}
