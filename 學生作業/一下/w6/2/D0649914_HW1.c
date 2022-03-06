#include<stdio.h>
#include<stdlib.h>
typedef struct node *NodePtr;					//宣告結構指標 
typedef struct node{							//宣告結構並宣告成員 
	char c;
	union{
		int num1;
		float num2;
		char str[16];	
	};
	NodePtr nextPtr;
}Node;
int create(NodePtr *ptr){						//新增的函數 
	NodePtr newPtr=malloc(sizeof(Node));		 
	newPtr->nextPtr=NULL;						//增加新的鏈結串鍊的元素並設定為NULL 
	printf("選擇類型 : (i : int/f :float/s : char[16]) :");
	scanf("%c%*c",&newPtr->c);					//儲存鏈結此新增的鏈結串鍊所要儲存的型態 
	if(newPtr->c=='i'||newPtr->c=='f'||newPtr->c=='s')		
		printf("輸入資料 : ");
		
	if(newPtr->c=='i'){							//依型態進入if裡 進行資料輸入 如輸入錯誤回傳-1否則為0 
		scanf("%d",&newPtr->num1);
	}
	else if(newPtr->c=='f'){
		scanf("%f",&newPtr->num2);
	}
	else if(newPtr->c=='s'){
		scanf("%s",&newPtr->str);
	}
	else{
		printf("輸入錯誤!\n");
		return -1; 
	}
	
	if(*ptr==NULL)							//如果上述num不是-1的話 會來到這裡 這裡判斷說我現在的ptr所儲存的是不是NULL如果是就指向他 
		*ptr=newPtr;						//否則進入else指向下一個在判斷是否為NULL 
	else{
		NodePtr tempPtr=*ptr;
		while(tempPtr->nextPtr !=NULL)
			tempPtr=tempPtr->nextPtr;
		tempPtr->nextPtr = newPtr;
	}
	return 0;								//成功就return 0 
}
void print(NodePtr node){
	while(node){							//印出列表的值 
		if(node->c=='i')					//依序判斷為什麼型態並印出 
			printf("%d\n",node->num1);
		else if(node->c=='f')
			printf("%f\n",node->num2);
		else if(node->c=='s')
			printf("%s\n",node->str);
		
		node=node->nextPtr;					//印出之後就換一個 
	}
}
void freeList(NodePtr *ptr){				//free空間的函數 
	while(*ptr!=NULL){
		NodePtr tempPtr=*ptr;				//宣告一個暫存ptr的結構指標並指向ptr 
		*ptr = (*ptr)->nextPtr;				//暫存後就可改變現階段的ptr指向的地方 直到ptr指向的地方為NULL才結束此迴圈 
		if(tempPtr->c=='i')					//可看出現在正要free哪個空間的判斷 
			printf("delete %d\n",tempPtr->num1);
		else if(tempPtr->c=='f')
			printf("delete %f\n",tempPtr->num2);
		else if(tempPtr->c=='s')
			printf("delete %s\n",tempPtr->str);
		
		free(tempPtr);						//一個一個free空間直到ptr有指向NULL的地方 
	}
}
int main(){
	NodePtr head=NULL;										//宣告鏈結串鍊的開頭 
	int user,num;
	do{
		printf("選擇 : (1.新增/2.印出/0.結束) :");
		scanf("%d%*c",&user);
		switch(user){
			case 1:
				num=-1;
				while(num==-1){								//當是-1的時候 代表輸入錯誤就重新進入迴圈哦~~~ 
					num=create(&head);						//新增的函數 
				}	
				break;
			case 2:
				print(head);								//印出的函數 
				break;
			case 0:
				freeList(&head);							//結束程式 順便free 
				printf("結束程式\n");
				break;
			default:
				printf("輸入錯誤!\n");
				break; 
		} 
	}while(user!=0);
}
