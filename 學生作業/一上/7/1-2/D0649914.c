#include<stdio.h>
int main(){
	int i,j,k,diamond,row,line,star,star2,space,space2;
	for(i=1;i<4;){                                          //3���P�_ ��W�L�ε���4���� ���X�j�� 
		if(i==1){                                           //�P�_�{�b�O���O�n��J�٧Ϊ����� 
			printf("��J�٧ι﨤�u����(3�B5�B7�B9): ");
			scanf("%d",&diamond);
			if(diamond !=3 && diamond !=5 && diamond !=7 && diamond !=9){       //�P�_�٧άO���O����3�B5�B7�B9 �p�G���O�L�X���~ �����^�h�j�� 
				printf("��J���~!\n");
				continue;
			}
			else{
				i++;
			}
		}
		else if(i==2){                                     //�P�_�{�b�O���O�n��J���                                    
			printf("��J���(2 ~ 10):");
			scanf("%d",&row);
			if(row>=2 && row<=10){                         //�P�_�C�ƬO���O����2~10 �p�G���O�L�X���~ �����^�h�j�� 
				i++;
			}
			else{
				printf("��J���~\n");
				continue;
			}
		}
		else if(i==3){                                     //�P�_�{�b�O���O�n��J�C�� 
			printf("��J�C��(2 ~ 10):");
			scanf("%d",&line);
			if(line>=2 && line<=10){                       //�P�_�C�ƬO���O����2~10 �p�G���O�L�X���~ �����^�h�j��
				i++;
			}
			else{
				printf("��J���~\n");
				continue;
			}	
		}
	}
	printf("\n");
	for(i=1;i<=line;i++){                                           //�L�X���h�֦C���j�� 
		for(j=1,star2=1,space2=(diamond+1)/2;j<=diamond;j++){       //�L�X�٧Ϊ��j��  �]���ƶq=diamond���ƶq 
			if(j<=(diamond+1)/2){                                   //�P�_�L�X�W�b���٧Ϊ����� 
				for(k=1;k<=row;k++){								//�L�X�W�b���٧Ϊ��j�� 
					for(space=space2;space>1;space--){
						printf(" ");
					}
					for(star=1;star<=star2;star++){
						printf("*");
					}
					for(space=space2;space>=1;space--){
						printf(" ");
					}
				}
				if(j!=(diamond+1)/2){
					star2+=2;
					space2--;
				}
			}
			else{                                 				    //�P�_�L�X�U�b���٧Ϊ�����
				for(k=1;k<=row;k++){								//�L�X�U�b���٧Ϊ��j�� 
					for(space=0;space<space2;space++){
						printf(" ");
					}
					for(star=star2-2;star>=1;star--){
						printf("*");
					}
					for(space=0;space<=space2;space++){
						printf(" ");
					}
				}
				star2-=2;
				space2++;
			}
			printf("\n");											//�檺���� 
		}
		printf("\n");											    //�C������ 
	}
	return 0;
}
