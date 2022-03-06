#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct{                                         //�H������O�� �إߵ��crole
	char name[100];                                     //�W��
	char type;                                          //�ݩ�
	int hp;                                             //��q
	int atk;                                            //����
	int def;                                            //���m
	float prediction;                                   //�j�׹w��
}role;
role npc[]={{"�P�z��y",'F',48,17,5},               //�H����O�ȳ]�w ���W��npc
	        {"���O���z",'W',45,15,7},
	        {"�Q����",'G',40,20,10}};
int num=3,first_atk,after_atk;                                          //�p��H�����X�����ܼ� �x�s����P��𪺶���
bool storage[2];                                    //�������L���~�����L��
void npc_call(){										//NPC���I�s
	int i;
	for(i=0;i<3;i++){                                    //���LNPC���ƭ�
	    npc[i].prediction=	(npc[i].hp*1.0+npc[i].atk*0.8+npc[i].def*0.5-50)*6.5;
		printf("����%d\n"
	           "�W��:%s\n"
		       "�ݩ�:%c   ����:%d\n"
		       "��q:%d  ���m:%d\n"
			   "�j�׹w��:%0.2f\n\n",i+1,npc[i].name,npc[i].type,npc[i].atk,npc[i].hp,npc[i].def,npc[i].prediction);
	}
}
void type_judgement(int i){                                                                   //�ݩʧP�_
    if(npc[i].type=='f' || npc[i].type=='w' || npc[i].type=='g' ||npc[i].type=='a')          //�p�G�Of,w,g,a���ܡA����F W G A
    npc[i].type=npc[i].type-' ';
    if(npc[i].type=='F' ^ npc[i].type=='W' ^ npc[i].type=='G' ^ npc[i].type=='A')           //�P�_�p�G���Of,w,g,a,F,W,G,A���ܡA��X:���~
    storage[0]=0;
    else{
    storage[0]=1;
    printf("���~:�L���ݩ�\n");
    }
}
void ability_judge(int i){                               //�P�_�s�W����O���O�b��O�Ƚd��H��
	int sum;
	storage[1]=0;
	sum=npc[i].hp+npc[i].atk+npc[i].def;
	if(npc[i].hp <40 || npc[i].hp > 50)                       //���⪺��q�n�b 40~50
		storage[1]=1;
	else if(npc[i].atk < 15 || npc[i].atk > 20)               //���⪺�����n�b 15~20
		storage[1]=1;
	else if(npc[i].def < 5 || npc[i].def > 10)                //���⪺���m�n�b 5~10
		storage[1]=1;
	else if(sum<65 || sum>70)                                 //���⪺��O���`�M�n�b65~70
		storage[1]=1;
	if(storage[1]==true)
    printf("���~:��O�ƭȦb����d�򤧥~\n");
}
void create(){											//�s�W����M�ᤩ��O��
	int i=num;
	printf("\n�s�W����\n");
	printf("�ݩ�:");
	scanf(" %c",&npc[i].type);
	printf("��q:");
	scanf("%d",&npc[i].hp);
	printf("����:");
	scanf("%d",&npc[i].atk);
	printf("���m:");
	scanf("%d",&npc[i].def);
	type_judgement(i);
	ability_judge(i);
	if(storage[0] == true ||storage[1] == true)          //�Q��storage[]�����Ҧ��L���~  ���~�ɦA�I�screate���
	create(i);
	else
	num+=1;
}

void choice_atk_role(){                                 //��ܨ������A���
	printf("��ܥ��𨤦�:");
	scanf("%d",&after_atk);
	first_atk=after_atk;
	if(after_atk > 0 && after_atk <= num){                  //�P�_���𦳵L�W�L�d��
		while(1){
			printf("��ܫ�𨤦�:");
			scanf("%d",&after_atk);
			if(after_atk > 0 && after_atk <= num && after_atk!=first_atk){          //�P�_��𦳵L�W�L�d��
				printf("\n���𨤦⬰%d�B��𨤦⬰%d\n",first_atk,after_atk);
				break;
			}
			else if( after_atk <= 0 || after_atk > num){
				printf("���~:�L������\n");
			}
			else{
				printf("���~:���i���ƿ��\n");
			}
		}
	}
	else{
		printf("���~:�L������\n");
		choice_atk_role();
	}
}
void create_call(int i){                                //�s�W���⪺�I�s
    npc[i].prediction=	(npc[i].hp*1.0+npc[i].atk*0.8+npc[i].def*0.5-50)*6.5;
	printf("\n����%d\n"
	       "�W��:�ۭq����\n"
		   "�ݩ�:%c   ����:%d\n"
		   "��q:%d  ���m:%d\n"
		   "�j�׹w��:%0.2f\n",i+1,npc[i].type,npc[i].atk,npc[i].hp,npc[i].def,npc[i].prediction);
}
void preparation_of_war(){								//�w�ƾ԰������
	int whether;
    npc_call();                                         //npc�I�s
    while(1){
    printf("�O�_�s�W����(1.YES/2.NO)? ");
    scanf("%d",&whether);
	if(whether==1){
		create();                                           //�Хߪ�����إ�
	if(storage[0]==false && storage[1]==false){
		create_call(num-1);                                 //�Хߪ�����I�s
		printf("\n");
		choice_atk_role();                                  //��ܨ������A��𪺩I�s
		break;
		}
	}
    else if(whether==2){									//��ܨ������A��𪺩I�s
    	choice_atk_role();
    	break;
    }
	else
	printf("��J���~\n");
	}
}
void pvp(int first_atk,int after_atk,int hp_1,int hp_2){               //��D pvp���I�s
	printf("�԰��}�l\n");
	int damage;                                                        //�x�s�ˮ`���ܼ�
	while(hp_1 > 0){                                                   //�p�G���𪺦�q�S���j��0�� ���X�j��
		damage=npc[first_atk-1].atk-npc[after_atk-1].def;
		hp_2-=damage;
		printf("\n����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n"
			   "����%d HP: %d  ����%d HP: %d\n",first_atk,after_atk,damage,first_atk,hp_1,after_atk,hp_2);
		if(hp_2 < 0)                                                   //�p�G��𪺦�q�p��0 �Nbreak
			break;
		damage=npc[after_atk-1].atk-npc[first_atk-1].def;
		hp_1-=damage;
		printf("\n����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n"
			   "����%d HP: %d  ����%d HP: %d\n",after_atk,first_atk,damage,first_atk,hp_1,after_atk,hp_2);
	}
	if(hp_1 < 0){
		printf("\n����%d ���h�԰���O\n"
			   "�԰�����\n"
			   "\n����%d���\n",first_atk,after_atk);
	}
	else{
		printf("\n����%d ���h�԰���O\n"
			   "�԰�����\n"
			   "\n����%d���\n",after_atk,first_atk);
	}
}
int main(){
	preparation_of_war();                                                 //pvp���ƫe�ǳƪ��I�s
	pvp(first_atk,after_atk,npc[first_atk-1].hp,npc[after_atk-1].hp);     //pvp��D�Ҧ����I�s
	return 0;
}
