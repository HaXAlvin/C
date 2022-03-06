#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef union _information{ //�Τ��P���A���ܼƥh�s��J�����
    int i;
    float f;
    char s[16];
}information;


typedef struct _array{  //���Ӧs���
    information infor;
    char type;
    struct _array *nextptr; //�U�@�Ӹ�ƪ���m
}array;

void scan(array *arr){  //��ܸ�ƫ��A�ο�J���
    while(1){
        printf("��������G(i�Gint/f�Gfloat/s�Gchar[16])�G");
        getchar();
        scanf("%c",&arr->type);
        printf("��J��ơG");
        if(arr->type == 's'){
            scanf("%s",&arr->infor.s);
            break;
        }
        else if(arr->type == 'i'){
            scanf("%d",&arr->infor.i);
            break;
        }
        else if(arr->type == 'f'){
            scanf("%f",&arr->infor.f);
            break;
        }
        else{
            printf("��J���~�I\n");
            continue;
        }
    }

}

int main(){
    int now = 0,chose,i;
    array *head = NULL,*currentarr = NULL,*tmp,*current;
    while(1){
        printf("��ܡG(1.�s�W/2.�L�X/0.����)�G");
        scanf("%d",&chose);  //��ܷs�W�L�X����
        if(chose == 1){  //�s�W���
            if(head == NULL){  //�Y�S����� ���L��}�Y
            	head = malloc(sizeof(array));
            	currentarr = head;
			}
            else {  //�p�G�e�����F �N��nextptr = �U�@�Ӹ�Ʀs���a��
            	currentarr->nextptr = malloc(sizeof(array));
            	currentarr = currentarr->nextptr;
			}
			currentarr->nextptr = NULL;
            scan(currentarr); //��J��
        }
        else if(chose == 2){  //�L�X
            current = head;
            while(current != NULL){
                if(current->type == 'i') { //�O�o�P�_���A �A�M�w���L�X
                    printf("%d\n",current->infor.i);
                }
                else if(current->type == 'f'){
                    printf("%f\n",current->infor.f);
                }
                else{
                    printf("%s\n",current->infor.s);
                }
                current = current->nextptr;
            }
        }
        else if(chose == 0){  //��Ŷ�free��
            printf("�����{��\n");
            currentarr = head;
            while(currentarr != NULL){
                tmp = currentarr->nextptr;
                free(currentarr);
                currentarr = tmp;
            }
            head = NULL;
            break;
        }
        else {  //�N012�A�ٷ|���!
            printf("��J���~�I\n");
            continue;
        }
    }

}

