#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>

void random_roll(int random[]);             //�ͦ��H����;
void get_ans(int input[]);                  //���o��J��;
int checking(int input[], int length);      //�T�{��J�ƬO�_�X�k;
int how_many_A_B(int ans[], int your[]);    //��X���G;
int continue_to_play(int play);             //�O�_�~��C��;

int main()
{
    while (1)                               //�o�Ӱj��]�A�H���ƥͦ��������A�C�@���j�鳣�O�@���s���C��;
    {
        int true_ans[4] = { 0 };
        int your_ans[500] = { 0 };
        int result = 0;
        int again = 0;

        random_roll(true_ans);
        while (1)                           //�j�餺���y�{�]�A�ϥΪ̿�J����ܵ��G�A����Win�~�|break�Ϊ��������{��;
        {
            get_ans(your_ans);
            result = how_many_A_B(true_ans, your_ans);
            if(result)
            {
                again = continue_to_play(again);
                if (again)
                    break;
                else
                    return 0;
            }
        }
    }
}

void random_roll(int random[])
{
    srand(time(NULL));
    for (int i = 0; i < 4; i++)
    {
        random[i] = rand() % 10;
        for (int j = 0; j < i; j++)         //�T�{�H���ƬO�_�����ơA�Yi��ƻP(0~i)��ƭ��ơA�h���s�ͦ�i���;
        {
            if (random[i] == random[j])
            {
                i = i - 1;
                break;
            }
        }
    }
}

void get_ans(int input[])
{
    while (1)
    {
        char temp[500];                                         //�ŧi�j�Ŷ��H����ϥΪ̿�J�L�h�B�y������;
        int a = 0;
        int check;
        printf(">> ");
        while (scanf("%c", &temp[a]) && temp[a] != '\n')        //�o���char��Ū�ϥΪ̿�J�~��Ū�촫��A�P�ɧ�char�����Ʀr��h0��ASCII Code�A�s�^int�}�C��;
        {
            input[a] = temp[a] - 48;
            a++;
        }
        check = checking(input,a);                              //�P�_��J�O�_�X�k;
        if (check)
            continue;
        else
            break;
    }
}

int checking(int input[], int length)
{
    if (length != 4)
    {
        printf("INPUT ERROR\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < 4; i++)                             //�P�_���ơA�C�@��Ƴ��|�M��L�Ƥ��
        {
            for (int j = 3; j >i; j--)
            {
                if (input[i] == input[j])
                {
                    printf("INPUT ERROR\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}

int how_many_A_B(int ans[], int your[])                         //���P�_��m��B�Ʀr�]�諸���X�ӡA�A�P�_�Ʀr�����m����
{
    int a = 0;
    int b = 0;
    for (int i = 0; i < 4; i++)
    {
        if (ans[i] == your[i])
            a++;
        for (int j = 0; j < 4; j++)
        {
            if (ans[i] == your[j] && i != j)
                b++;
        }
    }
    if (a == 4)
    {
        printf("YOU WIN\n");
        return 1;
    }
    else
        printf("%dA%dB\n", a, b);
    return 0;
}

int continue_to_play(int play)
{
    while(1)
    {
        char reply;
        printf("Play again?(Y/N)");
        scanf("%c", &reply);
        getchar();
        if (islower(reply))
            reply = toupper(reply);
        if (reply != 'Y'&&reply != 'N')
            continue;
        else if (reply == 'Y')
            return 1;
        else if (reply == 'N')
            return 0;
    }
}