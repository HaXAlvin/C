#include<stdio.h>

int main(){
    char sem= 0B11111111;
//1. �b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
    char event1 = 0B10111111;
    sem = sem & event1;
//2. �b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F
    char event2 = 0B11011111;
    sem = sem & event2;
//3. �b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
    char event3 = 0B00100000;
    sem = sem ^ event3;
//4. �b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
    char event4 = 0B11110111;
    sem = sem & event4;
//5. �b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
    char event5 = 0B11111101;
    sem = sem & event5;

    char sem1up = sem,sem1down = sem;
    char sem2up = sem,sem2down = sem;
    char sem3up = sem,sem3down = sem;
    char sem4up = sem,sem4down = sem;
    char stan = 0B00000001;
    sem1up = sem1up >> 7;
    sem1up = sem1up & stan;
    printf("�j�@�W:%d\n",sem1up);
    sem1down = sem1down >> 6;
    sem1down = sem1down & stan;
    printf("�j�@�U:%d\n",sem1down);
    sem2up = sem2up >> 5;
    sem2up = sem2up & stan;
    printf("�j�G�W:%d\n",sem2up);
    sem2down = sem2down >> 4;
    sem2down = sem2down & stan;
    printf("�j�G�U:%d\n",sem2down);
    sem3up = sem3up >> 3;
    sem3up = sem3up & stan;
    printf("�j�T�W:%d\n",sem3up);
    sem3down = sem3down >> 2;
    sem3down = sem3down & stan;
    printf("�j�T�U:%d\n",sem3down);
    sem4up = sem4up >> 1;
    sem4up = sem4up & stan;
    printf("�j�|�W:%d\n",sem4up);
    sem4down = sem4down & stan;
    printf("�j�|�U:%d\n",sem4down & stan);
}
