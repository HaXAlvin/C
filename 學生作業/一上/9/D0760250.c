#include <stdio.h>
#include <stdlib.h>

void EditNewChar(char char_name[][21],char type[],int hp[],int atk[],int def[]){
    int repeat_value;//�j��P�_
    while(1){
        repeat_value=0;
        printf("\n�s�W����(�ݩ��`�M=65~70)\n�W��:");
        scanf("%s%*c",&char_name[3]);
        printf("�ݩ�(F/W/G/A):");
        scanf("%c",&type[3]);
        //�p�G�O�p�g�A�h�ഫ���j�g
        if((type[3]=='f')||(type[3]=='w')||(type[3]=='g')||(type[3]=='a'))
            type[3]=type[3]-32;
        printf("��J��q(40~50):");
        scanf("%d",&hp[3]);
        printf("��J����(15~20):");
        scanf("%d",&atk[3]);
        printf("��J���m(5~10):");
        scanf("%d",&def[3]);
        //�p�G�ݩʤ�����FWGA�A�hrepeat_value=1�A�~�򭫽ƿ�J������
        if((type[3]!='F')&&(type[3]!='W')&&(type[3]!='G')&&(type[3]!='A')){
            printf("���~:�L���ݩ�\n");
            repeat_value=1;
        }
        //�P�_��O�ƭȬO�_�b����d�򤺡A�p�G���_�A�hrepeat_value=1�A�~�򭫽ƿ�J������
        if(!(atk[3]>=15&&atk[3]<=20)||!(hp[3]>=40&&hp[3]<=50)||!(def[3]>=5&&def[3]<=10)||
           !(atk[3]+hp[3]+def[3]>=65&&atk[3]+hp[3]+def[3]<=70)){
            printf("���~:��O�ƭȦb����d�򤧥~\n");
            repeat_value=1;
        }
        //�p�G�e�ⶵif���󳣬����A�h�L�X�ۭq����
        if(repeat_value==0){
            printf("\n����4\n�W��:%s\n�ݩ�\:%c     ����\:%d\n��q\:%d    ���m\:%d\n����j�׹w��:%.2f\n\n"
                   ,char_name[3],type[3],atk[3],hp[3],def[3],(hp[3]*1.0+atk[3]*0.8+def[3]*0.5-50)*6.5);
            break;
        }
    }
}
void PrintCharData(char char_name[][21],char type[],int hp[],int atk[],int def[]){
    int temp;
    if(hp[3]!=0)//�p�G����4�s�b�A�htemp=4�A�U����for�|�L�X4�Ө���
        temp=4;
    else
        temp=3;//�p�G����4���s�b�A�htemp=3�A�U����for�|�L�X3�Ө���
        for(int n1=0;n1<temp;n1++){
            printf("\n����%d\n�W��:%s\n�ݩ�\:%c     ����\:%d\n��q\:%d    ���m\:%d\n����j�׹w��:%.2f\n\n"
                   ,n1+1,char_name[n1],type[n1],atk[n1],hp[n1],def[n1],(hp[n1]*1.0+atk[n1]*0.8+def[n1]*0.5-50)*6.5);
        }
}
void SelectAndBattle(char type[],int hp[],int atk[],int def[],int sel_char[]){
    int temp;
    int s1,s2;//�԰��ɡA������=sel_char[s1]�A���u��=sel_char[s2]
    char Phases[4][4]={"WFA","GWF","AGW","FAG"};//�۫g��A�Ĥ@�C"WFA"�N��:F�QW�g�AF�gA
    printf("\n");
    do{
        temp=0;//�p�G������𨤦��J���T�A�htemp�̵M��0�A�M����X�j��
        printf("��ܥ��𨤦�:");
        scanf("%d",&sel_char[0]);
        if(sel_char[0]<1||(sel_char[0]>3&&hp[3]==0)||(sel_char[0]>4&&hp[3]!=0)){
            printf("���~:�L������\n");
            temp=1;
        }
    }while(temp==1);
    while(1){
        printf("��ܫ�𨤦�:");
        scanf("%d",&sel_char[1]);
        if(sel_char[1]<1||(sel_char[1]>3&&hp[3]==0)||(sel_char[1]>4&&hp[3]!=0))
            printf("���~:�L������\n");
        //�]�����𨤦⥲�s�b�A�ҥH"�L������"���i��P"���i���ƿ��"�P�ɵo�͡A�]���o��ӱ��󤣥ΦU�O��if�P�_
        else if(sel_char[1]==sel_char[0])
            printf("���~:���i���ƿ��\n");
        else{
            printf("\n���𨤦⬰%d�B��𨤦⬰%d\n�԰��}�l\n\n",sel_char[0],sel_char[1]);
            break;//��J���T�A���X�j��
        }
    }
    /*sel_data[2][6]:������(�Ĥ@�C):hp�Batk�Bdef�B�۫g���v�B�ݦ孿�v�B�U�Ӧ^�X�ˮ`
                     �����(�ĤG�C):hp�Batk�Bdef�B�۫g���v�B�ݦ孿�v�B�U�Ӧ^�X�ˮ`*/
    double sel_data[2][6]={{hp[sel_char[0]-1],atk[sel_char[0]-1],def[sel_char[0]-1],1,1,0},
                           {hp[sel_char[1]-1],atk[sel_char[1]-1],def[sel_char[1]-1],1,1,0}};

    //�ˬd���L�۫g�A���qPhases�}�C(�۫g��)���ĤG��������ݩʡA�����ˬd�o�@�C���Ĥ@���M�ĤT���ݩʬO�_������ݩ�
    for(int n1=0;n1<4;n1++){
        if(type[sel_char[0]-1]==Phases[n1][1]){//������ݩ�
            //�p�G�o�C���ĤT���ݩ�=����ݩʡA�h�N�����g���A����۫g���v=1.2�A���۫g���v=0.8
            if(Phases[n1][2]==type[sel_char[1]-1]){
                sel_data[0][3]=1.2;
                sel_data[1][3]=0.8;
                break;
            }
            //�p�G�o�C���Ĥ@���ݩ�=����ݩʡA�h�N����g����
            else if(Phases[n1][0]==type[sel_char[1]-1]){
                sel_data[0][3]=0.8;
                sel_data[1][3]=1.2;
                break;
            }
        }
    }
    Battling(sel_char,sel_data,hp);//�I�s�԰��禡
}
void Battling(int sel_char[],double sel_data[2][6],int hp[]){
    int temp,s1,s2;
    //�԰��ɡA������=sel_char[s1]�A���u��=sel_char[s2]
    s1=0;
    s2=1;
    while(sel_data[0][0]>0&&sel_data[1][0]>0){//�P�_�����q�A�ӨM�w�O�_�~��j��
        //�]�w�ۤv������=(int)(�ۤv�������O * �۫g���v * �ݦ孿�v - �Q�����訾�m�O)
        sel_data[0][5]=(int)(sel_data[0][1]*sel_data[0][3]*sel_data[0][4]-sel_data[1][2]);//�]�w�������
        sel_data[1][5]=(int)(sel_data[1][1]*sel_data[1][3]*sel_data[1][4]-sel_data[0][2]);//�]�w������
        //������"sel_char[s1]"����
        sel_data[s2][0]=sel_data[s2][0]-sel_data[s1][5];//���u��hp=���u��hp-������atk
        printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n����%d HP: %d ����%d HP: %d\n\n"
               ,sel_char[s1],sel_char[s2],(int)sel_data[s1][5],sel_char[0],(int)sel_data[0][0],sel_char[1],(int)sel_data[1][0]);
        //�ݦ孿�v�ˬd
        if(hp[sel_char[0]-1]>2*sel_data[0][0])//�����q�p��쥻��50%�ɴݦ孿�v��1.2��
            sel_data[0][4]=1.2;
        if(hp[sel_char[1]-1]>2*sel_data[1][0])//����q�p��쥻��50%
            sel_data[1][4]=1.2;
        //��u�洫
        temp=s1;
        s1=s2;
        s2=temp;
    }
    //�P�_��Ĺ�a
    if(sel_data[0][0]<=0)//�ˬd�����q
        printf("����%d ���h�԰���O\n�԰�����\n\n����%d ���\n\n",sel_char[0],sel_char[1]);
    else
        printf("����%d ���h�԰���O\n�԰�����\n\n����%d ���\n\n",sel_char[1],sel_char[0]);
}
int main(){
    int user_in,sel_char[2];//�ѥ��ܥk��:case��ܤ���J�B����𨤦�
    char char_name[4][21]={"SKY","SUN","DUST"};//����W��
    char type[4]="WWA";//�����ݩ�
    int hp[4]={50,45,40};
    int atk[4]={15,20,20};
    int def[4]={5,5,10};

    while(1){
        printf("1. �s�W�έק�s�W����\n"
               "2. ��ܩҦ�������\n"
               "3. �԰�\n"
               "0. �����C��\n"
               "�п��:");
        scanf("%d",&user_in);
        if(user_in==0){//case0:����
            printf("\n�����C��\n");
            break;
        }
        else if(user_in==1){//case1:�s�W����
            EditNewChar(char_name,type,hp,atk,def);
        }
        else if(user_in==2){//case2:�C�X������
            PrintCharData(char_name,type,hp,atk,def);
        }
        else if(user_in==3){//case3:�԰�
            SelectAndBattle(type,hp,atk,def,sel_char);
        }
        else//case��ܿ�J���~�A���ƿ�Jcase��ܤ���J
            printf("\n��J���~!\n\n");
    }
}




