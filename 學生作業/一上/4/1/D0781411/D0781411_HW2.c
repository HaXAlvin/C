#include <stdio.h>
#include <stdlib.h>

int main ()
{
	unsigned char a = 0b11111111; //�j�@�U�Q�� 
	a=a&0b10111111; //�j�G�W�Q�� 
	a=a&0b11011111; //�j�G�W�Q�� 
	a=a|0b00100000; //�j�G�W�D���L�F
	a=a&0b11110111; //�j�T�W�Q�� 
	a=a&0b11111101; //�j�|�Q�� 
	printf("�j�@�W:%d\n",a>>7);
	printf("�j�@�U:%d\n",(a&0b01000000)>>6);
	printf("�j�G�W:%d\n",(a&0b00100000)>>5);
	printf("�j�G�U:%d\n",(a&0b00010000)>>4);
	printf("�j�T�W:%d\n",(a&0b00001000)>>3);
	printf("�j�T�U:%d\n",(a&0b00000100)>>2);
	printf("�j�|�W:%d\n",(a&0b00000010)>>1);
	printf("�j�|�U:%d\n",(a&0b00000001));
	return 0; 
}

