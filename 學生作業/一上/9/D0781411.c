#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void EditNewChar (char name[200][200],char char_type[],int char_hp[],int char_atk[],int char_def[])//�ﶵ1  �s�W/�s�W�ק﨤��
{
	int sum=0;//����,���m,��q �`�M
	int max_char=3;//�����
	float char_power[10]={0};//����j��
	int i;
	if(char_hp[3]!=0)//�P�_���S������4
	{
		max_char=4;
	}
	if(max_char==3)   //�S������4
    {
    	printf("\n�s�W����\n");
	}
	if(max_char==4)	  //�ק﨤��
	{
		printf("\n�ק�s�W����\n");
	}
	printf("����W��:");   //�q�o�̶}�l�O�s���⪺ ��O��/ID  ��
    gets(name[3]);
    printf("�����ݩ� (F,W,G,A):");
    scanf ("%c%*c",&char_type[3]);
    char_type[3]=toupper(char_type[3]);//�p�g��j�g
    printf("��q(40-50):");
    scanf ("%d",&char_hp[3]);
    printf("����(15-20):");
    scanf ("%d",&char_atk[3]);
    printf("���m(5-10):");
    scanf ("%d%*c",&char_def[3]);
    sum=char_hp[3]+char_atk[3]+char_def[3];
	while(char_type[3]!='F'&&char_type[3]!='W'&&char_type[3]!='G'&&char_type[3]!='A'||char_atk[3]>20||char_atk[3]<15||char_hp[3]>50||char_hp[3]<40||char_def[3]<5||char_def[3]>10||sum>70||sum<65)
	{
		if(char_type[3]!='F'&&char_type[3]!='W'&&char_type[3]!='G'&&char_type[3]!='A')
	    {
	    	printf("���~:�L���ݩ�\n\n");
	    }
	    if(char_atk[3]>20||char_atk[3]<15||char_hp[3]>50||char_hp[3]<40||char_def[3]<5||char_def[3]>10||sum>70||sum<65)
	    {
	        printf("���~:��O�ƭȦb����d�򤧥~\n\n");
	    }
	    printf("����W��:");
		gets(name[3]);
		printf("�����ݩ�:");
		scanf ("%c",&char_type[3]);
		char_type[3]=toupper(char_type[3]);//�p�g��j�g
		printf("��q(40-50):");
		scanf ("%d",&char_hp[3]);
		printf("����(15-20):");
		scanf ("%d",&char_atk[3]);
		printf("���m(5-10):");
		scanf ("%d",&char_def[3]);
	}
	printf("\n");
	char_power [3] = (char_hp[3]*1.0+char_atk[3]*0.8+char_def[3]*0.5-50)*6.5;
	for(i=3;i<=3;i++)
	{
	   	printf("����%d\n",i+1);
	    printf("�W��:%s\n",name[i]);
	   	printf("�ݩ�:%c    ����:%d\n",char_type[i],char_atk[i]);
		printf("��q:%d   ���m:%d\n",char_hp[i],char_def[i]);
	    printf("����j��:%.2f\n\n",char_power[i]);
	}
}


void PrintCharData(char name[200][200],char char_type[],int char_hp[],int char_atk[],int char_def[])//�ﶵ2 ��X�F��
{
    int i=0;//�j��Ϊ�
    int max_char;//���h�֨���
	max_char=3;
    double char_power[5]={0}; //����j��
	if(char_atk[3]!=0)
	{
		max_char=4;
	}
    for(i=0;i<max_char;i++)
    {
    	char_power [i] = (char_hp[i]*1.0+char_atk[i]*0.8+char_def[i]*0.5-50)*6.5;
    }
	printf("\n");
	for(i=0;i<max_char;i++)
	{
	    printf("����%d\n",i+1);
	    printf("�W��:%s\n",name[i]);
	 	printf("�ݩ�:%c    ����:%d\n",char_type[i],char_atk[i]);
	 	printf("��q:%d   ���m:%d\n",char_hp[i],char_def[i]);
	    printf("����j��:%.2f\n\n",char_power[i]);
	}
}

