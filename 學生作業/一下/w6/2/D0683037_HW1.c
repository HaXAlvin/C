#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int value;
	float num;
	char abc[16];
	char type;
	struct node *nextptr;
}Node;

int main()  {
	Node *headptr=NULL,*temptr=NULL,*leftptr=NULL;
	int choose;
	while(1){
		//////�\���� //////
		printf("���:(1.�s�W/2.�L�X/0.����): ");
		scanf("%d",&choose);

		if(choose==1){

			//�s�W�`�Iand�N���Ы��V�U�@�Ӹ`�I�ðt�m�Ŷ�
			if(headptr==NULL){
                headptr = (struct node*)malloc(sizeof(Node));
                temptr = headptr;
			}
			else{
				temptr->nextptr = (struct node*)malloc(sizeof(Node));
				temptr = temptr->nextptr ;
			}

			//�s�W��ƫ��A���
			while(1){
				printf("�������:(i:int/f:float/s:char[16]): ");
				scanf("%s",&temptr->type);
				if(temptr->type=='i'){
					scanf("%d",&temptr->value);
					temptr->nextptr = NULL;
					break;
				}

				else if(temptr->type=='f'){
					scanf("%f",&temptr->num );
					temptr->nextptr = NULL;
					break;
				}

				else if(temptr->type=='s'){
					scanf("%s",&temptr->abc);
					temptr->nextptr = NULL;
					break;
				}
				else{
					printf("��J���~!\n");
				}
			}


		}

		//�L�X��C���
		else if(choose==2){
			temptr = headptr;
			while(temptr!=NULL){
				if(temptr->type=='i'){
					printf("%d\n",temptr->value);
				}
				if(temptr->type=='f'){
					printf("%f\n",temptr->num);
				}
				if(temptr->type=='s'){
					printf("%s\n",temptr->abc);
				}
				leftptr=temptr;
				temptr = temptr->nextptr;
			}
			temptr = leftptr;
	 	}

		//����������O����Ŷ�
		else if(choose==0){
			temptr = headptr;
			while(temptr!=NULL){

				if(temptr->type=='i'){
					//printf("����%d�O����\n",temptr->value);
					free(temptr);
				}
				else if(temptr->type=='f'){
					//printf("����%f�O����\n",temptr->num);
					free(temptr);
				}
				else if(temptr->type=='s'){
					//printf("����%s�O����\n",temptr->abc);
					free(temptr);
				}
				temptr = temptr->nextptr;
			}
			printf("�����{��");
			break;
		}

		//���X�k�\����
		else{
			printf("��J���~!\n");
		}

	}

	return 0;
}
