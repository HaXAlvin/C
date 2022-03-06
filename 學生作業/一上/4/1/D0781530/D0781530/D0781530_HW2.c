#include <stdio.h>
#include <stdlib.h>

int main(){
	char val = 0b11111111;
	char val2;

	val2 = val & 0b11111111;
	if(val2==val)
	{
	printf("大一上:1\n");
	val = val & 0b11111111;
	}
	else
	printf("大一上:0\n");
	val = val & 0b11111111;

    //1. 在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了
	val2 = val & 0b10111111;
	if(val2==val)
	{
	printf("大一下:1\n");
	val = val & 0b10111111;
	}
	else
	printf("大一下:0\n");
	val = val & 0b10111111;

    //2. 在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了
    //3. 在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分
	val2 = val & 0b10111111;
	if(val2==val)
	{
	printf("大二上:1\n");
	val = val & 0b10111111;
	}
	else
	printf("大二上:0\n");
	val = val & 0b10111111;

	val2 = val & 0b10111111;
	if(val2==val)
	{
	printf("大二下:1\n");
	val = val & 0b10111111;
	}
	else
	printf("大二下:0\n");
	val = val & 0b10111111;

    //4. 在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了
	val2 = val & 0b10110111;
	if(val2==val)
	{
	printf("大三上:1\n");
	val = val & 0b10110111;
	}
	else
	printf("大三上:0\n");
	val = val & 0b10110111;

	val2 = val & 0b10110111;
	if(val2==val)
	{
	printf("大三下:1\n");
	val = val & 0b10110111;
	}
	else
	printf("大三下:0\n");
	val = val & 0b10110111;

    //5. 在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了
	val2 = val & 0b10110101;
	if(val2==val)
	{
	printf("大四上:1\n");
	val = val & 0b10110101;
	}
	else
	printf("大四上:0\n");
	val = val & 0b10110101;

	val2 = val & 0b10110101;
	if(val2==val)
	{
	printf("大四下:1\n");
	val = val & 0b10110101;
	}
	else
	printf("大四下:0\n");
	val = val & 0b10110101;

return 0;


}
