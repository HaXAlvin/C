#include <stdio.h>
#include <stdlib.h>

typedef union{ //儲存資料的型態 
	int i_data; //整數 
	float f_data; //浮點數 
	char s_data[16]; //字串 
}Type;

typedef struct data* dataPtr;  

typedef struct data{ //存放資料的結構 
	Type type; //資料 
	char choosetype; //資料型態 
	dataPtr nextPtr; //自我參考指標成員 
}Data;

void inputnewdata(Data** Ptr){ //新增資料 
	Data* input = malloc(sizeof(Data)); //暫時存放輸入 
	input->nextPtr = NULL;
	while(1){ //選擇的資料型態超出限制 
		printf("選擇類型：(i：int/f：float/s：char[16])：");
		getchar();
		scanf("%c", &input->choosetype);
		if(input->choosetype == 'i' || input->choosetype == 'f' || input->choosetype == 's')
			break;
		printf("輸入錯誤!\n");
	}
	printf("輸入資料：");
	if(input->choosetype == 'i') //整數 
		scanf("%d", &input->type.i_data);
	else if(input->choosetype == 'f') //浮點數 
		scanf("%f", &input->type.f_data);
	else{ //字串 
		getchar();
		gets(input->type.s_data);
	}
	
	if(*Ptr == NULL) //第一筆資料輸入 
		*Ptr = input;
	else{
		Data* tempPtr = *Ptr;
		while(tempPtr->nextPtr != NULL){ //跑到出現空的 
			tempPtr = tempPtr->nextPtr;
		}
		tempPtr->nextPtr = input; //存入 
	}
}

void printdata(Data* Ptr){ //印出新增的所有資料 
	Data* tmp = Ptr;
	while(tmp != NULL){
		if(tmp->choosetype == 'i') //整數 
            printf("%d\n", tmp->type.i_data);
        else if(tmp->choosetype == 'f') //浮點數 
            printf("%f\n", tmp->type.f_data);
        else //字串 
            printf("%s\n", tmp->type.s_data);
        tmp = tmp->nextPtr;
	}
}

void freedata(Data* Ptr){ //釋放空間 
	while(Ptr != NULL){
		Data* temp = Ptr;
		Ptr = Ptr->nextPtr;
		free(temp);
	}
}

int main(){
	int choose = 0;
	Data* headPtr = NULL;
	while(1){
		printf("選擇：(1.新增/2.印出/0.結束)：");
		scanf("%d", &choose);
		if(choose == 0){ //結束程式 
			freedata(headPtr); //釋放記憶體 
			printf("結束程式");
			return 0;
		}
		else if(choose == 1) // 新增資料 
			inputnewdata(&headPtr);
		else if(choose == 2) // 印出資料 
			printdata(headPtr);
		else
			printf("輸入錯誤!\n");
	}
}
