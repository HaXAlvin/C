#include <stdio.h>

int main(){
    char a=0b11111111;
    //1.在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了
    a=a&0b11111101;
    //2. 在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了
    a=a&0b11111001;
    //3. 在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分
    a=a|0b11111101;
    //4. 在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了
    a=a&0b11101101;
    //5. 在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了
    a=a&0b10101101;
    printf("大一上:%d\n大一下:%d\n大二上:%d\n大二下:%d\n大三上:%d\n大三下:%d\n大四上:%d\n大四下:%d\n", a&0b00000001,a&0b00000000,a&0b00000100>>2,a&0b00001000>>3,a&0b00000000,a&0b00100000>>5,a&0b00000000,a&0b10000000>>7);
	return 0;
}



