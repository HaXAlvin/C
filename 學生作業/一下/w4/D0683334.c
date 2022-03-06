#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//分數結構
struct div{
	int fraction;
	int denominator;
};

struct div add(struct div div1,struct div div2){
	int answer_fraction,answer_denominator;
	struct div answer;

	//分母相乘分子相加
	answer.fraction = div1.fraction * div2.denominator + div2.fraction * div1.denominator;
	answer.denominator = div1.denominator * div2.denominator;
	return answer;
}

struct div sub(struct div div1,struct div div2){
	int answer_fraction,answer_denominator;
	struct div answer;
	//分母相乘分子相減
	answer.fraction = div1.fraction * div2.denominator - div2.fraction * div1.denominator;
	answer.denominator = div1.denominator * div2.denominator;
	return answer;
}
struct div multi(struct div div1,struct div div2){
	int answer_fraction,answer_denominator;
	struct div answer;
	//分子分母相乘
	answer.fraction =  div1.fraction *  div2.fraction;
	answer.denominator = div1.denominator * div2.denominator;
	return answer;
}
struct div divide(struct div div1,struct div div2){
	int answer_fraction,answer_denominator;
	struct div answer;
	//div1*div2倒數
	answer.fraction = div1.fraction * div2.denominator;
	answer.denominator = div1.denominator * div2.fraction;
	return answer;
}

int main(){
	char charOpt[] = {'+', '-', '*', '/'};
	int a, b, c, d;
	int choose;
	int answer;
	struct div div_1,div_2,div_answer;

	while(1){
		printf("選擇(1.加/2.減/3.乘/4.除/0.離開)：");
		scanf("%d",&choose);
		if(!choose--)
			return 0;
		printf("a/b %c c/d，請輸入a b c d\n",charOpt[choose]);
		scanf("%d %d %d %d",&a,&b,&c,&d);

		if(b==0||d==0){
			printf("分母不可為0\n");
		}
		else{
			div_1.fraction = a;
            div_1.denominator = b;
            div_2.fraction = c;
            div_2.denominator = d;
            div_answer = add(div_1, div_2);
		}
		//判別是不是整數
		if(div_answer.denominator == 1){
			printf("%d/%d %c %d/%d = %d",div_1.fraction,div_1.denominator,charOpt[choose],div_2.fraction,div_2.denominator,div_answer.fraction);
		}
		else{
			printf("%d/%d %c %d/%d = %d/%d",div_1.fraction,div_1.denominator,charOpt[choose],div_2.fraction,div_2.denominator,div_answer.fraction,div_answer.denominator);
		}
	}
    return 0;
}
