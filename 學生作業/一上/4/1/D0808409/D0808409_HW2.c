unsigned char OP = 0b11111111; //�ڭw
int main()
{
    //1. �b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F   //2  0100 0000
    SaveChar(2);
    //2. �b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��F //3
    SaveChar(3);
    //3. �b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60�� //3
    SaveChar(3);
    //4. �b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F  //5
    SaveChar(5);
    //5. �b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F //7
    SaveChar(7);
    for(int x=1 ;x<=8 ;x++)
    {
    Out(x);
    printf("\n");
    }
}

int SaveChar(int num)//,unsigned char op)//�L�o num�ĴX�� ���OP�Y�쬰0
{
   switch (num)
   {
    case 1:
        OP ^= 0b10000000;
        break;
    case 2:
        OP ^= 0b01000000;
        break;
    case 3:
        OP ^= 0b00100000;
        break;
    case 4:
        OP ^= 0b00010000;
        break;
    case 5:
        OP ^= 0b00001000;
        break;
    case 6:
        OP ^= 0b00000100;
        break;
    case 7:
        OP ^= 0b00000010;
        break;
    case 8:
        OP ^= 0b00000001;
        break;
   }
}
int Out(int num)//�N���w���j�Ǧ~�ŬO�_�ڭw��X
{
    unsigned char litteOP = OP;
    switch (num)
   {
    case 1:
        litteOP &= 0b10000000;
        printf("�j�@�W�G%d",litteOP>>7);
        break;
    case 2:
        litteOP &= 0b01000000;
        printf("�j�@�U�G%d",litteOP>>6);
        break;
    case 3:
        litteOP &= 0b00100000;
        printf("�j�G�W�G%d",litteOP>>5);
        break;
    case 4:
        litteOP &= 0b00010000;
        printf("�j�G�U�G%d",litteOP>>4);
        break;
    case 5:
        litteOP &= 0b00001000;
        printf("�j�T�W�G%d",litteOP>>3);
        break;
    case 6:
        litteOP &= 0b00000100;
        printf("�j�T�U�G%d",litteOP>>2);
        break;
    case 7:
        litteOP &= 0b00000010;
        printf("�j�|�W�G%d",litteOP>>1);
        break;
    case 8:
        litteOP &= 0b00000001;
        printf("�j�|�U�G%d",litteOP>>0);
        break;
   }
}
