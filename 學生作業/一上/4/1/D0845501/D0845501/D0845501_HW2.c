#include<stdio.h>
#include<stdlib.h>
int main()
{
    char sem1 = 0b11111111;
    char val = 0b00010000;
    char bite = 0b00000001;


    //1. �b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
    char sem2 = (val << 2)^sem1;//10111111
    //2. �b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F
    char orisem3 = sem2 ^ (val << 1);//10011111
    //3. �b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
    char sem3 = orisem3 ^ (val << 1);//10111111
    char sem4 = sem3 ;
    //4. �b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
    char sem5 = sem4 ^ (val >> 1);//10110111
    char sem6 = sem5;
    //5. �b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
    char sem7 = sem6 ^ (val >> 3);//10110101
    char sem8 = sem7 ;

    printf("�j�@�W:%d\n"
           "�j�@�U:%d\n"
           "�j�G�W:%d\n"
           "�j�G�U:%d\n"
           "�j�T�W:%d\n"
           "�j�T�U:%d\n"
           "�j�|�W:%d\n"
           "�j�|�U:%d\n"
           ,(sem1 & bite)
           ,(sem2 & bite) >> 1
           ,(sem3 & bite)
           ,(sem4 & bite)
           ,(sem5 & bite) >> 1
           ,(sem6 & bite)
           ,(sem7 & bite) >> 1
           ,(sem8 & bite));


    return 0;
}
