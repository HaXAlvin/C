#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned char pass      = 0b11111111;		
    unsigned char two_sem   = 0b11111101;   //大一下
    unsigned char three_sem = 0b11111011;   //大二上
    unsigned char five_sem  = 0b11101111;   //大三上
    unsigned char seven_sem = 0b10111111;   //大四上
    unsigned char mask;							
		
	
    //1. 在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了
    pass = pass & two_sem;
	
    //2. 在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了
    pass = pass & three_sem;
	
    //3. 在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分
    pass = pass | ~three_sem;

    //4. 在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了
    pass = pass & five_sem;

    //5. 在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了
    pass = pass & seven_sem;


    //排除不需要的數，先左移將代表該學期的數挪到首位，再右移回末位顯示出來 

    mask = pass << 7;  
    printf("大一上：%hhu \n", mask >> 7 );

    mask = pass << 6;
    printf("大一下：%hhu \n", mask >> 7 );

    mask = pass << 5;
    printf("大二上：%hhu \n", mask >> 7 );

    mask = pass << 4;
    printf("大二下：%hhu \n", mask >> 7 );

    mask = pass << 3;
    printf("大三上：%hhu \n", mask >> 7 );

    mask = pass << 2;
    printf("大三下：%hhu \n", mask >> 7 );

    mask = pass << 1;
    printf("大四上：%hhu \n", mask >> 7 );

    printf("大四下：%hhu \n", pass >> 7 );

    return 0;

}

