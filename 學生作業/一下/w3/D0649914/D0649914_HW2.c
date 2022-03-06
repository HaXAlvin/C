#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void sort(char **arr,int n,int (*cmp)(char *,char *)){			//�w�j�Ƨ�
	int k,i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(cmp(arr[j],arr[j+1])){
				char *c=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=c;
			}
		}

	}
}
int cmp1(char *a,char *b){						// Ascii�X�覡�Ƨ�
	if(strcmp(a,b)>=0)
		return 1;
	else
		return 0;
}
int cmp2(char *a,char *b){						// �r��覡�Ƨ�
	int i,len;
	int len1=strlen(a);							//25~30 �P�_���Ӧr�����u��len
	int len2=strlen(b);
	if(len1>len2)
		len=len2;
	else
		len=len1;

	for(i=0;i<len;i++){							//�r���@�˪��ܴN���U�@�Ӧr��
		char c1=*(a+i),c2=*(b+i);
		if(islower(c1))							//34~37���P�_�O�_���p�g�A�p�G�O�N�ন�j�g
			c1=toupper(*(a+i));
		if(islower(c2))
			c2=toupper(*(b+i));

		if(c1>c2){								//�p�Gc1>c2 �N�洫 �_�h �P�_ ��Ӫ��r���O�_�۵�
			return 1;
		}
		else if(c1==c2){
			if(*(a+i)>*(b+i))					//�p�G��r��a+i�O�p�g���� b+i���j�g �N��*(a+i)>*(b+i) �ҥH�n�洫 �_�h�~�����U�Ӧr��
				return 1;
			else if(*(a+i)==*(b+i))
				continue;
			else
				return 0;
		}

	}
}
int main(){
	char **sArr;								//�s��W�r���ʺA�}�C
	int n,num;									//n=�ϥΪ̨M�w�X�ӳ�r���ܼ� num=�M�w�ƧǤ覡���ܼ�
	int i;
	while(1){
		printf("�п�J�r���(��J0����) : ");
		scanf("%d",&n);
		if(n==0){								//�p�G�O0�N���}
			break;
		}
		sArr=malloc(n*sizeof(char *));				//63~67 ���ŧi�G���ʺA�}�C�A�H��Ū�J��r
		for(i=0;i<n;i++){
			sArr[i]=malloc(100*sizeof(char));
			scanf("%s",sArr[i]);
		}

		printf("��ܱƧǤ覡(1. �HASCII/2. �H�r���) : ");
		scanf("%d",&num);
		if(num==1){								//�ƧǤ@���P�_
				sort(sArr,n,cmp1);
			for(i=0;i<n;i++)
				printf("%s\n",sArr[i]);
		}
		else{									//�ƧǤG���P�_
			sort(sArr,n,cmp2);
			for(i=0;i<n;i++)
				printf("%s\n",sArr[i]);
		}
	}

	return 0;
}
