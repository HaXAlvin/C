#include<stdio.h>
#include<stdlib.h>


int main()
{
    char sem = 0b11111111;
    char event1 = 0b10111111;
    char event2 = 0b10011111;
    char event3 = 0b00100000;
    char event4 = 0b10110111;
    char event5 = 0b10110101;
    char val1 = 0b00000001;
    printf("�j�@�W:%d\n",sem>>7 & val1);


    sem = sem & event1;//�b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
    printf("�j�@�U:%d\n",sem>>6 & val1);


    sem = sem & event2;//�b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F

    sem = sem ^ event3;//�b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
    printf("�j�G�W:%d\n",sem>>5 & val1);

    printf("�j�G�U:%d\n",sem>>4 & val1);


    sem = sem & event4;//�b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
    printf("�j�T�W:%d\n",sem>>3 &val1);

    printf("�j�T�U:%d\n",sem>>2 &val1);


    sem = sem & event5;//�b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
    printf("�j�|�W:%d\n",sem>>1 &val1);
    printf("�j�|�U:%d\n",sem & val1);

    return 0;



}
