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
                Ran[i] = rand()%10;//�H���Ʀr�X�Өä��t��}�C�W
            }
        }while(Ran[0]==Ran[1]||Ran[0]==Ran[2]||Ran[0]==Ran[3]||
               Ran[1]==Ran[0]||Ran[1]==Ran[2]||Ran[1]==Ran[3]||
               Ran[2]==Ran[0]||Ran[2]==Ran[1]||Ran[2]==Ran[3]||
               Ran[3]==Ran[0]||Ran[3]==Ran[1]||Ran[3]==Ran[2]);//�a�|�k ��Ʀr���Ʈ� ���s�ͦ��H����
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
            if(strlen(inputStr)!=4)//�Φr��ӧP�w ��J�Ʀr���h��
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
               input[3]==input[0]||input[3]==input[1]||input[3]==input[2])//�a�|�k �P�W
            {
                printf("INPUT ERROR\n");
                continue;
            }
            for(int i=0;i<4;i++)
            {
                if(input[i]==Ran[i])
                {
                    A++;//�P�_���X��A
                }
                else
                {
                    for(int j=0;j<4;j++)//0 1 2 3
                    {
                        if(input[i]==Ran[j])
                        {
                            B++;//�P�_���X��B
                        }
                    }
                }
            }

            if(A>=4)
            {
                printf("YOU WIN\n");
                break;//A>=4����N���X�j��
            }
            else if(A==0&&B==0)
            {

            }
            else{
                printf("%dA%dB\n",A,B);//��XAB

            }
        }
        int k=0;
        while(1){//�P�_�O�_���s�C��
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
