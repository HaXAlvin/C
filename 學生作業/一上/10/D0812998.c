#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char choose=' ';
    int i,n,guess[4];
    char num[5];
    srand(time(NULL));
    while(1) {
        int answer[100]= {0},count=0,a[10]= {0}; //�H������4�Ӥ��P���Ʀr
        for(i=0; i<4; i++) {
            n=rand()%10;
            if(answer[count]<n && a[n-1]==0) {
                answer[count]=n;
                //printf("%d",answer[count]);
                count++;
                a[n-1]++;
            } else
                i--;

        }
        for(int i=0;i<4;i++){
            printf("%d",answer[i]);
        }
        puts("");
        puts(" ");

        int count1=0,count2=0;
        while(count1!=4) {
            int count1=0,count2=0;
            do {
                printf(">> ");
                gets(num);


                guess[0] =   num[0]-48;
                guess[1] =   num[1]-48;
                guess[2] =   num[2]-48;
                guess[3] =   num[3]-48;

                if(strlen(num)!=4||guess[0]==guess[1]||guess[0]==guess[2]||guess[0]==guess[3]||guess[1]==guess[2]||guess[1]==guess[3]||guess[2]==guess[3]) {
                    printf("INPUT ERROR\n");//�P�_�O�_��J���~
                }
            } while(strlen(num)!=4 ||guess[0]==guess[1]||guess[0]==guess[2]||guess[0]==guess[3]||guess[1]==guess[2]||guess[1]==guess[3]||guess[2]==guess[3]);//�P�_�O�_��J���~

            for(i=0; i<4; i++) {
                for(n=0; n<4; n++) {
                    if(answer[i]==guess[n]) {
                        if(i==n)
                            count1++;//�ۦP��m�B�ۦP�Ʀr
                        else
                            count2++;//���P��m�B�ۦP�Ʀr
                    }
                }
            }
            //printf("%d ",count1);
            //printf("%d\n",count2);
            if(count1==4) {
                break;
            } else
                printf("%dA%dB\n",count1,count2);

        }
        //    choose='a';
        printf("YOU WIN\n");
        int c=0;
        do {
            c=0;
            printf("Play Again?(Y/N)");//�P�_�O�_���s���@��
            scanf("%c",&choose);
            getchar();
            //	scanf("%c",&choose);
            //	printf("%c",choose);
            if(choose!='N' && choose!='Y')
                c=1;
            //    printf("%c",choose);

        } while(c==1);

        if(choose=='Y') {
            getchar();
            continue;
        }

        else if(choose=='N')
            return 0;
    }





}
