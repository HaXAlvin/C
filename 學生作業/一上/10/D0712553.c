#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    srand(time(0));
    int read[4]={0}; //�ϥΪ̿�J�s���ܼư}�C
    int ans[4]={0}; //�q���w�]����
    int write_read; //�ϥΪ̿�J�s���ܼ�
    int i, j;
    int A=0, B=0; //�Ʀr���T�CA=��m���T�CB=��m���~�C
    int count = 0;
    char play_again;
    do { //�ͦ��üƵ���
        for (i=0; i<4; i++){
            ans[i] = (rand() % 10); //%10�b0~9����
            for (j=0; j<i; j++){
                if (ans[i] == ans[j]){
                    i--;  //�Ʀr�ۦP�A�A���@���üƥͦ�
                }
            }
        }
        for(i=0;i<4;i++){
            printf("%d",ans[i]);
        }
        puts("");
        do {
            do {
                A = 0; //���m
                B = 0;  //���m
                count = 0; //���m
                printf(">> ");
                scanf("%d", &write_read);
                if (write_read<1000 || write_read>9999){ //�ϥΪ̥u���J4��Ʀr
                    count++;
                }
                read[0] = write_read / 1000; //�x�s�Ĥ@���
                read[1] = (write_read/100) % 10; //�x�s�ĤG���
                read[2] = (write_read/10) % 10; //�x�s�ĤT���
                read[3] = write_read % 10; //�x�s�ĥ|���
                for (i=0; i<4; i++){
                    for (j=0; j<i; j++){
                        if (read[j]==read[i]){ //��J�Ʀr����
                            count++;
                        }
                    }
                }
                if (count != 0){
                    printf("INPUT ERROR\n");
                }
            }while (count != 0);
            for (i=0; i<4; i++){ //���Ʀr���T�����p�U
                if (ans[i] == read[i]){ //��m���T
                    A++;
                } else {
                    for (j=0; j<4; j++){
                        if (ans[i] == read[j]){ //��m���~
                            B++;
                        }
                    }
                }
            }
            if (A != 4){
                printf("%dA%dB\n", A, B);
            }else {
                printf("YOU WIN\n");
            }
        }while (A != 4);
        do { //�O�_�A���@��
            count = 0;
            printf("Play again?(Y/N)");
            scanf("%*c%c", &play_again);
            if (play_again != 'Y' && play_again != 'y' && play_again != 'N' && play_again != 'n'){
                count ++;
            }
        }while (count != 0);
    }while (play_again == 'y' || play_again=='Y');
    return 0;
}
