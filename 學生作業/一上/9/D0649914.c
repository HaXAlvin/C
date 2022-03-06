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
role npc[100]={{"�P�z��y",'W',50,15,5},               //�H����O�ȳ]�w ���W��npc 
	          {"���O���z",'A',40,20,8},
	          {"�Q����",'G',40,20,10}};
int num=3,first_atk,after_atk;                           //�p��H�����X�����ܼ� �x�s����P��𪺶��� 
bool storage[3]={0};                                    //�������L���~�����L��  storage[2]�������S���Q�s�W�L���� 
void npc_call(){										//NPC���I�s 
	int i;
	for(i=0;i<num;i++){                                    //���LNPC���ƭ�   
	    npc[i].prediction=	(npc[i].hp*1.0+npc[i].atk*0.8+npc[i].def*0.5-50)*6.5;							
		printf("����%d\n"
	           "�W��:%s\n"
		       "�ݩ�:%c   ����:%d\n"
		       "��q:%d  ���m:%d\n"
			   "����j�׹w��:%0.2f\n\n",i+1,npc[i].name,npc[i].type,npc[i].atk,npc[i].hp,npc[i].def,npc[i].prediction);
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
void create(){										//�s�W����M�ᤩ��O�� 
	num=3;
	int i=num;
	if(storage[2]==0)                               //�P�_���S���s�W�L���� 
		printf("�s�W����\n");
	else
		printf("�ק�s�W����\n");
	printf("�W��:");
	scanf("%s",&npc[i].name);
	printf("�ݩ�:");
	scanf("%*c%c",&npc[i].type);
	printf("��q:");     	
	scanf("%d",&npc[i].hp);
	printf("����:");  	    
	scanf("%d",&npc[i].atk);
	printf("���m:");        
	scanf("%d",&npc[i].def);
	type_judgement(i);
	ability_judge(i);
	if(storage[0] == true ||storage[1] == true)          //�Q��storage[]�����Ҧ��L���~  ���~�ɦA�I�screate��� 
		create();
	else{
		storage[2]=1; 
		num=4;
	} 
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
	       "�W��:%s\n"
		   "�ݩ�:%c   ����:%d\n"
		   "��q:%d  ���m:%d\n"
		   "����j�׹w��:%0.2f\n\n",i+1,npc[i].name,npc[i].type,npc[i].atk,npc[i].hp,npc[i].def,npc[i].prediction);
}
void pvp(int first_atk,int after_atk,int hp_1,int hp_2,char type_1,char type_2){               //��D pvp���I�s 
	printf("�԰��}�l\n");
	int damage,status=0;                                                        				//�x�s�ˮ`���ܼ� 
	if((type_1 =='W' && type_2 == 'F'))          				//�p�Gstatus�ܬ�1��2���� �N���⦳�Q�۫g 
		status=1;
	else if((type_1 == 'F' && type_2 == 'W'))
		status=2;
	else if((type_1 =='F' && type_2 == 'A'))
		status=1;
	else if((type_1 == 'A' && type_2 == 'F'))
		status=2;
	else if((type_1 =='A' && type_2 == 'G'))
		status=1;
	else if((type_1 == 'G' && type_2 == 'A'))
		status=2;
	else if((type_1 =='G' && type_2 == 'W'))
		status=1;
	else if((type_1 == 'W' && type_2 == 'G'))
		status=2;
	while(hp_1 > 0){                                                   //�p�G���𪺦�q�S���j��0�� ���X�j��
		if(status == 1){
			damage=npc[first_atk-1].atk*1.2-npc[after_atk-1].def;
			if(hp_1 < npc[first_atk-1].hp/2){
				damage=npc[first_atk-1].atk*1.2*1.2-npc[after_atk-1].def;
			}
		}
		else if(status ==2){
			damage=npc[first_atk-1].atk*0.8-npc[after_atk-1].def;
			if(hp_1 < npc[first_atk-1].hp/2){
				damage=npc[first_atk-1].atk*0.8*1.2-npc[after_atk-1].def;
			}
		}
		else{
			damage=npc[first_atk-1].atk-npc[after_atk-1].def;
			if(hp_1 < npc[first_atk-1].hp/2){
				damage=npc[first_atk-1].atk*1.2-npc[after_atk-1].def;
			}
		}
		hp_2-=damage;
		printf("\n����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n"
			   "����%d HP: %d  ����%d HP: %d\n",first_atk,after_atk,damage,first_atk,hp_1,after_atk,hp_2);
		if(hp_2 < 0)                                                   //�p�G��𪺦�q�p��0 �Nbreak 
			break;
		if(status == 1){
			damage=npc[after_atk-1].atk*0.8-npc[first_atk-1].def;
			if(hp_2 < npc[after_atk-1].hp/2){
				damage=npc[after_atk-1].atk*0.8*1.2-npc[first_atk-1].def;
			}
		}
		else if(status == 2){
			damage=npc[after_atk-1].atk*1.2-npc[first_atk-1].def;
			if(hp_2 < npc[after_atk-1].hp/2){
				damage=npc[after_atk-1].atk*1.2*1.2-npc[first_atk-1].def;
			}
		}
		else{
			damage=npc[after_atk-1].atk-npc[first_atk-1].def;
			if(hp_2 < npc[after_atk-1].hp/2){
				damage=npc[after_atk-1].atk*1.2-npc[first_atk-1].def;
			}
		}		
		hp_1-=damage;
		printf("\n����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n"
			   "����%d HP: %d  ����%d HP: %d\n",after_atk,first_atk,damage,first_atk,hp_1,after_atk,hp_2);
	}
	if(hp_1 < 0){
		printf("\n����%d ���h�԰���O\n"
			   "�԰�����\n"
			   "\n����%d���\n\n",first_atk,after_atk);
	}
	else{
		printf("\n����%d ���h�԰���O\n"
			   "�԰�����\n"
			   "\n����%d���\n\n",after_atk,first_atk);
	}
}
int main(){
	int number;
	do{
		printf("1. �s�W�έק�s�W����\n"
			   "2. ��ܩҦ�������\n"
   			   "3. �԰�\n"
   			   "0. �����C��\n"
			   "�п��:");
		scanf("%d",&number);
		printf("\n");
		switch(number){
			case 1:
				create();																										//����s�W���I�s 
				create_call(num-1);																								//����s�W����ܯ�O���I�s 
				break;
			case 2:
				npc_call();																										 //��ܨ����ƪ��I�s 
				break;
			case 3:
				choice_atk_role();																								  //��ܥ���Ϋ�𪺩I�s	
				pvp(first_atk,after_atk,npc[first_atk-1].hp,npc[after_atk-1].hp,npc[first_atk-1].type,npc[after_atk-1].type);     //pvp��D�Ҧ����I�s
				break;
			case 0:
				break;
			default:
				printf("��J���~!\n\n"); 
		}
	}while(number!=0);                                                             //�p�G�O0���� ���Xwhile �����C�� 
	printf("�����C��\n");                                              
	 
	return 0;
} 
