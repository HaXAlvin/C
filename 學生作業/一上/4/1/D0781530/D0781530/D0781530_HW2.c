#include <stdio.h>
#include <stdlib.h>

int main(){
	char val = 0b11111111;
	char val2;

	val2 = val & 0b11111111;
	if(val2==val)
	{
	printf("�j�@�W:1\n");
	val = val & 0b11111111;
	}
	else
	printf("�j�@�W:0\n");
	val = val & 0b11111111;

    //1. �b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
	val2 = val & 0b10111111;
	if(val2==val)
	{
	printf("�j�@�U:1\n");
	val = val & 0b10111111;
	}
	else
	printf("�j�@�U:0\n");
	val = val & 0b10111111;

    //2. �b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F
    //3. �b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
	val2 = val & 0b10111111;
	if(val2==val)
	{
	printf("�j�G�W:1\n");
	val = val & 0b10111111;
	}
	else
	printf("�j�G�W:0\n");
	val = val & 0b10111111;

	val2 = val & 0b10111111;
	if(val2==val)
	{
	printf("�j�G�U:1\n");
	val = val & 0b10111111;
	}
	else
	printf("�j�G�U:0\n");
	val = val & 0b10111111;

    //4. �b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
	val2 = val & 0b10110111;
	if(val2==val)
	{
	printf("�j�T�W:1\n");
	val = val & 0b10110111;
	}
	else
	printf("�j�T�W:0\n");
	val = val & 0b10110111;

	val2 = val & 0b10110111;
	if(val2==val)
	{
	printf("�j�T�U:1\n");
	val = val & 0b10110111;
	}
	else
	printf("�j�T�U:0\n");
	val = val & 0b10110111;

    //5. �b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
	val2 = val & 0b10110101;
	if(val2==val)
	{
	printf("�j�|�W:1\n");
	val = val & 0b10110101;
	}
	else
	printf("�j�|�W:0\n");
	val = val & 0b10110101;

	val2 = val & 0b10110101;
	if(val2==val)
	{
	printf("�j�|�U:1\n");
	val = val & 0b10110101;
	}
	else
	printf("�j�|�U:0\n");
	val = val & 0b10110101;

return 0;


}
