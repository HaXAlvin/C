#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char word= 0b11111111;
    //1. �b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
    word=word^0b00000010;
    //2. �b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F
    word=word^0b00000100;
    //3. �b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
    word=word^0b00000100;
    //4. �b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
    word=word^0b00010000;
    //5. �b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
    word=word^0b01000000;

    //10110101;
    printf("�j�@�W:%hhd\n",word&0b00000001);
    printf("�j�@�U:%hhd\n",word&0b00000001>>1);
    printf("�j�G�W:%hhd\n",word&0b00000001);
    printf("�j�G�U:%hhd\n",word&0b00000001);
    printf("�j�T�W:%hhd\n",word&0b00000001>>4);
    printf("�j�T�U:%hhd\n",word&0b00000001);
    printf("�j�|�W:%hhd\n",word&0b00000001>>6);
    printf("�j�|�U:%hhd\n",word&0b00000001);
}


