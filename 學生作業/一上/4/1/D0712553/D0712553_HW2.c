#include<stdio.h>

int main()
{
    //�K�Ǵ��S���Q�����p
    char semesterpass = 0b11111111;
    //1.�b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F�C10111111
    char semester2 = 0b11111111 & 0b10111111;
    //2.�b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F�C10011111
    char semester3 = semester2 & 0b10011111;
    //3.�b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60���C10111111
    semester3 = semester3 | 0b10111111;
    //4.�b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F�C10110111
    char semester5 = semester3 & 0b10110111;
    //5.�b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F�C10110101
    char semester7 = semester5 & 0b10110101;
    //�K�Ǵ�semesterall�ǲߪ��p����̫�ƥ󵲧��ᤧ���p
    char semesterall = semester7;

    //�j1�W�Ǵ����Z��X�A�u��ܲ�1��bit
    int output = semesterall & 0b10000000;
    printf("�j�@�W:%d\n", output>>7);
    //�j1�U�Ǵ����Z��X�A�u��ܲ�2��bit
    output = semesterall & 0b00000000;
    printf("�j�@�U:%d\n", output>>6);
    //�j2�W�Ǵ����Z��X�A�u��ܲ�3��bit
    output = semesterall & 0b00100000;
    printf("�j�G�W:%d\n", output>>5);
    //�j2�U�Ǵ����Z��X�A�u��ܲ�4��bit
    output = semesterall & 0b00010000;
    printf("�j�G�U:%d\n", output>>4);
    //�j3�W�Ǵ����Z��X�A�u��ܲ�5��bit
    output = semesterall & 0b00000000;
    printf("�j�T�W:%d\n", output>>3);
    //�j3�U�Ǵ����Z��X�A�u��ܲ�6��bit
    output = semesterall & 0b00000100;
    printf("�j�T�U:%d\n", output>>2);
    //�j4�W�Ǵ����Z��X�A�u��ܲ�7��bit
    output = semesterall & 0b00000000;
    printf("�j�|�W:%d\n", output>>1);
    //�j4�U�Ǵ����Z��X�A�u��ܲ�8��bit
    output = semesterall & 0b00000001;
    printf("�j�|�U:%d\n", output);

    return 0;
}
