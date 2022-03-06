#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{
	union{
		int data;
		float data_f;
		char data_c[16];
	};
	//每個Node的型態 
	enum{
		INT, FLOAT, STRING
	}type;
	struct Node* next;
	
}; 
typedef struct Node node;
typedef node* link; 
link head = NULL;//把head設成全域變數這樣function就不用傳head進去了 

//根據型態獲得一個新的節點 
link getNode_int(int value){
	link newNode = malloc(sizeof(node));
	newNode->type = INT;
	newNode->data = value;
	newNode->next = NULL;//把節點的下一個設成NULL 
	return newNode;
}

link getNode_float(float value){
	link newNode = malloc(sizeof(node));
	newNode->type = FLOAT;
	newNode->data_f = value;
	newNode->next = NULL;
	return newNode;
}

link getNode_str(char str[]){
	link newNode = malloc(sizeof(node));
	newNode->type = STRING;
	strcpy(newNode->data_c, str);
	newNode->next = NULL;
	return newNode;
}

void insert_end_int(){
	printf("輸入資料: ");
	int value;
	scanf("%d", &value);
	link newNode = getNode_int(value);//用getNode新增一個node 
	
	if (head == NULL)
		head = newNode;//如果head等於NULL代表這個串列還沒有值 
	else{
		link current = head;
		while (current->next != NULL){
			//設一個新的指標讓他跑到串列的最後一個 
			current = current->next;
		}
		current->next = newNode;
	}
}
void insert_end_float(){
	printf("輸入資料: "); 
	float value;
	scanf("%f", &value);
	link newNode = getNode_float(value);
	
	if (head == NULL)
		head = newNode;
	else{
		link current = head;
		while (current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	}
}

void insert_end_str(){
	printf("輸入資料: ");
	char value[16];
	scanf("%s", &value);
	link newNode = getNode_str(value);
	
	if (head == NULL)
		head = newNode;
	else{
		link current = head;
		while (current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	}
}

void display(){
	link current = head;
	while (current != NULL){
		//根據型態把值印出來 
		if (current->type == INT)
			printf("%d\n", current->data);
		else if (current->type == FLOAT)
			printf("%f\n", current->data_f);
		else if (current->type == STRING)
			printf("%s\n", current->data_c);
		current = current->next;	
	}
}
void clear(){
	link temp = head, ptr = head;
	while(ptr != NULL){
		temp = ptr;
        ptr = ptr->next; 
        free(temp);
    }
    printf("Success\n");
}

int main(){
	int user_input, end = 0;
	char type;
	do{
        printf("選擇:(1.新增, 2.印出, 3.結束) : ");
        scanf("%d", &user_input);
        getchar();
        switch(user_input){
            case 1:
            	printf("選擇型態:(i: int/f: float/s: char[16]): ");
        		scanf("%c", &type);
				type == 'i'? insert_end_int() : type == 'f' ? insert_end_float() : insert_end_str();
                break;
            case 2:
                display();
                break;
            case 3:
                clear();
                end = 1;
                break;
            default:
            	printf("輸入錯誤!\n");
                break;
        } 
    }while(!end);
    
	return 0;
}
