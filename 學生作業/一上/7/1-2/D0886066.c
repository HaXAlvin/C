#include <stdio.h>
#include <stdlib.h>
int main(){
	int lengths,columns,rows; 
	printf("��J�٧ι﨤�u���(3�B5�B7�B9): ");
	scanf("%d",&lengths);
	//�P�_�﨤�u��ƬO�_�b�W�w�� 
	while(1){
		if(lengths == 3){
		    break;	
		}else if(lengths == 5){
			break;	
		}else if(lengths == 7){
			break;	
		}else if(lengths == 9){
			break;	
		}else{
			printf("��J���~!\n");
			printf("��J�٧ι﨤�u���(3�B5�B7�B9):");
			scanf("%d",&lengths);
		}
	}
	//�P�_��ƬO�_�b�W�w��
	printf("��J���(2 ~ 10) : ");
	scanf("%d",&columns);
	while((columns<2)||(columns>10)){
		printf("��J���~!\n");
		printf("��J���(2 ~ 10) : ");
		scanf("%d",&columns);
	}
	//�P�_�C�ƬO�_�b�W�w��
	printf("��J�C��(2 ~ 10) : ");
	scanf("%d",&rows);
	while((rows<2)||(rows>10)){
		printf("��J���~!\n");
		printf("��J�C��(2 ~ 10) : ");
		scanf("%d",&rows);
	}
	printf("\n");
/*�Ĥ@�j�鬰�P�_�g�h�֦C
  �Ĥ@�j�餤���Ĥ@�j��P�ĤG�j����O�P�_�W�B�U�ݰj��X��
  �A���O�P�_�ݼg�h�֦�
  �̤���j����O�P�_�ݭn�h�֪Ů�M�̦r�� 
*/ 
	for(int m=1;m<=rows;m++){
		for(int j=1;j<=(lengths+1)/2;j++){
			for(int i=1;i<=columns;i++){
				for(int k1=1;k1<=(lengths+1)/2-j;k1++){
					printf(" ");
				}
				for(int k2=1;k2<=2*j-1;k2++){
					printf("*");
				}
				for(int k1=1;k1<=(lengths+1)/2-j+1;k1++){
					printf(" ");
				}
		    }
		    printf("\n");
		}
	    for(int j=1;j<=(lengths-1)/2;j++){
			for(int i=1;i<=columns;i++){
				for(int k3=1;k3<=j;k3++){
					printf(" ");
				}
				for(int k4=1;k4<=lengths-2*j;k4++){
					printf("*");
				}
				for(int k3=1;k3<=j+1;k3++){
					printf(" ");
				}
		    }
			printf("\n");
    	}
    	printf("\n");
    }
	return 0;
} 
