#include<stdio.h>

int main()
{
    //八學期沒有被當的情況
    char semesterpass = 0b11111111;
    //1.在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了。10111111
    char semester2 = 0b11111111 & 0b10111111;
    //2.在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當了。10011111
    char semester3 = semester2 & 0b10011111;
    //3.在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分。10111111
    semester3 = semester3 | 0b10111111;
    //4.在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了。10110111
    char semester5 = semester3 & 0b10110111;
    //5.在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了。10110101
    char semester7 = semester5 & 0b10110101;
    //八學期semesterall學習狀況等於最後事件結束後之狀況
    char semesterall = semester7;

    //大1上學期成績輸出，只顯示第1個bit
    int output = semesterall & 0b10000000;
    printf("大一上:%d\n", output>>7);
    //大1下學期成績輸出，只顯示第2個bit
    output = semesterall & 0b00000000;
    printf("大一下:%d\n", output>>6);
    //大2上學期成績輸出，只顯示第3個bit
    output = semesterall & 0b00100000;
    printf("大二上:%d\n", output>>5);
    //大2下學期成績輸出，只顯示第4個bit
    output = semesterall & 0b00010000;
    printf("大二下:%d\n", output>>4);
    //大3上學期成績輸出，只顯示第5個bit
    output = semesterall & 0b00000000;
    printf("大三上:%d\n", output>>3);
    //大3下學期成績輸出，只顯示第6個bit
    output = semesterall & 0b00000100;
    printf("大三下:%d\n", output>>2);
    //大4上學期成績輸出，只顯示第7個bit
    output = semesterall & 0b00000000;
    printf("大四上:%d\n", output>>1);
    //大4下學期成績輸出，只顯示第8個bit
    output = semesterall & 0b00000001;
    printf("大四下:%d\n", output);

    return 0;
}
