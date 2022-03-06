#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdlib.h>

int main()
{
    while(1)
    {
        int Ran[4]={0};
        int input[4]={0};
        char inputStr[4]={0};
        srand(time(NULL));
        do
        {
            for(int i=0;i<4;i++)
            {
                Ran[i] = rand()%10;//隨機數字出來並分配到陣列上
            }
        }while(Ran[0]==Ran[1]||Ran[0]==Ran[2]||Ran[0]==Ran[3]||
               Ran[1]==Ran[0]||Ran[1]==Ran[2]||Ran[1]==Ran[3]||
               Ran[2]==Ran[0]||Ran[2]==Ran[1]||Ran[2]==Ran[3]||
               Ran[3]==Ran[0]||Ran[3]==Ran[1]||Ran[3]==Ran[2]);//窮舉法 當數字重複時 重新生成隨機數
        for(int i=0;i<4;i++){
            printf("%d",Ran[i]);
        }
        puts("");
        while(1)
        {
            int A=0,B=0;
            int Num;
            printf(">> ");
            scanf("%s",&inputStr);
            if(strlen(inputStr)!=4)//用字串來判定 輸入數字的多寡
            {
                printf("INPUT ERROR\n");
                continue;
            }
            for(int i=0;i<4;i++)
            {
                input[i]= inputStr[i]-'0';
            }
            if(input[0]==input[1]||input[0]==input[2]||input[0]==input[3]||
               input[1]==input[0]||input[1]==input[2]||input[1]==input[3]||
               input[2]==input[0]||input[2]==input[1]||input[2]==input[3]||
               input[3]==input[0]||input[3]==input[1]||input[3]==input[2])//窮舉法 同上
            {
                printf("INPUT ERROR\n");
                continue;
            }
            for(int i=0;i<4;i++)
            {
                if(input[i]==Ran[i])
                {
                    A++;//判斷有幾個A
                }
                else
                {
                    for(int j=0;j<4;j++)//0 1 2 3
                    {
                        if(input[i]==Ran[j])
                        {
                            B++;//判斷有幾個B
                        }
                    }
                }
            }

            if(A>=4)
            {
                printf("YOU WIN\n");
                break;//A>=4全對就跳出迴圈
            }
            else if(A==0&&B==0)
            {

            }
            else{
                printf("%dA%dB\n",A,B);//輸出AB

            }
        }
        int k=0;
        while(1){//判斷是否重新遊玩
            printf("Play Again?(Y/N)");
            char YN=0;
            scanf("%c%*c",&YN);
            if(YN=='N')
            {
                return 0;
            }
            else if(YN=='Y')
            {
                break;
            }
        }
    }

}
