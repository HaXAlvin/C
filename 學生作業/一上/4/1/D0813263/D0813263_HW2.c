#include<stdio.h>

int main(){
    char num=0b11111111;
    num=num&0b11111111;//�j�@�W All Pase
    num=num&0b11111101;//�b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
    num=num&0b11111011;//�b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F
    num=num&0b11111111;//�b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
    num=num&0b11111111;//�j�G�U All Pase
    num=num&0b11101111;//�b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
    num=num&0b11111111;//�j�T�U All Pase
    num=num&0b10111111;//�b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
    num=num&0b11111111;//�j�|�U All Pase

    printf("�j�@�W:%d\n",num&0b00000001);
    printf("�j�@�U:%d\n",num&0b00000000>>1);
    printf("�j�G�W:%d\n",num&0b00000100>>2);
    printf("�j�G�U:%d\n",num&0b00001000>>3);
    printf("�j�T�W:%d\n",num&0b00000000>>4);
    printf("�j�T�U:%d\n",num&0b00100000>>5);
    printf("�j�|�W:%d\n",num&0b00000000>>6);
    printf("�j�|�U:%d\n",num&0b10000000>>7);

    return 0;
}
