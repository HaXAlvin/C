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
role npc[]={{"�P�z��y",'F',50,10,5},               //�H����O�ȳ]�w ���W��npc
	        {"���O���z",'W',45,15,7},
	        {"�Q����",'G',40,20,10}};
int num=4;                                          //�p��H�����X�����ܼ�
bool storage[2];                                    //�������L���~�����L��
void npc_call(){										//NPC���I�s
	int i;
	for(i=0;i<3;i++){
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
	sum=npc[i].hp+npc[i].atk+npc[i].def;
	if(sum<65 || sum>70){
        storage[1]=1;
        printf("���~:��O�ƭȦb����d�򤧥~\n");
    }
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
	num+=1;
}
void choice_atk_role(){                                 //��ܨ������A���
	int role,repeat;
	printf("\n��ܥ��𨤦�:");
	scanf("%d",&role);
	repeat=role;
	if(role>0 && role<num){
		printf("��ܫ�𨤦�:");
		scanf("%d",&role);
		if(role>0 && role<num && role!=repeat)
			printf("\n���𨤦⬰:%d�B��𨤦⬰:%d\n",repeat,role);
		else if(role<=0 || role>=num)
			printf("���~:�L������\n");
		else
			printf("���~:���i���ƿ��\n");
	}
	else
		printf("���~:�L������\n");
}
void create_call(int i){                                //�s�W���⪺�I�s
    npc[i].prediction=	(npc[i].hp*1.0+npc[i].atk*0.8+npc[i].def*0.5-50)*6.5;
	printf("\n����%d\n"
	       "�W��:�ۭq����\n"
		   "�ݩ�:%c   ����:%d\n"
		   "��q:%d  ���m:%d\n"
		   "�j�׹w��:%0.2f\n",i,npc[i].type,npc[i].atk,npc[i].hp,npc[i].def,npc[i].prediction);
}
int main(){
	int whether;
    npc_call();                                         //npc�I�s
    printf("�O�_�s�W����(1.YES/2.NO)? ");
    scanf("%d",&whether);
	if(whether==1){
		create();                                           //�Хߪ�����إ�
        if(storage[0]==false && storage[1]==false){
            create_call(num-1);                                 //�Хߪ�����I�s
            printf("\n");
            choice_atk_role();                                  //��ܨ������A��𪺩I�s
        }
	}
    else if(whether==2)										//��ܨ������A��𪺩I�s
    	choice_atk_role();
	else
        printf("��J���~\n");

	return 0;
}
