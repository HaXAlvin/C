#include<stdio.h>
#include<stdlib.h>
int main()
{
    char val1=0b11111111;
    //1.�b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
    val1=val1&0b10111111;
    //2. �b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F
    val1=val1^0b00100000;
    //3. �b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
    val1=val1|0b10111111;
    //4. �b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
    val1=val1&0b10110111;
    //5. �b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
    val1=val1&0b10110101;
    printf("�j�@�W�G%d\n",(val1&(1<<7))>>7);
    printf("�j�@�U�G%d\n",(val1&(1<<6))>>6);
    printf("�j�G�W: %d\n",(val1&(1<<5))>>5);
    printf("�j�G�U�G%d\n",(val1&(1<<4))>>4);
    printf("�j�T�W�G%d\n",(val1&(1<<3))>>3);
    printf("�j�T�U�G%d\n",(val1&(1<<2))>>2);
    printf("�j�|�W�G%d\n",(val1&(1<<1))>>1);
    printf("�j�|�U�G%d\n",(val1&(1<<0))>>0);
    return 0;
}
