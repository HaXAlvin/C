#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned char pass      = 0b11111111;		
    unsigned char two_sem   = 0b11111101;   //�j�@�U
    unsigned char three_sem = 0b11111011;   //�j�G�W
    unsigned char five_sem  = 0b11101111;   //�j�T�W
    unsigned char seven_sem = 0b10111111;   //�j�|�W
    unsigned char mask;							
		
	
    //1. �b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
    pass = pass & two_sem;
	
    //2. �b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F
    pass = pass & three_sem;
	
    //3. �b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
    pass = pass | ~three_sem;

    //4. �b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
    pass = pass & five_sem;

    //5. �b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
    pass = pass & seven_sem;


    //�ư����ݭn���ơA�������N�N��ӾǴ����Ʈ��쭺��A�A�k���^������ܥX�� 

    mask = pass << 7;  
    printf("�j�@�W�G%hhu \n", mask >> 7 );

    mask = pass << 6;
    printf("�j�@�U�G%hhu \n", mask >> 7 );

    mask = pass << 5;
    printf("�j�G�W�G%hhu \n", mask >> 7 );

    mask = pass << 4;
    printf("�j�G�U�G%hhu \n", mask >> 7 );

    mask = pass << 3;
    printf("�j�T�W�G%hhu \n", mask >> 7 );

    mask = pass << 2;
    printf("�j�T�U�G%hhu \n", mask >> 7 );

    mask = pass << 1;
    printf("�j�|�W�G%hhu \n", mask >> 7 );

    printf("�j�|�U�G%hhu \n", pass >> 7 );

    return 0;

}

