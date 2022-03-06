#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned char Initial_value=0b11111111,result_temp;
	//1. 在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了
	Initial_value=Initial_value&0b11111101;
	//2. 在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了
	Initial_value=Initial_value&0b11111011;
	//3. 在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分
	Initial_value=Initial_value|0b00000100;
	//4. 在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了
	Initial_value=Initial_value&0b11101111;
	//5. 在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了
	Initial_value=Initial_value&0b10111111;

	result_temp=Initial_value&0b00000001;
	printf("大一上：%hhd\n",result_temp);
	result_temp=Initial_value&0b00000010;
    result_temp=result_temp>>1;
	printf("大一下：%hhd\n",result_temp);
	result_temp=Initial_value&0b00000100;
    result_temp=result_temp>>2;
	printf("大二上：%hhd\n",result_temp);
	result_temp=Initial_value&0b00001000;
	result_temp=result_temp>>3;
	printf("大二下：%hhd\n",result_temp);
	result_temp=Initial_value&0b00010000;
	result_temp=result_temp>>4;
	printf("大三上：%hhd\n",result_temp);
	result_temp=Initial_value&0b00100000;
	result_temp=result_temp>>5;
	printf("大三下：%hhd\n",result_temp);
	result_temp=Initial_value&0b01000000;
	result_temp=result_temp>>6;
	printf("大四上：%hhd\n",result_temp);
	result_temp=Initial_value&0b10000000;
	result_temp=result_temp>>7;
	printf("大四下：%hhd\n",result_temp);

	return 0;
}


