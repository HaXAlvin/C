#include<stdio.h>

int main(){
    int allpass = 0b11111111;

    // 1. �b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
    allpass = allpass ^ 0b00000010;//11111101
    // 2. �b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F
    allpass = allpass ^ 0b00000100;//11111001
    // 3. �b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
    allpass = allpass ^ 0b00000100;//11111101
    // 4. �b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
    allpass = allpass ^ 0b00010000;//11101101
    // 5. �b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
    allpass = allpass ^ 0b01000000;//10101101

    int sem1 = allpass & 0b00000001;
    int sem2 = allpass & 0b00000010;
    int sem3 = allpass & 0b00000100;
    int sem4 = allpass & 0b00001000;
    int sem5 = allpass & 0b00010000;
    int sem6 = allpass & 0b00100000;
    int sem7 = allpass & 0b01000000;
    int sem8 = allpass & 0b10000000;

    printf("�j�@�W:%d\n",sem1);
    printf("�j�@�U:%d\n",sem2>>1);
    printf("�j�G�W:%d\n",sem3>>2);
    printf("�j�G�U:%d\n",sem4>>3);
    printf("�j�T�W:%d\n",sem5>>4);
    printf("�j�T�U:%d\n",sem6>>5);
    printf("�j�|�W:%d\n",sem7>>6);
    printf("�j�|�U:%d\n",sem8>>7);
    
    return 0;

}
 
