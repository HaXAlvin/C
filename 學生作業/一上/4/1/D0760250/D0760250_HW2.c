#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned char Initial_value=0b11111111,result_temp;
	//1. �b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
	Initial_value=Initial_value&0b11111101;
	//2. �b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F
	Initial_value=Initial_value&0b11111011;
	//3. �b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
	Initial_value=Initial_value|0b00000100;
	//4. �b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
	Initial_value=Initial_value&0b11101111;
	//5. �b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
	Initial_value=Initial_value&0b10111111;

	result_temp=Initial_value&0b00000001;
	printf("�j�@�W�G%hhd\n",result_temp);
	result_temp=Initial_value&0b00000010;
    result_temp=result_temp>>1;
	printf("�j�@�U�G%hhd\n",result_temp);
	result_temp=Initial_value&0b00000100;
    result_temp=result_temp>>2;
	printf("�j�G�W�G%hhd\n",result_temp);
	result_temp=Initial_value&0b00001000;
	result_temp=result_temp>>3;
	printf("�j�G�U�G%hhd\n",result_temp);
	result_temp=Initial_value&0b00010000;
	result_temp=result_temp>>4;
	printf("�j�T�W�G%hhd\n",result_temp);
	result_temp=Initial_value&0b00100000;
	result_temp=result_temp>>5;
	printf("�j�T�U�G%hhd\n",result_temp);
	result_temp=Initial_value&0b01000000;
	result_temp=result_temp>>6;
	printf("�j�|�W�G%hhd\n",result_temp);
	result_temp=Initial_value&0b10000000;
	result_temp=result_temp>>7;
	printf("�j�|�U�G%hhd\n",result_temp);

	return 0;
}


