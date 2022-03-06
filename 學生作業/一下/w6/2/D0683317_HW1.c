#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum{
	in,										//�����x�s���A�ܼ� 
	f,
	s
}Data;

typedef struct node* NodePtr;
typedef struct node{
	Data datatype;
	int num1;
    float num2;
    char num3[16];
	NodePtr NextPtr;
}Node;

void AddNode(NodePtr* ptr, char datatype[10]){
	
	NodePtr newptr = (Node*)malloc(sizeof(Node));
	newptr->NextPtr = NULL;
	
	printf("��J���:  ");	
	if(strcmp(datatype, "i") == 0){			//�P�_����x�s���A 
		scanf("%d", &newptr->num1);
		newptr->datatype = in;				
	}
	if(strcmp(datatype, "f") == 0){
		scanf("%f", &newptr->num2);
		newptr->datatype = f;	
	}
	if(strcmp(datatype, "s") == 0){
		scanf("%s", &newptr->num3);
		newptr->datatype = s;
	}
	
	if(*ptr == NULL){
		*ptr = newptr;
	}else{
		NodePtr tempPtr = *ptr;				//HeadPtr
		while(tempPtr->NextPtr != NULL)		//find lastNode
			tempPtr = tempPtr->NextPtr;
		
		tempPtr->NextPtr = newptr;
	}
}

void Print(NodePtr ptr){
	
	printf("******\n");
	while(ptr != NULL){
		if(ptr->datatype == in){			//�P�_�Ӧ�m����ƫ��A�æL�X 
			printf("%d\n", ptr->num1);
		}
		if(ptr->datatype == f){
			printf("%f\n", ptr->num2);
		}
		if(ptr->datatype == s){
			printf("%s\n", ptr->num3);
		}
		ptr = ptr->NextPtr;
	}
	printf("******\n");
}

void Free(NodePtr ptr){
	while(ptr != NULL){
		NodePtr temp = ptr;
		ptr = ptr->NextPtr;
		free(temp);
	}
}

int main(){
	NodePtr headptr = NULL;
	int user_input, end = 0;
	char datatype[10];
	
	do{
		user_input = 5;								//��user_input����P�_��J���~ 
		printf("���: (1.�s�W/2.�L�X/0.����) : ");
		scanf("%d", &user_input);
		getchar();
		

		switch(user_input){
			case 1:
				printf("��ܸ��: (i : int/f : float/s : char[16]) : ");
				scanf("%s", &datatype);
				
				if(strcmp(datatype, "i") != 0 && strcmp(datatype, "f") != 0 && strcmp(datatype, "s") != 0){			//���ѿ��~���O 
					printf("��ܿ��~\n");
					break;
				}
				AddNode(&headptr, datatype);
				break;
			case 2:
				Print(headptr);
				break;
			case 0:
				printf("�����{��\n");
				Free(headptr);
				end = 1;
				break;
			default:
				printf("��ܿ��~\n");
				break;
		}
	}while(!end);
	
	return 0;
}
