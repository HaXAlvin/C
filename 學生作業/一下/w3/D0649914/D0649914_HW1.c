#include<stdio.h>
int add(int a,int b){						//加法的函數 
	return a+b;
}
int sub(int a,int b){						//減法的函數 
	return a-b;
}
int multi(int a,int b){						//乘法的函數 
	return a*b;
}
int divide(int a,int b){					//除法的函數 
	if(b!=0)
		return a/b;
	else
		return 0;
}
int mod(int a,int b){						//取餘數的函數 
	if(b!=0)
		return a%b;
	else
		return 0;
}
int main(){
	int (*opt[5])(int,int)={add,sub,multi,divide,mod};			//函數指標變數 
	int n,num1,num2,result;										//n為使用者輸入的變數 num1為數字1 num1為數字2 result是決定運用哪個四則運算的變數 
	do{
		printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0離開)"); 
		scanf("%d",&n);
		
		if(n!=0){
			printf("請輸入2個整數:");
			scanf("%d %d",&num1,&num2);
			result=opt[n-1](num1,num2);								//呼叫函數以及運算 
			switch(n){		
				case 1:												//加法 
					printf("%d + %d = %d\n",num1,num2,result);
					break;
				case 2:												//減法 
					printf("%d - %d = %d\n",num1,num2,result);
					break;
				case 3:												//乘法 
					printf("%d * %d = %d\n",num1,num2,result);
					break;
				case 4:												//除法 
					printf("%d / %d = %d\n",num1,num2,result);
					break;
				case 5:												//取餘數 
					printf("%d %% %d = %d\n",num1,num2,result);
					break;
			}
		}
	}while(n!=0);
	return 0;
} 
