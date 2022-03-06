#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int numerator; 							//���l 
	int denominator; 						//���� 
}Fraction;

int GCD(int a,int b);   					//�̤j���]�� 

int LCM(int a,int b); 						//�̤p������ 

Fraction Add(Fraction f1, Fraction f2);  	//�[�k 
Fraction Minus(Fraction f1, Fraction f2); 	//��k 
Fraction Plus(Fraction f1, Fraction f2);    //���k 
Fraction Divide(Fraction f1, Fraction f2);  //���k 


int main(){
   
    char cmd;
    
    while(1){
        printf("���(1.�[/2.��/3.��/4.��/0.���})�G ");
        cmd = getchar();
        if(cmd=='1'){
        	Fraction f1,f2,f3;
        	printf("a/b + c/d�A�п�Ja b c d�G ");
            scanf("%d %d %d %d",&f1.numerator,&f1.denominator,&f2.numerator,&f2.denominator);
            if(f1.denominator == 0 || f2.denominator == 0){
            	printf("���Ƥ��i��0\n");
			}
            if(f3.numerator == 0 || f3.denominator == 1){	
            	f3 = Add(f1, f2);
            	printf("%d/%d + %d/%d = %d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator, f3.numerator);
			}
			else{
				f3 = Add(f1, f2);
				printf("%d/%d + %d/%d = %d/%d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator, f3.numerator, f3.denominator);
			}
            getchar(); // clear your 'Enter' key.
        }
        else if(cmd=='2'){
            Fraction f1,f2,f3;
        	printf("a/b - c/d�A�п�Ja b c d�G ");
            scanf("%d %d %d %d",&f1.numerator,&f1.denominator,&f2.numerator,&f2.denominator);
            if(f1.denominator == 0 || f2.denominator == 0){
            	printf("���Ƥ��i��0\n"); 
			}
            else if(f3.numerator == 0 || f3.denominator == 1){
            	f3 = Minus(f1, f2);
            	printf("%d/%d - %d/%d = %d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator, f3.numerator);
			}
			else{
				f3 = Minus(f1, f2);
				printf("%d/%d - %d/%d = %d/%d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator, f3.numerator, f3.denominator);
			}
            getchar(); // clear your 'Enter' key.
        }
        else if(cmd=='3'){
           	Fraction f1,f2,f3;
        	printf("a/b * c/d�A�п�Ja b c d�G ");
            scanf("%d %d %d %d",&f1.numerator,&f1.denominator,&f2.numerator,&f2.denominator);
            if(f1.denominator == 0 || f2.denominator == 0){
            	printf("���Ƥ��i��0\n"); 
			}
            else if(f3.numerator == 0 || f3.denominator == 1){
            	f3 = Plus(f1, f2);
            	printf("%d/%d * %d/%d = %d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator, f3.numerator);
			}
			else{
				f3 = Plus(f1, f2);
				printf("%d/%d * %d/%d = %d/%d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator, f3.numerator, f3.denominator);
			}
            getchar(); // clear your 'Enter' key.
        }
        else if(cmd=='4'){
        	Fraction f1,f2,f3;
        	printf("a/b / c/d�A�п�Ja b c d�G ");
            scanf("%d %d %d %d",&f1.numerator,&f1.denominator,&f2.numerator,&f2.denominator);
            if(f1.denominator == 0 || f2.denominator == 0 || f2.numerator == 0){
            	printf("���Ƥ��i��0\n"); 
			}
            else if(f3.numerator == 0 || f3.denominator == 1){
            	f3 = Divide(f1, f2);
            	printf("%d/%d / %d/%d = %d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator, f3.numerator);
			}
			else{
				f3 = Divide(f1, f2);
				printf("%d/%d / %d/%d = %d/%d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator, f3.numerator, f3.denominator);
			}
        	getchar(); // clear your 'Enter' key.
        }
        else if(cmd=='0'){
        	break;
		}
        else{
            printf("��J���~\n");
            getchar(); // clear your 'Enter' key.
        }

    }
    return 0;
    
}


Fraction Add(Fraction f1, Fraction f2){
	Fraction retValue;
	int lcm = LCM(f1.denominator, f2.denominator);
	int gcd;
	retValue.denominator = lcm;
	retValue.numerator = (f1.numerator * lcm / f1.denominator) + (f2.numerator * lcm / f2.denominator);
	if(retValue.numerator==0){
		return retValue;
	}
	gcd = GCD(retValue.numerator, retValue.denominator);
	retValue.numerator /= gcd;
	retValue.denominator /= gcd;
	if(retValue.denominator < 0){
		retValue.denominator = retValue.denominator * (-1);
		retValue.numerator = retValue.numerator * (-1);
		return retValue;
	}
	return retValue;
}

Fraction Minus(Fraction f1, Fraction f2){
	Fraction retValue;
	int lcm = LCM(f1.denominator, f2.denominator);
	int gcd;
	retValue.denominator = lcm;
	retValue.numerator = (f1.numerator * lcm / f1.denominator) - (f2.numerator * lcm / f2.denominator);
	if(retValue.numerator==0){
		return retValue;
	}
	gcd = GCD(retValue.numerator, retValue.denominator);
	retValue.numerator /= gcd;
	retValue.denominator /= gcd;
	if(retValue.denominator < 0){
		retValue.denominator = retValue.denominator * (-1);
		retValue.numerator = retValue.numerator * (-1);
		return retValue;
	}
	return retValue;
}

Fraction Plus(Fraction f1, Fraction f2){
	Fraction retValue;
	int gcd;
	retValue.denominator = f1.denominator * f2.denominator;
	retValue.numerator = f1.numerator * f2.numerator;
	if(retValue.numerator==0){
		return retValue;
	}
	gcd = GCD(retValue.numerator, retValue.denominator);
	retValue.numerator /= gcd;
	retValue.denominator /= gcd;
	if(retValue.denominator < 0){
		retValue.denominator = retValue.denominator * (-1);
		retValue.numerator = retValue.numerator * (-1);
		return retValue;
	}
	return retValue;
}

Fraction Divide(Fraction f1, Fraction f2){
	Fraction retValue;
	int gcd;
	retValue.denominator = f1.denominator * f2.numerator;
	retValue.numerator = f1.numerator * f2.denominator;
	if(retValue.numerator==0){
		return retValue;
	}
	gcd = GCD(retValue.numerator, retValue.denominator);
	retValue.numerator /= gcd;
	retValue.denominator /= gcd;
	if(retValue.denominator < 0){
		retValue.denominator = retValue.denominator * (-1);
		retValue.numerator = retValue.numerator * (-1);
		return retValue;
	}
	return retValue;
}

int GCD(int a,int b){
	int i,tmp_gcd;

	for(i=a;i>=1;i--){
		if(a%i==0){
			if(b%i==0){
				tmp_gcd=i;
				return tmp_gcd;
			}
		}
	}
}

int LCM(int a,int b){
	int tmp_lcm;
	tmp_lcm = a * b / GCD(a,b);
	return tmp_lcm;
}

