#include<stdio.h>
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
void create(){											//�s�W����M�ᤩ��O�� 
	int i=num;
	printf("�s�W����:\n");	
	printf("�ݩ�:");	 	
	scanf(" %c",&npc[i].type);
	printf("��q:");     	
	scanf("%d",&npc[i].hp);
	printf("����:");  	    
	scanf("%d",&npc[i].atk);
	printf("���m:");        
	scanf("%d",&npc[i].def);
	num+=1;
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
    npc_call();                                         //npc�I�s 
	create();                                           //�Хߪ�����إ� 
	create_call(4);                                     //�Хߪ�����I�s 
	return 0;
} 
