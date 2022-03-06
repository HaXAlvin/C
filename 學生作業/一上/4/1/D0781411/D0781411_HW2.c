#include <stdio.h>
#include <stdlib.h>

int main ()
{
	unsigned char a = 0b11111111; //大一下被當 
	a=a&0b10111111; //大二上被當 
	a=a&0b11011111; //大二上被當 
	a=a|0b00100000; //大二上求情過了
	a=a&0b11110111; //大三上被當 
	a=a&0b11111101; //大四被當 
	printf("大一上:%d\n",a>>7);
	printf("大一下:%d\n",(a&0b01000000)>>6);
	printf("大二上:%d\n",(a&0b00100000)>>5);
	printf("大二下:%d\n",(a&0b00010000)>>4);
	printf("大三上:%d\n",(a&0b00001000)>>3);
	printf("大三下:%d\n",(a&0b00000100)>>2);
	printf("大四上:%d\n",(a&0b00000010)>>1);
	printf("大四下:%d\n",(a&0b00000001));
	return 0; 
}

