#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���Ƶ��c
struct div{
	int fraction;
	int denominator;
};

struct div add(struct div div1,struct div div2){
	int answer_fraction,answer_denominator;
	struct div answer;

	//�����ۭ����l�ۥ[
	answer.fraction = div1.fraction * div2.denominator + div2.fraction * div1.denominator;
	answer.denominator = div1.denominator * div2.denominator;
	return answer;
}

struct div sub(struct div div1,struct div div2){
	int answer_fraction,answer_denominator;
	struct div answer;
	//�����ۭ����l�۴�
	answer.fraction = div1.fraction * div2.denominator - div2.fraction * div1.denominator;
	answer.denominator = div1.denominator * div2.denominator;
	return answer;
}
struct div multi(struct div div1,struct div div2){
	int answer_fraction,answer_denominator;
	struct div answer;
	//���l�����ۭ�
	answer.fraction =  div1.fraction *  div2.fraction;
	answer.denominator = div1.denominator * div2.denominator;
	return answer;
}
struct div divide(struct div div1,struct div div2){
	int answer_fraction,answer_denominator;
	struct div answer;
	//div1*div2�˼�
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
		printf("���(1.�[/2.��/3.��/4.��/0.���})�G");
		scanf("%d",&choose);
		if(!choose--)
			return 0;
		printf("a/b %c c/d�A�п�Ja b c d\n",charOpt[choose]);
		scanf("%d %d %d %d",&a,&b,&c,&d);

		if(b==0||d==0){
			printf("�������i��0\n");
		}
		else{
			div_1.fraction = a;
            div_1.denominator = b;
            div_2.fraction = c;
            div_2.denominator = d;
            div_answer = add(div_1, div_2);
		}
		//�P�O�O���O���
		if(div_answer.denominator == 1){
			printf("%d/%d %c %d/%d = %d",div_1.fraction,div_1.denominator,charOpt[choose],div_2.fraction,div_2.denominator,div_answer.fraction);
		}
		else{
			printf("%d/%d %c %d/%d = %d/%d",div_1.fraction,div_1.denominator,charOpt[choose],div_2.fraction,div_2.denominator,div_answer.fraction,div_answer.denominator);
		}
	}
    return 0;
}
