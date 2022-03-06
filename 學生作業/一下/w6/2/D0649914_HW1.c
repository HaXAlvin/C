#include<stdio.h>
#include<stdlib.h>
typedef struct node *NodePtr;					//�ŧi���c���� 
typedef struct node{							//�ŧi���c�ëŧi���� 
	char c;
	union{
		int num1;
		float num2;
		char str[16];	
	};
	NodePtr nextPtr;
}Node;
int create(NodePtr *ptr){						//�s�W����� 
	NodePtr newPtr=malloc(sizeof(Node));		 
	newPtr->nextPtr=NULL;						//�W�[�s���쵲���媺�����ó]�w��NULL 
	printf("������� : (i : int/f :float/s : char[16]) :");
	scanf("%c%*c",&newPtr->c);					//�x�s�쵲���s�W���쵲����ҭn�x�s�����A 
	if(newPtr->c=='i'||newPtr->c=='f'||newPtr->c=='s')		
		printf("��J��� : ");
		
	if(newPtr->c=='i'){							//�̫��A�i�Jif�� �i���ƿ�J �p��J���~�^��-1�_�h��0 
		scanf("%d",&newPtr->num1);
	}
	else if(newPtr->c=='f'){
		scanf("%f",&newPtr->num2);
	}
	else if(newPtr->c=='s'){
		scanf("%s",&newPtr->str);
	}
	else{
		printf("��J���~!\n");
		return -1; 
	}
	
	if(*ptr==NULL)							//�p�G�W�znum���O-1���� �|�Ө�o�� �o�̧P�_���ڲ{�b��ptr���x�s���O���ONULL�p�G�O�N���V�L 
		*ptr=newPtr;						//�_�h�i�Jelse���V�U�@�Ӧb�P�_�O�_��NULL 
	else{
		NodePtr tempPtr=*ptr;
		while(tempPtr->nextPtr !=NULL)
			tempPtr=tempPtr->nextPtr;
		tempPtr->nextPtr = newPtr;
	}
	return 0;								//���\�Nreturn 0 
}
void print(NodePtr node){
	while(node){							//�L�X�C���� 
		if(node->c=='i')					//�̧ǧP�_�����򫬺A�æL�X 
			printf("%d\n",node->num1);
		else if(node->c=='f')
			printf("%f\n",node->num2);
		else if(node->c=='s')
			printf("%s\n",node->str);
		
		node=node->nextPtr;					//�L�X����N���@�� 
	}
}
void freeList(NodePtr *ptr){				//free�Ŷ������ 
	while(*ptr!=NULL){
		NodePtr tempPtr=*ptr;				//�ŧi�@�ӼȦsptr�����c���Шë��Vptr 
		*ptr = (*ptr)->nextPtr;				//�Ȧs��N�i���ܲ{���q��ptr���V���a�� ����ptr���V���a�謰NULL�~�������j�� 
		if(tempPtr->c=='i')					//�i�ݥX�{�b���nfree���ӪŶ����P�_ 
			printf("delete %d\n",tempPtr->num1);
		else if(tempPtr->c=='f')
			printf("delete %f\n",tempPtr->num2);
		else if(tempPtr->c=='s')
			printf("delete %s\n",tempPtr->str);
		
		free(tempPtr);						//�@�Ӥ@��free�Ŷ�����ptr�����VNULL���a�� 
	}
}
int main(){
	NodePtr head=NULL;										//�ŧi�쵲���媺�}�Y 
	int user,num;
	do{
		printf("��� : (1.�s�W/2.�L�X/0.����) :");
		scanf("%d%*c",&user);
		switch(user){
			case 1:
				num=-1;
				while(num==-1){								//��O-1���ɭ� �N���J���~�N���s�i�J�j��@~~~ 
					num=create(&head);						//�s�W����� 
				}	
				break;
			case 2:
				print(head);								//�L�X����� 
				break;
			case 0:
				freeList(&head);							//�����{�� ���Kfree 
				printf("�����{��\n");
				break;
			default:
				printf("��J���~!\n");
				break; 
		} 
	}while(user!=0);
}
