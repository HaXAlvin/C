#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//�ŧi
int answer[4]={-1,-1,-1,-1};//�q���ͦ�����
int output,player_input;//�ͦ����׮ɪ���X,���a��J���ƭ�
int input[4];//���a��J
int playerchoice;//���a�O�_������flag

//�H������0-9�Ʀr���禡
int random(){
    output=rand()%10;
    return output;
}

//�Ͳ��X���ת��禡
void count_answer(){
    for(int i=0;i<=3;i++){
        answer[i]=random();
        //�����
        for(int j=0;j<i;j++){
            if(answer[i]==answer[j]){
                i--;
            }
        }
    }
    for(int i=0;i<4;i++){
            printf("%d",answer[i]);
        }
        puts("");
}

//�T�{���a��J���ƭȬO�_���T���禡
void input_check(){
    while(1){
        int flag_allright=2;
        printf(">> ");
        scanf("%d",&player_input);
        //�P�_���a��J�ȬO�_���|���
        if(player_input>=10000||player_input<=999){
            printf("INPUT ERROR\n");
            continue;
        }
        else
            flag_allright--;
        //�N�ƭȩ�|�ӼƦr
        input[0]=player_input/1000;
        input[1]=(player_input%1000-player_input%100)/100;
        input[2]=(player_input%100-player_input%10)/10;
        input[3]=player_input%10;
        //�P�_�Ʀr�O�_����
        if(input[0]==input[1]||input[0]==input[2]||input[0]==input[3]||input[1]==input[2]||input[1]==input[3]||input[2]==input[3]){
            printf("INPUT ERROR\n");
            continue;
        }
        else
            flag_allright--;
        if(flag_allright==0){
            break;
        }
    }
}

//�C���D�n�XA�XB���B��禡
void game_operation(){
    while(1){
        input_check();//�I�s�ˬd���a��J���禡
        int A=0,B=0;
        //��XA
        for(int i=0;i<=3;i++){
            if(answer[i]==input[i]){
                A++;
            }
        }
        //���ץ��T
        if(A==4){
            printf("YOU WIN\n");
            return;
        }
        //��XB
        for(int i=0;i<=3;i++){
            for(int j=0;j<=3;j++){
                if(answer[i]==input[j]){
                B++;
                }
            }
        }
        B=B-A;
        printf("%dA%dB\n",A,B);
    }
}

//�P�_���a�O�_�������禡
int play_again(){
    char play_or_not;
    while(1){
        printf("Play Again?(Y/N)");
        getchar();
        scanf("%c",&play_or_not);
        if(play_or_not=='Y')
            return 1;
        else if(play_or_not=='N')
            return 0;
    }
}

//�D�禡
int main(){
    srand(time(NULL));//����SEED
    while(1){
        count_answer();
        game_operation();
        playerchoice=play_again();
        if(playerchoice==0)
            return 0;
    }
}
