#include<stdio.h>
#include<stdlib.h>

int check (char ans[5],int ran[4],int finish) {
    finish=0;
    int length=0;
    int temp=0,guess[5];
    int counta=0,countb=0,x=0;
    length = strlen(ans);

    while (length!=4) {
        printf("INPUT ERROR!\n");
        finish =0;
        return finish;
    }
    temp = atoi(ans);

    guess[1]=temp/1000;
    guess[2]=(temp%1000)/100;
    guess[3]=(temp%100)/10;
    guess[4]=temp%10;

    if (guess[1]==guess[2] || guess[1]==guess[3] || guess[1]==guess[4]||guess[2]==guess[3]||guess[2]==guess[4]||guess[3]==guess[4]) {
        printf("INPUT ERROR!\n");
        return finish;
    }

    for (x=0; x<=4; ++x) {
        if (guess[x]==ran[1] || guess[x]==ran[2] || guess[x]==ran[3] || guess[x]==ran[4]) {
            if (guess[x]==ran[x]) {
                counta++;
            } else {
                countb++;
            }
        } else {
            continue;
        }

    }
    if (counta==4) {
        finish=1;
        return finish;
    } else {
        printf("%dA%dB\n",counta,countb);
        finish=0;
        return finish;
    }

}

int main () {
    char choose[1]= {0};
play:
    do {
        int finish=0;
        char ans[5];
        char choose[1]= {0};
        int ran[5];

        srand(time(NULL));
        ran[1]= rand()%10;
        ran[2]= rand()%10;
        while (ran[2]==ran[1]) {
            ran[2]= rand()%10;
        }
        ran[3]= rand()%10;
        while (ran[3]==ran[1] || ran[3]==ran[2]) {
            ran[3]= rand()%10;
        }
        ran[4]= rand()%10;
        while (ran[4]==ran[1] || ran[4]==ran[2] || ran[4]==ran[3]) {
            ran[4]= rand()%10;
        }

        //printf("%d%d%d%d\n",ran[1],ran[2],ran[3],ran[4]);

        while (1) {
            scanf("%s",&ans);
            finish=check(ans,ran,finish);


            if ( finish==1) {
                printf("YOU WIN!\n");
pick:
                printf("Do you want to play again? Y/N :");
                scanf("%s",&choose[0]);
                if (choose[0]=='Y'||choose[0]=='y') {
                    //break;
                    goto play;
                }

                else if (choose[0]=='N'||choose[0]=='n') {
                    return 0;
                } else if (choose[0]!='N'&&choose[0]!='n'&&choose[0]!='Y'&&choose[0]!='y') {
                    printf("INPUT ERROR!\n");
                    goto pick;
                    //continue;
                }
            } else if (finish==0) {
                scanf("%s",&ans);
                check(ans,ran,finish);
            }
        }
    } while (choose=='Y'||choose=='y');
}
