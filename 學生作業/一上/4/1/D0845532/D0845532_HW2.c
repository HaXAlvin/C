#include<stdio.h>//11111111

int main()
{/* 1111 1111
    1011 1111
    1001 1111
    1011 1111
    1011 0111
    1011 0101*/
    char val1 =0b11111111,val2;
    char val3 =0b10000000;
    char val4 =0b00000000;
    char val5 =0b00100000;
    char val6 =0b00010000;
    char val7 =0b00000000;
    char val8 =0b00000100;
    char val9 =0b00000000;
    char val10 =0b00000001;
    val2 =0b01000000;
    val1^=val2;     //�b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
                    // �b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F
                    // �b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
    val2=0b00001000;
    val1^=val2;     //�b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
    val2 =0b10110101;
    val1&=val2;     //�b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
    printf("�j�@�W:%d\n",(val1&val3)>>7);
    printf("�j�@�U:%d\n",(val1&val4)>>6);
    printf("�j�G�W:%d\n",(val1&val5)>>5);
    printf("�j�G�U:%d\n",(val1&val6)>>4);
    printf("�j�T�W:%d\n",(val1&val7)>>3);
    printf("�j�T�U:%d\n",(val1&val8)>>2);
    printf("�j�|�W:%d\n",(val1&val9)>>1);
    printf("�j�|�U:%d\n",val1&val10);





    return 0;
}
