#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main(){
	srand(time(NULL));
	int temp=1;
	char user[100];                                                             //�ϥΪ̿�J���ܼ� 
	int i,j,com[4],com2[10]={0},user2[4],user3[10]={0},t=0,a=0,b=0;             
	//com�q������ com2�P�_���L���ƪ��ȱo�ܼ�  
	//user2 ��L�নint���ܼ� user3 �P�_���L���ƪ��ܼ�
	while(1){
		if(temp==1){                              //�P�_�O���O�٬O�쥻���@�� �p�G���O �q���~�|�i��random�ƭ� 
			for(i=0;i<10;i++){                    //���}�}�l�� ��P�_�k0 
				com2[i]=0;
			}
			for(i=0;i<4;i++){                     //�ᤩ�q���Ʀr���j�� 
				com[i]=rand()%10;
				if(com2[com[i]] == 1){            //�p�G��J���Ʀr�����ƪ��� ���s�ᤩ�Ȩ�}�C�� 
					i--;
					continue;
				}
				com2[com[i]]= 1;
				printf("%d",com[i]);              // �O�d���Ǫ��ݦ��S�����D����X 
 			}
 			temp=0;                                
 		}
 		if(t==0){                                 //�ΨӰϹj�쩳���S����J���~  �p�G���~ �����^��o�̰���l�� 
 			for(i=0;i<10;i++){                       
				user3[i]=0;
			}
			a=0;
			b=0;
		}
		printf(">> ");
			scanf("%s",&user);
			if(strlen(user)!=4){                 //�p�G��J������4�Ӧr�Ū��� �N���~ 
				printf("INPUT ERROR\n");
				continue;
			}
		for(i=0;i<4;i++){
			user2[i]=user[i]-48;
			if(user3[user2[i]]==1){              //�p�G��J�����ƪ��� �N���~ 
				printf("INPUT ERROR\n");         
				t=1;
				break;
			}
			user3[user2[i]]=1;
		}
		if(t==1){                                  //�p�G��J���~�N�^��28�� 
			t=0;
			continue;
		}
		for(i=0;i<4;i++){                           //�p�� A���h�� B���h�� 
			if(com[i]==user2[i]){
				a++;
			}
			else{
				for(j=0;j<10;j++){
					if(com2[j]==user3[j] && com2[j]!=0){
						b++;
					}
				}
			}
		}
		b/=4;                                     //�]���p�G��b���� �|����4�� �ҥHb/4 
		if(a==4){								  //A=4���� �NĹ  �_�h�L�X�XA�XB 
			printf("YOU WIN\n");
			char c;
			while(1){                            //�߰ݭn���n�A���@�� 
				printf("Play Again?(Y/N)");
				scanf("%*c%c",&c);
				if(c=='N'){
					break;
				}
				else if(c== 'Y'){
					break;
				}
				else{
					continue;
				}
			}
			if(c=='N'){                        //���n�� break 
				break;
			}
			else{							   //�n�� continue 
				temp=1;
				continue;
			}
		}
		else{
			printf("%dA%dB\n",a,b);
		}
	}
	return 0;
} 
