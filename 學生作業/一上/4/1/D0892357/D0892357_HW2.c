//�{���]�p�\�� 9/23 HW2
#include <stdio.h>

int main()
{
	unsigned char result = 0b11111111;

	// 1.�b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
	result = result & 0b10111111;

	// 2.�b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F
	result = result & 0b11011111;

	// 3.�b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
	result = result | 0b00100000;

	// 4.�b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
	result = result & 0b11110111;

	// 5.�b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
	result = result & 0b11111101;

	// ��X���G
	printf("�j�@�W: %d\n", (result >> 7) % 2);
	printf("�j�@�U: %d\n", (result >> 6) % 2);
	printf("�j�G�W: %d\n", (result >> 5) % 2);
	printf("�j�G�U: %d\n", (result >> 4) % 2);
	printf("�j�T�W: %d\n", (result >> 3) % 2);
	printf("�j�T�U: %d\n", (result >> 2) % 2);
	printf("�j�|�W: %d\n", (result >> 1) % 2);
	printf("�j�|�U: %d\n", (result) % 2);

	return 0;
}