void Battling(int attack_first,int attack_second,double attack_data[2][6],int char_hp[])//�԰�
{
	int attack_char[2]={attack_first,attack_second};
	int change;
	int a1;
	int a2;
    //�԰� ~  �C�����@����@�^�X �C�^�X�������H�u���@��
    a1=0;
    a2=1;
    while(attack_data[0][0]>0&&attack_data[1][0]>0)//�P�_�����q�A�ӨM�w�O�_�~��j��
	{
        attack_data[0][5]=(int)(attack_data[0][1]*attack_data[0][3]*attack_data[0][4]-attack_data[1][2]);//�]�w�������
        attack_data[1][5]=(int)(attack_data[1][1]*attack_data[1][3]*attack_data[1][4]-attack_data[0][2]);//�]�w������
        attack_data[a2][0]=attack_data[a2][0]-attack_data[a1][5];//���u��hp=���u��hp-������atk
        printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n����%d HP: %d \n����%d HP: %d\n\n",attack_char[a1],attack_char[a2],(int)attack_data[a1][5],attack_first,(int)attack_data[0][0],attack_second,(int)attack_data[1][0]);
        //�ݦ孿�v�ˬd
        if(char_hp[attack_first-1]/2>attack_data[0][0])//�����q�p��쥻��50%�ɴݦ孿�v��1.2��
        {
            attack_data[1][4]=1.2;
            //printf("�����z~\n\n");
        }
        if(char_hp[attack_second-1]/2>attack_data[1][0])//����q�p��쥻��50%
        {
            attack_data[0][4]=1.2;
            //printf("����z~\n\n");
        }
        //��u�洫
        change=a1;
        a1=a2;
        a2=change;
    }

    if(attack_data[1][0]<=0)
    {
        printf("����%d ���h�԰���O\n",attack_second);
        printf("�԰�����\n\n");
        printf("����%d ���\n\n",attack_first);
    }

    else
    {
        printf("����%d ���h�԰���O\n",attack_first);
        printf("�԰�����\n\n");
        printf("����%d ���\n\n",attack_second);
    }
}

