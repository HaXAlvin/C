#include<stdio.h>
typedef struct machine{                //建立一個名為count的結構，裡面有兩個成員，a 和 b
	int a;
	int b;
} count;
int toss(int a,int b){                  //輾轉相除法
	while(b!=0){
        int t=b;
        b=a%b;
        a=t;
	}
	return a;
}
count simplification(count simp){       //化簡
	int n=toss(simp.a,simp.b);
	simp.a/=n;
	simp.b/=n;
	if(simp.b<0){                       //當分母有負號時，把負號給分子
		simp.b*=-1;
		simp.a*=-1;
	}
	return simp;
}
count add(count x,count y){                   // 加法
	x.a*=y.b;
	y.a*=x.b;
	count result={x.a+y.a , y.b*x.b};
	result=simplification(result);
	return result;
}
count sub(count x,count y){                    //減法
	x.a*=y.b;
	y.a*=x.b;
	count result={x.a-y.a , y.b*x.b};
	result=simplification(result);
	return result;
}
count mul(count x,count y){                   //乘法
	count result={x.a*y.a , y.b*x.b};
	result=simplification(result);
	return result;
}
count div(count x,count y){                   //除法
	count result={x.a*y.b , y.a*x.b};
	result=simplification(result);
	return result;
}
int main(){
	int n;
	count number1;
	count number2;
	count number3;
	while(1){
		printf("選擇(1.加/2.減/3.乘/4.除/0.離開) : ");
		scanf("%d",&n);                    //使用者輸入
		int c;
		if(n==1)                           //57~64 為儲存四則運算符號符號
			c='+';
		else if(n==2)
			c='-';
		else if(n==3)
			c='*';
		else
			c='/';

		if(n==0)                             //如果是0就離開 不符合1~4就 輸出一個輸入錯誤
			break;
		else if(n<1 || n>4){
			printf("輸入錯誤\n\n");
			continue;
		}
		printf("a/b %c c/d、請輸入a b c d: ",c);
		scanf("%d %d %d %d",&number1.a,&number1.b,&number2.a,&number2.b);
		if(number1.b==0 || number2.b==0 ){
			printf("分母不可為0\n\n");
			continue;
		}
		else if((n==4 && (number1.a==0||number2.a==0))){
			printf("除數不可為0\n\n");
			continue;
		}
		switch(n){                                  //判斷是要到哪個結構函數的switch
			case 1:
				number3=add(number1,number2);
				break;
			case 2:
				number3=sub(number1,number2);
				break;
			case 3:
				number3=mul(number1,number2);
				break;
			case 4:
				number3=div(number1,number2);
		}
		if(number3.b!=1)                                 //如果不是整數就印出分數形式，否則只印出整數
            printf("%d/%d %c %d/%d = %d/%d\n\n",number1.a,number1.b,c,number2.a,number2.b,number3.a,number3.b);
        else
            printf("%d/%d %c %d/%d = %d\n\n",number1.a,number1.b,c,number2.a,number2.b,number3.a);
	}
	return 0;
}
