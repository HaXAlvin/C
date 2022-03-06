//程式設計功課 9/23 HW2
#include <stdio.h>

int main()
{
	unsigned char result = 0b11111111;

	// 1.在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了
	result = result & 0b10111111;

	// 2.在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了
	result = result & 0b11011111;

	// 3.在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分
	result = result | 0b00100000;

	// 4.在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了
	result = result & 0b11110111;

	// 5.在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了
	result = result & 0b11111101;

	// 輸出結果
	printf("大一上: %d\n", (result >> 7) % 2);
	printf("大一下: %d\n", (result >> 6) % 2);
	printf("大二上: %d\n", (result >> 5) % 2);
	printf("大二下: %d\n", (result >> 4) % 2);
	printf("大三上: %d\n", (result >> 3) % 2);
	printf("大三下: %d\n", (result >> 2) % 2);
	printf("大四上: %d\n", (result >> 1) % 2);
	printf("大四下: %d\n", (result) % 2);

	return 0;
}