#include<stdio.h>
int add(int a,int b){						//�[�k����� 
	return a+b;
}
int sub(int a,int b){						//��k����� 
	return a-b;
}
int multi(int a,int b){						//���k����� 
	return a*b;
}
int divide(int a,int b){					//���k����� 
	if(b!=0)
		return a/b;
	else
		return 0;
}
int mod(int a,int b){						//���l�ƪ���� 
	if(b!=0)
		return a%b;
	else
		return 0;
}
int main(){
	int (*opt[5])(int,int)={add,sub,multi,divide,mod};			//��ƫ����ܼ� 
	int n,num1,num2,result;										//n���ϥΪ̿�J���ܼ� num1���Ʀr1 num1���Ʀr2 result�O�M�w�B�έ��ӥ|�h�B�⪺�ܼ� 
	do{
		printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0���})"); 
		scanf("%d",&n);
		
		if(n!=0){
			printf("�п�J2�Ӿ��:");
			scanf("%d %d",&num1,&num2);
			result=opt[n-1](num1,num2);								//�I�s��ƥH�ιB�� 
			switch(n){		
				case 1:												//�[�k 
					printf("%d + %d = %d\n",num1,num2,result);
					break;
				case 2:												//��k 
					printf("%d - %d = %d\n",num1,num2,result);
					break;
				case 3:												//���k 
					printf("%d * %d = %d\n",num1,num2,result);
					break;
				case 4:												//���k 
					printf("%d / %d = %d\n",num1,num2,result);
					break;
				case 5:												//���l�� 
					printf("%d %% %d = %d\n",num1,num2,result);
					break;
			}
		}
	}while(n!=0);
	return 0;
} 
