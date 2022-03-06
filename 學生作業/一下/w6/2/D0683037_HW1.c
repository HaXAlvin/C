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
		//////功能選擇 //////
		printf("選擇:(1.新增/2.印出/0.結束): ");
		scanf("%d",&choose);

		if(choose==1){

			//新增節點and將指標指向下一個節點並配置空間
			if(headptr==NULL){
                headptr = (struct node*)malloc(sizeof(Node));
                temptr = headptr;
			}
			else{
				temptr->nextptr = (struct node*)malloc(sizeof(Node));
				temptr = temptr->nextptr ;
			}

			//新增資料型態選擇
			while(1){
				printf("選擇類型:(i:int/f:float/s:char[16]): ");
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
					printf("輸入錯誤!\n");
				}
			}


		}

		//印出串列資料
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

		//結束並釋放記憶體空間
		else if(choose==0){
			temptr = headptr;
			while(temptr!=NULL){

				if(temptr->type=='i'){
					//printf("釋放%d記憶體\n",temptr->value);
					free(temptr);
				}
				else if(temptr->type=='f'){
					//printf("釋放%f記憶體\n",temptr->num);
					free(temptr);
				}
				else if(temptr->type=='s'){
					//printf("釋放%s記憶體\n",temptr->abc);
					free(temptr);
				}
				temptr = temptr->nextptr;
			}
			printf("結束程式");
			break;
		}

		//不合法功能選擇
		else{
			printf("輸入錯誤!\n");
		}

	}

	return 0;
}
