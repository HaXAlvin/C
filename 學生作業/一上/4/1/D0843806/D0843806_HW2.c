#include<stdio.h>

int main()
{
    char init = 0b11111111;
    char val1 = 0b01000000;
    unsigned char Fre2 = init ^ val1;//1.�b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
    //1011 1111
    char val2 = 0b00100000;
    unsigned char Sop1 = Fre2 ^ val2;//2.�b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F
    //1001 1111
    char val3 = 0b10111111;
    unsigned char Sop1_2 = Sop1 | val3;//3.�b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
    //1011 1111
    char val4 = 0b00001000;
    unsigned char Jun1 = Sop1_2 ^ val4;//4.�b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
    //1011 0111
    char val5 = 0b00000010;
    unsigned char Sen1 = Jun1 ^ val5;//5.�b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
    //1011 0101
    printf("�j�@�W:%d\n", Sen1 & 0b00000001);
    printf("�j�@�U:%d\n", Sen1 & 0b00000000);
    printf("�j�G�W:%d\n", Sen1 & 0b00000001);
    printf("�j�G�U:%d\n", Sen1 & 0b00000001);
    printf("�j�T�W:%d\n", Sen1 & 0b00000000);
    printf("�j�T�U:%d\n", Sen1 & 0b00000001);
    printf("�j�|�W:%d\n", Sen1 & 0b00000000);
    printf("�j�|�U:%d\n", Sen1 & 0b00000001);
    return 0;
}
