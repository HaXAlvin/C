#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdbool.h>
#include <ctype.h>
int chara_Total=3;
char char1_name[21]="Momi";
char char2_name[21]="Kirito";
char char3_name[21]="Miku";
char char4_name[21]={0};
char type[4]={0}; //�ݩ�
int hp[4]={0};  //��q
int atk[4]={0};  //����
int def[4]={0};  //���m
/*
EditNewChar()
PrintCharData()
SelectAndBattle()
Battling()
Battling()����SelectAndBattle()�I�s*/
//�ۻs�U�ο�X���P
int PrintCharData(int Count,char name[] ,int type,int hp,int atk,int def)
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
int Battling(int Chara1,int Chara2)
{
    int  Hp1,Hp2,Atk1,Atk2,Def1,Def2;
    char type1,type2;
    printf("\n�԰��}�l\n");
    type1 =toupper(type[Chara1-1]);
    Hp1 = hp[Chara1-1];
    Atk1 = atk[Chara1-1];
    Def1 = def[Chara1-1];
    type2 =toupper(type[Chara2-1]);
    Hp2 = hp[Chara2-1];
    Atk2 = atk[Chara2-1];
    Def2 = def[Chara2-1];
    int AtkPower ;
    int Blood50_1=Hp1/2;//�Ѿl
    int Blood50_2=Hp2/2;//�Ѿl
    bool swi=false;//�洫������
    do{
        float Phase=1;
        float MinBlood=1;
        if(swi==false)//
        {//W>F>A>G>W �����ˮ` = (int)(����������O * �۫g���v * �ݦ孿�v - �Q�����訾�m�O)
        //�۫g���Y�G�u�ժ�1.2���A�H�ժ�0.8��
        //�������q�p��쥻��50%�ɴݦ孿�v��1.2��
            if(type1 =='W'&&type2=='F')
                Phase =1.2;
            else if(type1=='F'&&type2=='A')
                Phase =1.2;
            else if(type1=='A'&&type2=='G')
                Phase =1.2;
            else if(type1=='G'&&type2=='W')
                Phase =1.2;
            else if(type1=='F'&&type2=='W')
                Phase =0.8;
            else if(type1=='G'&&type2=='A')
                Phase =0.8;
            else if(type1=='A'&&type2=='F')
                Phase =0.8;
            else if(type1=='W'&&type2=='G')
                Phase =0.8;
            if(Hp1<Blood50_1)
                MinBlood=1.2;
            AtkPower =(int)(Atk1*Phase*MinBlood - Def2) ;
            Hp2-=AtkPower;
            printf("\n����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n����%d  HP: %d  ����%d HP: %d\n",Chara1,Chara2,AtkPower,Chara1,Hp1,Chara2,Hp2);
            swi=true;//�����h��������1�i��A�åB�������������u
        }
        else
        {
            if(type1 =='W'&&type2=='F')
                Phase =0.8;
            else if(type1=='F'&&type2=='A')
                Phase =0.8;
            else if(type1=='A'&&type2=='G')
                Phase =0.8;
            else if(type1=='G'&&type2=='W')
                Phase =0.8;
            else if(type1=='F'&&type2=='W')
                Phase =1.2;
            else if(type1=='G'&&type2=='A')
                Phase =1.2;
            else if(type1=='A'&&type2=='F')
                Phase =1.2;
            else if(type1=='W'&&type2=='G')
                Phase =1.2;
            float MinBlood=1;
            if(Hp2<Blood50_2)
                MinBlood=1.2;
            AtkPower =(int)(Atk2*Phase*MinBlood - Def1) ;
            Hp1-=AtkPower;
            printf("\n����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n����%d  HP: %d  ����%d HP: %d\n",Chara2,Chara1,AtkPower,Chara1,Hp1,Chara2,Hp2);
            swi=false;//���u�h��������2�i��A�åB��������������
        }

    }while(Hp1>0 && Hp2>0);

    if(Hp1<=0)
    {
        printf("\n����%d ���h�԰���O",Chara1);
        printf("\n�԰�����\n");
        printf("\n����%d ���\n\n",Chara2);//�԰���������X�H�ΧP�w�Ӫ�
    }
    else if(Hp2<=0)
    {
        printf("\n����%d ���h�԰���O",Chara2);
        printf("\n�԰�����\n");
        printf("\n����%d ���\n\n",Chara1);//�԰���������X�H�ΧP�w�Ӫ�
    }
}
void EditNewChar()
{
    bool Error404;
    do
    {
        Error404=false;//�C����J���~�A�^��o�̮ɡA�O�䬰���A�M�᭫�s�P�_
        if(chara_Total==3)
            printf("\n�s�W����\n");
        else
            printf("\n�ק�s�W����\n");
        printf("�W�١G");
        scanf("%s%*c",&char4_name);
        printf("�ݩʡG");
        scanf("%c%*c",&type[3]);
        printf("��q�G");
        scanf("%d%*c",&hp[3]);
        printf("�����G");
        scanf("%d%*c",&atk[3]);
        printf("���m�G");
        scanf("%d%*c",&def[3]);
        int Total  = hp[3] + atk[3] + def[3];
        switch(type[3]){//�ݩʦr���P�_
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
        if(RanInt(hp[3],40,50)==1)
        {
            printf("���~�G��O�ƭȦb����d�򤧥~\n");
            Error404=true;
        }
        else if(RanInt(atk[3],15,20)==1)
        {
            printf("���~�G��O�ƭȦb����d�򤧥~\n");
            Error404=true;
        }
        else if(RanInt(def[3],5,10)==1)
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
    PrintCharData(4,char4_name,toupper(type[3]),hp[3],atk[3],def[3]);
    puts("");
    chara_Total=4;//�����`�ơA�W�L�����O���~��J
}
void SelectAndBattle()
{
    bool Error404=false;
    puts("");
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
    Battling(AtkChara1,AtkChara2);//�԰����:�b�̭��i��԰������B���X
}
int main(){
    type[0]='W';
    type[1]='A';
    type[2]='F';
    hp[0]=50;
    hp[1]=40;
    hp[2]=45;
    atk[0]=15;
    atk[1]=20;
    atk[2]=17;
    def[0]=5;
    def[1]=8;
    def[2]=7;
    while(1)
    {
        int choose;
        bool Error404=false;//�Τ@��bool�ӧP�_�ϥΪ̬O�_��J���~
        puts("1. �s�W�έק�s�W����");
        puts("2. ��ܩҦ�������");
        puts("3. �԰�");
        puts("0. �����C��");
        printf("�п�ܡG");
        scanf("%d",&choose);
       // puts("");
        if(choose==0)
        {
            printf("\n�����C��\n");
            return 0;
        }
        else if(choose==1)
        {
            EditNewChar();
        }
        else if(choose==2)
        {
            puts("");
            PrintCharData(1,char1_name,toupper(type[0]),hp[0],atk[0],def[0]);
            puts("");
            PrintCharData(2,char1_name,toupper(type[1]),hp[1],atk[1],def[1]);
            puts("");
            PrintCharData(3,char1_name,toupper(type[2]),hp[2],atk[2],def[2]);
            puts("");
            if(chara_Total>3)
            {
                PrintCharData(4,char4_name,toupper(type[3]),hp[3],atk[3],def[3]);
                puts("");
            }
        }
        else if(choose==3)
        {
            SelectAndBattle();
        }
        else
        {
            puts("\n��J���~!\n");
        }



    }
}


