#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

char q[4]= {0};
char my[4]= {0};
void sn(void);
void check(void);
int i,j,ans;
int ag;
void sn() {    //�X�D���
    int i,j;
    srand(time(0));
    for(i=0; i<4; i++) {
        q[i]=rand()%10;
        for(j=0; j<i; j++)
            if(q[j]==q[i])
                i--;
    }
}
void   check() {
    int boolin = 1; //�ΨӪ�ܨϥΪ̬O�_���`��J
    printf(">> ");
    scanf("%d",&ans);
    my[0] = ans / 1000;  //�ഫ
    my[1] = ans / 100 % 10;
    my[2] = ans / 10 % 10;
    my[3] = ans % 10;
    if((strlen(my)!=4)) {
        //�P�_�ϥΪ̬O�_��J�F�|�Ӧr��
        boolin *=0;
        printf("INPUT ERROR\n");
    }
    for( i=0; i<4; i++) {
        //�P�_�ϥΪ̬O�_��J���ƼƦr
        for(j=0; j<i; j++) {
            while( my[j]==my[i]) {
                printf("INPUT ERROR\n");
                boolin *= 0;
                break;
            }
            if(!boolin)
                break;
        }
        if(!boolin)
            break;
    }

}
int main() {
    do {
        srand(time(NULL));
        int a=0;
        int b=0;
        sn();
        do {
            check();
            int i,j;
            a=0;
            b=0;

            for( i = 0; i < 4; i++ ) {
                if( q[i] == my[i] ) /* ��m�ۦP�AA �[�@ */
                    a++;
                else {
                    /* ��m���ۦP */
                    for( j = 0; j < 4; j++ )
                        if( q[i] == my[j] ) /* ���O�ȬۦP�AB �[�@ */
                            b++;
                }
            }



            if(a!=4)
                printf("%dA%dB\n",a,b);  //�S�L���A���N��ܴXA�XB
        } while(a!=4);  //�p�G��4A�N��ϥΪ̹L���F�I
        printf("YOU WIN\n");
        printf("Play again�H�]Y/N�^�G");
        scanf("%d", &ag);
        if(ag=='n'||ag=='N')
            return 0;
    } while(ag=='y'||ag=='Y');

}
