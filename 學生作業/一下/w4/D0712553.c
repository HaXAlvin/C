#include<stdio.h>

struct fraction {  //���Ƶ��c 
	int son;
	int mom;
};

//����۰��k + ���� + �t������l
struct fraction Euclid(struct fraction ans){
	int temp;
	int m = ans.son;
	int n = ans.mom;
	if (m < 0) {
		m = m * -1;
	}
	if (n < 0) {
		n = n * -1;
	}
	if (m < n) {  //�j�ƹ�p�ƨD��
		temp = m;
		m = n;
		n = temp;
	}
	while (m % n != 0) {  //�̫᪺n����ƪ��̤j���]��
		temp = m % n;
		m = n;
		n = temp;

	}

	//����
	ans.son = ans.son / n;
	ans.mom = ans.mom / n;

	//�t���Τ@����l 
	if (ans.mom < 0) {
		ans.mom = ans.mom * -1;
		ans.son = ans.son * -1;
	}

	return ans;
}

//�[�k�禡 
struct fraction add(struct fraction front, struct fraction back) {
	front.son = front.son * back.mom;  //���l�q��
	back.son = back.son * front.mom;   //���l�q��
	front.mom = front.mom * back.mom;  //�����q��
	back.mom = front.mom;              //�����q��

	struct fraction ans;  //��ۥ[�᪺����
	ans.son = front.son + back.son;
	ans.mom = front.mom;

	return Euclid(ans);
};
//��k�禡 
struct fraction sub(struct fraction front, struct fraction back) {
	front.son = front.son * back.mom;  //���l�q��
	back.son = back.son * front.mom;   //���l�q��
	front.mom = front.mom * back.mom;  //�����q��
	back.mom = front.mom;              //�����q��

	struct fraction ans;  //��۴�᪺���� 
	ans.son = front.son - back.son;
	ans.mom = front.mom;

	return Euclid(ans);
};
//���k�禡 
struct fraction mul(struct fraction front, struct fraction back) {
	struct fraction ans;
	ans.son = front.son * back.son;
	ans.mom = front.mom * back.mom;

	return Euclid(ans);
};
//���k�禡 
struct fraction div(struct fraction front, struct fraction back) {
	//���ư��k�A�ᶵ���l�����A�� 
	int change;
	change = back.son;
	back.son = back.mom;
	back.mom = change;
	
	struct fraction ans = mul(front, back);  //�A�˫�ϥΤ��ƭ��k�禡

	return Euclid(ans);
};

int main() {
	
	while (1) {
		int choose = 0;
		printf("���(1.�[/2.��/3.��/4.��/0.���})�G");
		scanf("%d", &choose);
		
		char mark[6] = {0, '+', '-', '*', '/' };

		printf("a/b %c c/d�A�п�Ja b c d�G", mark[choose]);
		if (choose == 0) {
			break;
		}
		else if(choose < 0 || choose  >= 5){
			printf("��J���~\n\n");
			continue;
		}

		struct fraction front;  //�s��e����a���l�Bb����
		struct fraction back;   //�s��᭱��c���l�Bd����
		scanf("%d %d %d %d", &front.son, &front.mom, &back.son, &back.mom);
		if (front.mom == 0 || back.mom == 0) {
			printf("�������i��0\n\n");
			continue;
		}
		if ((choose == 3 || choose == 4) && back.son == 0) {
			printf("���Ƥ��i��0\n\n");
			continue;
		}

		struct fraction ans;  //�񵲪G

		if (choose == 1) {  //�[
			ans = add(front, back);
			if (ans.son % ans.mom == 0) {
				printf("%d/%d + %d/%d = %d\n\n", front.son, front.mom, back.son, back.mom, ans.son);
			}
			else {
				printf("%d/%d + %d/%d = %d/%d\n\n", front.son, front.mom, back.son, back.mom, ans.son, ans.mom);
			}
		}
		else if (choose == 2) {  //��
			ans = sub(front, back);
			if (ans.son % ans.mom == 0) {
				printf("%d/%d - %d/%d = %d\n\n", front.son, front.mom, back.son, back.mom, ans.son);
			}
			else {
				printf("%d/%d - %d/%d = %d/%d\n\n", front.son, front.mom, back.son, back.mom, ans.son, ans.mom);
			}
		}
		else if (choose == 3) {  //��
			ans = mul(front, back);
			if (ans.son % ans.mom == 0) {
				printf("%d/%d * %d/%d = %d\n\n", front.son, front.mom, back.son, back.mom, ans.son);
			}
			else {
				printf("%d/%d * %d/%d = %d/%d\n\n", front.son, front.mom, back.son, back.mom, ans.son, ans.mom);
			}
		}
		else if (choose == 4) {  //��
			ans = div(front, back);
			if (ans.son % ans.mom == 0) {
				printf("%d/%d / %d/%d = %d\n\n", front.son, front.mom, back.son, back.mom, ans.son);
			}
			else {
				printf("%d/%d / %d/%d = %d/%d\n\n", front.son, front.mom, back.son, back.mom, ans.son, ans.mom);
			}
		}
	}

	return 0;
}
