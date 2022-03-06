#include <stdio.h>
#include <stdlib.h>

typedef union{ //�x�s��ƪ����A 
	int i_data; //��� 
	float f_data; //�B�I�� 
	char s_data[16]; //�r�� 
}Type;

typedef struct data* dataPtr;  

typedef struct data{ //�s���ƪ����c 
	Type type; //��� 
	char choosetype; //��ƫ��A 
	dataPtr nextPtr; //�ۧڰѦҫ��Ц��� 
}Data;

void inputnewdata(Data** Ptr){ //�s�W��� 
	Data* input = malloc(sizeof(Data)); //�Ȯɦs���J 
	input->nextPtr = NULL;
	while(1){ //��ܪ���ƫ��A�W�X���� 
		printf("��������G(i�Gint/f�Gfloat/s�Gchar[16])�G");
		getchar();
		scanf("%c", &input->choosetype);
		if(input->choosetype == 'i' || input->choosetype == 'f' || input->choosetype == 's')
			break;
		printf("��J���~!\n");
	}
	printf("��J��ơG");
	if(input->choosetype == 'i') //��� 
		scanf("%d", &input->type.i_data);
	else if(input->choosetype == 'f') //�B�I�� 
		scanf("%f", &input->type.f_data);
	else{ //�r�� 
		getchar();
		gets(input->type.s_data);
	}
	
	if(*Ptr == NULL) //�Ĥ@����ƿ�J 
		*Ptr = input;
	else{
		Data* tempPtr = *Ptr;
		while(tempPtr->nextPtr != NULL){ //�]��X�{�Ū� 
			tempPtr = tempPtr->nextPtr;
		}
		tempPtr->nextPtr = input; //�s�J 
	}
}

void printdata(Data* Ptr){ //�L�X�s�W���Ҧ���� 
	Data* tmp = Ptr;
	while(tmp != NULL){
		if(tmp->choosetype == 'i') //��� 
            printf("%d\n", tmp->type.i_data);
        else if(tmp->choosetype == 'f') //�B�I�� 
            printf("%f\n", tmp->type.f_data);
        else //�r�� 
            printf("%s\n", tmp->type.s_data);
        tmp = tmp->nextPtr;
	}
}

void freedata(Data* Ptr){ //����Ŷ� 
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
		printf("��ܡG(1.�s�W/2.�L�X/0.����)�G");
		scanf("%d", &choose);
		if(choose == 0){ //�����{�� 
			freedata(headPtr); //����O���� 
			printf("�����{��");
			return 0;
		}
		else if(choose == 1) // �s�W��� 
			inputnewdata(&headPtr);
		else if(choose == 2) // �L�X��� 
			printdata(headPtr);
		else
			printf("��J���~!\n");
	}
}
