#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{
	union{
		int data;
		float data_f;
		char data_c[16];
	};
	//�C��Node�����A 
	enum{
		INT, FLOAT, STRING
	}type;
	struct Node* next;
	
}; 
typedef struct Node node;
typedef node* link; 
link head = NULL;//��head�]�������ܼƳo��function�N���ζ�head�i�h�F 

//�ھګ��A��o�@�ӷs���`�I 
link getNode_int(int value){
	link newNode = malloc(sizeof(node));
	newNode->type = INT;
	newNode->data = value;
	newNode->next = NULL;//��`�I���U�@�ӳ]��NULL 
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
	printf("��J���: ");
	int value;
	scanf("%d", &value);
	link newNode = getNode_int(value);//��getNode�s�W�@��node 
	
	if (head == NULL)
		head = newNode;//�p�Ghead����NULL�N��o�Ӧ�C�٨S���� 
	else{
		link current = head;
		while (current->next != NULL){
			//�]�@�ӷs���������L�]���C���̫�@�� 
			current = current->next;
		}
		current->next = newNode;
	}
}
void insert_end_float(){
	printf("��J���: "); 
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
	printf("��J���: ");
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
		//�ھګ��A��ȦL�X�� 
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
        printf("���:(1.�s�W, 2.�L�X, 3.����) : ");
        scanf("%d", &user_input);
        getchar();
        switch(user_input){
            case 1:
            	printf("��ܫ��A:(i: int/f: float/s: char[16]): ");
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
            	printf("��J���~!\n");
                break;
        } 
    }while(!end);
    
	return 0;
}
