#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char userinput(char num[]) {
    int i,j,flag=0;
    while(55) {
        printf(">>");
        flag =0;
        scanf("%s",num);
        int len = strlen(num);
        if(len>4||len<4) {
            printf("INPUT ERROR\n");
            continue;
        }
        for(i=len-1; i>=0&&flag==0; i--) {
            for(j=i-1; j>=0; j--) {
                if(num[i]==num[j]) {
                    printf("INPUT ERROR\n");
                    flag = 1;
                }
            }
        }
        if(flag == 0){
            for(i=0;i<4;i++)
            {
                num[i]-=48;
            }
            return num;
        }
        else if(flag == 1)
            continue;
    }
}
char ramdom(char ans[]) {
    int i,j,flag=0;
    while(5) {
        flag =0;
        srand(time(NULL));
        for(i=0; i<4; i++) {
            ans[i] = rand()%10;
        }
        for(i=3; i>=0&&flag==0; i--) {
            for(j=i-1; j>=0; j--) {
                if(ans[i]==ans[j]) {
                    flag = 1;
                }
            }
        }
        if(flag == 0)
            return ans;
        else if(flag == 1)
            continue;
    }
}
int main() {
    char num[100]= {0,0,0,0,0};
    int i,j;
    char ans[4]= {0,0,0,0};
    char yn;
    int user_input;
    do {
        ramdom(ans);
        do {
            userinput(num);
            int acount=0,bcount=0;
            for(i=0; i<=3; i++) {
                for(j=0; j<=3; j++) {
                    if(num[i]==ans[j]&&i==j)
                        acount++;
                    else if(num[i]==ans[j]&&i!=j)
                        bcount++;
                }
            }
            printf("%dA%dB\n",acount,bcount);
        } while(strcmp(num,ans)!=0);
        printf("YOU WIN\n");
        printf("Play Again?(Y/N)");
        scanf(" %c",&yn);
    } while(yn=='Y'||yn=='y');
    return 0;
}






