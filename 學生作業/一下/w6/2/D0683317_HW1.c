#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum{
	in,										//紀錄儲存型態變數 
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
	
	printf("輸入資料:  ");	
	if(strcmp(datatype, "i") == 0){			//判斷資料儲存型態 
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
		if(ptr->datatype == in){			//判斷該位置的資料型態並印出 
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
		user_input = 5;								//讓user_input能夠判斷輸入錯誤 
		printf("選擇: (1.新增/2.印出/0.結束) : ");
		scanf("%d", &user_input);
		getchar();
		

		switch(user_input){
			case 1:
				printf("選擇資料: (i : int/f : float/s : char[16]) : ");
				scanf("%s", &datatype);
				
				if(strcmp(datatype, "i") != 0 && strcmp(datatype, "f") != 0 && strcmp(datatype, "s") != 0){			//辨識錯誤指令 
					printf("選擇錯誤\n");
					break;
				}
				AddNode(&headptr, datatype);
				break;
			case 2:
				Print(headptr);
				break;
			case 0:
				printf("結束程式\n");
				Free(headptr);
				end = 1;
				break;
			default:
				printf("選擇錯誤\n");
				break;
		}
	}while(!end);
	
	return 0;
}
