#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>

void random_roll(int random[]);             //生成隨機數;
void get_ans(int input[]);                  //取得輸入數;
int checking(int input[], int length);      //確認輸入數是否合法;
int how_many_A_B(int ans[], int your[]);    //輸出結果;
int continue_to_play(int play);             //是否繼續遊玩;

int main()
{
    while (1)                               //這個迴圈包括隨機數生成的部分，每一次迴圈都是一輪新的遊戲;
    {
        int true_ans[4] = { 0 };
        int your_ans[500] = { 0 };
        int result = 0;
        int again = 0;

        random_roll(true_ans);
        while (1)                           //迴圈內部流程包括使用者輸入到顯示結果，直到Win才會break或直接結束程式;
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
        for (int j = 0; j < i; j++)         //確認隨機數是否有重複，若i位數與(0~i)位數重複，則重新生成i位數;
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
        char temp[500];                                         //宣告大空間以防止使用者輸入過多、造成溢位;
        int a = 0;
        int check;
        printf(">> ");
        while (scanf("%c", &temp[a]) && temp[a] != '\n')        //這邊用char來讀使用者輸入才能讀到換行，同時把char內的數字減去0的ASCII Code，存回int陣列中;
        {
            input[a] = temp[a] - 48;
            a++;
        }
        check = checking(input,a);                              //判斷輸入是否合法;
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
        for (int i = 0; i < 4; i++)                             //判斷重複，每一位數都會和其他數比較
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

int how_many_A_B(int ans[], int your[])                         //先判斷位置對、數字也對的有幾個，再判斷數字對但位置錯的
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