#include<stdio.h>

int main(){
    int allpass = 0b11111111;

    // 1. 在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了
    allpass = allpass ^ 0b00000010;//11111101
    // 2. 在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了
    allpass = allpass ^ 0b00000100;//11111001
    // 3. 在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分
    allpass = allpass ^ 0b00000100;//11111101
    // 4. 在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了
    allpass = allpass ^ 0b00010000;//11101101
    // 5. 在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了
    allpass = allpass ^ 0b01000000;//10101101

    int sem1 = allpass & 0b00000001;
    int sem2 = allpass & 0b00000010;
    int sem3 = allpass & 0b00000100;
    int sem4 = allpass & 0b00001000;
    int sem5 = allpass & 0b00010000;
    int sem6 = allpass & 0b00100000;
    int sem7 = allpass & 0b01000000;
    int sem8 = allpass & 0b10000000;

    printf("大一上:%d\n",sem1);
    printf("大一下:%d\n",sem2>>1);
    printf("大二上:%d\n",sem3>>2);
    printf("大二下:%d\n",sem4>>3);
    printf("大三上:%d\n",sem5>>4);
    printf("大三下:%d\n",sem6>>5);
    printf("大四上:%d\n",sem7>>6);
    printf("大四下:%d\n",sem8>>7);
    
    return 0;

}
 
