#include<stdio.h>
typedef struct machine{                //�إߤ@�ӦW��count�����c�A�̭�����Ӧ����Aa �M b
	int a;
	int b;
} count;
int toss(int a,int b){                  //����۰��k
	while(b!=0){
        int t=b;
        b=a%b;
        a=t;
	}
	return a;
}
count simplification(count simp){       //��²
	int n=toss(simp.a,simp.b);
	simp.a/=n;
	simp.b/=n;
	if(simp.b<0){                       //��������t���ɡA��t�������l
		simp.b*=-1;
		simp.a*=-1;
	}
	return simp;
}
count add(count x,count y){                   // �[�k
	x.a*=y.b;
	y.a*=x.b;
	count result={x.a+y.a , y.b*x.b};
	result=simplification(result);
	return result;
}
count sub(count x,count y){                    //��k
	x.a*=y.b;
	y.a*=x.b;
	count result={x.a-y.a , y.b*x.b};
	result=simplification(result);
	return result;
}
count mul(count x,count y){                   //���k
	count result={x.a*y.a , y.b*x.b};
	result=simplification(result);
	return result;
}
count div(count x,count y){                   //���k
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
		printf("���(1.�[/2.��/3.��/4.��/0.���}) : ");
		scanf("%d",&n);                    //�ϥΪ̿�J
		int c;
		if(n==1)                           //57~64 ���x�s�|�h�B��Ÿ��Ÿ�
			c='+';
		else if(n==2)
			c='-';
		else if(n==3)
			c='*';
		else
			c='/';

		if(n==0)                             //�p�G�O0�N���} ���ŦX1~4�N ��X�@�ӿ�J���~
			break;
		else if(n<1 || n>4){
			printf("��J���~\n\n");
			continue;
		}
		printf("a/b %c c/d�B�п�Ja b c d: ",c);
		scanf("%d %d %d %d",&number1.a,&number1.b,&number2.a,&number2.b);
		if(number1.b==0 || number2.b==0 ){
			printf("�������i��0\n\n");
			continue;
		}
		else if((n==4 && (number1.a==0||number2.a==0))){
			printf("���Ƥ��i��0\n\n");
			continue;
		}
		switch(n){                                  //�P�_�O�n����ӵ��c��ƪ�switch
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
		if(number3.b!=1)                                 //�p�G���O��ƴN�L�X���ƧΦ��A�_�h�u�L�X���
            printf("%d/%d %c %d/%d = %d/%d\n\n",number1.a,number1.b,c,number2.a,number2.b,number3.a,number3.b);
        else
            printf("%d/%d %c %d/%d = %d\n\n",number1.a,number1.b,c,number2.a,number2.b,number3.a);
	}
	return 0;
}
