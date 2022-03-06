#include<stdio.h>

int add(int a, int b) {  //加法
	return a + b;
}

int sub(int a, int b) {  //減法
	return a - b;
}

int multi(int a, int b) {  //乘法
	return a * b;
}

int divide(int a, int b) {  //除法
	return a / b;
}

int mod(int a, int b) {  //取餘數
	return a % b;
}

int main() {
	int (*opt[])(int, int) = { add, sub, multi, divide, mod };
	int choose;
	while (1) {
		printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開)：");
		scanf("%d", &choose);
		int a, b;
		switch (choose) {
		case 1:
			printf("請輸入兩個整數：");
			scanf("%d %d", &a, &b);
			printf("%d + %d = %d\n", a, b, opt[0](a, b));

			break;
		case 2:
			printf("請輸入兩個整數：");
			scanf("%d %d", &a, &b);
			printf("%d - %d = %d\n", a, b, opt[1](a, b));
			break;
		case 3:
			printf("請輸入兩個整數：");
			scanf("%d %d", &a, &b);
			printf("%d * %d = %d\n", a, b, opt[2](a, b));
			break;
		case 4:
			printf("請輸入兩個整數：");
			scanf("%d %d", &a, &b);
			printf("%d / %d = %d\n", a, b, opt[3](a, b));
			break;
		case 5:
			printf("請輸入兩個整數：");
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