#include<stdio.h>
#include<stdlib.h>
typedef struct _list{                     	//ť���O�n�o�˳Хߵ��c ��char ��union ���D�� �g �n�ǥ� �o���@�ʤF�� 
	char c;
	union{
		int num1;
		float num2;
		char str[16];	
	};
}list;
int create(list *com){ 					 		//�s�W���禡 
	printf("������� : (i : int/f :float/s : char[16]) :");
	scanf("%c%*c",&com->c);						//���ƫ��A�s�J���c�� c ��	
	if(com->c=='i'||com->c=='f'||com->c=='s')
		printf("��J��� : ");
	if(com->c=='i'){							//�̫��A�i�Jif�� �i���ƿ�J �p��J���~�^��-1�_�h��0 
		int n;
		scanf("%d",&com->num1);
	}
	else if(com->c=='f'){
		scanf("%f",&com->num2);
	}
	else if(com->c=='s'){
		scanf("%s",&com->str);
	}
	else{
		printf("��J���~!\n");
		return -1; 
	}
	return 0;
}
int main(){
	int n,i=0;								//n���ϥΪ̿�J�n�s�W�٦L�X�����} i���p��ʺA���а}�C��ĴX�ӤF 
	list *user;								//�ʺA�}�C���� 
	while(1){
		printf("���: (1.�s�W/2.�L�X/0.����) :") ;
		scanf("%d%*c",&n);
		if(n==0){											// 0������ 1���s�W 2���L�X �_�h��J���~ 
			break;
		}
		else if(n==1){											 
			int num=-1;
			if(i==0){
				user=(list*)malloc(1*sizeof(list));			//�Ĥ@�����ܥ�malloc��l��realloc 
			}
			else{
				user=(list*)realloc(user,(i+1)*sizeof(list));
			}
			while(num==-1){								//��O-1���ɭ� �N���J���~�N���s�i�J�j��@~~~ 
				num=create(&user[i]);	
			}
			i++;										 
		}
		else if(n==2){
			int k;
			for(k=0;k<i;k++){							//�̷ӫ��A�L�X�� 
				if((user+k)->c=='i')
					printf("%d\n",(user+k)->num1);
				else if((user+k)->c=='f')
					printf("%f\n",(user+k)->num2);
				else if((user+k)->c=='s'){
					printf("%s\n",(user+k)->str);
				}
			}
		}
		else
			printf("��J���~!\n");
	}
	printf("�����{��\n");
	free(user);											//����O����  
	return 0;
}
