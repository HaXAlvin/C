#include <stdio.h>
#include <stdlib.h>

int main()
{
    char val00 =0b10000001;
    char val11 =0b10000000;
    char val12 =0b00000000;
    char val01 =0b00100001;
    char val21 =0b00100000;
    char val02 =0b00010001;
    char val22 =0b00010000;
    char val31 =0b00000000;
    char val03 =0b00000101;
    char val32 =0b00000100;
    char val41 =0b00000000;
    char val04 =0b00000000;
    char val42 =0b00000001;

    printf("�j�@�W:%d\n" , ( val00 ^ val11) );
    printf("�j�@�U:%d\n" , val12);//�b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
    printf("�j�G�W:%d\n" , ( val01 ^ val21) );//�b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F,�b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
    printf("�j�G�U:%d\n" , ( val02 ^ val22) );
    printf("�j�T�W:%d\n" , val31) ;//�b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
    printf("�j�T�U:%d\n" , ( val03 ^ val32) );
    printf("�j�|�W:%d\n" , val41);//�b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
    printf("�j�|�U:%d\n" , ( val04 ^ val42) );

    return 0;
}
