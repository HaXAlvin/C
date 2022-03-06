#include<stdio.h>

int add(int a, int b) {  //�[�k
	return a + b;
}

int sub(int a, int b) {  //��k
	return a - b;
}

int multi(int a, int b) {  //���k
	return a * b;
}

int divide(int a, int b) {  //���k
	return a / b;
}

int mod(int a, int b) {  //���l��
	return a % b;
}

int main() {
	int (*opt[])(int, int) = { add, sub, multi, divide, mod };
	int choose;
	while (1) {
		printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���})�G");
		scanf("%d", &choose);
		int a, b;
		switch (choose) {
		case 1:
			printf("�п�J��Ӿ�ơG");
			scanf("%d %d", &a, &b);
			printf("%d + %d = %d\n", a, b, opt[0](a, b));

			break;
		case 2:
			printf("�п�J��Ӿ�ơG");
			scanf("%d %d", &a, &b);
			printf("%d - %d = %d\n", a, b, opt[1](a, b));
			break;
		case 3:
			printf("�п�J��Ӿ�ơG");
			scanf("%d %d", &a, &b);
			printf("%d * %d = %d\n", a, b, opt[2](a, b));
			break;
		case 4:
			printf("�п�J��Ӿ�ơG");
			scanf("%d %d", &a, &b);
			printf("%d / %d = %d\n", a, b, opt[3](a, b));
			break;
		case 5:
			printf("�п�J��Ӿ�ơG");
			scanf("%d %d", &a, &b);
			printf("%d %% %d = %d\n", a, b, opt[4](a, b));
			break;
		case 0:
			return 0;
		default :
			break;
		}
	}
		return 0;
}