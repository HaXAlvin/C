unsigned char OP = 0b11111111; //歐趴
int main()
{
    //1. 在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了   //2  0100 0000
    SaveChar(2);
    //2. 在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了 //3
    SaveChar(3);
    //3. 在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分 //3
    SaveChar(3);
    //4. 在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了  //5
    SaveChar(5);
    //5. 在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了 //7
    SaveChar(7);
    for(int x=1 ;x<=8 ;x++)
    {
    Out(x);
    printf("\n");
    }
}

int SaveChar(int num)//,unsigned char op)//過濾 num第幾位 更改OP某位為0
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
int Out(int num)//將指定的大學年級是否歐趴輸出
{
    unsigned char litteOP = OP;
    switch (num)
   {
    case 1:
        litteOP &= 0b10000000;
        printf("大一上：%d",litteOP>>7);
        break;
    case 2:
        litteOP &= 0b01000000;
        printf("大一下：%d",litteOP>>6);
        break;
    case 3:
        litteOP &= 0b00100000;
        printf("大二上：%d",litteOP>>5);
        break;
    case 4:
        litteOP &= 0b00010000;
        printf("大二下：%d",litteOP>>4);
        break;
    case 5:
        litteOP &= 0b00001000;
        printf("大三上：%d",litteOP>>3);
        break;
    case 6:
        litteOP &= 0b00000100;
        printf("大三下：%d",litteOP>>2);
        break;
    case 7:
        litteOP &= 0b00000010;
        printf("大四上：%d",litteOP>>1);
        break;
    case 8:
        litteOP &= 0b00000001;
        printf("大四下：%d",litteOP>>0);
        break;
   }
}
