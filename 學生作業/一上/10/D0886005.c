#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
char ans;
void start(char temp[],int val[]){ //計算的函式
    int A=0,B=0,cot=0;
    for(int i=0;i<4;i++){
        temp[i]=temp[i]-48;
        for(int k=0;k<4;k++){  //找出是幾A幾B
            if(temp[i]==val[k]&&i==k){
               A=A+1;
            }
            else if(temp[i]==val[k]){
                B=B+1;
            }
        }
    }
    if(A==4){ //若全對
        printf("YOU WIN\n");
        A=0;
        while(cot==0){
            printf("Play Again?(Y/N)");
            getchar();
            scanf("%c",&ans);
            if(ans=='N'){
                cot=1;

            }
            else if(ans=='Y'){
                cot=1;
            }
            else{
                cot=0;
            }
        }
        return  ;

    }
    else{
       printf("%dA%dB\n",A,B); //印出結果
       A=0;
       B=0;
    }
    return;
}

int main(){
    int num,a,val[4];
    int count=0,cot=0;
    char r[100];
    int len ;
    srand(time(NULL)); //亂數產生
    while(cot==0){
        do{
            for(int i=0;i<4;i++){
                num=rand()%10;
                val[i]=num ;
            }
        }while(val[0]==val[1]||val[0]==val[2]||val[0]==val[3]||val[1]==val[2]||val[1]==val[3]||val[2]==val[1]||val[2]==val[3]);
        //產生不相等的亂數
        for(int i=0;i<4;i++){
            printf("%d",val[i]);
        }
        puts("");
        count=0;
        while(count==0){
            printf(">> ");
            scanf("%s",r);
            len=strlen(r); //計算長度
            if(len==4){
                if(r[0]==r[1]||r[0]==r[2]||r[0]==r[3]||r[1]==r[2]||r[1]==r[3]||r[2]==r[3]){
                    printf("INPUT ERROR\n");
                }
                else {
                    start(r,val);
                    if (ans=='N'){
                        return 0;
                    }
                    else if(ans=='Y'){
                        count=1;
                        cot=0;
                    }
                }
            }
            else{
                printf("INPUT ERROR\n");
            }
        }
    }
    return 0;
}