void SelectAndBattle(char char_type[],int char_hp[],int char_atk[],int char_def[],int attack_first,int attack_second)//�﨤
{
	double attack_first_count=1;
	double attack_second_count=1;
	int attack_second_weak=1;
	int attack_first_weak=1;
	char counter_type[4] ={'W','F','A','G'};//�@W>F>A>G>W
	int type_control;
	int max_char;
	int first_char_hurt;
	int second_char_hurt;
	max_char=3;
	if(char_atk[3]!=0)
	{
		max_char=4;
	}
	printf("\n��J���𨤦�:");  //�o�̶}�l�﨤��
    scanf("%d",&attack_first);
    while (attack_first>max_char||attack_first<1) //����u��1~max_char ����d��  1<=����<=max_char
    {
        printf("���~:�L������\n");
        printf("������𨤦�:");
        scanf("%d",&attack_first);
    }
    if(attack_first<=max_char||attack_first>=1)
    {
        printf("��J��𨤦�:");
        scanf("%d",&attack_second);
        while(attack_first==attack_second||attack_second>max_char||attack_second<1)//����u��1~max_char ����d��  1<=����<=max_char
        {
            if(attack_first==attack_second)
            {
               printf("���~:���i���ƿ��\n");
            }
            if(attack_second>max_char||attack_second<1)
            {
                printf("���~:�L������\n");
            }
            printf("��J��𨤦�:");
            scanf("%d", &attack_second);
        }
    }
	// ���𨤦��O��
    int attack_first_atk=char_atk[attack_first-1];
    int attack_first_hp=char_hp[attack_first-1];
    int attack_first_def=char_def[attack_first-1];
    int attack_first_type=char_type[attack_first-1];
    int attack_first_weak_hp=attack_first_hp/2;
	//��𨤦��O��
    int attack_second_atk=char_atk[attack_second-1];
    int attack_second_hp=char_hp[attack_second-1];
    int attack_second_def=char_def[attack_second-1];
    int attack_second_type=char_type[attack_second-1];
	int attack_second_weak_hp=attack_second_hp/2;
	// ��O��(�۫g)
    if(attack_first_type=='W')
    {
       	type_control=0;
	}
	if(attack_first_type=='F')
    {
   		type_control=1;
	}
	if(attack_first_type=='A')
    {
       	type_control=2;
	}
	if(attack_first_type=='G')
    {
       	type_control=3;
	}
	if(counter_type[(type_control+1)%4]==attack_second_type) //����J����   �O�o���v���m
	{
		attack_first_count=1.2;
		//printf("����J����\n");
	}
	if(counter_type[(type_control+3)%4]==attack_second_type) //���J�����
	{
		attack_first_count=0.8;
		//printf("���J�����\n");
	}
	attack_second_count=2-attack_first_count; //���v�ۥ[��2
	//printf("�ڬO���𪺱d�S���v: %f\n",attack_first_count);
	//printf("�ڬO��𪺱d�S���v: %f\n",attack_second_count);
	//�԰����`

	first_char_hurt=attack_second_atk*(attack_second_count*attack_second_weak)-attack_first_def;//���𨤦� ���쪺�ˮ`   �o�̤����`  �ڤ��Odebug�Ϊ�
	second_char_hurt=attack_first_atk*(attack_first_count*attack_first_weak)-attack_second_def;//��𨤦� ���쪺�ˮ`   �ڤ��Odebug�Ϊ�
	// �H�U�O�����ƾ�//
	//attack_data[2][6]:������(�Ĥ@�C):hp�Batk�Bdef�B���𨤥���𨤪��۫g���v�B���𨤥���𨤪��ݦ孿�v�B���𨤤U�Ӧ^�X����ˮ`
    //                  �����(�ĤG�C):hp�Batk�Bdef�B��𨤥����𨤪��۫g���v�B��𨤥����𨤪��ݦ孿�v�B��𨤤U�Ӧ^�X����ˮ`
	double attack_data[2][6]={{attack_first_hp,attack_first_atk,attack_first_def,attack_first_count,1,first_char_hurt},
                              {attack_second_hp,attack_second_atk,attack_second_def,attack_second_count,1,second_char_hurt}};
    //�﨤����
    printf("\n���𨤦⬰%d,��𨤦⬰%d\n",attack_first,attack_second);
    printf("�԰��}�l\n\n");
    Battling(attack_first, attack_second, attack_data, char_hp);
}


int main()//�D�{��
{
    //���� ��O / �m�W
    int game_type=1;
    int attack_first;
    int attack_second;
    char name[200][200] ={"����","����","�߫}"};
    char char_type [5] = {'F','W','G',' '};
    char counter_type[4] ={'W','F','A','G'};//�@W>F>A>G>W
    int char_hp [5] = {40,50,45,0};
    int char_atk [5] = {20,15,15,0};
    int char_def [5] = {10,5,10,0};
	//�i�J�C��
	while(game_type!=0)
	{
        printf("1. �s�W�έק﨤��\n");
		printf("2. ��ܩҦ�������\n");
		printf("3. �԰�\n");
		printf("0. �����C��\n");
		printf("�п��:");
        scanf("%d%*c",&game_type);
        if(game_type==1) //�s�W�έק﨤��
		{
            EditNewChar(name,char_type,char_hp,char_atk,char_def);
        }
        else if(game_type==2) //��X����
		{
            PrintCharData(name,char_type,char_hp,char_atk,char_def);
        }
        else if(game_type==3) //�԰�
		{
            SelectAndBattle(char_type,char_hp,char_atk,char_def,attack_first,attack_second);
        }
        else if(game_type!=0)//�ﶵ��L
		{
           printf("\n��J���~!\n");
    	}
	}
	printf("\n�����C��\n");
}

















