#include<stdio.h>
#include<stdlib.h>
char char_type[4] = "GAW";
int char_hp[4] = {50,40,44,0};
int char_atk[4] = {15,20,17,0};
int char_def[4] = {5,8,8,0};
char char_name[4][20] = {"Aibo", "���D�B", "�����l"};
//flag��
int is_error=0;
int is_error1=0;
int is_error2=0;
int is_creat=0;//����4�O�_�s�b
int select;
int player1=0;
int player2=0;

void EditNewChar()
{
    is_error = 0;   //�Nflag�k�^0
    is_error1 = 0;
    printf("\n�s�W����\n");
    printf("�W��:");
    scanf("%s",char_name[3]);
    getchar();
    printf("�ݩ�:");
    scanf("%c",&char_type[3]);

    printf("��q:");
    scanf("%d",&char_hp[3]);

    printf("����:");
    scanf("%d",&char_atk[3]);

    printf("���m:");
    scanf("%d",&char_def[3]);
    getchar();
    //�ƭȭ���
    if(char_type[3] != 'F' && char_type[3] != 'W' && char_type[3] != 'G' && char_type[3] != 'A' &&
        char_type[3] != 'f' && char_type[3] != 'w' && char_type[3] != 'g' && char_type[3] != 'a')
    {
        printf("���~:�L���ݩ�\n"),is_error=1;
    }
    //�N�ݩʤp�g�ন�j�g
    else if(char_type[3] == 'f')
        char_type[3] = 'F';
    else if(char_type[3] == 'w')
        char_type[3] = 'W';
    else if(char_type[3] == 'g')
        char_type[3] = 'G';
    else if(char_type[3] == 'a')
        char_type[3] = 'A';
    if(char_hp[3] >50 || char_hp[3] <40 ||
        char_atk[3] >20 || char_atk[3] <15 ||
        char_def[3] >10 ||  char_def[3] <5 ||
        (char_hp[3] + char_atk[3]  + char_def[3]) >70 || (char_hp[3] + char_atk[3]  + char_def[3]) <65)
    {
        printf("���~:��O�ƭȦb����d�򤧥~\n");
        is_error1=1;
    }

}
void PrintCharData(char name[],int hp,int atk,int def,char type)
{
    printf("\n�W��:%s\n",name);
    printf("�ݩ�:%c     ����:%d\n", type, atk);
    printf("��q:%d    ���m:%d\n", hp, def);
    printf("����j�׹w���G%.2f\n",
   (hp * 1.0 + atk * 0.8 + def * 0.5 - 50.0) * 6.5 );
   return;
}
void SelectAndBattle()
{
    while(1)    //���ƨ����J���j��
    {
        while(1)
        {
            is_error2=0;
            printf("\n��ܥ��𨤦�:");
            scanf("%d",&player1);
            if(player1 < 1 || player1 > 3 + is_creat) //����4�O�_�s�b��flag
            {
                printf("���~:�L������\n");
                is_error2=1;
            }
            if(is_error2==0)
            {
                break;
            }
        }
        while(1)
        {
            is_error2=0;
            printf("��ܫ�𨤦�:");
            scanf("%d",&player2);
            if(player2 < 1 || player2 > 3 + is_creat)
            {
                printf("���~:�L������\n");
                is_error2=1;
            }
            if(is_error2==0)
            {
                break;
            }
        }

        is_error2=0;
        if(player1 == player2)
        {
            printf("���~:���⭫�ƿ�J\n",is_error2=1);
        }
        if(is_error2 == 0)
        {
            break;
        }

    }
    printf("\n���𬰨���%d�B��𬰨���%d\n",player1,player2);
    printf("�԰��}�l\n\n");
    int first_hp,first_def;
    int later_hp,later_def;
    double first_atk,later_atk;
    char first_type,later_type;
    //����
    if(player1==1)
    {
        first_hp=char_hp[0];
        first_atk=char_atk[0];
        first_def=char_def[0];
        first_type=char_type[0];
    }
    else if(player1==2)
    {
        first_hp=char_hp[1];
        first_atk=char_atk[1];
        first_def=char_def[1];
        first_type=char_type[1];
    }
    else if(player1==3)
    {
        first_hp=char_hp[2];
        first_atk=char_atk[2];
        first_def=char_def[2];
        first_type=char_type[2];
    }
    else if(player1==4)
    {
        first_hp=char_hp[3];
        first_atk=char_atk[3];
        first_def=char_def[3];
        first_type=char_type[3];
    }
    //���
    if(player2==1)
    {
        later_hp=char_hp[0];
        later_atk=char_atk[0];
        later_def=char_def[0];
        later_type=char_type[0];
    }
    else if(player2==2)
    {
        later_hp=char_hp[1];
        later_atk=char_atk[1];
        later_def=char_def[1];
        later_type=char_type[1];
    }
    else if(player2==3)
    {
        later_hp=char_hp[2];
        later_atk=char_atk[2];
        later_def=char_def[2];
        later_type=char_type[2];
    }
    else if(player2==4)
    {
        later_hp=char_hp[3];
        later_atk=char_atk[3];
        later_def=char_def[3];
        later_type=char_type[3];
    }
    //�ݩʬ۫g
    if(first_type=='F'&&later_type=='A')
    {
        first_atk*=1.2;
        later_atk*=0.8;
    }
    else if(first_type=='A'&&later_type=='F')
    {
        first_atk*=0.8;
        later_atk*=1.2;
    }
    else if(first_type=='A'&&later_type=='G')
    {
        first_atk*=1.2;
        later_atk*=0.8;
    }
    else if(first_type=='G'&&later_type=='A')
    {
        first_atk*=0.8;
        later_atk*=1.2;
    }
    else if(first_type=='G'&&later_type=='W')
    {
        first_atk*=1.2;
        later_atk*=0.8;
    }
    else if(first_type=='W'&&later_type=='G')
    {
        first_atk*=0.8;
        later_atk*=1.2;
    }
    else if(first_type=='W'&&later_type=='F')
    {
        first_atk*=1.2;
        later_atk*=0.8;
    }
    else if(first_type=='F'&&later_type=='W')
    {
        first_atk*=0.8;
        later_atk*=1.2;
    }
    int damage,damage2;
    int turn = 1;
    int first_atk_origin_hp = first_hp; //������l��q
    int later_atk_origin_hp = later_hp;
    int first_is_hp50=0; //�ݦ孿�vflag
    int later_is_hp50=0;
    void Battling()
    {   while(1)
        {
            while(first_hp > 0 && later_hp > 0)
            {
                if(first_hp<=first_atk_origin_hp/2 && first_is_hp50==0) //�ݦ孿�v
                {
                    first_atk*=1.2;
                    first_is_hp50=1;
                }
                if(later_hp<=later_atk_origin_hp/2 && later_is_hp50==0)
                {
                    later_atk*=1.2;
                    later_is_hp50=1;
                }
                int atk;
                if(turn == 1)
                {
                    atk =(int)first_atk - later_def;
                    later_hp -= atk;
                    printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", player1, player2, atk);
                    turn = 2; //�洫������
                }
                else
                {
                    atk =(int)later_atk - first_def;
                    first_hp -= atk;
                    printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", player2, player1, atk);
                    turn = 1; //�洫������
                }
                printf("����%d HP: %d  ����%d HP: %d\n\n", player1, first_hp, player2, later_hp);
            }
            printf("����%d ���h�԰���O\n", (first_hp > 0) ? player1 : player2);
            printf("�԰�����\n\n");
            printf("����%d ���\n\n", (first_hp > 0) ? player1 : player2);
            break;
        }
    }
    Battling();
}
int main()
{
    while(1){
        while(1){
            is_error=0;
            printf("1. �s�W�ηs�W�ק�s�W����\n");
            printf("2. ��ܩҦ�������\n");
            printf("3. �԰�\n");
            printf("0. �����C��\n");
            printf("�п��:");
            scanf("%d",&select);
            if(select == 0)
            {
                printf("\n�����C��\n");
                return 0;
            }
            if(select != 1 && select != 2 && select != 3)
            {
                printf("\n��J���~!\n\n");
                is_error=1;
            }
            if(is_error == 0)
            {
                break;
            }
        }
        if(select == 1) //�s�W����έק�
        {
            while(1)            //�]�m��J���~���j��
            {
                EditNewChar();
                //��J���~���s��J��flag
                if(is_error==0 && is_error1==0)
                    break;
            }
            PrintCharData(char_name[3],char_hp[3],char_atk[3],char_def[3],char_type[3]);
            is_creat=1;
        }
        else if(select == 2)
        {
            for(int i = 0; i < 3 + is_creat ; i++)
            {
                printf("\n����%d", i + 1);
                PrintCharData(char_name[i],char_hp[i],char_atk[i],char_def[i],char_type[i]);
            }
            printf("\n");
        }
        else if(select == 3) //�԰�
        {
            SelectAndBattle();
        }
    }
}







