#include <stdio.h>
#include <stdlib.h>

// data, type, *next_node
typedef struct node {
	union {
		int I;
		float F;
		char S[16];
	};
	int type;
	struct node *Next;
} Node;

/*
   Info: ���J�s�`�I����w��C���̫᭱
   Parameters: �¦�C�̫�@�Ӹ`�I����}�A�s�`�I�N�Q���J�ܸӸ`�I���U�@�Ӧ�}�A�ǤJNULL�N��Ыؤ@�s��C
   Return value: �s��C���s�`�I����}
*/
Node* newNode(Node* startNode) {
	Node *currentNode = (Node*) malloc(sizeof(Node));          // �Ыؤ@�s�`�I�A����A���ʨ�ؼЦ�m
	if (startNode != NULL)                                     // �ǤJ�ȭY��NULL�A�Ыطs��C�A�������ާ@��H
		startNode->Next = currentNode;
	do {
		printf("�п������ (1: int, 2: float, 3: char[16])�G"); // ��������
		scanf("%i", &currentNode->type);
		setbuf(stdin, NULL);                                   // �����w�İϤ��e
		switch (currentNode->type) {
			case 1: //int
				printf("�п�J��ơG");
				scanf("%i", &currentNode->I);      // ��J��� (Int) 
			break;
			case 2: //float
				printf("�п�J�p�ơG");
				scanf("%f", &currentNode->F);      // ��J��� (Float)
			break;
			case 3: //string[16]
				printf("�п�J�r��G");
				scanf("%16[^\n]", currentNode->S); // ��J��� (String)
			break;
			default:
				puts("Wrong Type!\n");
				currentNode->type = -1;
			break;
		}
		setbuf(stdin, NULL);           // �����w�İϤ��e
	} while (currentNode->type == -1); // �������~�A����
	currentNode->Next = NULL;          // ���J���`�I���VNULL�פ�
	return currentNode;                // ��^�s�`�I��}
}

/*
   Info: �̧Ǵ����X��C���e�A�H�ǤJ�`�I���_�l�I
*/
void printNode(Node *currentNode) {
	while (currentNode != NULL) {
		switch (currentNode->type) {
			case 1:
				printf("%i\n", currentNode->I);
			break;
			case 2:
				printf("%f\n", currentNode->F);
			break;
			case 3:
				printf("%s\n", currentNode->S);
			break;
		}
		currentNode = currentNode->Next; // �����ܤU�@�`�I
	}
}

/*
   Info: �̧������C�O����A�H�ǤJ�`�I���_�l�I
*/
void freeNode(Node *currentNode) {
	void *nextPtr;
	while (currentNode != NULL) {
		nextPtr = currentNode->Next; // �U�@�`�I����}��Buffer
		free(currentNode);           // �����e�`�I
		currentNode = nextPtr;       // �̾ڽw�Ī�nextPtr�����ܤU�@�`�I
	}
}

int main(void) {
	int choice = 0;
	Node* startNode = NULL;
	Node* currentNode = NULL;

	while (1) {
		setbuf(stdin, NULL);  // �����w�İϤ��e
		printf("�п�ܰʧ@ (1. �s�W, 2. �L�X, 0. ����)�G");
		scanf("%i", &choice); // ��ܰʧ@
		switch (choice) {
			case 1:  // �s�W�`�I
				if (currentNode == NULL) {              // �L��C
					startNode = newNode(NULL);          // �s�W�@�Ӹ`�I
					currentNode = startNode;
				} else {                                // ����C
					currentNode = newNode(currentNode); // �s�W�`�I�ä����ܤU�@�Ӹ`�I
				}
			break;
			case 2:  // �L�X��C
				printNode(startNode);
			break;
			case 0:  // �����C�����}
				freeNode(startNode);
			return 0;
			default: // ���~���
				puts("Wrong Choice!\n");
			break;
		}
	}
	return 1;
}