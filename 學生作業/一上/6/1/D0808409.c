#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>
#include<stdbool.h>
int chara_Total=3;
//����1
char char1_name[] = "Momi";
char char1_type = 'W';
int char1_hp = 45;
int char1_atk = 15;
int char1_def = 7;
//����2
char char2_name[] = "Kirito";
char char2_type = 'F';
int char2_hp = 44;
int char2_atk = 16;
int char2_def = 8;
//����3
char char3_name[] = "Miku";
char char3_type = 'G';
int char3_hp = 43;
int char3_atk = 17;
int char3_def = 9;
//����4
char char4_name[] = "�ۭq����";
char char4_type = 'G';
int char4_hp = 46;
int char4_atk = 17;
int char4_def = 9;

int main(){

    //��J��X
    Print(1,char1_name,char1_type,char1_hp,char1_atk,char1_def);
    puts("");//����
    Print(2,char2_name,char2_type,char2_hp,char2_atk,char2_def);
    puts("");
    Print(3,char3_name,char3_type,char3_hp,char3_atk,char3_def);
    puts("");
    printf("�O�_�s�W����(1.Yes/2.No)?");
    int YN;//�s�xyes or no
    scanf("%d",&YN);
    while(RanInt(YN,1,2)==1)//���J���ȶW�L�d��A�O�ϥΪ̭��s��J
    {
        printf("��J���~\n");
        printf("�O�_�s�W����(1.Yes/2.No)?");
        scanf("%d",&YN);
    }
    bool Error404=false;//�Τ@��bool�ӧP�_�ϥΪ̬O�_��J���~
    if(YN==1)
    {
        do
        {
            Error404=false;//�C����J���~�A�^��o�̮ɡA�O�䬰���A�M�᭫�s�P�_
            getchar();
            printf("\n�s�W����\n");
            printf("�ݩʡG");
            scanf("%c",&char4_type);
            printf("��q�G");
            scanf("%d",&char4_hp);
            printf("�����G");
            scanf("%d",&char4_atk);
            printf("���m�G");
            scanf("%d",&char4_def);
            int Total  = char4_hp + char4_atk + char4_def;
            switch(char4_type){//�ݩʦr���P�_
                case 'F':
                    break;
                case 'W':
                    break;
                case 'G':
                    break;
                case 'A':
                    break;
                case 'f':
                    break;
                case 'w':
                    break;
                case 'g':
                    break;
                case 'a':
                    break;
                default:
                    printf("���~�G�L���ݩ�\n");
                    Error404=true;//����~�ɡA�O404���u�A��while��@��
                    break;
            }
            if(RanInt(char4_hp,40,50)==1)
            {
                printf("���~�G��O�ƭȦb����d�򤧥~\n");
                Error404=true;
            }
            else if(RanInt(char4_atk,15,20)==1)
            {
                printf("���~�G��O�ƭȦb����d�򤧥~\n");
                Error404=true;
            }
            else if(RanInt(char4_def,5,10)==1)
            {
                printf("���~�G��O�ƭȦb����d�򤧥~\n");
                Error404=true;
            }
            else if(RanInt(Total,65,70)==1){
                printf("���~�G��O�ƭȦb����d�򤧥~\n");
                Error404=true;
            }
        }while(Error404==true);
        puts("");
        Print(4,char4_name,char4_type,char4_hp,char4_atk,char4_def);
        puts("");
        chara_Total++;//�����`�ơA�W�L�����O���~��J
    }
    int AtkChara1;//�s�ϥΪ̿�J����𨤦��
    int AtkChara2;
    do
    {
        Error404=false;
        printf("��ܥ��𨤦�G");
        scanf("%d",&AtkChara1);
        if(RanInt(AtkChara1,1,chara_Total)==1)
        {
            printf("���~�G�L������\n");
            Error404=true;//��W���@�˥Ϊk
        }
    }while(Error404==true);
    do
    {
        Error404=false;
        printf("��ܫ�𨤦�G");
        scanf("%d",&AtkChara2);
        if(RanInt(AtkChara2,1,chara_Total)==1)
        {
            printf("���~�G�L������\n");
            Error404=true;
        }
        else if(AtkChara1 == AtkChara2)
        {
            printf("���~�G���i���ƿ��\n");
            Error404=true;
        }
    }while(Error404==true);
    Error404=false;
    printf("\n���𬰨���%d�B��𬰨���%d",AtkChara1,AtkChara2);
    Fight(AtkChara1,AtkChara2);//�԰����:�b�̭��i��԰������B���X
    return 0;
}
//�ۻs�U�ο�X���P
int Print(int Count,char name[] ,int type,int hp,int atk,int def)
{
    printf("����%d\n�W�١G%s\n�ݩʡG%c     �����G%d\n��q�G%d    ���m�G%d\n",Count,name,type,atk,hp,def);
    float Power  = ( hp * 1.0 + atk * 0.8 + def * 0.5 - 50 ) * 6.5;
    printf("����j�׹w���G%.2f\n",Power);
    return 0;
}
int RanInt(int num,int min,int max)//����Ʀr�b���w�d��
{
    if(num < min || num > max)
        return 1;
    else
        return 0;
}
int Fight(int Chara1,int Chara2)
{
    int Hp1,Hp2,Atk1,Atk2,Def1,Def2;
    printf("\n�԰��}�l\n");
    switch(Chara1)
    {
        case 1:
            Hp1 = char1_hp;
            Atk1 = char1_atk;
            Def1 = char1_def;
            break;
        case 2:
            Hp1 = char2_hp;
            Atk1 = char2_atk;
            Def1 = char2_def;
            break;
        case 3:
            Hp1 = char3_hp;
            Atk1 = char3_atk;
            Def1 = char3_def;
            break;
        case 4:
            Hp1 = char4_hp;
            Atk1 = char4_atk;
            Def1 = char4_def;
            break;
    }
    switch(Chara2)
    {
        case 1:
            Hp2 = char1_hp;
            Atk2 = char1_atk;
            Def2 = char1_def;
            break;
        case 2:
            Hp2 = char2_hp;
            Atk2 = char2_atk;
            Def2 = char2_def;
            break;
        case 3:
            Hp2 = char3_hp;
            Atk2 = char3_atk;
            Def2 = char3_def;
            break;
        case 4:
            Hp2 = char4_hp;
            Atk2 = char4_atk;
            Def2 = char4_def;
            break;
    }
    int AtkPower ;
    bool swi=false;//�洫������
    do{
        if(swi==false)//
        {
            AtkPower = Atk1 - Def2;
            Hp2-=AtkPower;
            printf("\n����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n����%d  HP: %d  ����%d HP: %d\n",Chara1,Chara2,AtkPower,Chara1,Hp1,Chara2,Hp2);
            swi=true;//�����h��������1�i��A�åB�������������u
        }
        else
        {
            AtkPower = Atk2 - Def1;
            Hp1-=AtkPower;
            printf("\n����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n����%d  HP: %d  ����%d HP: %d\n",Chara2,Chara1,AtkPower,Chara1,Hp1,Chara2,Hp2);
            swi=false;//���u�h��������2�i��A�åB��������������
        }

      }while(Hp1>0 && Hp2>0);

    if(Hp1<=0)
    {
        printf("\n����%d ���h�԰���O",Chara1);
        printf("\n�԰�����\n");
        printf("\n����%d ���\n",Chara1);//�԰���������X�H�ΧP�w�Ӫ�
    }
    else if(Hp2<=0)
    {
        printf("\n����%d ���h�԰���O",Chara2);
        printf("\n�԰�����\n");
        printf("\n����%d ���\n",Chara2);//�԰���������X�H�ΧP�w�Ӫ�
    }


}

